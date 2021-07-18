#include "rj_combos.h"

enum combos {
    // Top row, left hand
    JK_Z,
    KM_LK,
    FV_Q,
    MF_LF,

    // Top row, right hand
    UO_DEL,
    OY_BSPC,
    UOY_CTL_BSPC,

    // Home row, left hand
    NH_ESC,
    SN_SYMBOL,
    SNH_TAB,

    // Home row, right hand
    AE_SLSH,
    EI_SYMBOL,
    AEI_ENTER,

    // Bottom row, left hand
    UNDO_COMBO,
    CUT_COMBO,
    COPY_COMBO,
    PASTE_COMBO,
    SELECT_ALL_COMBO,

    // Both hands
    DCOMM_NUMWORD,
    LEQL_CAPSWORD,

    // Misc
    DLR_UNDS_PSITEM,

    COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM km_combo[] = {KC_K, KC_M, COMBO_END};
const uint16_t PROGMEM fv_combo[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM mf_combo[] = {KC_M, KC_F, COMBO_END};

const uint16_t PROGMEM uo_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM oy_combo[] = {KC_O, KC_Y, COMBO_END};
const uint16_t PROGMEM uoy_combo[] = {KC_U, KC_O, KC_Y, COMBO_END};

// const uint16_t PROGMEM nh_combo[] = {KC_N, KC_H, COMBO_END};
// const uint16_t PROGMEM sn_combo[] = {KC_S, KC_N, COMBO_END};
// const uint16_t PROGMEM snh_combo[] = {KC_S, KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM nh_combo[] = {SFT_N, CTL_H, COMBO_END};
const uint16_t PROGMEM sn_combo[] = {ALT_S, SFT_N, COMBO_END};
const uint16_t PROGMEM snh_combo[] = {ALT_S, SFT_N, CTL_H, COMBO_END};

// const uint16_t PROGMEM ae_combo[] = {KC_A, KC_E, COMBO_END};
// const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
// const uint16_t PROGMEM aei_combo[] = {KC_A, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {CTL_A, SFT_E, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {SFT_E, ALT_I, COMBO_END};
const uint16_t PROGMEM aei_combo[] = {CTL_A, SFT_E, ALT_I, COMBO_END};

const uint16_t PROGMEM dcomm_combo[] = {KC_D, KC_COMM, COMBO_END};
const uint16_t PROGMEM leql_combo[] = {KC_L, KC_EQL, COMBO_END};

const uint16_t PROGMEM undo_combo[] = {KC_X, KC_G, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_X, KC_L, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_G, KC_L, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM select_all_combo[] = {KC_X, KC_D, COMBO_END};

const uint16_t PROGMEM dlr_unds_combo[] = {KC_DLR, KC_UNDS, COMBO_END};

combo_t key_combos[] = {
  [JK_Z] = COMBO(jk_combo, KC_Z),
  [KM_LK] = COMBO_ACTION(km_combo),
  [FV_Q] = COMBO(fv_combo, KC_Q),
  [MF_LF] = COMBO_ACTION(mf_combo),

  [UO_DEL] = COMBO(uo_combo, KC_DEL),
  [OY_BSPC] = COMBO(oy_combo, KC_BSPC),
  [UOY_CTL_BSPC] = COMBO(uoy_combo, LCTL(KC_BSPC)),

  [NH_ESC] = COMBO(nh_combo, KC_ESC),
  [SN_SYMBOL] = COMBO(sn_combo, OSL(L_SYMBOLS)),
  [SNH_TAB] = COMBO(snh_combo, KC_TAB),

  [AE_SLSH] = COMBO(ae_combo, KC_SLSH),
  [EI_SYMBOL] = COMBO(ei_combo, OSL(L_SYMBOLS)),
  [AEI_ENTER] = COMBO(aei_combo, KC_ENT),

  [UNDO_COMBO] = COMBO(undo_combo, LCTL(KC_Z)),
  [CUT_COMBO] = COMBO(cut_combo, LCTL(KC_X)),
  [COPY_COMBO] = COMBO(copy_combo, LCTL(KC_C)),
  [PASTE_COMBO] = COMBO(paste_combo, LCTL(KC_V)),
  [SELECT_ALL_COMBO] = COMBO(select_all_combo, LCTL(KC_A)),

  [DCOMM_NUMWORD] = COMBO(dcomm_combo, NUMWORD),
  [LEQL_CAPSWORD] = COMBO(leql_combo, CAPWORD),

  [DLR_UNDS_PSITEM] = COMBO_ACTION(dlr_unds_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case KM_LK:
            if (pressed) {
                SEND_STRING("lk");
            }
            break;
        case MF_LF:
            if (pressed) {
                SEND_STRING("lf");
            }
            break;
        case DLR_UNDS_PSITEM:
            if (pressed) {
                SEND_STRING("$_");
            }
            break;
    }
}

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case KM_LK:
        case MF_LF:
            return COMBO_TERM_LONG;
        default:
            return COMBO_TERM;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}
