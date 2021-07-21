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

void check_adaptive_key_prefix(uint16_t keycode, keyrecord_t *record) {
    for (uint8_t i = 0;; i++) {
        const adaptive_key_t *const check_adaptive_key = adaptive_keys[i];

        if (check_adaptive_key == NULL) {
            // End of array
            return;
        }

        if (keycode == check_adaptive_key->prefix_key) {
            prefix_key = check_adaptive_key->prefix_key;
            timer      = timer_read();
            return;
        }
    }
}

bool process_adaptive_key(uint16_t keycode, keyrecord_t *record) {
    // @TODO keycodes for enable / disable?

    if (!b_adaptive_key_enable) {
        return true;
    }

    const bool key_down = record->event.pressed;

    if (prefix_key == KC_NO) {
        // If an adaptive key prefix isn't active, check if one should
        // be activated, but don't affect normal behavior
        check_adaptive_key_prefix(keycode, record);
        return true;
    }

    if (!key_down && keycode == prefix_key) {
        // Releasing the prefix key doesn't affect the logic for the
        // adaptive key.
        // Leave active_adaptive_key alone - it gets reset when the
        // adaptive key itself is released.
        return true;
    }

    // Try to find an adaptive key that matches the prefix and the
    // current keycode
    for (uint8_t i = 0;; i++) {
        const adaptive_key_t *const check_adaptive_key = adaptive_keys[i];

        if (check_adaptive_key == NULL) {
            // Didn't find one. Handle the key event normally

            if (key_down) {
                // If a different key was pressed down, no adaptive
                // behavior can be triggered for this prefix
                prefix_key = KC_NO;
            }

            return true;
        }

        if (check_adaptive_key->prefix_key == prefix_key && check_adaptive_key->trigger_key == keycode) {
            // This is our adaptive key definition

            if (!key_down) {
                if (check_adaptive_key == active_adaptive_key) {
                    unregister_code16(active_adaptive_key->replace_key);
                }
                else {
                    unregister_code16(check_adaptive_key->trigger_key);
                }

                prefix_key = KC_NO;
                active_adaptive_key = NULL;
                return false;
            }

            if (timer_elapsed(timer) > ADAPTIVE_KEY_TERM) {
                prefix_key = KC_NO;
                active_adaptive_key = NULL;
                return true;
            }

            active_adaptive_key = check_adaptive_key;
            register_code16(active_adaptive_key->replace_key);
            return false;
        }
    }

    // Should never be hit
    return true;
}
