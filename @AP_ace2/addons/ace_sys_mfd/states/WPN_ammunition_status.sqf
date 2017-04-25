//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_mfd\script_component.hpp"

TRACE_1("ENTER","");
private["_row", "_maxRows", "_maxCols", "_space", "_i"];

//_state = _this select 0;
PARAMS_1(_state);

[] call FUNC(clearAllText);
switch (GVAR(lastKeyPressed)) do {
	case "1": {
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN"];
	};
	default {
		_maxRows = ([] call FUNC(getMaxRows)) - 2;
		_row = 1;
		{
			if((_row + 3) > _maxRows) exitWith { _state };
	
			[_row, format["   Weapon: %1", (getText (configFile >> "CfgWeapons" >> _x >> "displayName"))]] call FUNC(setRowText);
			[(_row + 1), format["          Status: %1", ((vehicle player) ammo _x)]] call FUNC(setRowText);
			
			_row = _row + 3;
		} forEach weapons (vehicle player);

		_maxCols = [] call FUNC(getMaxCols);
		_space = "";
		_i = 0;
		while { _i < (_maxCols - 8) } do {
			_space = _space + " ";
			_i = _i + 1;
		};
		[(_maxRows + 1), format["%1 Back .1", _space]] call FUNC(setRowText);
	};
};

_state
