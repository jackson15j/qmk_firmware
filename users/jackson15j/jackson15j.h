#pragma once
#include "quantum.h"

enum userspace_layers {
    _QWERTY,
    _COLEMAK_DHM,
    _SYMBOL,
    _MOVMNT,
    _NUMBS,
    _ADJUST,
    _SYMBOL2
};

/* enum userspace_custom_keycodes {
  QWERTY,
  COLEMAK_DHM,
  SYMBOL,
  NUMBS,
  MOVMNT,
  ADJUST,
  SYMBOL2,
  RGBRST,
  MBTN1,
  SCRL
}; */

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_SPC_SYM LT(_SYMBOL, KC_SPC)  // Tap=space, hold=SYMBOL layer.
#define KC_SPC_NUM LT(_NUMBS, KC_SPC)  // Tap=space, hold=NUMBS layer.
#define KC_SPC_LSFT MT(MOD_LSFT, KC_SPC)  // Tap=space, hold=Left Shift.
#define KC_J_LCTRL MT(MOD_LCTL, KC_J)  // Tap=J, hold=Left Ctrl.
#define KC_K_LALT MT(MOD_LALT, KC_K)  // Tap=K, hold=Left Alt.
#define KC_RST   RESET
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
#define KC_WINX LWIN_T(KC_X)
#define KC_WINF2 LWIN_T(KC_F2)
#define KC_WINDO RWIN_T(KC_DOT)

#define KC_MBTN1  MBTN1
#define KC_SCRL   SCRL

// Colemak defintions.
#define KC_A_OS LGUI_T(KC_A)  // Tap=A, Hold=Left OS.
#define KC_R_SHFT MT(MOD_LSFT, KC_R)  // Tap=R, Hold=Left Shift.
#define KC_S_LALT MT(MOD_LALT, KC_S)  // Tap=S, Hold=Left Alt.
#define KC_T_LCTRL MT(MOD_LCTL, KC_T)  // Tap=T, Hold=Left Ctrl.
#define KC_G_ALTGR MT(MOD_RALT, KC_G)  // Tap=G, Hold=AltGr.
#define KC_M_ALTGR MT(MOD_RALT, KC_M)  // Tap=M, Hold=AltGr.
#define KC_N_LCTRL MT(MOD_RCTL, KC_N)  // Tap=N, Hold=Right Ctrl.
#define KC_E_LALT MT(MOD_LALT, KC_E)  // Tap=E, Hold=Left Alt.
#define KC_I_SHFT MT(MOD_RSFT, KC_I)  // Tap=R, Hold=Right Shift.
#define KC_O_OS RGUI_T(KC_O)  // Tap=O, Hold=Right OS.


#if (!defined(LAYOUT) && defined(KEYMAP))
    #define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)


// 1x6 Thumb cluster.
#define CORNE_THUMB_L KC_LCTRL, KC_LALT, KC_SPC_SYM
// #define CORNE_THUMB_R KC_SPC_LSFT, KC_MOVMNT, KC_NUMBS
#define CORNE_THUMB_R KC_SPC_NUM, MO(_MOVMNT), MO(_NUMBS)
#define CORNE_THUMBS CORNE_THUMB_L, CORNE_THUMB_R
#define CORNE_THUMBS_TRNS KC______, KC______, KC______, KC______, KC______, KC______

// 1x12 Thumb Cluster.
// TODO: Rotary Encoder - Testing out presses with a full-stop.
#define PLANCK_THUMBS KC_DOT, KC_LCTRL, KC_LGUI, CORNE_THUMBS, KC_LEFT, KC_DOWN, KC_RIGHT

// 3x12 Qwerty layout.
#define QWERTY_L1 KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define QWERTY_L2 KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define QWERTY_L3 KC_Z, KC_WINX,    KC_C,    KC_V,    KC_B
#define QWERTY_R1 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define QWERTY_R2 KC_H,    KC_J_LCTRL,    KC_K_LALT,    KC_L,    KC_SCLN
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
                              //| LCTRL,  LALT,SPC_SYM, SPC_NUM,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),
#define QWERTY_1_12 KC_ESC, QWERTY_L1, QWERTY_R1, KC_BSPC
#define QWERTY_2_12 KC_TAB, QWERTY_L2, QWERTY_R2, KC_ENT
#define QWERTY_3_12 KC_LSFT, QWERTY_L3, QWERTY_R3, KC_RSFT
#define QWERTY_3_12_PLANCK KC_LSFT, QWERTY_L3, QWERTY_R3_PLANCK, KC_RSFT

// 3x12 Colemak-DHm layout.
#define COLEMAK_DHM_L1 KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define COLEMAK_DHM_L2 KC_A_OS,    KC_R_SHFT,    KC_S_LALT,    KC_T_LCTRL,    KC_G_ALTGR
#define COLEMAK_DHM_L3 KC_Z, KC_X,    KC_C,    KC_D,    KC_V
#define COLEMAK_DHM_R1 KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define COLEMAK_DHM_R2 KC_M_ALTGR,    KC_N_LCTRL,    KC_E_LALT,    KC_I_SHFT,    KC_O_OS
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
#define COLEMAK_DHM_1_12 KC_ESC, COLEMAK_DHM_L1, COLEMAK_DHM_R1, KC_BSPC
#define COLEMAK_DHM_2_12 KC_TAB, COLEMAK_DHM_L2, COLEMAK_DHM_R2, KC_ENT
#define COLEMAK_DHM_3_12 KC_LSFT, COLEMAK_DHM_L3, COLEMAK_DHM_R3, KC_RSFT

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
#define SYMBOL_1_12 KC______, SYMBOL_L1, SYMBOL_R1, KC______
#define SYMBOL_2_12 KC_LANGLE, SYMBOL_L2, SYMBOL_R2, KC_RANGLE
#define SYMBOL_3_12 KC______, SYMBOL_L3, SYMBOL_R3, KC______

// 3x12 Movement layout.
#define MOVMNT_L1 KC_XXXXX,  KC_WH_U,  KC_MS_U,  KC_WH_D,  KC_XXXXX
#define MOVMNT_L2 KC_BTN1,   KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN2
#define MOVMNT_L3 KC_LGUI,   KC_LGUI,  DF(_COLEMAK_DHM), DF(_QWERTY), KC_XXXXX
#define MOVMNT_R1 KC_XXXXX,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_DEL
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
#define MOVMNT_1_12 KC______, MOVMNT_L1, MOVMNT_R1, KC______
#define MOVMNT_2_12 KC_TAB, MOVMNT_L2, MOVMNT_R2, KC_ENT
#define MOVMNT_3_12 KC______, MOVMNT_L3, MOVMNT_R3, KC______

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
                              //| LCTRL,  LALT,SPC_SYM, SPC_NUM,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),
#define NUMBS_1_12 KC______, NUMBS_L1, NUMBS_R1, KC______
#define NUMBS_2_12 KC______, NUMBS_L2, NUMBS_R2, KC______
#define NUMBS_3_12 KC______, NUMBS_L3, NUMBS_R3, KC______

// 3x12 Adjust layout.
#define ADJUST_L1 KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX
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
                              //| LCTRL,  LALT,SPC_SYM, SPC_NUM,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // )
#define ADJUST_1_12 KC_RST, ADJUST_L1, ADJUST_R1, KC_XXXXX
#define ADJUST_2_12 KC_LTOG, ADJUST_L2, ADJUST_R2, KC_XXXXX
#define ADJUST_3_12 KC_LMOD, ADJUST_L3, ADJUST_R3, KC_XXXXX
