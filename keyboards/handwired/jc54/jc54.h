#ifndef JC54_ALT_H
#define JC54_ALT_H

#include "quantum.h"

#define KEYMAP( \
  K00, K01, K02, K03, K04, K05, K50, K51, K52, K53, K54, K55, \
  K10, K11, K12, K13, K14, K15, K60, K61, K62, K63, K64, K65, \
  K20, K21, K22, K23, K24, K25, K70, K71, K72, K73, K74, K75, \
  K30, K31, K32, K33, K34, K35, K80, K81, K82, K83, K84, K85, \
                 K43, K44, K45, K90, K91, K92                 \
  ) { \
  { K00,   K01,   K02,   K03,   K04,   K05 }, \
  { K10,   K11,   K12,   K13,   K14,   K15 }, \
  { K20,   K21,   K22,   K23,   K24,   K25 }, \
  { K30,   K31,   K32,   K33,   K34,   K35 }, \
  { KC_NO, KC_NO, KC_NO, K43,   K44,   K45 }, \
  { K50,   K51,   K52,   K53,   K54,   K55 }, \
  { K60,   K61,   K62,   K63,   K64,   K65 }, \
  { K70,   K71,   K72,   K73,   K74,   K75 }, \
  { K80,   K81,   K82,   K83,   K84,   K85 }, \
  { K90,   K91,   K92,   KC_NO, KC_NO, KC_NO }, \
}

#endif
