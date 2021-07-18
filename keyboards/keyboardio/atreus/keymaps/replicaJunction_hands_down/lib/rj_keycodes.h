#pragma once
#include "quantum.h"
#include "rj_layers.h"

enum user_keycodes {
    NUMWORD = SAFE_RANGE,
    CAPWORD,

#ifdef USER_INCLUDE_LAYER_GAMING
    TG_GAME,
#endif

    KEYMAP_SAFE_RANGE
};


// Aliases

// The comments here may seem useless, but they provide tooltip support
// for VS Code. This is handy if I forget whether something means
// LSFT(KC_TAB) or LSFT_T(KC_TAB)

// Blocked / no function
#define xxxxxxx KC_NO

// Transparent, but needs to remain empty (i.e. a layer toggle)
#define ooooooo _______

// Shift+Tab
#define SFT_TAB LSFT(KC_TAB)

// Ctrl+Backspace
#define CTL_BSP LCTL(KC_BSPC)

// Windows Snipping Tool (screenshot)
#define OS_SNIP LGUI(LSFT(KC_S))

// Layer navigation

// Space on press, Nav layer on hold
#define SPC_NAV LT(L_NAVIGATION, KC_SPC)

#ifdef USER_INCLUDE_LAYER_GAMING
#   ifdef USER_INCLUDE_LAYER_GAMING_2
#       define MO_GAM2 MO(L_GAMING2)
#   endif
#endif

// Home row mods
#define GUI_R LGUI_T(KC_R)
#define ALT_S LALT_T(KC_S)
#define SFT_N LSFT_T(KC_N)
#define CTL_H LCTL_T(KC_H)

#define GUI_C RGUI_T(KC_C)
#define ALT_I RALT_T(KC_I)
#define SFT_E RSFT_T(KC_E)
#define CTL_A LCTL_T(KC_A)
