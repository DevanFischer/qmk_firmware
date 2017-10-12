/*
Copyright 2017 Jeremy Cowgar <jeremy@cowgar.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6660
#define DEVICE_VER      0x0002
#define MANUFACTURER    JC
#define PRODUCT         JC33
#define DESCRIPTION     33% Keyboard

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 11

//#define MATRIX_ROW_PINS { B0, B1, B2 }
//#define MATRIX_COL_PINS { D6, D7, B4, B5, B6, F7, F6, F5, F4, F1, F0 }

#define MATRIX_ROW_PINS { B2, B1, B0 }
#define MATRIX_COL_PINS { B7, D1, D2, D3, C6, C7, D7, B4, B5, B6, F7 }

#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
#define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN D5     // The pin the LED strip is connected to
#define RGBLED_NUM 14     // Number of LEDs in your strip
#define RGBLIGHT_ANIMATIONS

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
