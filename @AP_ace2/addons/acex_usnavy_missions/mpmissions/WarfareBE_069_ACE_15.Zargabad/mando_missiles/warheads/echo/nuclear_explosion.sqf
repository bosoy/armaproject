//
// Written by Evil_Echo 
//
// Usage:
// ok = [position, weapon] ExecVM "Scripts\nuclear_explosion.sqf";
//

#include "nuke.h"
 
private [
	"_pos",
	"_yield",
	"_mode"
];

_pos    = _this select 0;
_yield = _this select 1;
_mode = "unknown";

if isNil("echo_fallout_decay_rate") then {
	echo_fallout_decay_rate = 1.0;
};

if isNil("echo_fallout_number") then {
	echo_fallout_number = 0;
	publicVariable "echo_fallout_number";
};

if (isNil "echo_logic_center") then {
	echo_logic_center = createCenter sideLogic;
	echo_logic_group = createGroup echo_logic_center;
};

if (isNil "ECHO_FalloutGL") then {
	"Logic" createUnit [[0, 0, 0], echo_logic_group, "ECHO_FalloutGL = this"];
	publicVariable "ECHO_FalloutGL";
};

if (isNil "echo_nuke_fnc_sound") then {
	echo_nuke_fnc_sound = compile preprocessFile (NUKE_PATH + "nuke_sound.sqf");
};

if (isNil "echo_nuke_fnc_shockwave") then {
	echo_nuke_fnc_shockwave = compile preprocessFile (NUKE_PATH + "nuke_shockwave.sqf");
};

if (isNil "echo_nuke_fnc_impact") then {
	echo_nuke_fnc_impact = compile preprocessFile (NUKE_PATH + "nuke_shock_impact.sqf");
};

if (isNil "echo_nuke_fnc_damage") then {
	echo_nuke_fnc_damage = compile preprocessFile (NUKE_PATH + "nuke_damage.sqf");
};

if (isNil "echo_nuke_fnc_damageNonClass") then {
	echo_nuke_fnc_damageNonClass = compile preprocessFile (NUKE_PATH + "nuke_damageNonClass.sqf");
};

if (isNil "echo_nuke_fnc_damageSectional") then {
	echo_nuke_fnc_damageSectional = compile preprocessFile (NUKE_PATH + "nuke_damageSectional.sqf");
};

if (isNil "echo_nuke_fnc_fires") then {
	echo_nuke_fnc_fires = compile preprocessFile (NUKE_PATH + "nuke_fires.sqf");
};

if (isNil "echo_nuke_fnc_cloud") then {
	echo_nuke_fnc_cloud = compile preprocessFile (NUKE_PATH + "nuke_cloud.sqf");
};

if (isNil "echo_nuke_fnc_fallout") then {
	echo_nuke_fnc_fallout = compile preprocessFile (NUKE_PATH + "nuke_fallout.sqf");
};

if ( isServer ) then {
// damage
	[_pos, _yield, _mode, echo_nuke_fnc_damageSectional, echo_nuke_fnc_fires] spawn echo_nuke_fnc_damage;

// fallout
	for "_i" from 1 to 3 do {
		[_pos, _yield, _i] spawn echo_nuke_fnc_fallout;
	};
};

if ( !isDedicated ) then {
// bang
	[_pos, _yield] spawn echo_nuke_fnc_sound;

// shock wave
	[_pos, _yield] spawn echo_nuke_fnc_shockwave;
	[_pos, _yield] spawn echo_nuke_fnc_impact;

// cloud if ground burst.
	[_pos, _yield] spawn echo_nuke_fnc_cloud;
};

[_pos, _yield] spawn echo_nuke_fnc_damageNonClass;
