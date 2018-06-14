#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD			/* https://github.com/qmk/qmk_firmware/pull/1359/  */
#define IGNORE_MOD_TAP_INTERRUPT	/* https://github.com/qmk/qmk_firmware/issues/142  */

#undef MANUFACTURER
#define MANUFACTURER    Built by Graeme Geldenhuys

//  Restore mouse navigation settings back to QMK defaults instead of Ergodox EZ defaults.
//  QMK settings are intentionally a bit slower and more manageable
#undef  MOUSEKEY_DELAY
#define MOUSEKEY_DELAY             300
#undef  MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL          50
#undef  MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED         10
#undef  MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX       20
#undef  MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#undef  MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#endif
