#pragma once
#include "quantum.h"

// Number row; not on 40% boards
#define FUN_L00 QK_BOOT
#define FUN_L01 KC_F1
#define FUN_L02 KC_F2
#define FUN_L03 KC_F3
#define FUN_L04 KC_F4
#define FUN_L05 KC_F5
#define FUN_L06 _______

#define FUN_R00 _______
#define FUN_R01 KC_F6
#define FUN_R02 KC_F7
#define FUN_R03 KC_F8
#define FUN_R04 KC_F9
#define FUN_R05 KC_F10
#define FUN_R06 _______

// Top alpha row
#if defined(L_GAMING)
#    define FUN_L10 DF_TYPE
#else
#    define FUN_L10 _______
#endif
#define FUN_L11 KC_MEDIA_STOP
#define FUN_L12 KC_MEDIA_PREV_TRACK
#define FUN_L13 KC_MEDIA_PLAY_PAUSE
#define FUN_L14 KC_MEDIA_NEXT_TRACK
#define FUN_L15 LGUI(LSFT(KC_Q)) // PowerToys - mic/camera mute
#define FUN_L16 _______

#define FUN_R10 _______
#define FUN_R11 KC_F12
#define FUN_R12 KC_F7
#define FUN_R13 KC_F8
#define FUN_R14 KC_F9
#define FUN_R15 LCTL(KC_PLUS)
#define FUN_R16 _______

// Home row
#if defined(L_GAMING)
#    define FUN_L20 DF_GAME
#else
#    define FUN_L20 _______
#endif
#define FUN_L21 COS_GUI
#define FUN_L22 COS_ALT
#define FUN_L23 COS_SFT
#define FUN_L24 COS_CTL // Homing key
#define FUN_L25 _______
#define FUN_L26 _______ // Not on Ergodox

#define FUN_R20 _______ // Not on Ergodox
#define FUN_R21 KC_F11
#define FUN_R22 KC_F4   // Homing key
#define FUN_R23 KC_F5
#define FUN_R24 KC_F6
#define FUN_R25 LCTL(KC_MINS)
#define FUN_R26 _______

// Bottom alpha row
#define FUN_L30 _______
#define FUN_L31 KC_AUDIO_MUTE
#define FUN_L32 KC_AUDIO_VOL_DOWN
#define FUN_L33 LCTL(LSFT(KC_C))
#define FUN_L34 KC_AUDIO_VOL_UP
#define FUN_L35 LGUI(KC_V)        // Windows clipboard history
#define FUN_L36 _______

#define FUN_R30 _______
#define FUN_R31 KC_F10
#define FUN_R32 KC_F1
#define FUN_R33 KC_F2
#define FUN_R34 KC_F3
#define FUN_R35 LCTL(KC_0)
#define FUN_R36 _______

// Left hand thummb keys (2 is the "natural" resting key for the thumb)
#define FUN_LT1 _______
#define FUN_LT2 _______
#define FUN_LT3 _______

// Right hand thumb keys
#define FUN_RT1 QK_BOOT
#define FUN_RT2 KC_ENTER
#define FUN_RT3 QK_MAKE
