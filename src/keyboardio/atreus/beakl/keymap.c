/* jedit settings  :elasticTabstops=true:encoding=UTF-8: */

// Copyright (C) 2021 Graeme Geldenhuys
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _L1,
    _L2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT( /* BEAKL-15 */
	KC_Q,	KC_H,	KC_O,	KC_U,	KC_X,			KC_G,	KC_C,	KC_R,	KC_F,	KC_Z,
	CMD_T(KC_Y),	SFT_T(KC_I),	CTL_T(KC_E),	ALT_T(KC_A),	KC_DOT,			KC_D,	ALT_T(KC_S)	CTL_T(KC_T),	SFT_T(KC_N),	CMD_T(KC_B),
	KC_J,	KC_SLSH,	KC_COMM,	KC_K,	KC_QUOT,	KC_GRV,	KC_BSLS,	KC_W,	KC_M,	KC_L,	KC_P,	KC_V,
	KC_ESC,	KC_TAB,	KC_LGUI,	KC_LSFT,	KC_SPC,	KC_LCTL,	KC_LALT,	KC_BSPC,	MO(_L1),	KC_MINS,	KC_SCLN,	KC_ENT ),

	/*
	*  !       @     up     {    }        ||     pgup    7     8     9    *
	*  #     left   down  right  $        ||     pgdn    4     5     6    +
	*  [       ]      (     )    &        ||       `     1     2     3    \
	* lower  insert super shift bksp ctrl || alt space   fn    .     0    =
	*/
	[_L1] = LAYOUT(
	KC_EXLM,	KC_AT,	KC_LCBR,	KC_RCBR,	KC_PLUS,			KC_BSLASH,	KC_7,	KC_8,	KC_9,	KC_0,
	KC_PERC,	KC_DLR,	KC_LPRN,	KC_RPRN,	KC_EQL,			KC_HASH,	KC_4,	KC_5,	KC_6,	KC_DOT,
	KC_AMPR,	KC_CIRC,	KC_LBRC,	KC_RBRC,	KC_TILD,	KC_CIRC,	KC_AMPR,	KC_GRV,	KC_1,	KC_2,	KC_3,	KC_ASTR,
	TG(_L2),	KC_INS,	KC_LGUI,	KC_LSFT,	KC_BSPC,	KC_LCTL,	KC_LALT,	KC_SPC,	KC_TRNS,	KC_DOT,	KC_0,	KC_EQL ),

	/*
	* insert home   up  end   pgup       ||      up     F7    F8    F9   F10
	*  del   left  down right pgdn       ||     down    F4    F5    F6   F11
	*       volup             reset      ||             F1    F2    F3   F12
	*  L0   voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
	*/
	[_L2] = LAYOUT(
	KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
	KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
	RESET,   KC_VOLU, KC_NO,   KC_NO,   RESET,   _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
	TO(_BASE),KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC, TO(_BASE),KC_PSCR,KC_SLCK, KC_PAUS )
};
