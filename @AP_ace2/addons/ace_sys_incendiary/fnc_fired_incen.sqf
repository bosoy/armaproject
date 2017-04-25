/* ace_sys_incendiary(.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_incen","_incen_objects"];

#define __vel (velocity _incen) call ACE_fnc_magnitude

// TODO: Popping sound
// TODO: Burning sound

_incen = _this select 6;


while {alive _incen && {!isNull _incen}} do {
	sleep .1;
	if (__vel < 0.2) exitWith { };
};
sleep 2;

_incen spawn {
	while {alive _this} do {
		[_this, 3] call ace_sys_destruction_fnc_propagateFire;
		sleep 3;
	};
};

_incen_objects = nearestObjects [getPos _incen, ["WeaponHolder"], 1]; // Not detected by nearEntities!!
_incen_statics = (position _incen) nearEntities ["StaticWeapon",1];
TRACE_1("",_incen_objects);
TRACE_1("",_incen_statics);

if (count _incen_statics == 0 && {count _incen_objects == 0}) exitWith { TRACE_1("Nothing to burn",""); };

{
	_pos_x = getPos _x;
	deleteVehicle _x;
	_debris = "ACE_IncendiaryWreck" createVehicleLocal _pos_x; // Local?
	_debris setPos _pos_x; _debris setDir (random 360);
	[_debris, 600] call ACE_fnc_add2clean;
} forEach _incen_objects;

{
	_x setDamage 1;
} forEach _incen_statics;

// Incendiary is detected as burning due to ace_fire = 1; in the config. Will be picked up by Fire damage / propagation etc.

// TODO: Disable vehicles
// TODO: Small local fires on things where it fits / is possible
// TODO: Burn damage to players -> Trigger
