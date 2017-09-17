// This is the personal keymap (v2) of Jeremy Cowgar (@jcowgar). It is written for the programmer.

#include "atreus.h"

#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD
#define TAPPING_TERM 100

enum {
  ALPH = 0, // Alpha
  NUMS,     // Numbers
  CURS,     // Cursor Navigation
  CODE,     // Coding (special characters)
  FKEY      // Function Keys
};

enum {
  M_ENTU = SAFE_RANGE, // Open up a line above the cursor
  M_ENTD,              // Open up a line below the cursor
  M_ENTC,              // Open up a line below the cursor with a comma ,
  M_ENTB,              // Open up a line below the cursor with a brace {
  M_DPIP,              // Double pipe || (or in many languages)
  M_DAMP,              // Double ampersand && (and in many languages)
  M_ASUP, // Auto Shift Up (Increase Timeout)
  M_ASDN, // Auto Shift Down (Decrease Timeout)
  M_ASTM, // Auto Shift Time or Report Time
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

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

#define DYNM_R1 DYN_REC_START1
#define DYNM_P1 DYN_MACRO_PLAY1
#define DYNM_R2 DYN_REC_START2
#define DYNM_P2 DYN_MACRO_PLAY2
#define DYNM_ST DYN_REC_STOP

#define SFT_Z   SFT_T(KC_Z)
#define SFT_SLS SFT_T(KC_SLSH)
#define LT_CODE LT(CODE, KC_ENT)
#define LT_CURS LT(CURS, KC_SPC)
#define LT_NUMT LT(NUMS, KC_TAB)
#define LT_FUNC LT(FKEY, KC_ESC)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[ALPH] = {
  {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
  {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT},
  {SFT_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  SFT_SLS},
  {KC_LCTL, KC_LALT, KC_LGUI, LT_NUMT, LT_CURS, KC_LEAD, LT_CODE, LT_FUNC, KC_RGUI, KC_RALT, KC_RCTL}
},
[NUMS] = {
  {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_SLSH},
  {KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_VOLU, XXXXXXX, KC_LPRN, KC_4,    KC_5,    KC_6,    KC_ASTR},
  {KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_VOLD, XXXXXXX, KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS},
  {XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_MUTE, XXXXXXX, KC_ENT,  KC_0,    KC_DOT,  KC_EQL,  KC_PLUS}
},
[CURS] = {
  {DYNM_R1, DYNM_R2, DYNM_P1, DYNM_P2, DYNM_ST, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX},
  {KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX},
  {KC_BTN1, KC_MS_L, KC_MS_U, KC_MS_R, KC_BTN3, KC_BSPC, KC_PGDN, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX},
  {XXXXXXX, XXXXXXX, KC_MS_D, XXXXXXX, _______, KC_DELT, M_ENTU,  M_ENTD,  M_ENTC,  M_ENTB,  XXXXXXX}
},
[CODE] = {
  {XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_AMPR, XXXXXXX, KC_PIPE, KC_HASH, KC_AT,   KC_PERC, KC_CIRC},
  {XXXXXXX, KC_TILD, KC_LPRN, KC_LPRN, KC_PLUS, XXXXXXX, KC_ASTR, KC_UNDS, KC_DLR,  KC_GRV,  KC_DQUO},
  {XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_MINS, KC_0,    KC_SLSH, KC_COLN, KC_SCLN, KC_BSLS, KC_QUES},
  {XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, XXXXXXX, KC_1,    _______, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL}
},
[FKEY] = {
  {KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET},
  {KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT},
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {M_ASDN,  M_ASUP,  M_ASTM,  XXXXXXX, XXXXXXX, KC_DELT, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX}
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

      case M_ENTC:
        SEND_STRING(SS_TAP(X_END)" ,\n");
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
        autoshift_timeout += 5;
        return false;

      case M_ASDN:
        autoshift_timeout -= 5;
        return false;

      case M_ASTM:
        if (autoshift_timing) {
          char val[32];

          autoshift_timing = false;
          snprintf(val, 32, "\n%d/%d/%d/%d\n",
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

        any_mod_pressed = get_mods() & (
          MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|
          MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT)|
          MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTL)|
          MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)
        );

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

