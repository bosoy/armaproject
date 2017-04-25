// #define DEBUG_MODE_FULL
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#include "script_component.hpp"
private ["_s"];
PARAMS_1(_unit);
if (_unit iskindOf "parachutebase") exitwith {};

//if (isNumber(__unitcfg >> "ace_dmgsys_enable") && getNumber(__unitcfg >> "ace_dmgsys_enable") == 0) exitwith {};
TRACE_2("Adding HDEH to unit",_this,local (_this select 0));
//_unit removealleventhandlers "handledamage";
//_unit removealleventhandlers "dammaged";
//_unit removealleventhandlers "hit";
_unit addEventHandler ["handleDamage", {_this call FUNC(heli_hd)}];

_s = damage _unit;
//variables to later store damage set with 'sethit' as there's no 'gethit'

_unit setvariable ["ace_damage_engine",_s];
_unit setvariable ["ace_damage_hull",_s];
_unit setvariable ["ace_damage_turret",_s];
_unit setvariable ["ace_damage_gun",_s];
_unit setvariable ["ace_damage_fuel",_s];

_unit setvariable ["ace_damage_avionics",_s];
_unit setvariable ["ace_damage_vrotor",_s];
_unit setvariable ["ace_damage_hrotor",_s];

//vehicle capabilities vars
_unit setvariable ["ace_canmove",true];
_unit setvariable ["ace_canshoot",true];

//is on fire
_unit setvariable ["ace_onfire",false];

//support for non-standard selection names

_s = _unit getvariable "ace_name_engine";
if (isNil "_s") then {
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitengine">>"name");
	_unit setvariable ["ace_name_engine",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hithull">>"name");
	_unit setvariable ["ace_name_hull",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitfuel">>"name");
	_unit setvariable ["ace_name_fuel",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitavionics">>"name");
	_unit setvariable ["ace_name_avionics",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitvrotor">>"name");
	_unit setvariable ["ace_name_vrotor",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hithrotor">>"name");
	_unit setvariable ["ace_name_hrotor",_s];

	_s = tolower getText(__unitcfg>>"Turrets">>"MainTurret">>"hitpoints">>"hitturret">>"name");
	_unit setvariable ["ace_name_turret",_s];
	_s = tolower getText(__unitcfg>>"Turrets">>"MainTurret">>"hitpoints">>"hitgun">>"name");
	_unit setvariable ["ace_name_gun",_s];
};