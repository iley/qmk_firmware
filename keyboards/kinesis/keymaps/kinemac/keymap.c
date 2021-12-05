#include QMK_KEYBOARD_H


#include "features/caps_word.h"

#define MY_LOCK LCTL(LGUI(KC_Q))

enum custom_keycodes {
    // Auto-closed opening curly brace with newlines.
    MY_LBRC = SAFE_RANGE,
    // Closing curly brace with newlines.
    MY_RBRC,
};

/****************************************************************************************************
*
* Ilya Strukov's keyboard layout optimized for a software engineer who's using MacOS and Vim.
* 
* Differences from vanilla Kinesis layout:
*   - Up & Down arrows swapped to match Vim's J/K
*   - Fn, Ctrl, Alt & Command in both thumb clusters
*   - Esc swapped with Caps Lock for better Vim experience. Caps Lock is also accessible with Fn
*   - PageUp, PageDown, Home, and End are shifted into the FN layer like on Mac keyboards
*   - Fn+1 = F1, Fn+2 = F2 etc. This makes function keys easier to reach
*   - Media keys with Fn like on Mac keyboards
*   - Program = Lock Screen (Ctrl+Command+Q)
*   - Fn+Program = reset for firmware programming
*   - Auto-closing curly braces with Fn
*
* Default layer
*
* ,--------------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F11 |  F12 | PSCR | SLCK | PAUS |      |  LOCK  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                                  |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                                  +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                                  |------+------+------+------+------+--------|
* | Esc    |   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                                  |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                                  `------+------+------+------+------+--------'
*          | `~   | \|   | Left | Right|                                                | Down | Up   |  [{  |  ]}  |
*          `---------------------------'                                                `---------------------------'
*                                        ,-------------.                ,-------------.
*                                        | Gui  | Ctrl |                | Ctrl | Gui  |
*                                 ,------|------|------|                |------+------+------.
*                                 |      |      | Alt  |                | Alt  |      |      |
*                                 | BkSp | Del  |------|                |------|Return| Space|
*                                 |      |      | Fn   |                | Fn   |      |      |
*                                 `--------------------'                `--------------------'
*
* FN layer
*
* ,--------------------------------------------------------------------------------------------------------------------------.
* |        |      |      |      |      |      |PrevTr| Play |NextTr| Mute | VolDn| VolUp|      |      |      |      |  RESET |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+--------|
* |        |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
* |--------+------+------+------+------+------|                                  +------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                  |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                                  |------+------+------+------+------+--------|
* | Caps   |      |      |      |      |      |                                  | Left | Down |  Up  | Right|      |        |
* |--------+------+------+------+------+------|                                  |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                  |      |      |      |      |      |        |
* `--------+------+------+------+------+-------                                  `------+------+------+------+------+--------'
*          |      | Ins  | Home | End  |                                                | PgDn | PgUp |  {}  |  {}* |
*          `---------------------------'                                                `---------------------------'
*                                        ,-------------.                ,-------------.
*                                        |      |      |                |      |      |
*                                 ,------|------|------|                |------+------+------.
*                                 |      |      |      |                |      |      |      |
*                                 |      |      |------|                |------|      |      |
*                                 |      |      |      |                |      |      |      |
*                                 `--------------------'                `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_ESC, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_BSLS,KC_LEFT,KC_RGHT,
                                                   KC_LGUI,KC_LCTL,
                                                           KC_LALT,
                                           KC_BSPC,KC_DEL ,MO(1)  ,

           KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR,KC_SLCK,KC_PAUS,KC_NO  ,MY_LOCK,
                                   KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
                                   KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
                                   KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
                                   KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                                           KC_DOWN,KC_UP  ,KC_LBRC,KC_RBRC,
                  KC_RCTL,KC_RGUI,
                  KC_RALT,
                  MO(1)  ,KC_ENTER ,KC_SPC
    ),

    [1] = LAYOUT(
           _______,_______,_______,_______,_______,_______,_______,KC_MPRV,KC_MPLY,
           _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,
           _______,_______,_______,_______,_______,_______,
           KC_CAPS,_______,_______,_______,_______,_______,
           _______,_______,_______,_______,_______,_______,
                   _______,KC_INS ,KC_HOME,KC_END ,
                                                   _______,_______,
                                                           _______,
                                           _______,_______,_______,

           KC_MNXT,KC_MUTE,KC_VOLD,KC_VOLU,_______,_______,_______,_______,RESET  ,
                                   KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_______,
                                   _______,_______,_______,_______,_______,_______,
                                   KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______,
                                   _______,_______,_______,_______,_______,_______,
                                           KC_PGDN,KC_PGUP,MY_LBRC,MY_RBRC,
                  _______,_______,
                  _______,
                  _______,_______,_______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_caps_word(keycode, record)) {
        return false;
    }

    if (keycode == MY_LBRC && record->event.pressed) {
        SEND_STRING("{\n}"SS_TAP(X_UP)SS_TAP(X_END)"\n");
    } else if (keycode == MY_RBRC && record->event.pressed) {
        SEND_STRING("\n}"SS_TAP(X_UP)SS_TAP(X_END)"\n");
    }

    return true;
}
