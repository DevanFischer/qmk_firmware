#ifndef JCOWGAR_UNDER_CAMEL_USERCODE
#define JCOWGAR_UNDER_CAMEL_USERCODE

#include "quantum.h"

bool process_under_camel(uint16_t keycode, keyrecord_t *record);
void uc_set_under(bool value);
void uc_toggle_under(void);
void uc_set_camel(bool value);
void uc_toggle_camel(void);

#endif
