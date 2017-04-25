#include "script_component.hpp"

disableSerialization;

private ["_x","_y","_xgrid","_ygrid","_dsp","_dagrGrid"];

if (local player) then {

	135471 cutRsc ["DAGR_DISPLAY", "plain down"];
	_display = (uiNameSpace getVariable "DAGR_DISPLAY");

	_gridControl = _display displayCtrl 266851;
	_speedControl = _display displayCtrl 266858;
	_elevationControl = _display displayCtrl 266853;
	_headingControl = _display displayCtrl 266854;
	_timeControl = _display displayCtrl 266855;
	_background = _display displayCtrl 266856;

	_background ctrlSetText QPATHTO_T(data\dagr_vector.paa);

	if (NODAGRDISPLAY) exitwith {};

	if (Dagr_Map_Info == "default") then {
		_dagrGrid = mapGridPosition DAGRLAZPOS;
	} else {
		//find laser position
		_x = DAGRLAZPOS select 0;
		_y = DAGRLAZPOS select 1;

		_grid = [_x, _y] call ace_fnc_mapCoord;
		_xgrid = floor (call compile (_grid select 0));
		_ygrid = floor (call compile (_grid select 1));

		//Incase grids go neg due to 99-00 boundry
		if (_xgrid < 0) then {_xgrid = _xgrid + 9999;};
		if (_ygrid < 0) then {_ygrid = _ygrid + 9999;};

		_xcoord =
			if (_xgrid >= 1000) then {
				str _xgrid;
			} else {
				if (_xgrid >= 100) then {
					"0" + str _xgrid;
				} else {
					if (_xgrid >= 10) then {
						"00" + str _xgrid;
					}else{
						"000" + str _xgrid;
					};
				};
			};

		_ycoord =
			if (_ygrid >= 1000) then {
				str _ygrid;
			} else {
				if (_ygrid >= 100) then {
					"0" + str _ygrid;
				} else {
					if (_ygrid >= 10) then {
						"00" + str _ygrid;
					}else{
						"000" + str _ygrid;
					};
				};
			};

		_dagrGrid = _xcoord + " " + _ycoord;
	};

	//find target elevation
	_elevation = floor ((DAGRLAZPOS select 2) + getNumber(configFile >> "CfgWorlds" >> worldName >> "elevationOffset"));
	_dagrElevation = str _elevation + "m";

	//Time
	_time = daytime;
	_hour = floor (_time);
	_min  = floor ((_time mod 1) * 60);


	_hr =
		if (_hour >= 10) then {
			str _hour;
		} else {
			if (_hour >= 1) then {
				"0" + str _hour;
			} else {
				"00" + str _hour;
			};
		};
	_mn =
		if (_min >= 10) then {
			str _min;
		} else {
			"0" + str _min;
		};

	_dagrTime = _hr + ":" + _mn;

	//Bearing
	_bearing = ((DAGRLazHeading select 0) atan2 (DAGRLazHeading select 1)) + 360;
	if (_bearing >= 360) then {_bearing = _bearing - 360;};
	if (!DAGR_DIRECTION) then {_bearing = floor (_bearing/360*6400)};


	_bearing = floor (_bearing);

	//Distance
	_dagrDist = str DAGRLAZDIST + "m";

	//put grid into variable so DAGR menu can access it TODO: check if it is safe to do it in this fashion
	DAGR_GRID_VECTOR = _dagrGrid;
	
	//OUTPUT
	_gridControl ctrlSetText format ["%1", _dagrGrid];
	_speedControl ctrlSetText format ["%1", _dagrDist];
	_elevationControl ctrlSetText format ["%1", _dagrElevation];
	_headingControl ctrlSetText (if (!DAGR_DIRECTION) then { format ["%1", _bearing] } else { format ["%1°", _bearing] });
	_timeControl ctrlSetText format ["%1", _dagrTime];
};