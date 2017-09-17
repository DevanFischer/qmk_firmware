// This is the personal keymap (v2) of Jeremy Cowgar (@jcowgar). It is written for the programmer.

#include "jd45.h"


#define PREVENT_STUCK_MODIFIERS
#define PERMISSIVE_HOLD
#define TAPPING_TERM 100

enum {
  ALPH = 0, // Alpha
  NUMS,     // Numbers
	CURS,     // Cursor Navigation
	MOUS,     // Mouse Navigation
  CODE,     // Coding (special characters)
  FKEY      // Function Keys
};

enum {
	//
	// Coding Macros
	//
  M_ENTUP = SAFE_RANGE, // Open up a line above the cursor
  M_ENTDN,              // Open up a line below the cursor
	M_ENTBR,              // Open up a line below the cursor with a brace {
	M_ENTCM,              // Open up a line below the cursor with a ,
  M_DPIPE,              // Double pipe || (or in many languages)
	M_DAMPR,              // Double ampersand && (and in many languages)

	//
	// Visual Code Specific
	//
	M_PREVG,              // Goto the previous editor group (Visual Code)
	M_NEXTG,              // Goto the next editor group
	M_PREVE,              // Goto the previous editor
	M_NEXTE,              // Goto the next editor

	// END
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

#define DYNM_P1 DYN_MACRO_PLAY1
#define DYNM_P2 DYN_MACRO_PLAY2
#define DYNM_R1 DYN_REC_START1
#define DYNM_R2 DYN_REC_START2
#define DYNM_ST DYN_REC_STOP

#define LT_CURS LT(CURS, KC_SPC)
#define LT_CODE LT(CODE, KC_ENT)
#define MO_NUMS MO(NUMS)
#define MO_FKEY MO(FKEY)
#define MO_MOUS MO(MOUS)
#define SFT_TAB SFT_T(KC_TAB)
#define SFT_ESC SFT_T(KC_ESC)
#define MK_TOP  LCTL(KC_HOME)
#define MK_BOTM LCTL(KC_END)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[ALPH] = KEYMAP_JD45V2(
  KC_LEAD, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DYNM_P1, DYNM_P2,
  MO_NUMS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_LEAD,
  KC_BSPC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DELT,
  KC_LCTL, KC_LALT, KC_LGUI, SFT_TAB, LT_CURS, LT_CODE, SFT_ESC, MO_FKEY, KC_RALT, KC_RCTL
),
[NUMS] = KEYMAP_JD45V2(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_PLUS, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_LPRN,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_RPRN,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    KC_DOT,  KC_EQL,  XXXXXXX
),
[CODE] = KEYMAP_JD45V2(
  XXXXXXX, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS, KC_EXLM, XXXXXXX, KC_AT,   KC_HASH, KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LABK, KC_LBRC, KC_LPRN, KC_LCBR, KC_EQL,  KC_COLN, KC_DLR,  KC_GRV,  KC_DQUO, KC_QUOT, KC_0,
  XXXXXXX, KC_RABK, KC_RBRC, KC_RPRN, KC_RCBR, M_DPIPE, KC_PIPE, KC_AMPR, M_DAMPR, XXXXXXX, XXXXXXX, KC_1,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
[CURS] = KEYMAP_JD45V2(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  MK_TOP,  XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, MK_BOTM, XXXXXXX,
  XXXXXXX, M_PREVG, M_PREVE, M_NEXTE, M_NEXTG, XXXXXXX, KC_PGDN, M_ENTUP, M_ENTDN, M_ENTCM, M_ENTBR, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, MO_MOUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
[MOUS] = KEYMAP_JD45V2(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_WH_R, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
[FKEY] = KEYMAP_JD45V2(
  DYNM_ST, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DYNM_R1, DYNM_R2,
  XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_VOLD, KC_MPLY, XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_MUTE, KC_MPRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX
),
};

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

			case M_ENTBR:
        SEND_STRING(SS_TAP(X_END)" {\n");
        return false;

			case M_ENTCM:
        SEND_STRING(SS_TAP(X_END)" ,\n");
        return false;

			case M_PREVG:
				SEND_STRING(SS_LCTRL("k")SS_TAP(X_LEFT));
				return false;

			case M_NEXTG:
				SEND_STRING(SS_LCTRL("k")SS_TAP(X_RIGHT));
				return false;

			case M_PREVE:
				SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_PGUP)SS_UP(X_PGUP)SS_UP(X_LCTRL));
				return false;

			case M_NEXTE:
				SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_PGDOWN)SS_UP(X_PGDOWN)SS_UP(X_LCTRL));
				return false;

      case M_DPIPE:
        SEND_STRING("||");
        return false;

      case M_DAMPR:
        SEND_STRING("&&");
        return false;
    }
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
