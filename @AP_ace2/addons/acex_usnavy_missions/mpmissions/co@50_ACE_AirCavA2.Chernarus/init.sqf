diag_log format ["############################# %1 #############################", missionName];
ace_sys_tracking_markers_enabled = false;

setViewDistance 1600;
setterraingrid 50;
//enableEnvironment false;

if (isServer) then {
	if (!isNil "param1") then {
		switch (param1) do {
			case 1: {skipTime 5};
			case 2: {skipTime 12};
			case 3: {skipTime 19};
		};
	} else {
		skipTime 9;
	};
	ace_sys_aitalk_enabled = true;
	publicVariable "ace_sys_aitalk_enabled";
	ace_sys_aitalk_radio_enabled = true;
	publicVariable "ace_sys_aitalk_radio_enabled";
};

if (isServer) then {
	BIS_fnc_arrayPush = compile preprocessFileLineNumbers "\ca\modules\Functions\arrays\fn_arrayPush.sqf";
};

X_INIT = false;
X_Server = false; X_Client = false; X_JIP = false;X_SPE = false;

X_MP = isMultiplayer;

if (isServer) then {
	X_Server = true;
	if (!isdedicated) then {
		if (!(isNull player)) then {X_Client = true;X_SPE = true;};
	};
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
x_lock_spawned = true;

if (!isNil "param2") then {
	x_chopprespawn = if (param2 == 1) then {true} else {false};
} else {
	x_chopprespawn = true;
};

ari_type = "";

if (isServer) then {
	execVM "x_scripts\x_serverinit.sqf";
	ari_available = true; publicVariable "ari_available";
	"ari_type" addPublicVariableEventHandler {
		(_this select 1) execVM "x_arifire.sqf";
	};
	konvoy_killed = 0;
	//k1 addEventHandler ["killed",{konvoy_killed = konvoy_killed + 1}];
	//k2 addEventHandler ["killed",{konvoy_killed = konvoy_killed + 1}];
	k3 addEventHandler ["killed",{konvoy_killed = konvoy_killed + 1}];
	k4 addEventHandler ["killed",{konvoy_killed = konvoy_killed + 1}];
	k5 addEventHandler ["killed",{konvoy_killed = konvoy_killed + 1}];
	//k6 addEventHandler ["killed",{konvoy_killed = konvoy_killed + 1}];

	{
		_x spawn {
			private ["_t"];
			_t = _this;
			waitUntil {!(_t call ace_v_alive)};
			konvoy_killed = konvoy_killed + 1;
		};
	} forEach [k1,k2,k6];

	[herc,120] execVM "x_scripts\x_vehirespawn2H.sqf";
	[herc1,120] execVM "x_scripts\x_vehirespawn2H.sqf";
	[ch1,120] execVM "x_scripts\x_vehirespawn2H.sqf";
	[ch2,120] execVM "x_scripts\x_vehirespawn2H.sqf";
	[ch3,120] execVM "x_scripts\x_vehirespawn2H.sqf";
	[ch4,120] execVM "x_scripts\x_vehirespawn2H.sqf";

	ah1 addeventhandler ["getin", {_this execVM "x_scripts\x_checkhelipilot.sqf"}];
	ah2 addeventhandler ["getin", {_this execVM "x_scripts\x_checkhelipilot.sqf"}];

	[laz1, 240] execVM "x_scripts\x_mashrespawn.sqf";
	[laz2, 240] execVM "x_scripts\x_mashrespawn.sqf";
	[laz3, 240] execVM "x_scripts\x_mashrespawn.sqf";
	[laz4, 240] execVM "x_scripts\x_mashrespawn.sqf";

	[hmmwv1,160] execVM "x_scripts\x_vehirespawn2.sqf";
	[hmmwv2,160] execVM "x_scripts\x_vehirespawn2.sqf";
	[hmmwv3,160] execVM "x_scripts\x_vehirespawn2.sqf";
	[hmmwv4,160] execVM "x_scripts\x_vehirespawn2.sqf";
	[hmmwv5,160] execVM "x_scripts\x_vehirespawn2.sqf";
	[hmmwv6,160] execVM "x_scripts\x_vehirespawn2.sqf";

	[mot1,200] execVM "x_scripts\x_vehirespawn.sqf";
	[mot2,200] execVM "x_scripts\x_vehirespawn.sqf";
	[mot3,200] execVM "x_scripts\x_vehirespawn.sqf";
	[mot4,200] execVM "x_scripts\x_vehirespawn.sqf";
	[mot5,200] execVM "x_scripts\x_vehirespawn.sqf";
	[mot6,200] execVM "x_scripts\x_vehirespawn.sqf";
	[mot7,200] execVM "x_scripts\x_vehirespawn.sqf";
};

if (true) exitWith {};