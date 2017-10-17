#include "jc60.h"
#include "eeconfig.h"

#define EECONFIG_MY_DO_INVERT (uint8_t *)32

bool doInvert = false;

enum my_layers {
  L_QWERT = 0,
  L_COLMK,
  L_MODDH,
  L_CARPX,
  L_NAVIG,
  L_CONF,
};

enum my_keys {
  QWERT = SAFE_RANGE,
  COLMK,
  MODDH,
  CARPX,
  TOGINVT,
  STATUS,
};

enum hold_taps {
  TH_G_LCBR = 0,
  TH_K_RCBR,
  TH_V_LPRN,
  TH_M_RPRN,
  TH_B_LBRC,
  TH_J_RBRC,
};

#define QK_TAPHOLD 0x5A00
#define QK_TAPHOLD_MAX 0x5AFF
#define TH(t) (QK_TAPHOLD + t)

const uint16_t taphold[][2] = {
  [TH_G_LCBR] = { KC_G, KC_LCBR },
  [TH_K_RCBR] = { KC_K, KC_RCBR },
  [TH_V_LPRN] = { KC_V, KC_LPRN },
  [TH_M_RPRN] = { KC_M, KC_RPRN },
  [TH_B_LBRC] = { KC_B, KC_LBRC },
  [TH_J_RBRC] = { KC_J, KC_RBRC },
};

#define G_LCBR TH(TH_G_LCBR)
#define K_RCBR TH(TH_K_RCBR)
#define V_LPRN TH(TH_V_LPRN)
#define M_RPRN TH(TH_M_RPRN)
#define B_LBRC TH(TH_B_LBRC)
#define J_RBRC TH(TH_J_RBRC)

#define TAP(key) \
  register_code(key); \
  unregister_code(key)

#define TAP_WITH_MOD(mod, key) \
  register_code(mod); \
  register_code(key); \
  unregister_code(key); \
  unregister_code(mod)

#define MK_CONF TT(L_CONF)
#define NAV_BSP LT(L_NAVIG, KC_BSPC)
#define NAV_DEL LT(L_NAVIG, KC_DELT)
#define SPC_NAV LT(L_NAVIG, KC_SPC)
#define SPC_SFT MT(MOD_LSFT, KC_SPC)
#define ENT_NAV LT(L_NAVIG, KC_ENT)
#define ENT_SFT MT(MOD_LSFT, KC_ENT)
#define MK_RGUI MT(MOD_RGUI, KC_DELT)
#define Z_SFT   MT(MOD_LSFT, KC_Z)
#define SLS_SFT MT(MOD_LSFT, KC_SLSH)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

/*
  [EMPT] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWERT] = KEYMAP(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    NAV_BSP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_SCLN,
    MK_CONF, Z_SFT,   KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  SLS_SFT, KC_BSLS,
    KC_LCTL,          KC_LALT, NAV_BSP, KC_SPC,           ENT_SFT, KC_SPC,           NAV_DEL, KC_RALT, KC_RCTL
  ),
  [L_COLMK] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    _______, Z_SFT,   KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,  KC_K,    KC_M,    KC_COMM, KC_DOT,  SLS_SFT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [L_MODDH] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    B_LBRC,  J_RBRC,  KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,
    _______, KC_A,    KC_R,    KC_S,    KC_T,    G_LCBR,  K_RCBR,  KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    _______, Z_SFT,   KC_X,    KC_C,    KC_D,    V_LPRN,  KC_ESC,  M_RPRN,  KC_H,    KC_COMM, KC_DOT,  SLS_SFT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [L_CARPX] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_Q,    KC_G,    KC_M,    KC_L,    KC_W,    KC_B,    KC_Y,    KC_U,    KC_V,    KC_SCLN, KC_LBRC, KC_RBRC,
    _______, KC_D,    KC_S,    KC_T,    KC_N,    KC_R,    KC_I,    KC_A,    KC_E,    KC_O,    KC_H,    KC_QUOT,
    _______, Z_SFT,   KC_X,    KC_C,    KC_F,    KC_J,    KC_ESC,  KC_K,    KC_P,    KC_COMM, KC_DOT,  SLS_SFT, _______,
    _______, _______, _______, _______,          _______, _______,          _______, _______, _______
  ),
  [L_NAVIG] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______,
    KC_DELT, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_PGDN, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [L_CONF] = KEYMAP(
    XXXXXXX, QWERT,   COLMK,   MODDH,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STATUS,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TOGINVT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

#define DISPLAY_SIZE 128

void report_status(void) {
  char display[DISPLAY_SIZE];

  snprintf(display, DISPLAY_SIZE, "\n%s (%s) v%d\n", STR(PRODUCT), STR(DESCRIPTION), DEVICE_VER);
  send_string((const char *)display);

  switch (eeconfig_read_default_layer() >> 1UL) {
    case L_QWERT:
      snprintf(display, DISPLAY_SIZE, "Layout = Qwerty\n");
      break;

    case L_COLMK:
      snprintf(display, DISPLAY_SIZE, "Layout = Colemak\n");
      break;

    case L_MODDH:
      snprintf(display, DISPLAY_SIZE, "Layout = Colemak - Mod-DH\n");
      break;

    case L_CARPX:
      snprintf(display, DISPLAY_SIZE, "Layout = QWMLWB\n");
      break;

    default:
    snprintf(display, DISPLAY_SIZE, "Layout Unknown = %d\n", eeconfig_read_default_layer() >> 1UL);
  }

  send_string((const char *)display);

  snprintf(display, DISPLAY_SIZE, "Auto Invert = %s\n", doInvert ? "Yes" : "No");
  send_string((const char *)display);
}

void matrix_init_user(void) {
  doInvert = eeprom_read_byte(EECONFIG_MY_DO_INVERT) == 1;
}

uint16_t lastTime;
uint16_t lastKeycode;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    lastTime = record->event.time;
    lastKeycode = keycode;

    switch (keycode) {
      case QK_TAPHOLD ... QK_TAPHOLD_MAX:
        {
          uint16_t index = keycode - QK_TAPHOLD;
          uint16_t tap = taphold[index][0];
          TAP(tap);
        }
        return false;

      case STATUS:
        report_status();
        return false;

      case QWERT:
        persistent_default_layer_set(1UL << L_QWERT);
        return false;

      case COLMK:
        persistent_default_layer_set(1UL << L_COLMK);
        return false;

      case MODDH:
        persistent_default_layer_set(1UL << L_MODDH);
        return false;

      case CARPX:
        persistent_default_layer_set(1UL << L_CARPX);
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
            TAP_WITH_MOD(mod_code, keycode);
          } else {
            TAP_WITH_MOD(KC_LSFT, keycode);
          }

          return false;
        }

        return true;
      }
  } else {
    uint16_t elapsed = timer_elapsed(lastTime);

    if (keycode == lastKeycode && elapsed > 150) {
      switch (keycode) {
        case QK_TAPHOLD ... QK_TAPHOLD_MAX:
          {
            uint16_t index = keycode - QK_TAPHOLD;
            uint16_t hold = taphold[index][1];

            TAP(KC_BSPC);
            if (hold & (QK_LSFT|QK_RSFT)) {
              register_code(KC_LSFT);
            }
            TAP(hold);
            if (hold & (QK_LSFT|QK_RSFT)) {
              unregister_code(KC_LSFT);
            }
          }
          return false;
          }
    }
  }

  return true;
}
