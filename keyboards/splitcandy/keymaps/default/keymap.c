// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
// Define aliases for layers
#define _BASE 0
#define _LAYER1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐
     * │ q │ w │ e │ r │ t │
     * ├───┼───┼───┼───┼───┤
     * │ a │ s │ d │ f │ g │
     * ├───┼───┼───┼───┼───┤
     * │ z │ x │ c │ v │ b │
     * └───┴───┴───┼───┼───┤───┐
     *             │LSh│Spc│LCt│
     *             └───┴───┴───┘
     */
    [_BASE] = LAYOUT(
        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,
                                KC_LCTL, MO(_LAYER1) ,KC_SPACE
    ),
    /*
     * ┌───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │
     * ├───┼───┼───┼───┼───┤
     * │F1 │F2 │F3 │F4 │F5 │
     * ├───┼───┼───┼───┼───┤
     * │ _ │ _ │ _ │V+ │V- │
     * └───┴───┴───┼───┼───┤───┐
     *             │___│___│___│
     *             └───┴───┴───┘
     */
    [_LAYER1] = LAYOUT(
        KC_1,   KC_2,   KC_3,   KC_4,       KC_5,
        KC_F1,  KC_F2,  KC_F3,  KC_F4,      KC_F5,
        ____,   ____,   ____,   KC_VOLU,    KC_VOLD,
                                ______,     _______     ,_______
    )
};
