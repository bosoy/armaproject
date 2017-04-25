/* ace_sys_spacebar | (c) 2009 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"
private ["_target", "_type"];

_target = _this;
_type = "EXIT";

if (ace_sys_spectator_SPECTATINGON) exitWith {_type};

if (_target isKindOf "CaManBase" || {_target isKindOf "StaticWeapon"}) exitWith {"MAN"};

if ((_target isKindOf "Car" || {_target isKindOf "Air"} || {_target isKindOf "Ship"}) && {!(_target isKindOf "Wheeled_APC")}) exitWith {"VEHICLE"};

if (_target isKindOf "Tank" || {_target isKindOf "Tracked_APC"} || {_target isKindOf "Wheeled_APC"}) exitWith {"TANK"};

if (_target isKindOf "Reammobox") then {
	if (_target isKindOf "ACE_Rucksack_crate") exitWith {
		_type = "RUCK";
	};
	if !(_target isKindOf "ACE_Explosive_Object") exitWith {
		_type = "AMMO";
	};
	
};
_type
