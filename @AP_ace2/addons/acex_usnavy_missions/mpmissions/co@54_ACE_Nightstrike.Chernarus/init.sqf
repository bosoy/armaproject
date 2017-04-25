diag_log format ["############################# %1 #############################", missionName];
ace_sys_tracking_markers_enabled = false;

setTerrainGrid 50;

if (isNil "paramsArray") then {
	if (isClass (missionConfigFile/"Params")) then {
		for "_i" from 0 to (count (missionConfigFile/"Params") - 1) do {
			_paramName = configName ((missionConfigFile >> "Params") select _i);
			missionNamespace setVariable [_paramName, getNumber (missionConfigFile >> "Params" >> _paramName >> "default")];
		};
	};
} else {
	for "_i" from 0 to (count paramsArray - 1) do {
		missionNamespace setVariable [configName ((missionConfigFile/"Params") select _i), paramsArray select _i];
	};
};

X_fnc_arrayPush = {
	(_this select 0) set [count (_this select 0), _this select 1];
	(_this select 0)
};

X_fnc_arrayPushStack = {
	{
		(_this select 0) set [count (_this select 0), _x];
	} foreach (_this select 1);
	(_this select 0)
};

XfGetAltTankStatus = {
	private ["_c", "_s"];
	_c = _this getVariable "ace_canmove";
	if (isNil "_c") then {_c = true};
	_s = _this getVariable "ace_canshoot";
	if (isNil "_s") then {_s = true};
	if (!_s && !_c) then {true} else {false}
};

X_Client = false; X_Server = false; X_SPE = false;

X_MP = isMultiplayer;

if (isServer) then {
	X_Server = true;
	if (!isDedicated) then {
		X_Client = true;
		X_SPE = true;
	};
} else {
	X_Client = true;
};

X_Client = (
	if (isServer && !isDedicated) then {
		true
	} else {
		if (!isServer) then {
			true
		} else {
			false
		}
	}
);

if (X_Client) then {
	[] spawn {
		waitUntil {!isNull player};
		execVM "tasks_fix.sqf";
	};
};

x_addkilledhandler = [east];
x_lock_spawned = true;

"tanks" setMarkerAlphaLocal 0;
"extraction" setMarkerAlphaLocal 0;
"aaunit" setMarkerAlphaLocal 0;
"berezino" setMarkerAlphaLocal 0;

if (isServer) then {
	execVM "x_scripts\x_serverinit.sqf";
	[] spawn {
		sleep 15;
		execVM "x_objinit2.sqf";
	};
	t90_down = 0;
	tungi_down = 0;
	{
		_x spawn {
			private ["_t"];
			_t = _this;
			waitUntil {(!alive _t) || (_t call XfGetAltTankStatus)};
			t90_down = t90_down + 1;
		};
	} forEach [t90_1,t90_2,t90_3,t90_4];

	{
		_x spawn {
			private ["_t"];
			_t = _this;
			waitUntil {(!alive _t) || (_t call XfGetAltTankStatus)};
			tungi_down = tungi_down + 1;
		};
	} forEach [tungi1,tungi2,tungi3];

	[] spawn {
		waituntil {!isNil "allunits_add"};
		allunits_add set [count allunits_add, t90_1];
		allunits_add set [count allunits_add, t90_2];
		allunits_add set [count allunits_add, t90_3];
		allunits_add set [count allunits_add, t90_4];
	};
};

if (true) exitWith {};