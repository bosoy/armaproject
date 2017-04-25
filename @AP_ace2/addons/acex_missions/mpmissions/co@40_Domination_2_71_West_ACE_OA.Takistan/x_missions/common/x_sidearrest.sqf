// by Xeno
#define THIS_FILE "x_sidearrest.sqf"
#include "x_setup.sqf"
private ["_is_dead","_leader","_nobjs","_officer","_offz_at_base","_rescued","_winner","_group"];
if (!isServer) exitWith {};

PARAMS_1(_officer);

_offz_at_base = false;
_is_dead = false;
_rescued = false;
_winner = 0;

if (GVAR(with_ranked)) then {GVAR(sm_p_pos) = nil};

while {!_offz_at_base && !_is_dead} do {
	__MPCheck;
	if (!alive _officer) then {
		_is_dead = true;
	} else {
		if (!_rescued) then {
			_nobjs = (position _officer) nearEntities ["CAManBase", 20];
			if (count _nobjs > 0) then {
				{
					if (isPlayer _x && alive _x) exitWith {
						_rescued = true;
						_officer enableAI "MOVE";
						[QGVAR(joing), [group _x, [_officer]]] call FUNC(NetCallEventSTO);
						[QGVAR(setcapt), [_officer, true]] call FUNC(NetCallEvent);
					};
				} forEach _nobjs;
			};
		} else {
			if (_officer distance GVAR(FLAG_BASE) < 30) then {
				_offz_at_base = true;
			};
		};
	};

	sleep 5.621;
};

if (_is_dead) then {
	GVAR(side_mission_winner) = -500;
} else {
	if (_offz_at_base) then {
		if (GVAR(with_ranked)) then {
			if !(__TTVer) then {
				[QGVAR(sm_p_pos), position GVAR(FLAG_BASE)] call FUNC(NetCallEventToClients);
			} else {
				if (_winner == 1) then {
					[QGVAR(sm_p_pos), position GVAR(EFLAG_BASE)] call FUNC(NetCallEventToClients);
				} else {
					[QGVAR(sm_p_pos), position GVAR(WFLAG_BASE)] call FUNC(NetCallEventToClients);
				};
			};
		};
		if (_winner != 0) then {
			GVAR(side_mission_winner) = _winner;
		} else {
			GVAR(side_mission_winner) = 2;
		};
		sleep 2.123;
		if (vehicle _officer != _officer) then {
			_officer action ["eject", vehicle _officer];
			unassignVehicle _officer;
			_officer setPos [0,0,0];
		};
		sleep 0.5;
		deleteVehicle _officer;
	};
};

GVAR(side_mission_resolved) = true;