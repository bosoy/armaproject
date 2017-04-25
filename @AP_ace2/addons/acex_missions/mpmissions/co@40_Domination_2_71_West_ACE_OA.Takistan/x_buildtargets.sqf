private ["_i", "_mname", "_dtar", "_ar", "_pos", "_nlocs", "_nl", "_name"];
GVAR(targets_store) = "HeliHEmpty" createVehicleLocal [0, 0, 0];
GVAR(last_target_idx) = -1;
_east_targets_ar = [];
_west_targets_ar = [];
for "_i" from 0 to 100000 do {
	_mname = format [QGVAR(target_%1), _i];
	_dtar = __getMNsVar2(_mname);
	if (isNil "_dtar") exitWith {
		GVAR(last_target_idx) = _i - 1;
	};
	_dtar enableSimulation false;
	if ((direction _dtar < 90) || (direction _dtar > 270)) then {
		_east_targets_ar set [count _east_targets_ar, _dtar]
	} else {
		_west_targets_ar set [count _west_targets_ar, _dtar]
	};
	_ar = [];
	_name = GV(_dtar,GVAR(cityname));
	if (!isNil "_name") then {
		_ar set [count _ar, _name]; // name village/city
		_pos = getPosASL _dtar;
		_pos set [2, 0];
		_ar set [count _ar, _pos]; // position CityCenter by logic
	} else {
		_pos = [0,0,0];
		_nlocs = nearestLocations [getPosASL _dtar, ["NameCityCapital","NameCity","NameVillage"], 1000];
		if (count _nlocs > 0) then {
			_ar set [count _ar, text (_nlocs select 0)]; // name village/city
			_nl = nearestLocations [locationPosition (_nlocs select 0), ["CityCenter"], 1000];
			_pos = if (count _nl > 0) then {
				locationPosition (_nl select 0)
			} else {
				locationPosition (_nlocs select 0)
			};
			_pos set [2, 0];
			_ar set [count _ar, _pos]; // position CityCenter
			if (isServer) then {
				_dtar setPos _pos;
			};
		} else {
				hint ("No city found near target location " + _mname);
		};
	};
	__TRACE_1("All targets found","_ar")
	GVAR(targets_store) setVariable [_mname, _ar];
};

if (isServer) then {
	private ["_i", "_mname", "_dtar", "_ar", "_har", "_exitit", "_nlocs", "_nobjs", "_strx", "_ranlist", "_firstt", "_mname2", "_sect", "_ar2", "_ransel", "_tar1i", "_tar2i", "_ranval", "_tar1", "_tar2", "_ct1ar", "_ct1", "_ct2ar", "_ct2", "_curtarget", "_ntarget", "_ndist", "_helpers", "_helper", "_dist", "_ntargetar"];
	if (isServer) then {
		GVAR(targets_west_won) = count _west_targets_ar;
		GVAR(targets_east_won) = count _east_targets_ar;
	};
	
	// build neighbours
	for "_i" from 0 to GVAR(last_target_idx) do {
		_mname = format [QGVAR(target_%1), _i];
		_dtar = __getMNsVar2(_mname);
		_ar = GV2(GVAR(targets_store),_mname);
		_har = [];
		_exitit = false;
		_nlocs = nearestLocations [getPosASL _dtar, ["NameCityCapital","NameCity","NameVillage"], 5000];
		{
			_nobjs = (locationPosition _x) nearEntities ["LocationLogicCity", 1000];
			{
				if (_x != _dtar) then {
					_strx = str _x;
					if !(_strx in _har) then {_har set [count _har, _strx]};
				};
				if (count _har == 5) exitWith {_exitit = true};
			} forEach _nobjs;
			if (_exitit) exitWith {};
		} forEach _nlocs;
		
		_ar set [count _ar, _har];
		_ar set [count _ar, _i];
		_radius = GV(_dtar,GVAR(cityradius));
		_ar set [count _ar, if (isNil "_radius") then {300} else {_radius}];
		__TRACE_1("Neighbour array","_ar")
		GVAR(targets_store) setVariable [_mname, _ar];
	};
	// random first two cities
	_ranlist = [];
	for "_i" from 0 to GVAR(last_target_idx) do {
		_mname = format [QGVAR(target_%1), _i];
		__TRACE_1("x_buildtargets.sqf","_mname")
		_firstt = __getMNsVar2(_mname);
		_ar = GV2(GVAR(targets_store),_mname);
		__TRACE_1("x_buildtargets.sqf","_ar")
		_mname2 = (_ar select 2) select 0;
		_sect = __getMNsVar2(_mname2);
		_ar2 = GV2(GVAR(targets_store),_mname2);
		if (((direction _firstt < 90) || (direction _firstt > 270)) && ((direction _sect >= 90) && (direction _sect <= 270))) then {
			_ranlist set [count _ranlist, [_ar select 3, _ar2 select 3]];
		};
		if (count (_ar select 2) > 1) then {
			_mname2 = ((_ar select 2) select 1);
			_sect = __getMNsVar2(_mname2);
			_ar2 = GV2(GVAR(targets_store),_mname2);
			if (((direction _firstt < 90) || (direction _firstt > 270)) && ((direction _sect >= 90) && (direction _sect <= 270))) then {
				_ranlist set [count _ranlist, [_ar select 3, _ar2 select 3]];
			};
		};
	};
	__TRACE_1("Random two targets list","_ranlist")
	
	// select a random pair
	_ransel = _ranlist call FUNC(RandomArrayVal);
	_tar1i = _ransel select 0;
	_tar2i = _ransel select 1;
	
	//_ranval = random 100;
	[QGVAR(current_targets),_ransel] call FUNC(NetSetJIP);
	__TRACE_1("Two random selected targets","_ransel")
	
	_tar1 = format [QGVAR(target_%1), _tar1i];
	_tar2 = format [QGVAR(target_%1), _tar2i];
	
	_targets_list = [];

	// build random route from first target of the selected pair, then from second target of the selected pair
	_ct1ar = GV2(GVAR(targets_store),_tar1);
	_ct1 = __getMNsVar2(_tar1);
	_ct2ar = GV2(GVAR(targets_store),_tar2);
	_ct2 = __getMNsVar2(_tar2);
	_first_ar = [];
	_second_ar = [];
	if ((direction _ct1 < 90) || (direction _ct1 > 270)) then {
		_first_ar = _east_targets_ar;
		_second_ar = _west_targets_ar;
	} else {
		_first_ar = _west_targets_ar;
		_second_ar = _east_targets_ar;
	};
	_curtarget = _ct1;
	_targets_list = [_ct1ar select 3];
	_first_ar = _first_ar - [_curtarget];
	while {count _first_ar > 0} do {
		_ntarget = objNull;
		_ndist = 100000000;
		{
			_helpers = str _x;
			_helper = __getMNsVar2(_helpers);
			_dist = _helper distance _curtarget;
			if (_dist < _ndist) then {
				_ndist = _dist;
				_ntarget = _x;
			};
		} forEach _first_ar;
		if (!isNull _ntarget) then {
			_first_ar = _first_ar - [_ntarget];
			_ntargetar = GVAR(targets_store) getVariable str _ntarget;
			_targets_list = [_ntargetar select 3] + _targets_list;
			_curtarget = _ntarget;
		};
	};

	_curtarget = _ct2;
	_second_ar = _second_ar - [_curtarget];
	_targets_list set [count _targets_list, _ct2ar select 3];
	while {count _second_ar > 0} do {
		_ntarget = objNull;
		_ndist = 100000000;
		{
			_helpers = str _x;
			_helper = __getMNsVar2(_helpers);
			_dist = _helper distance _curtarget;
			if (_dist < _ndist) then {
				_ndist = _dist;
				_ntarget = _x;
			};
		} forEach _second_ar;
		if (!isNull _ntarget) then {
			_second_ar = _second_ar - [_ntarget];
			_ntargetar = GVAR(targets_store) getVariable str _ntarget;
			_targets_list set [count _targets_list, _ntargetar select 3];
			_curtarget = _ntarget;
		};
	};
	__TRACE_1("Final main targets list","_targets_list")
	[QGVAR(targets_list), _targets_list] call FUNC(NetSetJIP);
};