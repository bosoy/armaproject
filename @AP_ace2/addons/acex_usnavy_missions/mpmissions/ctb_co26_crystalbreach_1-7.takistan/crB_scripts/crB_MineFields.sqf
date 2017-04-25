//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20091103
// Version: 0.1 20091103 - Initial release
// Version: 0.2 20091104
//		- Fixed angled markers
//		- Added marker array inputs
//		- Fixed not killing everyone
// Version: 1.1 20091220
//		- Markers indicating mine fields are drawn without delay.
//		- Triggers are placed without delay
//		- Each minefield marker is populated in its own spawned process
//		- Removed real mines from function to improve FPS
//		- Reduced number of objects per metre to improve FPS
//		- Added hedgehogs to prevent vehicles from entering the area
// Contact: http://creobellum.org
// Purpose: Setup mine fields
// Usage: call{["rectangularMarker1","rectangularMarker2",etc] execVM "crb_scripts\crb_Minefields.sqf";};
///////////////////////////////////////////////////////////////////
/*
Original Script
objectMapper.sqf Author: Joris-Jan van 't Land
*/
RotatePosition = {
	private ["_array1", "_array2", "_rotMatrix", "_relPos", "_newRelPos", "_newPos"];
	_newPos = _this select 0;
	_array2 = _this select 1;
	_d = _this select 2;
	_rotMatrix =[[cos _d, sin _d],[-(sin _d), cos _d]];
	_array1 = _rotMatrix;
	_newRelPos =
	[
	(((_array1 select 0) select 0) * (_array2 select 0)) + (((_array1 select 0) select 1) * (_array2 select 1)),
	(((_array1 select 1) select 0) * (_array2 select 0)) + (((_array1 select 1) select 1) * (_array2 select 1))
	];
	_newPos = [(_newPos select 0) + (_newRelPos select 0), (_newPos select 1) + (_newRelPos select 1)];
	_newPos
};

{
	_marker = _x;
	_position = getMarkerPos _marker;
	_mrkr = format["mrkr%1", random 10000];
	createMarkerLocal [_mrkr, _position];
	_mrkr setMarkerTextLocal "Mines!";
	_mrkr setMarkerTypeLocal "hd_warning";
	_mrkr setMarkerColorLocal "ColorRed";
} forEach _this;
{
	_marker = _x;
	_position = getMarkerPos _marker;
	_px = _position select 0;
	_py = _position select 1;
	_size = getMarkerSize _marker;
	_width = _size select 0;
	_depth = _size select 1;
	_angle = markerDir _marker;
	_dist = 20;

	if (isServer) then {
		_trigW = createTrigger ["EmptyDetector", _position];
		_trigW setTriggerActivation ["WEST", "PRESENT", true];
		_trigW setTriggerArea [_width, _dist, _angle, true];
		_trigW setTriggerStatements ["this", "call{[thisList] execVM ""crb_scripts\crb_MineExplode.sqf"";};", ""];
		_trigW setTriggerTimeout [0, 0.5, 1, true];

		_trigE = createTrigger ["EmptyDetector", _position];
		_trigE setTriggerActivation ["EAST", "PRESENT", true];
		_trigE setTriggerArea [_width, _depth, _angle, true];
		_trigE setTriggerStatements ["this", "call{[thisList] execVM ""crb_scripts\crb_MineExplode.sqf"";};", ""];
		_trigE setTriggerTimeout [0, 0.5, 1, true];

		_trigG = createTrigger ["EmptyDetector", _position];
		_trigG setTriggerActivation ["GUER", "PRESENT", true];
		_trigG setTriggerArea [_width, _depth, _angle, true];
		_trigG setTriggerStatements ["this", "call{[thisList] execVM ""crb_scripts\crb_MineExplode.sqf"";};", ""];
		_trigG setTriggerTimeout [0, 0.5, 1, true];
	};

	[_position, _width, _depth, _angle, _dist] spawn {
		_position = _this select 0;
		_width = _this select 1;
		_depth = _this select 2;
		_angle = _this select 3;
		_dist = _this select 4;

		for "_w" from -_width to _width step 8 do {
			_newPos = [_position, [_w + (random 8) - 4, _dist - (random _dist)], _angle] call RotatePosition;
			_sign = "Sign_Danger" createVehicleLocal _newPos;
			_sign setDir _angle;
			_sign setVectorUp [0, 0, 1];
/*			_newPos = [_position, [_w, -_depth], _angle] call RotatePosition;
			_w1 = "Fort_RazorWire" createVehicleLocal _newPos;
			_w1 setPos _newPos;
			_w1 setDir _angle;
			_w1 setVectorUp [0, 0, 1];*/
			_newPos = [_position, [_w, -_depth - 2], _angle] call RotatePosition;
			_h1 = "Hedgehog" createVehicleLocal _newPos;
			_h1 setPos _newPos;
			_h1 setDir _angle;
			_h1 setVectorUp [0, 0, 1];
			_newPos = [_position, [_w + 4, -_depth - 2], _angle] call RotatePosition;
			_h1 = "Hedgehog" createVehicleLocal _newPos;
			_h1 setPos _newPos;
			_h1 setDir _angle;
			_h1 setVectorUp [0, 0, 1];
			sleep 0.2;
		};
	};
} forEach _this;