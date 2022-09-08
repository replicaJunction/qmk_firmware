#pragma once
#include "quantum.h"

#if defined(LEADER_ENABLE)
#   include "leader.h"
#endif

void matrix_scan_leader(void);
