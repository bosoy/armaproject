//#define DEBUG_MODE_FULL
/*
ACE sys_destruction killed EH by Maddmatt
*/
#include "script_component.hpp"
private ["_aceVDS","_int","_size"];

PARAMS_1(_veh);
_typev = typeOf _veh;
TRACE_1("type _veh",_typev);
if (isNull _veh) exitWith {};
if !(local _veh) exitWith {};	// in case somebody forgets to precheck it.
if (getNumber (configFile >> "CfgVehicles" >> typeOf _veh >> QGVAR(no_killed_fx)) == 1) exitWith {};	// fix for exploding parachutes

// Run only once. Handle respawn, not sure if necessary.
if !(isNil {_veh getVariable "ace_sys_destruction_killed"}) exitWith {
	TRACE_1("!(isNil {_veh getVariable ace_sys_destruction_killed})",_veh);	
	_prevTime = _veh getVariable "ace_sys_destruction_killed";
	if (time - _prevTime > 10) then {
		_veh setVariable ["ace_sys_destruction_killed",nil];
		_veh call FUNC(killed);
	}; 
};
_veh setVariable ["ace_sys_destruction_killed",time];

// Aircraft FX
if (_veh iskindof "helicopter" || {_veh iskindof "plane"}) then {
	[QGVAR(AirDestruction), _veh] call CBA_fnc_globalEvent;
};

if (fuel _veh <= 0) exitWith {
	TRACE_1("fuel _veh <= 0, exiting",_veh);
};

// Disable vanilla secondaries if ACE VDS supports vehicle.
_aceVDS = false;
if !(isNil "ace_sys_vehicledamage_enabled") then {
	if (ace_sys_vehicledamage_enabled) then {
		_aceVDS = _veh call ace_sys_vehicledamage_fnc_enabled;
	};
};

if (_aceVDS) exitWith {
	TRACE_1("_aceVDS, exiting",_veh);
};

_cfg = configFile >> "CfgVehicles" >> typeOf _veh;

 // Secondary check... needed? Anyone creates non Man-based classes with simulation = "soldier" ? :D
if (toLower(getText(_cfg >> "simulation")) == "soldier") exitWith {
	TRACE_1("sumlation soldier check, exiting",_veh);
};

// Don't explode if not burning.
if !(isClass(_cfg >> "DestructionEffects" >> "Fire1") || {isClass(_cfg >> "DestructionEffects" >> "Fire2")}) exitWith {
	TRACE_1("Fire1 and Fire2 check, exiting",_veh);
};

_size = sqrt(sizeOf (typeOf _veh));

// Burning ammo explodes, but not weaponholders.
if (_veh isKindOf "ReammoBox" && {!(_veh isKindOf "WeaponHolder")}) exitWith {
	TRACE_1("Reammobox, exiting",_veh);
	[QGVAR(engineBurn), [_veh]] call CBA_fnc_globalEvent;
};

_int = 1;

if (_veh iskindof "tank") then {
	_int = (fuel _veh) * (2 + random 2);
};

if (_veh iskindof "car" || {_veh iskindof "ship"}) then {
	_int = (fuel _veh) * (2 + random 1);
	//Possible initial explosion
	if ((random _int) > 2.2) then {
		"SmallSecondary" createvehicle (getpos _veh);
	};
};

// [_veh, _int] spawn FUNC(secondaries);
// Replaced engine burner for cars and tanks that don't support vds
[QGVAR(Burn), [_veh,(2.0 + (_size * sqrt(_int))) min 10,time,true,true]] call CBA_fnc_globalEvent;
// todo: don't use FX if cfg flames are visible?

// TODO: The length of burning seems to be related to the amount of fuel (capacity * current fuel level perhaps)

// TODO: Use MPKilledEH so no need for globalEvent
TRACE_1("Burn",_veh);
if (_int >= 1) then {[QGVAR(engineBurn), [_veh]] call CBA_fnc_globalEvent};
