#include "rj_key_overrides.h"

const key_override_t minus_plus_override = ko_make_basic(MOD_MASK_SHIFT,KC_MINS, KC_PLUS);
const key_override_t dot_colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,KC_COLN);
const key_override_t ques_exlm_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t comma_scln_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t eql_unds_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_UNDS);
const key_override_t dquo_hash_override = ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, KC_HASH);
const key_override_t quote_at_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_AT);
const key_override_t slash_pipe_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_PIPE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &minus_plus_override,
    &dot_colon_override,
    &ques_exlm_override,
    &comma_scln_override,
    &eql_unds_override,
    &dquo_hash_override,
    &quote_at_override,
    &slash_pipe_override,
	NULL // Null terminate the array of overrides!
};
