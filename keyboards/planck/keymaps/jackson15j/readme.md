Jackson15j Planck
=================

See: [/users/jackson15j/], for layout and generic code.

Build
-----

**Need to press the `RESET` button on the bottom of the board to put it into
Bootloader mode, before you run the following command from the root of the QMK
folder:**

```bash
make plank/rev6:jackson15j:dfu-util
```

**Note:** If the board is not in Bootloader mode, you get the following output:

```bash
No DFU capable USB device available
make[1]: *** [tmk_core/chibios.mk:238: dfu-util] Error 74
Make finished with errors
ake: *** [Makefile:560: planck/rev6:jackson15j:dfu-util] Error 1
```

See: [Reddit r/olkb: help flashing plank rev6].


[/users/jackson15j/]: ../../../../users/jackson15j/
[Reddit r/olkb: help flashing plank rev6]: https://www.reddit.com/r/olkb/comments/ao8bib/help_flashing_planck_rev6_keep_getting_make/
