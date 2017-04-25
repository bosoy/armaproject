/* ace_sys_explosives (.pbo)| Interaction | (c) 2008, 2009, 2010, 2011 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

PARAMS_2(_target,_params);

_menuDef = [];
_menuName = "";
_menuRsc = "popup";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__];};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};

//-----------------------------------------------------------------------------
#define __TYPE getText(configFile >> "CfgVehicles" >> typeOf GVAR(mine) >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(mine_type))
#define __DN getText(configFile >> "CfgVehicles" >> typeOf GVAR(mine) >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(name))
if (!ACE_PIPEDEFAULT) exitWith {_menuDef};
#define __CUTTRIPWIRE localize "STR_ACE_SYS_EXPLOSIVES_CUT_TRIPWIRE"
#define __HIDESTAKE localize "STR_ACE_SYS_EXPLOSIVES_HIDE_STAKE"
#define __ACTIVATE format [localize "STR_ACE_SYS_EXPLOSIVES_ACTIVATE",__DN]
#define __DEACTIVATE format [localize "STR_ACE_SYS_EXPLOSIVES_DEACTIVATE",__DN]
#define __DEFUSE format [localize "STR_ACE_SYS_EXPLOSIVES_DEFUSE",__DN] //"Defuse %1" // "%1 entschärfen"
#define __ARM format [localize "STR_ACE_SYS_EXPLOSIVES_ARM",__DN]		//"Arm %1" // "%1 scharf machen"
#define __DISARM format [localize "STR_ACE_SYS_EXPLOSIVES_DISARM",__DN] //"Take %1" // "%1 nehmen"
#define __TRIPWIRE localize "STR_ACE_SYS_EXPLOSIVES_ATTACH_TRIPWIRE"
#define __PARM_TRIPWIRE localize "STR_ACE_SYS_EXPLOSIVES_ATTACH_PARM_TRIPWIRE"
#define __CLACKER localize "STR_ACE_SYS_EXPLOSIVES_ATTACH_CLACKER"
#define __SIGHTIN format [localize "STR_ACE_SYS_EXPLOSIVES_SIGHT_IN",__DN]
#define __TIMER localize "STR_ACE_SYS_EXPLOSIVES_SET_TIMER"
#define __SUBMERGE format [localize "STR_ACE_SYS_EXPLOSIVES_SUBMERGE",__DN]
#define __ANTISUMBERGE format [localize "STR_ACE_SYS_EXPLOSIVES_ANTISUBMERGE",__DN]
#define __SETUP format [localize "STR_ACE_SYS_EXPLOSIVES_SETUP",__DN]
#define __PICKUP_CLACKER localize "STR_ACE_SYS_EXPLOSIVES_PICKUP_CLACKER"
#define __ALIVE alive GVAR(mine)

#define __DEFUSE_MENU [__DEFUSE, { GVAR(mine) spawn FUNC(action_defuse) },"", "", "", -1, 1, (GVAR(mine) isKindOf "ACE_Explosive_Object" && {!_cI})]

#define __LEVEL (_target getVariable [QGVAR(level),0])
#define __SUBMERGE_MENU [__SUBMERGE, { [GVAR(mine), -1] spawn FUNC(action_submerge)},"","","",-1,!(_target getVariable [QGVAR(burry),false]),(_cBB && {!_iOR} && {!_iIB} && {__LEVEL in [0,-1,-2]})], \
[__ANTISUMBERGE, { [GVAR(mine), 1, player] spawn FUNC(action_submerge)},"","","",-1,!(_target getVariable [QGVAR(burry),false]),__LEVEL != 0]

GVAR(mine) = _target;
if (GVAR(mine) getVariable [QGVAR(notamper), false]) exitWith {_menuDef};

/*
Interaction with mines to place, setup, arm or picking them up, requires them to be in Interaction State, defined by GVAR(canInteract) set to true.
Once armed, tripped or manipulated in any other way, no further interaction is possible, except an option to defuze the mine

Special cases like SLAM anti tamper mode or Pipebomb Command mode are handled seperately where necessary
*/

_cI = (__ALIVE && {_target getVariable [QGVAR(canInteract), false]} && {!(_target call FUNC(check_disabled))});		// canInteract
_iOR = isOnRoad _target;																							// isOnRoad
_iIB = [player, 1] call ACE_fnc_inBuilding;																			// isInBuilding
_cBB = getNumber(configFile >> "CfgVehicles" >> typeOf _target >> "ACE" >> "ACE_EXPLOSIVES" >> "bury") in [1,2];	// canBeBuried

// DEBUG LOG
TRACE_1("",__TYPE);
TRACE_2("",_target,(GVAR(mine)));
TRACE_3("",_cI,_iOR,_iIB);

	switch (toUpper (__TYPE)) do {
	// Claymore
		case "M18": {
			_menus =
			[
				[
					["main", "M18", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(M18\disarm)},"","","",-1,1,_cI],
						[__CLACKER,{GVAR(mine) spawn COMPILE_FILE(M18\attach_clacker)},"","","",-1,1,_cI],					
						[__TRIPWIRE,{GVAR(mine) spawn COMPILE_FILE(M18\attach_tripwire)},"","","",-1,1,_cI],							
						[__SIGHTIN,{GVAR(mine) spawn COMPILE_FILE(M18\peep_sight)},"","","",-1,1,_cI],
						__DEFUSE_MENU,
						__SUBMERGE_MENU
					]
				]
			];
		};
	// DM12 PARM1
		case "DM12": {
			_menus =
			[
				[
					["main", "DM12", _menuRsc],
					[
						[__DEACTIVATE,{GVAR(mine) spawn COMPILE_FILE(DM12\deactivate)},"","","",-1,1,GVAR(mine) getVariable [QGVAR(active),false]], 			// Deactivate PARM // If activated only = OFF
						[__ACTIVATE,{GVAR(mine) spawn COMPILE_FILE(DM12\activate)},"","","", -1,1,_cI && {GVAR(mine) getVariable [QGVAR(tw),false]}], 						// Activate PARM // If optical cable is attached only    = ON
						[__PARM_TRIPWIRE,{GVAR(mine) spawn COMPILE_FILE(DM12\attach_tripwire)},"","","",-1,1,_cI], 	// Always
						[__SIGHTIN,{GVAR(mine) spawn COMPILE_FILE(DM12\peep_sight)},"","","",-1,1,_cI],				// Always
						[__DEFUSE,{GVAR(mine) setVariable [QGVAR(arm),false,true]},"","","",-1,1,GVAR(mine) getVariable [QGVAR(arm),false] && {!GVAR(mine) getVariable [QGVAR(active),false]}],
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(DM12\disarm)},"","","",-1,1,alive GVAR(mine)]
						//__DEFUSE_MENU,																				// ?
						//__SUBMERGE_MENU																				// Always
					]
				]
			];
		};
		
	// Mon50
		case "MON50": {
			_menus =
			[
				[
					["main", "MON-50", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(MON50\disarm)},"","","",-1,1,_cI],
						[__CLACKER,{GVAR(mine) spawn COMPILE_FILE(MON50\attach_clacker)},"","","",-1,1,_cI],							
						[__TRIPWIRE,{GVAR(mine) spawn COMPILE_FILE(MON50\attach_tripwire)},"","","",-1,1,_cI],
						[__SIGHTIN,{GVAR(mine) spawn COMPILE_FILE(MON50\peep_sight)},"","","",-1,1,_cI],
						__DEFUSE_MENU,
						__SUBMERGE_MENU	
					]
				]
			];
		};
	// C4
		case "C4": {
			_hT = GVAR(mine) getVariable [QGVAR(timer),-1];	// hasTimer
			_menus =
			[
				[
					["main", "C4", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(C4\disarm)},"","","",-1,1,_cI],
						[__TIMER,{[GVAR(mine)] call FUNC(action_fuse)},"","","",-1,1,_cI && {_hT < 0}],
						[__CLACKER,{GVAR(mine) spawn COMPILE_FILE(C4\attach_clacker)},"","","",-1,1,_cI && {_hT < 0}],
						[__ARM,{GVAR(mine) spawn COMPILE_FILE(SATCHEL\arm) },"","","",-1,1,_cI && {_hT > 0}],
						__DEFUSE_MENU
					]
				]
			];
		};
	// PMN 1 + 2 + 3 + PPM2 	
		case "PMN": {
			_menus =
			[
				[
					["main", "POMZ", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(PMN\disarm)},"","","", -1,1,_cI],
						[__ARM,{GVAR(mine) spawn COMPILE_FILE(PMN\arm)},"","","", -1,1,_cI],
						__DEFUSE_MENU,
						__SUBMERGE_MENU	
					]
				]
			];
		};
	// POMZ
		case "POMZ": {
			_menus =
			[
				[
					["main", "POMZ", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(POMZ\disarm)},"","","", -1,1,_cI],
						[__TRIPWIRE,{GVAR(mine) spawn COMPILE_FILE(POMZ\attach_tripwire)},"","","",-1,1,_cI],
						__DEFUSE_MENU,
						__SUBMERGE_MENU	
					]
				]
			];
		};
	// Tripflare
		case "M49": {
			_menus =
			[
				[
					["main", "M49A1", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(M49\disarm)},"","","", -1,1,_cI],
						[__TRIPWIRE,{GVAR(mine) spawn COMPILE_FILE(M49\attach_tripwire)},"","","",-1,1,_cI],
						__DEFUSE_MENU	
					]
				]
			];
		};
	// Claymore
		case "DM16": {
			_menus =
			[
				[
					["main", "DM16", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(DM16\disarm)},"","","", -1,1,_cI],
						[__TRIPWIRE,{GVAR(mine) spawn COMPILE_FILE(DM16\attach_tripwire)},"","","",-1,1,_cI],
						__DEFUSE_MENU	
					]
				]
			];
		};		
	// Betty
		case "M16": {
			_menus =
			[
				[
					["main", "M16A1", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(M16\disarm)},"","","",-1,1,_cI],
						[__TRIPWIRE,{GVAR(mine) spawn COMPILE_FILE(M16\attach_tripwire)},"","","",-1,1,_cI],
						[__ARM,{GVAR(mine) spawn COMPILE_FILE(M16\arm)},"","","", -1,1,_cI],
						__DEFUSE_MENU,
						__SUBMERGE_MENU	
					]
				]
			];
		};
	// DM31
		case "DM31": {
			_menus =
			[
				[
					["main", "DM31", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(DM31\disarm)},"","","",-1,1,_cI],
						[__TRIPWIRE,{GVAR(mine) spawn COMPILE_FILE(DM31\attach_tripwire)},"","","",-1,1,_cI],
						__DEFUSE_MENU,
						__SUBMERGE_MENU	
					]
				]
			];
		};
	// OSM-4
		case "OSM4": {
			_menus =
			[
				[
					["main", "OSM4", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(OSM4\disarm)},"","","",-1,1,_cI],
						[__TRIPWIRE,{GVAR(mine) spawn COMPILE_FILE(OSM4\attach_tripwire)},"","","",-1,1,_cI],
						__DEFUSE_MENU,
						__SUBMERGE_MENU	
					]
				]
			];
		};
	// SLAM
		case "M2" : {
			_menus =
			[
				[
					["main", "SLAM", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(M2\disarm)},"","","",-1,1,_cI],
						[__SETUP,{GVAR(mine) spawn COMPILE_FILE(M2\setup)},"","","",-1,1,_cI],
						[__SIGHTIN,{GVAR(mine) spawn COMPILE_FILE(M2\peep_sight)},"","","",-1,1,_cI],
						__DEFUSE_MENU	
					]
				]
			];
		};
	// Satchel	
		case "SATCHEL": {
			_hT = GVAR(mine) getVariable [QGVAR(timer),-1];	// hasTimer
			_aT = "sys_explosives" == GVAR(mine) getVariable [QUOTE(GVARMAIN(attachedBy)),""];
			_menus =
			[
				[
					["main", "Pipebomb", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(SATCHEL\disarm)},"","","",-1,1,_cI],
						[__TIMER,{[GVAR(mine)] call FUNC(action_fuse)},"","","",-1,1,_cI && {_hT < 0}],
						[__ARM,{GVAR(mine) spawn COMPILE_FILE(SATCHEL\arm) },"","","",-1,1,_cI && {_hT > 0}],
						[__CLACKER,{GVAR(mine) spawn COMPILE_FILE(SATCHEL\attach_clacker)},"","","",-1,1,_cI && {_hT < 0} && {!_aT}],
						__DEFUSE_MENU		
					]
				]
			];
		};
	// IEDs
		case "IED": {
			private ["_vehicle","_dn"];
			_vehicles = (position player) nearEntities ["LandVehicle", 7.2];
			_vehicle = objNull;
			_dn = "";
			GVAR(aV) = [];
			if (count _vehicles > 0) then {
				_vehicle = _vehicles select 0;
				_dn = getText (configFile >> "CfgVehicles" >> typeOf _vehicle >> "displayName");
				GVAR(aV) = [GVAR(mine),_vehicle];
			};
			_cAI = (__ALIVE && {!isNull _vehicle} && {!_cI});	// canAttachIED
			_menus =
			[
				[
					["main", "IED", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(IED\disarm)},"","","",-1,1,_cI],
						[format["<t size='0.7'>"+ localize "STR_ACE_SYS_EXPLOSIVES_ATTACH" + "</t>",__DN,_dn],{GVAR(aV) spawn COMPILE_FILE(IED\attachTo)},"","","",-1,1,_cAI],						
						[__TRIPWIRE,{GVAR(mine) spawn COMPILE_FILE(IED\attach_tripwire)},"","","",-1,1,_cI],
						[__CLACKER,{GVAR(mine) spawn COMPILE_FILE(IED\attach_mobile)},"","","",-1,1,_cI],
						__DEFUSE_MENU,
						__SUBMERGE_MENU	
					]
				]
			];
		};
	// Mine, MineE
		case "MINE": {
			_menus =
			[
				[
					["main", "Mine", _menuRsc],
					[
						[__DISARM,{[GVAR(mine),true] spawn COMPILE_FILE(MINE\disarm)},"","","",-1,1,_cI],					
						[__ARM,{GVAR(mine) spawn COMPILE_FILE(MINE\arm)},"","","",-1,1,_cI],				
						__DEFUSE_MENU,
						__SUBMERGE_MENU	
					]
				]
			];
		};
	// Tripwire
		case "TRIPWIRE": {
			_menus =
			[
				[
					["main", "Defuse", _menuRsc],
					[
						[__CUTTRIPWIRE,{GVAR(mine) call FUNC(action_cutwire)},"","","",-1,1,(GVAR(mine) isKindOf "ACE_Stake")],
						[__HIDESTAKE,{GVAR(mine) call FUNC(action_hidestake)},"","","",-1,1,(GVAR(mine) isKindOf "ACE_Stake")]
					]
				]
			];
		};
	// Clacker
		case "CLACKER": {
			_menus =
			[
				[
					["main", "Clacker", _menuRsc],
					[
						[__PICKUP_CLACKER,{GVAR(mine) call FUNC(action_clacker)},"","","",-1,1,(GVAR(mine) isKindOf "ACE_Clacker")]						
					]
				]
			];
		};
	// Default
		default {
			_menus = [[["main","",_menuRsc],[["","","","","",-1,1,false]]]];
		};
	};

//-----------------------------------------------------------------------------

{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this}else{""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _params, __FILE__];
};

_menuDef // return value
