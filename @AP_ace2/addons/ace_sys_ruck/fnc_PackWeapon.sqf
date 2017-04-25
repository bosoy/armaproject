/*
Function: ACE_fnc_PackWeapon

Description:
	Pack a weapon into a ruck, performing checks to see if it fits.

Parameters:
	_unit - Unit owning ruck to pack weapon into. [Object]
	_weapon - Class name of weapon to pack. [String]
	_count - number of weapons to pack ( Optional, default 1). [Number]

Returns:
	"true" if has all items packed or "false" if not. [Boolean]

Example:
	(begin example)
		_success = [BOB, "ACE_Glock18",  2] call ACE_fnc_PackWeapon;
	(end)

Author:
	tcp, (c) 2010
*/


//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// arguments: [_unit, _weapon, _count] (_count is optional )

PARAMS_2(_unit,_weapon);
DEFAULT_PARAM(2,_count,1);

private ["_packable","_confNonPackable","_confDisposable"];

_packable = true;
_count = floor _count;

if ( _count > 0 ) then {
	_confNonPackable = configFile >> "CfgWeapons" >> _weapon >> "ACE_NoPack";
	if (getNumber(_confNonPackable) == 1) then {
		TRACE_1("Non-packable weapon", _weapon);
		_packable = false;
	} else {
		_confDisposable = configFile >> "CfgWeapons" >> _weapon >> "ace_disposable";
		if (getNumber(_confDisposable) == 1) then {
			TRACE_1("Disposable weapon", _weapon);
			_packable = false;
		};
	};

	if ( _packable ) then {
		if ( _unit call FUNC(hasRuck) && {!([_unit, _weapon, true, _count] call FUNC(FitsInRucksack))} ) then {
			//^ still allow if ruck hasn't had a chance to be added during first frame of initialization, ruck overflow has handling anyways
			TRACE_1("Too big", _weapon);
			_packable = false;
		};
	};
};

if ( _packable ) then {
	TRACE_3("Packing...", _unit, _weapon, _count);
	[_unit, _weapon, _count] call FUNC(AddWepToRuck);
};

_packable
