/* ace_sys_cartridges (.pbo) | (c) 2008, 2009, 2010 by rocko */

/* rocko_fx_cartridges.sqf | (c) 2008 by rocko

 # Creates cartridges that stay on ground, using FIFO technique and some other system #

 Mathematics, especially trigonometry, is somewhat gay in ArmA, so we cheat a little here and there to get this script roughly working.
 Feel free to improve the script, but the credits are mine, heck I got the friggin' idea for that !

*/

#include "script_component.hpp"

#define __SIMULATION configFile >> "CfgAmmo" >> _ammo >> "simulation"
#define __CARTRIDGE configFile >> "CfgAmmo" >> _ammo >> "cartridge"

#define __EXCLUDE_SIMULATION ["shotTimeBomb", "shotPipeBomb", "shotMine", "shotIlluminating", "shotSmoke", "shotRocket", "shotMissile"]

#define __EJECTLEFT ["PK", "ACE_PK", "ACE_Pecheneg", "ACE_Pecheneg_1P29", "M24", "ACE_M24", "ACE_M242", "ACE_M40A3"]
#define __SPAWN _cartridge = _casing createVehicleLocal _pos

#define __X ((_pos select 0) + (_a * (sin 360))*(cos (_dir)) + (_b * (cos 360))*(sin (_dir)))
#define __Y ((_pos select 1) + (_a * (sin 360))*(sin (_dir)) + (_b * (cos 360))*(cos (_dir)))

private ["_dir", "_a", "_b", "_ammo","_pos", "_casing_type", "_casing", "_cartridge"];
PARAMS_2(_unit,_weapon);

_ammo = _this select 4;
if (getText(__SIMULATION) in __EXCLUDE_SIMULATION) exitWith { false };

_casing_type = getText(__CARTRIDGE);
if (_casing_type == "") exitWith { false };
_casing = _casing_type + "_stay";
_pos = getposATL _unit;

_dir = (direction _unit) - 270;
//if (_weapon in __EJECTLEFT) then { _dir = (direction _unit) - 90; } else { _dir = (direction _unit) - 270; };

[_casing, _pos, _dir] spawn {
	PARAMS_3(_casing,_pos,_dir);
	sleep 0.4;
	__SPAWN;

	private ["_cartridge","_a","_b"];
	_a = 1.8 + random 0.6;
	_b = 1.8 + random 0.36;
	_cartridge setposATL [__X + (random 0.6),__Y + (random 0.6), _pos select 2];
	_cartridge setdir ((_a atan2 _b) + (random 360));
	TRACE_2("",_cartridge,_pos);
	[_cartridge, 300] call ACE_fnc_add2fifo;
};