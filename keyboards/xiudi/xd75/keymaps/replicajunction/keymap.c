/* Copyright 2021-2022 Joshua T.
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


// Be sure to include the local config.h before including the userspace
// header, since the local config.h sets some user preferences like
// "which layer is the numword layer"

#include QMK_KEYBOARD_H
#include "config.h"
#include "replicajunction.h"

#define LA_SYM OSL(L_SYMBOLS)
#define LA_FN OSL(L_FN)

#define SPC_NAV LT(L_NAVIGATION, KC_SPC)

#define DF_TYPE DF(L_BASE)
#define DF_GAME DF(L_GAMING)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_ortho_5x15(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KL_L10,  KL_L11,  KL_L12,  KL_L13,  KL_L14,  KL_L15,  KC_LBRC, KC_BSLS, KC_RBRC, KL_R11,  KL_R12,  KL_R13,  KL_R14,  KL_R15,  KL_R16,
        KL_L20,  KL_LH1,  KL_LH2,  KL_LH3,  KL_LH4,  KL_L25,  SALTTAB, KC_UP,   KC_END,  KL_R21,  KL_RH2,  KL_RH3,  KL_RH4,  KL_RH5,  KL_R26,
        KL_L30,  KL_L31,  KL_L32,  KL_L33,  KL_L34,  KL_L35,  KC_LEFT, KC_DOWN, KC_RGHT, KL_R31,  KL_R32,  KL_R33,  KL_R34,  KL_R35,  KL_R36,
        KC_LCTL, KC_LGUI, KC_LALT, LA_SYM,  KL_LT1,  KL_LT2,  KL_LT3,  KC_ENT,  KL_RT1,  KL_RT2,  KL_RT3,  LA_FN,   KC_RALT, KC_RGUI, KC_RCTL
    ),


    [L_GAMING] = LAYOUT_ortho_5x15(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_HOME,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_BTN1, KC_BTN2, KC_BTN3, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_UP,   KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LOCK, KC_LALT, LA_FN,   KC_LSFT, KC_SPC,  KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_SPC,  LA_FN,   KC_RALT, KC_RGUI, KC_RCTL
    ),


    [L_NUMBERS] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______, KC_LT,   KC_GT,   _______, _______,
        _______, KC_6,    KC_4,    KC_0,    KC_2,    _______, _______, _______, _______, _______, KC_3,    KC_1,    KC_5,    KC_7,    _______,
        _______, _______, KC_LBRC, KC_RBRC, KC_8,    _______, _______, _______, _______, _______, KC_9,    KC_LPRN, KC_RPRN, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    [L_SYMBOLS] = LAYOUT_ortho_5x15(
        SYM_L00, SYM_L01, SYM_L02, SYM_L03, SYM_L04, SYM_L05, SYM_L06, _______, SYM_R00, SYM_R01, SYM_R02, SYM_R03, SYM_R04, SYM_R05, SYM_R06,
        SYM_L10, SYM_L11, SYM_L12, SYM_L13, SYM_L14, SYM_L15, SYM_L16, _______, SYM_R10, SYM_R11, SYM_R12, SYM_R13, SYM_R14, SYM_R15, SYM_R16,
        SYM_L20, SYM_L21, SYM_L22, SYM_L23, SYM_L24, SYM_L25, SYM_L26, _______, SYM_R20, SYM_R21, SYM_R22, SYM_R23, SYM_R24, SYM_R25, SYM_R26,
        SYM_L30, SYM_L31, SYM_L32, SYM_L33, SYM_L34, SYM_L35, SYM_L36, _______, SYM_R30, SYM_R31, SYM_R32, SYM_R33, SYM_R34, SYM_R35, SYM_R36,
        _______, _______, _______, _______, ooooooo, _______, _______, _______, _______, _______, ooooooo, KC_P0,   KC_PDOT, KC_PENT, KC_COMM
    ),


    [L_NAVIGATION] = LAYOUT_ortho_5x15(
        NAV_L00, NAV_L01, NAV_L02, NAV_L03, NAV_L04, NAV_L05, _______, _______, _______, NAV_R01, NAV_R02, NAV_R03, NAV_R04, NAV_R05, NAV_R06,
        NAV_L10, NAV_L11, NAV_L12, NAV_L13, NAV_L14, NAV_L15, _______, _______, _______, NAV_R11, NAV_R12, NAV_R13, NAV_R14, NAV_R15, NAV_R16,
        NAV_L20, NAV_L21, NAV_L22, NAV_L23, NAV_L24, NAV_L25, _______, _______, _______, NAV_R21, NAV_R22, NAV_R23, NAV_R24, NAV_R25, NAV_R26,
        NAV_L30, NAV_L31, NAV_L32, NAV_L33, NAV_L34, NAV_L35, _______, _______, _______, NAV_R31, NAV_R32, NAV_R33, NAV_R34, NAV_R35, NAV_R36,
        _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, ooooooo, _______, _______, _______, _______, _______
    ),


    [L_FN] = LAYOUT_ortho_5x15(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NLCK, KC_CAPS, KC_SLCK, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        DF_TYPE, QK_VERS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, KC_INS,  _______, KC_VOLU, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        DF_GAME, QK_MAKE, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, MS_JIGL, _______, KC_MUTE, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
        _______, _______, K_SECR1, K_SECR2, K_SECR3, K_SECR4, _______, _______, _______, KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    // [L_MACROS] = LAYOUT_ortho_5x15(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, DM_REC2, DM_REC1, _______, _______, _______, _______, _______, SHEBANG, _______, _______, _______, _______,
    //     _______, QK_MAKE, _______, DM_PLY2, DM_PLY1, DM_RSTP, _______, _______, _______, PRG_NE,  PRG_EQ,  PRG_GEQ, PRG_LEQ, PRG_ARR, _______,
    //     _______, QK_VERS, _______, _______, _______, _______, _______, _______, _______, _______, PS_ITEM, FS_PIPE, _______, FS_ARR,  _______,
    //     _______, _______, _______, _______, ooooooo, _______, _______, _______, _______, ooooooo, _______, _______, _______, _______, _______
    // ),

    // // Template
    // [_LAYER] = LAYOUT_ortho_5x15(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    // ),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, L_SYMBOLS, L_NAVIGATION, L_MACROS);
// }
