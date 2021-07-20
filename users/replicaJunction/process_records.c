#include "process_records.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!(
#ifdef USER_ADAPTIVE_KEYS_ENABLE
        process_record_adaptive_keys(keycode, record) &&
#endif
#ifdef USER_CAPS_WORD_ENABLE
        process_record_caps_word(keycode, record) &&
#endif
#ifdef USER_NUM_WORD_ENABLE
        process_record_num_word(keycode, record) &&
#endif

        true
    )) {
        return false;
    }

#ifdef USER_INCLUDE_LAYER_GAMING
    if (keycode == TG_GAME) {
        if (record->event.pressed) {
            if (IS_LAYER_ON(L_GAMING)) {
                #ifdef COMBO_ENABLE
                combo_enable();
                #endif
                layer_off(L_GAMING);
            }
            else {
                #ifdef COMBO_ENABLE
                combo_disable();
                #endif
                layer_on(L_GAMING);
            }
        }

        // Keycode has been handled
        return false;
    }
#endif

    switch(keycode)
    {
        case QK_MAKE: {
            if (record->event.pressed)
                SEND_STRING("qmk compile --keyboard " QMK_KEYBOARD " --keymap " QMK_KEYMAP);
            return false;
        }
        case QK_FLSH: {
            if (record->event.pressed) {
                SEND_STRING("qmk flash --keyboard " QMK_KEYBOARD " --keymap " QMK_KEYMAP);
            }
            return false;
        }
        case QK_VERS: {
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
            }
            return false;
        }
        case PRG_EQ: {
            if (record->event.pressed) {
                SEND_STRING("==");
            }
            return false;
        }
        case PRG_NE: {
            if (record->event.pressed) {
                SEND_STRING("!=");
            }
            return false;
        }
        case PRG_GEQ: {
            if (record->event.pressed) {
                SEND_STRING(">=");
            }
            return false;
        }
        case PRG_LEQ: {
            if (record->event.pressed) {
                SEND_STRING("<=");
            }
            return false;
        }
        case PRG_ARR: {
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;
        }

        case PS_ITEM: {
            if (record->event.pressed) {
                SEND_STRING("$_");
            }
            return false;
        }
        case FS_PIPE: {
            if (record->event.pressed) {
                SEND_STRING("|>");
            }
            return false;
        }
        case FS_ARR: {
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        }
        case SHEBANG: {
            if (record->event.pressed) {
                SEND_STRING("#!");
            }
            return false;
        }
    }

    return process_record_keymap(keycode, record);
}
