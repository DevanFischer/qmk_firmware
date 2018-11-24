#include "jc31.h"

enum layer_names {
  ABC1 = 0, // Qwerty
  ABC2,
  NUMB,
  SYM1,
  SYM2,
  SPEC,
  FUNC
};

enum my_keys {
  M_START = SAFE_RANGE
 };

#define LT_SPAC LT(ABC2, KC_SPC)
#define LT_NUMB LT(NUMB, KC_COMM)
#define LT_SYMB LT(SYM1, KC_DOT)
#define LT_SYM2 LT(SYM2, KC_DOT)
#define LT_FUNC OSL(FUNC)
#define OS_SFT  OSM(MOD_LSFT)
#define OS_CTL  OSM(MOD_LCTL)
#define OS_ALT  OSM(MOD_LALT)

#define M_LCDEL LCTL(KC_DELT)
#define M_LCBSP LCTL(KC_BSPC)
#define M_LCHM LCTL(KC_HOME)
#define M_LCLF LCTL(KC_LEFT)
#define M_LCDN LCTL(KC_DOWN)
#define M_LCUP LCTL(KC_UP)
#define M_LCRG LCTL(KC_RGHT)
#define M_LCED LCTL(KC_END)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

/*
  [EMPT] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______,          _______,          _______
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ABC1] = KEYMAP(
    _______, KC_HOME, KC_UP,   KC_LEFT, KC_RGHT, KC_DOWN, KC_END,
    KC_ESC,  KC_C,    KC_M,    KC_R,    KC_A,    KC_F,    KC_DELT,
    LT_SPAC, KC_D,    KC_T,    KC_H,    KC_E,    KC_O,    KC_BSPC,
    OS_SFT,  KC_L,    KC_S,    KC_N,    KC_I,    KC_U,    KC_ENT,
             LT_SPAC,          LT_NUMB,          LT_SYMB
  ),
  [ABC2] = KEYMAP(
    _______, M_LCHM,  M_LCLF,  M_LCDN,  M_LCUP,  M_LCRG,  M_LCED,
    KC_TAB,  KC_Q,    KC_B,    KC_V,    KC_QUOT, KC_TAB,  M_LCBSP,
    _______, KC_J,    KC_P,    KC_G,    KC_W,    KC_Y,    M_LCDEL,
    _______, KC_Z,    KC_X,    KC_K,    XXXXXXX, KC_LALT, KC_DOT,
             _______,          KC_COMM,          KC_QUES
  ),
  [SYM1] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_SCLN, KC_COLN, KC_ASTR, KC_AMPR, KC_QUES, _______,
    LT_SYM2, KC_UNDS, KC_AT,   KC_MINS, KC_EXLM, KC_SLSH, _______,
    _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_LABK, KC_DQUO, LT_SYM2,
             _______,          _______,          _______
  ),
  [SYM2] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_HASH, KC_DLR,  KC_EQL,  KC_PLUS, KC_TAB,  _______,
    _______, KC_CIRC, KC_TILD, KC_PIPE, KC_PERC, KC_BSLS, _______,
    _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_RABK, KC_GRV,  _______,
             _______,          _______,          _______
  ),
  [NUMB] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MINS, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
    _______, KC_PLUS, KC_4,    KC_5,    KC_6,    KC_SLSH, _______,
    _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  LT_FUNC,
             OS_ALT,           _______,          OS_CTL
  ),
  [FUNC] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_COPY, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_CUT,  _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PASTE,_______,
             _______,          _______,          _______
  ),
};
