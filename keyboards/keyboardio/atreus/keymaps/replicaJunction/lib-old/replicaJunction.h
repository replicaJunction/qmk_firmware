#pragma once

#include "quantum.h"

#include "rj_layers.h"
#include "rj_keycodes.h"


#ifdef USER_CAPS_WORD_ENABLE
#    include "caps_word.h"
#endif

#ifdef USER_NUM_WORD_ENABLE
#    include "num_word.h"
#endif

#include "adaptive_keys.h"
#include "rj_key_overrides.h"
#include "process_records.h"

#ifdef COMBO_ENABLE
#   include "g/keymap_combo.h"
#   include "rj_combos.h"
#endif
