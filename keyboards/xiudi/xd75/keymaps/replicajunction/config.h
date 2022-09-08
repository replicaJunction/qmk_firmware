/* Copyright 2021-2022 Joshua T.
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

// Layer definitions.
// These need to be available for my userspace stuff, but this file
// also gets included as an assembly file, so we can't use an enum
// here. That results in this error:
//     Error: unknown opcode `enum'

#define L_BASE 0
#define L_GAMING 1
#define L_NUMBERS 2
#define L_SYMBOLS 3
#define L_NAVIGATION 4
#define L_FN 5
#define L_MACROS 6

// Define layer aliases used in userspace functions, like kb_layout
// and numword
#define USER_LAYER_NUMBER L_NUMBERS
#define USER_LAYER_SYMBOLS L_SYMBOLS
#define USER_LAYER_FUNCTION L_FN

// Define the layer to be placed on the escape LT()
#define USER_LAYER_ESCAPE_COMBO L_SYMBOLS
#define USER_LAYER_EQUALS_COMBO L_SYMBOLS

////////////////////////
// QMK config settings
////////////////////////

// Gotta go fast
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

// Enable the QK_MAKE keycode
#define ENABLE_COMPILE_KEYCODE

// Default: 200
#define TAPPING_TERM 200
// #define TAPPING_TERM_HOME_ROW_MODS (TAPPING_TERM + 100)
// #define TAPPING_TERM_PER_KEY

// Default: 50
#define COMBO_TERM 50
#define COMBO_TERM_HOME_ROW 35
#define COMBO_TERM_PER_COMBO
// #define COMBO_VARIABLE_LEN
#define COMBO_ONLY_FROM_LAYER L_BASE

// Tapping a oneshot key this many times will lock it until tapped again
// Default: 5
#define ONESHOT_TAP_TOGGLE 2

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300

// "Super Alt-Tab"
// https://docs.qmk.fm/#/feature_macros?id=super-alt%E2%86%AFtab
#define USER_SUPER_ALT_TAB_TIMEOUT 350

////////////////////////
// Userspace settings
////////////////////////

// #define USER_CANCEL_KEY_ENABLE
#define USER_ENABLE_HOME_ROW_MODS

#define ADAPTIVE_TERM 200

// Set the number/symbol layer to send numpad keycodes, not real number
// row keycodes
#define USER_USE_NUMPAD_KP_CODES
