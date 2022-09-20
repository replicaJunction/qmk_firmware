#include "repeat.h"
#include "rj_keycodes.h"

uint16_t previous_keycode = KC_NO;

void register_key_to_repeat(uint16_t keycode) {
    // Get the base keycode of a mod or layer tap key
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            keycode = keycode & 0xFF;
            break;
    }

    // Merge current mod state with keycode, for easy comparison when
    // we want to do special key reverse repeats.
    uint8_t mods = get_mods() | get_oneshot_mods();
    if (mods & MOD_MASK_CTRL) keycode |= QK_LCTL;
    if (mods & MOD_MASK_SHIFT) keycode |= QK_LSFT;
    if (mods & MOD_MASK_GUI) keycode |= QK_LGUI;
    if (mods & MOD_BIT(KC_LALT)) keycode |= QK_LALT;
    if (mods & MOD_BIT(KC_RALT)) keycode |= QK_RALT;

    previous_keycode = keycode;
}

bool process_record_repeat(uint16_t keycode, const keyrecord_t *record) {
    if (keycode == REPEAT) {
        if (record->event.pressed) {
            register_code16(previous_keycode);
        }
        else {
            unregister_code16(previous_keycode);
        }
        return false;
    }
    else if (record->event.pressed) {
        register_key_to_repeat(keycode);
    }

    return true;
}
