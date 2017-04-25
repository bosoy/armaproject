// by Xeno
#define THIS_FILE "x_clearlayout.sqf"
#include "x_setup.sqf"

GVAR(custom_layout) = [];

#ifdef __ACE__
GVAR(custom_ruckbkw) = nil;
GVAR(custom_ruckmag) = nil;
GVAR(custom_ruckwep) = nil;
#endif

(localize "STR_DOM_MISSIONSTRING_201") call FUNC(GlobalChat);
