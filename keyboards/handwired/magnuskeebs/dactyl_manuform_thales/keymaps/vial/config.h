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

#define VIAL_KEYBOARD_UID {0x6C, 0x99, 0x82, 0xA9, 0x32, 0xAC, 0x25, 0xD7}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 5 } // esc
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 } // 5

#define RGBLIGHT_LED_COUNT 68
// this seems to be sourced/generated from keyboards.json
/* #define RGBLED_SPLIT [0, 60] */

#define RGBLIGHT_DEFAULT_HUE 127
#define RGBLIGHT_DEFAULT_SAT 0
