#pragma once

/* Select hand configuration */
// Use either USB port, but need to flash each side with a unique hex.
// eg. `make:jackson15j:<avrdude/dfu>-split-<left/right>`.
// avrdude for pro-micro, dfu for elite-c.
# define EE_HANDS

#define USB_MAX_POWER_CONSUMPTION 100

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// #define DEBUG_MATRIX_SCAN_RATE
