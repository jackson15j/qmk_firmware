
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_SYMBOL 2
#define L_MOVMNT 4
#define L_NUMBS 8
#define L_ADJUST_TRI 22

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_MOVMNT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Movement");
    break;
  case L_SYMBOL:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Symbols");
    break;
  case L_NUMBS:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Numbers");
    break;
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
