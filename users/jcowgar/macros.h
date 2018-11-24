#ifndef JCOWGAR_USERCODE_MACROS
#define JCOWGAR_USERCODE_MACROS

#define TAP_KEY(keycode) register_code(keycode); unregister_code(keycode)
#define TAP_MODKEY(mod, keycode) register_code(mod); register_code(keycode); unregister_code(keycode); unregister_code(mod)

#endif
