#include "jc54.h"

#define UNDER_CAMEL_TERMINATE_ON_ENTER

#include "users/jcowgar/macros.h"
#include "users/jcowgar/rolling_bspc_delt.c"
#include "users/jcowgar/under_camel.c"

#include "eeconfig.h"

#define EECONFIG_MY_DO_INVERT (uint8_t *)32

bool doInvert = false;

enum my_layers {
  L_QWERT = 0,
  L_DVORK,
  L_COLMK,
  L_MODDH,
  L_NAV,
  L_PROGM
};

enum my_keys {
  QWERT = SAFE_RANGE,
  DVORK,
  COLMK,
  MODDH,
  TOGINVT,
  JC_OPNA,
  JC_OPNB,
  JC_OPNF,
  JC_OPNC,
  JC_NEQ,
  JC_NDEQ,
  JC_LTEQ,
  JC_GTEQ,
  JC_EQGT,
  JC_EQGF,
  JC_DEQ,
  JC_TEQ,
  JC_PEQ,
  JC_MEQ,
  JC_DFOC,
  JC_HTOP,
  JC_HTCL,
  JC_DOR,
  JC_DAND,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define MK_PROG LT(L_PROGM, KC_DELT)
#define MK_NAV  LT(L_NAV, KC_BSPC)

#define MK_GRV  CTL_T(KC_GRV)
#define MK_ESC  CTL_T(KC_ESC)
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
                               KC_LSFT, KC_SPC,  MK_NAV,  MK_PROG, KC_ENT,  KC_RSFT
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
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
    _______, MK_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  MK_SLSH, _______,
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
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    KC_F12,  QWERT,   DVORK,   COLMK,   MODDH,   _______, _______, KC_HOME, KC_UP,   KC_END,  KC_MPRV, KC_VOLU,
    _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, KC_VOLD,
    _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______, KC_MNXT, KC_MUTE,
                               _______, _______, _______, _______, _______, _______
  ),
  [L_PROGM] = KEYMAP(
    _______, _______, KC_LABK, KC_RABK, JC_NEQ,  JC_NDEQ, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LCBR, KC_RCBR, JC_LTEQ, JC_GTEQ, _______, _______, _______, _______, _______, _______,
    MK_ESC,  JC_DAND, KC_LPRN, KC_RPRN, JC_DEQ,  JC_TEQ,  JC_EQGT, JC_OPNA, JC_OPNB, JC_OPNF, JC_OPNC, JC_DFOC,
    _______, JC_DOR,  KC_LBRC, KC_RBRC, JC_PEQ,  JC_MEQ,  JC_EQGF, _______, JC_HTOP, JC_HTCL, _______, _______,
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
  if (process_under_camel(keycode, record) == false) {
    return false;
  }

  // if (process_rolling_bspc_delt(keycode, record) == false) {
  //   return false;
  // }

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

      case JC_OPNA:
        SEND_STRING(SS_TAP(X_UP)SS_TAP(X_END)"\n");
        return false;

      case JC_OPNB:
        SEND_STRING(SS_TAP(X_END)"\n");
        return false;

      case JC_OPNF:
        SEND_STRING(SS_TAP(X_END)" {\n");
        return false;

      case JC_OPNC:
        SEND_STRING(SS_TAP(X_END)",\n");
        return false;

      case JC_NEQ:
        SEND_STRING("!=");
        return false;

      case JC_NDEQ:
        SEND_STRING("!==");
        return false;

      case JC_LTEQ:
        SEND_STRING("<=");
        return false;

      case JC_GTEQ:
        SEND_STRING(">=");
        return false;

      case JC_DEQ:
        SEND_STRING("==");
        return false;

      case JC_TEQ:
        SEND_STRING("===");
        return false;

      case JC_PEQ:
        SEND_STRING("+=");
        return false;

      case JC_MEQ:
        SEND_STRING("-=");
        return false;

      case JC_DOR:
        SEND_STRING("||");
        return false;

      case JC_DAND:
        SEND_STRING("&&");
        return false;

      case JC_EQGT:
        SEND_STRING("=>");
        return false;

      case JC_EQGF:
        SEND_STRING("=> {\n");
        return false;

      case JC_DFOC:
        SEND_STRING("${}"SS_TAP(X_LEFT));
        return false;

      case JC_HTOP:
        SEND_STRING("<>"SS_TAP(X_LEFT));
        return false;

      case JC_HTCL:
        SEND_STRING("</>"SS_TAP(X_LEFT));
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
