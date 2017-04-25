/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

private ["_receiver"];

PARAMS_1(_receiver);

if !(alive _receiver) exitWith {};

if (isNil "ace_sys_wounds_enabled") exitWith {};

if (_receiver call ace_sys_wounds_fnc_isUncon) exitWith {};

if ((primaryWeapon _receiver) != "") then {
	_receiver action["DropWeapon", _receiver, (primaryWeapon _receiver)];
};

if ((secondaryWeapon _receiver) != "") then {
	_receiver action["DropWeapon", _receiver, (secondaryWeapon _receiver)];
};

[QGVAR(remwe), _receiver] call ACE_fnc_receiverOnlyEvent;
