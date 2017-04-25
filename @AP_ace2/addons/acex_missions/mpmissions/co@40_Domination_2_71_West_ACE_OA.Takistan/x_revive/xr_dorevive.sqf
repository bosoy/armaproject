#define THIS_FILE "x_revive\xr_dorevive.sqf"
#include "xr_macros.sqf"

__pSetVar [QGVARXR(cursorTarget), _this select 0];
(_this select 0) setVariable [QGVARXR(busyt), time + 10, true];

0 spawn FUNCXR(dorevive)