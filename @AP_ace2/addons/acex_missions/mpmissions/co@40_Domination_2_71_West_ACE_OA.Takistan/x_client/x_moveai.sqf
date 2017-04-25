// by Xeno
#define THIS_FILE "x_moveai.sqf"
#include "x_setup.sqf"
private ["_grp_player","_units_player"];
_grp_player = group player;
_units_player = units _grp_player;
if ((_units_player call FUNC(GetAliveUnits)) > 0) then {
	_units_formation = formationMembers player;
	if (isNil "_this") then {_this = []};
	if (count _this == 0) then {
		_pos_p = position player;
		_pos_p = [_pos_p select 0, _pos_p select 1, 0];
		{if (!isPlayer _x && vehicle _x == _x && _x distance _pos_p > 500) then {_x setPos _pos_p}} forEach _units_formation;
	} else {
		PARAMS_3(_pos_p,_veloc,_dir);
		waitUntil {(vehicle player isKindOf "ParachuteBase") || !alive player};
		if (!alive player) exitWith {};
		_parachute = GVAR(own_side) call FUNC(GetParachuteSide);
		{
			if (!isPlayer _x && vehicle _x == _x && _x distance _pos_p > 500) then {
				_obj_para = createVehicle [_parachute, [0,0,100], [], 0, "FLY"];
				_obj_para setDir _dir;
				_obj_para setVelocity _veloc;
				_obj_para setPos [((getPosASL player) select 0) + random 10, ((getPosASL player) select 1) + random 10, ((position player) select 2) + random 10];
				_x moveInDriver _obj_para;
				[_x] spawn {
					PARAMS_1(_unit);
					sleep 0.8321;
					waitUntil {sleep 0.111;(vehicle _unit == _unit || !alive _unit)};
					if (alive _unit) then {if (position _unit select 2 > 1) then {[_unit, 0] call FUNC(SetHeight)}};
				};
			};
		} forEach _units_formation;
	};
};