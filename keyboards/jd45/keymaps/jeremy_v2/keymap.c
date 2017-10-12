// This is the personal keymap (v2) of Jeremy Cowgar (@jcowgar). It is written for the programmer.

#include "jd45.h"

enum {
  ALPH = 0, // Alpha
  LOWR,
  UPPR
};

#define LT_UPPR LT(UPPR, KC_SPC)
#define LT_LOWR LT(LOWR, KC_ENT)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[ALPH] = KEYMAP_JD45V2(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, KC_EQL,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_BSPC,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, LT_UPPR, LT_LOWR, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL
),
[LOWR] = KEYMAP_JD45V2(
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DELT,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_LBRC, KC_RBRC, KC_LCBR, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[UPPR] = KEYMAP_JD45V2(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_COPY, XXXXXXX, XXXXXXX,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_CUT,  KC_DELT,
  _______, KC_BTN1, KC_MS_L, KC_MS_U, KC_MS_R, KC_BTN3, KC_PGDN, KC_ACL0, KC_ACL1, KC_ACL2, KC_PASTE,_______,
  _______, XXXXXXX, XXXXXXX, KC_MS_D, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
};