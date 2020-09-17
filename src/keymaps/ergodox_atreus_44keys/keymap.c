#include QMK_KEYBOARD_H
#include "version.h"

/*
  Author: Graeme Geldenhuys <graeme@geldenhuys.co.uk>

  As the directory name says. This layout is to allow you to seamlessly
  swap between the Ergodox and the Keyboardio Atreus, by only using
  a common set of 44 keys.
  
  Compile with:
    ./build.sh
       or
    make ergodox_ez:ergodox_atreus_44keys:teensy
*/

#define ______   KC_TRNS	// Make changes in layers more visible
#define __x___   KC_NO	// Make changes in layers more visible
#define TG_NKRO  MAGIC_TOGGLE_NKRO

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)

#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    // You can set brightness_level 15(LED_BRIGHTNESS_LO) to 255(LED_BRIGHTNESS_HI).
    
	ergodox_led_all_on();
	for (int i = LED_BRIGHTNESS_HI; i > LED_BRIGHTNESS_LO; i--) {
		ergodox_led_all_set (i);
		wait_ms (5);
	}
	wait_ms(700);
	for (int i = LED_BRIGHTNESS_LO; i > 0; i--) {
		ergodox_led_all_set (i);
		wait_ms (10);
	}
	ergodox_led_all_off();
    
	// not too bright LEDs
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
