#pragma once

#include "quantum.h"

#ifndef ADAPTIVE_KEY_TERM
#    define ADAPTIVE_KEY_TERM 200
#endif

typedef struct {
    const uint16_t prefix_key;
    const uint16_t trigger_key;
    const uint16_t replace_key;
} adaptive_key_t;

/** Define this as a null-terminated array of pointers to key overrides. These key overrides will be used by qmk. */
extern const adaptive_key_t **adaptive_keys;

#define ADAPTIVE_KEY(prefix_key_, trigger_key_, replace_key_) ((const adaptive_key_t){.prefix_key = prefix_key_, .trigger_key = trigger_key_, .replace_key = replace_key_})

bool process_adaptive_key(uint16_t keycode, keyrecord_t *record);

void enable_adaptive_keys(void);
void disable_adaptive_keys(void);
void toggle_adaptive_keys(void);
