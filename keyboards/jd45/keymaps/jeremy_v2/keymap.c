// This is the personal keymap (v2) of Jeremy Cowgar (@jcowgar). It is written for the programmer.

#include "jd45.h"

enum {
  ALPH = 0, // Alpha
  CURS,     // Cursor Navigation
  NUMS,     // Numbers
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

#define LT_CODE LT(CODE, KC_ENT)
#define LT_CURS LT(CURS, KC_SPC)
#define LT_NUMT LT(NUMS, KC_TAB)
#define LT_FUNC LT(FKEY, KC_ESC)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[ALPH] = KEYMAP_JD45V2(
  KC_LEAD, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DYNM_P1, DYNM_P2,
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_DELT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LALT, KC_LGUI, LT_NUMT, LT_CURS, LT_CODE, LT_FUNC, KC_RGUI, KC_RALT, KC_RCTL
),
[CURS] = KEYMAP_JD45V2(
  _______, DYNM_R1, DYNM_R2, DYNM_ST, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_COPY, XXXXXXX, XXXXXXX,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_CUT,  XXXXXXX,
  _______, KC_BTN1, KC_MS_L, KC_MS_U, KC_MS_R, KC_BTN3, KC_PGDN, KC_ACL0, KC_ACL1, KC_ACL2, KC_PASTE,_______,
  _______, XXXXXXX, XXXXXXX, KC_MS_D, _______, M_ENTU,  M_ENTD,  M_ENTC,  M_ENTB,  XXXXXXX
),
[NUMS] = KEYMAP_JD45V2(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_SLSH, XXXXXXX, XXXXXXX,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_VOLU, KC_LPRN, KC_4,    KC_5,    KC_6,    KC_ASTR, _______,
  _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_VOLD, KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS, _______,
  _______, _______, _______, _______, KC_MUTE, KC_ENT,  KC_0,    KC_DOT,  KC_EQL,  KC_PLUS
),
[CODE] = KEYMAP_JD45V2(
  _______, XXXXXXX, KC_EXLM, KC_LBRC, KC_RBRC, KC_AMPR, KC_PIPE, KC_HASH, KC_AT,   KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX,
  _______, KC_0,    KC_EQL,  KC_LPRN, KC_RPRN, KC_PLUS, KC_ASTR, KC_UNDS, KC_DLR,  KC_GRV,  KC_DQUO, XXXXXXX,
  _______, KC_1,    KC_TILD, KC_LCBR, KC_RCBR, KC_MINS, KC_SLSH, KC_COLN, KC_SCLN, KC_BSLS, KC_QUES, _______,
  _______, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, _______, KC_0,    KC_LGUI, KC_LALT, KC_LCTL
),
[FKEY] = KEYMAP_JD45V2(
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_ASDN, KC_ASUP, KC_ASRP, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    }
  }

	return true;
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
