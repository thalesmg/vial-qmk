/*
Copyright 2022 fgoodwin <fgoodwin@north-tech.net>
Copyright 2026 dumagnus

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
#include "print.h" // Add at the top of your keymap.c for uprintf

#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

/*
 * Thales - Dactyl Manuform 6x4 + 5 thumb
 *
 * Main area: 6 columns x 4 rows per hand.
 * In every keymap row below, the LEFT half reads OUTER -> INNER (pinky column
 * first, index/inner column last) and the RIGHT half reads INNER -> OUTER.
 * Both halves use matrix col 0 = innermost, col 5 = outermost.
 *
 * Thumb cluster (5 keys per hand):
 *   - Row 4 (pin 7): 3 keys on the 3 innermost columns.
 *   - Row 5 (pin 8): 2 keys on the 2 innermost columns.
 *
 * LAYOUT_split_6x4_5 argument order (58 keys):
 *   row0: L[c5 c4 c3 c2 c1 c0]  R[c0 c1 c2 c3 c4 c5]
 *   row1: L[c5 c4 c3 c2 c1 c0]  R[c0 c1 c2 c3 c4 c5]
 *   row2: L[c5 c4 c3 c2 c1 c0]  R[c0 c1 c2 c3 c4 c5]
 *   row3: L[c5 c4 c3 c2 c1 c0]  R[c0 c1 c2 c3 c4 c5]
 *   thumb top:    L[c2 c1 c0]   R[c0 c1 c2]
 *   thumb bottom:    L[c1 c0]   R[c0 c1]
 *
 * This keymap mirrors the layout configured in VIA
 * (see via/dactyl_manuform_thales__6x4___5_thumb_.layout.json).
 * MO(1) = LOWER, MO(2) = RAISE. RGB controls live on the RAISE layer.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_6x4_5(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   KC_LALT, MO(1),   KC_SPC,    KC_ENT,  MO(2),   KC_BSPC,
                                            KC_LGUI, KC_GRV,    KC_DEL,  KC_CAPS
    ),

    [_LOWER] = LAYOUT_split_6x4_5(
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_ESC,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_MPLY,   KC_MPRV,   KC_MNXT,
        KC_GRV,    S(KC_1),   S(KC_2),   S(KC_3),   S(KC_4),   S(KC_5),     S(KC_6),   S(KC_7),   S(KC_8),   S(KC_9),   S(KC_0),   S(KC_GRV),
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_MINS,   KC_EQL,    S(KC_LBRC),S(KC_RBRC),KC_BSLS,
                                         KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
                                                    KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS
    ),

    [_RAISE] = LAYOUT_split_6x4_5(
        QK_BOOT,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     RGB_TOG,   RGB_MOD,   RGB_HUI,   RGB_VAD,   RGB_VAI,   QK_BOOT,
        KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,        KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_TRNS,
        KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,       KC_END,    KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_TRNS,
        KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,      KC_EQL,    KC_MINS,   KC_EQL,    KC_LBRC,   KC_RBRC,   KC_BSLS,
                                         KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,
                                                    KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS
    ),

    [_ADJUST] = LAYOUT_split_6x4_5(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        uprintf("Row: %d, Col: %d | keycode: 0x%04X\n", record->event.key.row, record->event.key.col, keycode);
    }
    return true;
}
