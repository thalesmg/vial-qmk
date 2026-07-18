# Dactyl Manuform Thales (6x4 main + 5 thumb)

A handwired split [Dactyl-Manuform](https://github.com/tshort/dactyl-keyboard) variant
built by dumagnus. Each half has a 6-column x 4-row main finger area plus a 5-key thumb
cluster, for 58 keys total (29 per hand).

![Dactyl Manuform Thales layout](kle/dactyl-manuform-thales.jpg)

* Keyboard Maintainer: [dumagnus](https://github.com/duMagnus)
* Hardware Supported: RP2040 Zero (one per half), USB-C breakout for the split link
* Case / 3D model: designed in [Cosmos (ryanis.cool)](https://ryanis.cool/cosmos/beta#cm:CqYBChkSBRCAbyAnEgIgExICIAASADgeQICGisAHChYSBRCAYyAnEgIgExICIAASAxCwOzgKChsSBRCAVyAnEgIgExICIAASAxCwLzgJQIDwvAIKExIFEIBLICcSAiATEgIgABIAOB0KExIFEIA/ICcSAiATEgIgABIAODEKHBICICcSAiATEgYQoIAKIAASAhAwODJAgIaKwAcYAEDohaCu8FVI3ryfcAqUAQoXEhMQwIACQICAmAJIwpmglZC8AVBDOAgKGBIUEMCAAkCAgMwCSMKZoJWQvAFQhgFQOgoVEhAQQECAgCBI0JWA3ZD1A1ALUJ4CChQSEBBAQICA+AFI5pn8p5ALUFdQfwoVEhAQQECAgKQDSPCZxLXQMFB0UJUBGAIiCgjIARDIARhaIABAy4v8n9AxSK2R3I3BkwYQBhiEoAIiBhicBCCSCTgGWEtoAHIHEJwBkAGcAYIBBYEBxQIB)
  -- open the link to view or print the model.

## Hardware / wiring

* **Controller:** RP2040 Zero on each half.
* **Rows (both hands, top -> bottom):** GP3, GP4, GP5, GP6, GP7, GP8.
  * Rows 0-3 are the 4 main rows (all 6 columns populated).
  * Row 4 (GP7) is the thumb top row: 3 keys on the 3 innermost columns.
  * Row 5 (GP8) is the thumb bottom row: 2 keys on the 2 innermost columns.
* **Columns (inner -> outer):**
  * Left half:  GP29, GP28, GP27, GP26, GP15, GP14
  * Right half: GP14, GP15, GP26, GP27, GP28, GP29
  * On both halves matrix column 0 = innermost, column 5 = outermost.
* **Diodes:** COL2ROW.
* **Split link:** half-duplex serial on GP11 (USB-C breakout: D+ -> GP11, VCC -> 3V3, GND -> GND).
* **Underglow:** WS2812B addressable LEDs, data on **GP12**, powered from the reserved
  5V/GND wires.

### Matrix

The firmware matrix is 12 rows x 6 columns: left half = matrix rows 0-5, right half =
matrix rows 6-11. Verified physical positions (via `qmk console`):

* Outer top-left (Esc) = `[0,5]`; inner top-left (5) = `[0,0]`.
* Inner top-right (6) = `[6,0]`; outer top-right (grave) = `[6,5]`.
* Left thumb  top (L->R): `[4,2] [4,1] [4,0]`; bottom: `[5,1] [5,0]`.
* Right thumb top (L->R): `[10,0] [10,1] [10,2]`; bottom: `[11,0] [11,1]`.

### RGB underglow (split)

The LED strip is wired to the **right half only** (the serial slave). Because of this,
`keyboard.json` sets `rgblight.split_count` to `[0, 68]` (0 LEDs left, 68 right), which
implicitly enables `RGBLIGHT_SPLIT` so the master transmits RGB state across the link.
Without this, the RGB_* keycodes toggle state on the master but never reach the slave's
LEDs. `config.h` also defines `SPLIT_TRANSPORT_MIRROR` and `RGBLIGHT_SLEEP`.

Set `rgblight.led_count` (and the right value in `split_count`) in `keyboard.json` to match
your strip. If RGB state ever gets stuck after changing the LED count, clear the EEPROM
(`EE_CLR`, or a temporary `eeconfig_init()` in `keyboard_post_init_user`).

## VIA

The `via/` folder contains:

* `dactyl_via.json` -- the V3 definition to sideload in the [VIA](https://usevia.app) Design
  tab. Its physical layout comes from `kle/dactyl-manuform-thales.json` (converted via
  [keymap-layout-tools](https://nickcoutsos.github.io/keymap-layout-tools/)), with the key
  labels remapped to this firmware's real 12x6 matrix.
* `dactyl_manuform_thales__6x4___5_thumb_.layout.json` -- a saved VIA keymap backup. VIA
  stores layers in canonical matrix order (`index = row * 6 + col`).

## Build

Compile:

    qmk compile -kb handwired/magnuskeebs/dactyl_manuform_thales -km default

    # vial
    make handwired/magnuskeebs/dactyl_manuform_thales:vial

Note: `qmk compile -j 0` can hang under QMK-MSYS on Windows; omit `-j 0` or pass a real job
count. See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
and [make instructions](https://docs.qmk.fm/#/getting_started_make_guide). New to QMK? Start
with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

A prebuilt image is bundled here as `dactyl_manuform_thales_default.uf2`, so the board can be
re-flashed without recompiling. Update it whenever the keymap changes:

    qmk compile -kb handwired/magnuskeebs/dactyl_manuform_thales -km default
    cp handwired_magnuskeebs_dactyl_manuform_thales_default.uf2 \
       keyboards/handwired/magnuskeebs/dactyl_manuform_thales/dactyl_manuform_thales_default.uf2

## Flashing

Both halves must be flashed with matching firmware. For each half:

1. **Enter the bootloader:** press and hold **BOOT**, tap **RESET**, then release **BOOT**.
   The RP2040 mounts as a USB drive (RPI-RP2).
2. **Drag** `dactyl_manuform_thales_default.uf2` onto that drive. The board reboots into the
   new firmware automatically.

(`qmk flash` also works if you prefer, but the drag-and-drop of the bundled `.uf2` needs no
toolchain.)

## Bootloader

Enter the bootloader in 2 ways:

* **Buttons (reliable):** press and hold **BOOT**, tap **RESET**, then release **BOOT**.
* **Keycode:** `QK_BOOT` lives on the `_RAISE` layer -- hold `MO(2)` (right thumb) and press
  the outer top-row key on either half.
