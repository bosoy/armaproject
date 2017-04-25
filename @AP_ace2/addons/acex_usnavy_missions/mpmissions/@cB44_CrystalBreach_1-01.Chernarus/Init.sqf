//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090619
// Contact: http://creobellum.org
// Purpose: Setup mission modules and dynamic objects
///////////////////////////////////////////////////////////////////
processInitCommands;

setViewDistance 2000;
setTerrainGrid 50;

if(isNil "mission_init") then {
	mission_init = false;
	publicVariable "mission_init";
};

if(isNil "tasksPublicVariable") then {
	tasksPublicVariable = [false, false, false, false, false];
	PublicVariable "tasksPublicVariable";
	call {[] execVM "crb_scripts\JIPBriefing.sqf"};
};

defValueParam1 = 99;
defValueParam2 = 4;

_parts = 7;
player globalChat format["Initialising Mission: 1 of %1", _parts];
waituntil {!isnil "bis_fnc_init"};
//crb_ACV setVariable ["vehicleCount", "round ((sqrt %1) * 0.5)"];
call{server execVM "revive_init.sqf";};

// ====================================================================================

// F2 - Mission Conditions Selector
// Credits: Please see the F2 online manual (http://www.ferstaberinde.com/f2/en/)

player globalChat format["Initialising Mission: 2 of %1", _parts];
[] execVM "f\common\f_setMissionConditions.sqf";

player globalChat format["Initialising Mission: 3 of %1", _parts];
_cep_init = [WEST, [EAST,Resistance], [Civilian], [50, 20], false] execVM "coop_essential\cep_init.sqf";
waitUntil{scriptDone _cep_init;};

player globalChat format["Initialising Mission: 4 of %1", _parts];
erb_array = [ERB2, ERB3];
publicVariable "erb_array";

player globalChat format["Initialising Mission: 5 of %1", _parts];
onPlayerConnected "call{[] execVM ""crb_scripts\JIP.sqf""};";
call{[] execVM "crb_scripts\JIP.sqf";};

player globalChat format["Initialising Mission: 6 of %1", _parts];
call{["mrkAO"] execVM "crb_scripts\RUStaticRearm.sqf";};

player globalChat format["Initialising Mission: 7 of %1", _parts];
call{[50, 45] execVM "crb_scripts\crb_HideCorpses.sqf";};

if (isServer) then {
	mission_init = true;
	publicVariable "mission_init";
};

waitUntil{mission_init};
player globalChat format["Mission Initialisation Complete"];

finishMissionInit;
