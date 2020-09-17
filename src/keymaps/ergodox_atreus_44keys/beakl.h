/* jedit settings  :elasticTabstops=true:encoding=UTF-8:wrap=none: */

/* BEAKL15
 ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 │        │  Q   │  H   │  O   │  U   │   X  │      │           │      │  G   │  C   │  R   │  F   │  Z   │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │        │  Y   │  I   │  E   │  A  •│   . >├──────┤           ├──────┤  D   │• S   │  T   │  N   │  B   │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │        │  J   │  /  ?│  ,  <│  K   │   ' "│      │           │ Enter│  W   │  M   │  L   │  P   │  V   │        │
 ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
   │      │      │  -  _│  Esc │~Arrow│     «« Ergodox & Atreus 44 keys »»    │~FKeys│ Del  │  ;  :│ PScr │      │
   ╰──────┴──────┴──────┴──────┴──────╯                 v 4.0                 ╰──────┴──────┴──────┴──────┴──────╯
                                        ╭──────┬──────╮       ╭──────┬──────╮
                                        │ GAME │      │       │      │      │
                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮      Hyper = Meh+Gui
                                 │      │      │      │       │      │      │      │        Meh = Control+Alt+Shift
                                 │ Space│ Tab  ├──────┤       ├──────┤ BkSp │~SYMB │        GUI = Super, Win or Cmd key
                                 │      │      │      │       │      │      │      │        App = Menu key
                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯        OSL = One-Shot Layer
*/
[_BASE] = LAYOUT_ergodox(
  // left hand
	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,
	__x___,	KC_Q,	KC_H,	KC_O,	KC_U,	KC_X,	__x___,
	__x___,	LGUI_T(KC_Y),	LSFT_T(KC_I),	LCTL_T(KC_E),	LALT_T(KC_A),	KC_DOT,	
	__x___,	KC_J,	KC_SLASH,	KC_COMM,	KC_K,	KC_QUOTE,	__x___,
	__x___,	__x___,	KC_MINUS,	KC_ESC,	MO(_NAV),

	TG(_GAMES),	__x___,
	 	__x___,
	KC_SPC,	KC_TAB,	__x___,

  // right hand
	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,
	__x___,	KC_G,	KC_C,	KC_R,	KC_F,	KC_Z,	__x___,
	 	KC_D,	RALT_T(KC_S),	RCTL_T(KC_T),	RSFT_T(KC_N),	RGUI_T(KC_B),	__x___,
	KC_ENTER,	KC_W,	KC_M,	KC_L,	KC_P,	KC_V,	__x___,
	 	 	MO(_FKEYS),	KC_DELETE,	KC_SCOLON,	KC_PSCREEN,	__x___,

	__x___,    __x___,
	__x___,
	__x___,    KC_BSPC,    MO(_SYMBOLS)
),
