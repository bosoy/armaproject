#include "script_component.hpp"

private ["_unit", "_ammo", "_anim"];

PARAMS_3(_unit,_ammo,_anim);

if (_anim == "") then {
	_anim = (_unit call CBA_fnc_getUnitAnim) select 0;
};

if (_ammo isKindOf "bulletBase") then {
	if !(surfaceIsWater (position _unit)) then {
		if (_anim == "prone") then {
			10010 cutRsc["ACE_Wound_ScreenDirt","PLAIN"];
		};
	};
	10009 cutRsc[format ["ACE_Wound_ScreenBlood%1", ceil (random 3)],"PLAIN"];
};
