#include "jc68.h"
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

enum my_tapdances {
  TD_G_LPRN = 0,
  TD_K_RPRN,
  TD_V_LCBR,
  TD_M_RCBR,
  TD_END_ENT,
  TD_END_LBRC_ENT,
  TD_END_COMM_ENT,
};

typedef struct
{
  const char *s1;
  const char *s2;
} qk_tap_dance_string_pair_t;

void qk_tap_dance_string_pair_finished (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_string_pair_t *pair = (qk_tap_dance_string_pair_t *)user_data;

  if (state->count == 1) {
    send_string(pair->s1);
  } else if (state->count == 2) {
    send_string(pair->s2);
  }
}

#define ACTION_TAP_DANCE_DOUBLE_STRING(s1, s2) {  \
  .fn = { NULL, qk_tap_dance_string_pair_finished, NULL }, \
  .user_data = (void *)&((qk_tap_dance_string_pair_t) { s1, s2 }),  \
}

#define TAP(kc) register_code(kc); unregister_code(kc)
#define TAPM(mod, kc) register_code(mod); register_code(kc); unregister_code(kc); unregister_code(mod)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_G_LPRN]       = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_LPRN),
  [TD_K_RPRN]       = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_RPRN),
  [TD_V_LCBR]       = ACTION_TAP_DANCE_DOUBLE_STRING("v", "{"),
  [TD_M_RCBR]       = ACTION_TAP_DANCE_DOUBLE_STRING("m", "}"),
  [TD_END_ENT]      = ACTION_TAP_DANCE_DOUBLE_STRING("\n", SS_TAP(X_END)"\n"),
  [TD_END_LBRC_ENT] = ACTION_TAP_DANCE_DOUBLE_STRING("[", SS_TAP(X_END)" {\n"),
  [TD_END_COMM_ENT] = ACTION_TAP_DANCE_DOUBLE_STRING(",", SS_TAP(X_END)",\n"),
};

#define MK_CONF TT(L_CONFG)
#define MK_G KC_G /*TD(TD_G_LPRN)*/
#define MK_K KC_K /*TD(TD_K_RPRN)*/
#define MK_V KC_V /*TD(TD_V_LCBR)*/
#define MK_M KC_M /*TD(TD_M_RCBR)*/
//#define MK_ENT TD(TD_END_ENT)
//#define MK_ENT  KC_ENT
//#define MK_SPC  KC_SPC
#define MK_ENT  SFT_T(KC_ENT)
#define MK_SPC  SFT_T(KC_SPC)
#define MK_LBRC TD(TD_END_LBRC_ENT)
#define MK_COMM TD(TD_END_COMM_ENT)
#define MK_WUP  LGUI(KC_UP)
#define MK_WDN  LGUI(KC_DOWN)
#define MK_WLF  LGUI(KC_LEFT)
#define MK_WRT  LGUI(KC_RGHT)
#define MK_LOWR MO(L_LOWER)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

/*
  [EMPT] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
             _______, _______,          _______, _______,          _______, _______,          _______, _______,          _______, _______
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWERT] = KEYMAP(
    KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_HOME, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    KC_LGUI, MK_LOWR, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_UP,   KC_LEFT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DOWN, KC_RGHT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
             KC_LCTL, KC_LALT,          KC_LSFT, MK_SPC,           KC_BSPC, KC_DELT,          MK_ENT,  KC_RSFT,          KC_RALT, KC_RCTL
  ),
  [L_DVORK] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
             _______, _______,          _______, _______,          _______, _______,          _______, _______,          _______, _______
  ),
  [L_COLMK] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
             _______, _______,          _______, _______,          _______, _______,          _______, _______,          _______, _______
  ),
  [L_MODDH] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, _______,
    _______, _______, KC_A,    KC_R,    KC_S,    KC_T,    MK_G,    _______, _______, MK_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_BSLS,
    _______,          KC_Z,    KC_X,    KC_C,    KC_D,    MK_V,    _______, _______, MK_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
             _______, _______,          _______, _______,          _______, _______,          _______, _______,          _______, _______
  ),
  [L_LOWER] = KEYMAP(
    _______, _______, QWERT,   DVORK,   COLMK,   MODDH,   _______,                   _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_PGUP, KC_HOME, _______, _______, _______, _______, _______, _______, _______,
    TOGINVT,          _______, _______, _______, _______, _______, KC_PGDN, KC_END,  _______, _______, _______, _______, _______,          TOGINVT,
             _______, _______,          _______, _______,          _______, _______,          _______, _______,          _______, _______
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

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_ENT) {
      SEND_STRING(SS_TAP(X_END)"\n");
    }

    SEQ_TWO_KEYS(KC_ENT, KC_SPC) {
      SEND_STRING(SS_TAP(X_UP)SS_TAP(X_END)"\n");
    }

    SEQ_ONE_KEY(KC_SCLN) {
      SEND_STRING(SS_TAP(X_END)";");
    }

    SEQ_ONE_KEY(KC_LBRC) {
      SEND_STRING(SS_TAP(X_END)" {\n");
    }

    SEQ_TWO_KEYS(KC_H, KC_COMM) {
      SEND_STRING("<>"SS_TAP(X_LEFT));
    }

    SEQ_TWO_KEYS(KC_H, KC_DOT) {
      SEND_STRING("</>"SS_TAP(X_LEFT));
    }

    SEQ_TWO_KEYS(KC_W, KC_LEFT) {
      SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_LEFT)SS_UP(X_LGUI));
    }

    SEQ_TWO_KEYS(KC_W, KC_RGHT) {
      SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_RIGHT)SS_UP(X_LGUI));
    }

    SEQ_TWO_KEYS(KC_W, KC_UP) {
      SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_UP)SS_UP(X_LGUI));
    }

    SEQ_TWO_KEYS(KC_W, KC_DOWN) {
      SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_DOWN)SS_UP(X_LGUI));
    }
  }
}