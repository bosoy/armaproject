//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

PARAMS_2(_target,_params);

_menuName = "";
_menuRsc = "buttonList";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__]};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};

private ["_ied_inventory","_explosive_devices","_ied","_explosives_array","_explosives_name","_explosives_magazine","_explosives_action"];
_explosive_devices = ["ACE_DM21AT","ACE_DM31AT","ACE_M18", "ACE_C4", "ACE_DM12B1", "ACE_Pomz", "ACE_M16", "ACE_M49", "ACE_DM16", "ACE_M2SLAM", "ACE_M4SLAM", "ACE_MON50", "ACE_Pipebomb", "ACE_SchMiDM31", "ACE_OSM4","ACE_Mine","ACE_MineE","ACE_DM12PARM1","ACE_PMN1","ACE_PMN2","ACE_PMN3","ACE_PPM2"];
_ied = ["BAF_ied_v1","BAF_ied_v2","BAF_ied_v3","BAF_ied_v4","PMC_ied_v1","PMC_ied_v2","PMC_ied_v3","PMC_ied_v4"];
_ied_inventory = ({_ied find _x != - 1} count (magazines player) > 0);

_explosives_array = [];
{
	_explosives_name = getText(configFile >> "CfgVehicles" >> _x >> "ACE" >> "ACE_EXPLOSIVES" >> "name");
	_explosives_magazine = getText(configFile >> "CfgVehicles" >> _x >> "ACE" >> "ACE_EXPLOSIVES" >> "mine_magazine");
	_explosives_action = "'" + _x + "' call ace_sys_explosives_fnc_action_place_mine";
	if (_explosives_magazine in (magazines player)) then {
		TRACE_1("Found Explosives Magazine",_explosives_magazine);
		_explosives_array set [count _explosives_array,	[format[localize "STR_ACE_SYS_EXPLOSIVES_PLACE",_explosives_name], _explosives_action, "", "", "", -1, 1, true]];
	};
} foreach _explosive_devices;

_menus =
[
	[
		["main", localize "STR_ACE_MENU_EQUIPPLAYER", _menuRsc],
		[
			[localize "STR_INT_ACE_SYS_EXPLOSIVES_MENUNAME", "", "", "",
				[QPATHTO_F(fnc_menuDef_Self), "explosives", 1],
				-1, 1, ((count _explosives_array > 0) || {_ied_inventory}) && {ACE_SELFINTERACTION_RESTRICTED} && {ACE_PIPEDEFAULT}],
			[localize "STR_WDN_ACE_CELLPHONE",
				{ player spawn COMPILE_FILE(IED\call) },
				"", "", "", -1, 1, "ACE_Cellphone" in (weapons player)]
		]
	]
];

if (_menuName == "explosives") then {
	_menus set [count _menus,
		[
			["explosives", localize "STR_INT_ACE_SYS_EXPLOSIVES_MENUNAME", "popup", ""],
			[
				[format[localize "STR_ACE_SYS_EXPLOSIVES_PLACE",getText(configFile >> "CfgMagazines" >> "BAF_ied_v1" >> "displayName")],
				{ player call FUNC(action_place_ied) },
				"", "", "", -1, 1, ({["BAF_ied_v1","BAF_ied_v2","BAF_ied_v3","BAF_ied_v4","PMC_ied_v1","PMC_ied_v2","PMC_ied_v3","PMC_ied_v4"]  find _x != - 1} count (magazines player) > 0)]				
			] + _explosives_array
		]
	];
};

_menuDef = [];
{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this} else {""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _this, __FILE__];
};

_menuDef // return value