#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

#undef TAPPING_TERM
#define TAPPING_TERM 190

#undef DEBOUNCE
#define DEBOUNCE 7

#define PERMISSIVE_HOLD			/* https://github.com/qmk/qmk_firmware/pull/1359/  */
#define IGNORE_MOD_TAP_INTERRUPT	/* https://github.com/qmk/qmk_firmware/issues/142  */
#define PREVENT_STUCK_MODIFIERS


#endif