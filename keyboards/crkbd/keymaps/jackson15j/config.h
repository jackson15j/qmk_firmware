// See: `/users/jackson15j/config.h` for global options.
#pragma once
#include "quantum.h"

/* Select hand configuration */
// Use either USB port, but need to flash each side with a unique hex.
// eg. `make:jackson15j:<avrdude/dfu>-split-<left/right>`.
// avrdude for pro-micro, dfu for elite-c.
#define EE_HANDS
#define USE_SERIAL_PD2
// #define DEBUG_MATRIX_SCAN_RATE
