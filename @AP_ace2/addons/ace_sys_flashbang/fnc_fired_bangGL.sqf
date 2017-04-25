/* ace_sys_flashbang (.pbo) | (c) 2013 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __vel ((velocity _flashbang) call ACE_fnc_magnitude)

private ["_pos_bangATL","_viewers","_flashbang","_ammo","_time"];

_ammo = _this select 4;
_flashbang = _this select 6;

while { alive _flashbang && {!isNull _flashbang} } do {
	sleep 0.5;
	if (__vel < 0.2) exitWith {};
};

[_flashbang,_ammo] spawn FUNC(fx_visual);

_pos_bangATL = getPosATL _flashbang;
_viewers = _pos_bangATL nearEntities ["CaManBase", __AOE];
if (count _viewers == 0) exitWith { TRACE_1("No viewers found",""); false };
{
	if (local _x && {alive _x}) then {
		if (_x == player) then {
			[_x,_pos_bangATL,2] spawn FUNC(fx);
		} else {
			[_x,_pos_bangATL,1] spawn FUNC(fx);
		};
	};
} forEach _viewers;
