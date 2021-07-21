// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "version.h"

enum layer_names {
    _QW,
    _RS,
    _LW,
};

enum custom_keycodes {
    KC_TADP = SAFE_RANGE,
    KC_FLSH
};

#define ALT_ENT LALT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  KC_LCTL, ALT_ENT, KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_ENT ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_DLR,  KC_PERC,                  KC_PGUP, KC_7,    KC_8,   KC_9, KC_BSPC,
    KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,                  KC_PGDN, KC_4,    KC_5,   KC_6, KC_BSLS,
    KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR,KC_ASTR, KC_1,    KC_2,   KC_3, KC_PLUS,
    TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,   _______, KC_TADP, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case KC_TADP:
            toggle_adaptive_keys();
            return false;
        case KC_FLSH:
            SEND_STRING("qmk flash --keyboard " QMK_KEYBOARD " --keymap " QMK_KEYMAP);
            return false;
        default:
            return true;
    }
}

const adaptive_key_t qw_qu_adaptive = ADAPTIVE_KEY(KC_Q, KC_W, KC_U);
const adaptive_key_t hj_hi_adaptive = ADAPTIVE_KEY(KC_H, KC_J, KC_I);

// The next few are gimmicks that people would probably never want.
// These are for testing features, not really meant to be useful.

// Testing use of LALT_T(KC_ENT) as a trigger
const adaptive_key_t dot_ent_adaptive = ADAPTIVE_KEY(KC_DOT, ALT_ENT, KC_EXLM);

// Testing a custom keycode as the replacement
const adaptive_key_t qa_make_adaptive = ADAPTIVE_KEY(KC_Q, KC_A, KC_FLSH);

// Adaptive keys settings
const adaptive_key_t **adaptive_keys = (const adaptive_key_t *[]){
    &qw_qu_adaptive,
    &hj_hi_adaptive,
    &dot_ent_adaptive,
    &qa_make_adaptive,
    NULL
};

const adaptive_key_t vowel_dot_bang_adaptive = ADAPTIVE_KEY(KC_NO, KC_DOT, KC_EXLM);

const adaptive_key_t *try_get_adaptive_key_user(uint16_t prefix, uint16_t keycode) {
    if (keycode == KC_DOT && (prefix == KC_A || prefix == KC_E || prefix == KC_I || prefix == KC_O || prefix == KC_U)) {
        return &vowel_dot_bang_adaptive;
    }

    return NULL;
}
