#include QMK_KEYBOARD_H
#include "jackson15j.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

extern keymap_config_t keymap_config;
extern uint8_t is_master;

#define LAYOUT_crkbd_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, \
                   K31, K32, K33, K34, K35, K36 \
  )

#define LAYOUT_crkbd_wrapper(...) LAYOUT(__VA_ARGS__)
// See: `/users/jackson15j/jackson15j.h` for the layouts.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_crkbd_wrapper(
    QWERTY_1_12,
    QWERTY_2_12,
    QWERTY_3_12,
    CORNE_THUMBS
  ),

  [_SYMBOL] = LAYOUT_crkbd_wrapper(
    SYMBOL_1_12,
    SYMBOL_2_12,
    SYMBOL_3_12,
    CORNE_THUMBS
  ),

  [_MOVMNT] = LAYOUT_crkbd_wrapper(
    MOVMNT_1_12,
    MOVMNT_2_12,
    MOVMNT_3_12,
    CORNE_THUMBS
  ),

  [_NUMBS] = LAYOUT_crkbd_wrapper(
    NUMBS_1_12,
    NUMBS_2_12,
    NUMBS_3_12,
    CORNE_THUMBS
  ),

  [_ADJUST] = LAYOUT_crkbd_wrapper(
    ADJUST_1_12,
    ADJUST_2_12,
    ADJUST_3_12,
    CORNE_THUMBS
  ),
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }
uint16_t        oled_timer;

char     keylog_str[5]   = {};
uint8_t  keylogs_str_idx = 0;
uint16_t log_timer       = 0;

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = 4; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[5] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
        oled_timer = timer_read();
    }
    return true;
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    oled_write("Lyout", false);
    switch (biton32(default_layer_state)) {
        case _QWERTY:
            oled_write(" QRTY", false);
            break;
        // case _COLEMAK:
        //     oled_write(" COLE", false);
        //     break;
        // case _DVORAK:
        //     oled_write(" DVRK", false);
        //     break;
        // case _WORKMAN:
        //     oled_write(" WKMN", false);
        //     break;
        // case _NORMAN:
        //     oled_write(" NORM", false);
        //     break;
        // case _MALTRON:
        //     oled_write(" MLTN", false);
        //     break;
        // case _EUCALYN:
        //     oled_write(" ECLN", false);
        //     break;
        // case _CARPLAX:
        //     oled_write(" CRPX", false);
        //     break;
    }

    /* Show Lock Status (only work on master side) */
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write("Lock:", false);
    oled_write(" ", false);
    oled_write_ln("NUM", led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write(" ", false);
    oled_write("CAPS", led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write(" ", false);
    oled_write("SCRL", led_usb_state & (1 << USB_LED_SCROLL_LOCK));

    /* Show Alt-Gui Swap options */
    oled_write("BTMGK", false);
    oled_write(" ", false);
    oled_write_ln("Win", !keymap_config.swap_lalt_lgui);
    oled_write(" ", false);
    oled_write_ln("Mac", keymap_config.swap_lalt_lgui);

    oled_write(keylog_str, false);
}

void render_status_secondary(void) {
    /* Show Keyboard Layout  */
    oled_write("Lyout", false);
    switch (biton32(default_layer_state)) {
        case _QWERTY:
            oled_write(" QRTY", false);
            break;
        // case _COLEMAK:
        //     oled_write(" COLE", false);
        //     break;
        // case _DVORAK:
        //     oled_write(" DVRK", false);
        //     break;
        // case _WORKMAN:
        //     oled_write(" WKMN", false);
        //     break;
        // case _NORMAN:
        //     oled_write(" NORM", false);
        //     break;
        // case _MALTRON:
        //     oled_write(" MLTN", false);
        //     break;
        // case _EUCALYN:
        //     oled_write(" ECLN", false);
        //     break;
        // case _CARPLAX:
        //     oled_write(" CRPX", false);
        //     break;
    }

    /* Show Activate layer */
    oled_write("Layer", false);
    switch (biton32(layer_state)) {
        case _SYMBOL:
            oled_write("Symbl", false);
            break;
        case _MOVMNT:
            oled_write("Move ", false);
            break;
        case _NUMBS:
            oled_write("Num  ", false);
            break;
        case _ADJUST:
            oled_write("Adjst", false);
            break;
        default:
            oled_write("Dflt ", false);
            break;
    }

    /* Show Mod  */
    uint8_t modifiers = get_mods() | get_oneshot_mods();

    oled_write("Mods:", false);
    oled_write(" ", false);
    oled_write_ln("SFT", (modifiers & MOD_MASK_SHIFT));
    oled_write(" ", false);
    oled_write_ln("CTL", (modifiers & MOD_MASK_CTRL));
    oled_write(" ", false);
    oled_write_ln("ALT", (modifiers & MOD_MASK_ALT));
    oled_write(" ", false);
    oled_write_ln("GUI", (modifiers & MOD_MASK_GUI));

    /* Show logged Keys */
    oled_write(keylog_str, false);
}

void oled_task_user(void) {
    if (timer_elapsed(oled_timer) > 60000) {
        oled_off();
        return;
    }
    if (is_master) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

void matrix_scan_keymap(void) { update_log(); }
#endif

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
#endif

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case KC_SPC_LSFT:
      // Reduce tapping term of Space/Shift to avoid shifting when I'm typing fast.
      return 150;
    default:
      return TAPPING_TERM;
  }
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
        update_tri_layer(_SYMBOL, _MOVMNT, _ADJUST);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer(_SYMBOL, _MOVMNT, _ADJUST);
      }
      return false;
    case MOVMNT:
      if (record->event.pressed) {
        layer_on(_MOVMNT);
        update_tri_layer(_SYMBOL, _MOVMNT, _ADJUST);
      } else {
        layer_off(_MOVMNT);
        update_tri_layer(_SYMBOL, _MOVMNT, _ADJUST);
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

