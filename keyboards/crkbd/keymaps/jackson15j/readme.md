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

Layout is now held in: [/users/jackson15j/].

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

[/users/jackson15j/]: ../../../../users/jackson15j/
