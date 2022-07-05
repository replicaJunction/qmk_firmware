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

#define USER_CANCEL_KEY_ENABLE
#define USER_ENABLE_HOME_ROW_MODS

// Default: 200
#define TAPPING_TERM 200
#define TAPPING_TERM_HOME_ROW_MODS (TAPPING_TERM + 100)
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define ENABLE_COMPILE_KEYCODE

// Default: 50
#define COMBO_TERM 40

// #define COMBO_TERM_PER_COMBO
// #define COMBO_VARIABLE_LEN

#define COMBO_ONLY_FROM_LAYER 0

#define ADAPTIVE_KEY_TERM TAPPING_TERM

// Tapping a oneshot key this many times will lock it until tapped again
// Default: 5
#define ONESHOT_TAP_TOGGLE 2


// "Super Alt-Tab"
// https://docs.qmk.fm/#/feature_macros?id=super-alt%E2%86%AFtab
#define USER_SUPER_ALT_TAB_TIMEOUT 350
