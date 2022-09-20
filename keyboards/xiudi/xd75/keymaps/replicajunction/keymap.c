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
#define LA_MACR MO(L_MACROS)

#define SPC_NAV LT(L_NAVIGATION, KC_SPC)

#define DF_TYPE DF(L_BASE)
#define DF_GAME DF(L_GAMING)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_ortho_5x15(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KL_L10,  KL_L11,  KL_L12,  KL_L13,  KL_L14,  KL_L15,  KC_LBRC, KC_BSLS, KC_RBRC, KL_R11,  KL_R12,  KL_R13,  KL_R14,  KL_R15,  KL_R16,
        KL_L20,  KL_LH1,  KL_LH2,  KL_LH3,  KL_LH4,  KL_L25,  KC_HOME, KC_UP,   KC_END,  KL_R21,  KL_RH2,  KL_RH3,  KL_RH4,  KL_RH5,  KL_R26,
        KL_L30,  KL_L31,  KL_L32,  KL_L33,  KL_L34,  KL_L35,  KC_LEFT, KC_DOWN, KC_RGHT, KL_R31,  KL_R32,  KL_R33,  KL_R34,  KL_R35,  KL_R36,
        KC_LCTL, KC_LGUI, KC_LALT, LA_SYM,  KL_LT1,  KL_LT2,  KL_LT3,  KC_ENT,  KL_RT1,  KL_RT2,  KL_RT3,  LA_FN,   KC_RALT, KC_RGUI, LA_MACR
    ),


    [L_GAMING] = LAYOUT_ortho_5x15(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_HOME,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_BTN1, KC_BTN2, KC_BTN3, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_UP,   KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LOCK, KC_LALT, LA_FN,   KC_LSFT, KC_SPC,  KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_SPC,  LA_FN,   KC_RALT, KC_RGUI, LA_MACR
    ),


    [L_SYMBOLS] = LAYOUT_ortho_5x15(
        SYM_L00, SYM_L01, SYM_L02, SYM_L03, SYM_L04, SYM_L05, SYM_L06, _______, SYM_R00, SYM_R01, SYM_R02, SYM_R03, SYM_R04, SYM_R05, SYM_R06,
        SYM_L10, SYM_L11, SYM_L12, SYM_L13, SYM_L14, SYM_L15, SYM_L16, _______, SYM_R10, SYM_R11, SYM_R12, SYM_R13, SYM_R14, SYM_R15, SYM_R16,
        SYM_L20, SYM_L21, SYM_L22, SYM_L23, SYM_L24, SYM_L25, SYM_L26, _______, SYM_R20, SYM_R21, SYM_R22, SYM_R23, SYM_R24, SYM_R25, SYM_R26,
        SYM_L30, SYM_L31, SYM_L32, SYM_L33, SYM_L34, SYM_L35, SYM_L36, _______, SYM_R30, SYM_R31, SYM_R32, SYM_R33, SYM_R34, SYM_R35, SYM_R36,
        _______, _______, _______, _______, SYM_LT1, SYM_LT2, SYM_LT3, _______, SYM_RT1, SYM_RT2, SYM_RT3, _______, _______, _______, _______
    ),


    [L_SYMBOLS_2] = LAYOUT_ortho_5x15(
        SM2_L00, SM2_L01, SM2_L02, SM2_L03, SM2_L04, SM2_L05, SM2_L06, _______, SM2_R00, SM2_R01, SM2_R02, SM2_R03, SM2_R04, SM2_R05, SM2_R06,
        SM2_L10, SM2_L11, SM2_L12, SM2_L13, SM2_L14, SM2_L15, SM2_L16, _______, SM2_R10, SM2_R11, SM2_R12, SM2_R13, SM2_R14, SM2_R15, SM2_R16,
        SM2_L20, SM2_L21, SM2_L22, SM2_L23, SM2_L24, SM2_L25, SM2_L26, _______, SM2_R20, SM2_R21, SM2_R22, SM2_R23, SM2_R24, SM2_R25, SM2_R26,
        SM2_L30, SM2_L31, SM2_L32, SM2_L33, SM2_L34, SM2_L35, SM2_L36, _______, SM2_R30, SM2_R31, SM2_R32, SM2_R33, SM2_R34, SM2_R35, SM2_R36,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    [L_NAVIGATION] = LAYOUT_ortho_5x15(
        NAV_L00, NAV_L01, NAV_L02, NAV_L03, NAV_L04, NAV_L05, _______, _______, _______, NAV_R01, NAV_R02, NAV_R03, NAV_R04, NAV_R05, NAV_R06,
        NAV_L10, NAV_L11, NAV_L12, NAV_L13, NAV_L14, NAV_L15, _______, _______, _______, NAV_R11, NAV_R12, NAV_R13, NAV_R14, NAV_R15, NAV_R16,
        NAV_L20, NAV_L21, NAV_L22, NAV_L23, NAV_L24, NAV_L25, _______, _______, _______, NAV_R21, NAV_R22, NAV_R23, NAV_R24, NAV_R25, NAV_R26,
        NAV_L30, NAV_L31, NAV_L32, NAV_L33, NAV_L34, NAV_L35, _______, _______, _______, NAV_R31, NAV_R32, NAV_R33, NAV_R34, NAV_R35, NAV_R36,
        _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, ooooooo, _______, _______, _______, _______, _______
    ),


    [L_FN] = LAYOUT_ortho_5x15(
        FUN_L00, FUN_L01, FUN_L02, FUN_L03, FUN_L04, FUN_L05, KC_NLCK, KC_CAPS, KC_SLCK, FUN_R01, FUN_R02, FUN_R03, FUN_R04, FUN_R05, FUN_R06,
        FUN_L10, FUN_L11, FUN_L12, FUN_L13, FUN_L14, FUN_L15, FUN_L16, KC_INS,  FUN_R10, FUN_R11, FUN_R12, FUN_R13, FUN_R14, FUN_R15, FUN_R16,
        FUN_L20, FUN_L21, FUN_L22, FUN_L23, FUN_L24, FUN_L25, FUN_L26, MS_JIGL, FUN_R20, FUN_R21, FUN_R22, FUN_R23, FUN_R24, FUN_R25, FUN_R26,
        FUN_L30, FUN_L31, FUN_L32, FUN_L33, FUN_L34, FUN_L35, FUN_L36, _______, FUN_R30, FUN_R31, FUN_R32, FUN_R33, FUN_R34, FUN_R35, FUN_R36,
        _______, _______, _______, _______, FUN_LT1, FUN_LT2, FUN_LT3, _______, FUN_RT1, FUN_RT2, FUN_RT3, _______, _______, _______, _______
    ),


    [L_MACROS] = LAYOUT_ortho_5x15(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, DM_REC2, DM_REC1, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, DM_PLY2, DM_PLY1, DM_RSTP, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, K_SECR1, K_SECR2, K_SECR3, K_SECR4, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ooooooo
    ),


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
