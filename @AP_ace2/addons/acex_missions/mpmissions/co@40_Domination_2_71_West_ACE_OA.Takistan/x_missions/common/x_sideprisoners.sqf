// by Xeno
#define THIS_FILE "x_sideprisoners.sqf"
#include "x_setup.sqf"
private ["_posi_a", "_pos", "_newgroup", "_unit_array", "_leader", "_hostages_reached_dest", "_all_dead", "_rescued", "_units", "_winner", "_nobjs", "_retter", "_do_loop", "_i", "_one"];
if (!isServer) exitWith {};

PARAMS_1(_posi_a);
_pos = _posi_a select 0;
_posi_a = nil;

if (GVAR(with_ranked)) then {GVAR(sm_p_pos) = nil};

sleep 2;

#ifndef __TT__
_newgroup = [GVAR(own_side)] call FUNC(creategroup);
#else
_newgroup = [civilian] call FUNC(creategroup);
#endif
_unit_array = ["civilian", "CIV"] call FUNC(getunitliste);
[_pos, _unit_array select 0, _newgroup] call FUNC(makemgroup);
_leader = leader _newgroup;
_leader setSkill 1;
_unit_array = nil;
sleep 2.0112;
_newgroup allowFleeing 0;
_newgroup setVariable [QGVAR(gstate), 1];
_units = units _newgroup;
{
	removeAllWeapons _x;
	_x setCaptive true;
	_x disableAI "MOVE";
} forEach _units;

sleep 2.333;
["specops", 2, "basic", 2, _pos,100,true] spawn FUNC(CreateInf);
sleep 2.333;
["shilka", 1, "bmp", 1, "tank", 1, _pos,1,140,true] spawn FUNC(CreateArmor);

sleep 32.123;

_hostages_reached_dest = false;
_all_dead = false;
_rescued = false;

#ifdef __TT__
_winner = 0;
#endif

if (!GVAR(with_ai)) then {
	while {!_hostages_reached_dest && !_all_dead} do {
		__MPCheck;
		if ((_units call FUNC(GetAliveUnits)) == 0) then {
			_all_dead = true;
		} else {
			if (!_rescued) then {
				_leader = leader _newgroup;
				_nobjs = (position _leader) nearEntities ["CAManBase", 20];
				if (count _nobjs > 0) then {
					{
						if (isPlayer _x && (toUpper (str(_x)) in ["RESCUE","RESCUE2"]) && alive _x) exitWith {
							_rescued = true;
							_retter = _x;
							{
								if (!isNull _x && alive _x) then {
									_x setCaptive false;
									_x enableAI "MOVE";
								};
							} forEach _units;
							[QGVAR(joing), [group _retter, _units]] call FUNC(NetCallEventSTO);
						};
						sleep 0.01;
					} forEach _nobjs;
				};
			} else {
				_do_loop = true;
				{
					if (!isNull _x && alive _x) then {
						if (!__TTVer) then {
							if ((vehicle _x) distance GVAR(FLAG_BASE) < 20) then {
								_hostages_reached_dest = true;
								_do_loop = false;
							};
						} else {
							if ((vehicle _x) distance GVAR(WFLAG_BASE) < 20) then {
								_hostages_reached_dest = true;
								_do_loop = false;
								_winner = 2;
							} else {
								if ((vehicle _x) distance GVAR(EFLAG_BASE) < 20) then {
									_hostages_reached_dest = true;
									_do_loop = false;
									_winner = 1;
								};
							};
						};
					};
					if (!_do_loop) exitWith {};
				} forEach _units;
			};
		};
		if (__RankedVer) then {
			if (_hostages_reached_dest) then {
				if (!__TTVer) then {
					[QGVAR(sm_p_pos), position GVAR(FLAG_BASE)] call FUNC(NetCallEventToClients);
				} else {
					switch (_winner) do {
						case 1: {[QGVAR(sm_p_pos), position GVAR(EFLAG_BASE)] call FUNC(NetCallEventToClients)};
						case 2: {[QGVAR(sm_p_pos), position GVAR(WFLAG_BASE)] call FUNC(NetCallEventToClients)};
					};
				};
			};
		};
		sleep 5.123;
	};
} else {
	_retter = objNull;

	while {!_hostages_reached_dest && !_all_dead} do {
		__MPCheck;
		if ((_units call FUNC(GetAliveUnits)) == 0) then {
			_all_dead = true;
		} else {
			if (!_rescued) then {
				_leader = leader _newgroup;
				_nobjs = (position _leader) nearEntities ["CAManBase", 20];
				if (count _nobjs > 0) then {
					{
						if (isPlayer _x && alive _x) exitWith {
							_rescued = true;
							_retter = _x;
						};
						sleep 0.01;
					} forEach _nobjs;
					if (_rescued && !isNull _retter) then {
						{
							if (!isNull _x && alive _x) then {
								_x setCaptive false;
								_x enableAI "MOVE";
							};
						} forEach _units;
						[QGVAR(joing), [group _retter, _units]] call FUNC(NetCallEventSTO);
					};
				};
			} else {
				{
					if (!isNull _x && alive _x && (vehicle _x) distance GVAR(FLAG_BASE) < 20) exitWith {_hostages_reached_dest = true};
				} forEach _units;
			};
		};
		if (__RankedVer) then {
			if (_hostages_reached_dest) then {[QGVAR(sm_p_pos), position GVAR(FLAG_BASE)] call FUNC(NetCallEvent)};
		};
		sleep 5.123;
	};
};

if (_all_dead) then {
	GVAR(side_mission_winner) = -400;
} else {
	if (_hostages_reached_dest) then {
		if ((_units call FUNC(GetAliveUnits)) > 7) then {
#ifndef __TT__
			GVAR(side_mission_winner) = 2;
#else
			GVAR(side_mission_winner) = _winner;
#endif
		} else {
			GVAR(side_mission_winner) = -400;
		};
	} else {
		GVAR(side_mission_winner) = -400;
	};
};

GVAR(side_mission_resolved) = true;

sleep 5.123;

{
	if (!isNull _x) then {
		if (vehicle _x != _x) then {
			_x action ["eject", vehicle _x];
			unassignVehicle _x;
			_x setPos [0,0,0];
		};
		deleteVehicle _x;
	};
} forEach _units;
sleep 0.5321;
if (!isNull _newgroup) then {deleteGroup _newgroup};

_units = nil;
