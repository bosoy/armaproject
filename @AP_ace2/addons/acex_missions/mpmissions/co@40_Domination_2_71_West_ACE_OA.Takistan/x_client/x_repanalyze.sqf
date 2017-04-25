// by Xeno
#define THIS_FILE "x_repanalyze.sqf"
#include "x_setup.sqf"
private ["_aid","_caller","_coef","_damage","_damage_val","_estimated_time","_fuel","_fuel_val","_rep_count","_this","_type_name"];

_caller = _this select 1;
_aid = _this select 2;

if !(local _caller) exitWith {};

#ifdef __ACE__
if (GVAR(objectID2) isKindOf "Tank" || GVAR(objectID2) isKindOf "Wheeled_APC") exitWith {hint (localize "STR_DOM_MISSIONSTRING_322")};
#endif

_rep_count = switch (true) do {
	case (GVAR(objectID2) isKindOf "Air"): {0.1};
	case (GVAR(objectID2) isKindOf "Tank"): {0.2};
	default {0.3};
};

_fuel = fuel GVAR(objectID2);
_damage = damage GVAR(objectID2);

_damage_val = _damage / _rep_count;
_fuel_val = (1 - _fuel) / _rep_count;
_coef = switch (true) do {
	case (_fuel_val == _damage_val): {_damage_val};
	case (_fuel_val > _damage_val): {_fuel_val};
	default {_damage_val};
};
_coef = ceil _coef;
_estimated_time = _coef * 3;

_type_name = [typeOf (GVAR(objectID2)),0] call FUNC(GetDisplayName);
hintSilent format [(localize "STR_DOM_MISSIONSTRING_323"),_fuel, _damage,_estimated_time,_type_name];