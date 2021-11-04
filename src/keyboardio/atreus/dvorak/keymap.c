/* jedit settings  :elasticTabstops=true:encoding=UTF-8: */

// Copyright (C) 2021 Graeme Geldenhuys
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _BEAKL15,
    _SYM,
    _SYM2,
    _NAV,
    _FKEY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/*
	   '     ,     .     p    y        ||      f     g     c     r    l
	   a     o     e     u    i        ||      d     h     t     n    s
	   ;     q     j     k    x     `  ||  \   b     m     w     v    z
	  esc   tab  super  nav  spc  fkey || del bspc  lay    -     /   enter
	*/
	[_BASE] = LAYOUT( /* Dvorak */
	KC_QUOT,	KC_COMM,	KC_DOT,	KC_P,	KC_Y,			KC_F,	KC_G,	KC_C,	KC_R,	KC_L,
	LCMD_T(KC_A),	LSFT_T(KC_O),	LCTL_T(KC_E),	LALT_T(KC_U),	KC_I,			KC_D,	RALT_T(KC_H),	RCTL_T(KC_T),	RSFT_T(KC_N),	RCMD_T(KC_S),
	KC_SCLN,	KC_Q,	KC_J,	KC_K,	KC_X,	KC_GRV,	KC_BSLS,	KC_B,	KC_M,	KC_W,	KC_V,	KC_Z,
	KC_ESC,	KC_TAB,	KC_LGUI,	MO(_NAV),	KC_SPC,	MO(_FKEY),	KC_DEL,	LT(_SYM, KC_BSPC),	TG(_BEAKL15),	KC_MINS,	KC_SLSH,	KC_ENT ),

	/*
	   q     h     o     u    x        ||      g     c     r     f    z
	   y     i     e     a    .        ||      d     s     t     n    b
	   j     /     ,     k    '     `  ||  \   w     m     l     p    v
	  esc   tab  super  nav  spc  fkey || del bspc  lay    -     ;   enter
	*/
	[_BEAKL15] = LAYOUT( /* BEAKL-15 */
	KC_Q,	KC_H,	KC_O,	KC_U,	KC_X,			KC_G,	KC_C,	KC_R,	KC_F,	KC_Z,
	CMD_T(KC_Y),	SFT_T(KC_I),	CTL_T(KC_E),	ALT_T(KC_A),	KC_DOT,			KC_D,	ALT_T(KC_S),	CTL_T(KC_T),	SFT_T(KC_N),	CMD_T(KC_B),
	KC_J,	KC_SLSH,	KC_COMM,	KC_K,	KC_QUOT,	_______,	_______,	KC_W,	KC_M,	KC_L,	KC_P,	KC_V,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_SCLN,	_______ ),


	/*
	   !     @     {     }    +        ||      *     7     8     9    0
	   %     $     (     )    =        ||      #     4     5     6    .
	   &     ^     [     ]    ~        ||      `     1     2     3    /
	                                   ||          reset
	*/
	[_SYM] = LAYOUT(
	KC_EXLM,	KC_AT,	KC_LCBR,	KC_RCBR,	KC_PLUS,			KC_ASTR,	KC_7,	KC_8,	KC_9,	KC_0,
	KC_PERC,	KC_DLR,	KC_LPRN,	KC_RPRN,	KC_EQL,			KC_HASH,	KC_4,	KC_5,	KC_6,	KC_DOT,
	KC_AMPR,	KC_CIRC,	KC_LBRC,	KC_RBRC,	KC_TILD,	_______,	_______,	KC_GRV,	KC_1,	KC_2,	KC_3,	KC_SLASH,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	RESET,	_______,	_______,	_______ ),


	/*
	   !     @     {     }    +        ||      *     7     8     9    0
	   %     $     (     )    =        ||      #     4     5     6    .
	   &     ^     [     ]    ~        ||      `     1     2     3    /
	                                   ||          reset
	*/
	[_SYM2] = LAYOUT(
	KC_EXLM,	KC_AT,	KC_LCBR,	KC_RCBR,	KC_PLUS,			KC_ASTR,	KC_7,	KC_8,	KC_9,	KC_0,
	KC_PERC,	KC_DLR,	KC_LPRN,	KC_RPRN,	KC_EQL,			KC_HASH,	KC_4,	KC_5,	KC_6,	KC_DOT,
	KC_AMPR,	KC_CIRC,	KC_LBRC,	KC_RBRC,	KC_TILD,	_______,	_______,	KC_GRV,	KC_1,	KC_2,	KC_3,	KC_SLASH,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	RESET,	_______,	_______,	_______ ),


	/*
	  ins   slck   caps                ||            del   home    up    end
	  cmd   shift  ctrl  alt           ||                  left   down   right
	               vol+  vol-     paus || pscr             pgup          pgdn
	                                   ||          
	*/
	[_NAV] = LAYOUT(
	KC_INS,	KC_SLCK,	KC_CAPS,	KC_NO,	KC_NO,			KC_DEL,	KC_HOME,	KC_UP,	KC_END,	KC_NO,
	KC_LGUI,	KC_LSFT,	KC_LCTL,	KC_LALT,	KC_NO,			LALT_T(KC_LEFT),	KC_LEFT,	KC_DOWN,	KC_RGHT,	LALT_T(KC_RIGHT),
	KC_NO,	KC_NO,	KC_VOLU,	KC_VOLD,	KC_NO,	KC_PAUS,	KC_PSCR,	KC_NO,	KC_PGUP,	KC_NO,	KC_PGDN,	KC_NO,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_NO,	KC_NO,	KC_NO,	KC_NO ),

	/*
	                                   ||            F7    F8    F9    F10
	  cmd   shift  ctrl  alt           ||            F4    F5    F6    F11
	                                   ||            F1    F2    F3    F12
	                                   ||          
	*/
	[_FKEY] = LAYOUT(
	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,			KC_NO,	KC_F7,	KC_F8,	KC_F9,	KC_F10,
	KC_LGUI,	KC_LSFT,	KC_LCTL,	KC_LALT,	KC_NO,			KC_NO,	KC_F4,	KC_F5,	KC_F6,	KC_F11,
	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	_______,	_______,	KC_NO,	KC_F1,	KC_F2,	KC_F3,	KC_F12,
	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	_______,	_______,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO )
	
};
