#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;
extern uint8_t is_master;

enum layer_names {
  _QWERTY,
  _SYMBOL,
  _MOVMNT,
  _NUMBS,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOL,
  NUMBS,
  MOVMNT,
  ADJUST,
  RGBRST,
  MBTN1,
  SCRL
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_SYMBOL SYMBOL
#define KC_NUMBS NUMBS
#define KC_MOVMNT MOVMNT
#define KC_SPC_SYM LT(_SYMBOL, KC_SPC)  // Tap=space, hold=SYMBOL layer.
#define KC_SPC_LSFT MT(MOD_LSFT, KC_SPC)  // Tap=space, hold=Left Shift.
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLA CTL_T(KC_A)
#define KC_CTLSC CTL_T(KC_SCLN)
#define KC_SFTZ LSFT(KC_Z)
#define KC_SFTSL LSFT(KC_SLSH)
#define KC_UNDSCR LSFT(KC_MINS)  // `_`
#define KC_PLUS LSFT(KC_EQL)  // `+`
#define KC_JPIPE LSFT(KC_NUBS)  // `|`
#define KC_JHASH KC_NUHS  // `#`
#define KC_TILDA LSFT(KC_NUHS)  // `~`
#define KC_ATT LSFT(KC_QUOT)  // `@`
#define KC_QUEST LSFT(KC_SLSH)  // `?`
#define KC_LCURLY LSFT(KC_LBRC)  // `{`
#define KC_RCURLY LSFT(KC_RBRC)  // `}`
#define KC_EXCLM LSFT(KC_1)  // `!`
#define KC_DBLQT LSFT(KC_2)  // `"`
#define KC_GBP LSFT(KC_3)  // `£`
#define KC_DOLR LSFT(KC_4)  // `$`
#define KC_PRCNT LSFT(KC_5)  // `%`
#define KC_HAT LSFT(KC_6)  // `^`
#define KC_AMP LSFT(KC_7)  // `&`
#define KC_STAR LSFT(KC_8)  // `*`
#define KC_LPAREN LSFT(KC_9)  // `(`
#define KC_RPAREN LSFT(KC_0)  // `)`
#define KC_WINX LWIN_T(KC_X)
#define KC_WINF2 LWIN_T(KC_F2)
#define KC_WINDO RWIN_T(KC_DOT)

#define KC_MBTN1  MBTN1
#define KC_SCRL   SCRL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        TAB,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,  WINX,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  ),

  [_SYMBOL] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC, EXCLM, DBLQT,   GBP,  DOLR, PRCNT,                    HAT,   AMP,  STAR,LPAREN,RPAREN,   DEL,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        TAB,LCURLY,  LBRC,LPAREN, MINUS, GRAVE,                  JHASH,UNDSCR,RPAREN,  RBRC,RCURLY,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,   ATT,  PLUS,  NUBS, JPIPE,  QUOT,                  TILDA,  SLSH,   EQL, QUEST,  SLSH,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  ),

  [_MOVMNT] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC, XXXXX,  WH_U,  MS_U,  WH_D, XXXXX,                  XXXXX,  PGUP,    UP,  PGDN,   DEL,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        TAB,  BTN1,  MS_L,  MS_D,  MS_R,  BTN2,                   HOME,  LEFT,  DOWN,  RGHT,   END,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,  LGUI,  LGUI, XXXXX, XXXXX,   RST,                   MUTE, VOLD,   VOLU,   INS,  PSCR,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  ),

  [_NUMBS] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC, EXCLM, DBLQT,   GBP,  DOLR, PRCNT,                    HAT,   AMP,  STAR,LPAREN,RPAREN,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        TAB,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,    F1, WINF2,    F3,    F4,    F5,                     F6,    F7,    F8,   DOT,   F12,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
        RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD, XXXXX,   RST,                    RST, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  )
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

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
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

