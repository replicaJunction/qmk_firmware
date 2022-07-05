#pragma once
#include "quantum.h"

// Number row; not on 40% boards
#define NAV_L00 _______
#define NAV_L01 KC_F1
#define NAV_L02 KC_F2
#define NAV_L03 KC_F3
#define NAV_L04 KC_F4
#define NAV_L05 KC_F5
#define NAV_L06 _______

#define NAV_R00 _______
#define NAV_R01 KC_F6
#define NAV_R02 KC_F7
#define NAV_R03 KC_F8
#define NAV_R04 KC_F9
#define NAV_R05 KC_F10
#define NAV_R06 KC_F11

// Top alpha row
#define NAV_L10 _______
#define NAV_L11 _______
#define NAV_L12 _______
#define NAV_L13 _______
#define NAV_L14 LGUI(LSFT(KC_Q)) // PowerToys - mic/camera mute
#define NAV_L15 _______
#define NAV_L16 _______

#define NAV_R10 _______
#define NAV_R11 KC_PGUP
#define NAV_R12 KC_HOME
#define NAV_R13 KC_UP
#define NAV_R14 KC_END
#define NAV_R15 _______
#define NAV_R16 KC_F12

// Home row
#define NAV_L20 _______
#define NAV_L21 COS_GUI
#define NAV_L22 COS_ALT
#define NAV_L23 COS_SFT
#define NAV_L24 COS_CTL // Homing key
#define NAV_L25 _______
#define NAV_L26 _______ // Not on Ergodox

#define NAV_R20 _______ // Not on Ergodox
#define NAV_R21 KC_PGDN
#define NAV_R22 KC_LEFT // Homing key
#define NAV_R23 KC_DOWN
#define NAV_R24 KC_RGHT
#define NAV_R25 KC_DEL
#define NAV_R26 _______

// Bottom alpha row
#define NAV_L30 _______
#define NAV_L31 _______
#define NAV_L32 _______
#define NAV_L33 LGUI(KC_V)   // Windows clipboard history
#define NAV_L34 LALT(KC_SPC) // PowerToys Run
#define NAV_L35 HYPR(KC_S)   // Everything Search Engine
#define NAV_L36 _______

#define NAV_R30 _______
#define NAV_R31 LGUI(LSFT(KC_S)) // Windows Snipping Tool (screenshots)
#define NAV_R32 LSFT(KC_TAB)
#define NAV_R33 KC_TAB
#define NAV_R34 _______
#define NAV_R35 _______
#define NAV_R36 _______
