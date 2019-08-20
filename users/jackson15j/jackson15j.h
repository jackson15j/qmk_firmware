#pragma once

enum userspace_layers {
    _QWERTY,
    _SYMBOL,
    _MOVMNT,
    _NUMBS,
    _ADJUST
};

enum userspace_custom_keycodes {
  QWERTY,
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

// 1x6 Thumb cluster.
#define CORNE_THUMB_L KC_LCTRL, KC_LALT, KC_SPC_SYM
// #define CORNE_THUMB_R KC_SPC_LSFT, KC_MOVMNT, KC_NUMBS
#define CORNE_THUMB_R KC_SPC, KC_MOVMNT, KC_NUMBS
#define CORNE_THUMBS CORNE_THUMB_L, CORNE_THUMB_R

// 1x12 Thumb Cluster.
// TODO: Rotary Encoder.
#define PLANCK_THUMBS KC_XXXXX, KC_LCTRL, KC_LGUI, CORNE_THUMBS, KC_LEFT, KC_DOWN, KC_RIGHT

// 3x12 Qwerty layout.
#define QWERTY_L1 KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define QWERTY_L2 KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define QWERTY_L3 KC_Z, KC_WINX,    KC_C,    KC_V,    KC_B
#define QWERTY_R1 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define QWERTY_R2 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define QWERTY_R3 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH
#define QWERTY_R3_PLANCK KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP
  // [_QWERTY] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   ESC,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|   TAB,     A,     S,     D,     F,     G,                      H,     J,     K,     L,     ;,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LSFT,     Z,  WINX,     C,     V,     B,                      N,     M,     ,,     .,     /,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),
#define QWERTY_1_12 KC_ESC, QWERTY_L1, QWERTY_R1, KC_BSPC
#define QWERTY_2_12 KC_TAB, QWERTY_L2, QWERTY_R2, KC_ENT
#define QWERTY_3_12 KC_LSFT, QWERTY_L3, QWERTY_R3, KC_RSFT
#define QWERTY_3_12_PLANCK KC_LSFT, QWERTY_L3, QWERTY_R3_PLANCK, KC_RSFT

// 3x12 Symbols layout.
#define SYMBOL_L1 KC_EXCLM, KC_DBLQT,   KC_GBP,  KC_DOLR, KC_PRCNT
#define SYMBOL_L2 KC_LCURLY,  KC_LBRC, KC_LPAREN, KC_MINUS, KC_GRAVE
#define SYMBOL_L3 KC_ATT,  KC_PLUS,  KC_NUBS, KC_JPIPE,  KC_QUOT
#define SYMBOL_R1 KC_HAT,   KC_AMP,  KC_STAR, KC_LPAREN, KC_RPAREN
#define SYMBOL_R2 KC_JHASH, KC_UNDSCR, KC_RPAREN,  KC_RBRC, KC_RCURLY
#define SYMBOL_R3 KC_TILDA,  KC_SLSH,   KC_EQL, KC_QUEST,  KC_SLSH
  // [_SYMBOL] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   ESC,     !,     ",     £,     $,     %,                      ^,     &,     *,     (,     ),   DEL,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|   TAB,     {,     [,     (,     -,     `,                      #,     _,     ),     ],     },   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LSFT,     @,     +,     \,     |,     ',                      ~,     /,     =,     ?,     /,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),
#define SYMBOL_1_12 KC_ESC, SYMBOL_L1, SYMBOL_R1, KC_DEL
#define SYMBOL_2_12 KC_TAB, SYMBOL_L2, SYMBOL_R2, KC_ENT
#define SYMBOL_3_12 KC_LSFT, SYMBOL_L3, SYMBOL_R3, KC_RSFT

// 3x12 Movement layout.
#define MOVMNT_L1 KC_XXXXX,  KC_WH_U,  KC_MS_U,  KC_WH_D,  KC_XXXXX
#define MOVMNT_L2 KC_BTN1,   KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN2
#define MOVMNT_L3 KC_LGUI,   KC_LGUI,  KC_XXXXX, KC_XXXXX, KC_RST
#define MOVMNT_R1 KC_XXXXX,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_DEL
#define MOVMNT_R2 KC_HOME,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END
#define MOVMNT_R3 KC_MUTE,   KC_VOLD,  KC_VOLU,  KC_INS,   KC_PSCR
  // [_MOVMNT] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   ESC, XXXXX,  WH_U,  MS_U,  WH_D, XXXXX,                  XXXXX,  PGUP,    UP,  PGDN,   DEL,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|   TAB,  BTN1,  MS_L,  MS_D,  MS_R,  BTN2,                   HOME,  LEFT,  DOWN,  RGHT,   END,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LSFT,  LGUI,  LGUI, XXXXX, XXXXX,   RST,                   MUTE, VOLD,   VOLU,   INS,  PSCR,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),
#define MOVMNT_1_12 KC_ESC, MOVMNT_L1, MOVMNT_R1, KC_BSPC
#define MOVMNT_2_12 KC_TAB, MOVMNT_L2, MOVMNT_R2, KC_ENT
#define MOVMNT_3_12 KC_LSFT, MOVMNT_L3, MOVMNT_R3, KC_RSFT

// 3x12 Numbers layout.
#define NUMBS_L1 KC_EXCLM, KC_DBLQT, KC_GBP,   KC_DOLR,   KC_PRCNT
#define NUMBS_L2 KC_1,     KC_2,     KC_3,     KC_4,      KC_5
#define NUMBS_L3 KC_F1,    KC_WINF2, KC_F3,    KC_F4,     KC_F5
#define NUMBS_R1 KC_HAT,   KC_AMP,   KC_STAR,  KC_LPAREN, KC_RPAREN
#define NUMBS_R2 KC_6,     KC_7,     KC_8,     KC_9,      KC_0
#define NUMBS_R3 KC_F6,    KC_F7,    KC_F8,    KC_DOT,    KC_F12
  // [_NUMBS] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   ESC,     !,     ",     £,     $,     %,                      ^,     &,     *,     (,     ),  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|   TAB,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LSFT,    F1, WINF2,    F3,    F4,    F5,                     F6,    F7,    F8,     .,   F12,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),
#define NUMBS_1_12 KC_ESC, NUMBS_L1, NUMBS_R1, KC_BSPC
#define NUMBS_2_12 KC_TAB, NUMBS_L2, NUMBS_R2, KC_ENT
#define NUMBS_3_12 KC_LSFT, NUMBS_L3, NUMBS_R3, KC_RSFT

// 3x12 Adjust layout.
#define ADJUST_L1 KC_LRST,  KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX
#define ADJUST_L2 KC_LHUI,  KC_LSAI,  KC_LVAI,  KC_XXXXX, KC_XXXXX
#define ADJUST_L3 KC_LHUD,  KC_LSAD,  KC_LVAD,  KC_XXXXX, KC_RST
#define ADJUST_R1 KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX
#define ADJUST_R2 KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX
#define ADJUST_R3 KC_RST,   KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX
  // [_ADJUST] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LMOD,  LHUD,  LSAD,  LVAD, XXXXX,   RST,                    RST, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // )
#define ADJUST_1_12 KC_RST, ADJUST_L1, ADJUST_R1, KC_XXXXX
#define ADJUST_2_12 KC_LTOG, ADJUST_L2, ADJUST_R2, KC_XXXXX
#define ADJUST_3_12 KC_LMOD, ADJUST_L3, ADJUST_R3, KC_XXXXX
