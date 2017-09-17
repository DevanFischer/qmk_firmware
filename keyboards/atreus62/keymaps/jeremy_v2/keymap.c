// This is the personal keymap (v2) of Jeremy Cowgar (@jcowgar). It is written for the programmer.

#include <stdio.h>

#include "atreus62.h"

#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD
#define TAPPING_TERM 100

#define TAP(key) \
  register_code(key); \
  unregister_code(key)

#define TAP_WITH_MOD(mod, key) \
  register_code(mod); \
  register_code(key); \
  unregister_code(key); \
  unregister_code(mod)

#define TAP_WITH_2MODS(mod1, mod2, key) \
  register_code(mod1); \
  register_code(mod2); \
  register_code(key); \
  unregister_code(key); \
  unregister_code(mod2); \
  unregister_code(mod1)

#define ANY_MOD (MOD_BIT(KC_LGUI))

enum {
  ALPH = 0, // Alpha
  NUMS,     // Numbers
  CURS,     // Cursor Navigation
  CODE,     // Coding (special characters)
  FKEY      // Function Keys
};

enum {
  M_ENTU = SAFE_RANGE, // Open up a line above the cursor, regardless of cursor position
  M_ENTD,              // Open up a line below the cursor, regardless of cursor position
  M_ENTB,              // Open up a line below the cursor with a brace {, regardless of cursor position
  M_DPIP,              // Double pipe || (or in many languages)
  M_DAMP,              // Double ampersand && (and in many languages)
  M_ASUP,
  M_ASDN,
  M_ASTM,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define DYNM_R1 DYN_REC_START1
#define DYNM_P1 DYN_MACRO_PLAY1
#define DYNM_R2 DYN_REC_START2
#define DYNM_P2 DYN_MACRO_PLAY2
#define DYNM_ST DYN_REC_STOP

#define LT_CODZ LT(CODE, KC_Z)
#define LT_CODS LT(CODE, KC_SLSH)
#define LT_CURT LT(CURS, KC_TAB)
#define LT_NUME LT(NUMS, KC_ESC)
#define SFT_SPC SFT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define MO_FKEY MO(FKEY)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[ALPH] = {
	{KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS},
  {M_ASUP,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX},
  {M_ASDN,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX},
  {M_ASTM,  LT_CODZ, KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  LT_CODS, XXXXXXX},
  {XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, LT_CURT, SFT_SPC, KC_LEAD, SFT_ENT, LT_NUME, KC_DELT, KC_RALT, KC_RCTL, XXXXXXX}
},
[NUMS] = {
	{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_SLSH, _______, KC_MUTE, _______, _______, _______, _______, XXXXXXX},
  {XXXXXXX, KC_LPRN, KC_4,    KC_5,    KC_6,    KC_ASTR, _______, KC_VOLU, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX},
  {XXXXXXX, KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS, _______, KC_VOLD, MO_FKEY, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX},
  {XXXXXXX, XXXXXXX, KC_0,    KC_DOT,  KC_EQL,  KC_PLUS, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX}
},
[CURS] = {
	{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, DYNM_R1, DYNM_P1, DYNM_R2, DYNM_P2, DYNM_ST, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, XXXXXXX},
  {XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______, XXXXXXX},
  {XXXXXXX, KC_BTN2, KC_MS_L, KC_MS_U, KC_MS_R, KC_BTN1, _______, KC_PGDN, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX},
  {XXXXXXX, _______, _______, KC_MS_D, _______, _______, KC_DELT, M_ENTU,  M_ENTD,  M_ENTB,  _______, _______, XXXXXXX}
},
[CODE] = {
	{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX},
  {XXXXXXX, KC_TILD, KC_LBRC, KC_LPRN, KC_LCBR, KC_PIPE, _______, KC_AMPR, KC_UNDS, KC_GRV,  KC_DQUO, KC_QUOT, XXXXXXX},
  {XXXXXXX, _______, KC_RBRC, KC_RPRN, KC_RCBR, M_DPIP,  _______, M_DAMP,  KC_CIRC, KC_BSLS, _______, _______, XXXXXXX},
  {XXXXXXX, _______, _______, _______, XXXXXXX, _______, KC_DELT, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX}
},
[FKEY] = {
	{XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, RESET,   XXXXXXX},
  {XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX},
  {XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______, XXXXXXX},
  {XXXXXXX, _______, _______, _______, XXXXXXX, _______, KC_DELT, _______, _______, _______, _______, _______, XXXXXXX}
}};

bool autoshifting = false;
bool autoshift_timing = false;
uint16_t autoshift_time = 0;
uint16_t autoshift_lastkey = 0;
uint16_t autoshift_timeout = 200;
uint16_t autoshift_timer = 0;
uint16_t autoshift_timer_min = 999;
uint16_t autoshift_timer_max = 0;
uint16_t autoshift_timer_keys = 0;

void autoshift_on(uint16_t keycode) {
  autoshift_time = timer_read();
  autoshift_lastkey = keycode;
}

void autoshift_off(void) {
  autoshift_time = 0;
  autoshift_lastkey = KC_NO;
}

void autoshift_flush(void) {
  if (autoshift_lastkey != KC_NO) {
    uint16_t elapsed = timer_elapsed(autoshift_time);

    if (elapsed > autoshift_timeout) {
      TAP_WITH_MOD(KC_LSFT, autoshift_lastkey);
    } else {
      TAP(autoshift_lastkey);
    }

    if (autoshift_timing) {
      if (elapsed > autoshift_timer_max) {
        autoshift_timer_max = elapsed;
      }
      if (elapsed < autoshift_timer_min) {
        autoshift_timer_min = elapsed;
      }
      autoshift_timer += elapsed;
    }

    autoshift_off();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t any_mod_pressed;

  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if (record->event.pressed) {
    switch (keycode) {
      case M_ENTU:
        SEND_STRING(SS_TAP(X_HOME)"\n"SS_TAP(X_UP));
        return false;

      case M_ENTD:
        SEND_STRING(SS_TAP(X_END)"\n");
        return false;

      case M_ENTB:
        SEND_STRING(SS_TAP(X_END)" {\n");
        return false;

      case M_DPIP:
        SEND_STRING("||");
        return false;

      case M_DAMP:
        SEND_STRING("&&");
        return false;

      case M_ASUP:
        autoshift_timeout += 25;
        return false;

      case M_ASDN:
        autoshift_timeout -= 25;
        return false;

      case M_ASTM:
        if (autoshift_timing) {
          char val[64];

          autoshift_timing = false;
          snprintf(val, 64, "min: %d avg: %d max: %d hold time, %d timeout setting",
            autoshift_timer_min, autoshift_timer / autoshift_timer_keys, autoshift_timer_max,
            autoshift_timeout);
          send_string((const char *)val);
        } else {
          autoshift_timing = true;
        }

      case KC_A:
      case KC_B:
      case KC_C:
      case KC_D:
      case KC_E:
      case KC_F:
      case KC_G:
      case KC_H:
      case KC_I:
      case KC_J:
      case KC_K:
      case KC_L:
      case KC_M:
      case KC_N:
      case KC_O:
      case KC_P:
      case KC_Q:
      case KC_R:
      case KC_S:
      case KC_T:
      case KC_U:
      case KC_V:
      case KC_W:
      case KC_X:
      case KC_Y:
      case KC_Z:
      case KC_1:
      case KC_2:
      case KC_3:
      case KC_4:
      case KC_5:
      case KC_6:
      case KC_7:
      case KC_8:
      case KC_9:
      case KC_0:
      case KC_SCLN:
      case KC_SLSH:
      case KC_QUOT:
      case KC_TILD:
      case KC_EQL:
      case KC_MINUS:
        if (autoshift_timing) {
          autoshift_timer_keys++;
        }

        autoshift_flush();

        any_mod_pressed = get_mods() & MOD_BIT(KC_LGUI);

        if (any_mod_pressed) {
          return true;
        }

        autoshift_on(keycode);
        return false;

      default:
        autoshift_flush();
        return true;
    }
  } else {
    autoshift_flush();
  }

	return true;
}

void matrix_init_user(void) {
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    //
    // F leader
    //

    // Find
    SEQ_TWO_KEYS(KC_F, KC_F) {
      TAP_WITH_MOD(KC_LCTL, KC_F);
    }

    // Find and Replace
    SEQ_TWO_KEYS(KC_F, KC_R) {
      TAP_WITH_MOD(KC_LCTL, KC_H);
    }

    // Find in Files
    SEQ_THREE_KEYS(KC_F, KC_I, KC_F) {
      TAP_WITH_2MODS(KC_LCTL, KC_LSFT, KC_F);
    }

    // Find and Replace in Files
    SEQ_THREE_KEYS(KC_F, KC_R, KC_F) {
      TAP_WITH_2MODS(KC_LCTL, KC_LSFT, KC_H);
    }

    // File Save
    SEQ_TWO_KEYS(KC_F, KC_S) {
      TAP_WITH_MOD(KC_LCTL, KC_S);
    }

    // File Open
    SEQ_TWO_KEYS(KC_F, KC_O) {
      TAP_WITH_MOD(KC_LCTL, KC_P);
    }
  }
}
