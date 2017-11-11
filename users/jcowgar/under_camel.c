#include "under_camel.h"

bool isUnder = false;
bool isCamel = false;

void uc_set_under(bool value) {
  isUnder = value;
}

void uc_set_camel(bool value) {
  isCamel = value;
}

bool process_under_camel(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case KC_SPC:
        if (isUnder) {
          register_code(KC_LSFT);
          register_code(KC_MINS);
          return false;
        }

        // Let someone else handle it
        return true;

#ifdef UC_TOGG
      case UC_TOGG:
        isUnder = !isUnder;
        return false;
#endif

#ifdef UNDER_CAMEL_TERMINATE_ON_ENTER
      case KC_ENT:
        if (isUnder) {
          isUnder = false;
          return false;
        }

        return true;
#endif
    }
  } else {
    switch (keycode) {
      case KC_SPC:
        if (isUnder) {
          unregister_code(KC_MINS);
          unregister_code(KC_LSFT);
          return false;
        }

        return true;
    }
  }

  return true;
}
