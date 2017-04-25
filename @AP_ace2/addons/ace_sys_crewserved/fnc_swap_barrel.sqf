#include "script_component.hpp"

private["_MG","_unit","_actor"];

if (count _this == 1) then {
	call (_this select 0);
	_MG = ACE_MG;
	ACE_MG = nil;
	_unit=player;
	_actor=player;
} else {
	_unit  = _this select 0;
	_actor = _this select 1;
	_MG	= nearestObject[_unit,'StaticWeapon'];
};
if (_actor != _unit) exitWith {};

if (isnil "_MG") exitWith {
	[localize "STR_ACE_CREW_ERR_NOWEP",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};

_busy = _MG getVariable [QGVAR(busy), false];
if (_busy) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};

// Only gunner can swap for now
if (_unit != gunner _MG) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};

_unit setVariable ["ACE_PB_Result", 0];
[7,[localize "STR_ACE_SWAPBARRELACT"],true,true] spawn ace_progressbar;
waitUntil { (_unit getVariable "ACE_PB_Result" != 0) };
if (_unit getVariable "ACE_PB_Result" == 1) then {
	hint "done";
	_temp = _MG getVariable ["ace_sys_overheating_temp",0];
	_lst = _MG getVariable ["ace_sys_overheating_lst",0]; //lastSwapTime
	_cbh = _MG getVariable ["ace_sys_overheating_cbh",0]; //currentBarrelHeat
	_dif = time - _lst;
	_MG setVariable ["ace_sys_overheating_lst", time, false];
	_MG setVariable ["ace_sys_overheating_cbh",_temp,false];
	_temp = _cbh - 1.2*_dif;
	if (_temp < 0) then { _temp = 0 };
	_MG setVariable ["ace_sys_overheating_temp",_temp,true];
};
