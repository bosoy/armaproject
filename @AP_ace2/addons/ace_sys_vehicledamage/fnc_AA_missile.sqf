#include "script_component.hpp"
#define __cfg configFile >> "CfgAmmo" >> _ammo

private ["_bullet"];

_bullet = _this select 6;

if (isNull _bullet) exitwith {};

[_this select 0, _this select 4, _bullet] spawn {
	private ["_posASL","_pos","_stuff","_expl"];
	PARAMS_3(_unit,_ammo,_bullet);
	
	_pos = [0,0,0];
	_posASL = [0,0,0];
	
	while { alive _bullet } do {
		_pos = getPos _bullet;
		_posASL = getPosASL _bullet;
		sleep 0.001;
	};
	_stuff = _pos nearEntities ["Air", 30];
	
	if ({!(_x isKindOf "ParachuteBase" || {_x isKindOf "BIS_Steerable_Parachute"})} count _stuff > 0) then {
		_expl = "ACE_AA_explosion" createVehicle _pos;
		_expl setPosASL _posASL;
		TRACE_2("",_stuff,((_stuff select 0) distance _pos));
	};
};