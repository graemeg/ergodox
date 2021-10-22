/* jedit settings  :elasticTabstops=true:encoding=UTF-8: */

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "timer.h"

/*
  Author: Graeme Geldenhuys <graeme@geldenhuys.co.uk>

  Based on the Dvorak keymap, with some TypeMatrix 2030 design ideas.
  Some key locations are also designed to work well with my programming
  environment.
  
  Compile with:
    ./build.sh
       or
    gmake ergodox_ez:gg_dvorak:teensy
*/

#define GG_VERSION "1.33"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)

#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)


/* Window Layout layer keys */
#define KC_LAY_CENTRE LALT(LGUI(KC_C))

#define KC_LAY_TOPLEFT LCTL(LGUI(KC_LEFT))
#define KC_LAY_TOPHALF LALT(LGUI(KC_UP))
#define KC_LAY_TOPRIGHT LCTL(LGUI(KC_RIGHT))

#define KC_LAY_NEXT3RD LALT(LCTL(KC_RIGHT))
#define KC_LAY_LEFTHALF LALT(LGUI(KC_LEFT))
#define KC_LAY_FULLSCR LALT(LGUI(KC_F))
#define KC_LAY_RIGHTHALF LALT(LGUI(KC_RIGHT))
#define KC_LAY_NEXTDSP LALT(LCTL(LGUI(KC_RIGHT)))

#define KC_LAY_PREV3RD LALT(LCTL(KC_LEFT))
#define KC_LAY_LOWLEFT LCTL(LGUI(LSFT(KC_LEFT)))
#define KC_LAY_LOWHALF LALT(LGUI(KC_DOWN))
#define KC_LAY_LOWRIGHT LCTL(LGUI(LSFT(KC_RIGHT)))
#define KC_LAY_PREVDSP LALT(LCTL(LGUI(KC_LEFT)))

#define ______   KC_TRNS	// Make changes in layers more visible
#define __x___   KC_NO	// Make changes in layers more visible

/* Layers */
enum {
	BASE = 0,	// default layer
	BEAKL15,	// BEAKL-15 layout
//	BEAKL27A,	// BEAKL-27A layout
	QWER,	// QWERTY
	MAC,	// Mac CMD instead of Ctrl
	SYMB,	// symbols + NumPad
	MOUSE,	// Mouse navigation and Media buttons
	AROWS,	// arrows, PgUp, PgDn, Home, End
	GAMES,	// Games (No dual-function keys)
//	SHRTCUT,	// Shortcuts & OS Modifiers
	WINLAYOUT	// Window Layout manager shortcuts
};

/* Macros (aka Actions) */
enum {
	NONE = 0,
	
	// useful shortcuts
	MDBL0,
	EPRM,
	VRSN,
	GBP,
	EUR,
	
	A_COPYCUT,	// Copy/Cut

	// number/symbol keys
	A_1, // 1
	A_2, // 2
	A_3, // ...
	A_4,
	A_5,
	A_6,
	A_7,
	A_8,
	A_9,
	A_0,
};

// use for dual-key Cut/Copy action.
static uint16_t m_copypaste_timer;

/*
	If it accepts an argument (i.e, is a function), it doesn't need KC_.
	Otherwise, it needs KC_*

	You can use dual keys for modifiers too, as follows:
	SFT_T(KC_O),	CTL_T(KC_E),	ALT_T(KC_U)
	ALL_T(...) = Hyper
	MEH_T(...) = Meh

	For layer switching options and explanation, see the following page:
	   https://docs.qmk.fm/#/feature_advanced_keycodes

	I also have Space-Cadet Shift keys enabled and disabled command mode via the Makefile.
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
/* Keymap 0: Basic layer                                                  Version: 1.xx

 ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 │  Esc   │  F1  │  F2  │  F3  │  F4  │  F5  │  F11 │           │  F12 │  F6  │  F7  │  F8  │  F9  │  F10 │   \  | │
 ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 │  Tab   │  '  "│  ,  <│  .  >│  P   │   Y  │ Del  │           │ BkSp │   F  │   G  │  C   │  R   │  L   │   /  ? │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │  Caps  │  A   │  O   │  E   │  U • │   I  ├──────┤           ├──────┤   D  │ • H  │  T   │  N   │  S   │   -  _ │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │ Enter├──────┼──────┼──────┼──────┼──────┼────────┤
 │ Shift  │  ;  :│  Q   │  J   │  K   │   X  │      │           │      │   B  │   M  │  W   │  V   │  Z   │  Shift │
 ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
   │LCtrl │ Cmd  │ LAlt │~WinMg│~Arrow│                                       │~Mouse│ Cut  │ Copy │ Enter│ RCtrl│
   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
                                        ╭──────┬──────╮       ╭──────┬──────╮
                                        │ GAME │ QWER │       │ MAC  │      │
                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮      Hyper = Meh+Gui
                                 │ Space│ Enter│ BEAKL│       │ PgUp │      │      │        Meh = Control+Alt+Shift
                                 │  /   │  /   ├──────┤       ├──────┤ Del  │~SYMB │        GUI = Super, Win or Cmd key
                                 │ Ctrl │ RAlt │ PScr │       │ PgDn │      │      │        App = Menu key
                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯        OSL = One-Shot Layer
 */
	// left hand
	KC_ESC,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F11,
	KC_TAB,	KC_QUOT,	KC_COMM,	KC_DOT,	KC_P,	KC_Y,	KC_DEL,
	KC_CAPS,	KC_A,	KC_O,	KC_E,	KC_U,	KC_I,
	KC_LSFT,	KC_SCLN,	KC_Q,	KC_J,	KC_K,	KC_X,	__x___,
	KC_LCTRL,	KC_LGUI,	KC_LALT,	MO(WINLAYOUT),	MO(AROWS),

		TG(GAMES),	TG(QWER),
			TG(BEAKL15),
	CTL_T(KC_SPC),	ALGR_T(KC_ENT),	KC_PSCR,

	// right hand
	KC_F12,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_BSLASH,
	KC_BSPC,	KC_F,	KC_G,	KC_C,	KC_R,	KC_L,	KC_SLASH,
		KC_D,	KC_H,	KC_T,	KC_N,	KC_S,	KC_MINUS,
	KC_ENT,	KC_B,	KC_M,	KC_W,	KC_V,	KC_Z,	KC_RSFT,
			MO(MOUSE),	KC_PC_CUT,	KC_PC_COPY,	KC_ENT,	KC_RCTRL,

	TG(MAC),	__x___,
	KC_PGUP,
	KC_PGDN,	KC_ENT,	MO(SYMB)
),
#include "beakl15.h"
//#include "beakl27a.h"
#include "qwerty.h"
#include "mac.h"
#include "symbols.h"
#include "mouse.h"
#include "arrows.h"
#include "games.h"
[WINLAYOUT] = LAYOUT_ergodox(
/* Window Manager Layout shortcuts

 ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │        │      │      │      │     •│      ├──────┤           ├──────┤      │•     │      │      │      │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
   │      │      │      │      │      │                                       │      │      │      │      │      │
   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
                                        ╭──────┬──────╮       ╭──────┬──────╮
                                        │      │      │       │      │      │
                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮
                                 │      │      │      │       │      │      │      │
                                 │      │      ├──────┤       ├──────┤      │      │
                                 │      │      │      │       │      │      │      │
                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
*/
	// left hand
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,
	______,	______,
	______,
	______,	______,	______,

	// right hand
	______,	______,	______,	KC_LAY_CENTRE,	______,	______,	______,
	______,	______,	KC_LAY_TOPLEFT,	KC_LAY_TOPHALF,	KC_LAY_TOPRIGHT,	______,	______,
		KC_LAY_NEXT3RD,	KC_LAY_LEFTHALF,	KC_LAY_FULLSCR,	KC_LAY_RIGHTHALF,	KC_LAY_NEXTDSP,	______,
	______,	KC_LAY_PREV3RD,	KC_LAY_LOWLEFT,	KC_LAY_LOWHALF,	KC_LAY_LOWRIGHT,	KC_LAY_PREVDSP,	______,
			______,	______,	______,	______,	______,
	______,	______,
	______,
	______,	______,	______
)

};

/* Empty template layer - copy and paste usage

 ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │        │      │      │      │     •│      ├──────┤           ├──────┤      │•     │      │      │      │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
   │      │      │      │      │      │                                       │      │      │      │      │      │
   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
                                        ╭──────┬──────╮       ╭──────┬──────╮
                                        │      │      │       │      │      │
                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮
                                 │      │      │      │       │      │      │      │
                                 │      │      ├──────┤       ├──────┤      │      │
                                 │      │      │      │       │      │      │      │
                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 
	// left hand
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,
	______,	______,
	______,
	______,	______,	______,

	// right hand
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,	______,
		______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,	______,
			______,	______,	______,	______,	______,
	______,	______,
	______,
	______,	______,	______

*/



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
		case MDBL0:
			if (record->event.pressed) {
				return MACRO( T(0), T(0), END );
			}
			break;
		case EPRM:
			if (record->event.pressed) { // For resetting EEPROM
				eeconfig_init();
			}
			break;
		case VRSN:
			if (record->event.pressed) {
				SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " (" GG_VERSION ") with QMK " QMK_VERSION );
			}
			break;
		//case GBP:
		//	if (record->event.pressed) {
		//		send_unicode_string("£");
		//	}
		//	break;
		//case EUR:
		//	if (record->event.pressed) {
		//		send_unicode_string("€");
		//	}
		//	break;
		case A_COPYCUT:
			if (record->event.pressed) {
				m_copypaste_timer = timer_read ();
			} else {
				if (timer_elapsed (m_copypaste_timer) > TAPPING_TERM) {
					// Long press: Cut
					return MACRO(D(RCTRL), T(X), U(RCTRL), END);
				} else {
					// Short press: Copy
					return MACRO(D(RCTRL), T(C), U(RCTRL), END);
				}
			}
			break;
      }
    return MACRO_NONE;

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
	
//	set_unicode_input_mode(UC_BSD);
/*
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
*/
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

//    static uint8_t state;
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    //reduce LED on time to 1/6th because LEDs are too strong
//    if (++state < 6) return;
//    state = 0;

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

};
