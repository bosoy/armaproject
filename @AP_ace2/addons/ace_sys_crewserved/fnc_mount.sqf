#include "script_component.hpp"

#define __MG_CFG configFile >> "CfgVehicles" >> (typeOf _MG)

private ["_unit","_actor","_statics","_tripod","_tripodType","_MG", "_weapon"];

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

if (_unit != _actor) exitWith {};
if !(isPlayer _unit) then { _unit moveTo (getPos _MG); };

_weapon = secondaryWeapon _unit;
_MGType = (getText (configfile >> "CfgWeapons" >> _weapon >> "ACE" >> "ACE_CREWSERVED" >> "weapon"));
_crewTripods = (getArray (configfile >> "CfgWeapons" >> _weapon >> "ACE" >> "ACE_CREWSERVED" >> "canUseTripods"));
_statics = (getposATL _unit) nearEntities ["StaticWeapon", if !(isPlayer _unit) then {6} else {3}];

if (count _statics == 0) exitWith {
	[localize "STR_ACE_CREW_ERR_NOWEP",[1,0,0,1],true,0] spawn ace_fnc_visual;
};
_tripod = _statics select 0;

_tripodType = typeOf _tripod;
if !(isText (configfile >> "CfgVehicles" >> _tripodType >> "ACE" >> "ACE_CREWSERVED" >> "tripodProxy")) exitWith {
	[localize "STR_ACE_CREW_ERR_NOWEP",[1,0,0,1],true,0] spawn ace_fnc_visual;
};

if !(_tripodType in _crewTripods) then {
	_weapon = primaryWeapon _unit;
	_MGType = (getText (configfile >> "CfgWeapons" >> _weapon >> "ACE" >> "ACE_CREWSERVED" >> "weapon"));
	_crewTripods = (getArray (configfile >> "CfgWeapons" >> _weapon >> "ACE" >> "ACE_CREWSERVED" >> "canUseTripods"));
};

if !(_tripodType in _crewTripods) exitWith {
	[localize "STR_ACE_CREW_ERR_NOTFIT",[1,0,0,1],true,0] spawn ace_fnc_visual;
};

if !(_unit getVariable [QGVAR(busy), false]) then {
	_unit setVariable ["ACE_PB_Result", 0];
	_time = getNumber(__MG_CFG >> "ACE" >> "ACE_CREWSERVED" >> "mountTime");
	_unit removeWeapon _weapon;
	[_time,[""],false,true,_unit,true] spawn ace_progressbar;
	waitUntil { (_unit getVariable "ACE_PB_Result" != 0) };
	_exit = (_unit getVariable "ACE_PB_Result" != 1);

	_unit setVariable ["ACE_PB_Result", 0];

	if (_exit) exitWith {
		_unit addWeapon _weapon;
	};

	[_MG,true] call FUNC(setbusy);
	_unit setVariable [QGVAR(busy), true];
	_MG = _MGType createVehicle [0,0,0];
	_MG setPosATL [getPosATL _tripod select 0, getPosATL _tripod select 1, getPosATL _tripod select 2];
	_MG setDir getDir _tripod;

	deleteVehicle _tripod;
	
	_unit reveal _MG;

	[QGVAR(noam), _MG] call CBA_fnc_globalEvent;
	[_MG,_unit] spawn {
		PARAMS_2(_MG,_unit);
		sleep 2;
		_unit setVariable [QGVAR(busy), false];
		[_MG,false] call FUNC(setbusy);
	};
};
