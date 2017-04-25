// by Xeno

x_funcs2_compiled = false;

// direction from one object to another
// parameters: object1, object2
// example: _dir = [tank1, apc1] call XfDirToObj;
XfDirToObj = {
	private ["_o1","_o2","_deg"];
	_o1 = _this select 0;_o2 = _this select 1;
	_deg = ((position _o2 select 0) - (position _o1 select 0)) atan2 ((position _o2 select 1) - (position _o1 select 1));
	if (_deg < 0) then {_deg = _deg + 360};
	_deg
};

// get a random number, floored, from count array
// parameters: array
// example: _randomarrayint = _myarray call XfRandomFloorArray;
XfRandomFloorArray = {
	floor (random (count _this))
};

// get a random item from an array
// parameters: array
// example: _randomval = _myarray call XfRandomArrayVal;
XfRandomArrayVal = {
	_this select (_this call XfRandomFloorArray);
};

// get a random numer, ceiled
// parameters: number
// example: _randomint = 30 call XfRandomCeil;
XfRandomCeil = {
	ceil (random _this)
};

// returns the number of human players currently playing a mission in MP
XPlayersNumber = {
	(playersNumber east + playersNumber west + playersNumber resistance + playersNumber civilian)
};

// gets a random number in a specific range
// parameters: number from, number to
// example: _random_number = [30,150] call XfGetRandomRange;
XfGetRandomRange = {
	private ["_num1","_num2","_ra"];
	_num1 = _this select 0;_num2 = _this select 1;
	_ra = _num2 - _num1;
	_ra = random _ra;
	(_num1 + _ra)
};

// gets a random integer number in a specific range
// parameters: integer from, integer to
// example: _random_integer = [30,150] call XfGetRandomRangeInt;
XfGetRandomRangeInt = {
	private ["_num1","_num2","_ra"];
	_num1 = _this select 0;_num2 = _this select 1;
	if (_num1 > _num2) then {_num1 = _this select 1;_num2 = _this select 0;};
	_ra = _num2 - _num1;
	_ra = _ra call XfRandomFloor;
	(_num1 + _ra)
};

// compares two arrays, if equal returns true, if not false
// parameters: array1, array2
// example: _isequal = [array1, array2] call XfArrayCompare;
XfArrayCompare = {
	if (str (_this select 0) == str (_this select 1)) then {true} else {false}
};

// get height of object
// parameters: object (no brackets)
// _height = tank1 call XfGetHeight;
XfGetHeight = {
	position _this select 2
};

// set only height of an object
// parameters: object, height
// example: [unit1, 30] call XfSetHeight;
XfSetHeight = {
	(this select 0) setPos [position (this select 0) select 0, position (this select 0) select 1, (_this select 1)];
};

// get x position of an object
// parameters: object (no brackets)
// _posx = tank1 call XfGetPosX;
XfGetPosX = {
	position _this select 0
};

// set only x position of an object
// parameters: object, x
// example: [unit1, 30] call XfSetPosX;
XfSetPosX = {
	(this select 0) setPos [(_this select 1), position (this select 0) select 1, position (this select 0) select 2];
};

// get y position of an object
// parameters: object (no brackets)
// _posy = tank1 call XfGetPosY;
XfGetPosY = {
	position _this select 1
};

// set only y position of an object
// parameters: object, y
// example: [unit1, 30] call XfSetPosY;
XfSetPosY = {
	(this select 0) setPos [position (this select 0) select 0, (_this select 1), position (this select 0) select 2];
};

// get displayname of an object
// parameters: type of object (string), what (0 = CfgVehicles, 1 = CfgWeapons, 2 = CfgMagazines)
// example: _dispname = ["UAZ", 0] call XfGetDisplayName;
XfGetDisplayName = {
	private ["_obj_name", "_obj_kind", "_cfg"];
	_obj_name = _this select 0;_obj_kind = _this select 1;
	_cfg = (switch (_obj_kind) do {case 0: {"CfgVehicles"};case 1: {"CfgWeapons"};case 2: {"CfgMagazines"};});
	getText(configFile >> _cfg >> _obj_name >> "displayName")
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
		};
	};
	_ret_val
};

// no slope check, for patrolling
XfGetRanPointCircleOld = {
	private ["_center", "_radius", "_center_x", "_center_y", "_ret_val", "_co", "_angle", "_x1", "_y1", "_helper"];
	_center = _this select 0;_radius = _this select 1;
	_center_x = _center select 0;_center_y = _center select 1;
	_ret_val = [];_co = 0;
	while {count _ret_val == 0 && _co < 50} do {
		_angle = floor (random 360);
		_x1 = _center_x - ((random _radius) * sin _angle);
		_y1 = _center_y - ((random _radius) * cos _angle);
		if (!(surfaceiswater [_x1, _y1])) then {
			_ret_val = [_x1, _y1, 0];
		};
		if (count _ret_val == 0) then {
			_co = _co + 1;
		};
	};
	_ret_val
};

// get a random point inside a circle for bigger objects
// parameters:
// center position, radius of the circle
// example: _random_point = [position trigger1, 200] call XfGetRanPointCircleBig;
XfGetRanPointCircleBig = {
	private ["_center", "_radius", "_center_x", "_center_y", "_ret_val", "_co", "_angle", "_x1", "_y1", "_nobs", "_helper"];
	_center = _this select 0;_radius = _this select 1;
	_center_x = _center select 0;_center_y = _center select 1;
	_ret_val = [];_co = 0;
	while {count _ret_val == 0 && _co < 50} do {
		_angle = floor (random 360);
		_x1 = _center_x - ((random _radius) * sin _angle);
		_y1 = _center_y - ((random _radius) * cos _angle);
		if (!(surfaceiswater [_x1, _y1])) then {
			_nobs = [_x1,_y1,0] nearObjects ["Static",20];
			if (count _nobs == 0) then {
				_helper = "RoadCone" createVehicleLocal [_x1,_y1,0];
				if (!(surfaceIsWater [position _helper select 0, position _helper select 1])) then {
					_slope = [position _helper, 5] call XfGetSlope;
					if (_slope < 0.5 && !(isOnRoad (position _helper))) then {
						_ret_val = [position _helper select 0,position _helper select 1,0];
					};
				};
				deleteVehicle _helper;
			};
		};
		if (count _ret_val == 0) then {
			_co = _co + 1;
		};
	};
	_ret_val
};

// get a random point at the borders of a circle
// parameters:
// center position, radius of the circle
// example: _random_point = [position trigger1, 200] call XfGetRanPointCircleOuter;
XfGetRanPointCircleOuter = {
	private ["_center", "_radius", "_center_x", "_center_y", "_ret_val", "_co", "_angle", "_x1", "_y1", "_helper"];
	_center = _this select 0;_radius = _this select 1;
	_center_x = _center select 0;_center_y = _center select 1;
	_ret_val = [];_co = 0;
	while {count _ret_val == 0 && _co < 50} do {
		_angle = floor (random 360);
		_x1 = _center_x - (_radius * sin _angle);
		_y1 = _center_y - (_radius * cos _angle);
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
		};
	};
	_ret_val
};

// no slope check, for patrolling
XfGetRanPointSquareOld = {
	private ["_pos", "_a", "_b", "_angle", "_centerx", "_centery", "_leftx", "_lefty", "_width", "_height", "_ret_val", "_co", "_px1", "_py1", "_radius", "_atan", "_x1", "_y1"];
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
			_ret_val = [_x1, _y1, 0];
		};
		if (count _ret_val == 0) then {
			_co = _co + 1;
		};
	};
	_ret_val
};

// get a random point at the borders of a square
// parameters:
// center position, a and b (like in triggers), angle
// example: _random_point  = [position trigger2, 200, 300, 30] call XfGetRanPointSquareOuter;
XfGetRanPointSquareOuter = {
	private ["_pos", "_a", "_b", "_angle", "_centerx", "_centery", "_leftx", "_lefty", "_width", "_height", "_ret_val", "_co", "_px1", "_py1", "_radius", "_atan", "_x1", "_y1", "_helper"];
	_pos = _this select 0;_a = _this select 1;_b = _this select 2;_angle = _this select 3;
	_centerx = _pos select 0;_centery = _pos select 1;_leftx = _centerx - _a;_lefty = _centery - _b;
	_width = 2 * _a;_height = 2 * _b;_ret_val = [];_co = 0;
	while {count _ret_val == 0 && _co < 50} do {
		_rside = floor (random 4);
		_px1 = (
			switch (_rside) do {
				case 0: {_leftx + random _width};
				case 1: {_leftx + _width};
				case 2: {_leftx + random _width};
				case 3: {_leftx};
			}
		);
		_py1 = (
			switch (_rside) do {
				case 0: {_lefty + _height};
				case 1: {_lefty + random _height};
				case 2: {_lefty};
				case 3: {_lefty + random _height};
			}
		);
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
		};
	};
	_ret_val
};

// hopefully not needed in A2, function returns two flanking positions for AI
// parameters: target unit(s) pos , flanking unit(s) pos, distance between both
// example: _flankarray = [position player, position _enemy1, (player distance _enemy1)]
XfGetFlankPos = {
	private ["_pp", "_pe", "_dis", "_px", "_py", "_ex", "_ey", "_angle", "_a", "_b", "_flank_ret", "_i", "_xp", "_yp", "_ret", "_rand"];
	_pp = _this select 0;_pe = _this select 1;_dis = _pp distance _pe;_px = _pp select 0;_py = _pp select 1;_ex = _pe select 0;_ey = _pe select 1;
	_angle = 0; _a = (_px - _ex);_b = (_py - _ey);
	if (_a != 0 || _b != 0) then {_angle = _a atan2 _b};
	if (_angle < 0) then {_angle = _angle + 360};
	_rand = random 100;_flank_ret = [];_i = if (_rand > 49) then {-85} else {85};
	_xp = _px - ((_dis * 0.5) * sin (_angle + _i));_yp = _py - ((_dis * 0.5) * cos (_angle + _i));_ret = [_xp,_yp,0];[_flank_ret , _ret] call X_fnc_arrayPush;
	_i = if (_rand > 49) then {-35} else {35};
	_xp = _px - ((_dis) * sin (_angle + _i));_yp = _py - ((_dis) * cos (_angle + _i));_ret = [_xp,_yp,0];
	[_flank_ret , _ret] call X_fnc_arrayPush;
	_flank_ret
};

// from warfare
// Returns an average slope value of terrain within passed radius.
// a little bit modified. no need to create a "global" logic, local is enough, etc
// parameters: position, radius
// example: _slope = [the_position, the_radius] call XfGetSlope;
if (isNil "X_SlopeObject") then {
	X_SlopeObject = "HeliHEmpty" CreateVehicleLocal [0,0,0];
};
XfGetSlope = {
	private ["_position", "_radius", "_centerHeight", "_height", "_direction", "_count"];
	_position = _this select 0;_radius = _this select 1;
	X_SlopeObject setPos _position;
	_centerHeight = getPosASL X_SlopeObject select 2;
	_height = 0;_direction = 0;
	for "_count" from 0 to 7 do {
		X_SlopeObject setPos [(_position select 0)+((sin _direction)*_radius),(_position select 1)+((cos _direction)*_radius),0];
		_direction = _direction + 45;
		_height = _height + abs (_centerHeight - (getPosASL X_SlopeObject select 2));
	};
	_height / 8
};

// create a global marker
// parameters: marker name, marker pos, marker shape, marker color, marker size;(optional) marker text, marker dir, marker type, marker brush
// example: ["my marker",  position player, "Dot", "ColorBlue", [0.5,0.5]] call XfCreateMarkerGlobal;
XfCreateMarkerGlobal = {
	private ["_m_name","_m_pos","_m_shape","_m_col","_m_size","_m_text","_m_dir","_m_type","_m_brush","_m_alpha"];
	_m_name = _this select 0;
	_m_pos = _this select 1;
	_m_shape = _this select 2;
	_m_col = _this select 3;
	_m_size = _this select 4;
	_m_text = (if (count _this > 5) then {_this select 5} else {""});
	_m_dir = (if (count _this > 6) then {_this select 6} else {-888888888888});
	_m_type = (if (count _this > 7) then {_this select 7} else {""});
	_m_brush = (if (count _this > 8) then {_this select 8} else {""});
	_m_alpha = (if (count _this > 9) then {_this select 9} else {0});

	_marker = createMarker [_m_name, _m_pos];
	if (_m_shape != "") then {_marker setMarkerShape _m_shape};
	if (_m_col != "") then {_marker setMarkerColor _m_col};
	if (count _m_size > 0) then {_marker setMarkerSize _m_size};
	if (_m_text != "") then {_marker setMarkerText _m_text};
	if (_m_dir != -888888888888) then {_marker setMarkerDir _m_dir};
	if (_m_type != "") then {_marker setMarkerType _m_type};
	if (_m_brush != "") then {_marker setMarkerBrush _m_brush};
	if (_m_alpha != 0) then {_marker setMarkerAlpha _m_alpha};
};

// create a local marker
// parameters: marker name, marker pos, marker shape, marker color, marker size;(optional) marker text, marker dir, marker type, marker brush
// example: ["my marker",  position player, "Dot", "ColorBlue", [0.5,0.5]] call XfCreateMarkerLocal;
XfCreateMarkerLocal = {
	private ["_m_name","_m_pos","_m_shape","_m_col","_m_size","_m_text","_m_dir","_m_type","_m_brush","_m_alpha"];
	_m_name = _this select 0;
	_m_pos = _this select 1;
	_m_shape = _this select 2;
	_m_col = _this select 3;
	_m_size = _this select 4;
	_m_text = (if (count _this > 5) then {_this select 5} else {""});
	_m_dir = (if (count _this > 6) then {_this select 6} else {-888888888888});
	_m_type = (if (count _this > 7) then {_this select 7} else {""});
	_m_brush = (if (count _this > 8) then {_this select 8} else {""});
	_m_alpha = (if (count _this > 9) then {_this select 9} else {0});

	_marker = createMarkerLocal [_m_name, _m_pos];
	if (_m_shape != "") then {_marker setMarkerShapeLocal _m_shape};
	if (_m_col != "") then {_marker setMarkerColorLocal _m_col};
	if (count _m_size > 0) then {_marker setMarkerSizeLocal _m_size};
	if (_m_text != "") then {_marker setMarkerTextLocal _m_text};
	if (_m_dir != -888888888888) then {_marker setMarkerDirLocal _m_dir};
	if (_m_type != "") then {_marker setMarkerTypeLocal _m_type};
	if (_m_brush != "") then {_marker setMarkerBrushLocal _m_brush};
	if (_m_alpha != 0) then {_marker setMarkerAlphaLocal _m_alpha};
};

// send a text message over the network
// parameters: msg text, receiver ("unit","grp","all","vec"), receiver (unit, grp, vehicle), type ("global", "vehicle", "side", "group", "hint")
XfSendMessage = {
	["xmsg",_this] call XNTSendNetStartScriptClient;
};

XfGetAliveUnits = {
	({alive _x} count _this)
};

XfGetAliveUnitsGrp = {
	({alive _x} count (units _this))
};

X_fnc_subSelect = {
	/************************************************************
		Subarray Select
		By Andrew Barron

	Returns a sub-selection of the passed array. There are various
	methods the sub-array can be determined.

	Parameters: [array, beg, <end>]
	Returns: subarray

	array - Array to select sub array from.
	beg - Index of array to begin sub-array. If negative, index is
		counted from the end of array.
	end - Optional. Index of array to end the sub-array. If ommitted,
		remainder of the array will be selected. If negative, it
		specifies the length of the sub-array (in absolute form).

	Examples:

		_array = ["a","b",true,3,8];
		[_array, 2] call X_fnc_subSelect; //returns [true,3,8]
		[_array, -2] call X_fnc_subSelect; //returns [3,8]
		[_array, 1, 3] call X_fnc_subSelect; //returns ["b",true,3]
		[_array, 1, -2] call X_fnc_subSelect; //returns ["b",true]

	************************************************************/

	private ["_ary","_beg","_len","_end","_ret","_i"];

	_ret = [];

	//inputs
	_ary = _this select 0;
	_len = (count _ary)-1;

	//beginning point of subarray
	_beg = _this select 1;

	//if negative, index is counted from end of array
	if(_beg < 0) then {_beg = _len+_beg+1};

	//end point of subarray, optional
	if(count _this > 2) then {_end = _this select 2} else {_end = _len};

	//if end is negative, it means a fixed length array is returned
	if(_end < 0) then {_end = _beg-_end-1};

	//ensure we don't get errors from going past the end of the array
	if(_end > _len) then {_end = _len};

	//simply loop thru the passed array, copying elements over to the return array
	for "_i" from _beg to _end do
	{
		[_ret, _ary select _i] call X_fnc_arrayPush;
	};

	_ret;
};

X_fnc_arrayInsert = {
	/************************************************************
		Array Insert
		By Andrew Barron

	Parameters: [base array, insert array, index]
	Returs: [array]

	Inserts the elements of one array into another, at a specified
	index.

	Neither arrays are touched by reference, a new array is returned.

	Example: [[0,1,2,3,4], ["a","b","c"], 1] call X_fnc_arrayInsert
	Returns: [0,"a","b","c",1,2,3,4]
	************************************************************/

	//extract parameters
	private ["_baseArray","_toInsert","_index","_ret"];
	_baseArray = _this select 0;
	_toInsert = _this select 1;
	_index = _this select 2;


	//special processing needed unless we are "inserting" at the beginning of the array
	if(_index > 0) then
	{
		//select left part of base array, before the insertion index
		_ret = [_baseArray, 0, _index-1] call X_fnc_subSelect;

		//push in the elements to be inserted
		[_ret, _toInsert] call X_fnc_arrayPushStack;
	}
	else
	{
		_ret = _toInsert;
	};

	//push in the remaining elements from the base array
	[_ret, [_baseArray, _index] call X_fnc_subSelect] call X_fnc_arrayPushStack;

	//return new array
	_ret
};

X_fnc_inTrigger = {
	/*
		File: inTrigger.sqf
		Author: Karel Moricky

		Description:
		Detects whether is position within trigger area.

		Parameter(s):
			_this select 0: Trigger
			_this select 1: Position
			_this select 2: OPTIONAL - scalar result (distance from border)

		Returns:
		Boolean (true when position is in area, false if not).
	*/
	private ["_trig","_object","_posx","_posy","_tarea","_tx","_ty","_tdir","_tshape","_in"];

	_trig = _this select 0;
	_position = _this select 1;
	_scalarresult = if (count _this > 2) then {_this select 2} else {false};

	_posx = position _trig select 0;
	_posy = position _trig select 1;
	_tarea = triggerarea _trig;
	_tx = _tarea select 0;
	_ty = _tarea select 1;
	_tdir = _tarea select 2;
	_tshape = _tarea select 3;
	_in = false;

	if (_tshape) then {

		//--- RECTANGLE
		_difx = (_position select 0) - _posx;
		_dify = (_position select 1) - _posy;
		_dir = atan (_difx / _dify);
		if (_dify < 0) then {_dir = _dir + 180};
		_relativedir = _tdir - _dir;
		_adis = abs (_tx / cos (90 - _relativedir));
		_bdis = abs (_ty / cos _relativedir);
		_borderdis = _adis min _bdis;
		_positiondis = _position distance _trig;

		_in = if (_scalarresult) then {
			_positiondis - _borderdis;
		} else {
			if (_positiondis < _borderdis) then {true} else {false};
		};

	} else {
		//--- ELLIPSE
		_e = sqrt(_tx^2 - _ty^2);
		_posF1 = [_posx + (sin (_tdir+90) * _e),_posy + (cos (_tdir+90) * _e)];
		_posF2 = [_posx - (sin (_tdir+90) * _e),_posy - (cos (_tdir+90) * _e)];
		_total = 2 * _tx;

		_dis1 = _position distance _posF1;
		_dis2 = _position distance _posF2;
		_in = if (_scalarresult) then {
			(_dis1+_dis2) - _total;
		} else {
			if (_dis1+_dis2 < _total) then {true} else {false};
		};
	};

	_in
};

X_fnc_isPosBlacklisted = {
	/*
		File: isPosBlacklisted.sqf
		Author: Joris-Jan van 't Land & Karel Moricky

		Description:
		Function checks a blacklist and sees if the given position is on it or not.

		Parameter(s):
		_this select 0: position (Array)
		_this select 1: blacklist (Array or Object/Trigger)

		Returns:
		Is the position blacklisted or not (Boolean)
	*/

	private ["_pos", "_list", "_x", "_y", "_listed"];
	_pos = _this select 0;
	_list = _this select 1;

	_x = _pos select 0;
	_y = _pos select 1;
	_listed = false;

	//Go through all areas in the blacklist.
	for "_i" from 0 to ((count _list) - 1) do {
		_current = (_list select _i);
		switch (typename _current) do {
			//--- Definition by top-left and bottom right corner -------------------------------
			case (typeName []): {
				//Check the top-left and bottom-right coordinates.
				private ["_tl", "_br"];
				_tl = _current select 0;
				_br = _current select 1;

				private ["_minX", "_maxX", "_minY", "_maxY"];
				_minX = _tl select 0;
				_maxX = _br select 0;
				_minY = _br select 1;
				_maxY = _tl select 1;

				if ((_x > _minX) && (_x < _maxX) && (_y > _minY) && (_y < _maxY)) exitWith {
					_listed = true;
				};
			};
			//--- Definition by trigger --------------------------------------------------------
			case (typeName objNull): {
				if ([_current,_pos] call X_fnc_inTrigger) exitwith {
					_listed = true;
				};
			};
			default {
				debuglog "Log: Error in isPosBlacklisted.sqf - wrong input data.";
			};
		};
	};

	_listed
};

X_fn_findSafePos = {
	/*
		File: findSafePos.sqf
		Author: Joris-Jan van 't Land

		Description:
		Function to retrieve and dynamic position in the world according to several parameters.

		Parameter(s):
		_this select 0: center position (Array)
							Note: passing [] (empty Array), the world's safePositionAnchor entry will be used.
		_this select 1: minimum distance from the center position (Number)
		_this select 2: maximum distance from the center position (Number)
							Note: passing -1, the world's safePositionRadius entry will be used.
		_this select 3: minimum distance from the nearest object (Number)
		_this select 4: water mode (Number)
							0: cannot be in water
							1: can either be in water or not
							2: must be in water
		_this select 5: maximum terrain gradient (average altitude difference in meters - Number)
		_this select 6: shore mode (Number):
							0: does not have to be at a shore
							1: must be at a shore
		_this select 7: (optional) blacklist (Array of Arrays):
							(_this select 7) select X: Top-left and bottom-right coordinates of blacklisted area (Array)
		_this select 8: (optional) default positions (Array of Arrays):
							(_this select 8) select 0: default position on land (Array)
							(_this select 8) select 1: default position on water (Array)

		Returns:
		Coordinate array with a position solution.

		TODO:
		* Maybe allow passing several combinations of position, min and max dist ... so that you can
		avoid several things?
		* Interpretation of minDist / maxDist is wrong. It's not true distance that is used. Too bad?
	*/

	scopeName "main";

	private ["_pos", "_minDist", "_maxDist", "_objDist", "_waterMode", "_maxGradient", "_shoreMode", "_defaultPos", "_blacklist"];
	_pos = _this select 0;
	_minDist = _this select 1;
	_maxDist = _this select 2;
	_objDist = _this select 3;
	_waterMode = _this select 4;
	_maxGradient = _this select 5;
	_shoreMode = _this select 6;

	if (_shoreMode == 0) then {_shoreMode = false} else {_shoreMode = true};

	_blacklist = [];
	if ((count _this) > 7) then
	{
		_blacklist = _this select 7;
	};

	_defaultPos = [];
	if ((count _this) > 8) then
	{
		_defaultPos = _this select 8;
	};

	//See if default world values should be used.
	if ((count _pos) == 0) then
	{
		_pos = getArray(configFile >> "CfgWorlds" >> worldName >> "safePositionAnchor");
	};
	if ((count _pos) == 0) exitWith {debugLog "Log: [findSafePos] No center position was passed!"; []}; //TODO: instead return defaults below.

	if (_maxDist == -1) then
	{
		_maxDist = getNumber(configFile >> "CfgWorlds" >> worldName >> "safePositionRadius");
	};

	//TODO: Validate parameters.

	private ["_newPos", "_posX", "_posY"];
	_newPos = [];
	_posX = _pos select 0;
	_posY = _pos select 1;


	//Limit the amount of attempts at finding a good location.
	private ["_attempts"];
	_attempts = 0;
	while {_attempts < 1000} do
	{
		private ["_newX", "_newY", "_testPos"];
		_newX = _posX + (_maxDist - (random (_maxDist * 2)));
		_newY = _posY + (_maxDist - (random (_maxDist * 2)));
		_testPos = [_newX, _newY];

		//Blacklist check.
		//TODO: Do not use function when the blacklist is empty?
		if (!([_testPos, _blacklist] call X_fnc_isPosBlacklisted)) then
		{
				if ((_pos distance _testPos) >= _minDist) then
				{
					if (!((count (_testPos isFlatEmpty [_objDist, 0, _maxGradient, _objDist max 5, _waterMode, _shoreMode, objNull])) == 0)) then
					{
						_newPos = _testPos;
						breakTo "main";
					};
				};
		};

		_attempts = _attempts + 1;
	};

	//No position was found, use defaults.
	if ((count _newPos) == 0) then
	{
		if (_waterMode == 0) then
		{
			if ((count _defaultPos) > 0) then
			{
				_newPos = _defaultPos select 0;
			}
			else
			{
				//Use world Armory default position:
				_newPos = getArray(configFile >> "CfgWorlds" >> worldName >> "Armory" >> "positionStart");
			};
		}
		else
		{
			if ((count _defaultPos) > 1) then
			{
				_newPos = _defaultPos select 1;
			}
			else
			{
				//Use world Armory default water position:
				_newPos = getArray(configFile >> "CfgWorlds" >> worldName >> "Armory" >> "positionStartWater");
			};
		};
	};

	if ((count _newPos) == 0) then
	{
		//Still nothing was found, use world center positions.
		_newPos = getArray(configFile >> "CfgWorlds" >> worldName >> "centerPosition");
	};

	_newPos
};

X_fnc_selectCrew = {
	/*
		File: selectCrew.sqf
		Author: Joris-Jan van 't Land

		Description:
		Return an appropriate crew type for a certain vehicle.

		Parameter(s):
		_this select 0: side (Side)
		_this select 1: vehicle config entry (Config)

		Returns:
		String - crew type
	*/

	//Validate parameter count
	if ((count _this) < 2) exitWith {debugLog "Log: [selectCrew] Function requires at least 2 parameters!"; ""};

	private ["_side", "_entry"];
	_side = _this select 0;
	_entry = _this select 1;

	//Validate parameters
	if ((typeName _side) != (typeName sideEnemy)) exitWith {debugLog "Log: [selectCrew] Side (0) must be a Side!"; ""};
	if ((typeName _entry) != (typeName configFile)) exitWith {debugLog "Log: [selectCrew] Vehicle config entry (1) must be a Config!"; ""};

	//Try to find the crew type in the config
	private ["_crew"];
	_crew = "";
	_crew = getText (_entry >> "crew");

	//If not found, use defaults
	if (_crew == "") then
	{
		switch (_side) do
		{
			case west:
			{
				_crew = "USMC_Soldier_Crew";
			};

			case east:
			{
				_crew = "RU_Soldier_Crew";
			};

			default {};
		};
	};

	_crew
};

X_fnc_returnVehicleTurrets = {
	/*
		File: fn_returnVehicleTurrets.sqf
		Author: Joris-Jan van 't Land

		Description:
		Function return the path to all turrets and sub-turrets in a vehicle.

		Parameter(s):
		_this select 0: vehicle config entry (Config)

		Returns:
		Array of Scalars and Arrays - path to all turrets
	*/

	//Validate parameter count
	if ((count _this) < 1) exitWith {debugLog "Log: [returnVehicleTurrets] Function requires at least 1 parameter!"; []};

	private ["_entry"];
	_entry = _this select 0;

	//Validate parameters
	if ((typeName _entry) != (typeName configFile)) exitWith {debugLog "Log: [returnVehicleTurrets] Entry (0) must be a Config!"; []};

	private ["_turrets", "_turretIndex"];
	_turrets = [];
	_turretIndex = 0;

	//Explore all turrets and sub-turrets recursively.
	for "_i" from 0 to ((count _entry) - 1) do
	{
		private ["_subEntry"];
		_subEntry = _entry select _i;

		if (isClass _subEntry) then
		{
			private ["_hasGunner"];
			_hasGunner = [_subEntry, "hasGunner"] call X_fnc_returnConfigEntry;

			//Make sure the entry was found.
			if (!(isNil "_hasGunner")) then
			{
				if (_hasGunner == 1) then
				{
					_turrets = _turrets + [_turretIndex];

					//Include sub-turrets, if present.
					if (isClass (_subEntry >> "Turrets")) then
					{
						_turrets = _turrets + [[_subEntry >> "Turrets"] call X_fnc_returnVehicleTurrets];
					}
					else
					{
						_turrets = _turrets + [[]];
					};
				};
			};

			_turretIndex = _turretIndex + 1;
		};
	};

	_turrets
};

X_fnc_returnConfigEntry = {
	/*
		File: returnConfigEntry.sqf
		Author: Joris-Jan van 't Land

		Description:
		Explores parent classes in the run-time config for the value of a config entry.

		Parameter(s):
		_this select 0: starting config class (Config)
		_this select 1: queried entry name (String)

		Returns:
		Number / String - value of the found entry
	*/

	//Validate parameter count
	if ((count _this) < 2) exitWith {debugLog "Log: [returnConfigEntry] This function requires at least 2 parameters!"; nil};

	private ["_config", "_entryName"];
	_config = _this select 0;
	_entryName = _this select 1;

	//Validate parameters
	if ((typeName _config) != (typeName configFile)) exitWith {debugLog "Log: [returnConfigEntry] Starting class (0) must be of type Config!"; nil};
	if ((typeName _entryName) != (typeName "")) exitWith {debugLog "Log: [returnConfigEntry] Entry name (1) must be of type String!"; nil};

	private ["_entry", "_value"];
	_entry = _config >> _entryName;

	//If the entry is not found and we are not yet at the config root, explore the class' parent.
	if (((configName (_config >> _entryName)) == "") && (!((configName _config) in ["CfgVehicles", "CfgWeapons", ""]))) then
	{
		[inheritsFrom _config, _entryName] call X_fnc_returnConfigEntry;
	}
	else
	{
		//Supporting either Numbers or Strings
		if (isNumber _entry) then
		{
			_value = getNumber _entry;
		}
		else
		{
			if (isText _entry) then
			{
				_value = getText _entry;
			};
		};
	};

	//Make sure returning 'nil' works.
	if (isNil "_value") exitWith {nil};

	_value
};

x_funcs2_compiled = true;

if (true) exitWith {};