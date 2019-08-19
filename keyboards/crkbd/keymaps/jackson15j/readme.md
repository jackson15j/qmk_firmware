Jackson15j Crkbd/Corne
======================

Custom layout that is based on my custome programming layout from my Vortex
Core ([Github: jackson15j/vortex_core]). Aim of my layout:

* Place programming symbols (Python/C++) under/around index fingers, instead of
  pinky.
* Symmetric layout between hands (as much as possible).
* Use emacs, so need `Ctrl`/`Alt` on the left-side.
* I'm a right-hand `Space` fan, but added to left-side as well for single half
  gaming.
* Keep shifted-number symbols in the same place (fallback stock-Qwerty muscle
  memory).
* Use `EE_HANDS` so that either half can be plugged in.

Build
-----

From the root of the QMK folder:

```bash
make crkbd:jackson15j:dfu-split-<left/right>  # Elite-C.
make crkbd:jackson15j:avrdude-split-<left/right>  # Pro-Micro.
```

Then double tap (Single tap = ~1sec, double tap = ~8secs in Boot Loader) the
`GND` and `RST` pins on the MCU, so that the red LED flashes and it drops into
the boot loader. Should flash in a few seconds.

### Gotcha's

Couldn't get this to flash on my Dell XPS (would flash slowly and always
timeout). Think it was due to the inbuilt USB3/thunderbolt hub.

Layout
------

Current code dump of my layout layers:

```cpp
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
```

Links
-----

Build logs:

* [The Frey: helidox-build-log].
* [ThomasBaart: corne/helidox build log].
* [Vlukash: Corne/Crkbd build log].
* [Github: foostan/crkbd corne-classic build guide].

QMK firmware:

* [QMK Docs].
* [QMK Docs: split-keyboard-options].
* [ThomasBaart: qmk-basics].
* [Github: qmk/qmk_driver_installer].


[QMK Docs]: https://docs.qmk.fm/
[QMK Docs: split-keyboard-options]: https://docs.qmk.fm/reference/config_options#split-keyboard-options
[ThomasBaart: qmk-basics]: https://thomasbaart.nl/category/mechanical-keyboards/firmware/qmk/qmk-basics/
[Github: qmk/qmk_driver_installer]: https://github.com/qmk/qmk_driver_installer
[Github: jackson15j/vortex_core]: https://github.com/jackson15j/vortex_core

[The Frey: helidox-build-log]: http://the-frey.github.io/2019/02/15/helidox-build-log
[ThomasBaart: corne/helidox build log]: https://thomasbaart.nl/2018/11/26/corne-keyboard-helidox-build-log/
[Vlukash: Corne/Crkbd build log]: https://vlukash.com/2019/01/14/corne-crkbd-keyboard-build/
[Github: foostan/crkbd corne-classic build guide]: https://github.com/foostan/crkbd/blob/master/corne-classic/doc/buildguide_en.md
