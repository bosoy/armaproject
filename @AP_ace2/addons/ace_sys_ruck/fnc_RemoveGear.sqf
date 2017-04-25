/*
Function: ACE_fnc_RemoveGear

Description:
	Remove gear from Ruck or Weapon on Back.

Parameters:
	_unit - Unit owning the gear. [Object]
	_type - Type to remove [String]
		"WEP" - Remove all Weapons from Ruck {_class,_count can be specified}
		"MAG" - Remove all Magazines from Ruck {_class,_count can be specified}
		"BTH" - Remove everything from Ruck
		"WOB" - Remove Weapon on Back
		"ALL" - Remove WOB and everything from Ruck
	_class - Specific class to remove (Optional) [String]
	_count - Amount to remove, defaults to >> 1 <<, >> -1 << for all (Optional) [Number]
Returns:
	BOOL - Successfully removed or not

Example:
	(begin example)
		[player, "BTH"] call ACE_fnc_RemoveGear;
	(end)
	(begin example)
		[player, "MAG", "ACE_5Rnd_762x51_T_M24"] call ACE_fnc_RemoveGear;
	(end)
	(begin example)
		[player, "WEP", "ACE_M4A1_ACOG", -1] call ACE_fnc_RemoveGear;
	(end)

Author:
	tcp, (c) 2010
*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_return", "_wob"];
PARAMS_2(_unit,_type);
DEFAULT_PARAM(2,_class,"");
DEFAULT_PARAM(3,_count,1);

_return = false;
switch (toUpper _type) do {
	case "WEP": {
		if (_class == "") then {
			_unit setVariable ["ACE_RuckWepContents", []];
			_return = true;
		} else {
			_return = [_unit, _class, _count] call FUNC(RemoveWepFromRuck);
		};
	};
	case "MAG": {
		if (_class == "") then {
			_unit setVariable ["ACE_RuckMagContents", []];
			_return = true;
		} else {
			_return = count ([_unit, _class, _count] call FUNC(RemoveMagFromRuck)) > 0;
		};
	};
	case "BTH": {
		_unit setVariable ["ACE_RuckWepContents", []];
		_unit setVariable ["ACE_RuckMagContents", []];
		_return = true;
	};
	case "WOB": {
		_wob = _unit getVariable ["ACE_weapononback",""];
		if (_wob != "") then {
		    if (_class == "") then {
				_unit setVariable ["ACE_weapononback", "", true];
				_return = true;
			} else {
				if (_wob == _class) then {
				    _unit setVariable ["ACE_weapononback", "", true];
					_return = true;
				};
			};
		};
	};
	case "ALL": {
		_unit setVariable ["ACE_RuckWepContents", []];
		_unit setVariable ["ACE_RuckMagContents", []];
		_unit setVariable ["ACE_weapononback", "", true];
		_return = true;
	};
	default {
		ERROR("Invalid Parameter");
	};
};

_return;
