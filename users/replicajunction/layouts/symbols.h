#pragma once
#include "quantum.h"

// This allows 40% boards and larger boards to share the same "numpad"
// definitions, but change whether they are the numpad/keypad codes
// or the number row keycodes. 40% keyboards typically don't have
// the numpad.

#if defined(USER_USE_NUMPAD_KP_CODES)
#    define USER_NUMPAD_1    KC_P1
#    define USER_NUMPAD_2    KC_P2
#    define USER_NUMPAD_3    KC_P3
#    define USER_NUMPAD_4    KC_P4
#    define USER_NUMPAD_5    KC_P5
#    define USER_NUMPAD_6    KC_P6
#    define USER_NUMPAD_7    KC_P7
#    define USER_NUMPAD_8    KC_P8
#    define USER_NUMPAD_9    KC_P9
#    define USER_NUMPAD_0    KC_P0
#    define USER_NUMPAD_DOT  KC_PDOT
#    define USER_NUMPAD_PLUS KC_PPLS
#    define USER_NUMPAD_MINS KC_PMNS
#else
#    define USER_NUMPAD_1    KC_1
#    define USER_NUMPAD_2    KC_2
#    define USER_NUMPAD_3    KC_3
#    define USER_NUMPAD_4    KC_4
#    define USER_NUMPAD_5    KC_5
#    define USER_NUMPAD_6    KC_6
#    define USER_NUMPAD_7    KC_7
#    define USER_NUMPAD_8    KC_8
#    define USER_NUMPAD_9    KC_9
#    define USER_NUMPAD_0    KC_0
#    define USER_NUMPAD_DOT  KC_DOT
#    define USER_NUMPAD_PLUS KC_PLUS
#    define USER_NUMPAD_MINS KC_MINS
#endif

// Number row; not on 40% boards
#define SYM_L00 _______
#define SYM_L01 KC_F1
#define SYM_L02 KC_F2
#define SYM_L03 KC_F3
#define SYM_L04 KC_F4
#define SYM_L05 KC_F5
#define SYM_L06 KC_F11

#define SYM_R00 KC_F12
#define SYM_R01 KC_F6
#define SYM_R02 KC_F7
#define SYM_R03 KC_F8
#define SYM_R04 KC_F9
#define SYM_R05 KC_F10
#define SYM_R06 _______

// Top alpha row
#define SYM_L10 _______
#define SYM_L11 KC_GRV
#define SYM_L12 KC_PLUS
#define SYM_L13 KC_ASTR
#define SYM_L14 _______
#define SYM_L15 KC_TILD
#define SYM_L16 _______

#define SYM_R10 _______
#define SYM_R11 _______
#define SYM_R12 KC_CIRC
#define SYM_R13 KC_DLR
#define SYM_R14 KC_HASH
#define SYM_R15 _______
#define SYM_R16 _______

// Home row
#define SYM_L20 _______
#define SYM_L21 KC_PIPE
#define SYM_L22 KC_LCBR
#define SYM_L23 KC_RCBR
#define SYM_L24 KC_MINS
#define SYM_L25 KC_EXLM
#define SYM_L26 _______ // Not on Ergodox

#define SYM_R20 _______ // Not on Ergodox
#define SYM_R21 REPEAT
#define SYM_R22 KC_QUES
#define SYM_R23 KC_LBRC
#define SYM_R24 KC_RBRC
#define SYM_R25 _______
#define SYM_R26 _______

// Bottom alpha row
#define SYM_L30 _______
#define SYM_L31 KC_BSLS
#define SYM_L32 KC_LT
#define SYM_L33 KC_GT
#define SYM_L34 KC_PERC
#define SYM_L35 _______
#define SYM_L36 _______

#define SYM_R30 _______
#define SYM_R31 KC_SLSH
#define SYM_R32 KC_UNDS
#define SYM_R33 KC_LPRN
#define SYM_R34 KC_RPRN
#define SYM_R35 KC_AMPR
#define SYM_R36 _______
