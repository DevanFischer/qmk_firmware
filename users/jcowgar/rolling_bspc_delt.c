#include "rolling_bspc_delt.h"

bool isSpaceDown = false;
bool isEnterDown = false;
bool doingDelete = false;
bool doingBackspace = false;

bool process_rolling_bspc_delt(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case KC_SPC:
        isSpaceDown = true;

        if (isSpaceDown && isEnterDown) {
          doingBackspace = true;
          register_code(KC_BSPC);
        }

        return false;

      case KC_ENT:
        isEnterDown = true;

        if (isSpaceDown && isEnterDown) {
          doingDelete = true;
          register_code(KC_DELT);
        }

        return false;
      }
  } else {
    switch (keycode) {
      case KC_SPC:
        if (doingDelete == false && doingBackspace == false) {
          TAP_KEY(KC_SPC);
        } else if (doingBackspace) {
          unregister_code(KC_BSPC);
          doingBackspace = isEnterDown;
        } else if (doingDelete) {
          unregister_code(KC_DELT);
          doingDelete = isEnterDown;
        }

        isSpaceDown = false;

        return false;

      case KC_ENT:
        if (doingDelete == false && doingBackspace == false) {
          TAP_KEY(KC_ENT);
        } else if (doingBackspace) {
          unregister_code(KC_BSPC);
          doingBackspace = isSpaceDown;
        } else if (doingDelete) {
          unregister_code(KC_DELT);
          doingDelete = isSpaceDown;
        }

        isEnterDown = false;

        return false;
    }
  }

  return true;
}
