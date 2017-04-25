// #define DEBUG_MODE_FULL
#include "script_component.hpp"
scriptName "Functions\misc\fn_PosToGrid.sqf";
/*
	File: PosToGrid.sqf
	Author: Karel Moricky

	Description:
	Converts array position to map grid position.

	Parameter(s):
	_this: Object, Array in format position or String with marker name

	Returns:
	Array in format ["X","Y"]
*/
private ["_x","_y","_xgrid","_ygrid","_xcoord","_ycoord"];

_x = -1;
_y = -1;

_grid = _this call ace_fnc_mapCoord;
_xGrid = floor (call compile (_grid select 0) / 10);
_yGrid = floor (call compile (_grid select 1) / 10);

_xcoord =
	if (_xgrid >= 100) then {
		str _xgrid;
	} else {
		if (_xgrid >= 10) then {
			"0" + str _xgrid;
		} else {
			"00" + str _xgrid;
		};
	};

_ycoord =
	if (_ygrid >= 100) then {
		str _ygrid;
	} else {
		if (_ygrid >= 10) then {
			"0" + str _ygrid;
		} else {
			"00" + str _ygrid;
		};
	};


#ifdef DEBUG_MODE_FULL
	diag_log [_x, _y, _xGrid,_yGrid, _xCoord, _yCoord];
#endif

[_xCoord,_yCoord]
