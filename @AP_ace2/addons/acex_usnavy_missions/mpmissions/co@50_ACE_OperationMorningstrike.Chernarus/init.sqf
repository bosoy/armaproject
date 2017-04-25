diag_log format ["############################# %1 #############################", missionName];

setterraingrid 50;

if (isServer) then {
	BIS_fnc_arrayPush = compile preprocessFileLineNumbers "\ca\modules\Functions\arrays\fn_arrayPush.sqf";
	BIS_fnc_arrayPushStack = compile preprocessFileLineNumbers "\ca\modules\Functions\arrays\fn_arrayPushStack.sqf";
	ace_sys_aitalk_enabled = true;
	publicVariable "ace_sys_aitalk_enabled";
	ace_sys_aitalk_radio_enabled = true;
	publicVariable "ace_sys_aitalk_radio_enabled";
};

XfGetAltTankStatus = {
	private ["_c", "_s"];
	_c = _this getVariable "ace_canmove";
	if (isNil "_c") then {_c = true};
	_s = _this getVariable "ace_canshoot";
	if (isNil "_s") then {_s = true};
	if (!_s && !_c) then {true} else {false}
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

"service" setMarkerAlphaLocal 0;
"combase" setMarkerAlphaLocal 0;
"aa" setMarkerAlphaLocal 0;
"artillery" setMarkerAlphaLocal 0;
"supply_depot" setMarkerAlphaLocal 0;

"main_airfield" setMarkerAlphaLocal 0;
"service2" setMarkerAlphaLocal 0;
"hq" setMarkerAlphaLocal 0;
"paradrop" setMarkerAlphaLocal 0;

x_addkilledhandler = [east];
x_lock_spawned = true;

if (isServer) then {
	execVM "x_scripts\x_serverinit.sqf";
	generators_down = 0;
	tungis_down = 0;
	firebase_killed = 0;
	officer_dead = 0;

	generator1 addEventHandler ["killed", {generators_down = generators_down + 1}];
	generator2 addEventHandler ["killed", {generators_down = generators_down + 1}];
	generator3 addEventHandler ["killed", {generators_down = generators_down + 1}];

	// tungi1 addEventHandler ["killed", {tungis_down = tungis_down + 1}];
	// tungi2 addEventHandler ["killed", {tungis_down = tungis_down + 1}];
	// tungi3 addEventHandler ["killed", {tungis_down = tungis_down + 1}];

	{
		_x spawn {
			private ["_t"];
			_t = _this;
			waitUntil {!(_t call ace_v_alive)};
			tungis_down = tungis_down + 1;
		};
	} forEach [tungi1,tungi2,tungi3];

	[] spawn {
		waituntil {!isNil "allunits_add"};
		allunits_add set [count allunits_add, generator1];
		allunits_add set [count allunits_add, generator2];
		allunits_add set [count allunits_add, generator3];
	};
	[uh1, 240] execFSM "fsms\VehicleRespawn.fsm";
	[bh1, 240] execFSM "fsms\VehicleRespawn.fsm";
	[bh2, 240] execFSM "fsms\VehicleRespawn.fsm";
	[bh3, 240] execFSM "fsms\VehicleRespawn.fsm";
	[bh4, 240] execFSM "fsms\VehicleRespawn.fsm";
	[osp1, 240] execFSM "fsms\VehicleRespawn.fsm";
	[c130_1, 280] execFSM "fsms\VehicleRespawn.fsm";
	[c130_2, 280] execFSM "fsms\VehicleRespawn.fsm";
	[bh5, 260] execFSM "fsms\VehicleRespawn.fsm";
	[bh6, 260] execFSM "fsms\VehicleRespawn.fsm";
	[osp2, 280] execFSM "fsms\VehicleRespawn.fsm";

	execVM "x_bombs1.sqf";
};

if (true) exitWith {};