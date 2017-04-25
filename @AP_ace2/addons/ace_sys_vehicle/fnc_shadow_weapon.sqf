#include "script_component.hpp"

// (c) 2012 by zGuba
// Fire shadow weapon defined on Fired EH.
// Add shadow weapon to be fired if needed.
 // IMPORTANT: Shadow weapon must have reloadtime = 0, magazinereloadtime = 0, and its magazine entry must match magazine classname - case sensitive.
 
PARAMS_2(_vehicle,_weapon);

private ["_gunner", "_shadowWeapon"];

if !(isText (configFile >> "CfgWeapons" >> _weapon >> "ace_shadow_weapon")) exitWith {};

_gunner = ([_vehicle, _weapon] call CBA_fnc_getFirer) select 0;

if (local _gunner) then {
	_shadowWeapon = getText (configFile >> "CfgWeapons" >> _weapon >> "ace_shadow_weapon");
//	if (_shadowWeapon == _weapon) exitWith {}; // Costful; set to number in shadow weapon instead
	_shadowMagazine = (getArray (configFile >> "CfgWeapons" >> _shadowWeapon >> "magazines")) select 0;
	if (_vehicle getVariable [QGVAR(shadow_check),0] < time) then {
		_vehicle setVariable [QGVAR(shadow_check),time + 15];
		if !(_shadowMagazine in (magazines _vehicle)) then {_vehicle addMagazine _shadowMagazine};
		if !(_vehicle hasWeapon _shadowWeapon) then {_vehicle addWeapon _shadowWeapon};
	};
	_vehicle fireAtTarget [objNull,_shadowWeapon];
};
