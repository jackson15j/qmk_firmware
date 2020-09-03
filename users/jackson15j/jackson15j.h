#pragma once
#include "quantum.h"

enum userspace_layers {
    _QWERTY,
    _COLEMAK_DHM,
    _GAME,
    _SYMBOL,
    _MOVMNT,
    _NUMBS,
    _ADJUST,
};

#define KC_SPC_SYM LT(_SYMBOL, KC_SPC)  // Tap=space, hold=SYMBOL layer.
#define KC_SPC_NUM LT(_NUMBS, KC_SPC)  // Tap=space, hold=NUMBS layer.
#define KC_UNDSCR LSFT(KC_MINS)  // `_`
#define KC_PLUS LSFT(KC_EQL)  // `+`
#define KC_JPIPE LSFT(KC_NUBS)  // `|`
#define KC_JHASH KC_NUHS  // `#`
#define KC_TILDA LSFT(KC_NUHS)  // `~`
#define KC_ATT LSFT(KC_QUOT)  // `@`
#define KC_QUEST LSFT(KC_SLSH)  // `?`
#define KC_LCURLY LSFT(KC_LBRC)  // `{`
#define KC_RCURLY LSFT(KC_RBRC)  // `}`
#define KC_LANGLE LSFT(KC_COMMA)  // `<`
#define KC_RANGLE LSFT(KC_DOT) // `>`
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
#define KC_TRNS_1X4 _______, _______, _______, _______
#define KC_TRNS_1X5 KC_TRNS_1X4, _______
#define KC_TRNS_1X6 KC_TRNS_1X5, _______


#if (!defined(LAYOUT) && defined(KEYMAP))
    #define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
// #define LAYOUT_split_3x5_2_wrapper(...)  LAYOUT_split_3x5_2(__VA_ARGS__)


// 1x4 Thumb cluster.
#define FERRIS_THUMB_L LSFT_T(KC_BSPC), KC_SPC_SYM
#define FERRIS_GAME_THUMB_L KC_LCTRL, KC_SPC_NUM  // TODO: `KC_ALT`.
#define FERRIS_THUMB_R KC_SPC_NUM, LT(_MOVMNT, KC_ENT)
#define FERRIS_THUMBS FERRIS_THUMB_L, FERRIS_THUMB_R
#define FERRIS_GAME_THUMBS FERRIS_GAME_THUMB_L, FERRIS_THUMB_R
#define FERRIS_THUMBS_TRNS KC_TRNS_1X4

// 1x6 Thumb cluster.
#define CORNE_THUMB_L LCTL_T(KC_DEL), FERRIS_THUMB_L
#define CORNE_GAME_THUMB_L KC_LCTRL, KC_LALT, KC_SPC_NUM
#define CORNE_THUMB_R FERRIS_THUMB_R, MO(_NUMBS)
#define CORNE_THUMBS CORNE_THUMB_L, CORNE_THUMB_R
#define CORNE_GAME_THUMBS CORNE_GAME_THUMB_L, CORNE_THUMB_R
#define CORNE_THUMBS_TRNS KC_TRNS_1X6

// 1x10 Thumb Cluster.
#define KYRIA_THUMBS KC_MUTE, KC_LGUI, CORNE_THUMBS, KC_RGUI, KC_MUTE

// 1x12 Thumb Cluster.
// TODO: Rotary Encoder - Testing out presses with a full-stop.
#define PLANCK_THUMBS KC_DOT, KC_LCTRL, KC_LGUI, CORNE_THUMBS, KC_LEFT, KC_DOWN, KC_RIGHT

// 3x10 Qwerty layout.
#define QWERTY_L1 KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define QWERTY_L2 LGUI_T(KC_A),    LSFT_T(KC_S),    LALT_T(KC_D),    LCTL_T(KC_F),    ALGR_T(KC_G)
#define QWERTY_L2_NO_MODS KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define QWERTY_L3 KC_Z, KC_X,    KC_C,    KC_V,    KC_B
#define QWERTY_R1 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define QWERTY_R2 ALGR_T(KC_H),    RCTL_T(KC_J),    LALT_T(KC_K),    RSFT_T(KC_L),    RGUI_T(KC_SCLN)
#define QWERTY_R2_NO_MODS KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define QWERTY_R3 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH
#define QWERTY_R3_PLANCK KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP
// TODO: Update/Delete these layout comments !!
  // [_QWERTY] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   ESC,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|   TAB,     A,     S,     D,     F,     G,                      H,     J,     K,     L,     ;,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LSFT,     Z,  WINX,     C,     V,     B,                      N,     M,     ,,     .,     /,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM, SPC_NUM,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),
#define QWERTY_3_12_PLANCK KC_LSFT, QWERTY_L3, QWERTY_R3_PLANCK, KC_RSFT

// 3x12 Colemak-DHm layout.
// FIXME: Still can't hit: ŵ and ŷ with `AltGr` yet. need to fix that up.
// See: https://en.wikipedia.org/wiki/AltGr_key#Scotland_and_Wales
#define COLEMAK_DHM_L1 KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define COLEMAK_DHM_L2 LGUI_T(KC_A),    RSFT_T(KC_R),    LALT_T(KC_S),    LCTL_T(KC_T),    ALGR_T(KC_G)
#define COLEMAK_DHM_L3 KC_Z, KC_X,    KC_C,    KC_D,    KC_V
#define COLEMAK_DHM_R1 KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define COLEMAK_DHM_R2 ALGR_T(KC_M),    RCTL_T(KC_N),    LALT_T(KC_E),    RSFT_T(KC_I),    RGUI_T(KC_O)
#define COLEMAK_DHM_R3 KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH
  // [_COLEMAK_DHM] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   ESC,     Q,     W,     F,     P,     B,                      J,     L,     U,     Y,     ;,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|   TAB,  A_OS, R_SFT, S_LAT, T_CTL, G_ALG,                  M_ALG, N_CTL, E_SFT, I_ALT,  O_OS,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LSFT,     Z,     X,     C,     D,     V,                      K,     H,     ,,     .,     /,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM, SPC_NUM,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),

// 3x12 Symbols layout.
#define SYMBOL_L1 KC_EXCLM, KC_DBLQT,   KC_GBP,  KC_DOLR, KC_PRCNT
#define SYMBOL_L2 KC_LCURLY,  KC_LBRC, KC_LPAREN, KC_MINUS, KC_GRAVE
#define SYMBOL_L3 KC_ATT,  KC_PLUS, KC_JPIPE,  KC_NUBS,  KC_QUOT
#define SYMBOL_R1 KC_HAT,   KC_AMP,  KC_STAR, KC_LPAREN, KC_RPAREN
#define SYMBOL_R2 KC_JHASH, KC_UNDSCR, KC_RPAREN,  KC_RBRC, KC_RCURLY
#define SYMBOL_R3 KC_TILDA,  KC_SLSH,   KC_EQL, KC_QUEST,  KC_SLSH
  // [_SYMBOL] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   ESC,     !,     ",     £,     $,     %,                      ^,     &,     *,     (,     ),   DEL,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|     <,     {,     [,     (,     -,     `,                      #,     _,     ),     ],     },     >,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LSFT,     @,     +,     |,     \,     ',                      ~,     /,     =,     ?,     /,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM, SPC_NUM,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),
#define SYMBOL_1_12 _______, SYMBOL_L1, SYMBOL_R1, KC_DEL
#define SYMBOL_2_12 KC_LANGLE, SYMBOL_L2, SYMBOL_R2, KC_RANGLE
#define SYMBOL_3_12 _______, SYMBOL_L3, SYMBOL_R3, _______

// 3x12 Movement layout.
// TODO: Having home row mods on left-hand feels like a bigger win than
// mouse-keys that I rarely use! Need to also remove from `rules.mk`.
// Maybe numpad/symbols/F-keys or something on left instead to make a better
// use of this side ??
#define MOVMNT_L1 XXXXXXX,  KC_WH_U,  KC_MS_U,  KC_WH_D,  XXXXXXX
#define MOVMNT_L2 KC_BTN1,   KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN2
#define MOVMNT_L3 KC_LGUI,   KC_LGUI,  DF(_COLEMAK_DHM), DF(_QWERTY), DF(_GAME)
#define MOVMNT_R1 XXXXXXX,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_DEL
#define MOVMNT_R2 KC_HOME,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END
#define MOVMNT_R3 KC_MUTE,   KC_VOLD,  KC_VOLU,  KC_INS,   KC_PSCR
  // [_MOVMNT] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   ESC, XXXXX,  WH_U,  MS_U,  WH_D, XXXXX,                  XXXXX,  PGUP,    UP,  PGDN,   DEL,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|   TAB,  BTN1,  MS_L,  MS_D,  MS_R,  BTN2,                   HOME,  LEFT,  DOWN,  RGHT,   END,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LSFT,  LGUI,  LGUI,COLEMK, QWERTY, GAME,                   MUTE, VOLD,   VOLU,   INS,  PSCR,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM, SPC_NUM,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),

// 3x12 Numbers layout.
#define NUMBS_L1 KC_EXCLM, KC_DBLQT, KC_GBP,   KC_DOLR,   KC_PRCNT
#define NUMBS_L2 KC_1,     KC_2,     KC_3,     KC_4,      KC_5
#define NUMBS_L3 KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5
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
                              //| LCTRL,  LALT,SPC_SYM, SPC_NUM,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),

// 3x12 game layout.
#define GAME_L1 QWERTY_L1
#define GAME_L2 QWERTY_L2_NO_MODS
#define GAME_L3 QWERTY_L3
#define GAME_R1 MOVMNT_R1
#define GAME_R2 MOVMNT_R2
#define GAME_R3 MOVMNT_R3
#define GAME_R3_PLANCK QWERTY_R3_PLANCK
  // [_GAME] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   ESC,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|   TAB,     A,     S,     D,     F,     G,                      H,     J,     K,     L,     ;,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LSFT,     Z,     X,     C,     V,     B,                      N,     M,     ,,     .,     /,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_NUM, SPC_NUM,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),
#define GAME_1_12 _______, GAME_L1, GAME_R1, _______
#define GAME_2_12 _______, GAME_L2, GAME_R2, _______
#define GAME_3_12 _______, GAME_L3, GAME_R3, _______

// 3x12 Adjust layout.
#define ADJUST_L1 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_L2 RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX, XXXXXXX
#define ADJUST_L3 RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX, RESET
#define ADJUST_R1 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_R2 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_R3 RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  // [_ADJUST] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   RST,  LRST, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LMOD,  LHUD,  LSAD,  LVAD, XXXXX,   RST,                    RST, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM, SPC_NUM,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // )
