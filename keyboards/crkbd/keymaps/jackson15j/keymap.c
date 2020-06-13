#include QMK_KEYBOARD_H
#include "jackson15j.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

extern keymap_config_t keymap_config;
extern uint8_t is_master;

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

  [_SYMBOL] = LAYOUT_wrapper(
    SYMBOL_1_12,
    SYMBOL_2_12,
    SYMBOL_3_12,
    CORNE_THUMBS_TRNS
  ),

  [_SYMBOL2] = LAYOUT_wrapper(
    SYMBOL_1_12,
    SYMBOL_2_12,
    SYMBOL_3_12,
    CORNE_THUMBS_TRNS
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


#ifdef OLED_DRIVER_ENABLE

#    define KEYLOGGER_LENGTH 5
static uint32_t oled_timer                       = 0;
static char     keylog_str[KEYLOGGER_LENGTH + 1] = {"\n"};
static uint16_t log_timer                        = 0;
// clang-format off
static const char PROGMEM code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 128, ' ', ' ', ' ', ' ', ' ', ' ',  // 3x
    ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'S', ' ', ' ', ' ', ' ',  16, ' ', ' ', ' ',  // 4x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 5x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '        // Fx
};

void add_keylog(uint16_t keycode);

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }

    for (uint8_t i = (KEYLOGGER_LENGTH - 1); i > 0; --i) {
        keylog_str[i] = keylog_str[i - 1];
    }

    if (keycode < (sizeof(code_to_name) / sizeof(char))) {
        keylog_str[0] = pgm_read_byte(&code_to_name[keycode]);
    }

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        // add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Lyout"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(" QRTY"), false);
            break;
        case _COLEMAK_DHM:
            oled_write_P(PSTR(" CLMK"), false);
            break;    }
}

void render_layer_state(void) {
    oled_write_P(PSTR("LAYER"), false);
    oled_write_P(PSTR("Symbl"), layer_state_is(_SYMBOL));
    oled_write_P(PSTR("NmSym"), layer_state_is(_SYMBOL2));
    oled_write_P(PSTR("Move "), layer_state_is(_MOVMNT));
    oled_write_P(PSTR("Nums "), layer_state_is(_NUMBS));
    oled_write_P(PSTR("Adj  "), layer_state_is(_ADJUST));
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("Lock:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("C"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_ln_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("Mods:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_bootmagic_status(void) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    oled_write_P(PSTR("BTMGK"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(logo[0][0], !keymap_config.swap_lctl_lgui);
    oled_write_P(logo[1][0], keymap_config.swap_lctl_lgui);
    oled_write_P(PSTR(" "), false);
    oled_write_P(logo[0][1], !keymap_config.swap_lctl_lgui);
    oled_write_P(logo[1][1], keymap_config.swap_lctl_lgui);
    oled_write_P(PSTR(" NKRO"), keymap_config.nkro);
}

// void render_user_status(void) {
//     oled_write_P(PSTR("USER:"), false);
//     oled_write_P(PSTR(" Anim"), userspace_config.rgb_matrix_idle_anim);
//     oled_write_P(PSTR(" Layr"), userspace_config.rgb_layer_change);
//     oled_write_P(PSTR(" Nuke"), userspace_config.nuke_switch);
// }

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_default_layer_state();
    render_keylock_status(host_keyboard_leds());
    render_bootmagic_status();
    // render_user_status();

    render_keylogger_status();
}

void render_status_secondary(void) {
    /* Show Keyboard Layout  */
    render_default_layer_state();
    render_layer_state();
    render_mod_status(get_mods() | get_oneshot_mods());

    render_keylogger_status();
}

void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 30000) {
        oled_off();
        return;
    }
#    ifndef SPLIT_KEYBOARD
    else {
        oled_on();
    }
#    endif

    update_log();
    if (is_master) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}
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

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _SYMBOL, _MOVMNT, _ADJUST);
  // Go back to symbols layer whilst still holding numbers layer, to avoid
  // constantly alternately tapping my thumbs.
  state = update_tri_layer_state(state, _SYMBOL, _NUMBS, _SYMBOL2);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
        add_keylog(keycode);
#endif
#ifndef SPLIT_KEYBOARD
        if (keycode == RESET && !is_master) {
            return false;
        }
#endif
    }

  switch (keycode) {
    case _QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case _COLEMAK_DHM:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_DHM);
      }
      return false;
    case _SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
      } else {
        layer_off(_SYMBOL);
      }
      return false;
    case _MOVMNT:
      if (record->event.pressed) {
        layer_on(_MOVMNT);
      } else {
        layer_off(_MOVMNT);
      }
      return false;
    case _NUMBS:
      if (record->event.pressed) {
        layer_on(_NUMBS);
      } else {
        layer_off(_NUMBS);
      }
      return false;
  }
  return true;
}

