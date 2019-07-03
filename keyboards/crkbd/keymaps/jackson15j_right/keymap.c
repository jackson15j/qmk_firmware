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
  _NUMBER
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOL,
  NUMBER,
  MOVMNT,
  RGBRST,
  MBTN1,
  SCRL
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_SYMBOL SYMBOL
#define KC_NUMBER NUMBER
#define KC_MOVMNT MOVMNT
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
#define KC_SFTZ SFT_T(KC_Z)
#define KC_SFTSL SFT_T(KC_SLSH)
#define KC_UNDSCR SFT_T(KC_MINS)  // `_`
#define KC_PLUS LSFT(KC_EQL)  // `+`
#define KC_JPIPE SFT_T(KC_BSLS)  // `|`
#define KC_JHASH KC_NUHS  // `#`
#define KC_TILDA SFT_T(KC_HASH)  // `~`
#define KC_ATT SFT_T(KC_QUOT)  // `@`
#define KC_QUEST SFT_T(KC_SLSH)  // `?`
#define KC_LCURLY SFT_T(KC_LBRC)  // `{`
#define KC_RCURLY SFT_T(KC_RBRC)  // `}`
#define KC_EXCLM SFT_T(KC_1)  // `!`
#define KC_DBLQT SFT_T(KC_2)  // `"`
#define KC_GBP SFT_T(KC_3)  // `£`
#define KC_DOLR SFT_T(KC_4)  // `$`
#define KC_PRCNT SFT_T(KC_5)  // `%`
#define KC_HAT SFT_T(KC_6)  // `^`
#define KC_AMP SFT_T(KC_7)  // `&`
#define KC_STAR SFT_T(KC_8)  // `*`
#define KC_LPAREN SFT_T(KC_9)  // `(`
#define KC_RPAREN SFT_T(KC_0)  // `)`
#define KC_WINX LWIN_T(KC_X)
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
                                  LCTRL,  LALT,SYMBOL,      SPC, MOVMNT,NUMBER
                              //`--------------------'  `--------------------'
  ),

  [_SYMBOL] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC, EXCLM, DBLQT,   GBP,  DOLR, PRCNT,                    HAT,   AMP,  STAR,LPAREN,RPAREN,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        TAB,LCURLY,  LBRC,LPAREN, MINUS, GRAVE,                  JHASH,UNDSCR,RPAREN,  RBRC,RCURLY,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,   ATT,  PLUS,  BSLS, JPIPE,  QUOT,                  TILDA,  SLSH,   EQL, QUEST,  SLSH,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LCTRL,  LALT,SYMBOL,      SPC, MOVMNT,NUMBER
                              //`--------------------'  `--------------------'
  ),

  [_NUMBER] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        TAB,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,    F1,    F2,    F3,    F4,    F5,                     F6,    F7,    F8,   DOT,   F12,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LCTRL,  LALT,SYMBOL,      SPC, MOVMNT,NUMBER
                              //`--------------------'  `--------------------'
  ),

  [_MOVMNT] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
        ESC,  VOLD,  VOLU,  MUTE, XXXXX, XXXXX,                  XXXXX,  PGUP,    UP,  PGDN,   DEL,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        TAB,  MPRV,  MPLY,  MNXT, XXXXX, XXXXX,                   HOME,  LEFT,  DOWN,  RGHT,   END,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,  LGUI, XXXXX, XXXXX, XXXXX,   RST,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LCTRL,  LALT,SYMBOL,      SPC, MOVMNT,NUMBER
                              //`--------------------'  `--------------------'
  ),
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting NUMBER layer RGB back to default
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
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
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
        update_tri_layer_RGB(_SYMBOL, _MOVMNT, _NUMBER);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer_RGB(_SYMBOL, _MOVMNT, _NUMBER);
      }
      return false;
    case MOVMNT:
      if (record->event.pressed) {
        layer_on(_MOVMNT);
        update_tri_layer_RGB(_SYMBOL, _MOVMNT, _NUMBER);
      } else {
        layer_off(_MOVMNT);
        update_tri_layer_RGB(_SYMBOL, _MOVMNT, _NUMBER);
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

