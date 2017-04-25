// #define DEBUG_MODE_FULL
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#include "script_component.hpp"
private ["_s"];
PARAMS_1(_unit);
if !([_unit] call FUNC(enabled)) exitWith {};
TRACE_2("Adding HDEH to unit",_this,local (_this select 0));
(vehicle _unit) allowCrewInImmobile true;
_unit setVariable [QGVAR(hdeh), _unit addEventHandler ["handleDamage", {_this call FUNC(wapc_hd)}]];

_s = damage _unit;
//variables to later store damage set with 'sethit' as there's no 'gethit'

_unit setvariable ["ace_damage_engine",_s];
_unit setvariable ["ace_damage_hull",_s];
_unit setvariable ["ace_damage_turret",_s];
_unit setvariable ["ace_damage_gun",_s];
_unit setvariable ["ace_damage_fuel",_s];


_unit setvariable ["ace_damage_lfwheel",_s];
_unit setvariable ["ace_damage_rfwheel",_s];
_unit setvariable ["ace_damage_lf2wheel",_s];
_unit setvariable ["ace_damage_rf2wheel",_s];
_unit setvariable ["ace_damage_lmwheel",_s];
_unit setvariable ["ace_damage_rmwheel",_s];
_unit setvariable ["ace_damage_lbwheel",_s];
_unit setvariable ["ace_damage_rbwheel",_s];

//vehicle capabilities vars
_unit setvariable ["ace_canmove",true];
_unit setvariable ["ace_canshoot",true];

//is on fire
_unit setvariable ["ace_onfire",false];
//is knocked out
_unit setvariable ["ace_ko",false];

//support for non-standard selection names

_s = _unit getvariable "ace_name_engine";
if (isNil "_s") then {
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitengine">>"name");
	_unit setvariable ["ace_name_engine",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hithull">>"name");
	_unit setvariable ["ace_name_hull",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitfuel">>"name");
	_unit setvariable ["ace_name_fuel",_s];
	_s = tolower getText(__unitcfg>>"Turrets">>"MainTurret">>"hitpoints">>"hitturret">>"name");
	_unit setvariable ["ace_name_turret",_s];
	_s = tolower getText(__unitcfg>>"Turrets">>"MainTurret">>"hitpoints">>"hitgun">>"name");
	_unit setvariable ["ace_name_gun",_s];

	// wheels

	_s = tolower getText(__unitcfg>>"hitpoints">>"hitlfwheel">>"name");
	_unit setvariable ["ace_name_lfwheel",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitrfwheel">>"name");
	_unit setvariable ["ace_name_rfwheel",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitlbwheel">>"name");
	_unit setvariable ["ace_name_lbwheel",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitrbwheel">>"name");
	_unit setvariable ["ace_name_rbwheel",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitlmwheel">>"name");
	_unit setvariable ["ace_name_lmwheel",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitrmwheel">>"name");
	_unit setvariable ["ace_name_rmwheel",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitlf2wheel">>"name");
	_unit setvariable ["ace_name_lf2wheel",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitrf2wheel">>"name");
	_unit setvariable ["ace_name_rf2wheel",_s];
};
