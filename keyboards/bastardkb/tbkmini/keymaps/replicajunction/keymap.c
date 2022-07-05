/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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
#include "config.h"


enum layers {
    L_BASE,
    L_GAMING,
    L_GAMING2,
    L_NAVIGATION,
    L_FUNC,
    L_NUMPAD,
};

#define USER_LAYER_NUMBER L_NUMPAD
#define USER_LAYER_FUNCTION L_FUNC

#define TG_GAME TG(L_GAMING)
#define LA_FN OSL(L_FUNC)
#define LA_GAM2 OSL(L_GAMING2)

#include "replicajunction.h"

uint8_t NUMWORD_LAYER = L_NUMPAD;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_BASE] = LAYOUT_split_3x6_3(
    KL_L10, KL_L11, KL_L12, KL_L13, KL_L14, KL_L15,                 KL_R11, KL_R12, KL_R13, KL_R14, KL_R15, KL_R16,
    KL_L20, KL_LH1, KL_LH2, KL_LH3, KL_LH4, KL_L25,                 KL_R21, KL_RH2, KL_RH3, KL_RH4, KL_RH5, KL_R26,
    KL_L30, KL_L31, KL_L32, KL_L33, KL_L34, KL_L35,                 KL_R31, KL_R32, KL_R33, KL_R34, KL_R35, KL_R36,
                                    KL_LT1, KL_LT2, KL_LT3, KL_RT1, KL_RT2, KL_RT3
),


[L_GAMING] = LAYOUT_split_3x6_3(
    KC_LOCK,KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,                   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,
    KC_LALT,KC_ESC, KC_A,   KC_S,   KC_D,   KC_F,                   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,
    _______,LA_GAM2,KC_Z,   KC_X,   KC_C,   KC_V,                   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, LA_FN,
                                    KC_LSFT,KC_SPC, KC_LCTL,KC_ENT, KC_BSPC,_______
),


[L_GAMING2] = LAYOUT_split_3x6_3(
    _______,_______,KC_7,   KC_8,   KC_9,   KC_BTN3,                _______,_______,KC_UP,  _______,_______,_______,
    _______,_______,KC_4,   KC_5,   KC_6,   KC_BTN2,                _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
    _______,ooooooo,KC_1,   KC_2,   KC_3,   KC_BTN1,                _______,_______,_______,_______,_______,_______,
                                    _______,_______,_______,_______,_______,_______
),

[L_NAVIGATION] = LAYOUT_split_3x6_3(
    RESET,  NAV_L11,NAV_L12,NAV_L13,NAV_L14,NAV_L15,                NAV_R11,NAV_R12,NAV_R13,NAV_R14,NAV_R15,NAV_R16,
    NAV_L20,NAV_L21,NAV_L22,NAV_L23,NAV_L24,NAV_L25,                NAV_R21,NAV_R22,NAV_R23,NAV_R24,NAV_R25,NAV_R26,
    NAV_L30,NAV_L31,NAV_L32,NAV_L33,NAV_L34,NAV_L35,                NAV_R31,NAV_R32,NAV_R33,NAV_R34,NAV_R35,NAV_R36,
                                    _______,KC_BSPC,CTALDEL,_______,ooooooo,_______
),


// [L_SYMBOLS] = LAYOUT_split_3x6_3(
//     SYM_L10,SYM_L11,SYM_L12,SYM_L13,SYM_L14,SYM_L15,                SYM_R11,SYM_R12,SYM_R13,SYM_R14,SYM_R15,SYM_R16,
//     SYM_L20,SYM_L21,SYM_L22,SYM_L23,SYM_L24,SYM_L25,                SYM_R21,SYM_R22,SYM_R23,SYM_R24,SYM_R25,SYM_R26,
//     SYM_L30,SYM_L31,SYM_L32,SYM_L33,SYM_L34,SYM_L35,                SYM_R31,SYM_R32,SYM_R33,SYM_R34,SYM_R35,SYM_R36,
//                                     _______,ooooooo,_______,_______,_______,_______
// ),


[L_FUNC] = LAYOUT_split_3x6_3(
    RESET,  QK_VERS,RGB_TOG,RGB_MOD,RGB_SPI,_______,                KC_VOLU,KC_F9,  KC_F10, KC_F11, KC_F12, TG_GAME,
    _______,QK_FLSH,RGB_HUI,RGB_SAI,RGB_VAI,_______,                KC_MUTE,KC_F5,  KC_F6,  KC_F7,  KC_F8,  _______,
    _______,QK_MAKE,K_SECR1,K_SECR2,K_SECR3,K_SECR4,                KC_VOLD,KC_F1,  KC_F2,  KC_F3,  KC_F4,  ooooooo,
                                    _______,_______,_______,_______,_______,_______
),


[L_NUMPAD] = LAYOUT_split_3x6_3(
    _______,KC_HASH,KC_PERC,KC_LCBR,KC_RCBR,_______,                _______,KC_7,   KC_8,   KC_9,   _______,ooooooo,
    _______,_______,_______,KC_LPRN,KC_RPRN,_______,                _______,KC_4,   KC_5,   KC_6,   _______,_______,
    _______,KC_LT,  KC_GT,  KC_LBRC,KC_RBRC,_______,                KC_0,   KC_1,   KC_2,   KC_3,   KC_DOT, KC_COMM,
                                    _______,_______,_______,_______,_______,_______
),


// Template
// [L_FUNC] = LAYOUT_split_3x6_3(
//     _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
//                                     _______,_______,_______,_______,_______,_______
// ),

};


uint32_t layer_state_set_user(uint32_t state) {
    if (IS_LAYER_ON_STATE(state, L_GAMING)) {
        combo_disable();
        key_override_off();
    }
    else {
        combo_enable();
        key_override_on();
    }

    return state;
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    if (
        #if defined(USER_CANCEL_KEY_ENABLE)
        keycode == CANCEL ||
        #endif

        false
    ) {
        return true;
    }

    return false;
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    if (
        keycode == COS_CTL ||
        keycode == COS_ALT ||
        keycode == COS_SFT ||
        keycode == COS_GUI //||
        // keycode == OSL(L_SYMBOLS_LEFT_THUMB) ||
        // keycode == OSL(L_SYMBOLS_RIGHT_THUMB)
    ) {
        return true;
    }

    return false;
}
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
