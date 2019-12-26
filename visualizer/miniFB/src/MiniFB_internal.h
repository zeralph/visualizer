#pragma once

#include "../include/MiniFB.h"
#include "../include/MiniFB_enums.h"

#define kCall(func, ...)    if(window_data && window_data->func) window_data->func((struct Window *) window_data, __VA_ARGS__);
#define kUnused(var)        (void) var;

#if defined(__cplusplus)
extern "C" {
#endif

    extern short int g_keycodes[512];
    void init_keycodes();
    void keyboard_default(struct Window *window, Key key, KeyMod mod, bool isPressed);

#if defined(__cplusplus)
}
#endif
