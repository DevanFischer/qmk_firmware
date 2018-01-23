#include "jtiny.h"

enum layer_names {
  ABC1 = 0,
  ABC2,
  ABC3,
  NUMB,
  SYMB,
  FUNC,
  SPEC,
  CNFG
};

enum my_keys {
  M_START = SAFE_RANGE
 };

#define LT_SPAC LT(ABC2, KC_SPC)
#define LT_ENTR LT(ABC3, KC_ENT)
#define LT_NUM0 LT(NUMB, KC_0)
#define LT_NUM1 LT(NUMB, KC_1)
#define LT_NUMC LT(NUMB, KC_COMM)
#define LT_NUMP LT(NUMB, KC_DOT)
#define LT_SYMB LT(SYMB, KC_BSPC)
#define LT_SYMT LT(SYMB, KC_TAB)
#define LT_CNFG MO(CNFG)
#define LT_FUNC OSL(FUNC)
#define OS_SFT  OSM(MOD_LSFT)
#define OS_CTL  OSM(MOD_LCTL)
#define OS_ALT  OSM(MOD_LALT)

#define M_LCDEL LCTL(KC_DELT)
#define M_LCBSP LCTL(KC_BSPC)
#define M_LCHM  LCTL(KC_HOME)
#define M_LCLF  LCTL(KC_LEFT)
#define M_LCDN  LCTL(KC_DOWN)
#define M_LCUP  LCTL(KC_UP)
#define M_LCRG  LCTL(KC_RGHT)
#define M_LCED  LCTL(KC_END)
#define M_COPY  LCTL(KC_C)
#define M_CUT   LCTL(KC_X)
#define M_PASTE LCTL(KC_V)
#define M_UNDO  LCTL(KC_Z)
#define M_REDO  LCTL(KC_Y)


#define _______ KC_TRNS
#define XXXXXXX KC_NO

/*
  [EMPT] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ABC1] = KEYMAP(
    KC_A,    KC_R,    KC_S,    KC_T,    KC_HOME, KC_UP,   KC_END,  KC_N,    KC_E,    KC_I,    KC_O,
    KC_F,    KC_W,    KC_C,    KC_D,    KC_LEFT, KC_DOWN, KC_RGHT, KC_H,    KC_L,    KC_U,    KC_M,
    KC_LCTL, KC_LALT, LT_NUMC, LT_SYMB, LT_SPAC, KC_LSFT, LT_ENTR, LT_SYMT, LT_NUMP, KC_RALT, KC_RCTL
  ),
  [ABC2] = KEYMAP(
    KC_MINS, KC_Q,    KC_B,    KC_G,    KC_LPRN, KC_LBRC, KC_LCBR, KC_K,    KC_SCLN, KC_Y,    KC_QUOT,
    KC_Z,    KC_X,    KC_V,    KC_P,    KC_RPRN, KC_LBRC, KC_RCBR, KC_J,    KC_COMM, KC_DOT,  KC_SLSH,
    _______, _______, XXXXXXX, KC_DEL,  _______, _______, LT_FUNC, KC_ESC,  XXXXXXX, _______, _______
  ),
  [ABC3] = KEYMAP(
    KC_MINS, KC_Q,    KC_B,    KC_G,    KC_LPRN, KC_LBRC, KC_LCBR, KC_K,    KC_SCLN, KC_Y,    KC_QUOT,
    KC_Z,    KC_X,    KC_V,    KC_P,    KC_RPRN, KC_LBRC, KC_RCBR, KC_J,    KC_COMM, KC_DOT,  KC_SLSH,
    _______, _______, XXXXXXX, KC_DEL,  LT_FUNC, _______, _______, KC_ESC,  XXXXXXX, _______, _______
  ),
  [SYMB] = KEYMAP(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______, _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_TILD, KC_MINS, KC_UNDS, KC_PERC, _______, _______, _______, KC_CIRC, KC_PIPE, KC_BSLS, KC_EQL,
    LT_CNFG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [NUMB] = KEYMAP(
    KC_1,    KC_2,    KC_3,    KC_4,    _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_0,
    KC_EQL,  KC_PLUS, KC_MINS, KC_5,    _______, _______, _______, KC_6,    KC_SLSH, KC_ASTR, KC_EQL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [FUNC] = KEYMAP(
    KC_F2,   KC_F3,   KC_F4,   KC_F5,   M_UNDO,  M_REDO,  _______, KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_F1,   _______, _______, KC_F6,   M_CUT,   M_COPY,  M_PASTE, KC_F7,   _______, _______, KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [CNFG] = KEYMAP(
    RGB_TOG, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_MOD, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET
  ),
};
