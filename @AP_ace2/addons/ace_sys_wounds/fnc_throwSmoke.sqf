//unit throws smoke towards the closest known enemy (if there is one)
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __SMOKEMUZZLES ["SmokeShellMuzzle","ACE_SmokeShellMuzzle_RU","ACE_SmokeShellMuzzle_GER"]

PARAMS_1(_unit);
private ["_cant","_smokemuz","_smokeshell","_smokeveh","_thism","_pos","_dir","_throwdist","_smoke","_anim","_nearestEnemy"];

_cant = {
	private "_ret";
	_ret = _this call FUNC(isUncon) || {!alive _this};
	if (!_ret) then {
		_ret = getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState _this) >> "canPullTrigger") == 0;
	};
	_ret
};

// check for smoke
_smokemuz = "";
_smokeveh = "";
scopeName "smoke_main";
{
	_thism = _x;
	if (isArray (configFile >> "CfgWeapons" >> "Throw" >> _thism >> "magazines")) then {
		{
			if (_x in (magazines _unit)) then {
				_smokemuz = _thism; //muzzle
				_smokeshell = _x;
				_smokeveh = getText (configFile >> "CfgMagazines" >> _smokeshell >> "ammo");
				//TRACE_4("FOUND",_unit,_smokemuz,_smokeshell,_smokeveh);
				breakTo "smoke_main";
			};
		} forEach getArray(configFile >> "CfgWeapons" >> "Throw" >> _thism >> "magazines");
	};
} forEach __SMOKEMUZZLES;

if (_smokeveh == "") exitWith {};

// throw it towards closest known enemy
_nearestEnemy = _unit findNearestEnemy _unit; TRACE_2("",_unit,_nearestEnemy);
if (!isNull _nearestEnemy) then {
	if !(_unit call _cant || {isNil "_smokeshell"} || {_smokeveh == ""}) then {
		//TRACE_4("THROWING",_unit,_smokemuz,_smokeshell,_smokeveh);
		_unit doTarget _nearestEnemy;
		_unit selectWeapon _smokemuz;
		_anim = _unit call FUNC(getThrowAnim);
		_unit playMove _anim;
		_pos = position _unit;
		_dir = direction _unit;
		waitUntil {animationState _unit != _anim};
		#ifndef DEBUG_MODE_FULL
		_unit removeMagazine _smokeshell;
		#endif
		if !(_unit call _cant) then {
			_throwdist = 3 + random 6;
			_pos = [(_pos select 0) + _throwdist*sin _dir, (_pos select 1) + _throwdist*cos _dir, (_pos select 2) + 1 + random 3];
		};
		_unit doTarget objNull;
		sleep 3; _smoke = _smokeveh createVehicle _pos;
		if (!isNil "ace_sys_viewblock_fnc_fired") then {
			["","","","",_smokeveh,"",_smoke] call ace_sys_viewblock_fnc_fired;
		};
	};
};
