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

// #define USER_CANCEL_KEY_ENABLE
#define USER_ENABLE_HOME_ROW_MODS

// Default: 200
#define TAPPING_TERM 200
// #define TAPPING_TERM_HOME_ROW_MODS (TAPPING_TERM + 100)
// #define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define ENABLE_COMPILE_KEYCODE

// Default: 50
#define COMBO_TERM               (TAPPING_TERM / 4)
#define COMBO_ONLY_FROM_LAYER 0

// #define COMBO_TERM_PER_COMBO
// #define COMBO_TERM_HOME_ROW_MODS COMBO_TERM - 30
// #define COMBO_TERM_LONG          (COMBO_TERM * 2)
// #define COMBO_HOLD               (COMBO_TERM * 3)
// #define COMBO_VARIABLE_LEN


// Tapping a oneshot key this many times will lock it until tapped again
// Default: 5
#define ONESHOT_TAP_TOGGLE 2

#undef MASTER_RIGHT
#define EE_HANDS

// "Super Alt-Tab"
// https://docs.qmk.fm/#/feature_macros?id=super-alt%E2%86%AFtab
// #define USER_SUPER_ALT_TAB_TIMEOUT 350


// RGB settings
// Disabling most of these saves a ton of FW space, and I honestly only
// use a few, anyway
//
// The TBK Mini's keyboard config.h explicitly enables all of these.
// I don't need most of them, and I need the firmware space for other
// features. With these three enabled, I have 108 bytes of EEPROM free.
//
// Unfortunately, that means I need to undefine most of these
// constants, one-by-one.

#ifdef RGB_MATRIX_ENABLE
// #    undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#    undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #    undef ENABLE_RGB_MATRIX_BREATHING
#    undef ENABLE_RGB_MATRIX_BAND_SAT
#    undef ENABLE_RGB_MATRIX_BAND_VAL
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    undef ENABLE_RGB_MATRIX_CYCLE_ALL
#    undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    undef ENABLE_RGB_MATRIX_DUAL_BEACON
#    undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    undef ENABLE_RGB_MATRIX_RAINDROPS
#    undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    undef ENABLE_RGB_MATRIX_HUE_BREATHING
#    undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#    undef ENABLE_RGB_MATRIX_HUE_WAVE
#    undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#    undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#    undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL

// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#    undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    undef ENABLE_RGB_MATRIX_SPLASH
#    undef ENABLE_RGB_MATRIX_MULTISPLASH
#    undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#    undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
