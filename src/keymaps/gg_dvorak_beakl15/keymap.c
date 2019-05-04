/* jedit settings  :elasticTabstops=true: */

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
/* #include "keymap_extras/keymap_uk.h" */
#include "process_unicode.h"
#include "version.h"
#include "timer.h"

/*
  Author: Graeme Geldenhuys <graeme@geldenhuys.co.uk>
  Ver 9
  Based on the default Dvorak keymap, and applied some
  tweaks from the TypeMatrix 2030 design. Some key locations are also
  designed to work well with my programming environment (FPC +Lazarus).
  Second keymap is the BEAKL-15 layout.
  
  Compile with;   make ergodox_ez:gg_dvorak_beakl15:teensy
*/

#define CUT      LCTL(KC_X)	// C-x Cut
#define COPY     LCTL(KC_C)	// C-c Copy
#define PASTE    LCTL(KC_V)	// C-v Paste
#define COMPI    LCTL(KC_F9)	// Ctrl+F9 used for compiling while developing with Object Pascal IDEs.
#define ______   KC_TRNS	// Make changes in layers more visible
#define __x___   KC_NO	// Make changes in layers more visible
#define SPC_SHF  SFT_T(KC_SPC)  // Dual key: Space on tap, Shift on hold

/* Custom layer names - easier for when you reorganise layers */
enum {
	BASE = 0,	// default layer
	BEAKL1,	// BEAKL-15 unshifted layer
	SYMB,	// symbols + NumPad
	ARROWS,	// arrows, PgUp, PgDn, Home, End
	GAME,	// easier for gaming
	FKEYS,	// F-keys
	QWER,	// QWERTY
	MOUSE,	// Mouse navigation
	SHORT	// shortcuts
};

/* Macros (aka Actions) */
enum {
	NONE = 0,
	
	// useful shortcuts
	MACRO_TODO,
	MACRO_ISEQUALS,
	MACRO_PARENTHESE,
	MDBL0,
	EPRM,
	VRSN,
	POUND,
	EURO,
	
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
	A_0
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
	   https://docs.qmk.fm/#/feature_advanced_keycodes?id=switching-and-toggling-layers

	I also have Space-Cadet Shift keys enabled and disabled command mode via the Makefile.
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
/* Keymap 0: Basic layer                                                  Version: 9
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │  Esc   │  1   │  2   │  3   │  4   │   5  │  F11 │           │  F12 │   6  │   7  │  8   │  9   │  0   │  Home  │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Tab   │  '  "│  ,  <│  .  >│  P   │   Y  │ Cut/ │           │ BkSp │   F  │   G  │  C   │  R   │  L   │   End  │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤  Copy│           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │   -    │  A   │  O   │  E   │  U • │   I  ├──────┤           ├──────┤   D  │ • H  │  T   │  N   │  S   │   ;    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ Paste│           │ Enter├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ Shift  │  /  ?│   Q  │   J  │  K   │   X  │      │           │      │   B  │   M  │  W   │  V   │  Z   │  Shift │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │LCtrl │ LAlt │      │      │~Arows│                                       │~FK/ ◀│   ▲  │   ▼  │  ▶   │ RCtrl│
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬──────╮
 *                                        │ Game │ BEAKL│       │ GUI  │ Menu │
 *                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮      Hyper = Meh+Gui
 *                                 │      │      │ PScr │       │ ScrLk│      │ ~Symb│        Meh = Control+Alt+Shift
 *                                 │ Space│ BkSp ├──────┤       ├──────┤  Del │   /  │        GUI = Super or Win key
 *                                 │      │      │ Tab  │       │ Caps │      │  TAB │        App = Menu key
 *                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 */
	// left hand
	KC_ESCAPE,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_F11,
	KC_TAB,	KC_QUOTE,	KC_COMMA,	KC_DOT,	KC_P,	KC_Y,	M(A_COPYCUT),
	KC_MINUS,	KC_A,	KC_O,	KC_E,	KC_U,	KC_I,
	KC_LSHIFT,	KC_SLASH,	KC_Q,	KC_J,	KC_K,	KC_X,	LCTL(KC_V),
	KC_LCTRL,	KC_LALT,	__x___,	__x___,	MO(ARROWS),
	
	TG(GAME),	TG(BEAKL1),
	KC_PSCREEN,
	KC_SPACE,	KC_ENTER,	KC_TAB,
	
	// right hand
	KC_F12,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_CAPSLOCK,
	KC_BSPACE,	KC_F,	KC_G,	KC_C,	KC_R,	KC_L,	__x___,
		KC_D,	KC_H,	KC_T,	KC_N,	KC_S,	KC_SCOLON,
	KC_ENTER,	KC_B,	KC_M,	KC_W,	KC_V,	KC_Z,	KC_RSHIFT,
			LT(FKEYS,KC_LEFT),	KC_UP,	KC_DOWN,	KC_RIGHT,	KC_RCTRL,
	
	KC_RGUI,	KC_APPLICATION,
	KC_SCROLLLOCK,
	KC_CAPSLOCK,	KC_DELETE,	LT(SYMB, KC_TAB)
),


[BEAKL1] = LAYOUT_ergodox(
/* Keymap 1: BEAKL-15
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  Q   │  H   │  O   │  U   │   X  │ Cut/ │           │ BkSp │   G  │   C  │  R   │  F   │  Z   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤  Copy│           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  Y   │  I   │  E   │  A • │   .  ├──────┤           ├──────┤   D  │ • S  │  T   │  N   │  B   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤ Paste│           │ Enter├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ Shift  │  J   │  /  ?│  ,   │  K   │   '  │      │           │      │   W  │   M  │  L   │  P   │  V   │  Shift │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                       │      │      │      │      │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬──────╮
 *                                        │      │      │       │      │      │
 *                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮      Hyper = Meh+Gui
 *                                 │      │      │      │       │      │      │      │        Meh = Control+Alt+Shift
 *                                 │      │      ├──────┤       ├──────┤      │      │        GUI = Super or Win key
 *                                 │      │      │      │       │      │      │      │        App = Menu key
 *                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 */
	// left hand
	______,	______,	______,	______,	______,	______,	______,
	______,	KC_Q,	KC_H,	KC_O,	KC_U,	KC_X,	______,
	______,	KC_Y,	KC_I,	KC_E,	KC_A,	KC_DOT,
	______,	KC_J,	KC_SLASH,	KC_COMMA,	KC_K,	KC_QUOTE,	______,
	______,	______,	______,	______,	______,
	
	______,	______,
	______,
	______,	______,	______,
	
	// right hand
	______,	______,	______,	______,	______,	______,	______,
	______,	KC_G,	KC_C,	KC_R,	KC_F,	KC_Z,	______,
		KC_D,	KC_S,	KC_T,	KC_N,	KC_B,	______,
	______,	KC_W,	KC_M,	KC_L,	KC_P,	KC_V,	______,
			______,	______,	______,	______,	______,
	
	______,	______,
	______,
	______,	______,	______
),


[SYMB] = LAYOUT_ergodox(
/* Keymap 1: Symbol Layer
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │  £   │  €   │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  `   │  <   │  $   │  >   │  !   │      │           │      │  @   │   [  │  _   │  ]   │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  \   │  (   │  "   │  ) • │  #   ├──────┤           ├──────┤  %   │•  {  │  =   │  }   │  |   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │  :   │  *   │  +   │      │      │           │      │      │   &  │  ^   │  ~   │      │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                       │      │      │      │      │      │  
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯  
 *                                        ╭──────┬──────╮       ╭──────┬──────╮
 *                                        │      │      │       │      │      │
 *                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮
 *                                 │      │      │      │       │      │      │      │
 *                                 │      │      ├──────┤       ├──────┤      │      │
 *                                 │      │      │      │       │      │      │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 */
	// left hand
	______,	______,	______,	UC(0x00ac),	UC(0x20ac),	______,	______,
	______,	KC_GRAVE,	KC_LABK,	KC_DLR,	KC_RABK,	KC_EXLM,	______,
	KC_MINUS,	KC_BSLASH,	KC_LPRN,	KC_DQUO,	KC_RPRN,	KC_HASH,
	______,	__x___,	KC_COLN,	KC_KP_ASTERISK,	KC_PLUS,	__x___,	______,
	______,	______,	______,	______,	______,
	
	______,	______,
	______,
	______,	______,	______,
	
	// right hand
	______,	______,	______,	______,	______,	______,	______,
	______,	KC_AT,	KC_LBRACKET,	KC_UNDS,	KC_RBRACKET,	__x___,	______,
		KC_PERC,	KC_LCBR,	KC_EQUAL,	KC_RCBR,	KC_PIPE,	KC_SCOLON,
	______,	__x___,	KC_AMPR,	KC_CIRC,	KC_TILD,	__x___,	______,
	______,	______,	______,	______,	______,
	
	______,	______,
	______,
	______,	______,	______
),

[ARROWS] = LAYOUT_ergodox(
/* Keymap 2: Symbol Layer (right hand)
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │ RESET  │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │           │      │      │ Home │  ▲   │  End │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      ├──────┤           ├──────┤      │•  ◀  │  ▼   │   ▶  │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │           │      │      │ PgUp │      │ PgDn │      │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │~Arows│                                       │ Ctrl │      │      │      │ SLCK │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬──────╮                                   
 *                                        │      │      │       │      │      │
 *                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮
 *                                 │      │      │      │       │      │      │ Shift│
 *                                 │ Shift│      ├──────┤       ├──────┤  Alt │   +  │
 *                                 │      │      │  VER │       │      │      │ Ctrl │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 */
	// left hand
	RESET,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,
	
	______,	______,
	______,
	KC_LSHIFT,	______,	M(VRSN),
	
	// right hand
	______,	______,	______,	______,	______,	______,	MAGIC_TOGGLE_NKRO,
	______,	______,	KC_HOME,	KC_UP,	KC_END,	______,	______,
		______,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_INSERT,	______,
	______,	______,	KC_PGUP,	______,	KC_PGDOWN,	______,	______,
			KC_LCTRL,	______,	______,	______,	______,
	
	______,	______,
	______,
	______,	KC_LALT,	LSFT(KC_LCTRL)
),


[GAME] = LAYOUT_ergodox(
/* Keymap 3:  (games)
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │  Esc   │  1  !│  2  @│  3  #│  4  $│   5 %│      │           │      │   6 ^│   7 &│  8  *│  9  (│  0  )│        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   Q  │   W  │   E  │   R  │   T  │      │           │      │   Y  │   U  │   I  │   O  │   P  │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   A  │   S  │   D  │   F  │   G  ├──────┤           ├──────┤   H  │   J  │   K  │   L  │   ;  │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   Z  │   X  │   C  │   V  │   B  │      │           │      │   N  │   M  │   ,  │   .  │   /  │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │ Space│                                       │      │      │      │      │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬──────╮
 *                                        │      │      │       │      │      │
 *                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮
 *                                 │      │      │      │       │      │      │      │
 *                                 │      │      ├──────┤       ├──────┤      │      │
 *                                 │      │      │      │       │      │      │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 */
	// left hand
	KC_TRANSPARENT,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_TRANSPARENT,
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_U,	KC_TRANSPARENT,
	KC_LSHIFT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_SPACE,
	
	KC_TRANSPARENT,	KC_TRANSPARENT,
	KC_TRANSPARENT,
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,
	
	// right hand
	KC_TRANSPARENT,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_TRANSPARENT,
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_RSHIFT,
			KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,
	
	KC_TRANSPARENT,	KC_TRANSPARENT,
	KC_TRANSPARENT,
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT
),

[FKEYS] = LAYOUT_ergodox(
/* Shortcuts
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  F1  │  F2  │  F3  │  F4  │  F5  │      │           │      │  F6  │  F7  │  F8  │  F9  │  F10 │  F11   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │ Ctrl │ Shift│ Alt •│      ├──────┤           ├──────┤      │• Alt │ Shift│ Ctrl │      │  F12   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                       │      │      │      │      │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬──────╮
 *                                        │      │      │       │      │      │
 *                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮
 *                                 │      │      │      │       │      │      │      │
 *                                 │      │      ├──────┤       ├──────┤      │      │
 *                                 │      │      │      │       │      │      │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 */
	// left hand
	KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
	KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,
	KC_TRANSPARENT,KC_TRANSPARENT,KC_LCTRL,KC_LSHIFT,KC_LALT,KC_TRANSPARENT,
	KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
	KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
	
	KC_TRANSPARENT,KC_TRANSPARENT,
	KC_TRANSPARENT,
	KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
	
	// right hand
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,
	KC_TRANSPARENT,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,
		KC_TRANSPARENT,	KC_RALT,	KC_RSHIFT,	KC_RCTRL,	KC_TRANSPARENT,	KC_F12,
	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,
			KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,	KC_TRANSPARENT,
	
	KC_TRANSPARENT,KC_TRANSPARENT,
	KC_TRANSPARENT,
	KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT
)

};

/* Empty template layer - copy and paste usage
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │     •│      ├──────┤           ├──────┤      │•     │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                       │      │      │      │      │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬──────╮
 *                                        │      │      │       │      │      │
 *                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮
 *                                 │      │      │      │       │      │      │      │
 *                                 │      │      ├──────┤       ├──────┤      │      │
 *                                 │      │      │      │       │      │      │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 
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
		case MACRO_TODO:
			if (record->event.pressed) {
				return MACRO( T(SLASH), T(SLASH), T(SPACE), D(LSHIFT), T(T), T(O), T(D), T(O), T(SCOLON), U(LSHIFT), T(SPACE), END );
			} 
			break;
		case MACRO_ISEQUALS:
			if (record->event.pressed) {
				return MACRO( D(LSFT), T(SCOLON), U(LSHIFT), T(EQL), T(SPC), END );
			} 
			break;
		case MACRO_PARENTHESE:
			if (record->event.pressed) {
				return MACRO(  D(LSHIFT),T(9), T(0),U(LSHIFT), T(LEFT), END);
			} 
			break;
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
				SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
			}
			break;
		case POUND:  // POUND = UC(0x00A3)
			if (record->event.pressed) {
				//return MACRO( I(15), D(RALT), T(L), T(MINUS), U(RALT), END );
				return MACRO( D(LCTRL), D(LSHIFT), T(U), U(LSHIFT), U(LCTRL), T(0), T(0), T(A), T(3), T(ENTER), END);
			}
			break;
		case EURO:  // EURO = UC(0x20AC)
			if (record->event.pressed) {
				return MACRO( D(LCTRL), D(LSHIFT), T(U), U(LSHIFT), U(LCTRL), T(2), T(0), T(A), T(C), T(ENTER), END);
			}
			break;
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
	
	set_unicode_input_mode(UC_BSD);
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
