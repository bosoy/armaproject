#define THIS_FILE "x_revive.sqf"
#include "xr_macros.sqf";

// playable units, var name as string that can be revived
if (!isDedicated) then {
	if !("TT" in d_version) then {
		GVARXR(player_entities) = d_player_entities;
	} else {
		GVARXR(player_entities) = d_entities_tt;
	};
} else {
	GVARXR(player_entities) = [];
};

// units that can revive, use var name as string like in player entities or empty array so that anybody can revive
// if a unit can't revive another one it can at least enhance the lifetime with CPR menu entry
GVARXR(can_revive) = if (d_only_medics_canrevive == 0) then {
	if !("TT" in d_version) then {
		["alpha_6", "bravo_6", "charlie_6", "echo_6"]
	} else {
		switch (d_player_side) do {
			case west: {["west_6", "west_17"]};
			case east: {["east_6", "east_17"]};
		};
	}
} else {
	[]
};

// set max lives to -1 to have unlimited lives
if (isNil QGVARXR(max_lives)) then {
	GVARXR(max_lives) = 30;
};

// show markers on map where unit died
GVARXR(with_marker) = true;

// life time once unconscious
if (isNil QGVARXR(lifetime)) then {
	GVARXR(lifetime) = 300;
};

// map click respawn available after x seconds, -1 for immedeate respawn
if (isNil QGVARXR(respawn_available_after)) then {
	GVARXR(respawn_available_after) = 120;
};

// list players only if they are x meters avway
GVARXR(near_player_dist) = 250;

// respawn available when no other players in near_player_dist
GVARXR(near_player_dist_respawn) = true;

// respawn with weapons, set to false because Dom handles it internally
GVARXR(withweaponrespawn) = false;

// respawn markers (respawn positions) 
if !("TT" in d_version) then {
	GVARXR(respawn_markers) = ["base_spawn_1", "mobilerespawn1", "mobilerespawn2"];
} else {
	GVARXR(respawn_markers) = switch (d_player_side) do {
		case west: {["base_spawn_1", "mobilerespawn1", "mobilerespawn2"]};
		case east: {["base_spawn_2", "mobilerespawnE1", "mobilerespawnE2"]};
	};
};

// set the number of bonus lifes a player gets when he revives another player, 0 to disable it
GVARXR(help_bonus) = 1;

// if set to false no "x was revived by y" message will show up
GVARXR(revivemsg) = true;

// set to true to use follow cam instead of normal red uncon screen
// red uncon screen disabled and not available in Dom!
GVARXR(followcam) = true;

// set to true to remove the primary and secondary weapon of a dead unit (if weapon respawn is enabled)
GVARXR(dead_removeweapon) = false;

// if set to true internal respawn dialog won't get used
GVARXR(no_respawn_dialog) = true;

// if a player can not revive another unit he can at least use CPR. cpr_time_add gets added to the other units livetime
GVARXR(cpr_time_add) = 300;

// selfheals, how often a player can heal himself (0 = disabled)
GVARXR(selfheals) = 1;
// if selfheals is enabled then if damage player >= 0.3 and <= 0.7 the action shows up
GVARXR(selfheals_minmaxdam) = [0.3, 0.7];

// uncon units cry (like babies :D)
GVARXR(withSounds) = true;

__ccppfln(x_revive\xr_functions.sqf);
__ccppfln(x_revive\xr_main.sqf);

execVM "x_revive\xr_init.sqf";
