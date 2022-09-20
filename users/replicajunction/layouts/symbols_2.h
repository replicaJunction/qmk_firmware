#pragma once
#include "quantum.h"

// Number row; not on 40% boards
#define SM2_L00 _______
#define SM2_L01 KC_F1
#define SM2_L02 KC_F2
#define SM2_L03 KC_F3
#define SM2_L04 KC_F4
#define SM2_L05 KC_F5
#define SM2_L06 KC_F11

#define SM2_R00 KC_F12
#define SM2_R01 KC_F6
#define SM2_R02 KC_F7
#define SM2_R03 KC_F8
#define SM2_R04 KC_F9
#define SM2_R05 KC_F10
#define SM2_R06 _______

// Top alpha row
#define SM2_L10 _______
#define SM2_L11 TO(0)
#define SM2_L12 KC_MS_BTN1
#define SM2_L13 KC_MS_UP
#define SM2_L14 KC_MS_BTN2
#define SM2_L15 _______
#define SM2_L16 _______

#define SM2_R10 _______
#define SM2_R11 _______
#define SM2_R12 KC_AMPR
#define SM2_R13 KC_GRV
#define SM2_R14 KC_TILD
#define SM2_R15 _______
#define SM2_R16 _______

// Home row
#define SM2_L20 _______
#define SM2_L21 TO(1)
#define SM2_L22 KC_MS_LEFT
#define SM2_L23 KC_MS_DOWN
#define SM2_L24 KC_MS_RIGHT // Homing key
#define SM2_L25 _______
#define SM2_L26 _______

#define SM2_R20 _______
#define SM2_R21 _______
#define SM2_R22 KC_DLR // Homing key
#define SM2_R23 KC_PERC
#define SM2_R24 KC_CIRC
#define SM2_R25 KC_UNDS
#define SM2_R26 _______

// Bottom alpha row
#define SM2_L30 _______
#define SM2_L31 _______
#define SM2_L32 KC_MS_BTN4
#define SM2_L33 KC_MS_BTN3
#define SM2_L34 KC_MS_BTN5
#define SM2_L35 _______
#define SM2_L36 _______

#define SM2_R30 _______
#define SM2_R31 _______
#define SM2_R32 KC_EXLM
#define SM2_R33 KC_AT
#define SM2_R34 KC_HASH
#define SM2_R35 RSFT(RALT(KC_DOT))
#define SM2_R36 _______

// Left hand thummb keys (2 is the "natural" resting key for the thumb)
#define SM2_LT1 _______
#define SM2_LT2 _______
#define SM2_LT3 _______

// Right hand thumb keys
#define SM2_RT1 _______
#define SM2_RT2 _______
#define SM2_RT3 _______
