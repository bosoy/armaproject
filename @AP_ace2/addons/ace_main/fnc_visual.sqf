/* ----------------------------------------------------------------------------
Function: ACE_fnc_visual

Description:
	-

Parameters:
	-

Returns:
		-

Examples:
	(begin example)
		-
	(end)

Author:
	(c) Rocko 2010
---------------------------------------------------------------------------- */

/* ace_rsc_generic_fnc_visual.sqf | (c) 2009 by rocko */

// ACE2 LAYER: 1352 - 0 = Base layer for ace_rsc_generic

#include "script_component.hpp"

// ["Text",[1,0,0,1],1] spawn ACE_fnc_visual
// Example: Display "Text" at top left corner with default fade in/fade out in color red

// ["Text12",[1,0,0,1],0,10] spawn ACE_fnc_visual
// Example: Display "Text12" at top left corner with 10 seconds duration in color red

// _text = "Test_69";
// _text spawn ACE_fnc_visual
// Example: Display "Test_69" at top left corner with default fade in/fade out in default color

#define __dsp (uiNamespace getVariable _display)
#define __ctrl (__dsp displayCtrl _idc)
#define __setText __ctrl ctrlSetText _text
#define __setColor __ctrl ctrlSetTextColor _color

#define __visual 13520 cutRsc [_display,"PLAIN"]; \
__setText; \
__setColor;

#define __isCrew ((player in [(driver vehicle player), (gunner vehicle player), (commander vehicle player)]) && {(player != vehicle player)})

#define __controls (getArray (configFile >> "RscTitles" >> _display >> "controls"))
#define __idc (getNumber (configFile >> "RscTitles" >> _display >> _x >> "idc"))

#define __MOVEY (0.155)
#define __POSX (getNumber (configFile >> "RscTitles" >> _display >> _x >> "x"))
#define __POSY (getNumber (configFile >> "RscTitles" >> _display >> _x >> "y"))

#define __ADAPT { \
	(__dsp displayCtrl __idc) ctrlSetPosition [__POSX, (__POSY + __MOVEY)]; \
	(__dsp displayCtrl __idc) ctrlCommit 0; \
} foreach __controls

private["_ar"];
_ar = _this;

private["_text","_color","_fade","_time"];
if (typeName _ar == "STRING") then {
	_text = _ar;
	_color = [0.8784,0.8471,0.651,1];//[0.6,0.8392,0.4706,1];
	_fade = true;
	_time = 0;
} else {
	_text = _ar select 0;
	if (_text == "") then { _text = "nil"; };
	_color = _ar select 1;
	if (isNil "_color" || {(count _color) < 4}) then {_color = [0.6,0.8392,0.4706,1]};
	_fade = _ar select 2;
	if (isNil "_fade") then {_fade = true};
	if (!isNil "_fade" && {(_fade in [0,1])}) then {
		_fade = (_fade == 1);
	};
	_time = _ar select 3;
	if (isNil "_time") then {_time = 0.1};
};

private ["_display","_idc"];
if (_fade) then {
	_display = "ACE_RscGeneric"; _idc = 135136;
} else {
	_display = "ACE_RscGenericNF"; _idc = 1358009;
};

private "_time";
_t = time;

if (_fade) then {
	__visual
	if __isCrew then { __ADAPT; };
} else {
	__visual
	if (__isCrew) then { __ADAPT; };
	while { time < (_t + _time) } do {
		sleep 1;
	};
	13520 cutRsc ["Default","PLAIN"];
};

false
