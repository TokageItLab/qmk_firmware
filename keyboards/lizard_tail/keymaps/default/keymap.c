#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
               KC_F1, KC_F2, KC_F3, KC_F4,
        KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,
        KC_KP_SLASH, KC_KP_7, KC_KP_8, KC_KP_9, KC_HOME,
        KC_KP_ASTERISK, KC_KP_4, KC_KP_5, KC_KP_6, KC_END,
        KC_KP_MINUS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PAGE_UP,
        KC_KP_PLUS, KC_KP_0, KC_KP_DOT, KC_KP_ENTER, KC_PAGE_DOWN
    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    /* First encoder */
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
    return true;
}
#endif

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) { return false; }

    switch (index) {
    /* First encoder */
    case 0:
        if (active) {
            register_code(KC_MS_BTN3);
        } else {
            unregister_code(KC_MS_BTN3);
        }
        break;
    }
    return true;
}
#endif