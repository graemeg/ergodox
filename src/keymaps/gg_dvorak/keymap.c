/* jedit settings  :elasticTabstops=true:encoding=UTF-8: */

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "timer.h"

/*
  Author: Graeme Geldenhuys <graeme@geldenhuys.co.uk>

  Based on the default Dvorak keymap, and applied some
  tweaks from the TypeMatrix 2030 design. Some key locations are also
  designed to work well with my programming environment (FPC/Lazarus/Delphi).
  
  Compile with:
    ./build.sh
       or
    gmake ergodox_ez:gg_dvorak:teensy
*/

#define GG_VERSION "1.24"

#define CUT      LCTL(KC_X)	// C-x Cut
#define COPY     LCTL(KC_C)	// C-c Copy
#define PASTE    LCTL(KC_V)	// C-v Paste
#define COMPI    LCTL(KC_F9)	// Ctrl+F9 used for compiling while developing with Object Pascal IDEs.
#define ______   KC_TRNS	// Make changes in layers more visible
#define __x___   KC_NO	// Make changes in layers more visible

/* Layers */
enum {
	BASE = 0,	// default layer
	BEAKL,	// BEAKL-9 layout
	SYMB,	// symbols + NumPad
	AROWS,	// arrows, PgUp, PgDn, Home, End
	QWER,	// QWERTY
	SYMB2	// new symbol layer based on Dan's Workman layout
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
	   https://docs.qmk.fm/features/advanced-keycodes#switching-and-toggling-layers

	I also have Space-Cadet Shift keys enabled and disabled command mode via the Makefile.
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
/* Keymap 0: Basic layer                                                  Version: 1.xx
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │  Esc   │  F1  │  F2  │  F3  │  F4  │  F5  │  F11 │           │  F12 │  F6  │  F7  │  F8  │  F9  │  F10 │   \   |│
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │  Tab   │  '  "│  ,  <│  .  >│  P   │   Y  │ Hyper│           │ BkSp │   F  │   G  │  C   │  R   │  L   │   /   ?│
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ Shift  │  A   │  O   │  E   │  U • │   I  ├──────┤           ├──────┤   D  │ • H  │  T   │  N   │  S   │   ─   _│
 * ├────────┼──────┼──────┼──────┼──────┼──────┤  :=  │           │ Enter├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ Shift  │  ;  :│  Q   │  J   │  K   │   X  │      │           │      │   B  │   M  │  W   │  V   │  Z   │  Shift │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │LCtrl │ LAlt │ C+F9 │CP/CUT│ PASTE│                                       │  ◀   │   ▲  │   ▼  │  ▶   │ RCtrl│
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬──────╮
 *                                        │ INS  │ CAPS │       │ GUI  │ QWER │
 *                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮      Hyper = Meh+Gui
 *                                 │ Space│ Enter│ App  │       │ Beakl│ Enter│ Space│        Meh = Control+Alt+Shift
 *                                 │  /   │  /   ├──────┤       ├──────┤   /  │   /  │        GUI = Super or Win key
 *                                 │ Ctrl │ Alt  │ PScr │       │ Del  │ ~Sym2│ ~Sym1│        App = Menu key
 *                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 */
	// left hand
	KC_ESC,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F11,
	KC_TAB,	KC_QUOT,	KC_COMM,	KC_DOT,	KC_P,	KC_Y,	ALL_T(KC_NO),
	KC_LSFT,	KC_A,	KC_O,	KC_E,	LT(AROWS,KC_U),	KC_I,
	KC_LSFT,	KC_SCLN,	KC_Q,	KC_J,	KC_K,	KC_X,	M(MACRO_ISEQUALS),
	KC_LCTRL,	KC_LALT,	M(COMPI),	M(A_COPYCUT),	PASTE,

	KC_INS,	KC_CAPS,
	KC_APP,	
	CTL_T(KC_SPC),	ALT_T(KC_ENT),	KC_PSCR,

	// right hand
	KC_F12,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_BSLS,
	KC_BSPC,	KC_F,	KC_G,	KC_C,	KC_R,	KC_L,	KC_SLSH,
		KC_D,	KC_H,	KC_T,	KC_N,	KC_S,	KC_MINS,
	KC_ENT,	KC_B,	KC_M,	KC_W,	KC_V,	KC_Z,	KC_RSFT,
			LT(SYMB2,KC_LEFT),	KC_UP,	KC_DOWN,	KC_RIGHT,	KC_RCTRL,

	KC_LGUI,	TG(QWER),
	TG(BEAKL),
	KC_DELT,	LT(SYMB2,KC_ENT),	LT(SYMB,KC_SPC)
),
[BEAKL] = KEYMAP(
/* BEAKL-9 [http://www.shenafu.com/code/keyboard/beakl/index.php]
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   J  │  H   │  O   │   U  │   K  │      │           │      │  G   │  C   │  R   │  F   │  Z   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │   -    │   Q  │  I   │  E   │   A •│   Y  ├──────┤           ├──────┤  D   │• S   │  T   │  N   │  B   │   ;    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   /  │  ,   │  '   │   .  │   X  │      │           │      │  W   │  M   │  L   │  P   │  V   │        │
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
	______,	______,	______,	______,	______,	______,	______,
	______,	KC_J,	KC_H,	KC_O,	KC_U,	KC_K,	______,
	KC_MINUS,	KC_Q,	KC_I,	KC_E,	LT(AROWS,KC_A),	KC_Y,
	______,	KC_SLASH,	KC_COMM,	KC_QUOTE,	KC_DOT,	KC_X,	______,
	______,	______,	______,	______,	______,
	______,	______,
	______,
	______,	______,	______,

	// right hand
	______,	______,	______,	______,	______,	______,	______,
	______,	KC_G,	KC_C,	KC_R,	KC_F,	KC_Z,	______,
		KC_D,	KC_S,	KC_T,	KC_N,	KC_B,	KC_SCLN,
	______,	KC_W,	KC_M,	KC_L,	KC_P,	KC_V,	______,
			______,	______,	______,	______,	______,
	______,	__x___,
	______,
	______,	______,	______

),
[SYMB] = LAYOUT_ergodox(
/* Keymap 1: Symbol Layer with NumPad
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │  £   │  €   │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  !   │  @   │  {   │  }   │  +   │ TODO │           │      │      │   7  │  8   │  9   │  0   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  %   │  $   │  (   │  ) • │  =   ├──────┤           ├──────┤  #   │•  4  │  5   │  6   │  .   │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤  ( ) │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  &   │  ^   │  [   │  ]   │  ~   │      │           │      │  `   │   1  │  2   │  3   │  *   │        │
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
	______,	______,	______,	M(POUND),	M(EURO),	______,	______,
	______,	KC_EXLM,	KC_AT,	KC_LCBR,	KC_RCBR,	KC_PLUS,	M(MACRO_TODO),
	______,	KC_PERC,	KC_DLR,	KC_LPRN,	KC_RPRN,	KC_EQL,
	______,	KC_AMPR,	KC_CIRC,	KC_LBRC,	KC_RBRC,	KC_TILD,	M(MACRO_PARENTHESE),
	______,	______,	______,	______,	______,
	______,	______,
	______,		
	______,	______,	______,

	// right hand
	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,
	______,	__x___,	KC_7,	KC_8,	KC_9,	KC_0,	__x___,
		KC_HASH,	KC_4,	KC_5,	KC_6,	KC_DOT,	__x___,
	______,	KC_GRV,	KC_1,	KC_2,	KC_3,	KC_ASTR,	__x___,
			__x___,	__x___,	__x___,	__x___,	__x___,
	______,	______,
	______,		
	______,	______,	______
),
[AROWS] = LAYOUT_ergodox(
/* Keymap 2: Symbol Layer (right hand)
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │ RESET  │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │           │      │      │ Home │  ▲   │  End │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │ Shift│ Ctrl │ Alt  │     •│      ├──────┤           ├──────┤ PgUp │•  ◀  │  ▼   │   ▶  │  Ins │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │           │      │ PgDn │      │      │      │      │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                       │      │      │      │      │ SLCK │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬──────╮                                   
 *                                        │      │      │       │      │      │             *** left hand ***     
 *                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮        ESC = Reset         
 *                                 │      │      │      │       │      │Shift+│      │       PScr = Version       
 *                                 │      │      ├──────┤       ├──────┤ Ctrl │ Ctrl │                            
 *                                 │      │      │  VER │       │      │      │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 */
	// left hand
	RESET,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,	______,	______,
	______,	KC_LSFT,	KC_LCTRL,	KC_LALT,	______,	______,
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,
	______,	______,
	______,
	______,	______,	M(VRSN),

	// right hand
	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,
	______,	__x___,	KC_HOME,	KC_UP,	KC_END,	__x___,	__x___,
		KC_PGUP,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_INS,	__x___,
	______,	KC_PGDN,	__x___,	__x___,	__x___,	__x___,	__x___,
			__x___,	__x___,	__x___,	__x___,	KC_SLCK,
	______,	______,
	______,
	______,	LCTL(KC_LSHIFT),	KC_LCTRL
),

[QWER] = LAYOUT_ergodox(
/* Keymap 3: QWERTY layer (games)
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
	KC_ESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	__x___,
	______,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	______,
	______,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	
	______,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	______,
	______,	______,	______,	______,	KC_SPC,

	______,	______,
	______,
	______,	______,	______,

	// right hand
	__x___,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	______,
	______,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	______,
		KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	______,	
	______,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	______,
			______,	______,	______,	______,	______,

	______,	______,
	______,
	______,	______,	______
),
[SYMB2] = KEYMAP(
/* Symbols 2 - based on Workman layout
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  F1  │  F2  │  F3  │  F4  │  F5  │      │           │      │  F6  │  F7  │  F8  │  F9  │ F10  │  F11   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  1  !│  2  @│  3  #│  4 $•│  5  %├──────┤           ├──────┤  6  ^│• 7  &│  8  *│  9  (│  0  )│  F12   │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │  `  ~│  =  +│  -  _│  [  {│  ]  }│      │           │      │  '  "│  ;  :│  ,  <│  .  >│  /  ?│   \  | │
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
	______,	______,	______,	______,	______,	______,	______,
	______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	______,
	______,	SFT_T(KC_1),	CTL_T(KC_2),	ALT_T(KC_3),	KC_4,	KC_5,
	______,	KC_GRV,	KC_EQL,	KC_MINUS,	KC_LBRC,	KC_RBRC,	KC_TILD,
	______,	______,	______,	______,	______,
	______,	______,
	______,
	______,	______,	______,

	// right hand
	______,	______,	______,	______,	______,	______,	______,
	______,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,
		KC_6,	KC_7,	ALT_T(KC_8),	CTL_T(KC_9),	SFT_T(KC_0),	KC_F12,
	______,	KC_QUOTE,	KC_SCLN,	KC_COMM,	KC_DOT,	KC_SLASH,	KC_BSLASH,
			______,	______,	______,	______,	______,
	______,	______,
	______,
	______,	______,	______

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
				SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " (" GG_VERSION ")");
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
