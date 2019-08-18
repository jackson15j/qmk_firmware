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


[Github: jackson15j/vortex_core]: https://github.com/jackson15j/vortex_core
