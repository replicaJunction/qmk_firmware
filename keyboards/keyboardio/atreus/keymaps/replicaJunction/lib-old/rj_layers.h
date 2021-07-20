#pragma once

enum layer_names {
    L_BASE,
    L_NAVIGATION,
    L_NUMBERS,
    L_SYMBOLS,

#ifdef USER_INCLUDE_LAYER_GAMING
    L_GAMING,

#   ifdef USER_INCLUDE_LAYER_GAMING_2
    L_GAMING2,
#   endif
#endif
};
