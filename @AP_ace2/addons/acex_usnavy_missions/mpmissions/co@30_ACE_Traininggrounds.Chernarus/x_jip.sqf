player setVariable ["BIS_noCoreConversations", true];

execVM "x_scripts\x_playerinit.sqf";

player addEventHandler ["killed",{[_this select 0, _this select 1] execVM "x_scripts\x_checkkill.sqf"}];

[] spawn {
		private ["_idday", "_idnewenemies"];
		while {true} do {
			waitUntil {alive player};
			waitUntil {(serverCommandAvailable "#shutdown")};
			_idday = player addAction ["Change Day/Night", "x_changedaytime.sqf",0,-1,false];
			_idnewenemies = player addAction ["Create new enemies", "x_createenemies.sqf",0,-1,false];
			waitUntil {!(serverCommandAvailable "#shutdown") || !alive player};
			player removeAction _idday;
			player removeAction _idnewenemies;
		};
};

_p = player;
_primw = primaryWeapon _p;
if (_primw != "") then {
	_p selectWeapon _primw;
	_muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
	_p selectWeapon (_muzzles select 0);
};

"cancreateenemies" addPublicVariableEventHandler {
	if (_this select 1) then {
		hint "Target cleared, the admin can now create new enemies at target side again!";
	};
};

"ecreatedx" addPublicVariableEventHandler {
	player sideChat "New enemies get created...";
};

"dayornight" addPublicVariableEventHandler {
	if (_this select 1) then {
		tdaytime = [date select 0, date select 1, date select 2, 9, 0];
	} else {
		tdaytime = [date select 0, date select 1, date select 2, 0, 0];
	};
	setDate tdaytime;
};

x_playerspawn = compile preprocessFileLineNumbers "x_scripts\x_playerspawn.sqf";

player addEventHandler ["killed", {[0] call x_playerspawn}];

player addEventHandler ["respawn", {[1] call x_playerspawn;deleteVehicle (_this select 1)}];