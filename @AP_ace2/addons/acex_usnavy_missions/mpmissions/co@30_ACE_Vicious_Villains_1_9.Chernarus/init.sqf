diag_log format ["############################# %1 #############################", missionName];
ace_sys_tracking_markers_enabled = false;

setViewDistance 1400;
setterraingrid 50;

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

execVM "revive_init.sqf";

x_addkilledhandler = [east,resistance,civilian];

ari_type = "";

if (isServer) then {
	execVM "x_scripts\x_serverinit.sqf";
};

if (true) exitWith {};