#include "quantum.h"

const key_override_t comm_shift_override  = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EXLM);
const key_override_t dot_shift_override   = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_QUES);
const key_override_t slsh_shift_override  = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS);
const key_override_t unds_shift_override  = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_MINS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &comm_shift_override,
    &dot_shift_override,
    &slsh_shift_override,
    &unds_shift_override,
	NULL // Null terminate the array of overrides!
};
