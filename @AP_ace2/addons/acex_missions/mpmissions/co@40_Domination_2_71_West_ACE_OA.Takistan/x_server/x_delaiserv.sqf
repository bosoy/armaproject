// by Xeno
#define THIS_FILE "x_delaiserv.sqf"
#include "x_setup.sqf"
private ["_group", "_dodelete", "_odl", "_dummygrp"];
if (!isServer) exitWith {};

sleep 60;

#ifdef __OWN_SIDE_WEST__
_dummygrp = createGroup west;
#endif
#ifdef __OWN_SIDE_EAST__
_dummygrp = createGroup east;
#endif
#ifdef __OWN_SIDE_GUER__
_dummygrp = createGroup resistance;
#endif
_dummygrp setVariable [QGVAR(gstate), 0];

while {true} do {
	__MPCheck;
	{
		if (!isNull _x) then {
			_group = _x;
			_has_player = false;
			{if (isPlayer _x) exitWith {_has_player = true}} forEach units _group;
			if (!_has_player) then {
				if (isNull (GVAR(player_groups_lead) select _forEachIndex)) then {
					{
						if (!isPlayer _x) then {
							if (vehicle _x != _x) then {
								_x action ["eject", vehicle _x];
								unassignVehicle _x;
								_x setPos [0,0,0];
							};
							sleep 0.01;
							deleteVehicle _x;
						};
						sleep 0.01;
					} forEach units _group;
					GVAR(player_groups) set [_forEachIndex, _dummygrp];
					GVAR(player_groups_lead) set [_forEachIndex, -1];
				};
			};
		} else {
			GVAR(player_groups) set [_forEachIndex, _dummygrp];
			GVAR(player_groups_lead) set [_forEachIndex, -1];
		};
	} forEach GVAR(player_groups);
	GVAR(player_groups) = GVAR(player_groups) - [_dummygrp];
	GVAR(player_groups_lead) = GVAR(player_groups_lead) - [-1];
	sleep 5.321;
};