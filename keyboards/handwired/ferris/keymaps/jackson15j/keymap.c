/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "jackson15j.h"

// // Blank template at the bottom
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// /* Keymap 0: Qwerty
//  *
//  * ,-----------------------------.      ,-----------------------------.
//  * |  Q  |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |  P  |
//  * |-----+-----+-----+-----+-----|      |-----------------------------|
//  * |  A  |  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  |  ;  |
//  * |-----+-----+-----+-----+-----+      |-----------------------------|
//  * |  Z  |  X  |  C  |  V  |  B  |      |  N  |  M  |  <  |  >  |  ?  |
//  * `-----+-----+-----+-----+-----+--. ,-+-----------------------------'
//  *                     | BSPC | SPC | | SPC | ENT |
//  *                     '------------' '-----------'
//  */
// [0] = LAYOUT(
//     KC_Q, KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I,    KC_O,   KC_P,
//     KC_A, KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
//     KC_Z, KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
//                    KC_BSPC, KC_SPC,   KC_SPC, KC_ENT)
// };




extern keymap_config_t keymap_config;

#define LAYOUT_ferris_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A \
  ) \
  LAYOUT_wrapper( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
                   FERRIS_THUMBS \
  )

#define LAYOUT_ferris_base_wrapper(...) LAYOUT_ferris_base(__VA_ARGS__)
// See: `/users/jackson15j/jackson15j.h` for the layouts.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ferris_base_wrapper(
    QWERTY_L1, QWERTY_R1,
    QWERTY_L2, QWERTY_R2,
    QWERTY_L3, QWERTY_R3
  ),

  [_COLEMAK_DHM] = LAYOUT_ferris_base_wrapper(
    COLEMAK_DHM_L1, COLEMAK_DHM_R1,
    COLEMAK_DHM_L2, COLEMAK_DHM_R2,
    COLEMAK_DHM_L3, COLEMAK_DHM_R3
  ),

  [_GAME] = LAYOUT_wrapper(
    GAME_L1, GAME_R1,
    GAME_L2, GAME_R2,
    GAME_L3, GAME_R3,
    FERRIS_GAME_THUMBS
  ),

  [_SYMBOL] = LAYOUT_ferris_base_wrapper(
    SYMBOL_L1, SYMBOL_R1,
    SYMBOL_L2, SYMBOL_R2,
    SYMBOL_L3, SYMBOL_R3
  ),

  [_MOVMNT] = LAYOUT_ferris_base_wrapper(
    MOVMNT_L1, MOVMNT_R1,
    MOVMNT_L2, MOVMNT_R2,
    MOVMNT_L3, MOVMNT_R3
  ),

  [_NUMBS] = LAYOUT_ferris_base_wrapper(
    NUMBS_L1, NUMBS_R1,
    NUMBS_L2, NUMBS_R2,
    NUMBS_L3, NUMBS_R3
),

  [_ADJUST] = LAYOUT_ferris_base_wrapper(
    ADJUST_L1, ADJUST_R1,
    ADJUST_L2, ADJUST_R2,
    ADJUST_L3, ADJUST_R3
 ),
};
