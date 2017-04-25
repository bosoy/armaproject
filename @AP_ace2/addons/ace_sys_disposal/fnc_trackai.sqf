// Script by Inkompetent & zGuba A.D. 2009

#include "script_component.hpp"

#define __cfgWeapon configFile >> "CfgWeapons" >> _weapon

private ["_weapon", "_magazine", "_unitsArray", "_delay"];

while {true} do {
	if (!isServer) then {
		waitUntil {sleep 5; player == leader (group player)};	// not a priority.
	};
	_unitsArray = if (isServer) then {allUnits} else {units (group player)};
	_delay = 10 / ((count _unitsArray) + 1);
	{
		if (local _x && {!isPlayer _x}) then {
			_iter = _x getVariable [QGVAR(nextcheck), 0];
			if (_iter == 0) then {
				_x setVariable [QGVAR(nextcheck), 10 + (floor (random 15))];
				_weapon = secondaryWeapon _x;
				if ((getNumber (__cfgWeapon >> "ace_disposable") == 1) && {((getNumber (__cfgWeapon >> "ace_disposable_needpart") == 0) || {((getNumber (__cfgWeapon >> "ace_disposable_needpart") == 1) && {(getText (__cfgWeapon >> "ace_disposable_neededpart") in (weapons _x))})})}) then {
					_magazine = (getArray (__cfgWeapon >> "magazines")) select 0;
					if !(_magazine in (magazines _x)) then {	// Add  "magazine"
						_x removeWeapon _weapon;
						_x addMagazine _magazine;
						_x addWeapon _weapon;
					};

					if ({_x == _magazine} count (magazines _x) > 1) then {	// Remove unneeded "magazines"
						_x removeMagazine _magazine;
					};
				} else {
					_unit = _x;
					{	// Remove unneeded "magazines"
						if (getNumber (configFile >> "CfgMagazines" >> _x >> "ace_disposable") == 1) then {
							_unit removeMagazines _x;
						};
					} forEach (magazines _x);
				};
			} else {
				_x setVariable [QGVAR(nextcheck), _iter - 1];
			};
			sleep _delay;	// Smooth forEach
		};
	} forEach _unitsArray;
	sleep 5;
};
