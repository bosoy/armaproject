/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// drops all ruck items into a way so that others may retrieve

PARAMS_1(_unit);
private ["_weapon_on_back", "_magAry", "_wepAry"];

// Post a lock to inhibit multi-threads.
if ( isNil {_unit getVariable "ace_sys_ruck_fnc_killedEH_handled"} ) then {
	_unit setVariable [QGVAR(killedEH_handled), true];

// Must grab initial info before respawn
	_weapon_on_back = _unit getVariable ["ACE_weapononback", ""];
	_magAry = _unit getvariable ["ACE_RuckMagContents", []];
	_wepAry = _unit getvariable ["ACE_RuckWepContents", []];

// For use by respawn scripts, accessed via API
	_unit setvariable ["ACE_RuckMagContents_last", _magAry];
	_unit setvariable ["ACE_RuckWepContents_last", _wepAry];
	_unit setvariable ["ACE_weapononback_last", _weapon_on_back];

	[_unit,_weapon_on_back,_magAry,_wepAry] spawn {
		PARAMS_4(_unit,_weapon_on_back,_magAry,_wepAry);
		sleep 1.0; //required wait for respawn scripts
// Weapon on back added to dead body gear.
		if ( _weapon_on_back != "" && {isClass (configFile >> "cfgWeapons" >> _weapon_on_back)} ) then {
			_unit addweapon _weapon_on_back;
		};

// Track ruck contents (various dead dropped ruck functions)
		//[_unit,_magAry,_wepAry] call FUNC(contRuck); // disabled, to use interaction menu instead --Robalo
// Unlock
		_unit setVariable [QGVAR(killedEH_handled), Nil];
	};
};
