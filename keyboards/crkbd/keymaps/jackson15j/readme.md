Jackson15j Crkbd/Corne
======================

See: [/users/jackson15j/], for layout and generic code.

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

Links
-----

Build logs:

* [The Frey: helidox-build-log].
* [ThomasBaart: corne/helidox build log].
* [Vlukash: Corne/Crkbd build log].
* [Github: foostan/crkbd corne-classic build guide].


[The Frey: helidox-build-log]: http://the-frey.github.io/2019/02/15/helidox-build-log
[ThomasBaart: corne/helidox build log]: https://thomasbaart.nl/2018/11/26/corne-keyboard-helidox-build-log/
[Vlukash: Corne/Crkbd build log]: https://vlukash.com/2019/01/14/corne-crkbd-keyboard-build/
[Github: foostan/crkbd corne-classic build guide]: https://github.com/foostan/crkbd/blob/master/corne-classic/doc/buildguide_en.md

[/users/jackson15j/]: ../../../../users/jackson15j/
