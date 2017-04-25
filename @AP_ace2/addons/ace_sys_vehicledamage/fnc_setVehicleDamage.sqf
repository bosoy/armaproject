/*
Function: ACE_fnc_setVehicleDamage

Description:
	Apply damage to a vehicle in a fashion compatable with ACE vehicle damage system.
	Must be called from machine where target vehicle is local.

Parameters:
	_vehicle - Vehicle to damage [Object]
	_ammotype - Weapon to detonate [String]
	_position - Location of weapon above terrain level when damage occurred, for direction calculations [Position3D]
	_blast_damage - Blast damage in BIS indirect fire units [Number]
	_thermal_damage - Thermal damage in BIS indirect fire units [Number]
	_rad_damage - Radiation damage in BIS indirect fire units [Number]

Returns:
	nil

Example:
	(begin example)
		[_poortank, "BombCore", (getPosATL _bomb), 250, 0, 0] spawn ACE_fnc_setVehicleDamage
	(end)

Author:
	q1148 (c) 2010
*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_6(_unit,_ammo,_pos,_blast,_thermal,_rad);

#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

private["_hitr","_type","_p","_armor","_partarmor","_prevdamage","_newpartdamage","_newpartdamage1","_s","_t","_dparts","_wh"];

if !(alive _unit) exitwith {};
if !(local _unit) exitwith {};
if (getNumber(__unitcfg >> "ace_dmgsys_enable") != 1 ) exitwith {};

switch (true) do {
	case (_unit isKindOf "Tank"): {
		_type = ["turret","hull","engine"] select (random (round 2));
		_unit setvariable ["ace_hitpart",[_type,_blast,0.5,0.5]];
		_unit setvariable ["ace_dparts",[_blast,_blast,_blast,_blast,_blast,_blast]];
		_s = [_unit,"",0.5,objNull,_ammo] spawn FUNC(tank_setfx);
	};
	case (_unit isKindOf "Wheeled_APC"): {
		_armor = getNumber (__unitcfg >> "armor");
		_wh = [];
		{
			_hitr = (0.7 + random 0.6)*_blast;
			_partarmor = getNumber (__unitcfg >> "hitpoints" >> ("hit"+_x) >> "armor");
			_newpartdamage1 = _hitr/(_partarmor*_armor);
			_prevdamage = _unit getvariable ("ace_damage_"+_x);
			_partdamage = _newpartdamage1 + _prevdamage;
			_wh set [(count _wh),[_x,_hitr,_partdamage,_newpartdamage1]];
		} foreach ["lfwheel","lf2wheel","lmwheel","lbwheel","rfwheel","rf2wheel","rmwheel","rbwheel"];
		_unit setvariable ["ace_d_wheels",_wh];
		_wh = [];
		{
			_hitr = (0.7 + random 0.6)*_blast;
			if (_x == "turret") then {
				_partarmor = getNumber (__unitcfg >> "Turrets" >> "MainTurret" >> "hitpoints" >> "hitturret" >> "armor");
			} else {
				if (isNumber (__unitcfg >> "hitpoints" >> ("hit"+_x) >> "armor")) then {
					_partarmor = getNumber (__unitcfg >> "hitpoints" >> ("hit"+_x) >> "armor");
				} else {
					_partarmor = 0.5;
				};
			};
			_newpartdamage1 = _hitr/(_partarmor*_armor);
			_prevdamage = _unit getvariable ("ace_damage_"+_x);
			_partdamage = _newpartdamage1 + _prevdamage;
			_wh set [(count _wh),[_x,_hitr,_partdamage]];
		} foreach ["turret","engine","fuel"];
		_unit setvariable ["ace_d_parts",_wh];
		_s = [_unit,"",0.5,objNull,_ammo] spawn FUNC(wAPC_setfx);
	};
	default {};
};
