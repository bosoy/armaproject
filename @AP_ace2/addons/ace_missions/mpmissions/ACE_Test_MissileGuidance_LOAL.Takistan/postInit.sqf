#include "script_component.hpp"

if (isDedicated) exitWith {};

_actionIndex = [["Open Spectator", "\x\ace\addons\sys_spectator\fnc_startSpectator.sqf"]] call CBA_fnc_addPlayerAction;
_actionIndex = [["Switch debug", "action.sqf"]] call CBA_fnc_addPlayerAction;
_actionIndex = [["Switch missileCam", "action2.sqf"]] call CBA_fnc_addPlayerAction;

setViewDistance 5000;

FUNC(fired) = {
	private ["_obj"];
	PARAMS_5(_unit,_bla1,_bla2,_bla3,_ammo);
	if !(isNil "ace_test_debug_disabled") exitWith {};
	if !((_ammo isKindOf "ShellBase") || (_ammo isKindOf "MissileBase")) exitWith {};
	_obj = nearestObject [_unit, _ammo];
	if !(isNull _obj) then { [_obj] spawn ACE_fnc_track };
};

FUNC(fired2) = {
	if (isNil 'ace_test_debug2_enabled') exitWith {};
	if !(player in crew (_this select 0)) exitWith {};
	[_this select 0, _this select 5] spawn ACE_fnc_bulletCam;
};

[] spawn {
	while {true} do {
		sleep 15;
		waitUntil {alive player && vehicle player != player};
		(vehicle player) setVehicleAmmo 1;
	};
};