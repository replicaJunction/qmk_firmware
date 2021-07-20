#pragma once
#include "quantum.h"
#include "../rj_keycodes.h"
#include "../rj_layers.h"

// Include the gboards combo engine
#include "g/keymap_combo.h"
// #define COMBO_VARIABLE_LEN

#define COMBO_TERM_PER_COMBO

#ifndef COMBO_TERM_LONG
#   define COMBO_TERM_LONG COMBO_TERM
#endif
