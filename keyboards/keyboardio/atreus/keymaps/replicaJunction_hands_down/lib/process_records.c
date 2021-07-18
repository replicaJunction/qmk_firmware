#include "process_records.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!(
        process_record_adaptive_keys(keycode, record) &&
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

    return process_record_keymap(keycode, record);
}
