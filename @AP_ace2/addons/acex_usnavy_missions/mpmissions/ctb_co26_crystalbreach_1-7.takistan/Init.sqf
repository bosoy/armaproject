//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090619
// Modified: 20100805
// Contact: http://creobellum.org
// Purpose: Setup mission modules and dynamic objects
///////////////////////////////////////////////////////////////////
NumWrecks = 150;

cutText ["Now joining an AEF Combat Team Bravo mission...\n\nMission concept by Williepete/Delta 51 - Mission design by Wolffy.au", "BLACK FADED", 1]; 	// This next line can be commented out or removed if it interferes with intro movies
1 cutRsc ["CTBTitle", "PLAIN", 1];
2 cutRsc ["CTBFlag","PLAIN", 1];

player globalChat "Begin Initialisation";
if (isServer) then {
	if(isNil "mission_init") then {
		mission_init = [];
		publicVariable "mission_init";
	};

	if(isNil "tasksPublicVariable") then {
		tasksPublicVariable = [false, false, false, false, false];
		if (isDedicated) then {
			[] call compile preprocessFileLineNumbers "crb_scripts\JIPBriefing.sqf";
		};
		PublicVariable "tasksPublicVariable";
	};

	BIS_marta_mainscope setvariable ["delay", 5];
};
waitUntil{!isNil "mission_init"};
waitUntil{!isNil "tasksPublicVariable"};

// ====================================================================================
// F2 - Mission Conditions Selector
// Credits: Please see the F2 online manual (http://www.ferstaberinde.com/f2/en/)

player globalChat "Initialising weather and time";
[] execVM "f\common\f_setMissionConditions.sqf";

player globalChat "Initialise First Aid Fix";
[] execVM "scripts\firstaidfix.sqf";

player globalChat "Setup Wrecks";
if (isServer) then {
	_wrecks = [
		"BMP2Wreck",
		"BRDMWreck",
		"HMMWVWreck",
		"LADAWreck",
		"Mi8Wreck",
		"SKODAWreck",
		"T72Wreck",
		"T72WreckTurret",
		"UAZWreck",
		"UH60_wreck_EP1",
		"datsun01Wreck",
		"datsun02Wreck",
		"hiluxWreck",
		"UralWreck"
	];
	_sizeAO = markerSize "AO";
	for "_i" from 1 to NumWrecks do {
		_vehclass = _wrecks select floor(random count _wrecks);
		_size = if ((_sizeAO select 0) > (_sizeAO select 1)) then {(_sizeAO select 0) * 0.8;} else {(_sizeAO select 1) * 0.8;};
		_veh = createVehicle [_vehclass, markerPos "AO", [], _size, "NONE"];
		_veh setDir random 360;
		_veh setVectorUp [0,0,1];
	};
	mission_init = mission_init + ["wrecks"];
	publicVariable "mission_init";
};
waitUntil{"wrecks" in mission_init};


if(isNil "END_MISSION") then {
	END_MISSION = false;
	PublicVariable "END_MISSION";
};

player globalChat "Perform processInitCommands";
processInitCommands;

player globalChat "Server viewdist and terrain";
setViewDistance 2000;
setTerrainGrid 25;

defValueParam1 = 99;

player globalChat "Initialising Towns";
if (isServer) then {
//	_locs = ["AO", ["CityCenter"]] call compile preprocessFileLineNumbers "crB_scripts\LocationsZone.sqf";
	_locs = [loc, loc_1, loc_2, loc_3, loc_4, loc_5, loc_6, loc_7, loc_8, loc_9, loc_10, loc_11, loc_12, loc_13];

/*	hint str _locs;
	_i = 0;
	{
		_i = _i + 1;
		_n = format["x_%1", _i];
		_m = createMarker [_n, position _x];
		_m setMarkerType "Dot";
		_m setMarkerColor "ColorRed";
	} forEach _locs;
*/
	BIS_silvie_mainscope setVariable ["townlist", _locs];
	BIS_silvie_mainscope setVariable ["vehicleCount", "round ((sqrt %1) * 0.5)"];

	[_locs, "round (0.25 * sqrt %1)"] call compile preprocessFileLineNumbers "crB_scripts\crB_AmbientCivilians.sqf";

	LOCS = _locs;
	publicVariable "LOCS";

	mission_init = mission_init + ["towns"];
	publicVariable "mission_init";
};
waitUntil{!isNil "LOCS"};
waitUntil{typeName LOCS == "ARRAY"};
[LOCS] call compile preprocessFileLineNumbers "crb_scripts\crB_AmbientTowns.sqf";
waitUntil{"towns" in mission_init};

player globalChat "Initialising Patrols";
if (isServer) then {
	if(isNil "f_crB_randomGroup") then {
		f_crB_randomGroup = compile preprocessFileLineNumbers "crb_scripts\crB_randomGroup.sqf";
	};
	private["_grp"];
	_grp = [position ENV1, "Motorized", "BIS_TK"] call f_crB_randomGroup;
	[_grp, LOCS] execVM "crB_scripts\crB_WaypointPatrol.sqf";
	_grp = [position ENV2, "Motorized", "BIS_TK"] call f_crB_randomGroup;
	[_grp, LOCS] execVM "crB_scripts\crB_WaypointPatrol.sqf";
	_grp = [position ENV3, "Mechanized", "BIS_TK"] call f_crB_randomGroup;
	[_grp, LOCS] execVM "crB_scripts\crB_WaypointPatrol.sqf";
	_grp = [position ENV4, "Mechanized", "BIS_TK"] call f_crB_randomGroup;
	[_grp, LOCS] execVM "crB_scripts\crB_WaypointPatrol.sqf";

	mission_init = mission_init + ["patrols"];
	publicVariable "mission_init";
};
waitUntil{"patrols" in mission_init};

if (!isDedicated) then {
	player globalChat "Executing JIP";
	[] call compile preprocessFileLineNumbers "crB_scripts\JIP.sqf";
};

player globalChat "Kitting Playable AI";
if(isServer) then {
	{
		_nul = [_x] execVM "crB_scripts\PlayerInit.sqf";
	} forEach (playableUnits + switchableUnits);
	mission_init = mission_init + ["aikit"];
	publicVariable "mission_init";
};
waitUntil{"aikit" in mission_init};

player globalChat "Initialising CEP AI Unit Caching";
0 = [1000] execVM "coop_essential\cep_init.sqf";

/*player globalChat "Setup RU static rearm";
0 = ["AO"] execVM "crB_scripts\RUStaticRearm.sqf";
*/
player globalChat "Setup hide corpses";
0 = [50, 45] execVM "crB_scripts\crB_HideCorpses.sqf";

player globalChat "Setup Call Support";
setGroupIconsVisible [true, false];

f_initCallSupport = compile preprocessFileLineNumbers "crB_scripts\crB_initCallSupport.sqf";

[player, AMBO, "Ambulance"] call f_initCallSupport;
[player, REPAIR, "Repair Truck"] call f_initCallSupport;
[player, REFUEL, "Refuel Truck"] call f_initCallSupport;
[player, REARM, "Rearm Truck"] call f_initCallSupport;

player globalChat "Perform finishMissionInit";
finishMissionInit;

if (isServer) then {
	mission_init = mission_init + ["finish"];
	publicVariable "mission_init";
};
waitUntil{"finish" in mission_init};
player globalChat "Mission Initialisation Complete";

sleep 5;

hint "Change your View Distance Settings and Team Status options at the flagpole.";