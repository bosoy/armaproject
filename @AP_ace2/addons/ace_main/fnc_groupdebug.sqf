/* ----------------------------------------------------------------------------
Function: ACE_fnc_groupDebug

Description:
	Debug Markers etc for Groups

Parameters:
	_grp - Group [Object]

Returns:


Examples:
	(begin example)
	(end)

Author:
	(c) Xeno 2010
---------------------------------------------------------------------------- */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_grp);

if (isNil QGVAR(dg_initialized)) then {
	GVAR(dg_initialized) = true;
	FUNC(GetAliveUnitsGrp) = {({alive _x} count (units _this))};

	// direction from one object to another
	// parameters: object1, object2
	// example: _dir = [tank1, apc1] call FUNC(DirToObj);
	FUNC(DirToObj) = {
		private "_deg";
		PARAMS_2(_o1,_o2);
		_deg = ((position _o2 select 0) - (position _o1 select 0)) atan2 ((position _o2 select 1) - (position _o1 select 1));
		if (_deg < 0) then {_deg = _deg + 360};
		_deg
	};

	// create a local marker, returns created marker
	// parameters: marker name, marker pos, marker shape, marker color, marker size;(optional) marker text, marker dir, marker type, marker brush
	// example: ["my marker",  position player, "Dot", "ColorBlue", [0.5,0.5]] call FUNC(CreateMarkerLocal);
	FUNC(CreateMarkerLocal) = {
		private ["_m_text","_m_dir","_m_type","_m_brush","_m_alpha"];
		PARAMS_5(_m_name,_m_pos,_m_shape,_m_col,_m_size);
		_m_text = (if (count _this > 5) then {_this select 5} else {""});
		_m_dir = (if (count _this > 6) then {_this select 6} else {-888888});
		_m_type = (if (count _this > 7) then {_this select 7} else {""});
		_m_brush = (if (count _this > 8) then {_this select 8} else {""});
		_m_alpha = (if (count _this > 9) then {_this select 9} else {0});

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
		if ((_mpos select 0) == 0 &&  {(_mpos select 1) == 0} && {(_mpos select 2) == 0}) then {
			[_mname,[_x1, _y1],"RECTANGLE","ColorBlack",[_dist / 2, 0.9],"",_dir + 90] call FUNC(CreateMarkerLocal);
		} else {
			_mname setMarkerPosLocal [_x1, _y1];
			_mname setMarkerSizeLocal [_dist / 2, 0.9];
			_mname setMarkerDirLocal _dir + 90;
		};
	};

	FUNC(map_group_count_marker) = {
		_mname = "all_groups_yeah";
		_mtext = "Groups: %1, alive units: %2";
		[_mname, [3000,0,0],"ICON","ColorBlack",[2,2],format [_mtext, 0,0],0,"mil_dot"] call FUNC(CreateMarkerLocal);
		while {true} do {
			GVAR(all_marker_groups) = GVAR(all_marker_groups) - [objNull, grpNull];
			_grpcounter = count GVAR(all_marker_groups);
			_units = 0;
			_remgrps = [];
			{
				_alu = _x call FUNC(GetAliveUnitsGrp);
				if (_alu > 0) then {
					_units = _units + _alu;
				} else {
					_remgrps set [count _remgrps, _x];
				};
			} forEach GVAR(all_marker_groups);
			if (count _remgrps > 0) then {
				GVAR(all_marker_groups) = GVAR(all_marker_groups) - _remgrps;
			};
			_mname setMarkerTextLocal format [_mtext, _grpcounter,_units];
			sleep 1;
		};
	};

	FUNC(groupmarker) = {
		private ["_grp", "_mname", "_mnamel", "_leader", "_p1", "_wps", "_idx", "_curwppos", "_gname"];
		PARAMS_1(_grp);
		waitUntil {(_grp call FUNC(GetAliveUnitsGrp)) > 0};
		_gname = str(_grp);
		_mname = _gname + "dgrp";
		_mnamel = _mname + "lm";
		_mnamewp = _mname + "wpm";
		_gname = _gname;
		sleep 1;
		GVAR(all_marker_groups) set [count GVAR(all_marker_groups), _grp];
		_vec = vehicle leader _grp;
		_mtype = if (_vec == leader _grp) then {
			if (side _grp == west) then {"b_inf"} else {"o_inf"}
		} else {
			switch (true) do {
				case (_vec isKindOf "Wheeled_APC"): {if (side _grp == west) then {"b_mech_inf"} else {"o_mech_inf"}};
				case (_vec isKindOf "Car"): {if (side _grp == west) then {"b_motor_inf"} else {"o_motor_inf"}};
				case (_vec isKindOf "Tank"): {if (side _grp == west) then {"b_armor"} else {"o_armor"}};
				case (_vec isKindOf "Helicopter"): {if (side _grp == west) then {"b_air"} else {"o_air"}};
				case (_vec isKindOf "Plane"): {if (side _grp == west) then {"b_plane"} else {"o_plane"}};
				case (_vec isKindOf "StaticCannon"): {if (side _grp == west) then {"b_art"} else {"o_art"}};
				case (_vec isKindOf "StaticMortar"): {if (side _grp == west) then {"b_mortar"} else {"o_mortar"}};
				default {if (side _grp == west) then {"b_support"} else {"n_support"}};
			}
		};
		[_mname, [0,0,0],"ICON",(if (side _grp == east) then {"ColorRed"} else {"ColorBlue"}),[0.8,0.8],_gname,0,_mtype] call FUNC(CreateMarkerLocal);
		_gname = _gname + " (%1)";
		while {true} do {
			if (isNull _grp || {(_grp call FUNC(GetAliveUnitsGrp)) == 0}) exitWith {
				deleteMarkerLocal _mname;
				deleteMarkerLocal _mnamel;
				deleteMarkerLocal _mnamewp;
			};
			_leader = leader _grp;
			if (!isNull _leader) then {
				_p1 = getPosASL _leader;
				_p1 set [2,0];
				_mname setMarkerPosLocal _p1;
				_mname setMarkerTextLocal format [_gname, _grp call FUNC(GetAliveUnitsGrp)];
				_wps = waypoints _grp;
				_idx = currentWaypoint _grp;
				if (_idx < count _wps && {_idx > 0}) then {
					_curwppos = waypointPosition (_wps select _idx);
					_curwppos set [2,0];
					_mpos = markerPos _mnamewp;
					if ((_mpos select 0) == 0 &&  {(_mpos select 1) == 0} && {(_mpos select 2) == 0}) then {
						[_mnamewp,_curwppos,"ICON","ColorGreen",[0.7, 0.7],"",0,"waypoint"] call FUNC(CreateMarkerLocal);
					} else {
						_mnamewp setMarkerPosLocal _curwppos;
					};
					[_p1, _curwppos, _mnamel] call FUNC(linemaker2);
				} else {
					deleteMarkerLocal _mnamel;
					deleteMarkerLocal _mnamewp;
				};
			} else {
				deleteMarkerLocal _mnamel;
				deleteMarkerLocal _mnamewp;
			};
			sleep (0.6 + random 0.2);
		};
	};
};

if (isNil QGVAR(all_marker_groups)) then {
	GVAR(all_marker_groups) = [];
	0 spawn FUNC(map_group_count_marker);
};

[_grp] spawn FUNC(groupmarker);
