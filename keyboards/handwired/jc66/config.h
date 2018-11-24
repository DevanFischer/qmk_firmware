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
#define VENDOR_ID       0xABCD
#define PRODUCT_ID      0x0059
#define DEVICE_VER      0x0001
#define MANUFACTURER    JC
#define PRODUCT         JC66
#define DESCRIPTION     66% Keyboard

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

#define MATRIX_ROW_PINS { D2, D1, D0, B7, B3, B5, B6, F7, F6, F5 }
#define MATRIX_COL_PINS { D4, D6, D7, D5, C7, C6, D3 }

#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN B4     // The pin the LED strip is connected to
#define RGBLED_NUM 14     // Number of LEDs in your strip
#define RGBLIGHT_ANIMATIONS

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#endif
