//#define DEBUG_MODE_FULL
#include "script_component.hpp"

//	BUTTON	TEXT PICTURE SHOW/HIDE

#define __DSP (uiNamespace getVariable "MGCrewMenu")

#define __ASS(x) __DSP displayCtrl ##x
#define __DISABLE(yy) (__DSP displayCtrl ##yy) ctrlEnable false; (__DSP displayCtrl ##yy) ctrlCommit 0
#define __HIDE(yy) (__DSP displayCtrl ##yy) ctrlShow false; (__DSP displayCtrl ##yy) ctrlCommit 0

#define __ENABLE(yy) (__DSP displayCtrl ##yy) ctrlEnable true; (__DSP displayCtrl ##yy) ctrlCommit 0
#define __SHOW(yy) (__DSP displayCtrl ##yy) ctrlShow true; (__DSP displayCtrl ##yy) ctrlCommit 0

ACE_MG = _this select 0;
TRACE_1("",ACE_MG);
if !(alive ACE_MG) exitWith {
	[localize "STR_ACE_CREW_ERR_DESTROY",[1,0,0,1],true,0] spawn ace_fnc_visual;
};
_ok = createDialog "MGCrewMenu";

disableSerialization;

player setVariable [QUOTE(ace_sys_interaction_csw_menu_open), true, false];

_disableDisassemble = ACE_MG getVariable [QGVAR(disableDisassemble),false]; // TODO: Allow the real ace mortars to be taken apart
if (typeName _disableDisassemble != "BOOL") then { _disableDisassemble = false; };

_type = getText(configFile >> "CfgVehicles" >> typeOf ACE_MG >> "ACE" >> "ACE_CREWSERVED" >> "interaction");
_disassembleType = getText(configFile >> "CfgVehicles" >> typeOf ACE_MG >> "ACE" >> "ACE_CREWSERVED" >> "disassemblyType");
if (isNil "_disassembleType") then { _disableDisassemble = true; };

_hasSpareBarrel = "ACE_SpareBarrel" in (weapons player);

_canChangeHeight = (getNumber(configFile >> "CfgVehicles" >> typeOf ACE_MG >> "ACE" >> "ACE_CREWSERVED" >> "canChangeHeight") == 1);

_pitch = [ACE_MG] call FUNC(getPitch);

TRACE_2("",_type,_hasSpareBarrel);

switch (_type) do {
	// STATIC WEAPONS & CSW (DISASSEMLBE & ASSEMBLE with CSW backpack)
	case "Crewserved": {
		// SWAP BARREL / CLEAN BARREL
		if (ACE_MG isKindOf "StaticMGWeapon" && {_hasSpareBarrel}) then {
			buttonSetAction [2030, QUOTE([{closeDialog 0}] spawn FUNC(swap_barrel))]; 	// Show Barrel Swap button
		} else {
			// IF is Mortar add clean tube action
			if (ACE_MG isKindOf "StaticMortar" && {getNumber (configFile >> "CfgVehicles" >> typeOf ACE_MG >> "ACE_ARTY_ISARTY") == 1}) then {
				ctrlSetText [1030, QPATHTO_T(data\dialog\icon_cleanbarrel.paa)];
				buttonSetAction [2030, QUOTE([{closeDialog 0}] spawn FUNC(clean_barrel))]; 	// Show Barrel Swap button
				ctrlSetText [3030, "Clean barrel"];
			} else {
				__DISABLE(2030);__HIDE(3030);
				ctrlSetText [1030, QPATHTO_T(data\dialog\icon_changebarrel_dis.paa)];	// Hide Barrel Swap button
			};
		};
		
		// ROTATE
		if (ACE_MG isKindOf "StaticMortar" && {ACE_MG getVariable ["ace_sys_arty_shoton",false]}) then {
			__DISABLE(2023);__HIDE(3023);
			ctrlSetText [1023, QPATHTO_T(data\dialog\icon_rotateleft_dis.paa)];
			__DISABLE(2024);__HIDE(3024);
			ctrlSetText [1024, QPATHTO_T(data\dialog\icon_rotateright_dis.paa)];
		} else {
			buttonSetAction [2023, QUOTE([-10] call FUNC(rotate))];							// Show Rotate
			buttonSetAction [2024, QUOTE([10] call FUNC(rotate))];							// Show Rotate		
		};
		
		// LOAD
		if (getNumber (configFile >> "CfgVehicles" >> typeOf ACE_MG >> "ACE_ARTY_ISARTY") != 1) then {
			if (ACE_MG getVariable [QGVAR(busy),false]) then {
				__DISABLE(2021);__HIDE(3021);
				ctrlSetText [1021, QPATHTO_T(data\dialog\icon_load_dis.paa)];				
			} else {
				buttonSetAction [2021, QUOTE([{closeDialog 0}] spawn FUNC(load))]; 				// Show Loading button
			};
		} else {
			__DISABLE(2021);__HIDE(3021);__HIDE(1021);
		};
		
		// UNLOAD
		if (ACE_MG isKindOf "StaticMortar") then {
			__DISABLE(2022);__HIDE(3022);__HIDE(1022);
		} else {
			buttonSetAction [2022, QUOTE([{closeDialog 0}] spawn FUNC(unload))]; 			// Show Unloading button
		};
		
		// PITCH
		if (_pitch < 10 && {!(ACE_MG isKindOf "StaticMortar")}) then {
			__ENABLE(2031);__SHOW(3031);
			ctrlSetText [1031, QPATHTO_T(data\dialog\icon_pitchup.paa)];
			buttonSetAction [2031, QUOTE([2] call FUNC(pitch))];							// Show Pitch Up
		} else {
			__DISABLE(2031);__HIDE(3031);
			ctrlSetText [1031, QPATHTO_T(data\dialog\icon_pitchup_dis.paa)];	// Hide Barrel Swap button		
		};
		if (_pitch > -10 && {!(ACE_MG isKindOf "StaticMortar")}) then {
			__ENABLE(2032);__SHOW(3032);
			ctrlSetText [1032, QPATHTO_T(data\dialog\icon_pitchdn.paa)];
			buttonSetAction [2032, QUOTE([-2] call FUNC(pitch))];							// Show Pitch Dn
		} else {
			__DISABLE(2032);__HIDE(3032);
			ctrlSetText [1032, QPATHTO_T(data\dialog\icon_pitchdn_dis.paa)];	// Hide Barrel Swap button		
		};
		
		// UNMOUNT
		if (!_disableDisassemble) then {
			if (_disassembleType == "proxy") then {
				buttonSetAction [2025, QUOTE([{closeDialog 0}] spawn FUNC(unmount))];			// Show Unmount
			} else {
				buttonSetAction [2025, QUOTE([{closeDialog 0}] spawn FUNC(unmount_parts))];		// Show Unmount
			};
		} else {
			__DISABLE(2025);__HIDE(3025);													// Hide Unmount if DISASSEMLBE is disabled
			ctrlSetText [1025, QPATHTO_T(data\dialog\icon_unmount_dis.paa)];
		};
		
		// GETIN
		buttonSetAction [2028, QUOTE([{closeDialog 0}] call FUNC(getin))];				// Show Getin	
	};
	
	// TRIPOD & BIPOD
	case "Tripod": {
		__DISABLE(2030);__HIDE(3030);__HIDE(1030);											// Hide Barrel Swap button
		__DISABLE(2021);__HIDE(3021);__HIDE(1021);											// Hide Loading
		__DISABLE(2022); __HIDE(3022); __HIDE(1022);										// Hide Unloading
		buttonSetAction [2023, QUOTE([-10] call FUNC(rotate))];							// Show Rotate
		buttonSetAction [2024, QUOTE([10] call FUNC(rotate))];							// Show Rotate
		__DISABLE(2031);__HIDE(3031);__HIDE(1031);											// Hide Pitch Up
		__DISABLE(2032); __HIDE(3032); __HIDE(1032);										// Hide Pitch Dn		
			if ([player,3,false] call FUNC(checkMountCrewMG)) then {					// Show Mount
				ctrlSetText [3025, localize "STR_ACE_CREW_MOUNT"];
				ctrlSetText [1025, QPATHTO_T(data\dialog\icon_mount.paa)];
				buttonSetAction [2025, QUOTE([{closeDialog 0}] spawn FUNC(mount))];
			} else {
				buttonSetAction [2025, QUOTE([{closeDialog 0}] spawn FUNC(unmount))];
				ctrlSetText [3025, localize "STR_ACE_CREW_PICKUP"]; 					// Show Unmount
			};
		// Can change height?
		if (_canChangeHeight) then {
				ctrlSetText [3028, localize "STR_ACE_CREW_ELEVATE"];
				ctrlSetText [1028, QPATHTO_T(data\dialog\icon_elevate.paa)];
				buttonSetAction [2028, QUOTE([{closeDialog 0}] spawn FUNC(elevate))];		
		} else {
			__DISABLE(2028);__HIDE(3028);__HIDE(1028);											// Hide Getin	
		};
	};
	
	// NON SUPPORTED STATIC WEAPONS
	case "RotateOnly": {
		__DISABLE(2030);__HIDE(3030);__HIDE(1030);											// Hide Barrel Swap button
		__DISABLE(2021);__HIDE(3021);__HIDE(1021);											// Hide Loading
		__DISABLE(2022); __HIDE(3022); __HIDE(1022);										// Hide Unloading
		buttonSetAction [2023, QUOTE([-10] call FUNC(rotate))];							// Show Rotate
		buttonSetAction [2024, QUOTE([10] call FUNC(rotate))];							// Show Rotate
		__DISABLE(2025);__HIDE(3025);__HIDE(1025);											// Hide Unmount
		__DISABLE(2031);__HIDE(3031);__HIDE(1031);											// Hide Pitch Up
		__DISABLE(2032); __HIDE(3032); __HIDE(1032);										// Hide Pitch Dn		
		__DISABLE(2030);__HIDE(3030);
		buttonSetAction [2028, QUOTE([{closeDialog 0}] call FUNC(getin))];				// Show Getin
	};
	
	//REST
	default {
		if (ACE_MG isKindOf "StaticMGWeapon" && {_hasSpareBarrel}) then {
			buttonSetAction [2030, QUOTE([{closeDialog 0}] spawn FUNC(swap_barrel))]; 	// Show Barrel Swap button
		} else {
			__DISABLE(2030);__HIDE(3030);
			ctrlSetText [1030, QPATHTO_T(data\dialog\icon_changebarrel_dis.paa)];	// Hide Barrel Swap button
		};
		buttonSetAction [2021, QUOTE([{closeDialog 0}] spawn FUNC(load))]; 				// Show Loading button
		buttonSetAction [2022, QUOTE([{closeDialog 0}] spawn FUNC(unload))]; 			// Show Unloading button
		buttonSetAction [2023, QUOTE([-10] call FUNC(rotate))];							// Show Rotate
		buttonSetAction [2024, QUOTE([10] call FUNC(rotate))];							// Show Rotate
		buttonSetAction [2031, QUOTE([2] call FUNC(pitch))];							// Show Pitch Up
		buttonSetAction [2032, QUOTE([-2] call FUNC(pitch))];							// Show Pitch Dn		
		__DISABLE(2025);__HIDE(3025);														// Hide Mount/Unmount
		ctrlSetText [1025, QPATHTO_T(data\dialog\icon_unmount_dis.paa)];			// Hide Mount/Unmount
		buttonSetAction [2028, QUOTE([{closeDialog 0}] call FUNC(getin))];				// Show Getin	
	};
};
