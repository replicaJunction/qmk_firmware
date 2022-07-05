#pragma once
#include "quantum.h"

// Left hand top row (1 = QWERTY Q)
#define KL_L10 KC_EQL  // Outermost column, not on Atreus
#define KL_L11 KC_Q
#define KL_L12 KC_W
#define KL_L13 KC_F
#define KL_L14 KC_P
#define KL_L15 KC_B
#ifdef USER_NUM_WORD_ENABLE
#    define KL_L16 NUMWORD
#else
#    define KL_L16 xxxxxxx
#endif

// Right hand top row (1 = QWERTY Y)
#ifdef USER_CAPS_WORD_ENABLE
#    define KL_R01 CAPWORD
#else
#    define KL_R01 xxxxxxx
#endif
#define KL_R11 KC_J
#define KL_R12 KC_L
#define KL_R13 KC_U
#define KL_R14 KC_Y
#define KL_R15 KC_SCLN
#define KL_R16 KC_BSLS // Outermost column

// Left hand home row
#define KL_L20 OSL(USER_LAYER_NUMBER)
#define KL_L21 KC_A
#define KL_L22 KC_R
#define KL_L23 KC_S
#define KL_L24 KC_T
#define KL_L25 KC_G

// Right hand home row
#define KL_R21 KC_M
#define KL_R22 KC_N
#define KL_R23 KC_E
#define KL_R24 KC_I
#define KL_R25 KC_O
#define KL_R26 KC_QUOT

// Left hand bottom row
#define KL_L30 KC_LSFT
#define KL_L31 KC_Z
#define KL_L32 KC_X
#define KL_L33 KC_C
#define KL_L34 KC_D
#define KL_L35 KC_V

// Right hand bottom row
#define KL_R31 KC_K
#define KL_R32 KC_H
#define KL_R33 KC_COMM
#define KL_R34 KC_DOT
#define KL_R35 KC_SLSH
#define KL_R36 OSL(L_FUNC)

// Left hand thummb keys (2 is the "natural" resting key for the thumb)
// #define KL_LT1 KC_LSFT
#define KL_LT1 KC_BSPC
#define KL_LT2 COS_SFT
#define KL_LT3 REPEAT

// Right hand thumb keys
#define KL_RT1 KC_ENT
#define KL_RT2 LT(L_NAVIGATION, KC_SPC)
#define KL_RT3 OSL(USER_LAYER_NUMBER)
