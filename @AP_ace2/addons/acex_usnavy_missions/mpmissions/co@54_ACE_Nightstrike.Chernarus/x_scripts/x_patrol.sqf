private ["_not_reached_wp_array", "_private_patrol_group_array", "_aa", "_grp", "_leader", "_wp_array", "_start_pos", "_wp_pos", "_tp"];

_not_reached_wp_array = [];
_private_patrol_group_array = [];
while {true} do {
	for "_aa" from 0 to (count _private_patrol_group_array - 1) do {
		_grp = _private_patrol_group_array select _aa;
		if (!(isNull _grp) && ({alive _x} count (units _grp)) > 0) then {
			_leader = leader _grp;
			if (!isNull _leader) then {
				if (!(behaviour _leader in ["COMBAT","STEALTH"])) then {
					_wp_array = _grp getVariable "XGRP_WPARR";
					_leader = leader _grp;
					_start_pos = position _leader;
					sleep 0.01;
					if (!(_grp in _not_reached_wp_array)) then {
						_wp_pos = _wp_array select ([count _wp_array] call x_getrandom);
						_not_reached_wp_array = _not_reached_wp_array + [_grp];
						sleep 0.01;
						if (!isNull _grp) then {
							if (({alive _x} count units _grp) > 0) then {
								while {_wp_pos distance _start_pos < 20} do {
									_wp_pos = _wp_array select ([count _wp_array] call x_getrandom);
									sleep 0.01;
								};
								_grp move _wp_pos;
								_grp setSpeedMode "LIMITED";
								_grp setVariable ["XGRP_WPPOS", _wp_pos];
							};
						};
					} else {
						if ((position _leader) distance (_grp getVariable "XGRP_WPPOS") < 15) then {
							if (!isNull _grp) then {
								if (({alive _x} count units _grp) > 0) then {
									_wp_pos = _wp_array select ([count _wp_array] call x_getrandom);
									while {_wp_pos distance _start_pos < 20} do {
										_wp_pos = _wp_array select ([count _wp_array] call x_getrandom);
										sleep 0.01;
									};
									_grp move _wp_pos;
									_grp setSpeedMode "LIMITED";
									_grp setVariable ["XGRP_WPPOS", _wp_pos];
								};
							};
						};
					};
				};
			};
		} else {
			if (_grp in _not_reached_wp_array) then {
				_not_reached_wp_array = _not_reached_wp_array - [_grp];
			};
			_private_patrol_group_array set [_aa, "XM_RM_ME"];
		};
		sleep 3.528;
	};
	_private_patrol_group_array = _private_patrol_group_array - ["XM_RM_ME"];
	sleep 0.5321;
	for "_tp" from 0 to (count _not_reached_wp_array - 1) do {
		_grp = _not_reached_wp_array select _tp;
		if (isNull _grp || ({alive _x} count (units _grp)) == 0) then {_not_reached_wp_array set [_tp, "XM_RM_ME"]};
		sleep 0.012;
	};
	_not_reached_wp_array = _not_reached_wp_array - ["XM_RM_ME"];
	sleep 12.631;
	if (count patrol_groups_array > 0) then {
		can_add_patrol_group = false;
		_private_patrol_group_array = _private_patrol_group_array + patrol_groups_array;
		patrol_groups_array = [];
		can_add_patrol_group = true;
		sleep 1.218;
	};
};

if (true) exitWith {};