#pragma once

enum userspace_layers {
    _QWERTY,
    _SYMBOL,
    _MOVMNT,
    _NUMBS,
    _ADJUST
};

enum custom_keycodes {
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

