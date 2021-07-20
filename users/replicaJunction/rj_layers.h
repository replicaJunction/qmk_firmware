#pragma once

enum rj_layers {
    L_BASE,

#ifdef USER_INCLUDE_QWERTY
    L_QWERTY,
#endif

#ifdef USER_INCLUDE_LAYER_GAMING
    L_GAMING,

#   ifdef USER_INCLUDE_LAYER_GAMING_2
    L_GAMING2,
#   endif

#endif

    L_NUMBERS,
    L_SYMBOLS,
    L_NAVIGATION,
    L_FN,

#ifdef USER_INCLUDE_LAYER_MACRO
    L_MACROS,
#endif

    _LAYER_SAFE_RANGE,
};
