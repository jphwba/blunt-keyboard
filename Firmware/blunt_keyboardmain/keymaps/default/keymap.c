// Copyright 2022 QMK / James Young (@noroadsleft)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    WINLOCK = SAFE_RANGE,
    KBLOCK,
};

bool winlock = false;
bool keyboard_lock = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WINLOCK:
            if (record->event.pressed) {
                winlock = !winlock;
            }
            return false;

        case KBLOCK:
            if (record->event.pressed) {
                keyboard_lock = !keyboard_lock;
            }
            return false;
    }

    if (keyboard_lock) {
        return false;
    }

    if (winlock && (keycode == KC_LGUI || keycode == KC_RGUI)) {
        return false;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_6x16(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_PAUS, KC_DEL, // Row 0 (16)
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,         // Row 1 (15)
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,         // Row 2 (15)
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN,                  // Row 3 (14)
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP, KC_END,                     // Row 4 (14)
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT                                                         // Row 5 (10)
    ),

[1] = LAYOUT_ortho_6x16(
    QK_BOOT, RM_TOGG, RM_NEXT, RM_HUEU, RM_VALU, RM_VALD, RM_FLGN, _______, _______, _______, _______, KBLOCK, WINLOCK, _______, _______, _______, // Row 0 (16)
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         // Row 1 (15)
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         // Row 2 (15)
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                  // Row 3 (14)
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______,                  // Row 4 (14)
    _______, _______, _______, KC_MPLY, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT                                                       // Row 5 (10)
),
};



