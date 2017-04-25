#include "script_component.hpp"

private ["_found", "_statics"];
PARAMS_3(_unit,_radius,_forAI);

if (isPlayer _unit && {_forAI}) exitWith {false};

_found = false;
_cfg = configFile >> "CfgWeapons" >> secondaryWeapon _unit >> "ACE" >> "ACE_CREWSERVED" >> "canUseTripods";
if (isArray _cfg) then {
	_crewTripods = getArray _cfg;
	_statics = nearestObjects [_unit, ["StaticWeapon"], _radius];
	if (count _statics == 0) exitWith {};
	{
		if (typeOf _x in _crewTripods) exitWith {
			_found = true;
		};
	} forEach _statics;
};

if !(_found) then {
	_cfg = configFile >> "CfgWeapons" >> primaryWeapon _unit >> "ACE" >> "ACE_CREWSERVED" >> "canUseTripods";
	if (isArray _cfg) then {
		_crewTripods = getArray _cfg;
		_statics = nearestObjects [_unit, ["StaticWeapon"], _radius];
		if (count _statics == 0) exitWith {};
		{
			if (typeOf _x in _crewTripods) exitWith {
				_found = true;
			};
		} forEach _statics;
	};
};

_found
