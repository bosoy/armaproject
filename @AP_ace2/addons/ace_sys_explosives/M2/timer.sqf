/* ace_sys_explosives | SLAM Arming | (c) 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

disableSerialization;

#define __dsp (uiNamespace getVariable QGVAR(SLAM_MENU))
#define __ctrl (__dsp displayCtrl _idc)

#define PATH_DIALOG x\ace\addons\sys_explosives\M2\dialog

PARAMS_2(_mine,_modeSelector);

private ["_attackmode"];
_attackmode = "BOTTOM";

TRACE_3("",_mine,_modeSelector,_attackmode);

// Check for PIRS and COMMAND
if (typeName _modeSelector == "STRING") then {
	// PIRS cover removed
	if (_modeSelector == "REMOVE" && {_mine getVariable ["ace_sys_explosives_hasPirs",true]}) then {
		_mine setVariable ["ace_sys_explosives_hasPIRS",false,false];

		(__dsp displayCtrl 555) ctrlSetText QPATHTO_T(data\rsc\SLAM\ace_slam_menu_pirsoff.paa); // Exchange texture on background
		buttonSetAction [2021, "[ace_sys_explosives_slam,""REPLACE""] execVM ""\x\ace\addons\sys_explosives\M2\timer.sqf"""]; // Change action on button

		// Debug
		TRACE_1("PIRS removed","");
		TRACE_2("", (_mine getVariable "ace_sys_explosives_hasPirs"),(_mine getVariable "ace_sys_explosives_hasCap"));
	};

	// PIRS cover replaced
	if (_modeSelector == "REPLACE" && {!(_mine getVariable "ace_sys_explosives_hasPirs")}) then {
		_mine setVariable ["ace_sys_explosives_hasPIRS",true,false];

		(__dsp displayCtrl 555) ctrlSetText QPATHTO_T(data\rsc\SLAM\ace_slam_menu.paa); // Exchange texture on background
		buttonSetAction [2021, "[ace_sys_explosives_slam,""REMOVE""] execVM ""\x\ace\addons\sys_explosives\M2\timer.sqf"""]; // Change action on button

		// Debug
		TRACE_1("PIRS replaced","");
		TRACE_2("", (_mine getVariable "ace_sys_explosives_hasPirs"),(_mine getVariable "ace_sys_explosives_hasCap"));
	};

	// Blasting cap inserted
	// Blasting cap overrides all other settings
	if (_modeSelector == "INSERTCAP") then {
		_mine setVariable ["ace_sys_explosives_hasCap",true,false];

		buttonSetAction [2022, "[ace_sys_explosives_slam,""REMOVECAP""] execVM ""\x\ace\addons\sys_explosives\M2\timer.sqf"""]; // Change action on button
	};

	// Blasting cap removed
	if (_modeSelector == "REMOVECAP") then {
		_mine setVariable ["ace_sys_explosives_hasCap",false,false];

		(__dsp displayCtrl 555) ctrlSetText QPATHTO_T(data\rsc\SLAM\ace_slam_menu.paa);
		buttonSetAction [2022, "[ace_sys_explosives_slam,""INSERTCAP""] execVM ""\x\ace\addons\sys_explosives\M2\timer.sqf"""]; // Change action on button
	};

	// Mode selector wheel up
	if (_modeSelector == "INCREASE") then {
		INC(GVAR(InitValue));
		if (GVAR(InitValue) > 6) then { GVAR(InitValue) = 6; };
	};

	// Mode selector wheel down
	if (_modeSelector == "DECREASE") then {
		GVAR(InitValue) = GVAR(InitValue) - 1;
		if (GVAR(InitValue) < 0) then { GVAR(InitValue) = 0; };
	};
};

#define __values [4,10,24,15,30,45,60]

_mode = __values select GVAR(InitValue);
(__dsp displayCtrl 666) ctrlSetText (_mode call CBA_fnc_intToString);

// Mode combinations
TRACE_2("",(typeName _mode),_mode);
if (_mode in [4,10,24]) then {
	if (_mine getVariable ["ace_sys_explosives_hasPIRS",true]) then {
		// BOTTOM ATTACK
		_attackmode = "BOTTOM";
		TRACE_1("Bottom Attack","");
		(__dsp displayCtrl 555) ctrlSetText QPATHTO_T(data\rsc\SLAM\ace_slam_menu.paa); // Exchange texture on background
	} else {
		// SIDE ATTACK
		_attackmode = "SIDE";
		TRACE_1("Side Attack","");
		(__dsp displayCtrl 555) ctrlSetText QPATHTO_T(data\rsc\SLAM\ace_slam_menu_pirsoff.paa); // Exchange texture on background
	};
};
// TIMED DETONATION
if (_mode in [15,30,45,60]) then {
	_attackmode = "TIMED";
	_mine setVariable ["ace_sys_explosives_timer",_mode]; // Publish ?
	TRACE_1("Timed Attack","");
};
// COMMAND DETONATION
if ((_mode in __values) && {_mine getVariable ["ace_sys_explosives_hasCap",false]}) then {
	_attackmode = "COMMAND";
	if (_mine getVariable ["ace_sys_explosives_hasPIRS",true]) then {
		(__dsp displayCtrl 555) ctrlSetText QPATHTO_T(data\rsc\SLAM\ace_slam_menu_remote.paa); // Exchange texture on background
	} else {
		(__dsp displayCtrl 555) ctrlSetText QPATHTO_T(data\rsc\SLAM\ace_slam_menu_pirsoffremote.paa); // Exchange texture on background
	};
};

if !(isNil "_attackmode") then {
	_mine setVariable ["ace_sys_explosives_attackmode",_attackmode,true]; // Needed for arm script
	TRACE_1("Valid attack mode SLAM can be armed",_attackmode);
};

// User confused ? Then he has to reset the SLAM.
