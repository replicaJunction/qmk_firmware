/*
 * Not my work. Based almost entirely on this:
 * https://github.com/openorclose/qmk_firmware/blob/master/keyboards/crkbd/keymaps/openorclose/features/adaptive_keys.h
 */

#pragma once
#ifndef ADAPTIVE_TERM
#    define ADAPTIVE_TERM 100
#endif

bool process_record_adaptive_keys(uint16_t keycode, const keyrecord_t *record);
void matrix_scan_adaptive_keys(void);
