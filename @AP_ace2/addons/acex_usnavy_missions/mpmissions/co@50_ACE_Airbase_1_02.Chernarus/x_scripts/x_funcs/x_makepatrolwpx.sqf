// from warfare
// Returns an average slope value of terrain within passed radius.
// a little bit modified. no need to create a "global" logic, local is enough, etc
// parameters: position, radius
// example: _slope = [the_position, the_radius] call XfGetSlope;
XfGetSlope = {
	private ["_position", "_radius", "_slopeObject", "_centerHeight", "_height", "_direction", "_count"];
	_position = _this select 0;_radius = _this select 1;
	_slopeObject = "Logic" createVehicleLocal [0,0,0];
	_slopeObject setPos _position;
	_centerHeight = getPosASL _slopeObject select 2;
	_height = 0;_direction = 0;
	for "_count" from 0 to 7 do {
		_slopeObject setPos [(_position select 0)+((sin _direction)*_radius),(_position select 1)+((cos _direction)*_radius),0];
		_direction = _direction + 45;
		_height = _height + abs (_centerHeight - (getPosASL _slopeObject select 2));
	};
	deleteVehicle _slopeObject;
	_height / 8
};

// get a random point inside a circle
// parameters:
// center position, radius of the circle
// example: _random_point = [position trigger1, 200] call XfGetRanPointCircle;
XfGetRanPointCircle = {
	private ["_center", "_radius", "_center_x", "_center_y", "_ret_val", "_co", "_angle", "_x1", "_y1", "_helper"];
	_center = _this select 0;_radius = _this select 1;
	_center_x = _center select 0;_center_y = _center select 1;
	_ret_val = [];_co = 0;
	while {count _ret_val == 0 && _co < 50} do {
		_angle = floor (random 360);
		_x1 = _center_x - ((random _radius) * sin _angle);
		_y1 = _center_y - ((random _radius) * cos _angle);
		if (!(surfaceiswater [_x1, _y1])) then {
			_helper = "RoadCone" createVehicleLocal [_x1,_y1,0];
			if (!(surfaceIsWater [position _helper select 0, position _helper select 1])) then {
				_slope = [position _helper, 5] call XfGetSlope;
				if (_slope < 0.5) then {
					_ret_val = [position _helper select 0, position _helper select 1,0];
				};
			};
			deleteVehicle _helper;
		};
		if (count _ret_val == 0) then {
			_co = _co + 1;
			sleep .01;
		};
	};
	_ret_val
};

// get a random point inside a square
// parameters:
// center position, a and b (like in triggers), angle
// example: _random_point  = [position trigger2, 200, 300, 30] call XfGetRanPointSquare;
XfGetRanPointSquare = {
	private ["_pos", "_a", "_b", "_angle", "_centerx", "_centery", "_leftx", "_lefty", "_width", "_height", "_ret_val", "_co", "_px1", "_py1", "_radius", "_atan", "_x1", "_y1", "_helper"];
	_pos = _this select 0;_a = _this select 1;_b = _this select 2;_angle = _this select 3;
	_centerx = _pos select 0;_centery = _pos select 1;_leftx = _centerx - _a;_lefty = _centery - _b;
	_width = 2 * _a;_height = 2 * _b;_ret_val = [];_co = 0;
	while {count _ret_val == 0 && _co < 50} do {
		_px1 = _leftx + random _width;
		_py1 = _lefty + random _height;
		_radius = _pos distance [_px1,_py1];
		_atan = (_centerx - _px1) atan2 (_centery - _py1);
		_x1 = _centerx - (_radius * sin (_atan + _angle));
		_y1 = _centery - (_radius * cos (_atan + _angle));
		if (!(surfaceiswater [_x1, _y1])) then {
			_helper = "RoadCone" createVehicleLocal [_x1,_y1,0];
			if (!(surfaceIsWater [position _helper select 0, position _helper select 1])) then {
				_slope = [position _helper, 5] call XfGetSlope;
				if (_slope < 0.5) then {
					_ret_val = [position _helper select 0, position _helper select 1,0];
				};
			};
			deleteVehicle _helper;
		};
		if (count _ret_val == 0) then {
			_co = _co + 1;
			sleep .01;
		};
	};
	_ret_val
};

// from BIS but not using BIS_fnc_findSafePos as it returns no positions inside cities :(
// supports also patrols in square areas, including angle
XMakePatrolWPX = {
	private ["_grp", "_start_pos", "_wp_array", "_i", "_wp_pos", "_counter", "_wp", "_wppos", "_pos", "_cur_pos"];
	_grp = _this select 0;
	_start_pos = _this select 1;
	_wp_array = _this select 2;
	_grp setBehaviour "SAFE";
	_cur_pos = _start_pos;
	for "_i" from 0 to (2 + (floor (random 3))) do {
		_wp_pos = switch (count _wp_array) do {
			case 2: {[_wp_array select 0, _wp_array select 1] call XfGetRanPointCircle};
			case 4: {[_wp_array select 0, _wp_array select 1, _wp_array select 2, _wp_array select 3] call XfGetRanPointSquare};
		};
		_counter = 0;
		while {_wp_pos distance _cur_pos < ((_wp_array select 1)/8) && _counter < 50} do {
			_wp_pos = switch (count _wp_array) do {
				case 2: {[_wp_array select 0, _wp_array select 1] call XfGetRanPointCircle};
				case 4: {[_wp_array select 0, _wp_array select 1, _wp_array select 2, _wp_array select 3] call XfGetRanPointSquare};
			};
			_counter = _counter + 1;
			sleep 0.02;
		};
		_cur_pos = _wp_pos;
		_wp = _grp addWaypoint [_wp_pos, 0];
		_wp setWaypointType "MOVE";
		_wp setWaypointCompletionRadius 20;

		if (_i == 0) then {
			_wp setWaypointSpeed "LIMITED";
			_wp setWaypointFormation "STAG COLUMN";
		};
	};
	_wp = _grp addWaypoint [_start_pos, 0];
	_wp setWaypointType "CYCLE";
	_wp setWaypointCompletionRadius 20;
};