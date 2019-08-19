Overview
========

Personal user space for my keyboards:

* [crkbd].

Layout
------

Current code dump of my layout layers:

```cpp
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

  // [_NUMBS] = LAYOUT_kc(
  //,-----------------------------------------.                ,-----------------------------------------.
  //|   ESC,     !,     ",     £,     $,     %,                      ^,     &,     *,     (,     ),   DEL,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|   TAB,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,   ENT,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  //|  LSFT,    F1, WINF2,    F3,    F4,    F5,                     F6,    F7,    F8,     .,   F12,  RSFT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                              //| LCTRL,  LALT,SPC_SYM,SPC_LSFT,MOVMNT, NUMBS
                              //`--------------------'  `--------------------'
  // ),

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
```

Links
-----

QMK firmware:

* [QMK Docs].
* [QMK Docs: feature/userspace].
* [ThomasBaart: qmk-basics].
* [Github: qmk/qmk_driver_installer].

Good User spaces and keymaps:

* [/users/jarred/].
* [/users/drashna/].


[QMK Docs]: https://docs.qmk.fm/
[QMK Docs: feature/userspace]: https://docs.qmk.fm/#/feature_userspace
[ThomasBaart: qmk-basics]: https://thomasbaart.nl/category/mechanical-keyboards/firmware/qmk/qmk-basics/
[Github: qmk/qmk_driver_installer]: https://github.com/qmk/qmk_driver_installer
[Github: jackson15j/vortex_core]: https://github.com/jackson15j/vortex_core

[crkbd]: ../../keyboards/crkbd/keymaps/jackson15j/
[/users/jarred/]: ../jarred/
[/users/drashna/]: ../drashna/
