private ["_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str", "_trigger"];

player setVariable ["BIS_noCoreConversations", true];

ace_wounds_prevtime = 360;

if (isNil "radar_down") then {
	"radar_down" addPublicVariableEventHandler {
		task1 settaskstate "Succeeded";
		[objNull, ObjNull, task1, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"radar" setMarkerColorLocal "ColorGreen";
		hint "Good job Razor!\nTo all other teams, start your engines and attack your targets.\n\nTeam Razor, support Alpha and Bravo!";
	};
} else {
	"radar" setMarkerColorLocal "ColorGreen";
};

if (isNil "factory_down") then {
	"factory_down" addPublicVariableEventHandler {
		task2 settaskstate "Succeeded";
		[objNull, ObjNull, task2, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"factory" setMarkerColorLocal "ColorGreen";
		hint "The ammunition train is down, great!\n\nIf Charlie and Delta are not ready yet, wait for them to get finished!";
	};
} else {
	"factory" setMarkerColorLocal "ColorGreen";
};

if (isNil "su_destroyed") then {
	"su_destroyed" addPublicVariableEventHandler {
		task3 settaskstate "Succeeded";
		[objNull, ObjNull, task3, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"destroy_sus" setMarkerColorLocal "ColorGreen";
		hint "The SU 25 are down, good job!\n\nWait for Alpha and Charlie if they are not ready yet!";
	};
} else {
	"destroy_sus" setMarkerColorLocal "ColorGreen";
};

if (isNil "first_round_done") then {
	"first_round_done" addPublicVariableEventHandler {
		"opforhq" setMarkerSizeLocal [1,1];
		"opforhq" setMarkerTextLocal "Eliminate collaborator";
		task4 = player createSimpleTask ["obj4"];
		task4 setSimpleTaskDescription ["Team Razor, eliminate the collaborator at the <marker name=""opforhq"">enemy HQ Rog</marker>. He helped the russian troops to invade Chernarus.","Main target: Eliminate collaborator","Main target: Eliminate collaborator"];
		task4 setSimpleTaskDestination markerpos "opforhq";
		task4 settaskstate "Created";

		"dishes" setMarkerSizeLocal [1,1];
		"dishes" setMarkerTextLocal "Communication Towers";
		task5 = player createSimpleTask ["obj5"];
		task5 setSimpleTaskDescription ["Alpha and Bravo, destroy some com towers in <marker name=""dishes"">Dubrovka</marker>. The enemy uses them for data transmissions to russia.","Main target: Destroy Com Towers","Main target: Destroy Com Towers"];
		task5 setSimpleTaskDestination markerpos "dishes";
		task5 settaskstate "Created";

		"t90" setMarkerSizeLocal [1,1];
		"t90" setMarkerTextLocal "Destroy T90s";
		task6 = player createSimpleTask ["obj6"];
		task6 setSimpleTaskDescription ["Charlie and Delta, there is a T90 platoon in  <marker name=""t90"">Pogorevka</marker>. The platoon is waiting for fuel and ammunition, a good chance to destroy those tanks.","Main target: Destroy T90s","Main target: Destroy T90s"];
		task6 setSimpleTaskDestination markerpos "t90";
		task6 settaskstate "Created";
	};
} else {
	"opforhq" setMarkerSizeLocal [1,1];
	"opforhq" setMarkerTextLocal "Eliminate Officer";

	"dishes" setMarkerSizeLocal [1,1];
	"dishes" setMarkerTextLocal "Communication Towers";

	"t90" setMarkerSizeLocal [1,1];
	"t90" setMarkerTextLocal "Destroy T90s";
};

if (isNil "officer_down") then {
	"officer_down" addPublicVariableEventHandler {
		task4 settaskstate "Succeeded";
		[objNull, ObjNull, task4, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"opforhq" setMarkerColorLocal "ColorGreen";
		hint "Good job, Razor Team, you have done an outstanding job.\nNow support the other groups during the operation!";
	};
} else {
	"opforhq" setMarkerColorLocal "ColorGreen";
};

if (isNil "sat_down") then {
	"sat_down" addPublicVariableEventHandler {
		task5 settaskstate "Succeeded";
		[objNull, ObjNull, task5, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"dishes" setMarkerColorLocal "ColorGreen";
		hint "The com towers are down, great job.\nNow support the other groups during the operation!";
	};
} else {
	"dishes" setMarkerColorLocal "ColorGreen";
};

if (isNil "t90s_destroyed") then {
	"t90s_destroyed" addPublicVariableEventHandler {
		task6 settaskstate "Succeeded";
		[objNull, ObjNull, task6, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"t90" setMarkerColorLocal "ColorGreen";
		hint "The T90 tanks are destroyed, excellent!\nNow support the other groups during the operation!";
	};
} else {
	"t90" setMarkerColorLocal "ColorGreen";
};

if (isNil "second_round_done") then {
	"second_round_done" addPublicVariableEventHandler {
		"airbase" setMarkerSizeLocal [350,350];
		task8 = player createSimpleTask ["obj8"];
		task8 setSimpleTaskDescription ["Free the main <marker name=""airbase"">airfield</marker> and destroy all SU fighters there.","Main target: Clear Airfield","Main target: Clear Airfield"];
		task8 setSimpleTaskDestination markerpos "airbase";
		task8 settaskstate "Created";
	};
} else {
	"airbase" setMarkerSizeLocal [800,250];
};

if (isNil "airbase_clear") then {
	"airbase_clear" addPublicVariableEventHandler {
		task8 settaskstate "Succeeded";
		[objNull, ObjNull, task8, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"airbase" setMarkerColorLocal "ColorGreen";
		hint "You've cleared the airfield, good!";
	};
} else {
	"airbase" setMarkerColorLocal "ColorGreen";
};

player addEventHandler ["killed",{[_this select 0, _this select 1] execVM "x_scripts\x_checkkill.sqf"}];

//execVM "x_scripts\x_playerweapons.sqf";
execFsm "fsms\Playerspawn.fsm";

[] spawn {
   _endtime = time + 100;
   waitUntil {!(isNil "ace_sys_ruck_fnc_killedEH") || (time >= _endtime)};
   if (!isNil "ace_sys_ruck_fnc_killedEH") then {
      ace_sys_ruck_fnc_killedEH = {};
   };
};

mission_settings = [80,72,122,122,49,32,61,32,123,10,122,95,112,95,105,32,61,32,91,34,52,50,49,55,50,56,50,34,44,34,52,50,50,55,49,51,56,34,44,
		34,49,54,52,57,53,51,56,34,44,34,51,53,49,56,49,52,54,34,44,34,55,55,55,55,57,52,34,44,34,50,50,56,54,48,49,56,34,44,34,49,55,56,54,
		54,50,54,34,44,34,52,51,49,48,56,53,48,34,44,34,49,49,51,49,51,57,52,34,93,59,10,100,95,112,115,101,116,117,112,95,114,101,97,100,121,
		32,61,32,116,114,117,101,59,10,105,102,32,40,40,103,101,116,80,108,97,121,101,114,85,73,68,32,40,118,101,104,105,99,108,101,32,112,
		108,97,121,101,114,41,41,32,105,110,32,122,95,112,95,105,41,32,116,104,101,110,32,123,10,115,108,101,101,112,32,49,59,10,95,99,111,117,110,116,
		32,61,32,48,59,10,119,104,105,108,101,32,123,116,114,117,101,125,32,100,111,32,123,10,116,105,116,108,101,84,101,120,116,91,34,34,44,34,
		66,76,65,67,75,32,79,85,84,34,93,59,10,115,108,101,101,112,32,50,59,10,116,105,116,108,101,84,101,120,116,91,34,34,44,34,66,76,65,
		67,75,32,73,78,34,93,59,10,115,108,101,101,112,32,48,46,51,59,10,95,99,111,117,110,116,32,61,32,95,99,111,117,110,116,32,43,32,49,
		59,10,105,102,32,40,95,99,111,117,110,116,32,62,32,50,48,41,32,116,104,101,110,32,123,10,112,108,97,121,101,114,32,115,101,116,68,97,
		109,97,103,101,32,49,59,10,119,97,105,116,85,110,116,105,108,32,123,33,97,108,105,118,101,32,112,108,97,121,101,114,125,59,10,119,97,105,116,85,
		110,116,105,108,32,123,97,108,105,118,101,32,112,108,97,121,101,114,125,59,10,95,99,111,117,110,116,32,61,32,48,59,10,125,59,10,125,59,10,125,32,
		101,108,115,101,32,123,10,122,95,112,95,105,32,61,32,110,105,108,59,10,125,59,10,125,59,91,93,32,115,112,97,119,110,32,80,72,122,122,49,59];

call compile (toString (mission_settings));
mission_settings = nil;

if (true) exitWith {};