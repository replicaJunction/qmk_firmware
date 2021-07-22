#include "process_adaptive_key.h"

static uint16_t              timer                 = 0;
static bool                  b_adaptive_key_enable = true;
static uint16_t              prefix_key            = KC_NO;
static const adaptive_key_t *active_adaptive_key   = NULL;

void enable_adaptive_keys(void) { b_adaptive_key_enable = true; }

void disable_adaptive_keys(void) { b_adaptive_key_enable = false; }

void toggle_adaptive_keys(void) {
    if (b_adaptive_key_enable) {
        disable_adaptive_keys();
    } else {
        enable_adaptive_keys();
    }
}


__attribute__ ((__weak__))
const adaptive_key_t *try_get_adaptive_key_user(uint16_t prefix, uint16_t keycode) {
    return NULL;
}


const adaptive_key_t *try_get_adaptive_key(uint16_t prefix, uint16_t trigger, bool check_trigger) {
    const adaptive_key_t *user_result = try_get_adaptive_key_user(prefix, trigger);
    if (user_result != NULL) {
        return user_result;
    }


    for (uint8_t i = 0;; i++) {
        const adaptive_key_t *const check_adaptive_key = adaptive_keys[i];

        if (check_adaptive_key == NULL) {
            // Reached the end of the list
            return NULL;
        }

        if (check_adaptive_key->prefix_key == prefix && (!check_trigger || (check_trigger && check_adaptive_key->trigger_key == trigger))) {
            return check_adaptive_key;
        }
    }
}


__attribute__ ((__weak__))
const bool is_adaptive_key_prefix_user(uint16_t keycode) {
    return false;
}


const bool is_adaptive_key_prefix(uint16_t keycode) {
    if (is_adaptive_key_prefix_user(keycode)) {
        return true;
    }

    const adaptive_key_t *possible_adaptive_key = try_get_adaptive_key(keycode, KC_NO, false);
    return (possible_adaptive_key != NULL);
}


bool process_adaptive_key(uint16_t keycode, keyrecord_t *record) {
    // @TODO keycodes for enable / disable?

    if (!b_adaptive_key_enable) {
        return true;
    }

    const bool key_down = record->event.pressed;

    if (active_adaptive_key != NULL) {
        if (!key_down && keycode == active_adaptive_key->trigger_key) {
            unregister_code16(active_adaptive_key->replace_key);
            prefix_key = KC_NO;
            active_adaptive_key = NULL;
            return false;
        }

        return true;
    }

    if (key_down && prefix_key == KC_NO) {
        // If an adaptive key prefix isn't active, check if one should
        // be activated, but don't affect normal behavior
        if (is_adaptive_key_prefix(keycode)) {
            prefix_key = keycode;
            timer      = timer_read();
        }
        return true;
    }

    if (!key_down && keycode == prefix_key) {
        // Releasing the prefix key doesn't affect the logic for the
        // adaptive key.
        return true;
    }

    const adaptive_key_t *found_adaptive_key = try_get_adaptive_key(prefix_key, keycode, true);
    if (found_adaptive_key == NULL) {
        // This doesn't look like an adaptive key

        if (key_down) {
            // If the user pressed a valid prefix, but then pressed a
            // different key, do not trigger adaptive behavior.
            prefix_key = KC_NO;
        }

        // Handle the key event normally
        return true;
    }


    if (!key_down) {
        if (found_adaptive_key == active_adaptive_key) {
            unregister_code16(active_adaptive_key->replace_key);
        }
        else {
            unregister_code16(found_adaptive_key->trigger_key);
        }

        prefix_key = KC_NO;
        return false;
    }

    if (timer_elapsed(timer) > ADAPTIVE_KEY_TERM) {
        prefix_key = KC_NO;
        active_adaptive_key = NULL;
        return true;
    }

    active_adaptive_key = found_adaptive_key;
    register_code16(active_adaptive_key->replace_key);
    return false;
}
