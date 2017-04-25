//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __MEDS_LOWER ["ace_medkit","ace_bandage","ace_largebandage","ace_morphine","ace_epinephrine","ace_tourniquet"]

PARAMS_1(_unit);
private ["_weps","_mags"];

_weps = [configFile >> "CfgVehicles" >> (typeOf _unit) >> "ACE" >> QUOTE(COMPONENT) >> "weapons", "array", []] call CBA_fnc_getConfigEntry;
_mags = [configFile >> "CfgVehicles" >> (typeOf _unit) >> "ACE" >> QUOTE(COMPONENT) >> "magazines", "array", []] call CBA_fnc_getConfigEntry;
TRACE_3("Reading ACE Ruck content from config",_unit,_weps,_mags);

{
	if (isClass (configFile >> "CfgWeapons" >> _x)) then {
		[_unit, _x] call ACE_fnc_PackWeapon;
	};
} forEach _weps;

{
	if (isClass (configFile >> "CfgMagazines" >> _x)) then {
		if (!isNil "ace_sys_wounds_fnc_medGearEnabled" && {toLower(_x) in __MEDS_LOWER}) then {
			 if (_unit call ace_sys_wounds_fnc_medGearEnabled) then {	[_unit, _x] call ACE_fnc_PackMagazine };
		} else { [_unit, _x] call ACE_fnc_PackMagazine };
	};
} forEach _mags;
