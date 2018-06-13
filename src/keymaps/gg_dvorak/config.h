#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

//#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD			/* https://github.com/qmk/qmk_firmware/pull/1359/  */
#define IGNORE_MOD_TAP_INTERRUPT	/* https://github.com/qmk/qmk_firmware/issues/142  */


//#undef TAPPING_TERM
//#undef IGNORE_MOD_TAP_INTERRUPT

#undef MANUFACTURER
#define MANUFACTURER    Built by Graeme Geldenhuys

#endif
