// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __MG_CFG configFile >> "CfgVehicles" >> (typeOf _MG)

private ["_MG","_unit", "_MGProxyType","_tripodType","_tripod","_magCount","_numFullMags","_secWep","_wepType","_fullMagRds","_correctAmmo","_holders","_pos","_actor"];

if (count _this == 1) then {
	call (_this select 0);
	_MG	= ACE_MG;
	ACE_MG = nil;
	_unit  = player;
	_actor = player;
} else {
	_unit  = _this select 0;
	_actor = _this select 1;
	_MG = nearestObject [_unit, "StaticWeapon"];
};
if (_actor != _unit) exitWith {};

_MGProxyType = getText (configfile >> "CfgVehicles" >> typeOf _MG >> "ACE" >> "ACE_CREWSERVED" >> "weaponProxy");
_tripodType = getText (configfile >> "CfgVehicles" >> typeOf _MG >> "ACE" >> "ACE_CREWSERVED" >> "tripod");

if (count crew _MG > 0) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
};
if (_MG getVariable QGVAR(busy)) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};

_busy = _unit getVariable [QGVAR(busy), false];

if (!_busy) then {
	[_MG,true] call FUNC(setbusy);

	// PROGRESS BAR
	_unit setVariable ["ACE_PB_Result", 0];
	_time = getNumber(__MG_CFG >> "ACE" >> "ACE_CREWSERVED" >> "mountTime");
	[_time,[""],false,true,_unit,true] spawn ace_progressbar;
	waitUntil { _unit getVariable "ACE_PB_Result" != 0 };
	_exit = _unit getVariable "ACE_PB_Result" != 1;
	_unit setVariable ["ACE_PB_Result", 0];

	if (_exit) exitWith {
		[_MG,false] call FUNC(setbusy);
	};
	_pos = getPosATL _MG;
	
	_part1 = _MGProxyType createVehicle _pos; 
	_pos set [0,((_pos select 0) + 0.15)]; _pos set [1,((_pos select 1) + 0.15)];
	_part1 setPos _pos; _part1 setDir getDir _MG;
	_part2 = _tripodType createVehicle _pos;
	_pos set [0,((_pos select 0) + 0.15)]; _pos set [1,((_pos select 1) + 0.15)];
	_part2 setPos _pos; _part2 setDir getDir _MG;
	// TODO: Space between parts

	deleteVehicle _MG;
	_unit reveal _tripod;
	sleep 1;
	_unit setVariable [QGVAR(busy), false];
};
