/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#include "jackson15j.h"

#define LAYOUT_kyria_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_ESC,  K01, K02, K03, K04, K05,                                               K06, K07, K08, K09, K0A, KC_BSPC, \
    KC_TAB,  K11, K12, K13, K14, K15,                                               K16, K17, K18, K19, K1A, KC_ENT, \
    KC_LSFT, K21, K22, K23, K24, K25, TG(_SYMBOL), TG(_GAME),  TG(_NUMBS), KC_CAPS, K26, K27, K28, K29, K2A, KC_RSFT, \
                                                        KYRIA_THUMBS \
)
/* Re-pass though to allow templates to be used */
#define LAYOUT_kyria_base_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)

// See: `/users/jackson15j/jackson15j.h` for the layouts.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kyria_base_wrapper(
    QWERTY_L1, QWERTY_R1,
    QWERTY_L2, QWERTY_R2,
    QWERTY_L3, QWERTY_R3
  ),

  [_COLEMAK_DHM] = LAYOUT_kyria_base_wrapper(
    COLEMAK_DHM_L1, COLEMAK_DHM_R1,
    COLEMAK_DHM_L2, COLEMAK_DHM_R2,
    COLEMAK_DHM_L3, COLEMAK_DHM_R3
  ),

  [_GAME] = LAYOUT_kyria_base_wrapper(
    GAME_L1, KC_TRNS_1X5,
    GAME_L2, KC_TRNS_1X5,
    GAME_L3, KC_TRNS_1X5
  ),

  [_SYMBOL] = LAYOUT_kyria_base_wrapper(
    SYMBOL_L1, SYMBOL_R1,
    SYMBOL_L2, SYMBOL_R2,
    SYMBOL_L3, SYMBOL_R3
  ),

  [_MOVMNT] = LAYOUT_kyria_base_wrapper(
    MOVMNT_L1, MOVMNT_R1,
    MOVMNT_L2, MOVMNT_R2,
    MOVMNT_L3, MOVMNT_R3
  ),

  [_NUMBS] = LAYOUT_kyria_base_wrapper(
    NUMBS_L1, NUMBS_R1,
    NUMBS_L2, NUMBS_R2,
    NUMBS_L3, NUMBS_R3
),

  [_ADJUST] = LAYOUT_kyria_base_wrapper(
    ADJUST_L1, ADJUST_R1,
    ADJUST_L2, ADJUST_R2,
    ADJUST_L3, ADJUST_R3
 ),
};



// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// /*
//  * Base Layer: QWERTY
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |RAIS/ESC|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * | LShift |   Z  |   X  |   C  |   V  |   B  |LShift|LShift|  |LShift|LShift|   N  |   M  | ,  < | . >  | /  ? |  - _   |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter| Space| Tab  | Bksp | AltGr|
//  *                        |      |      | Alt  | Lower| Raise|  | Lower| Raise|      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_QWERTY] = LAYOUT(
//       LT(_SYMBOL, KC_ESC),       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
//       MT(MOD_LCTL, KC_BSPC),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//       KC_LSFT,                 KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LSFT,   KC_LSFT, KC_LSFT, KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
//               KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_SYMBOL, KC_SPC), LT(_NUMBS, KC_ESC), LT(_MOVMNT, KC_ENT), LT(_NUMBS, KC_SPC), KC_TAB,  KC_BSPC, KC_RALT
//     ),
// /*
//  * Lower Layer: Symbols
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |  !   |  @   |  {   |  }   |  |   |                              |      |      |      |      |      |  | \   |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |  ;   |  =   |  |  =   |  ;   |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_SYMBOL] = LAYOUT(
//       _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, _______, _______, _______, _______, KC_BSLS,
//       _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
//       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
//                                  _______, _______, _______, KC_SCLN, KC_EQL,  KC_EQL,  KC_SCLN, _______, _______, _______
//     ),
// /*
//  * Raise Layer: Number keys, media, navigation
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      | Prev | Play | Next | VolUp|                              | Left | Down | Up   | Right|      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      | Mute | VolDn|      |      |  |      |      | MLeft| Mdown| MUp  |MRight|      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_NUMBS] = LAYOUT(
//       _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
//       _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
//       _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
// /*
//  * Adjust Layer: Function keys, RGB
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_ADJUST] = LAYOUT(
//       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
//       _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
//       _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
// // /*
// //  * Layer template
// //  *
// //  * ,-------------------------------------------.                              ,-------------------------------------------.
// //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// //  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
// //  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
// //  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
// //  *                        |      |      |      |      |      |  |      |      |      |      |      |
// //  *                        |      |      |      |      |      |  |      |      |      |      |      |
// //  *                        `----------------------------------'  `----------------------------------'
// //  */
// //     [_LAYERINDEX] = LAYOUT(
// //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
// //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
// //       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
// //                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// //     ),
// };

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
