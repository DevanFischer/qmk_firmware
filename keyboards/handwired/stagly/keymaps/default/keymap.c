#include "stagly.h"

enum layer_names {
  QWER = 0, // Qwerty
  TAR1,     // Tarmak 1
  TAR2,     // Tarmak 2
  TAR3,     // Tarmak 3
  TAR4,     // Tarmak 4
  COLM,     // Colemak
  DVOR,     // Dvorak
  CURS,     // Cursor Navigation
  SYMB,     // Symbols
  FUNC,     // Function layer
  CNFG      // Configuration
};

enum my_keys {
  M_ENTUP = SAFE_RANGE, // Open up a line above the cursor
  M_ENTDN,              // Open up a line below the cursor
  M_ENTCM,              // Open up a line below the cursor with a comma ,
  M_ENTBR,              // Open up a line below the cursor with a brace {
  DL_QWER,              // Set the default layer to Qwerty
  DL_TAR1,              // Set the default layer to Tarmak stage 1
  DL_TAR2,              // Set the default layer to Tarmak stage 2
  DL_TAR3,              // Set the default layer to Tarmak stage 3
  DL_TAR4,              // Set the default layer to Tarmak stage 4
  DL_COLM,              // Set the default layer to Colemak
  DL_DVOR               // Set the default layer to Dvorak
 };

#define LT_CURS LT(CURS, KC_SPC)
#define LT_FUNE LT(FUNC, KC_ENT)
#define LT_SYME LT(SYMB, KC_ESC)
#define LT_CNFG MO(CNFG)

#define MT_LFSF SFT_T(KC_LEFT)
#define MT_RGSF SFT_T(KC_RIGHT)
#define MT_UPCT CTL_T(KC_UP)
#define MT_DNCT CTL_T(KC_DOWN)

#define BM_SGE MAGIC_SWAP_GRAVE_ESC
#define BM_UGE MAGIC_UNSWAP_GRAVE_ESC

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWER] = KEYMAP(
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    MT_LFSF, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_RGSF,
    MT_UPCT, KC_LALT, KC_LGUI, KC_BSPC, LT_CURS, LT_SYME, LT_FUNE, KC_DELT, KC_MENU, KC_RALT, MT_DNCT
  ),
  [TAR1] = KEYMAP(
    _______, _______, _______, KC_J,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_N,    KC_E,    _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [TAR2] = KEYMAP(
    _______, _______, _______, KC_F,    _______, KC_G,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_T,    KC_J,    _______, KC_N,    KC_E,    _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [TAR3] = KEYMAP(
    _______, _______, _______, KC_F,    KC_J,    KC_G,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_R,    KC_S,    KC_T,    KC_D,    _______, KC_N,    KC_E,    _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [TAR4] = KEYMAP(
    _______, _______, _______, KC_F,    KC_P,    KC_G,    KC_J,    _______, _______, KC_Y,    KC_SCLN, _______, _______,
    _______, _______, KC_R,    KC_S,    KC_T,    KC_D,    _______, KC_N,    KC_E,    _______, KC_O,    _______,
    _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [COLM] = KEYMAP(
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, _______,
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [DVOR] = KEYMAP(
    _______, KC_Q,    KC_D,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, _______, _______, _______,
    _______, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT,
    _______, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [CURS] = KEYMAP(
    XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_COPY, XXXXXXX, XXXXXXX,
    KC_DELT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_CUT,  KC_BSPC,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_PGDN, KC_COPY, KC_CUT,  KC_PASTE,KC_PASTE,_______,
    _______, _______, _______, _______, _______, XXXXXXX, M_ENTUP, M_ENTDN, M_ENTCM, M_ENTBR, _______
  ),
  [SYMB] = KEYMAP(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, XXXXXXX, XXXXXXX, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [FUNC] = KEYMAP(
    XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  LT_CNFG, RESET,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F19,  KC_F20,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [CNFG] = KEYMAP(
    BM_SGE,  BM_UGE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, XXXXXXX,
    XXXXXXX, DL_QWER, DL_COLM, DL_DVOR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, DL_TAR1, DL_TAR2, DL_TAR3, DL_TAR4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case DL_QWER:
        persistent_default_layer_set(1UL<<QWER);
        return false;

      case DL_TAR1:
        persistent_default_layer_set(1UL<<TAR1);
        return false;

      case DL_TAR2:
        persistent_default_layer_set(1UL<<TAR2);
        return false;

      case DL_TAR3:
        persistent_default_layer_set(1UL<<TAR3);
        return false;

      case DL_TAR4:
        persistent_default_layer_set(1UL<<TAR4);
        return false;

      case DL_COLM:
        persistent_default_layer_set(1UL<<COLM);
        return false;

      case DL_DVOR:
        persistent_default_layer_set(1UL<<DVOR);
        return false;

      case M_ENTUP:
        SEND_STRING(SS_TAP(X_HOME)"\n"SS_TAP(X_UP));
        return false;

      case M_ENTDN:
        SEND_STRING(SS_TAP(X_END)"\n");
        return false;

      case M_ENTCM:
        SEND_STRING(SS_TAP(X_END)",\n");
        return false;

      case M_ENTBR:
        SEND_STRING(SS_TAP(X_END)" {\n");
        return false;
    }
  }

  return true;
}
