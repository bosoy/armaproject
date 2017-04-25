diag_log format ["############################# %1 #############################", missionName];

setterraingrid 50;

ace_sys_tracking_markers_enabled = false;

"respawn_west" setMarkerPosLocal [markerPos "respawn_west" select 0, markerPos "respawn_west" select 1, 15.9];
//enableEnvironment false;

if (isServer) then {
	X_fnc_arrayPush = compile preprocessFileLineNumbers "x_scripts\x_funcs\x_arrayPush.sqf";
	X_fnc_arrayPushStack = compile preprocessFileLineNumbers "x_scripts\x_funcs\x_arrayPushStack.sqf";
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

x_addkilledhandler = [east];
x_lock_spawned = true;

//factory = (position helperfactory) nearestObject 297801;

if (isServer) then {
	execVM "x_scripts\x_serverinit.sqf";
	sus_down = 0;
	dishes_down = 0;
	t90_down = 0;
	su34_down = 0;
	aaradar1 addEventHandler ["killed", {
		radar_down = true;publicVariable "radar_down";
		{deleteVehicle _x} forEach [tunguska2] + crew tunguska2;
		{deleteVehicle _x} forEach [tunguska1] + crew tunguska1;
	}];
	su1 addEventHandler ["killed", {sus_down = sus_down + 1}];
	su2 addEventHandler ["killed", {sus_down = sus_down + 1}];
	su3 addEventHandler ["killed", {sus_down = sus_down + 1}];
	su4 addEventHandler ["killed", {sus_down = sus_down + 1}];
	boss addEventHandler ["killed",{officer_down = true;publicVariable "officer_down"}];
	dish1 addEventHandler ["killed", {dishes_down = dishes_down + 1}];
	dish2 addEventHandler ["killed", {dishes_down = dishes_down + 1}];
	dish3 addEventHandler ["killed", {dishes_down = dishes_down + 1}];
	dish4 addEventHandler ["killed", {dishes_down = dishes_down + 1}];
	// tank1 addEventHandler ["killed", {t90_down = t90_down + 1}];
	// tank2 addEventHandler ["killed", {t90_down = t90_down + 1}];
	// tank3 addEventHandler ["killed", {t90_down = t90_down + 1}];
	// tank4 addEventHandler ["killed", {t90_down = t90_down + 1}];

	{
		_x spawn {
			private ["_t"];
			_t = _this;
			waitUntil {!(_t call ace_v_alive)};
			t90_down = t90_down + 1;
		};
	} forEach [tank1,tank2,tank3,tank4];

	su34_1 addEventHandler ["killed", {su34_down = su34_down + 1}];
	su34_2 addEventHandler ["killed", {su34_down = su34_down + 1}];
	su34_3 addEventHandler ["killed", {su34_down = su34_down + 1}];
	su34_4 addEventHandler ["killed", {su34_down = su34_down + 1}];
	su34_5 addEventHandler ["killed", {su34_down = su34_down + 1}];
	su34_6 addEventHandler ["killed", {su34_down = su34_down + 1}];
	su34_7 addEventHandler ["killed", {su34_down = su34_down + 1}];

	[] spawn {
		waituntil {!isNil "allunits_add"};
		allunits_add set [count allunits_add, aaradar1];
		allunits_add set [count allunits_add, su1];
		allunits_add set [count allunits_add, su2];
		allunits_add set [count allunits_add, su3];
		allunits_add set [count allunits_add, su4];
		allunits_add set [count allunits_add, dish1];
		allunits_add set [count allunits_add, dish2];
		allunits_add set [count allunits_add, dish3];
		allunits_add set [count allunits_add, dish4];
		allunits_add set [count allunits_add, tank1];
		allunits_add set [count allunits_add, tank2];
		allunits_add set [count allunits_add, tank3];
		allunits_add set [count allunits_add, tank4];
		allunits_add set [count allunits_add, su34_1];
		allunits_add set [count allunits_add, su34_2];
		allunits_add set [count allunits_add, su34_3];
		allunits_add set [count allunits_add, su34_4];
		allunits_add set [count allunits_add, su34_5];
		allunits_add set [count allunits_add, su34_6];
		allunits_add set [count allunits_add, su34_7];
	};
};

if (true) exitWith {};