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
#include "quantum.h"

// Custom keycodes and macros
enum userspace_custom_keycodes {
    QK_FLSH = SAFE_RANGE,  // QMK flash command
    QK_VERS,               // QMK version

#ifdef USER_CALLUM_ONESHOT_ENABLE
    COS_SFT,
    COS_CTL,
    COS_ALT,
    COS_GUI,
#endif

#ifdef USER_PROGRAMMING_MACRO_KEYCODES
    // Programming macros
    PRG_EQ,                // ==
    PRG_NE,                // !=
    PRG_GEQ,               // >=
    PRG_LEQ,               // <=
    PRG_ARR,               // =>
    PS_ITEM,               // $_        (PowerShell - $PSItem variable)
    FS_PIPE,               // |>        (F# pipe operator)
    FS_ARR,                // ->        (F# lambda / pattern matching)
    SHEBANG,               // #!
#endif

#ifdef USER_CAPS_WORD_ENABLE
    CAPWORD,
#endif

#ifdef USER_NUM_WORD_ENABLE
    NUMWORD,
#endif

#ifdef USER_CANCEL_KEY_ENABLE
    CANCEL,
#endif

    // // USER_ENABLE_CUSTOM_SHIFT_CODES
    // // Custom characters that send different symbols than usual when shifted
    // KCC_COM,                // , or !
    // KCC_DOT,                // . or @
    // KCC_QUO,                // ' or ~

#ifdef USER_MOUSE_JIGGLE_ENABLE
    MS_JIGL,
#endif

#ifdef USER_SUPER_ALT_TAB_ENABLE
    SALTTAB,
#endif

#ifdef USER_REPEAT_KEY_ENABLE
    REPEAT,
#endif

    // USER_ENABLE_SECRETS
    K_SECR1,
    K_SECR2,
    K_SECR3,
    K_SECR4,

    DYNAMIC_MACRO_RANGE
};
