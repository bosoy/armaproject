#define THIS_FILE "x_revive\drop_body.sqf"
#include "xr_macros.sqf"
private ["_dragee", "_unit", "_switchm"];

_dragee	= (_this select 3) select 0;
_switchm = (_this select 3) select 1;

if (GVARXR(dropAction) != -3333) then {
	__PRA(GVARXR(dropAction));
	GVARXR(dropAction) = -3333;
};
if (GVARXR(carryAction) != -3333) then {
	__PRA(GVARXR(carryAction));
	GVARXR(carryAction) = -3333;
};
GVARXR(drag) = false;
GVARXR(carry) = false;
_unit = player;

detach _unit;
detach _dragee;

[QGVARXR(wn), [_dragee,101]] call d_fnc_NetCallEvent;
if (_switchm == 0) then {
	[QGVARXR(swmnon), _unit] call d_fnc_NetCallEvent;
};
