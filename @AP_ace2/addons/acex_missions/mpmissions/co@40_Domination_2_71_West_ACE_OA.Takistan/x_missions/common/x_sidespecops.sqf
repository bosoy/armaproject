// by Xeno
#define THIS_FILE "x_sidespecops.sqf"
#include "x_setup.sqf"
private ["_poss", "_fire", "_radius", "_angle", "_i", "_x1", "_y1", "_tent", "_grps", "_units", "_endnum"];
if (!isServer) exitWith {};

PARAMS_1(_poss);

_fire = createVehicle ["Land_Fire", _poss, [], 0, "NONE"];
_fire setPos _poss;
__AddToExtraVec(_fire)
sleep 0.01;

_center_x = _poss select 0;
_center_y = _poss select 1;
_radius = 5;
_angle = 0;
_pos_array = [];
_count_obj = 4;
_angle_plus = 360 / _count_obj;

for "_i" from 0 to _count_obj - 1 do {
	_x1 = _center_x - (_radius * sin _angle);
	_y1 = _center_y - (_radius * cos _angle);
	_pos_array set [count _pos_array, [[_x1,_y1,0], _angle]];
	_angle = _angle + _angle_plus;
};


#ifdef __TT__
GVAR(sm_points_west) = 0;
GVAR(sm_points_east) = 0;
#endif

for "_i" from 0 to (_count_obj - 1) do {
	_obj_pos_dir = _pos_array select _i;
	_tent = createVehicle [GVAR(sm_tent), _obj_pos_dir select 0, [], 0, "NONE"];
	_tent setDir (_obj_pos_dir select 1);
	_tent setPos (_obj_pos_dir select 0);
	__AddToExtraVec(_tent)
	sleep 0.2321;
};

_pos_array = nil;

_grps = ["specops", 3, "basic", 0, _poss , 150, true] call FUNC(CreateInf);
_units = [];
{
	_units = [_units, units _x] call FUNC(arrayPushStack)
} forEach _grps;

GVAR(num_species) = 0;

private "_unitcode";
_unitcode = {
	_this allowFleeing 0;
	_this addEventHandler ["killed", {
		__INC(GVAR(num_species));
		#ifdef __TT__
		_this call FUNC(AddSMPoints);
		#endif
	}];
	__addDeadAI(_this)
};
{
	[_x, _unitcode] call FUNC(setUnitCode);
} forEach _units;

sleep 2.123;
_endnum = (count _units) - 2;

while {GVAR(num_species) < _endnum} do {
	{
		if (alive _x) then {
			_dist = _x distance _poss;
			if (_dist > 200 && _dist < 400) then {
				(leader _x) doMove _poss;
			} else {
				if (_dist >= 400) then {_x setDamage 1};
			};
			sleep 0.01;
		};
	} forEach _units;
	sleep 4.631;
};

_units = nil;

#ifndef __TT__
GVAR(side_mission_winner) = 2;
#else
if (GVAR(sm_points_west) > GVAR(sm_points_east)) then {
	GVAR(side_mission_winner) = 2;
} else {
	if (GVAR(sm_points_east) > GVAR(sm_points_west)) then {
		GVAR(side_mission_winner) = 1;
	} else {
		if (GVAR(sm_points_east) == GVAR(sm_points_west)) then {
			GVAR(side_mission_winner) = 123;
		};
	};
};
#endif
GVAR(side_mission_resolved) = true;