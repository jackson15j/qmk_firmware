#include QMK_KEYBOARD_H
#include "jackson15j.h"

extern keymap_config_t keymap_config;

#define LAYOUT_crkbd_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A \
  ) \
  LAYOUT_wrapper( \
    KC_ESC, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, KC_BSPC, \
    KC_TAB, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, KC_ENT, \
    KC_LSFT, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, KC_RSFT, \
                   CORNE_THUMBS \
  )

#define LAYOUT_crkbd_base_wrapper(...) LAYOUT_crkbd_base(__VA_ARGS__)
// See: `/users/jackson15j/jackson15j.h` for the layouts.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_crkbd_base_wrapper(
    QWERTY_L1, QWERTY_R1,
    QWERTY_L2, QWERTY_R2,
    QWERTY_L3, QWERTY_R3
  ),

  [_COLEMAK_DHM] = LAYOUT_crkbd_base_wrapper(
    COLEMAK_DHM_L1, COLEMAK_DHM_R1,
    COLEMAK_DHM_L2, COLEMAK_DHM_R2,
    COLEMAK_DHM_L3, COLEMAK_DHM_R3
  ),

  [_GAME] = LAYOUT_wrapper(
    _______, GAME_L1, KC_TRNS_1X6,
    _______, GAME_L2, KC_TRNS_1X6,
    _______, GAME_L3, KC_TRNS_1X6,
    CORNE_GAME_THUMBS
  ),

  [_SYMBOL] = LAYOUT_crkbd_base_wrapper(
    SYMBOL_L1, SYMBOL_R1,
    SYMBOL_L2, SYMBOL_R2,
    SYMBOL_L3, SYMBOL_R3
  ),

  [_MOVMNT] = LAYOUT_crkbd_base_wrapper(
    MOVMNT_L1, MOVMNT_R1,
    MOVMNT_L2, MOVMNT_R2,
    MOVMNT_L3, MOVMNT_R3
  ),

  [_NUMBS] = LAYOUT_crkbd_base_wrapper(
    NUMBS_L1, NUMBS_R1,
    NUMBS_L2, NUMBS_R2,
    NUMBS_L3, NUMBS_R3
  ),

  [_ADJUST] = LAYOUT_crkbd_base_wrapper(
    ADJUST_L1, ADJUST_R1,
    ADJUST_L2, ADJUST_R2,
    ADJUST_L3, ADJUST_R3
  ),
};
