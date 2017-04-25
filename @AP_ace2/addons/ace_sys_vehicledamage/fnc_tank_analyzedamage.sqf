//post-processing damage

#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

PARAMS_3(_unit,_part,_injurer);

//["Analyzing damage"] call CBA_fnc_debug;
if (! alive _unit) exitwith {};

private["_canmove","_canshoot","_ko"];

_ko = _unit getvariable ["ace_ko",false];
if (_ko) exitwith {};
_canmove = _unit getvariable ["ace_canmove",false]; 	// Assume false if not set
_canshoot = _unit getvariable ["ace_canshoot",true];	// Assume true if not set

//mark as knocked out if seriously damaged and empty - prevents AI from shooting at abndnd vhcls
//atm just kill it if AI is shooting to prevent wasting ammo
if ((!_canmove || {!_canshoot}) && {(count(crew _unit)==0)}) exitwith {
	if (!(isplayer _injurer) && {!isNull _injurer}) then {_unit spawn FUNC(set_ko)};
};

_canmove = _canmove && {(alive (driver _unit))};
_canshoot = _canshoot && {(alive (gunner _unit))};


/*
// deploy smoke - disabled as only blinds player, not AI
if (0.3 > random 1) then
{
	[_unit,_injurer] spawn FUNC(tank_deploysmoke);
};
*/

//abandon or flee if srsly damaged
switch (true) do {
	case (!_canmove && {!_canshoot}): { //sitting duck
		_unit spawn FUNC(tank_abandon); //player sidechat "leave sitting duck";
	};
	case (!_canmove && {_canshoot}): { //still can fight, keep shooting or abandon
		if ((_unit skill "courage") < random 1) then {
			_unit spawn FUNC(tank_abandon);
		}; /* else { // Make car driver eject to defend lololol
			if (alive driver _unit) then {
				[driver _unit] joinSilent grpNull;
				unassignVehicle (driver _unit);
				moveout (driver _unit);
			};
			if (alive gunner _unit) then {
				(gunner _unit) assignAsGunner _unit;
			};
		};*/
		//player sidechat "cannot move but canshoot";
	};
	case (_canmove && {!_canshoot}): { //still can move, flee or abandon
		if (0.5 > random 1) then {
			_unit spawn FUNC(tank_abandon);
		} else {
			_unit allowfleeing 1;
		};
		//player sidechat "cannot shoot but canmove";
	};
	default {};
};
sleep 1;
if (count (crew _unit) == 0) then {
	if (!(isplayer _injurer) && {!isNull _injurer}) then {_unit spawn FUNC(set_ko)};
};

// + influence commander's courage if hit but not too damaged?
