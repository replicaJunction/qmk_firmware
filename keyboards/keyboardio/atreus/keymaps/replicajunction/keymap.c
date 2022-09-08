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
#include "config.h"
#include "replicajunction.h"

#define BSP_SYM LT(L_SYMBOLS, KC_BSPC)
#define SPC_NAV LT(L_NAVIGATION, KC_SPC)
#define EQL_FUN LT(L_FN, KC_EQL)

#define ESC_SFT LSFT_T(KC_ESC)
#define TAB_SFT RSFT_T(KC_TAB)

#define DF_TYPE DF(L_BASE)
#define DF_GAME DF(L_GAMING)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_BASE] = LAYOUT(
    KL_L11, KL_L12, KL_L13, KL_L14, KL_L15,                 KL_R11, KL_R12, KL_R13, KL_R14, KL_R15,
    KL_LH1, KL_LH2, KL_LH3, KL_LH4, KL_L25,                 KL_R21, KL_RH2, KL_RH3, KL_RH4, KL_RH5,
    KL_L31, KL_L32, KL_L33, KL_L34, KL_L35, SALTTAB,KC_BSLS,KL_R31, KL_R32, KL_R33, KL_R34, KL_R35,
    KC_ESC, KC_LGUI,KC_TAB, KL_LT1, KL_LT2, KL_LT3, KL_RT1, KL_RT2, KL_RT3, KC_MINS,KC_QUOT,EQL_FUN
),

[L_GAMING] = LAYOUT(
    _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
    _______,_______,KC_C,   KC_D,   _______,_______,KC_LOCK,_______,_______,_______,_______,_______,
    _______,KC_TAB, KC_LALT,KC_LSFT,KC_SPC, KC_LCTL,KC_LALT,KC_BSPC,KC_BTN1,KC_BTN2,KC_BTN3,_______
),

[L_NUMBERS] = LAYOUT(
    _______,KC_LCBR,KC_RCBR,_______,_______,                _______,_______,KC_LT,  KC_GT,  _______,
    KC_6,   KC_4,   KC_0,   KC_2,   _______,                _______,KC_3,   KC_1,   KC_5,   KC_7,
    _______,KC_LBRC,KC_RBRC,KC_8,   _______,_______,_______,_______,KC_9,   KC_LPRN,KC_RPRN,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

[L_SYMBOLS] = LAYOUT(
    SYM_L11,SYM_L12,SYM_L13,SYM_L14,SYM_L15,                SYM_R11,SYM_R12,SYM_R13,SYM_R14,SYM_R15,
    SYM_L21,SYM_L22,SYM_L23,SYM_L24,SYM_L25,                SYM_R21,SYM_R22,SYM_R23,SYM_R24,SYM_R25,
    SYM_L31,SYM_L32,SYM_L33,SYM_L34,SYM_L35,_______,_______,SYM_R31,SYM_R32,SYM_R33,SYM_R34,SYM_R35,
    _______,_______,_______,_______,ooooooo,_______,_______,ooooooo,CAPWORD,_______,_______,_______
),

[L_NAVIGATION] = LAYOUT(
    NAV_L11,NAV_L12,NAV_L13,NAV_L14,NAV_L15,                NAV_R11,NAV_R12,NAV_R13,NAV_R14,NAV_R15,
    NAV_L21,NAV_L22,NAV_L23,NAV_L24,NAV_L25,                NAV_R21,NAV_R22,NAV_R23,NAV_R24,NAV_R25,
    NAV_L31,NAV_L32,NAV_L33,NAV_L34,NAV_L35,_______,_______,NAV_R31,NAV_R32,NAV_R33,NAV_R34,NAV_R35,
    _______,_______,_______,NUMWORD,ooooooo,_______,_______,ooooooo,_______,_______,_______,_______
),

[L_FN] = LAYOUT(
    QK_BOOT,QK_VERS,_______,_______,_______,                KC_VOLU,KC_F9,  KC_F10, KC_F11, KC_F12,
    QK_MAKE,_______,_______,_______,_______,                KC_MUTE,KC_F5,  KC_F6,  KC_F7,  KC_F8,
    _______,K_SECR1,K_SECR2,K_SECR3,K_SECR4,MS_JIGL,QK_BOOT,KC_VOLD,KC_F1,  KC_F2,  KC_F3,  KC_F4,
    DF_TYPE,DF_GAME,_______,_______,_______,KC_LCTL,KC_LALT,_______,_______,_______,_______,ooooooo
),

// [L_MACROS] = LAYOUT(
//     _______,_______,DM_REC2,DM_REC1,DM_RSTP,                _______,SHEBANG,_______,_______,_______,
//     QK_MAKE,_______,DM_PLY2,DM_PLY1,_______,                PRG_NE, PRG_EQ, PRG_GEQ,PRG_LEQ,PRG_ARR,
//     QK_VERS,_______,_______,_______,_______,_______,_______,_______,PS_ITEM,FS_PIPE,_______,FS_ARR,
//     _______,_______,_______,_______,ooooooo,_______,_______,ooooooo,_______,_______,_______,_______
// )


// Template
// [L_FUNC] = LAYOUT(
//     _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
// ),

};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, L_SYMBOLS, L_NAVIGATION, L_MACROS);
// }
