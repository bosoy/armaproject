//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20100803
// Contact: http://creobellum.org
// Purpose: Setup MP compatible ambient civilians
// Usage: 0 = [array of locs] execVM "crB_scripts\crB_AmbientCivilians.sqf";
///////////////////////////////////////////////////////////////////
if (!isServer) exitWith{};

_locs = _this select 0;
_maxcivcount = "round (0.66 * sqrt %1)";
if(count _this > 1) then {
	_maxcivcount = _this select 1;
};

if(isNil "f_crB_randomGroup") then {
	f_crB_randomGroup = compile preprocessFileLineNumbers "crb_scripts\crB_randomGroup.sqf";
};

//for each of the towns
{
	private["_bldgpos", "_i", "_j", "_nearbldgs", "_maxcivs", "_civcount", "_pos", "_cars"];
	// identify number of doorways within 500m
	_bldgpos = [];
	_i = 0;
	_j = 0;
	_nearbldgs = nearestObjects [position _x, ["Building"], 500];
	{
		private["_y"];
		_y = _x buildingPos _i;
		while {format["%1", _y] != "[0,0,0]"} do {
			_bldgpos set [_j, _y];
			_i = _i + 1;
			_j = _j + 1;
			_y = _x buildingPos _i;
		};
		_i = 0;
	} forEach _nearbldgs;

	// identify number of civilians to create based on round (2 * (sqrt %1))
	_maxcivs = call compile format[_maxcivcount, count _bldgpos];

	// create units
	_civcount = 0;
	while{_civcount < _maxcivs} do {
		_grp = [position _x, "Infantry", "BIS_TK_CIV"] call f_crB_randomGroup;
		{
			_pos = _bldgpos select floor(random count _bldgpos);
			_x setPos _pos;
		} forEach units _grp;
		_civcount = _civcount + (count units _grp);
	};

} forEach _locs;