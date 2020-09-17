/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
//#define ORYX_CONFIGURATOR

#define PERMISSIVE_HOLD			/* https://github.com/qmk/qmk_firmware/pull/1359/  */
#define IGNORE_MOD_TAP_INTERRUPT	/* https://github.com/qmk/qmk_firmware/issues/142  */
#define PREVENT_STUCK_MODIFIERS
//#define FORCE_NKRO	// Apparently the rules.mk setting doesn't always take effect


#undef TAPPING_TERM
#define TAPPING_TERM 200

#undef  TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

#undef DEBOUNCE
#define DEBOUNCE 10  /* This was the previous default and seems to work better for me. */

#undef MANUFACTURER
#define MANUFACTURER    Built by Graeme Geldenhuys

#define BEAKL15
//#define BEAKL19
//#define DVORAK
//#define QWERTY

// Old or New symbol layout?
#define OLDSYMBL
//#define NEWSYMBL
