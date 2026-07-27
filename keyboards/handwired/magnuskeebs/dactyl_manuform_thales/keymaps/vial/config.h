/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#define SERIAL_USE_MULTI_TRANSACTION
#define SPLIT_USB_DETECT

/* WS2812 underglow on GP12 (data), shared 5V/GND already soldered.
 * Sync RGB state across the split so both halves match. */
#define RGBLIGHT_SLEEP
#define SPLIT_TRANSPORT_MIRROR

/* Recover from a half that boots without a working split link (seen on cold
 * boot when the PC powers up with the keyboard already connected). Supported
 * in this QMK's split_common; timeout must be above SPLIT_USB_TIMEOUT. */
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

/* EXPERIMENT: cap underglow brightness to lower peak current draw. The right
 * thumb cluster is farthest from USB power and reads dimmer, likely voltage
 * drop; a lower ceiling reduces current and should even out the halves. Raise
 * back to 255 (the default) if it does not help. Retest on hardware.
 * Tuning: if 150 evens out the halves, try raising toward 200 for more overall
 * brightness; if the sides still differ noticeably, lower the value until the
 * difference is gone, then nudge it back up a little. */
#define RGBLIGHT_LIMIT_VAL 150

#define VIAL_KEYBOARD_UID {0x6C, 0x99, 0x82, 0xA9, 0x32, 0xAC, 0x25, 0xD7}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 } // esc
#define VIAL_UNLOCK_COMBO_COLS { 5, 0 } // 5
