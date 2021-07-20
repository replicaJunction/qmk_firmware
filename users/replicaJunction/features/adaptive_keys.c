#include "adaptive_keys.h"

uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0;

bool process_record_adaptive_keys(uint16_t keycode, const keyrecord_t *record) {
    #ifdef USER_INCLUDE_LAYER_GAMING
    if (IS_LAYER_ON(L_GAMING)) {
        return true;
    }
    #endif

    bool return_state = true;

    if (record->event.pressed) {
        switch (keycode) {
            case KC_C:
                // $-c -> $_
                if ((prior_keycode == KC_DLR) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code16(KC_UNDS);
                    return_state = false;
                }
                break;
            case KC_D:
                // B-D -> BL
                if ((prior_keycode == KC_B) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_L);
                    return_state = false;
                }
                break;
            case KC_F:
                // M-F -> MB
                if ((prior_keycode == KC_M) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_B);
                    return_state = false;
                }
                break;
            case KC_M:
                // F-M -> FL
                // G-M -> GL
                // K-M -> KL
                if (((prior_keycode == KC_F)||(prior_keycode == KC_G)||(prior_keycode == KC_K)) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_L);
                    return_state = false;
                }
                break;
            case KC_V:
                // M-V -> MB
                if ((prior_keycode == KC_M) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                    tap_code(KC_B);
                    return_state = false;
                }
        }
        prior_keycode = keycode;
        prior_keydown = timer_read();
    }

    return return_state;
}
