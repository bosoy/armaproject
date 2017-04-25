//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

#define __LOAD (localize "STR_ACE_UA_LOAD") 				// "Load %1 into %2"
#define __UNLOAD (localize "STR_ACE_PRISONUNLOAD") 	// "Get unit out of vehicle"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus", "_isknockeddown"];

PARAMS_2(_target,_params);

_menuDef = [];
_menuName = "";
_menuRsc = "popup";

_distance = if !(_target isKindOf "CAManBase") then {10} else {2.5};

if ((_target distance player) > _distance) exitWith { closeDialog 0; _menuDef }; // TODO: Menu range is way to big, should not be > 2.5 - 3 m ! // Menu title still becomes shown though

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__]};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};

GVAR(targets) = [_target, "MAN"];

private ["_name"];
if (_target isKindOf "CAManBase") then {
	_name = localize "STR_ACE_NO_UNIT"; // "body"
	if (alive _target) then {if (name _target != "Error: No unit") then {_name = name _target}};
} else {
	_name = getText (configFile >> "cfgVehicles" >> typeOf _target >> "displayName");
	if (_name == "") then {_name = typeOf _target};
};

if (_menuName == "main") then {
	_badKarma = rating _target < 0;
	_isAlive = alive _target;
	_isFriend = (side (group _target) == side (group player));
	_isCivilian = (side (group _target) == civilian);
	_srrs = !(isNil "BIS_SRRS_init");

	_haskeycuffsleft = (player getVariable [QGVAR(keycuffsleft),5] > 0) && {"ACE_KeyCuffs" in (weapons player)};
	if (!_haskeycuffsleft && {"ACE_KeyCuffs" in (weapons player)}) then { // Reset
		player setVariable [QGVAR(keycuffsleft),5];
	};

	_unc = _target call ace_sys_wounds_fnc_isUncon;

	_hasBeenSearched = _target getVariable [QGVAR(searched),false];
	_cAE = ACE_SELFINTERACTION_RESTRICTED && {_haskeycuffsleft} && {_isAlive} && {!_isFriend} && {_srrs || {isPlayer _target} || {_hasBeenSearched}};	// canArrestEnemySoldier - only with SRRS module, that makes enemy surrender (surrender != capturing)
	_cAC = ACE_SELFINTERACTION_RESTRICTED && {_isAlive} && {_isCivilian} && {_haskeycuffsleft}; 									// canArrestCivilian

	_hasBeenSearched = _target getVariable [QGVAR(searched),false];
	
	_menus =
	[
		[
			["main", if (!_isFriend) then {" "} else {_name}, _menuRsc],
			[
				[localize "STR_DN_ACE_DISARM",
					{ [GVAR(targets) select 0] spawn FUNC(disarm) },
					"", "", "", -1, 1, _isAlive && {!_isFriend} && {_hasBeenSearched} && {ACE_SELFINTERACTION_RESTRICTED}],

				[localize "STR_DN_ACE_CUFF",
					{ [GVAR(targets) select 0,true] spawn FUNC(arrest) },
					"", "", "", -1, alive _target && {animationState player != "AmelPercMstpSlowWrflDnon_StrokeGun"}, !_unc && {(_cAE || {_cAC})} && {!(_target getVariable [QGVAR(cuffed),false])}],

				[localize "STR_DN_ACE_UNCUFF",
					{ [GVAR(targets) select 0,false] spawn FUNC(arrest) },
					"", "", "", -1, 1, alive _target && {_target getVariable [QGVAR(cuffed),false]} && {ACE_SELFINTERACTION_RESTRICTED}],
					
				[localize "STR_ACTION_GEAR",
					{ [GVAR(targets) select 0] spawn FUNC(gear) },
					"", "", "Gear", DIK_G, 1, ACE_SELFINTERACTION_RESTRICTED && {_isAlive} && {_isFriend}],

				[localize "STR_DN_ACE_SEARCH",
					{ [GVAR(targets) select 0] spawn FUNC(s_and_d) },
					"", "", "Gear", DIK_G, 1, ACE_SELFINTERACTION_RESTRICTED && {_isAlive} && {!_isFriend}],				

				[localize "STR_DN_ACE_REHAB",
					{ [GVAR(targets) select 0] spawn FUNC(rehab) },
					"", "", "", -1, 1, ACE_SELFINTERACTION_RESTRICTED && {_isAlive} && {_isFriend} && {_badKarma}]
			]
		]
	];
};

if (_menuName == "vehicle") then {
	cba_ui_cuffedPerson = objNull;
	private ["_listc", "_i"];
	_listc = nearestObjects [player, ["CAManBase"], 2]; // needs to stay nearestObjects, we want to handle dead units too
	_listc = _listc - [player]; // Player is always in the list
	if (count _listc > 0) then {
		cba_ui_cuffedPerson = _listc select 0;
	};
	
	_vehicle = if !(_target isKindOf "CAManBase") then {_target} else {objNull};
	TRACE_2("isNull vehicle",(isNull _vehicle),_vehicle);
	
	_hasTransportAbility = (getNumber(configFile >> "cfgVehicles" >> typeOf _vehicle >> "transportSoldier") > 0);
	_freeCargoSeats = 0;
	if (!(_vehicle isKindOf "ParachuteBase") && {!(_vehicle isKindOf "BIS_Steerable_Parachute")} && {!(_vehicle isKindOf "UAV")}) then {
		_freeCargoSeats = _vehicle emptyPositions "cargo";
	};
	// create list of handcuffed people inside vehicle
	_list = [];
	GVAR(cuffedlist) = [];

	TRACE_1("",_target);

	{
		if (alive _x && {_x getVariable [QGVAR(cuffed),false]}) then {
			TRACE_1("Found Handcuffed unit in vehicle",_x);
			PUSH(GVAR(cuffedlist),_x);
		};
	} forEach crew _target;

	TRACE_1("",GVAR(cuffedlist));

	// create menu to unload unconscious people from inside vehicle
	{
		if (alive _x) then {
			_cuffed2 = (_x getVariable [QGVAR(cuffed),false]) && {!(_x call ace_sys_wounds_fnc_isUncon)};
			if (_cuffed2) then {
				TRACE_1("Adding Found Handcuffed unit to list", _x);
				_list set [count _list,
						[format["<t size='0.6'>" + __UNLOAD + "</t>", name _x],
						format['[GVAR(cuffedlist) select %1] spawn FUNC(unloadPris)', _forEachIndex],
						"", name _x, "",-1, {alive _x} count (crew _target) > 0, 1]
				];
			};
		};
	} forEach GVAR(cuffedlist);

	TRACE_3("",cba_ui_cuffedPerson,_freeCargoSeats,_hasTransportAbility);
	_menus =
	[
		[
			["vehicle", "", _menuRsc],
			[
					[format["<t size='0.6'>" + __LOAD + "</t>", name cba_ui_cuffedPerson, _name],
					{ [cba_ui_target, player, -1, [cba_ui_cuffedPerson, cba_ui_target]] spawn FUNC(loadPris) },
					"", name cba_ui_cuffedPerson, "", DIK_D, 1, // don't use DIK_L
					_freeCargoSeats > 0 && {ACE_SELFINTERACTION_RESTRICTED} && {_hasTransportAbility} && {cba_ui_cuffedPerson isKindOf "CAManBase"} && {!isNull cba_ui_cuffedPerson} && {alive cba_ui_cuffedPerson} && {!(_target call CBA_fnc_locked)}&& {!(cba_ui_cuffedPerson call ace_sys_wounds_fnc_isUncon)}]
			] + _list
		]
	];
};

//-----------------------------------------------------------------------------

{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then {
	hintC format ["Error: Menu not found: %1\n%2", str _menuName, if (_menuName == "") then {_params} else {""}];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _params, __FILE__];
};

//TRACE_1("DIK_G",DIK_G);
//TRACE_2("",_menuName,_menuDef);
//TRACE_1("",ACE_SELFINTERACTION_RESTRICTED && {_isAlive} && {_isFriend});
_menuDef // return value
