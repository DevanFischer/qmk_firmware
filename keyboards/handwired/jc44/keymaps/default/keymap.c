#include "jc44.h"

enum layer_names {
  QWER = 0,
  NAV1,
  NAV2,
  NUMB,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LT_SPC  LT(NAV1, KC_SPC)
#define LT_ENT  LT(NAV2, KC_ENT)
#define LT_NSPC LT(NUMB, KC_SPC)
#define LT_NENT LT(NUMB, KC_ENT)
#define LT_0NUM LT(NUMB, KC_0)
#define LT_1NUM LT(NUMB, KC_1)

/*
  [EMPT] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWER] = KEYMAP(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SCLN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_LCTL, KC_LALT, LT_0NUM, KC_BSPC, LT_SPC,  KC_LSFT, LT_ENT,  KC_TAB,  LT_1NUM, KC_RALT, KC_RCTL
  ),
  [NAV1] = KEYMAP(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_TILD, _______, KC_HOME, KC_UP,   KC_END,  _______,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_LBRC, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_RBRC, KC_PGDN, _______, _______, _______, KC_BSLS,
    _______, _______, _______, KC_DELT, _______, _______, LT_NENT, KC_ESC,  _______, _______, _______
  ),
  [NAV2] = KEYMAP(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_TILD, _______, KC_HOME, KC_UP,   KC_END,  _______,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_LBRC, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_RBRC, KC_PGDN, _______, _______, _______, KC_BSLS,
    _______, _______, _______, KC_DELT, LT_NSPC, _______, LT_ENT,  KC_ESC,  _______, _______, _______
  ),
  [NUMB] = KEYMAP(
    KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};
