/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "jackson15j.h"

extern keymap_config_t keymap_config;

#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
// See: `/users/jackson15j/jackson15j.h` for the layouts.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_planck_grid_wrapper(
    QWERTY_1_12,
    QWERTY_2_12,
    QWERTY_3_12_PLANCK,
    PLANCK_THUMBS
  ),

  [_SYMBOL] = LAYOUT_planck_grid_wrapper(
    SYMBOL_1_12,
    SYMBOL_2_12,
    SYMBOL_3_12,
    PLANCK_THUMBS
  ),

  [_MOVMNT] = LAYOUT_planck_grid_wrapper(
    MOVMNT_1_12,
    MOVMNT_2_12,
    MOVMNT_3_12,
    PLANCK_THUMBS
  ),

  [_NUMBS] = LAYOUT_planck_grid_wrapper(
    NUMBS_1_12,
    NUMBS_2_12,
    NUMBS_3_12,
    PLANCK_THUMBS
  ),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _SYMBOL, _MOVMNT, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
      } else {
        layer_off(_SYMBOL);
      }
      return false;
    case MOVMNT:
      if (record->event.pressed) {
        layer_on(_MOVMNT);
      } else {
        layer_off(_MOVMNT);
      }
      return false;
    case NUMBS:
      if (record->event.pressed) {
        layer_on(_NUMBS);
      } else {
        layer_off(_NUMBS);
      }
      return false;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(_MOVMNT)) {
    if (clockwise) {
      register_code (KC_PGUP);
      unregister_code (KC_PGUP);
    } else {
      register_code (KC_PGDN);
      unregister_code (KC_PGDN);
    }
  }
  if (IS_LAYER_ON(_SYMBOL)) {
    if (clockwise) {
      register_code (KC_MS_WH_UP);
      unregister_code (KC_MS_WH_UP);
    } else {
      register_code (KC_MS_WH_DOWN);
      unregister_code (KC_MS_WH_DOWN);
    }
  } else {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}

// FIXME: Can't get my slimmed down or above code working on the Encoder ??
// void encoder_update(bool clockwise) {
//     if (IS_LAYER_ON(_MOVMNT)) {
//         clockwise ? tap_code(KC_MS_WH_DOWN) : tap_code(KC_MS_WH_UP);
//     } else if (IS_LAYER_ON(_QWERTY)) {
//         clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
//     } else {
//         clockwise ? tap_code(KC_A) : tap_code(KC_B);
//     }
// }

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case SYMBOL:
    case MOVMNT:
      return false;
    default:
      return true;
  }
}
