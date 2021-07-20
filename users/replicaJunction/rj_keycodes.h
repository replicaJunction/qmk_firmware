#pragma once
#include "quantum.h"
#include "rj_layers.h"

enum user_keycodes {
    QK_MAKE = SAFE_RANGE,  // QMK make command
    QK_FLSH,               // QMK flash command
    QK_VERS,               // QMK version

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

#ifdef USER_NUM_WORD_ENABLE
    NUMWORD,
#endif

#ifdef USER_CAPS_WORD_ENABLE
    CAPWORD,
#endif

#ifdef USER_INCLUDE_LAYER_GAMING
    TG_GAME,
#endif

    // // USER_ENABLE_CUSTOM_SHIFT_CODES
    // // Custom characters that send different symbols than usual when shifted
    // KCC_COM,                // , or !
    // KCC_DOT,                // . or @
    // KCC_QUO,                // ' or ~

    // USER_MOUSE_JIGGLE_ENABLE
    MS_JIGL,

    // USER_ENABLE_SUPER_ALT_TAB
    SALTTAB,

    // USER_ENABLE_SECRETS
    K_SECR1,
    K_SECR2,
    K_SECR3,
    K_SECR4,

    KEYMAP_SAFE_RANGE
};
