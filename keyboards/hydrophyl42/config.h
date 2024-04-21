#pragma once

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


#define TAPPING_TOGGLE 2
#define COMBO_VARIABLE_LEN


#ifdef MOUSEKEY_ENABLE
    #define MOUSEKEY_MAX_SPEED 2
    #define MOUSEKEY_WHEEL_DELAY 0
    #define MOUSEKEY_TIME_TO_MAX 40
#endif