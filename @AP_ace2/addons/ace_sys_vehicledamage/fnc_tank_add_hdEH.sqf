//#define DEBUG_MODE_FULL
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#include "script_component.hpp"
private ["_s"];
PARAMS_1(_unit);
if !([_unit] call FUNC(enabled)) exitWith {};
TRACE_2("Adding HDEH to unit",_this,local (_this select 0));
_unit setVariable [QGVAR(hdeh), _unit addEventHandler ["handleDamage", {_this call FUNC(tank_hd)}]];
(vehicle _unit) allowCrewInImmobile true;
//(_this select 0) addEventHandler ["hit", {[format["%1",_this]] call CBA_fnc_debug}];

_s = damage _unit;
//variables to later store damage set with 'sethit' as there's no 'gethit'

_unit setvariable ["ace_damage_engine",_s];
_unit setvariable ["ace_damage_hull",_s];
_unit setvariable ["ace_damage_turret",_s];
_unit setvariable ["ace_damage_gun",_s];
_unit setvariable ["ace_damage_ltrack",_s];
_unit setvariable ["ace_damage_rtrack",_s];

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
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitltrack">>"name");
	_unit setvariable ["ace_name_ltrack",_s];
	_s = tolower getText(__unitcfg>>"hitpoints">>"hitrtrack">>"name");
	_unit setvariable ["ace_name_rtrack",_s];
	_s = tolower getText(__unitcfg>>"Turrets">>"MainTurret">>"hitpoints">>"hitturret">>"name");
	_unit setvariable ["ace_name_turret",_s];
	_s = tolower getText(__unitcfg>>"Turrets">>"MainTurret">>"hitpoints">>"hitgun">>"name");
	_unit setvariable ["ace_name_gun",_s];
};
