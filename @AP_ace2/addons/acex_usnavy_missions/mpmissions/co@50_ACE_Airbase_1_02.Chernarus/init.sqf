diag_log format ["############################# %1 #############################", missionName];
ace_sys_tracking_markers_enabled = false;

// by Xeno

titleText ["", "BLACK FADED", 0.2];

setViewDistance 2500;
setterraingrid 50;

if (isServer) then {
	BIS_fnc_arrayPush = compile preprocessFileLineNumbers "\ca\modules\Functions\arrays\fn_arrayPush.sqf";
};

X_INIT = false;
X_Server = false; X_Client = false; X_JIP = false;X_SPE = false;

X_MP = isMultiplayer;

if (isServer) then {
	X_Server = true;
	if (!(isNull player)) then {X_Client = true;X_SPE = true;};
	X_INIT = true;
} else {
	X_Client = true;
	if (isNull player) then {
		X_JIP = true;
		[] spawn {waitUntil {!(isNull player)};X_INIT = true};
	} else {
		X_INIT = true;
	};
};

if (X_Client) then {
	[] spawn {
		waitUntil {!isNull player};
		execVM "tasks_fix.sqf";
	};
};

x_addkilledhandler = [east];
x_add_nvg = true;
x_add_binocular = true;
x_show_settings = true;
//x_weapon_respawn = true;
x_lock_spawned = true;
x_repair_service = ["ace_usarmy_sapper"];

//waitUntil {!isNil "BIS_MPF_initDone"};
//waitUntil {!isNil "BIS_fnc_init"};
//waitUntil {BIS_fnc_init};

if (isServer) then {
	execVM "x_scripts\x_serverinit.sqf";
	x_vehirespawn2 = compile preprocessFile "x_scripts\x_vehirespawn2.sqf";
	x_vehirespawn = compile preprocessFile "x_scripts\x_vehirespawn.sqf";
	x_vehirespawn2H = compile preprocessFile "x_scripts\x_vehirespawn2H.sqf";
	[markerPos "guard1", 200, 3,1,1,1,1,1,0,1,["EAST",["WEST"],800]] execVM "x_scripts\x_createpatrolgroups.sqf";
	[markerPos "guard2", 200, 3,1,1,1,1,1,0,1,["EAST",["WEST"],1600]] execVM "x_scripts\x_createpatrolgroups.sqf";
	[markerPos "guard3", 200, 3,1,1,1,1,1,0,1,["EAST",["WEST"],1200]] execVM "x_scripts\x_createpatrolgroups.sqf";
	[markerPos "guard4", 200, 3,1,1,1,1,1,0,1,["EAST",["WEST"],1200]] execVM "x_scripts\x_createpatrolgroups.sqf";
	[markerPos "guard5", 200, 3,1,1,1,1,1,0,1,["EAST",["WEST"],800]] execVM "x_scripts\x_createpatrolgroups.sqf";
};

if (true) exitWith {};