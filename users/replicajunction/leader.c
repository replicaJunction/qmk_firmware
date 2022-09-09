#include "leader.h"

LEADER_EXTERNS();

void matrix_scan_leader(void) {
    LEADER_DICTIONARY() {
        leading = false;

        SEQ_ONE_KEY(KC_C) {
            #if defined(CAPS_WORD_ENABLE)
                caps_word_off();
            #endif

            #if defined(USER_NUM_WORD_ENABLE)
                disable_num_word();
            #endif

            layer_clear();
        }

        SEQ_TWO_KEYS(KC_T, KC_N) {
            layer_invert(USER_LAYER_NUMBER);
        }

        // Git commands
        SEQ_TWO_KEYS(KC_G, KC_SPC) {
            SEND_STRING("git ");
        }

        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit\n");
        }

        SEQ_TWO_KEYS(KC_G, KC_L) {
            SEND_STRING("git pull\n");
        }

        SEQ_TWO_KEYS(KC_G, KC_S) {
            SEND_STRING("git status\n");
        }

        SEQ_TWO_KEYS(KC_G, KC_U) {
            SEND_STRING("git push\n");
        }

        SEQ_THREE_KEYS(KC_G, KC_C, KC_A) {
            SEND_STRING("git commit --amend");
        }

        leader_end();
    }
}
