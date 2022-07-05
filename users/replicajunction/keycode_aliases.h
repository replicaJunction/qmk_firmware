/* Copyright 2021 Joshua T.
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

#pragma once

#include QMK_KEYBOARD_H

// Transparent, but indicates that this key must be blocked (for example, a layer shift key)
#define ooooooo KC_TRNS

// Nothing
#define xxxxxxx KC_NO


#define SFT_TAB  LSFT(KC_TAB)
#define SFT_G    LSFT(KC_G)
#define WIN_TAB  LGUI(KC_TAB)
#define WIN_L    LGUI(KC_L)
#define WIN_V    LGUI(KC_V)
#define ALT_F4   LALT(KC_F4)
#define CTL_DEL  LCTL_T(KC_DEL)
#define CTL_ESC  CTL_T(KC_ESC)
#define ALT_ENT  ALT_T(KC_ENT)
#define ALT_TAB  ALT_T(KC_TAB)

#define OSM_LSF OSM(MOD_LSFT)
#define OSM_RSF OSM(MOD_RSFT)

// OS shortcuts (Windows)
#define OS_COPY LCTL(KC_C)
#define OS_PAST LCTL(KC_V)
#define OS_CUT  LCTL(KC_X)
#define OS_UNDO LCTL(KC_Z)
#define OS_SALL LCTL(KC_A)
#define OS_FIND LCTL(KC_F)

// Windows 10 Snipping Tool
#define OS_SNIP LGUI(LSFT(KC_S))

// Ctrl+Alt+Delete
#define CTALDEL LCTL(LALT(KC_DEL))

// Mouse keys
#define M_UP KC_MS_UP
#define M_DOWN KC_MS_DOWN
#define M_LEFT KC_MS_LEFT
#define M_RIGHT KC_MS_RIGHT
#define M_LCLIK KC_MS_BTN1
#define M_RCLIK KC_MS_BTN2
#define M_MCLIK KC_MS_BTN3
#define M_WHLUP KC_WH_U
#define M_WHLDN KC_WH_D


// Windows 10 shortcuts: change desktop to the left/right
#define DESKLFT LCTL(LGUI(KC_LEFT))
#define DESKRGT LCTL(LGUI(KC_RGHT))

// Application-specific shortcuts

// Search: defined in Everything Search Engine as the keypress to show/hide the window
#define SEARCH HYPR(KC_S)

// Microsoft PowerToys hotkeys
// https://github.com/microsoft/PowerToys
#define PTYRUN  LALT(KC_SPC)       // PowerToys Run
#define PTYZONE LGUI(KC_GRV)       // PowerToys FancyZones
#define PTYCOLR LGUI(LSFT(KC_C))   // PowerToys ColorPicker

// PowerToys Run
#define LAUNCH LALT(KC_SPC)

#define PTYMUTE LGUI(KC_N)
