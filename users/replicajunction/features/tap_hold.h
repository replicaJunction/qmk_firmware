#pragma once
#include "quantum.h"

// Process tap hold, place in process_record_user().
// If this returns false, we should also return false from process_record_user().
bool process_record_tap_hold(uint16_t keycode, const keyrecord_t *record);

// Matrix scan, place in matrix_scan_user()
void matrix_scan_tap_hold(void);

// End tap hold
void end_tap_hold(void);

void enable_tap_hold(void);
void disable_tap_hold(void);

////////////////////////////////
// User overrideable functions
////////////////////////////////

// User can override this to do whatever tap action they want.
void tap_hold_send_tap(uint16_t keycode);

// User must define this to do whatever hold action they want.
void tap_hold_send_hold(uint16_t keycode);

// Per key tap hold timeout
uint16_t tap_hold_timeout(uint16_t keycode);

// User override for what keys to trigger a tap hold action.
bool is_tap_hold_keycode(uint16_t keycode);
