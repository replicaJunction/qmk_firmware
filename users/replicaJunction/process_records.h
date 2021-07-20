/* Copyright 2021 Joshua T.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"
#include "rj_keycodes.h"
#include "rj_layers.h"
#include "version.h"

#ifdef USER_ADAPTIVE_KEYS_ENABLE
#    include "features/adaptive_keys.h"
#endif

#ifdef USER_CAPS_WORD_ENABLE
#    include "features/caps_word.h"
#endif

#ifdef USER_NUM_WORD_ENABLE
#    include "features/num_word.h"
#endif
