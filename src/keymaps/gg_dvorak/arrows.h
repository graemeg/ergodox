[AROWS] = LAYOUT_ergodox(
/* Navigation Layer

 ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 │ RESET  │      │      │      │      │      │      │           │      │      │      │      │      │      │  SLOCK │
 ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 │ NKRO   │      │      │      │      │      │      │           │      │      │ Home │  ▲   │  End │      │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │        │ CMD  │ Shift│ Ctrl │ Alt •│      ├──────┤           ├──────┤      │• ◀   │  ▼   │  ▶   │  Ins │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │        │      │      │      │      │      │      │           │      │      │ PgUp │      │ PgDn │      │        │
 ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
   │      │      │      │      │ //// │                                       │      │      │      │      │      │
   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
                                        ╭──────┬──────╮       ╭──────┬──────╮
                                        │      │      │       │      │      │
                                 ╭──────┼──────┼──────┤       ├──────┼──────┼──────╮        ESC = Reset
                                 │      │      │      │       │      │      │      │       PScr = Version
                                 │      │      ├──────┤       ├──────┤      │ Del  │
                                 │      │      │  VER │       │      │      │      │
                                 ╰──────┴──────┴──────╯       ╰──────┴──────┴──────╯
 */ 
	// left hand
	RESET,	______,	______,	______,	______,	______,	______,
	MAGIC_TOGGLE_NKRO,	______,	______,	______,	______,	______,	______,
	______,	KC_LGUI,	KC_LSFT,	KC_LCTRL,	KC_LALT,	______,
	______,	______,	______,	______,	______,	______,	______,
	______,	______,	______,	______,	______,
	______,	______,
	______,
	______,	______,	M(VRSN),

	// right hand
	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,	KC_SLCK,
	______,	__x___,	KC_HOME,	KC_UP,	KC_END,	__x___,	__x___,
		__x___,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_INS,	__x___,
	______,	__x___,	KC_PGUP,	__x___,	KC_PGDN,	__x___,	__x___,
			______,	______,	______,	______,	__x___,
	______,	______,
	______,
	______,	______,	KC_DEL
),