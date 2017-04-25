private ["_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str", "_trigger"];

player setVariable ["BIS_noCoreConversations", true];

ace_wounds_prevtime = 360;

waitUntil {!isNil "tasks_done"};

if (!isNil "convoy_down") then {
	deleteMarkerLocal "Hinterhalt";
} else {
	"convoy_down" addPublicVariableEventHandler {
		hint "The convoy was destroyed, good work!";
		task1 settaskstate "Succeeded";
		deleteMarkerLocal "Hinterhalt";
	};
};

_str = str player;

if (_str in ["sf_1d","sf_2d","sf_3d","sf_4d","sf_5d","sf_1","sf_2","sf_3","sf_4","sf_5"]) then {
	if (isNil "convoy_down") then {
		player setCurrentTask task1;
	};
} else {
	if (_str in ["pilot_1","pilot_2","pilot_3","pilot_4","pilot_5"]) then {
		player setCurrentTask task5;
	} else {
		if (_str in ["a1","a2","a3","a4","a5","a6","a7","a8","a9","a10","a11","a12","a13","c1","c2","c3","c4","c5","c6","c7","c8","c9","c10","c11","c12","c13"]) then {
			if (isNil "elektro_clear") then {
				player setCurrentTask task3;
			};
		} else {
			if (_str in ["b1","b2","b3","b4","b5","b6","b7","b8","b9","b10","b11","b12","b13"]) then {
				if (isNil "zele_clear") then {
					player setCurrentTask task2;
				};
			} else {
				if (isNil "elektro_clear") then {
					player setCurrentTask task3;
				};
			};
		};
	};
};

if (isNil "tanks_down") then {
	"tanks_down" addPublicVariableEventHandler {
		"tanks" setMarkerColorLocal "ColorGreen";
		hint "Tanks in Zelenogorsk are destroyed !!!";
	};
} else {
	"tanks" setMarkerColorLocal "ColorGreen";
};

if (isNil "zele_clear") then {
	"zele_clear" addPublicVariableEventHandler {
		"zeleno" setMarkerColorLocal "ColorGreen";
		task2 settaskstate "Succeeded";
		[objNull, ObjNull, task2, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		hint "Zelenogorsk cleared !!!";
	};
} else {
	"zeleno" setMarkerColorLocal "ColorGreen";
};

if (isNil "elektro_clear") then {
	"elektro_clear" addPublicVariableEventHandler {
		"elektro" setMarkerColorLocal "ColorGreen";
		task3 settaskstate "Succeeded";
		[objNull, ObjNull, task3, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		hint "Elektrozavodsk cleared !!!";
	};
} else {
	"elektro" setMarkerColorLocal "ColorGreen";
};

if (isNil "krasno_clear") then {
	"krasno_clear" addPublicVariableEventHandler {
		"krasnostav" setMarkerColorLocal "ColorGreen";
		task4 settaskstate "Succeeded";
		[objNull, ObjNull, task4, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		hint "Krasnostav cleared !!!";
	};
} else {
	"elektro" setMarkerColorLocal "ColorGreen";
};

if (isNil "shilka1_cracked") then {
	"shilka1_cracked" addPublicVariableEventHandler {
		deleteMarkerLocal "shilka1";
		hint "Tunguska One Down!";
	};
} else {
	deleteMarkerLocal "shilka1"
};

if (isNil "shilka2_cracked") then {
	"shilka2_cracked" addPublicVariableEventHandler {
		deleteMarkerLocal "shilka2";
		hint "Tunguska Two Down!";
	};
} else {
	deleteMarkerLocal "shilka2";
};

"convoy_reached_dest" addPublicVariableEventHandler {
	task1 settaskstate "FAILED";
	[objNull, ObjNull, task1, "FAILED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
	hint "The convoy reached its destination, mission failed!";
};

"ari_available" addPublicVariableEventHandler {
	[playerSide,"HQ"] sideChat "Artillery available again!";
};

is_artiman = false;
arti_action = -1000;
if (_str in ["arti","artid"]) then {
	arti_action = player addAction ["Call Artillery","call_arti.sqf",[],-1,false];
	is_artiman = true;
	_trigger = createTrigger["EmptyDetector" ,position player];
	_trigger setTriggerArea [0, 0, 0, false];
	_trigger setTriggerActivation ["NONE", "PRESENT", true];
	vec_ass = -8876;
	_trigger setTriggerStatements["vehicle player != player", "arti_vehicle = vehicle player;if (vec_ass == -8876) then {vec_ass = arti_vehicle addAction ['Call Artillery', 'call_arti.sqf',[],-1,false]}", "if (vec_ass != -8876) then {arti_vehicle removeAction vec_ass;vec_ass = -8876}"];
};

player addEventHandler ["killed",{[_this select 0, _this select 1] execVM "x_scripts\x_checkkill.sqf"}];

execVM "x_scripts\x_playerweapons.sqf";

[] spawn {
		private ["_idadmin"];
		while {true} do {
			waitUntil {alive player};
			waitUntil {(serverCommandAvailable "#shutdown")};
			_idadmin = player addAction ["Admin Spectate", "x_scripts\x_adminspectate.sqf",0,-1,false];
			waitUntil {!(serverCommandAvailable "#shutdown") || !alive player};
			player removeAction _idadmin;
		};
};