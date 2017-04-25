#include "script_component.hpp"

try {
  _table = "ace_sys_menu_weapons";
	if !(_table call sqlTableExists) then {
		format["CREATE TABLE %1(id, name, weaps, mags)", _table] call SQL;
	};
} catch {
  ["SQL Error: " + _exception] call CBA_fnc_debug;
};

// Prepare Functions & Scripts
PREP(menuArmaLib);

ace_sys_menu_enum = {
	private ["_r"];
	_r = []; {
		_r = _r + [_x select (_this select 1)];
	} forEach (_this select 0);
	_r
};
