/* Copyright 2021 Joshua T.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "replicajunction.h"

__attribute__ ((weak))
void matrix_scan_user_kb(void) { }

#if defined(LEADER_ENABLE)
LEADER_EXTERNS();
#endif

// Runs on every matrix scan. Be careful what goes here - you can really impact the
// responsiveness of your keyboard if you add too much in this function.
void matrix_scan_user(void) {
#ifdef USER_MOUSE_JIGGLE_ENABLE
    matrix_scan_mouse_jiggle();
#endif

#ifdef USER_SUPER_ALT_TAB_ENABLE
    matrix_scan_super_alt_tab();
#endif

#ifdef USER_ADAPTIVE_KEYS_ENABLE
    matrix_scan_adaptive_keys();
#endif

#if defined(LEADER_ENABLE)
    LEADER_DICTIONARY() {
        leading = false;

        SEQ_ONE_KEY(KC_C) {
            #if defined(USER_CAPS_WORD_ENABLE)
                disable_caps_word();
            #endif

            #if defined(USER_NUM_WORD_ENABLE)
                disable_num_word();
            #endif

            layer_clear();
        }

        SEQ_TWO_KEYS(KC_T, KC_N) {
            layer_invert(USER_LAYER_NUMBER);
        }

        leader_end();
    }

#endif

    matrix_scan_user_kb();
}
