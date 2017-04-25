/* (c) 2010 by zGuba */
// incomingMissile EH for Longbow Hellfire and Javelin
// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfg configFile >> "CfgAmmo" >> _ammoType >> "ace_guidance_type"

PARAMS_3(_target,_ammoType,_attacker);

if !(isText(__cfg)) exitWith {};
if !(local (gunner _attacker) || {local _attacker}) exitWith {};

if !(isPlayer (gunner _attacker) || {isPlayer _attacker}) exitWith {
	_attacker setVariable [QGVAR(longbowTarget),_target];
	_attacker setVariable [QGVAR(longbowData),true];
};

switch toLower getText(__cfg) do {
	case "longbow":	{
		_attacker setVariable [QGVAR(longbowTarget),_target];
		_attacker setVariable [QGVAR(longbowData),true];
	};
	case "javelin":	{
		_attacker setVariable [QGVAR(longbowTarget),_target];
		_attacker setVariable [QGVAR(longbowData),true];
	};
};
