// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "config.h"
#include "replicaJunction.h"

// Home row mods
#define GUI_R LGUI_T(KC_R)
#define ALT_S LALT_T(KC_S)
#define SFT_N LSFT_T(KC_N)
#define CTR_T LCTL_T(KC_T) // because CTL_T means something different

#define GUI_C RGUI_T(KC_C)
#define ALT_I RALT_T(KC_I)
#define SFT_E RSFT_T(KC_E)
#define CTL_A LCTL_T(KC_A)

#include "g/keymap_combo.h"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_BASE] = LAYOUT(
    KC_V,   KC_F,   KC_H,   KC_G,   KC_K,                   KC_MINS,KC_U,   KC_O,   KC_Y,   KC_W,
    GUI_R,  ALT_S,  SFT_N,  CTR_T,  KC_P,                   KC_J,   CTL_A,  SFT_E,  ALT_I,  GUI_C,
    KC_X,   KC_M,   KC_L,   KC_D,   KC_B,   TG_GAME,KC_NO,  KC_EQL, KC_DOT, KC_COMM,KC_DQUO,KC_QUOT,
    xxxxxxx,xxxxxxx,xxxxxxx,KC_LSFT,KC_BSPC,CTL_BSP,KC_ENT, SPC_NAV,KC_RSFT,xxxxxxx,xxxxxxx,xxxxxxx
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
        case CTR_T:
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


////////////////////////////////////////////////////////////////////////
// Key overrides
////////////////////////////////////////////////////////////////////////

const key_override_t minus_plus_override = ko_make_basic(MOD_MASK_SHIFT,KC_MINS, KC_PLUS);
const key_override_t dot_colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,KC_COLN);
const key_override_t comma_scln_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t eql_unds_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_UNDS);
const key_override_t dquo_ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, KC_QUES);
const key_override_t quote_exlm_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_EXLM);
const key_override_t slash_pipe_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_PIPE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &minus_plus_override,
    &dot_colon_override,
    &comma_scln_override,
    &eql_unds_override,
    &dquo_ques_override,
    &quote_exlm_override,
    &slash_pipe_override,
	NULL // Null terminate the array of overrides!
};


////////////////////////////////////////////////////////////////////////
// Combos
////////////////////////////////////////////////////////////////////////

// The full combo definitions are defined in combos.def using the
// GBoards combo engine.
//
// See here for more information:
// http://combos.gboards.ca/

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    if (combo->keys[0] == KC_K && combo->keys[1] == KC_M) {
        return COMBO_TERM_LONG;
    }

    if (combo->keys[0] == KC_M && combo->keys[1] == KC_F) {
        return COMBO_TERM_LONG;
    }

    return COMBO_TERM;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}
