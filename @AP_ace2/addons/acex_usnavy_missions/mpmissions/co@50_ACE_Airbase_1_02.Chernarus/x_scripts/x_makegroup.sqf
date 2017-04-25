private ["_grptype", "_wp_array", "_target_pos", "_numbervehicles", "_type", "_side", "_grp_in", "_vec_dir", "_grpspeed", "_grp", "_pos", "_unit_array", "_leader", "_grpskill", "_fran", "_grp_array", "_one", "_vehicles"];

if !(isServer) exitWith{};

_grptype = _this select 0;
_wp_array = _this select 1;
_target_pos = _this select 2;
_numbervehicles = _this select 3; // only for tanks and cars
_type = _this select 4;
_side = _this select 5;
_grp_in = _this select 6;
_vec_dir = _this select 7;
_grpspeed = "LIMITED";

_grp = (if (isNull _grp_in) then {[_side] call x_creategroup} else {_grp_in});
_pos = if (count _wp_array == 2) then {
	[_wp_array select 0, _wp_array select 1] call XfGetRanPointCircle
} else {
	[_wp_array select 0, _wp_array select 1,  _wp_array select 2,  _wp_array select 3] call XfGetRanPointSquare
};

_unit_array = [_grptype, _side] call x_getunitliste;

if (_numbervehicles > 0) then {
	[_numbervehicles, _pos, (_unit_array select 2), (_unit_array select 1), _grp, 0,_vec_dir] spawn x_makevgroup;
	_grp setspeedmode _grpspeed;
} else {
	[_pos, (_unit_array select 0), _grp] spawn x_makemgroup;
};

sleep 1.011;

_leader = leader _grp;
_leader setRank "LIEUTENANT";
_grpskill = (d_skill_array select 0) + (random (d_skill_array select 1));
_fran = (floor random 3) + 1;
_grp allowFleeing (_fran / 10);

switch (_type) do {
	case "patrol": {
		[_grp, _pos, _wp_array] spawn XMakePatrolWPX;
	};
	case "guard": {
		sleep 0.0123;
		if (toUpper (_grptype) in ["BASIC","SPECOPS"]) then {
			[_grp, _pos] call BIS_fnc_taskDefend;
		} else {
			[_grp, false] call XGuardWP;
		};
	};
	case "guardstatic": {
		sleep 0.0123;
		if (toUpper (_grptype) in ["BASIC","SPECOPS"]) then {
			[_grp, _pos] call BIS_fnc_taskDefend;
		} else {
			[_grp, false] call XGuardWP;
		};
	};
	case "guardstatic2": {
		_one = _vehicles select 0;
		_one setDir floor random 360;
	};
	case "attack": {
		[_grp, _target_pos] call XAttackWP;
	};
	case "attackwaves": {
		[_grp, _target_pos] call XAttackWavesWP;
	};
};

if (true) exitWith {};