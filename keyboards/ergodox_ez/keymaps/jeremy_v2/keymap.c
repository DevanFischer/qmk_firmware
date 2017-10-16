#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum {
  QWER = 0, // Qwerty
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

/*
[EMPTY] = LAYOUT_ergodox(
	// Left Hand
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
																																	XXXXXXX, XXXXXXX,
																																					XXXXXXX,
																												XXXXXXX, XXXXXXX, XXXXXXX,

	// Right Hand
										XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
										XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
															XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
										XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
																			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX,
	XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX
)
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[QWER] = LAYOUT_ergodox(
		// Left Hand
		KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
		KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,
		KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,
		KC_LCTL, KC_LALT, KC_LGUI, KC_LEFT, KC_RIGHT,
		                                                               KC_HOME, XXXXXXX,
																																						XXXXXXX,
																												 KC_SPC,   KC_ENT,  XXXXXXX,

		// Right Hand
											KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
											KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
															 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
											KC_DELT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
															          KC_UP,   KC_DOWN, KC_APP,  KC_RALT, KC_RCTL,
		KC_APP,  KC_END,
		XXXXXXX,
		XXXXXXX, KC_ENT, KC_SPC
	),
};
