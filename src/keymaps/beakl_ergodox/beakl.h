// ............................................................................. BEAKL15
#ifdef BEAKL15
[_BASE] = LAYOUT_ergodox_pretty(
//  KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_F11,                                         KC_F12,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
  KC_ESCAPE,      KC_4,           KC_0,           KC_1,           KC_2,           KC_3,           KC_F11,                                         KC_F12,         KC_7,           KC_6,           KC_5,           KC_9,           KC_8,           KC_TRANSPARENT,
  KC_TAB,         KC_Q,           KC_H,           KC_O,           KC_U,           KC_X,           KC_CAPSLOCK,                                    KC_BSPACE,      KC_G,           KC_C,           KC_R,           KC_F,           KC_Z,           KC_TRANSPARENT,
  KC_MINUS,       KC_Y,           KC_I,           KC_E,           KC_A,           KC_DOT,                                                                         KC_D,           KC_S,           KC_T,           KC_N,           KC_B,           KC_SCOLON,
  MO(_SHIFT),     KC_J,           KC_SLASH,       KC_COMMA,       KC_K,           KC_QUOTE,       KC_DELETE,                                      KC_ENTER,       KC_W,           KC_M,           KC_L,           KC_P,           KC_V,           MO(_SHIFT),
  KC_LCTRL,       KC_LGUI,        KC_LALT,        LSFT(KC_LCTRL), MO(_NAV),                                                                                                       MO(_MOUSE),     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_RCTRL,
                                                                                                  TG(_GAME),      KC_PSCREEN,       TG(_MACOS),          TG(_QWERTY),
                                                                                                                  TG(1),            KC_PGUP,
                                                                                  LCTL_T(KC_SPACE),LALT_T(KC_ENTER),KC_CAPSLOCK,    KC_PGDOWN,      KC_TAB,         MO(_SYMBOLS)
),
[_SHIFT] = LAYOUT_ergodox_pretty(
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, LSFT(KC_Q),     LSFT(KC_H),     LSFT(KC_O),     LSFT(KC_U),     LSFT(KC_X),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_G),     LSFT(KC_C),     LSFT(KC_R),     LSFT(KC_F),     LSFT(KC_Z),     KC_TRANSPARENT,
  KC_MINUS,       LSFT(KC_Y),     LSFT(KC_I),     LSFT(KC_E),     LSFT(KC_A),     KC_AT,                                                                          LSFT(KC_D),     LSFT(KC_S),     LSFT(KC_T),     LSFT(KC_N),     LSFT(KC_B),     KC_SCOLON,
  KC_TRANSPARENT, LSFT(KC_J),     KC_QUES,        KC_EXLM,        LSFT(KC_K),     KC_GRAVE,       KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_W),     LSFT(KC_M),     LSFT(KC_L),     LSFT(KC_P),     LSFT(KC_V),     KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),
#endif

// ............................................................................. BEAKL19
#ifdef BEAKL19
[_BASE] = LAYOUT_ergodox_pretty(
//  KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,       KC_F11,                                         KC_F12,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
  KC_ESCAPE,      KC_3,           KC_2,           KC_1,           KC_0,           KC_4,       KC_F11,                                         KC_F12,         KC_7,           KC_6,           KC_5,           KC_9,           KC_8,           KC_TRANSPARENT,
  KC_TAB,         KC_Q,           KC_DOT,         KC_O,           KC_U,           KC_J,       KC_CAPSLOCK,                                    KC_BSPACE,      KC_W,           KC_D,           KC_N,           KC_M,           KC_COMMA,       KC_TRANSPARENT,
  KC_MINUS,       KC_H,           KC_A,           KC_E,           KC_I,           KC_K,                                                                       KC_G,           KC_S,           KC_R,           KC_T,           KC_P,           KC_SCOLON,
  MO(_SHIFT),     KC_Z,           KC_QUOTE,       KC_SLASH,       KC_Y,           KC_X,       KC_DELETE,                                      KC_ENTER,       KC_B,           KC_C,           KC_L,           KC_F,           KC_V,           MO(_SHIFT),
  KC_LCTRL,       KC_LGUI,        KC_LALT,        LSFT(KC_LCTRL), MO(_NAV),                                                                                                    MO(_MOUSE),    KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    KC_RCTRL,
                                                                                                  TG(_GAME),      KC_PSCREEN,       TG(_MACOS),          TG(_QWERTY),
                                                                                                                  TG(1),            KC_PGUP,
                                                                                  LCTL_T(KC_SPACE),LALT_T(KC_ENTER),KC_CAPSLOCK,    KC_PGDOWN,      KC_TAB,         MO(_SYMBOLS)
),
[_SHIFT] = LAYOUT_ergodox_pretty(
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
  KC_TRANSPARENT, LSFT(KC_Q),     LSFT(KC_AT),    LSFT(KC_O),     LSFT(KC_U),     LSFT(KC_J),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_W),     LSFT(KC_D),     LSFT(KC_N),     LSFT(KC_M),     LSFT(KC_EXLM),  KC_TRANSPARENT,
  KC_MINUS,       LSFT(KC_H),     LSFT(KC_A),     LSFT(KC_E),     LSFT(KC_I),     LSFT(KC_K),                                                                     LSFT(KC_G),     LSFT(KC_S),     LSFT(KC_R),     LSFT(KC_T),     LSFT(KC_P),     KC_SCOLON,
  KC_TRANSPARENT, LSFT(KC_Z),     KC_GRAVE,       KC_QUES,        LSFT(KC_Y),     LSFT(KC_X),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_B),     LSFT(KC_C),     LSFT(KC_L),     LSFT(KC_F),     LSFT(KC_V),     KC_TRANSPARENT,
  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),
#endif
