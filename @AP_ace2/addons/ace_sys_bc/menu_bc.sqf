#include "script_component.hpp"
/*
	by Sickboy (sb_at_dev-heaven.net)
*/

_mainItems = []; _MenuStructureArray = [];
_group = group player;
private ["_lead", "_inVeh", "_veh", "_rf"];
_lead = false; _inVeh = false; _rf = false;
_rf = serverCommandAvailable "#kick"; if !(isNil "ace_referee") then { if (ace_referee) then { _rf = true } };
if (([player] call FUNC(getName)) in GVAR(commanders)) then { GVAR(commander) = true };

//if (player == (leader player)) then { _cmd = true }; // Must be done like this because if there is no commander, it would otherwise return BOOL

_veh = vehicle player;
if (_veh != player) then {
	if ( ((_veh isKindOf "LandVehicle") || (_veh isKindOf "Air")) ) then { _inVeh = true };
};

if (player == (leader player)) then { _lead = true };
if (getNumber(configFile >> "CfgVehicles" >> typeOf player >> "attendant") == 1) then { _lead = true };

// load the admins menu items
_MenuStructureArray = _MenuStructureArray + call ace_sys_menu_fnc_admins;


if (GETVAR(ready)) then {
	_title = "Battle Center Support >"; _short = "SIX_BC_SUP"; _items = [];
	[_mainItems, _title, _short] call FUNC(addSubMenu);
	[_items, "Call Airstrike", '[12, 1] spawn FUNC(menuAI)'] call FUNC(addAction);
	[_items, "Call Artillery (Shell 125)", '[12, 0, 901] spawn FUNC(menuAI)'] call FUNC(addAction);
	[_items, "Call Artillery (SmokeShell)", '[12, 0, 902] spawn FUNC(menuAI)'] call FUNC(addAction);
	[_items, " == Support Spread == "] call FUNC(addHeader); {
		[_items, (str(_x)+"m"), format["SIX_BC_SUPSPREAD = %1; hint 'BC: Support Spread set to: %1'",_x], "noclose"] call FUNC(addAction);
	} forEach [5,10,15,25,50,75,100];
	[_menuStructureArray, _title, _short, _items] call FUNC(addMenu);

	if !(_lead) then {
		if ((player distance (GETVAR(_side) call FUNC(startpos))) < 200) then {
			[_mainItems, "Teleport to Team", "player setPos (getPos (leader player))"] call FUNC(addAction);
		};
	} else {
		if (((player distance (GETVAR(_side) call FUNC(startpos))) < 200) && {(count (units player))>1}) then {
			// Maybe should be possible to determine/choose which teammember to teleport to?
			[_mainItems, "Teleport to Team", "player setPos (getPos (((units player) - [player]) select 0))"] call FUNC(addAction);
		};
	};
/*
	if (_inveh) then {
		_title = "Cargo Control"; _short = "SIX_BC_CARGO"; _items = [];
		SIX_BC_BOXES = nearestObjects [_veh, ["ReammoBox"], 15];
		if (count SIX_BC_BOXES > 0) then {
			[_items, "Load Crate", "deleteVehicle (SIX_BC_Boxes select 0)"] call FUNC(addAction);
		} else { {
				[_items, "Unload AmmoBox", format["['%1', %2] call CBA_network_fnc_cV", _x, getPos _veh]] call FUNC(addAction);
			} forEach ["SIX_AmmoBox"]; // ["SIX_AmmoBoxWest", "SIX_AmmoBoxEast", "SIX_AmmoBoxGuer"];
		};
		if (count _items > 0) then {
			[_mainItems, _title, _short] call FUNC(addSubMenu);
			[_MenuStructureArray, _title, _short] call FUNC(addMenu);
		};
	};
*/
};

if (GETVAR(_state) < 2 || GVAR(commander) || _rf) then {
	_title = "Battle Center Setup >"; _short = "SIX_BC"; _items = [];
	[_mainItems, _title, _short, "break"] call FUNC(addSubMenu);
	[_menuStructureArray, _title, _short, _items] call FUNC(addMenu);
	if !(GETVAR(modify)) exitWith {
		[_items, "Enable Modification Mode (else start in 45sec)", '[60] spawn FUNC(menu)'] call FUNC(addAction);
	};
	if (_rf || GVAR(commander) || (_lead && GETVAR(_state) < 2)) then {

		[_items, "Enable Weapon Box at Spawn", '[23] spawn FUNC(menu)', "noclose"] call FUNC(addAction);
		[_items, "Weapon Box at Mission Start?", '[44] spawn FUNC(menu)', "noclose"] call FUNC(addAction);
		[_items, "Set Player Start Position", '[21] spawn FUNC(menu)', "noclose"] call FUNC(addAction);

		_title0 = "Select AI >"; _short0 = "SIX_BC_AI_SELECT"; _aiItems = [];
		[_items, _title0, _short0] call FUNC(addSubmenu);
		_a = [GVAR(ai_hash),
		{ [_aiItems, _key, format['[70, "%1"] call FUNC(menu)', _key]] call FUNC(addAction) }] call CBA_fnc_hashEachPair;
		[_menuStructureArray, _title0, _short0, _aiItems] call FUNC(addMenu);

		_title0 = "AI Settings >"; _short0 = "SIX_BC_AI_SETTINGS"; _aiItems = [];
		[_items, _title0, _short0] call FUNC(addSubmenu);
		_a = [GVAR(ai_hash), GVAR(AI) select 0] call CBA_fnc_hashGet;
		_options = _a select 0;
		{ [_aiItems, _x, format['[71, "%1"] call FUNC(menu)', _x], "noclose"] call FUNC(addAction) } forEach _options;
		[_menuStructureArray, _title0, _short0, _aiItems] call FUNC(addMenu);

		_title0 = "Select Zone >"; _short0 = "SIX_BC_ZONE_SELECT"; _selItems = [];
		[_items, _title0, _short0] call FUNC(addSubmenu);
		[_selItems, "Unselect current working zone(s)", '[55, ""] spawn FUNC(menu)', "noclose"] call FUNC(addAction);
		{ [_selItems, _x select 4, format['[55, "%1"] spawn FUNC(menu)', _x select 4], "noclose"] call FUNC(addAction) } forEach GVAR(zones_mine);
		[_menuStructureArray, _title0, _short0, _selitems] call FUNC(addMenu);

		[_items, "Set Zone Position", '[13] spawn FUNC(menu)', "noclose"] call FUNC(addAction);

		_sizes = [25, 50, 100, 200, 250, 500, 1000, 2000];
		// X-Size
		_title0 = "Set Zone X-Size >"; _short0 = "SIX_BC_ZONE_SIZE_X"; _sizeItems = [];
		[_items, _title0, _short0] call FUNC(addSubmenu);
		{ [_sizeItems, format["%1m",_x], format['[15, %1] spawn FUNC(menu)', _x], "noclose"] call FUNC(addAction) } forEach _sizes;
		[_menuStructureArray, _title0, _short0, _sizeitems] call FUNC(addMenu);

		// Y-Size
		_title0 = "Set Zone Y-Size >"; _short0 = "SIX_BC_ZONE_SIZE_Y"; _sizeItems = [];
		[_items, _title0, _short0] call FUNC(addSubmenu);
		{ [_sizeItems, format["%1m",_x], format['[16, %1] spawn FUNC(menu)', _x], "noclose"] call FUNC(addAction) } forEach _sizes;
		[_menuStructureArray, _title0, _short0, _sizeitems] call FUNC(addMenu);


		_title0 = "Import/Export >"; _short0 = "SIX_BC_ZONE_PORT"; _portItems = [];
		[_portItems, "Export Zones to Clipboard", '[52] spawn FUNC(menu)', "noclose", "break"] call FUNC(addAction);
		[_portItems, "Import Zones from Clipboard", '[53] spawn FUNC(menu)', "noclose", "break"] call FUNC(addAction);
		[_items, _title0, _short0] call FUNC(addSubmenu);
		[_menuStructureArray, _title0, _short0, _portItems] call FUNC(addMenu);

		[_items, "Realtime Editor >", "AdminRTE"] call FUNC(addSubMenu);

		[_items, " == Submit == "] call FUNC(addHeader);
		[_items, "Submit and Start Mission", '[88] spawn FUNC(menu)'] call FUNC(addAction);
		[_items, "Submit and Clear Queue", '[87] spawn FUNC(menu)', "noclose"] call FUNC(addAction);
		[_items, "WARNING: Clear Queue!", '[89] spawn FUNC(menu)', "noclose"] call FUNC(addAction);
		[_items, " == Other == "] call FUNC(addHeader);
		[_items, "Spawn Ammobox >", "AdminCrates2"] call FUNC(addSubMenu);

		// Training Mode
		_title = "Training Mode >"; _short = "SIX_BC_TRAINING"; _trnItems = [];
		[_items, _title, _short] call FUNC(addSubMenu);
		[_trnItems, "Enable Training Mode", '[11, true] spawn FUNC(menu)'] call FUNC(addAction);
		[_trnItems, "Disable Training Mode", '[11, false] spawn FUNC(menu)'] call FUNC(addAction);
		[_menuStructureArray, _title, _short, _trnItems] call FUNC(addMenu);

		[_items, "Time of Day Setting (00:00-11:00) >", "AdminTime0"] call FUNC(addSubMenu);
		[_Items, "Time of Day Setting (12:00-23:00) >", "AdminTime1"] call FUNC(addSubMenu);
		[_Items, "Weather Overcast Setting >", "AdminWeather0"] call FUNC(addSubMenu);
		[_Items, "Weather Fog Setting >", "AdminWeather1"] call FUNC(addSubMenu);
		[_Items, "Weather Rain Setting >", "AdminWeather2"] call FUNC(addSubMenu);
		// [_Items, "Weather Snow Setting >", "AdminWeather3"] call FUNC(addSubMenu);

		// Setup custom menu for given AI
		switch (GVAR(AI) select 0) do {
			case "DAC": {
				call COMPILE_FILE(menu_bc_dac);
			};
			default {
				_config = configFile >> "CfgGroups";
				for "_i" from 0 to (count _config) - 1 do {
					_side = _config select _i;
					if (isClass _side) then {
						_title2 = format["Spawn %1 >", configName(_side)]; _short2 = format["spawn_%1", configName(_side)]; _sideItems = [];
						[_mainItems, _title2, format["'%1' execVM '%2'", configName _side, QUOTE(PATHTO(menu_bc_side))]] call FUNC(addAction);
					};
				};
			};
		};
	};
};

[_mainItems, "Return to Main Menu", QUOTE([] spawn COMPILE_FILE2(PATHTO_SYS(PREFIX,sys_menu,CreatePopupMenu)))] call FUNC(addAction);

//-----------------------------------------------------------------------------
// Main Menu
[_MenuStructureArray, "Six Battle Center >", "MainMenu", _mainitems] call FUNC(addMenu);


//-----------------------------------------------------------------------------
// Create Menu
//["CreatePopupMenu.sqf", _MenuStructureArray] call fn_DebugAppend; // debug
_MenuStructureArray spawn COMPILE_FILE2(PATHTO_SYS(PREFIX,sys_menu,PopupMenu));
//-----------------------------------------------------------------------------
