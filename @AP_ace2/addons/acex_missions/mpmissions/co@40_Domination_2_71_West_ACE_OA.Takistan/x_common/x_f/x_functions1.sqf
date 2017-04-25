// by Xeno
#define THIS_FILE "x_functions1.sqf"
#include "x_setup.sqf"

x_funcs1_compiled = false;

FUNC(arrayPushStack) = {
	{if (!isNil "_x") then {(_this select 0) set [count (_this select 0), _x]}} foreach (_this select 1);
	(_this select 0)
};

FUNC(arrayPushStack2) = {
	{(_this select 0) set [count (_this select 0), _x]} foreach (_this select 1);
	(_this select 0)
};

// get a random numer, floored
// parameters: number
// example: _randomint = 30 call FUNC(RandomFloor);
FUNC(RandomFloor) = {floor (random _this)};

// shuffles the content of an array
// parameters: array
// example: _myrandomarray = _myNormalArray call FUNC(RandomArray);
FUNC(RandomArray) = {
	private ["_ar","_ran_array","_this"];
	_ar =+ _this;
	_ran_array = [];
	while {count _ar > 0} do {_ran = (count _ar) call FUNC(RandomFloor);
		_ran_array set [count _ran_array, _ar select _ran];
		_ar set [_ran, "-1"];
		_ar = _ar - ["-1"];
	};
	_ran_array
};

// creates an array with count random indices
// parameters: int (number of entries)
// example: _myrandomindexarray = _numberentries call FUNC(RandomIndexArray);
FUNC(RandomIndexArray) = {
	private ["_count","_ran_array"];
	_count = _this;
	_ran_array = [];
	for "_i" from 0 to (_count - 1) do {_ran_array set [count _ran_array, _i]};
	_ran_array = _ran_array call FUNC(RandomArray);
	_ran_array
};

FUNC(GetConfigGroup) = {
	private ["_side", "_type", "_typeunits", "_typegroup", "_ret", "_config", "_i", "_cfgn"];
	PARAMS_4(_side,_type,_typeunits,_typegroup);
	_ret = [];
	
	_config = (configFile >> "CfgGroups" >> _side >> _type >> _typeunits >> _typegroup);
	if (isClass _config) then {
		for "_i" from 0 to (count _config - 1) do {
			_cfgn = _config select _i;
			if (isClass _cfgn) then {_ret set [count _ret, getText (_cfgn >> "vehicle")]};
		};
	};
	_ret
};

#ifdef __ACE__
FUNC(GetAltTankStatus) = {
	private ["_c", "_s"];
	_c = GV2(_this,"ace_canmove");
	if (isNil "_c") then {_c = true};
	_s = GV2(_this,"ace_canshoot");
	if (isNil "_s") then {_s = true};
	(!_s && !_c)
};
#endif

// direction from one object to another
// parameters: object1, object2
// example: _dir = [tank1, apc1] call FUNC(DirToObj);
FUNC(DirToObj) = {
	private ["_o1","_o2","_deg","_pos1","_pos2"];
	PARAMS_2(_o1,_o2);
	_pos1 = getPosASL _o1;
	_pos2 = getPosASL _o2;
	_deg = ((_pos2 select 0) - (_pos1 select 0)) atan2 ((_pos2 select 1) - (_pos1 select 1));
	if (_deg < 0) then {_deg = _deg + 360};
	_deg
};

FUNC(DirToPos) = {
	private ["_deg","_pos1","_pos2"];
	PARAMS_2(_pos1,_pos2);
	_deg = ((_pos2 select 0) - (_pos1 select 0)) atan2 ((_pos2 select 1) - (_pos1 select 1));
	if (_deg < 0) then {_deg = _deg + 360};
	_deg
};

// get a random number, floored, from count array
// parameters: array
// example: _randomarrayint = _myarray call FUNC(RandomFloorArray);
FUNC(RandomFloorArray) = {floor (random (count _this))};

// get a random item from an array
// parameters: array
// example: _randomval = _myarray call FUNC(RandomArrayVal);
FUNC(RandomArrayVal) = {_this select (_this call FUNC(RandomFloorArray))};

// get a random numer, ceiled
// parameters: number
// example: _randomint = 30 call FUNC(RandomCeil);
FUNC(RandomCeil) = {ceil (random _this)};

// returns the number of human players currently playing a mission in MP
FUNC(PlayersNumber) = {(playersNumber east + playersNumber west + playersNumber resistance + playersNumber civilian)};

// gets a random number in a specific range
// parameters: number from, number to (second number must be greater than first)
// example: _random_number = [30,150] call FUNC(GetRandomRange);
FUNC(GetRandomRange) = {
	private ["_num1","_num2","_ra"];
	PARAMS_2(_num1,_num2);
	_ra = _num2 - _num1;
	_ra = random _ra;
	(_num1 + _ra)
};

// gets a random integer number in a specific range
// parameters: integer from, integer to (second number must be greater than first)
// example: _random_integer = [30,150] call FUNC(GetRandomRangeInt);
FUNC(GetRandomRangeInt) = {
	private ["_num1","_num2","_ra"];
	PARAMS_2(_num1,_num2);
	if (_num1 > _num2) then {_num1 = _this select 1;_num2 = _this select 0};
	_ra = _num2 - _num1;
	_ra = _ra call FUNC(RandomFloor);
	(_num1 + _ra)
};

// compares two arrays, if equal returns true, if not false
// parameters: array1, array2
// example: _isequal = [array1, array2] call FUNC(ArrayCompare);
FUNC(ArrayCompare) = {(str (_this select 0) == str (_this select 1))};

// get height of object
// parameters: object (no brackets)
// _height = tank1 call FUNC(GetHeight);
FUNC(GetHeight) = {position _this select 2};

// set only height of an object
// parameters: object, height
// example: [unit1, 30] call FUNC(SetHeight);
FUNC(SetHeight) = {private "_p";_p = getPosASL (_this select 0);(_this select 0) setPos [_p select 0, _p select 1, _this select 1]};

// set only ASL height of an object
// parameters: object, height
// example: [unit1, 30] call FUNC(SetASLHeight);
FUNC(SetASLHeight) = {private "_p";_p = getPosASL (_this select 0);(_this select 0) setPosASL [_p select 0, _p select 1, _this select 1]};

// set only ATL height of an object
// parameters: object, height
// example: [unit1, 30] call FUNC(SetATLHeight);
FUNC(SetATLHeight) = {private "_p";_p = getPosASL (_this select 0);(_this select 0) setPosATL [_p select 0, _p select 1, _this select 1]};

// get x position of an object
// parameters: object (no brackets)
// _posx = tank1 call FUNC(GetPosX);
FUNC(GetPosX) = {getPosASL _this select 0};

// set only x position of an object
// parameters: object, x
// example: [unit1, 30] call FUNC(SetPosX);
FUNC(SetPosX) = {private "_p";_p = position (_this select 0);(_this select 0) setPos [_this select 1, _p select 1, _p select 2]};

// get y position of an object
// parameters: object (no brackets)
// _posy = tank1 call FUNC(GetPosY);
FUNC(GetPosY) = {getPosASL _this select 1};

// set only y position of an object
// parameters: object, y
// example: [unit1, 30] call FUNC(SetPosY);
FUNC(SetPosY) = {private "_p";_p = position (_this select 0);(_this select 0) setPos [_p select 0, _this select 1, _p select 2]};

// get displayname of an object
// parameters: type of object (string), what (0 = CfgVehicles, 1 = CfgWeapons, 2 = CfgMagazines)
// example: _dispname = ["UAZ", 0] call FUNC(GetDisplayName);
FUNC(GetDisplayName) = {
	private ["_obj_name", "_obj_kind", "_cfg"];
	PARAMS_2(_obj_name,_obj_kind);
	_cfg = switch (_obj_kind) do {case 0: {"CfgVehicles"};case 1: {"CfgWeapons"};case 2: {"CfgMagazines"};};
	getText (configFile >> _cfg >> _obj_name >> "displayName")
};

// from warfare
// Returns an average slope value of terrain within passed radius.
// a little bit modified. no need to create a "global" logic, local is enough, etc
// parameters: position, radius
// example: _slope = [the_position, the_radius] call FUNC(GetSlope);
if (isNil QGVAR(SlopeObject)) then {GVAR(SlopeObject) = "Logic" createVehicleLocal [0,0,0]};
FUNC(GetSlope) = {
	private ["_position", "_radius", "_centerHeight", "_height", "_direction", "_count"];
	PARAMS_2(_position,_radius);
	GVAR(SlopeObject) setPos _position;
	_centerHeight = getPosASL GVAR(SlopeObject) select 2;
	_height = 0;_direction = 0;
	for "_count" from 0 to 7 do {
		GVAR(SlopeObject) setPos [(_position select 0) + ((sin _direction) * _radius), (_position select 1) + ((cos _direction) * _radius), 0];
		_direction = _direction + 45;
		_height = _height + abs (_centerHeight - (getPosASL GVAR(SlopeObject) select 2));
	};
	_height / 8
};

// create a global marker, returns created marker
// parameters: marker name, marker pos, marker shape, marker color, marker size;(optional) marker text, marker dir, marker type, marker brush
// example: ["my marker",  position player, "Dot", "ColorBlue", [0.5,0.5]] call FUNC(CreateMarkerGlobal);
FUNC(CreateMarkerGlobal) = {
	private ["_m_name","_m_pos","_m_shape","_m_col","_m_size","_m_text","_m_dir","_m_type","_m_brush","_m_alpha"];
	PARAMS_5(_m_name,_m_pos,_m_shape,_m_col,_m_size);
	_m_text = if (count _this > 5) then {_this select 5} else {""};
	_m_dir = if (count _this > 6) then {_this select 6} else {-888888};
	_m_type = if (count _this > 7) then {_this select 7} else {""};
	_m_brush = if (count _this > 8) then {_this select 8} else {""};
	_m_alpha = if (count _this > 9) then {_this select 9} else {0};
	
	_marker = createMarker [_m_name, _m_pos];
	if (_m_shape != "") then {_marker setMarkerShape _m_shape};
	if (_m_col != "") then {_marker setMarkerColor _m_col};
	if (count _m_size > 0) then {_marker setMarkerSize _m_size};
	if (_m_text != "") then {_marker setMarkerText _m_text};
	if (_m_dir != -888888) then {_marker setMarkerDir _m_dir};
	if (_m_type != "") then {_marker setMarkerType _m_type};
	if (_m_brush != "") then {_marker setMarkerBrush _m_brush};
	if (_m_alpha != 0) then {_marker setMarkerAlpha _m_alpha};
	_marker
};

// create a local marker, returns created marker
// parameters: marker name, marker pos, marker shape, marker color, marker size;(optional) marker text, marker dir, marker type, marker brush
// example: ["my marker",  position player, "Dot", "ColorBlue", [0.5,0.5]] call FUNC(CreateMarkerLocal);
FUNC(CreateMarkerLocal) = {
	private ["_m_name","_m_pos","_m_shape","_m_col","_m_size","_m_text","_m_dir","_m_type","_m_brush","_m_alpha"];
	PARAMS_5(_m_name,_m_pos,_m_shape,_m_col,_m_size);
	_m_text = if (count _this > 5) then {_this select 5} else {""};
	_m_dir = if (count _this > 6) then {_this select 6} else {-888888};
	_m_type = if (count _this > 7) then {_this select 7} else {""};
	_m_brush = if (count _this > 8) then {_this select 8} else {""};
	_m_alpha = if (count _this > 9) then {_this select 9} else {0};
	
	_marker = createMarkerLocal [_m_name, _m_pos];
	if (_m_shape != "") then {_marker setMarkerShapeLocal _m_shape};
	if (_m_col != "") then {_marker setMarkerColorLocal _m_col};
	if (count _m_size > 0) then {_marker setMarkerSizeLocal _m_size};
	if (_m_text != "") then {_marker setMarkerTextLocal _m_text};
	if (_m_dir != -888888) then {_marker setMarkerDirLocal _m_dir};
	if (_m_type != "") then {_marker setMarkerTypeLocal _m_type};
	if (_m_brush != "") then {_marker setMarkerBrushLocal _m_brush};
	if (_m_alpha != 0) then {_marker setMarkerAlphaLocal _m_alpha};
	_marker
};

FUNC(GetAliveUnits) = {({alive _x} count _this)};

FUNC(GetAliveUnitsGrp) = {({alive _x} count (units _this))};

FUNC(GetAliveCrew) = {({alive _x} count (crew _this))};

FUNC(GetVehicleEmpty) = {(_this call FUNC(GetAliveCrew)) == 0};

FUNC(GetAllAlive) = {
	private "_ret";
	_ret = [];
	{if (alive _x) then {_ret set [count _ret, _x]}} forEach (units _this);
	_ret
};

FUNC(DirTo) = {
	/************************************************************
		Direction To
		By Andrew Barron

	Parameters: [object or position 1, object or position 2]

	Returns the compass direction from object/position 1 to
	object/position 2. Return is always >=0 <360.

	Example: [player, getpos dude] call FUNC(DirTo)
	************************************************************/
	private ["_pos1","_pos2","_ret"];
	PARAMS_2(_pos1,_pos2);

	if (typename _pos1 == "OBJECT") then {_pos1 = getposASL _pos1};
	if (typename _pos2 == "OBJECT") then {_pos2 = getposASL _pos2};

	_ret = ((_pos2 select 0) - (_pos1 select 0)) atan2 ((_pos2 select 1) - (_pos1 select 1));
	if (_ret < 0) then {_ret = _ret + 360};
	_ret
};

FUNC(DirTo2x) = {
	private ["_pos1","_pos2"];
	PARAMS_2(_pos1,_pos2);

	if(typename _pos1 == "OBJECT") then {_pos1 = getpos _pos1};
	if(typename _pos2 == "OBJECT") then {_pos2 = getpos _pos2};

	((_pos2 select 0) - (_pos1 select 0)) atan2 ((_pos2 select 1) - (_pos1 select 1))
};

FUNC(BDirTo) = {
	/************************************************************
	Direction To
	By Andrew Barron

	Parameters: [object or position 1, object or position 2]

	Returns the compass direction from object/position 1 to
	object/position 2. Return is always >=0 <360.

	Example: [player, getpos dude] call FUNC(BDirTo)
	************************************************************/

	private ["_pos1","_pos2","_ret"];
	
	PARAMS_2(_pos1,_pos2);

	//if objects, not positions, were passed in, then get their positions
	if (typename _pos1 == "OBJECT") then {_pos1 = getpos _pos1};
	if (typename _pos2 == "OBJECT") then {_pos2 = getpos _pos2};

	_ret = ((_pos2 select 0) - (_pos1 select 0)) atan2 ((_pos2 select 1) - (_pos1 select 1));
	_ret = _ret % 360; //ensure return is 0-360
	_ret
};

FUNC(GetParachuteSide) = {
	private "_ret";
	_ret = if (typeName _this == "STRING") then {
		switch (_this) do {
			case "EAST": {"ParachuteEast"};
			case "WEST": {"ParachuteWest"};
			case "GUER": {"ParachuteG"};
			case "CIV": {"ParachuteC"};
		}
	} else {
		switch (_this) do {
			case east: {"ParachuteEast"};
			case west: {"ParachuteWest"};
			case resistance: {"ParachuteG"};
			case civilian: {"ParachuteC"};
		}
	};
	_ret
};

FUNC(CreateTrigger) = {
	private ["_pos", "_trigarea", "_trigact", "_trigstatem", "_trigger"];
	PARAMS_4(_pos,_trigarea,_trigact,_trigstatem);
	_trigger = createTrigger ["EmptyDetector" ,_pos];
	_trigger setTriggerArea _trigarea;
	_trigger setTriggerActivation _trigact;
	_trigger setTriggerStatements _trigstatem;
	_trigger
};

// draws a marker line between two points
// param1 = position one, param2 = position two, param3 for naming the lines, value gets increased by one and returned 
// markernames are componmentname_aline_param3value
// for dom it's d_aline_1 for example
FUNC(linemaker) = {
	// _p1 and _p2 = positions
	private ["_p1", "_p2", "_curnum", "_dist", "_radius", "_dir", "_dirn", "_x1", "_y1"];
	PARAMS_3(_p1,_p2,_curnum);
	_dist = _p1 distance _p2;
	_radius = _dist / 2;
	_dir = [_p1, _p2] call FUNC(DirTo);
	_dirn = _dir + 180;
	_x1 = (_p1 select 0) - (_radius * sin _dirn);
	_y1 = (_p1 select 1) - (_radius * cos _dirn);
	//[QGVAR(epl1_) + str(_curnum),_p1,"ICON","ColorBlack",[0.5,0.5],"",0,"mil_dot"] call FUNC(CreateMarkerLocal);
	//[QGVAR(epl2_) + str(_curnum),_p2,"ICON","ColorBlack",[0.5,0.5],"",0,"mil_dot"] call FUNC(CreateMarkerLocal);
	[QGVAR(aline) + str(_curnum),[_x1, _y1],"RECTANGLE","ColorBlack",[_dist / 2, 10],"",_dir + 90,"mil_dot"] call FUNC(CreateMarkerLocal);
	__INC(_curnum);
	_curnum
};

FUNC(linemaker2) = {
	// _p1 and _p2 = positions, _mname = marker name
	private ["_p1", "_p2", "_mname", "_dist", "_radius", "_dir", "_dirn", "_x1", "_y1", "_curnum"];
	PARAMS_3(_p1,_p2,_mname);
	_dist = _p1 distance _p2;
	_radius = _dist / 2;
	_dir = [_p1, _p2] call FUNC(DirTo);
	_dirn = _dir + 180;
	_x1 = (_p1 select 0) - (_radius * sin _dirn);
	_y1 = (_p1 select 1) - (_radius * cos _dirn);
	_mpos = markerPos _mname;
	if ((_mpos select 0) == 0 &&  (_mpos select 1) == 0 && (_mpos select 2) == 0) then {
		[_mname,[_x1, _y1],"RECTANGLE","ColorBlack",[_dist / 2, 0.9],"",_dir + 90] call FUNC(CreateMarkerLocal);
	} else {
		_mname setMarkerPosLocal [_x1, _y1];
		_mname setMarkerSizeLocal [_dist / 2, 0.9];
		_mname setMarkerDirLocal _dir + 90;
	};
};

FUNC(posbehind) = {
	private ["_p1", "_p2", "_mdist", "_hdist", "_dist", "_dir", "_dirn", "_x1", "_y1"];
	PARAMS_2(_p1,_p2);
	_mdist = _p1 distance _p2;
	_hdist = _mdist * 1.7;
	_dist = _mdist + ((_hdist - _mdist) min 900);
	_dir = [_p1, _p2] call FUNC(DirTo);
	_dirn = _dir + 180;
	_x1 = (_p1 select 0) - (_dist * sin _dirn);
	_y1 = (_p1 select 1) - (_dist * cos _dirn);
	//[QUOTE(blablabla),[_x1,_y1],"ICON","ColorBlack",[1,1],"",0,"mil_dot"] call FUNC(CreateMarkerLocal);
	[[_x1,_y1,0], _dirn];
};

FUNC(posbehind2) = {
	private ["_p1", "_p2", "_dist", "_dir", "_dirn", "_x1", "_y1"];
	PARAMS_2(_p1,_p2);
	_dist = (random 1300) max 900;
	_dir = [_p1, _p2] call FUNC(DirTo);
	_dirn = _dir + 180;
	_x1 = (_p2 select 0) - (_dist * sin _dirn);
	_y1 = (_p2 select 1) - (_dist * cos _dirn);
	//[QUOTE(blablabla),[_x1,_y1],"ICON","ColorBlack",[1,1],"",0,"mil_dot"] call FUNC(CreateMarkerLocal);
	[[_x1,_y1,0], _dirn];
};

FUNC(getgroup) = {
	if (tolower (typeName _this) == "group") exitwith {_this};
	group _this
};

// CBA function
FUNC(SortAR) = {
	private "_sort";
	_sort = {
		private ["_h","_i","_j","_hi","_x"];
		PARAMS_4(_a,_id,_lo,_hi);
		 // _a, array to be sorted
		 // _id, array item index to be compared
		 // _lo, lower index to sort from
		 // _hi, upper index to sort to

		_h = nil; //used to make a do-while loop below
		_i = _lo;
		_j = _hi;
		if (count _a == 0) exitWith {};
		_x = (_a select ((_lo + _hi) / 2)) select _id;

		//  partition
		while {isnil "_h" || _i <= _j} do {
			//find first and last elements within bound that are greater / lower than _x
			while {(_a select _i) select _id < _x} do {__INC(_i)};
			while {(_a select _j) select _id > _x} do {__DEC(_j)};

			if (_i <= _j) then {
				//swap elements _i and _j
				_h = _a select _i;
				_a set [_i, _a select _j];
				_a set [_j, _h];

				__INC(_i);
				__DEC(_j);
			};
		};

		// recursion
		if (_lo < _j) then {[_a, _id, _lo, _j] call _sort};
		if (_i < _hi) then {[_a, _id, _i, _hi] call _sort};
	};

	// and start it off
	[_this select 0, _this select 1, 0, 0 max ((count (_this select 0)) - 1)] call _sort;
	
	// array is already modified by reference, but return the modified array anyway
	_this select 0
};

#ifndef __TOH__
FUNC(isVecLocked) = {
	locked _this
};
#else
FUNC(isVecLocked) = {
	locked _this > 1
};
#endif

FUNC(getUnitStance) = {
	private ["_unit", "_selz"];
	_unit = _this;
	if (isNull _unit) exitWith {""};
	if (vehicle _unit != _unit) exitWith {""};
	_selz = (_unit selectionPosition "neck") select 2;
	if (_selz == 0) exitWith {""};
	if (_selz > 1.4) exitWith {"stand"};
	if (_selz > 0.8) exitWith {"kneel"};
	"prone"
};

x_funcs1_compiled = true;