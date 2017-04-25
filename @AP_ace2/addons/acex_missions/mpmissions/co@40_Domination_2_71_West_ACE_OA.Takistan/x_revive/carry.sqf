#define THIS_FILE "x_revive\carry.sqf"
#include "xr_macros.sqf"

private ["_dragee", "_unit"];
_dragee	= _this select 3;
private ["_name_dragee"];
_name_dragee = (localize "STR_DOM_MISSIONSTRING_906");
if (alive _dragee) then {if (name _dragee != (localize "STR_DOM_MISSIONSTRING_906")) then {_name_dragee = name _dragee}};
_unit = player;
GVARXR(carry) = true;
GVARXR(drag) = false;

if (GVARXR(carryAction) != -3333) then {
	_unit removeAction GVARXR(carryAction);
	GVARXR(carryAction) = -3333;
};
if (isNull _dragee) exitWith {};
detach _dragee;
sleep 1.5;
__pSetVar [QGVARXR(pisinaction), true];
_dragee setVariable [QGVARXR(dragged), true, true];

[QGVARXR(a1), _dragee] call d_fnc_NetCallEvent;
[QGVARXR(a2), _unit] call d_fnc_NetCallEvent;
sleep 10;
_dragee attachTo [_unit,  [-0,-0.1,-1.2], "RightShoulder"];
[QGVARXR(dir), _dragee] call d_fnc_NetCallEvent;

if (GVARXR(loadAction) == -3333) then {
	__PRA(GVARXR(loadAction));
	GVARXR(loadAction) = - 3333;
};

_found_anim = false;

_anims = ["acinpercmstpsraswrfldnon","acinpercmrunsraswrfldf"];

while {GVARXR(carry)} do {
	if (!_found_anim) then {
		if (animationState player in _anims) then {
			_found_anim = true;
		};
	};
	if (!__GV(_dragee,GVARXR(pluncon)) && alive _dragee) exitWith {
		detach _dragee;
		sleep 0.5;
		[QGVARXR(swmnon), _unit] call d_fnc_NetCallEvent;
		[QGVARXR(wn), [_dragee,102]] call d_fnc_NetCallEvent;
		__PRA(GVARXR(dropAction));
		GVARXR(dropAction) = -3333;
		GVARXR(carry) = false;
	};

	//check that dragged unit still exists
	if (isNull _dragee || !alive _unit || (_found_anim && !((animationState _unit) in _anims))) exitWith {
		__PRA(GVARXR(dropAction));
		GVARXR(dropAction) = -3333;
		if (!isNull _dragee) then {
			detach _dragee;
			sleep 0.5;
			if ((alive _dragee && __GV(_dragee,GVARXR(pluncon))) || !alive _dragee) then {
				[QGVARXR(wn), [_dragee,101]] call d_fnc_NetCallEvent;
			} else {
				[QGVARXR(wn), [_dragee,102]] call d_fnc_NetCallEvent;
			};
		};
		[QGVARXR(swmnon), _unit] call d_fnc_NetCallEvent;
		GVARXR(carry) = false;
	};
	sleep 0.1;
};

__pSetVar [QGVARXR(pisinaction), false];
_dragee setVariable [QGVARXR(dragged), false, true];
