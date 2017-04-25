// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_x", "_y", "_xGrid", "_yGrid", "_grid", "_obj"];

switch (typename _this) do
{
	//--- Coordinates
	case "ARRAY": {
		_x = _this select 0;
		_y = _this select 1;
		_obj = "ACE_LogicDummy" createVehicleLocal [_x,_y];
	};
	//--- Unit
	case "OBJECT": {
		_obj = _this;
	};
	//--- Marker
	case "STRING": {
		_x = markerpos _this select 0;
		_y = markerpos _this select 1;
		_obj = "ACE_LogicDummy" createVehicleLocal [_x,_y];
	};
	default {
		hintc format ["Bad input - %1.",typename _this];
	};
};

_grid = toArray (mapGridPosition _obj);
if (count _grid > 4) then {
	if (count _grid > 6) then {
		_xGrid = toString [_grid select 0, _grid select 1, _grid select 2, _grid select 3];
		_yGrid = toString [_grid select 4, _grid select 5, _grid select 6, _grid select 7];
	} else {
		_xGrid = toString [_grid select 0, _grid select 1, _grid select 2];
		_yGrid = toString [_grid select 3, _grid select 4, _grid select 5];
	};
} else {
	_xGrid = toString [_grid select 0, _grid select 1];
	_yGrid = toString [_grid select 2, _grid select 3];
};
deleteVehicle _obj;

_r = [_xGrid, _yGrid];
TRACE_1("Return",_r);

_r;
