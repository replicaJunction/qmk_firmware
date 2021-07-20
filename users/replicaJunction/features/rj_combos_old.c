#include "rj_combos.h"

// The full combo definitions are defined in combos.def using the
// GBoards combo engine.
//
// See here for more information:
// http://combos.gboards.ca/

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    if (combo->keys[0] == KC_K && combo->keys[1] == KC_M) {
        return COMBO_TERM_LONG;
    }

    if (combo->keys[0] == KC_M && combo->keys[1] == KC_F) {
        return COMBO_TERM_LONG;
    }

    return COMBO_TERM;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}
