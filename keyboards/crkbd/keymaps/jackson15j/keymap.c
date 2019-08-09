#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

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

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default.
// Call adjust layer when RAISE and LOWER are both pressed.
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void render_crkbd_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void iota_gfx_task_user(void) {
    if (is_master) {
        struct CharacterMatrix matrix;
        matrix_clear(&matrix);
        matrix_render_user(&matrix);
        matrix_update(&display, &matrix);
    } else {
        render_crkbd_logo();
        // oled_scroll_left();  // Turns on scrolling
    }
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
        update_tri_layer_RGB(_SYMBOL, _MOVMNT, _ADJUST);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer_RGB(_SYMBOL, _MOVMNT, _ADJUST);
      }
      return false;
    case MOVMNT:
      if (record->event.pressed) {
        layer_on(_MOVMNT);
        update_tri_layer_RGB(_SYMBOL, _MOVMNT, _ADJUST);
      } else {
        layer_off(_MOVMNT);
        update_tri_layer_RGB(_SYMBOL, _MOVMNT, _ADJUST);
      }
      return false;
    case NUMBS:
      if (record->event.pressed) {
        layer_on(_NUMBS);
      } else {
        layer_off(_NUMBS);
      }
      return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

