#include QMK_KEYBOARD_H
#include "eeconfig.h"

#define EECONFIG_MY_DO_INVERT (uint8_t *)32

bool doInvert = false;

enum my_layers {
  L_QWERT = 0,
  L_DVORK,
  L_COLMK,
  L_MODDH,
  L_LOWER
};

enum my_keys {
  QWERT = SAFE_RANGE,
  DVORK,
  COLMK,
  MODDH,
  TOGINVT,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define MK_LOWR MO(L_LOWER)
#define MK_CTL CTL_T(KC_ESC)
#define MK_TAB CTL_T(KC_TAB)
#define MK_QUOT CTL_T(KC_QUOT)

/*
[EMPTY] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
                                        _______, _______,
                                                 _______,
                              _______,  _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______,  _______, _______
),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWERT] = LAYOUT_ergodox(
    // left hand
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC,
    MK_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, MK_LOWR,
    MK_CTL,  KC_LALT, KC_LGUI, KC_TILD, KC_LSFT,
                                        KC_HOME, KC_END,
                                                 KC_PGUP,
                               KC_SPC,  KC_BSPC, KC_PGDN,
    // right hand
    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MK_QUOT,
    MK_LOWR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_RSFT, KC_MENU, KC_RGUI, KC_RALT, MK_CTL,
    KC_LEFT, KC_RGHT,
    KC_UP,
    KC_DOWN, KC_DELT, KC_ENT
  ),
  [L_DVORK] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
                                        _______, _______,
                                                 _______,
                              _______,  _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______,  _______, _______
  ),
  [L_COLMK] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
                                        _______, _______,
                                                _______,
                              _______,  _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______,  _______, _______
  ),
  [L_MODDH] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    _______,
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,
    _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,
    _______, _______, _______, _______, _______,
                                        _______, _______,
                                                _______,
                              _______,  _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
             KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
    _______, KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                      _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______,  _______, _______
  ),
  [L_LOWER] = LAYOUT_ergodox(
    // left hand
    _______, QWERT,   DVORK,   COLMK,   MODDH,   _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,
    _______, _______, _______, _______, TOGINVT,
                                        _______, _______,
                                                 _______,
                              _______,  _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
                      TOGINVT, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
  doInvert = eeprom_read_byte(EECONFIG_MY_DO_INVERT) == 1;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case QWERT:
        persistent_default_layer_set(1UL << L_QWERT);
        return false;

      case DVORK:
        persistent_default_layer_set(1UL << L_DVORK);
        return false;

      case COLMK:
        persistent_default_layer_set(1UL << L_COLMK);
        return false;

      case MODDH:
        persistent_default_layer_set(1UL << L_MODDH);
        return false;

      case TOGINVT:
        doInvert = !doInvert;
        eeprom_update_byte(EECONFIG_MY_DO_INVERT, doInvert ? 1 : 0);
        return false;

      case KC_1 ... KC_0:
      case KC_LBRC:
      case KC_RBRC:
      case KC_BSLS:
        if (doInvert) {
          uint16_t mod_code = KC_NO;

          if (get_mods() & MOD_BIT(KC_LSFT)) {
            mod_code = KC_LSFT;
          } else if (get_mods() & MOD_BIT(KC_RSFT)) {
            mod_code = KC_RSFT;
          }

          if (mod_code != KC_NO) {
            unregister_code(mod_code);
            register_code(keycode);
            unregister_code(keycode);
            register_code(mod_code);
          } else {
            register_code(KC_LSFT);
            register_code(keycode);
            unregister_code(keycode);
            unregister_code(KC_LSFT);
          }

          return false;
        }

        return true;
      }
  }

  return true;
}
