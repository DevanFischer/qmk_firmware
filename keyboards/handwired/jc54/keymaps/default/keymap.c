#include "jc54.h"
#include "users/jcowgar/macros.h"
#include "users/jcowgar/rolling_bspc_delt.c"

#include "eeconfig.h"

#define EECONFIG_MY_DO_INVERT (uint8_t *)32

bool doInvert = false;

enum my_layers {
  L_QWERT = 0,
  L_DVORK,
  L_COLMK,
  L_MODDH,
  L_NAV,
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
#define MK_NAV  MO(L_NAV)

#define MK_GRV  CTL_T(KC_GRV)
#define MK_BSLS ALT_T(KC_BSLS)
#define MK_Z    GUI_T(KC_Z)
#define MK_SLSH GUI_T(KC_SLSH)
#define MK_RBRC ALT_T(KC_RBRC)
#define MK_QUOT CTL_T(KC_QUOT)

/*
  [L_EMPTY] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWERT] = KEYMAP(
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    MK_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MK_QUOT,
    MK_BSLS, MK_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MK_SLSH, MK_RBRC,
                               KC_LSFT, KC_SPC, MK_NAV,  MK_LOWR,  KC_ENT,  KC_RSFT
  ),
  [L_DVORK] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______
  ),
  [L_COLMK] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______
  ),
  [L_MODDH] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
    _______, MK_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    KC_COMM, KC_DOT,  MK_SLSH, _______,
                               _______, _______, _______, _______, _______, _______
  ),
  [L_NAV] = KEYMAP(
    _______, QWERT,   DVORK,   COLMK,   MODDH,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_MPRV, KC_VOLU,
    _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, KC_VOLD,
    _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______, KC_MNXT, KC_MUTE,
                               _______, _______, _______, _______, _______, _______
  ),
  [L_LOWER] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, _______, _______,
    KC_ESC,  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
    _______, _______, _______, _______, _______, KC_WH_D, _______, _______, _______, _______, _______, _______,
                               TOGINVT, _______, _______, _______, _______, TOGINVT
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
  if (process_rolling_bspc_delt(keycode, record) == false) {
    return false;
  }

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
            TAP_MODKEY(mod_code, keycode);
          } else {
            TAP_MODKEY(KC_LSFT, keycode);
          }

          return false;
        }

        return true;
      }
  }

  return true;
}
