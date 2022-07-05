#pragma once

#if defined(USER_LAYOUT_QWERTY)
#    include "qwerty/layout.h"
#else
#    include "colemak_dh/layout.h"
#endif

#ifdef USER_ENABLE_HOME_ROW_MODS
#    define KL_LH1 LGUI_T(KL_L21)
#    define KL_LH2 LALT_T(KL_L22)
#    define KL_LH3 LSFT_T(KL_L23)
#    define KL_LH4 LCTL_T(KL_L24)

#    define KL_RH2 LCTL_T(KL_R22)
#    define KL_RH3 LSFT_T(KL_R23)
#    define KL_RH4 LALT_T(KL_R24)
#    define KL_RH5 LGUI_T(KL_R25)
#else
#    define KL_LH1 KL_L21
#    define KL_LH2 KL_L22
#    define KL_LH3 KL_L23
#    define KL_LH4 KL_L24

#    define KL_RH2 KL_R22
#    define KL_RH3 KL_R23
#    define KL_RH4 KL_R24
#    define KL_RH5 KL_R25
#endif

#include "symbols.h"
#include "nav.h"
