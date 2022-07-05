#include "callum_oneshot.h"

void update_oneshot(
    callum_oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                register_code(mod);
            }
            *state = os_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
            case os_down_unused:
                // If we didn't use the mod while trigger was held, queue it.
                *state = os_up_queued;
                break;
            case os_down_used:
                // If we did use the mod while trigger was held, unregister it.
                *state = os_up_unqueued;
                unregister_code(mod);
                break;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                unregister_code(mod);
            }
        } else {
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_down_unused:
                    *state = os_down_used;
                    break;
                case os_up_queued:
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

callum_oneshot_state os_shift_state = os_up_unqueued;
callum_oneshot_state os_ctrl_state = os_up_unqueued;
callum_oneshot_state os_alt_state = os_up_unqueued;
callum_oneshot_state os_gui_state = os_up_unqueued;

bool process_record_callum_oneshot(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(&os_shift_state, KC_LSFT, COS_SFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, COS_CTL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, COS_ALT, keycode, record);
    update_oneshot(&os_gui_state, KC_LGUI, COS_GUI, keycode, record);

    return true;
}

__attribute__ ((weak))
bool is_oneshot_cancel_key(uint16_t keycode) {
    return false;
}

__attribute__ ((weak))
bool is_oneshot_ignored_key(uint16_t keycode) {
    return false;
}
