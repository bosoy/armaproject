#include "script_component.hpp"
#define __scriptname fMenuArmaLib


// General Positions
#define __sqlId 0
#define __sqlName 1

// DAC Zones positions
#define __sqlContents 2
#define __sqlWorldName 3
#define __sqlZoneId 4
#define __sqlLinkId 5

// Weapons Positions
#define __sqlWeaps 2
#define __sqlMags 3

private ["_table", "_ar", "_c", "_lastId", "_lastEntry", "_r"];
_table = _this select 1;
_ar = _table call SIX_fSqlGet;
_c = (count _ar) - 1; // First row is table headers
if (_c > 0) then { _lastEntry = _ar select _c; _lastId = (_lastEntry select __sqlId) } else { _c = 0; _lastEntry = -1; _lastId = -1 };

private ["_sql", "_sql2", "_load", "_menu"];
switch (_table) do {
	// Could be read from a config
	case "ace_sys_bc_zones_multi": {
		_sql = { format["name = '%1', contents = '%2', worldname = '%3', zoneid = %4, linkid = %5", _name, _contents, worldName, SIX_BC_DAC_CUSTOM_ID, SIX_BC_DAC_CUSTOM_LINK] };
		_sql2 = { [_id, _name, _contents, worldName, SIX_BC_DAC_CUSTOM_ID, SIX_BC_DAC_CUSTOM_LINK] };
		_menu = QPATHTO_F(menu_bc);
		_load = {
			SIX_BC_SET_ZONES = call compile (_lastEntry select __sqlContents);
			SIX_BC_DAC_CUSTOM_ID = (_lastEntry select __sqlZoneId);
			SIX_BC_DAC_CUSTOM_LINK = (_lastEntry select __sqlLinkId);
			[2] spawn ace_sys_bc_fnc_menuDac;
			// needed since we need to update the editing of the zones
			closeDialog 0;
			execVM _menu; // reopen menu
		};
	};
	case "ace_sys_menu_weapons": {
		_sql = { format["name = '%1', weaps = '%2', mags = '%3'", _name, weapons player, magazines player] };
		_sql2 = { [_id, _name, weapons player, magazines player] };
		_menu = "\x\ace\addons\sys_menu\CreatePopupMenu.sqf";
		_load = { [player, (call compile (_lastEntry select __sqlWeaps)), (call compile (_lastEntry select __sqlMags))] spawn CBA_fSwitchWeapons };
	};
};

switch (_this select 0) do {
	// Save (Insert or Update) Current Record
	case 0: {
		private ["_contents", "_id", "_name", "_act", "_msg"];
		_contents = _this select 2;
		// Crappy Hack lol
		if !(isNil "ace_sys_menu_fnc_menuArmaLib_RECORDID") then {
			if (ace_sys_menu_fnc_menuArmaLib_RECORDID != -1) then {
				_this = _this + [ace_sys_menu_fnc_menuArmaLib_RECORDID];
			};
		};
		// Decide on update or insert
		if (count _this > 3) then {
			_id = _this select 3;
			_act = { [_table, call _sql, format["id = %1", _id]] call SIX_fSqlUpdate };
		} else {
			_id = _lastId + 1;
			_act = { [_table, call _sql2] call SIX_fSqlInsert };
			_c = _c + 1;
		};
		_name = "custom" + str(_id); // Should become editable :D

		_r = call _act;
		if (_r) then {
			_msg = format["Saved Record, Count is now %1, id was: %2, Record selection Reset", _c, _id];
			ace_sys_menu_fnc_menuArmaLib_RECORDID = -1;
			closedialog 0;
			execVM _menu;
		} else {
			_msg = format["Not saved, Count is now %1, id was: %2", _c, _id];
		};
		hint _msg;
	};

	// Load Record (no id specified; load last. id specified; load where id = _id
	case 1: {
		private ["_id", "_msg"];
		// Crappy Hack lol
		if !(isNil "ace_sys_menu_fnc_menuArmaLib_RECORDID") then {
			if (ace_sys_menu_fnc_menuArmaLib_RECORDID != -1) then {
				_this = _this + [ace_sys_menu_fnc_menuArmaLib_RECORDID];
			};
		};
		if (count _this > 2) then {
			_id = _this select 2;
			_ar = format["%1 WHERE id = %2", _table, _id] call SIX_fSqlGet;
			_c = (count _ar) - 1;
			if (_c > 0) then {
				_lastEntry = _ar select _c;
			};
		} else {
			_id = _lastId;
		};
		if (_c > 0) then {
			call _load;
			_msg = format["BC: Loaded Record (Name: %1, ID: %2)", _lastEntry select __sqlName, _id];
		} else {
			_msg = "BC: No Records available to load";
		};
		hint _msg;
	};

	// Delete Record
	case 2: {
		private ["_id", "_msg"];
		// Crappy Hack lol
		if !(isNil "ace_sys_menu_fnc_menuArmaLib_RECORDID") then {
			if (ace_sys_menu_fnc_menuArmaLib_RECORDID != -1) then {
				_this = _this + [ace_sys_menu_fnc_menuArmaLib_RECORDID];
			};
		};
		if (count _this > 2) then {
			_id = _this select 2;
			_ar = format["%1 WHERE id = %2", _table, _id] call SIX_fSqlGet;
			_c = (count _ar) - 1;
		} else {
			_id = _lastId;
		};
		if (_c > 0) then {
			_r = [_table, format["id = %1", _id]] call SIX_fSqlDelete;
			if (_r) then {
				_msg = "BC: Record Removed (ID: %1), Record selection Reset";
				ace_sys_menu_fnc_menuArmaLib_RECORDID = -1;
				closedialog 0;
				execVM _menu;
			} else {
				_msg = "BC: Record not Removed, SQL Error (ID: %1)";
			};
		} else {
			_msg = "BC: No records to remove";
		};
		hint format[_msg, _id];
	};

	// Set Record ID?
	case 3: {
		ace_sys_menu_fnc_menuArmaLib_RECORDID = _this select 2;
	};

	// Enumurate available id's
	case 11: {
		_r = [_ar, 0] call ace_sys_menu_enum;
	};
};
if !(isNil "_r") then { _r };
