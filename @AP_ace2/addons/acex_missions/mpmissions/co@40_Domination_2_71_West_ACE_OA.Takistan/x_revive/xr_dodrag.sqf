#define THIS_FILE "x_revive\xr_dodrag.sqf"
#include "xr_macros.sqf"

__pSetVar [QGVARXR(cursorTarget), _this select 0];

0 spawn FUNCXR(drag);