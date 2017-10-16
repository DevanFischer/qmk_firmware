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
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_SCLN,
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
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    _______, Z_SFT,   KC_X,    KC_C,    KC_D,    KC_V,    KC_ESC,  KC_M,    KC_H,    KC_COMM, KC_DOT,  SLS_SFT, _______,
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
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
