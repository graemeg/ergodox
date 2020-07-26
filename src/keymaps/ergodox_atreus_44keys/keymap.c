#include QMK_KEYBOARD_H
#include "version.h"

#define ______   KC_TRNS	// Make changes in layers more visible
#define __x___   KC_NO	// Make changes in layers more visible
#define NK_TOGG  MAGIC_TOGGLE_NKRO

enum layers {
   _BASE = 0
  ,_SYMBOLS
  ,_FKEYS
  ,_NAV
  ,_GAMES
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#include "beakl.h"
#include "symbols.h"
#include "fkeys.h"
#include "nav.h"
#include "game.h"

};

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};

void matrix_init_user(void) {
    // You can set brightness_level 15(LED_BRIGHTNESS_LO) to 255(LED_BRIGHTNESS_HI).
    ergodox_led_all_set( 25 );
};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}

// Auto enable the NumLock key so the numpad layer always works.
void led_set_keymap(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }
}
