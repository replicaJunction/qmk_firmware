#include "process_adaptive_key.h"

static uint16_t              timer                 = 0;
static bool                  b_adaptive_key_enable = true;
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
        const adaptive_key_t *const current_adaptive_key = adaptive_keys[i];

        if (current_adaptive_key == NULL) {
            // End of array
            return;
        }

        if (keycode == current_adaptive_key->prefix_key) {
            active_adaptive_key = current_adaptive_key;
            timer               = timer_read();
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

    if (active_adaptive_key == NULL) {
        // If an adaptive key prefix isn't active, check if one should
        // be activated, but don't affect normal behavior
        check_adaptive_key_prefix(keycode, record);
        return true;
    }

    if (keycode == active_adaptive_key->trigger_key) {
        if (!key_down) {
            unregister_code(active_adaptive_key->replace_key);
            active_adaptive_key = NULL;
            return false;
        }

        if (timer_elapsed(timer) > ADAPTIVE_KEY_TERM) {
            active_adaptive_key = NULL;
            return true;
        }

        register_code(active_adaptive_key->replace_key);
        return false;
    }

    return true;
}
