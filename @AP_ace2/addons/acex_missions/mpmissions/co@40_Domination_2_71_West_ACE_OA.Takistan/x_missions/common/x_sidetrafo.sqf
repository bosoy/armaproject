// by Xeno
#define THIS_FILE "x_sidetrafo.sqf"
#include "x_setup.sqf"
if (!isServer) exitWith {};

PARAMS_1(_poss);

_objs = nearestObjects [_poss, ["Land_trafostanica_velka"], 40];

#ifdef __TT__
GVAR(sm_points_west) = 0;
GVAR(sm_points_east) = 0;
{_x addEventHandler ["killed", FUNC(AddSMPoints)]} forEach _objs;
#endif

sleep 2.123;
["specops", 2, "basic", 1, _poss,200,true] spawn FUNC(CreateInf);
sleep 2.221;
["shilka", 1, "bmp", 1, "tank", 1, _poss,1,300,true] spawn FUNC(CreateArmor);

while {(_objs call FUNC(GetAliveUnits)) > 0} do {sleep 5.326};

_objs = nil;

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