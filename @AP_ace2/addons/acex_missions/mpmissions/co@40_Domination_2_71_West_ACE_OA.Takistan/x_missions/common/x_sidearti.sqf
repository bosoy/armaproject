// by Xeno
#define THIS_FILE "x_sidearty.sqf"
#include "x_setup.sqf"
private ["_angle","_angle_plus","_arti","_arti_pos_dir","_center_x","_center_y","_count_arti","_grp","_i","_pos_array","_poss","_radius","_this","_truck","_unit","_x1","_y1"];
if (!isServer) exitWith {};

PARAMS_1(_poss);

#ifndef __TT__
GVAR(sm_arty_crewman) = getText (configFile >> "CfgVehicles" >> GVAR(sm_arty) >> "crew");
#endif

// calc positions
_center_x = _poss select 0;
_center_y = _poss select 1;
_radius = 30;
_angle = 0;
_pos_array = [];
_count_arti = 8;
_angle_plus = 360 / _count_arti;

for "_i" from 0 to _count_arti - 1 do {
	_x1 = _center_x - (_radius * sin _angle);
	_y1 = _center_y - (_radius * cos _angle);
	_pos_array set [count _pos_array, [[_x1,_y1,0], _angle]];
	_angle = _angle + _angle_plus;
};

GVAR(dead_arti) = 0;
__GetEGrp(_grp)

#ifdef __TT__
GVAR(sm_points_west) = 0;
GVAR(sm_points_east) = 0;
#endif

for "_i" from 0 to (_count_arti - 1) do {
	_arti_pos_dir = _pos_array select _i;
	_arti = createVehicle [GVAR(sm_arty), _arti_pos_dir select 0, [], 0, "NONE"];
	_arti setDir (_arti_pos_dir select 1);
	_arti setPos (_arti_pos_dir select 0);
	GVAR(extra_mission_vehicle_remover_array) set [count GVAR(extra_mission_vehicle_remover_array), _arti];
	_arti addEventHandler ["killed",{__INC(GVAR(dead_arti));_this call FUNC(handleDeadVec);
		#ifdef __TT__
		_this call FUNC(AddSMPoints)
		#endif
	}];
	if (GVAR(domdatabase)) then {
		_arti addEventHandler ["Killed", {if (isServer) then {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddCarKillPoints)}}}];
	};
	_arti lock true;
	_unit = _grp createUnit [GVAR(sm_arty_crewman), _arti_pos_dir select 0, [], 0, "NONE"];
	if (GVAR(without_nvg) == 0) then {
		if (_unit hasWeapon "NVGoggles") then {_unit removeWeapon "NVGoggles"};
	};
	_unit setSkill 1;_unit assignAsGunner _arti;_unit moveInGunner _arti;
	_unit setVariable ["BIS_noCoreConversations", true];
	__addDeadAI(_unit)
	if (GVAR(domdatabase)) then {
		_unit addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddAIKillPoints)}}];
	};
	sleep 0.5321;
};

_pos_array = nil;

for "_i" from 1 to 3 do {
	_truck = createVehicle [GVAR(sm_ammotrucktype), _poss, [], 0, "NONE"];
	_truck setPos _poss;
	_truck lock true;
	if (GVAR(domdatabase)) then {
		_truck addMPEventHandler ["MPKilled", {if (isServer) then {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddCarKillPoints)}}}];
	};
	sleep 0.523;
};

sleep 2.123;
["specops", 3, "basic", 2, _poss, 300,true] spawn FUNC(CreateInf);
sleep 4.123;
["shilka", 1, "bmp", 2, "tank", 1, _poss,1,400,true] spawn FUNC(CreateArmor);

while {GVAR(dead_arti) != _count_arti} do {
	sleep 4.631;
};

GVAR(dead_arti) = nil;

#ifndef __TT__
GVAR(side_mission_winner) = 2;
#endif
#ifdef __TT__
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
GVAR(no_more_observers) = true;