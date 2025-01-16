/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

#include QMK_KEYBOARD_H

#include "rgb_matrix_map.h"
#include "rgb_settings.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     MO(2)           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    MO(1)       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TG(2),          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, RGB_TOG, AC_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,   KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0, KC_PSLS, KC_PAST, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PMNS, KC_PPLS, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(LCTL(KC_TAB), LCTL(LSFT(KC_TAB)))},
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif


#ifdef RGB_MATRIX_ENABLE

#include QMK_KEYBOARD_H

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case AC_TOGG:
                autocorrect_toggle();
                return false; // Skip further processing for this key
            case AC_ON:
                autocorrect_enable();
                return false;
            case AC_OFF:
                autocorrect_disable();
                return false;
        }
    }
    return true; // Process other keycodes as usual
}



bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // if (get_rgb_nightmode()) rgb_matrix_set_color_all(RGB_OFF);

    led_t led_state = host_keyboard_led_state();

    // Scroll Lock RGB setup
    if (led_state.scroll_lock) {
        rgb_matrix_set_color(LED_L3, RGB_RED);
        rgb_matrix_set_color(LED_L4, RGB_RED);
        rgb_matrix_set_color(LED_TAB, RGB_RED);
        rgb_matrix_set_color(LED_F12, RGB_RED);
    }

    // CapsLock RGB setup
    if (led_state.caps_lock) {
        hsv_t hsv = user_config.caps_lock_hs;
        hsv.v = rgb_matrix_get_val();
        rgb_t rgb = hsv_to_rgb(hsv);

        for (uint8_t i = 0; i < ARRAY_SIZE(LED_LIST_LETTERS); i++) {
            rgb_matrix_set_color(LED_LIST_LETTERS[i], rgb.r, rgb.g, rgb.b);
        }
        rgb_matrix_set_color(LED_L1, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L2, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L3, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L4, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L5, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L6, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L7, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L8, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_LSFT, rgb.r, rgb.g, rgb.b);
    }

    // Winkey disabled (gaming) mode RGB setup
    if (keymap_config.no_gui) {
        rgb_matrix_set_color(LED_LWIN, RGB_RED); //light up Winkey red when disabled
        rgb_matrix_set_color(LED_W, RGB_CHARTREUSE); //light up gaming keys with WSAD highlighted
        rgb_matrix_set_color(LED_S, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_A, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_D, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_Q, RGB_ORANGE2);
        rgb_matrix_set_color(LED_E, RGB_ORANGE2);
        rgb_matrix_set_color(LED_R, RGB_ORANGE2);
        rgb_matrix_set_color(LED_TAB, RGB_ORANGE2);
        rgb_matrix_set_color(LED_F, RGB_ORANGE2);
        rgb_matrix_set_color(LED_Z, RGB_ORANGE2);
        rgb_matrix_set_color(LED_X, RGB_ORANGE2);
        rgb_matrix_set_color(LED_C, RGB_ORANGE2);
        rgb_matrix_set_color(LED_V, RGB_ORANGE2);
        rgb_matrix_set_color(LED_SPC, RGB_ORANGE2);
        rgb_matrix_set_color(LED_LCTL, RGB_ORANGE2);
        rgb_matrix_set_color(LED_LSFT, RGB_ORANGE2);
    }

    if (IS_LAYER_ON(1)) {
        hsv_t hsv = user_config.layer1_hs;
        hsv.v = rgb_matrix_get_val();
        rgb_t rgb = hsv_to_rgb(hsv);

        for (uint8_t j = 0; j < ARRAY_SIZE(LED_LIST_FUNCROW); j++) {
            rgb_matrix_set_color(LED_LIST_FUNCROW[j], rgb.r, rgb.g, rgb.b);
        }

        rgb_matrix_set_color(LED_FN, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_BSLS, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L1, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L2, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L3, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L4, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L5, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L6, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L7, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L8, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_W, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_S, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_E, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_D, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_F, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_N, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_DOWN, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_LEFT, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_RIGHT, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R1, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R2, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R3, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R4, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R5, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R6, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R7, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_R8, rgb.r, rgb.g, rgb.b);
    }

    if (IS_LAYER_ON(2)) {
        hsv_t hsv = user_config.layer2_hs;
        hsv.v = rgb_matrix_get_val();
        rgb_t rgb = hsv_to_rgb(hsv);

        for (uint8_t i = 0; i < ARRAY_SIZE(LED_LIST_NUMPAD); i++) {
            rgb_matrix_set_color(LED_LIST_NUMPAD[i], rgb.r, rgb.g, rgb.b);
        }
        rgb_matrix_set_color(LED_L1, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L2, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L3, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L4, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L5, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L6, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L7, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(LED_L8, rgb.r, rgb.g, rgb.b);
    }
    return false;
}

#endif // RGB_MATRIX_ENABLE
