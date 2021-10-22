[MOUSE] = LAYOUT_ergodox(
/* Mouse Navigation and Media buttons

 ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 │ Vol Up │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 │ Vol Dn │      │      │ MS ▲ │      │      │      │           │      │      │  ▲▲  │  ▼▼  │      │      │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │  Mute  │      │ MS ◀ │ MS ▼ │ MS ▶•│      ├──────┤           ├──────┤      │• B1  │  B2  │  B3  │  B4  │        │
 ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 │        │      │      │      │      │      │      │           │      │      │  <<  │  >>  │      │      │        │
 ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
   │      │      │      │      │ Acc0 │                                       │ //// │      │      │      │      │
   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
                                        ╭──────┬──────╮       ╭──────┬────────╮
                                        │      │      │       │      │        │
                                 ╭──────┼──────┼──────┤       ├──────┼────────┼──────╮
                                 │      │      │      │       │      │        │      │
                                 │ Acc1 │ Acc0 ├──────┤       ├──────┤        │      │
                                 │      │      │      │       │      │        │      │
                                 ╰──────┴──────┴──────╯       ╰──────┴────────┴──────╯
 */
	// left hand
	KC_AUDIO_VOL_UP,	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,
	KC_AUDIO_VOL_DOWN,	__x___,	__x___,	KC_MS_UP,	__x___,	__x___,	__x___,
	KC_AUDIO_MUTE,	__x___,	KC_MS_LEFT,	KC_MS_DOWN,	KC_MS_RIGHT,	__x___,
	______,	__x___,	__x___,	__x___,	__x___,	__x___,	______,
	______,	______,	__x___,	__x___,	KC_MS_ACCEL0,
	______,	______,
	______,
	KC_MS_ACCEL1,	KC_MS_ACCEL0,	______,

	// right hand
	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,	__x___,
	__x___,	__x___,	KC_MS_WH_UP,	KC_MS_WH_DOWN,	__x___,	__x___,	__x___,
		__x___,	KC_MS_BTN1,	KC_MS_BTN2,	KC_MS_BTN3,	KC_MS_BTN4,	__x___,
	__x___,	__x___,	KC_MS_WH_LEFT,	KC_MS_WH_RIGHT,	__x___,	__x___,	__x___,
			______,	______,	______,	______,	__x___,
	______,	______,
	______,
	______,	______,	______
),
