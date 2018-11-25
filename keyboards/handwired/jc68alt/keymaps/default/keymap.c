#include "jc68alt.h"

enum my_layers {
	QWER = 0,
	CURS,
	PROG
};

enum {
  M_DPIP = SAFE_RANGE,
  M_DAMP,
  M_SFLK,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define MT_CBSP MT(CURS, KC_BSPC)
#define MT_PDEL MT(PROG, KC_DELT)

#define T_CTGRV CTL_T(KC_GRV)
#define T_CTBSL CTL_T(KC_BSLS)
#define T_SFTAB SFT_T(KC_TAB)
#define T_SFESC SFT_T(KC_ESC)

/*
  [EMPT] = KEYMAP(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    _______, _______, _______, _______,                                                       _______, _______, _______, _______
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWER] = KEYMAP(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_LBRC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_EQL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    T_CTGRV, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, T_CTBSL,
    KC_LALT, KC_LGUI, _______,          T_SFTAB, KC_SPC, MT_CBSP,  MT_PDEL, KC_ENT,  T_SFESC,          _______, KC_LGUI, KC_RALT,
    _______, _______, _______, _______,                                                       _______, _______, _______, _______
  ),
  [CURS] = KEYMAP(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, _______, _______, _______, _______, _______,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLU, KC_F12,
    XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [PROG] = KEYMAP(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
    XXXXXXX, KC_GRV,  KC_DLR,  KC_LCBR, KC_RCBR, XXXXXXX,                   KC_EQL,  KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, XXXXXXX,
    XXXXXXX, M_DPIP,  M_DAMP,  KC_AMPR, KC_PIPE, XXXXXXX,                   XXXXXXX, KC_EXLM, KC_LABK, KC_RABK, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_DPIP:
      SEND_STRING("||");
      return false;

    case M_DAMP:
      SEND_STRING("&&");
      return false;
	}

  return true;
}
