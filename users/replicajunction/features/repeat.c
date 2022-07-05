#include "repeat.h"
#include "rj_keycodes.h"

uint16_t previous_keycode = KC_NO;

void register_key_to_repeat(uint16_t keycode) {
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
