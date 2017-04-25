// by Xeno
//private ["_magazines","_p","_weapons","_primw","_muzzles","_s","_p", "_trigger","_parachute"];

waitUntil {alive player};
_p = player;
if (isNil "x_show_settings") then {x_show_settings = false;};
if (isNil "x_weapon_respawn") then {x_weapon_respawn = false;};
if (isNil "x_backpack") then {x_backpack = false;};
if (isNil "x_add_nvg") then {x_add_nvg = false;};
if (isNil "x_add_binocular") then {x_add_binocular = false;};
if (isNil "x_weapon_array") then {x_weapon_array = [];};
x_vec_hud = false;
if (isnil "x_with_revive")then{x_with_revive=false};
if (isNil "x_dynamic_weather") then {x_dynamic_weather = false};

if (x_show_settings) then {
	x_settings_action = _p addAction ["Settings", "x_scripts\x_showsettings.sqf",[],-1,false];
	_trigger = createTrigger["EmptyDetector" ,position _p];
	_trigger setTriggerArea [0, 0, 0, false];
	_trigger setTriggerActivation ["NONE", "PRESENT", true];
	_trigger setTriggerStatements["vehicle player != player", "set_vehicle = vehicle player;set_vec_id = set_vehicle addAction [""Settings"", ""x_scripts\x_showsettings.sqf"",[],-1,false];", "set_vehicle removeAction set_vec_id;set_vec_id = -1"];
};

if (x_backpack) then {
	player_backpack = [];
	prim_weap_player = primaryWeapon _p;
	pbp_id = -1;
	// No Weapon fix for backpack
	_trigger = createTrigger["EmptyDetector" ,position _p];
	_trigger setTriggerArea [0, 0, 0, false];
	_trigger setTriggerActivation ["NONE", "PRESENT", true];
	_trigger setTriggerStatements["primaryWeapon player != prim_weap_player","prim_weap_player = primaryWeapon player;if (pbp_id != -1 && count player_backpack == 0) then {player removeAction pbp_id;pbp_id = -1;};if (pbp_id == -1 && count player_backpack == 0 && prim_weap_player != """") then {pbp_id = player addAction [format [""%1 to Backpack"", prim_weap_player], ""x_scripts\x_backpack.sqf"",[],-1,false];};",""];
	_s = format ["%1 to Backpack", primaryWeapon _p];
	if (primaryWeapon _p != "") then {
		pbp_id = _p addAction [_s, "x_scripts\x_backpack.sqf",[],-1,false];
	};
};

if (x_add_nvg) then {
	if (!(_p hasWeapon "NVGoggles")) then {
		_p addWeapon "NVGoggles";
	};
};

if (x_add_binocular) then {
	if (!(_p hasWeapon "Binocular")) then {
		_p addWeapon "Binocular";
	};
};

if (!(isNil "x_show_player_marker")) then {
	if (count x_show_player_marker > 0) then {
		x_show_p_marker = true;
		[] execVM "x_scripts\x_playermarker.sqf";
	};
} else {
	x_show_player_marker = [];
};
execVM "x_scripts\weather\weatherrec2.sqf";
execVM "x_scripts\x_playerthread.sqf";
execVM "x_scripts\x_playerrespawn.sqf";

if (x_vec_hud) then {
	[] execVM "x_scripts\x_vec_hud.sqf";
};

if (true) exitWith {};