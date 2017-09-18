#include "clueboard.h"

enum {
  ALPH = 0, // Alpha
  NUMS,     // Numbers
  CODE,     // Coding (special characters)
  CURS,     // Cursor Navigation
  FKEY      // Function Keys
};

enum {
  M_ENTUP = SAFE_RANGE, // Open up a line above the cursor
  M_ENTDN,              // Open up a line below the cursor
  M_ENTCM,              // Open up a line below the cursor with a comma ,
  M_ENTBR,              // Open up a line below the cursor with a brace {
  M_DPIP,               // Double pipe || (or in many languages)
  M_DAMP,               // Double ampersand && (and in many languages)
  M_SFLK,               // Shift Lock
  M_NMTGL,              // Number Toggle
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
#define X       KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[ALPH] = KEYMAP(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  DYNM_P1, DYNM_P2, M_NMTGL,
  KC_LEAD, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, X,       KC_DELT,
  KC_LSFT, X,KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, M_SFLK,  KC_UP,
  KC_LCTL, KC_LGUI, KC_LALT, LT_NUMT, LT_CURS, LT_CODE,                   LT_FUNC, KC_RALT, KC_MENU, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
[NUMS] = KEYMAP(
  XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, KC_LPRN, KC_7,    KC_8,    KC_9,    KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_VOLD, KC_PLUS, KC_4,    KC_5,    KC_6,    KC_ASTR, XXXXXXX, XXXXXXX, _______,
  _______, X,KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MINS, KC_1,    KC_2,    KC_3,    KC_SLSH, XXXXXXX, _______, _______,
  _______, _______, _______, _______, XXXXXXX, XXXXXXX,                   KC_0,    KC_DOT,  KC_EQL,  _______, _______, _______, _______),
[CODE] = KEYMAP(
  XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, KC_EXLM, KC_LBRC, KC_RBRC, KC_AMPR, KC_PIPE, KC_HASH, KC_AT,   KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
  _______, KC_0,    KC_EQL,  KC_LPRN, KC_RPRN, KC_PLUS, KC_ASTR, KC_UNDS, KC_DLR,  KC_GRV,  KC_DQUO, XXXXXXX, XXXXXXX, _______,
  _______, X,KC_1,  KC_TILD, KC_LCBR, KC_RCBR, KC_MINS, KC_SLSH, KC_COLN, KC_SCLN, KC_BSLS, KC_QUES, XXXXXXX, _______, _______,
  _______, _______, _______, XXXXXXX, XXXXXXX, _______,                   M_ENTUP, M_ENTDN, M_ENTCM, M_ENTBR, _______, _______, _______),
[CURS] = KEYMAP(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_Y,    KC_HOME, KC_UP,   KC_END,  KC_COPY, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_CUT,  XXXXXXX, XXXXXXX, _______,
  _______, X,KC_NO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_PASTE,XXXXXXX, _______, _______,
  _______, _______, _______, XXXXXXX, _______, XXXXXXX,                   XXXXXXX, _______, _______, _______, _______, _______, _______),
[FKEY] = KEYMAP(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DYNM_R1, DYNM_R2, DYNM_ST,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RESET,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, _______,
  _______, X,KC_F1, KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
  _______, KC_ASDN, KC_ASUP, KC_ASRP, XXXXXXX, XXXXXXX,                   _______, AG_SWAP, AG_NORM, _______, _______, _______, _______)
};

bool shift_lock = false;
bool number_toggle = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if (record->event.pressed) {
    switch (keycode) {
      case M_ENTUP:
        SEND_STRING(SS_TAP(X_HOME)"\n"SS_TAP(X_UP));
        return false;

      case M_ENTDN:
        SEND_STRING(SS_TAP(X_END)"\n");
        return false;

      case M_ENTCM:
        SEND_STRING(SS_TAP(X_END)" ,\n");
        return false;

      case M_ENTBR:
        SEND_STRING(SS_TAP(X_END)" {\n");
        return false;

      case M_DPIP:
        SEND_STRING("||");
        return false;

      case M_DAMP:
        SEND_STRING("&&");
        return false;

      case M_SFLK:
        shift_lock = !shift_lock;
        return false;

      case M_NMTGL:
        number_toggle = !number_toggle;
        return false;

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
        if (number_toggle) {
          register_code(KC_LSFT);
        }

        return true;

      default:
        if (shift_lock) {
          register_code(KC_LSFT);
        }
    }
  } else {
    if (shift_lock) {
      unregister_code(KC_LSFT);
    }

    if (number_toggle) {
      unregister_code(KC_LSFT);
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
