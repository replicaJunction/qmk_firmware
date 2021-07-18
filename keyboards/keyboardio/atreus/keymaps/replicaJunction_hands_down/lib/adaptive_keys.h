#pragma once
#include "quantum.h"

#ifndef ADAPTIVE_TERM
#   define ADAPTIVE_TERM 200
#endif

bool process_record_adaptive_keys(uint16_t keycode, const keyrecord_t *record);
