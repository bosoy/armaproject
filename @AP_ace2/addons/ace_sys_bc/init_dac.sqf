// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// TODO: Zone numbering + linking, activating/deactivating on request, and zone direction
// TODO: Waypoint Only zones
// TODO: Allow DAC Behaviour/Unit/WP Configs to be changed per zone, on the fly, like zone position/size
// TODO: Handle DAC_Res_Side
// TODO: Allow realtime configuration of DAC_Dyn_Weather, DAC_Marker

// ["z1",[1,0,0],[3,3,20,6],[3,3,20,6],[3,3,20,6],[2,2,50,0,100,10],[0,0,0,0,1]] spawn DAC_Zone
// PARAMS_7(_zoneId,_zoneSettings,_infantrySettings,_vehicleSettings,_tankSettings,_airCampSettings,_sideSettings);

// Set default DAC Settings
DAC_AI_Count_Level  = [[2,4],[2,6],[2,8],[2,12],[4,0],[6,0]];

// Need to be updated/determined from mission.sqm - amount of player units
DAC_StrPlayers = [];
for "_i" from 1 to 270 do {
	PUSH(DAC_StrPlayers,("p"+str(_i)));
};


// TODO: Evaluate the extra code parameter ..
[GVAR(ai_hash), "DAC", [[], {}]] call CBA_fnc_hashSet;

// Spawn DAC Logic
// TODO: Confirm it is no problem to use a shared group with DAC - perhaps it has special uses for its group
if (SLX_XEH_MACHINE select 3) then {
	_group = [sideLogic] call CBA_fnc_getSharedGroup;
	_logic = _group createUnit ["DAC_Source_Extern", [0,0,0], [], 0, "NONE"]; // DAC_Source_Intern
};
//DAC_Zone = COMPILE_FILE2(\x\ace\addons\sys_bc\DAC\Scripts\DAC_Init_Zone.sqf);
//DAC_Objects	= COMPILE_FILE2(\x\ace\addons\sys_bc\DAC\Scripts\DAC_Create_Objects.sqf);
//execVM "\x\ace\addons\sys_bc\DAC\DAC_Config_Creator.sqf";


// Functions
FUNC(dacZone) = {
	PARAMS_6(_position,_side,_size,_cfgGroups,_zoneName,_ai);

	if (SLX_XEH_MACHINE select 3) then {
		if (isNil QUOTE(GVAR(DAC_INIT))) then {
			GVAR(DAC_INIT) = true;
			//_group = [sideLogic] call CBA_fnc_getSharedGroup;
			//_logic = _group createUnit ["DAC_Source_Extern", [0,0,0], [], 0, "NONE"]; // DAC_Source_Intern
			// waitUntil {DAC_Basic_Value > 0};
		};
	};

	// BAH
	waitUntil {!(isNil "DAC_Basic_Value")};
	waitUntil {!(isNil "DAC_NewZone")};
	waitUntil {DAC_NewZone == 0};
	/*
	_z = createTrigger ["EmptyDetector", _position];
	_z setTriggerArea	(_size + [0, false]);
	_z setTriggerActivation["GAMELOGIC","PRESENT", true];
	_z setTriggerStatements["this", "", ""];
	missionNameSpace setVariable [_zoneName, _z];
	([_zoneName] + _cfgGroups) spawn DAC_Zone;
	*/

	[_position, _size select 0, _size select 1, 0, 0, ([_zoneName] + _cfgGroups)] call DAC_fNewZone;
};

if !(isDedicated) then {
	PREP(menu_dac);

	[] spawn {
		waitUntil { GETVAR(_state) > 0 };
		GVAR(DAC_SIDE) = GVAR(ENEMY_SIDE);
		GVAR(DAC_Settings) = [[1,0,0],[3,2,20,6],[],[],[],[GVAR(DAC_SIDE),GVAR(DAC_SIDE),GVAR(DAC_SIDE),0,1]];
		GVAR(DAC_Settings_Default) = [[1,0,0],[3,2,20,6],[2,2,14,6],[2,2,14,6],[2,2,50,0,100,10],[GVAR(DAC_SIDE),GVAR(DAC_SIDE),GVAR(DAC_SIDE),0,1]];
	};
};
