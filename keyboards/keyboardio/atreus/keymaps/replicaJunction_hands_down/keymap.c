// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "config.h"
#include "lib/replicaJunction.h"




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_BASE] = LAYOUT(
    KC_J,   KC_K,   KC_M,   KC_F,   KC_V,                   KC_MINS,KC_U,   KC_O,   KC_Y,   KC_W,
    // KC_R,   KC_S,   KC_N,   KC_H,   KC_P,                   KC_DOT, KC_A,   KC_E,   KC_I,   KC_C,
    GUI_R,  ALT_S,  SFT_N,  CTL_H,  KC_P,                   KC_COMM,CTL_A,  SFT_E,  ALT_I,  GUI_C,
    KC_X,   KC_G,   KC_L,   KC_D,   KC_B,   TG_GAME,KC_NO,  KC_QUES,KC_DOT, KC_EQL, KC_DQUO,KC_QUOT,
    xxxxxxx,xxxxxxx,xxxxxxx,KC_LSFT,KC_T,   CTL_BSP,KC_ENT, SPC_NAV,KC_RSFT,xxxxxxx,xxxxxxx,xxxxxxx
),

[L_NAVIGATION] = LAYOUT(
    _______,_______,_______,_______,_______,                KC_PGUP,KC_HOME,KC_UP,  KC_END, KC_DEL,
    KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______,                KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,KC_BSPC,
    _______,_______,_______,_______,_______,_______,_______,OS_SNIP,SFT_TAB,KC_TAB, KC_APP, KC_PSCR,
    _______,_______,_______,_______,KC_BSPC,_______,_______,ooooooo,_______,_______,_______,_______
),

[L_NUMBERS] = LAYOUT(
    _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
    KC_6,   KC_4,   KC_0,   KC_2,   _______,                KC_DOT, KC_3,   KC_1,   KC_5,   KC_7,
    _______,_______,_______,KC_8,   _______,_______,_______,_______,KC_9,   _______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

[L_SYMBOLS] = LAYOUT(
    _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
    KC_LCBR,KC_RCBR,KC_LPRN,KC_RPRN,_______,                _______,KC_ASTR,KC_CIRC,KC_DLR, KC_AMPR,
    KC_LT,  KC_GT,  KC_LBRC,KC_RBRC,_______,_______,_______,_______,KC_PERC,KC_BSLS,KC_TILD,KC_GRV,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

[L_GAMING] = LAYOUT(
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,                   KC_T,   KC_Y,   KC_U,   KC_I,   KC_BTN1,
    KC_ESC, KC_A,   KC_S,   KC_D,   KC_F,                   KC_G,   KC_H,   KC_J,   KC_K,   KC_BTN2,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   ooooooo,KC_LOCK,KC_B,   KC_N,   KC_M,   KC_COMM,KC_BTN3,
    _______,_______,KC_LALT,KC_LSFT,KC_SPC, MO_GAM2,_______,_______,_______,_______,_______,_______
),

[L_GAMING2] = LAYOUT(
    _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,                  _______,_______,_______,_______,_______,
    _______,KC_1,   KC_2,   KC_3,   KC_4,                   _______,_______,_______,_______,_______,
    _______,KC_5,   KC_6,   KC_7,   KC_8,   _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,ooooooo,_______,_______,_______,_______,_______,_______
),

// Template
// [L_FUNC] = LAYOUT(
//     _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
// ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_R:
        case ALT_S:
        case SFT_N:
        case CTL_H:
        case GUI_C:
        case ALT_I:
        case SFT_E:
        case CTL_A:
            return TAPPING_TERM_HOME_ROW_MODS;
        default:
            return TAPPING_TERM;
    }
}

// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     // "Rolled modifiers cancellation"
//     // https://precondition.github.io/home-row-mods#rolled-modifiers-cancellation
//     switch (keycode) {
//         case CTL_A:
//             break;
//     }

//     return true;
// }
