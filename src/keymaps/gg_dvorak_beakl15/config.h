#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

//#define FORCE_NKRO
//#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD			/* https://github.com/qmk/qmk_firmware/pull/1359/  */
#define IGNORE_MOD_TAP_INTERRUPT	/* https://github.com/qmk/qmk_firmware/issues/142  */


#undef TAPPING_TERM
#define TAPPING_TERM    200
//#undef IGNORE_MOD_TAP_INTERRUPT

#undef DEBOUNCE
#define DEBOUNCE    15  /* this was the previous default and seem to work better for me. */
 
#define PREVENT_STUCK_MODIFIERS

#endif
