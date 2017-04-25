#include "script_component.hpp"
/*
	Six Battle Center - Init - by Sickboy (sb_at_dev-heaven.net)
	*** ALPHA *** NOT FOR PUBLIC USAGE ***
*/

// Enable ace_sys_wounds
if (isNil "ace_sys_wounds_enabled") then { ace_sys_wounds_enabled = true };

// Enable ace_sys_aitalk
if (isNil "ace_sys_aitalk_enabled") then { ace_sys_aitalk_enabled = true };
if (isNil "ace_sys_aitalk_radio_enabled") then { ace_sys_aitalk_radio_enabled = true };

if !(isDedicated) then {
	[] spawn {
		sleep 1; hintC "Battle Center Mission is Initializing\nPlease be Patient, or Setup the Mission";
		if !(isClass(configFile >> "CfgPatches" >> "ION_RTEV")) then {
			CBA_logic globalChat "I0n0s RealTimeEditor (RTE) seems to be missing, please install for additional functionality!";
		};
	};
	if (isServer) then {
		ace_referee = true;
		ace_debug_miss = true;
		ace_sys_tracking_markers_debug = true;
	};
};

if (isServer) then {
	[] spawn {
		call COMPILE_FILE2(\x\ace\addons\sys_menu\init.sqf);
		CREATELOGICGLOBALTEST;

		// Enable the extra arma2 systems
		// "Alice2Manager" createUnit [[0, 0, 0], (createGroup sideLogic), "this setVariable ['debug', false]"]; // debug error workaround
		{ (createGroup sideLogic) createUnit [_x, [0,0,0], [], 0, "NONE"] } forEach ["BIS_SRRS_Logic", "Alice2Manager", "SilvieManager", "BIS_animals_Logic"]; // "BIS_clouds_Logic"
	};
};
