#include QMK_KEYBOARD_H

#define MY_LOCK LCTL(LGUI(KC_Q))

enum custom_keycodes {
    // Auto-closed opening curly brace with move back.
    MY_LBRC = SAFE_RANGE,
    // Closing curly brace with move back.
    MY_RBRC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  =+    |   1  |   2  |   3  |   4  |   5  | REC1 |           | PLY1 |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | CTRL |           | CTRL |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| +SPC |           | +SPC |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;:  |   '"   |
 * |--------+------+------+------+------+------| GUI  |           | GUI  |------+------+------+------+------+--------|
 * | Shift  |Z/Ctrl|   X  |   C  |   V  |   B  | +SPC |           | +SPC |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  `~  |  \|  | Left | Right|                                       | Down |  Up  |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                         ,------------.       ,------------.
 *                                         | Gui | Ctrl |       | Ctrl | Gui |
 *                                  ,------|-----|------|       |------+-----+------.
 *                                  |      |     | Alt  |       | Alt  |     |      |
 *                                  | BkSp | Del |------|       |------| Tab |Space |
 *                                  |      |     | Fn   |       | Fn   |     |      |
 *                                  `-------------------'       `-------------------'
 */

[0] = LAYOUT_ergodox(
        // left hand
        KC_EQL  ,KC_1       ,KC_2    ,KC_3    ,KC_4    ,KC_5 ,DM_REC1     ,
        KC_TAB  ,KC_Q       ,KC_W    ,KC_E    ,KC_R    ,KC_T ,LCTL(KC_SPC),
        KC_ESC  ,KC_A       ,KC_S    ,KC_D    ,KC_F    ,KC_G ,
        KC_LSFT ,CTL_T(KC_Z),KC_X    ,KC_C    ,KC_V    ,KC_B ,LGUI(KC_SPC),
        _______ ,KC_GRV     ,KC_BSLS ,KC_LEFT ,KC_RGHT ,
                                                                      KC_LGUI, KC_LCTL,
                                                                               KC_LALT,
                                                              KC_BSPC,KC_DEL,  MO(1),
        // right hand
             DM_PLY1     ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0          ,KC_MINS,
             RCTL(KC_SPC),KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P          ,KC_BSLS,
                          KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN       ,KC_QUOT,
             RGUI(KC_SPC),KC_N   ,KC_M   ,KC_COMM,KC_DOT ,CTL_T(KC_SLSH),KC_RSFT,
                                  KC_DOWN,KC_UP  ,KC_LBRC,KC_RBRC       ,_______,
             KC_RCTL,KC_RGUI,
             KC_LALT,
             MO(1),  KC_ENTER,KC_SPC
    ),

/* FN layer.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | REC2 |           | PLY2 |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   Fl2  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Caps  |      |      |      |      |      |------|           |------| Left | Down |  Up  |Right |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Boot |      |  Ins | Home | End  |                                       | PgDn | PgUp |  {}  |  {}* |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[1] = LAYOUT_ergodox(
       // left hand
       _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  DM_REC2,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,
       KC_CAPS,_______,_______,_______,_______,_______,_______,
       QK_BOOT,_______,KC_INS ,KC_HOME,KC_END ,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,

       // right hand
       DM_PLY2,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10,  KC_F11,
       _______,_______,_______,_______,_______,_______, KC_F12,
               KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
                       KC_PGDN,KC_PGUP,MY_LBRC,MY_RBRC,_______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (keycode == MY_LBRC && record->event.pressed) {
        SEND_STRING("{}"SS_TAP(X_LEFT));
    } else if (keycode == MY_RBRC && record->event.pressed) {
        SEND_STRING("}"SS_TAP(X_LEFT));
    }

    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
        case KC_LSFT:
        case KC_RSFT:
            return true;

        // Digits continue Caps Word unless shifted.
        case KC_1 ... KC_0: {
            const uint8_t mods = get_mods();
            if (mods & MOD_MASK_SHIFT) {
                return false;
            }
            return true;
        }

        default:
            return false;  // Deactivate Caps Word.
    }
}
