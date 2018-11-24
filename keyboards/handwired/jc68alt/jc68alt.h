#ifndef JC66_ALT_H
#define JC66_ALT_H

#include "quantum.h"

#define KEYMAP( \
  K00, K01, K02, K03, K04, K05, K60, K61, K62, K63, K64, K65, \
  K10, K11, K12, K13, K14, K15, K70, K71, K72, K73, K74, K75, \
  K20, K21, K22, K23, K24, K25, K80, K81, K82, K83, K84, K85, \
  K30, K31, K32, K33, K34, K35, K90, K91, K92, K93, K94, K95, \
  K40, K41, K42, K43, K44, K45, KA0, KA1, KA2, KA3, KA4, KA5, \
  K50, K51, K52, K53,                     KB2, KB3, KB4, KB5 \
  ) { \
  { K00,   K01,   K02,  K03,   K04,   K05 }, \
  { K10,   K11,   K12,  K13,   K14,   K15 }, \
  { K20,   K21,   K22,  K23,   K24,   K25 }, \
  { K30,   K31,   K32,  K33,   K34,   K35 }, \
  { K40,   K41,   K42,  K43,   K44,   K45 }, \
  { K50,   K51,   K52,  K53,   KC_NO, KC_NO }, \
  { K60,   K61,   K62,  K63,   K64,   K65 }, \
  { K70,   K71,   K72,  K73,   K74,   K75 }, \
  { K80,   K81,   K82,  K83,   K84,   K85 }, \
  { K90,   K91,   K92,  K93,   K94,   K95 }, \
  { KA0,   KA1,   KA2,  KA3,   KA4,   KA5 }, \
  { KC_NO, KC_NO, KB2,  KB3,   KB4,   KB5 }, \
}

#endif
