#include "script_component.hpp"
/*
	by Sickboy (sb_at_dev-heaven.net)
*/

#define __scriptname bc

PREP(handleWeapons);

private ["_safeZone", "_pos", "_crate"];

_safeZone = call compile format["ace_sys_bc_safezone_%1", GETVAR(_side)];
_pos = getPos player;
_posASL = getPosASL player;
{ createMarkerLocal [_x, _pos] } forEach GVAR(start_markers); // Create markers at player position

// TODO: Fix Lame
[] spawn {
	sleep 1; sleep 1; sleep 1;
	[player] call FUNC(handleWeapons);

	while {! (GETVAR(ready)) } do {
		sleep 1;
		if !(alive player) then {
			waitUntil {alive player};
			sleep 1; sleep 1; sleep 1;
			[player] call FUNC(handleWeapons);
		};
	};
};

waitUntil { GETVAR(ready) };
// TODO: Can now actually be done in mission.hpp or globally at server ?
for "_i" from 0 to (count GVAR(startpos)) do {
	(GVAR(start_markers) select _i) setMarkerPosLocal (GVAR(startpos) select _i); // Set markers to base location
};

// Using loop for trainingMode
while { true } do {
	waitUntil { alive player };
	waitUntil { !(alive player) };

	if (GETVAR(training)) then {
		{ _x setMarkerPosLocal (GETVAR(_side) call FUNC(startpos)) } forEach GVAR(start_markers); // Set markers to base location
	} else {
		{ _x setMarkerPosLocal (getPos _safeZone) } forEach GVAR(start_markers); // Set markers to boat position
		if !(ACE_NODISABLERESPAWN) then {
			_group = [civilian] call CBA_fnc_getSharedGroup;
			[player] join _group;
			[format["PLAYER: %1, SIDE: %2, GROUP: %3, TYPEOF: %4", player, side player, group player, typeOf player], QUOTE(GVAR(__scriptname)), [false, true, false]] call CBA_fnc_debug;
		};
	};

	waitUntil { (alive player) && (player isKindOf "CAManBase") };
	[format["PLAYER: %1, SIDE: %2, GROUP: %3, TYPEOF: %4", player, side player, group player, typeOf player], QUOTE(GVAR(__scriptname)), [false, true, false]] call CBA_fnc_debug;

	if (GETVAR(training)) then {
		player setCaptive false;
		sleep 1; sleep 1; sleep 1;
		[player] call FUNC(handleWeapons);
	} else {
		player setCaptive true;
		//ACE_NoStaminaEffects = true;
		titlecut ["You Died...","BLACK OUT", 3];
		if !(ACE_NOSPECT) then {
			[] call ace_fnc_startSpectator;
		};
		sleep 1;
		sleep (random 1);
		_pos = getPos _safeZone; _pos set [2, 0.5];
		player setPos _pos;
		ACE_DEAD = true;
	};
};
