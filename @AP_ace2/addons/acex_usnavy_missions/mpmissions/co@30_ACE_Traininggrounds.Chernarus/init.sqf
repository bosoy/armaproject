diag_log format ["################################# %1 #################################", missionName];

if (isServer) then {
	BIS_fnc_arrayPush = compile preprocessFileLineNumbers "\ca\modules\Functions\arrays\fn_arrayPush.sqf";
};

ace_settings_enable_vd_change = true; // enable viewdistance change in ACE Options Dialog
ace_settings_enable_tg_change = true; // enable terraingrid (gras) change in ACE Options Dialog

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

x_addkilledhandler = [east];
x_add_nvg = true;
x_show_settings = true;
if (isNil "dayornight") then {dayornight = true};
if (isNil "tdaytime") then {
	tdaytime = [date select 0, date select 1, date select 2, 9, 0];
};
setDate tdaytime;

if (isServer) then {
	execVM "x_scripts\x_serverinit.sqf";
	publicVariable "dayornight";
	cancreateenemies = false;
	docreateenemies = false;
	eready = false;
	[] spawn {
		sleep 20;
		[position trig2, 300, 4,5,3,3,2,2,2,2,"EAST"] execVM "x_scripts\x_createpatrolgroups.sqf";
		sleep 20;
		eready = true;
	};
	"dayornight" addPublicVariableEventHandler {
		if (_this select 1) then {
			tdaytime = [date select 0, date select 1, date select 2, 9, 0];
		} else {
			tdaytime = [date select 0, date select 1, date select 2, 0, 0];
		};
		setDate tdaytime;
		publicVariable "tdaytime";
	};
};
