/*
Function: ACE_fnc_PackMagazine

Description:
	Pack a magazine into a ruck, performing checks to see if it fits.

Parameters:
	_unit - Unit owning ruck to pack magazine into. [Object]
	_magazine - Class name of magazine to pack. [String]
	_count - number of magazines to pack ( Optional, default 1). [Number]
	_ammocount - number of rounds added to the magazine(s) (Optional, default -1) [Number]

Returns:
	"true" if has all items packed or "false" if not. [Boolean]

Example:
	(begin example)
		_success = [BOB, "ACE_33Rnd_9x19_G18", 4] call ACE_fnc_PackMagazine;
	(end)

Author:
	tcp, (c) 2010
*/


//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// arguments: [_unit, _magazine, _count] (_count is optional )

PARAMS_2(_unit,_magazine);
DEFAULT_PARAM(2,_count,1);
DEFAULT_PARAM(3,_ammocount,-1); // -1 = default max ammo from CfgMagazines

private ["_packable","_confNonPackable","_confDisposable"];

_packable = true;
_count = floor _count;

if ( _count > 0 ) then {
	_confNonPackable = configFile >> "CfgMagazines" >> _magazine >> "ACE_NoPack";
	if (getNumber(_confNonPackable) == 1) then {
		TRACE_1("Non-packable magazine", _magazine);
		_packable = false;
	} else {
		_confDisposable = configFile >> "CfgMagazines" >> _magazine >> "ace_disposable";
		if (getNumber(_confDisposable) == 1) then {
			TRACE_1("Disposable magazine", _magazine);
			_packable = false;
		};
	};

	if ( _packable ) then {
		if ( _unit call FUNC(hasRuck) && {!([_unit, _magazine, false, _count] call FUNC(FitsInRucksack))} ) then {
			//^ still allow if ruck hasn't had a chance to be added during first frame of initialization, ruck overflow has handling anyways
			TRACE_1("Too big", _magazine);
			_packable = false;
		};
	};
};

if ( _packable ) then {
	TRACE_3("Packing...", _unit, _magazine, _count);
	[_unit, _magazine, _count, _ammocount] call FUNC(AddMagToRuck);
};

_packable
