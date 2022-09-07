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
void keyboard_post_init_user_kb(void) { }

void keyboard_post_init_user(void) {
    keyboard_post_init_user_kb();
}

#ifdef USER_ADAPTIVE_KEYS_ENABLE
#    include "features/adaptive_keys.h"
#endif

#if defined(USER_CANCEL_KEY_ENABLE) && defined(USER_CALLUM_ONESHOT_ENABLE)
bool is_oneshot_cancel_key(uint16_t keycode) {
    if (
        keycode == CANCEL
    ) {
        return true;
    }

    return false;
}
#endif

#if defined(COMBO_TERM_PER_COMBO)
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (combo->keycode) {
        case KL_LH1:
        case KL_LH2:
        case KL_LH3:
        case KL_LH4:

        case KL_RH2:
        case KL_RH3:
        case KL_RH4:
        case KL_RH5:
            return COMBO_TERM_HOME_ROW;

        default:
            return COMBO_TERM;
    }
}
#endif


#if defined(USER_CALLUM_ONESHOT_ENABLE)
bool is_oneshot_ignored_key(uint16_t keycode) {
    if (
        keycode == COS_CTL ||
        keycode == COS_ALT ||
        keycode == COS_SFT ||
        keycode == COS_GUI
    ) {
        return true;
    }

    return false;
}
#endif

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KL_LH1:
        case KL_LH2:
        case KL_LH3:
        case KL_LH4:

        case KL_RH2:
        case KL_RH3:
        case KL_RH4:
        case KL_RH5:
            return TAPPING_TERM_HOME_ROW_MODS;

        default:
            return TAPPING_TERM;
    }
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Permissive hold tends to get in the way of home row mods for me
    switch (keycode) {
        case KL_LH1:
        case KL_LH2:
        case KL_LH3:
        case KL_LH4:

        case KL_RH2:
        case KL_RH3:
        case KL_RH4:
        case KL_RH5:
            return false;
        default:
            return true;
    }
}
#endif
