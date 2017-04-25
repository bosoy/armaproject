//#define DEBUG_MODE_FULL
#include "script_component.hpp"

if (vehicle player == player) exitWith {false};
if (vehicle player isKindOf "Air") exitWith {false};

if (! isNil QGVAR(meter_inpro)) exitWith {true};
GVAR(meter_inpro) = true;

_this spawn {
	private ["_veh", "_sh", "_sh_once", "_fnc_updater", "_fnc_show"];
	PARAMS_1(_action);

//local func
	_fnc_show = {
		private ["_dist", "_sh", "_state"];
		PARAMS_1(_veh);
		_dist = _veh getVariable [QGVAR(meter_dist), 0];
		_sh = _veh getVariable [QGVAR(meter_sh), GVAR(sh_done)];
		if (scriptDone _sh) then {
			_state = localize "STR_ACE_STOPPED";
		} else {
			_state = localize "STR_ACE_RUNNING";
		};
		format["%1: %2 km (%3)",localize "STR_ACE_ODOMETER",[_dist, 1, 2, true] call CBA_fnc_formatNumber,_state] spawn ace_fnc_visual;
	};

	_fnc_updater = {
		private ["_max_speed", "_dist_max", "_dist", "_cur_pos", "_height", "_dist_add"];
		PARAMS_1(_veh);
		DEFAULT_PARAM(1,_once,false);
		scopeName "upd_fnc";
		_max_speed = getNumber(configFile >> "CfgVehicles" >> (typeOf _veh) >> "maxSpeed");
		_dist_max = _max_speed / 60 / 10; //h->m, m->6s
		while {_veh == vehicle player} do {
			_dist = _veh getVariable [QGVAR(meter_dist), 0];
			_cur_pos = getPosATL _veh;
			_height = _cur_pos select 2;
			_dist_add = ((_veh getVariable [QGVAR(meter_pos),_cur_pos]) distance _cur_pos) * 0.001; //m->km

			_veh setVariable [QGVAR(meter_pos),_cur_pos];
			if ( !(_height > 10 || {_dist_add > (_dist_max + 10)})) then {
				_veh setVariable [QGVAR(meter_dist), _dist + _dist_add];
			};
			if (_once) then {breakOut "upd_fnc"};
			sleep 6;
		};
		_veh setVariable [QGVAR(meter_pos),nil];
	};
//end local func

	_veh = vehicle player;
	_sh = _veh getVariable [QGVAR(meter_sh), GVAR(sh_done)];

	switch (_action) do {
		case "start": {
			if (! scriptDone _sh) then {
				terminate _sh;
			};
			_sh_once = [_veh, true] spawn _fnc_updater;
			waitUntil {scriptDone _sh_once};
			_veh setVariable [QGVAR(meter_sh), [_veh] spawn _fnc_updater];
			[_veh] spawn _fnc_show;
		};
		case "stop": {
			if (! scriptDone _sh) then {
				terminate _sh;
			};
			_sh_once = [_veh, true] spawn _fnc_updater;
			waitUntil {scriptDone _sh_once};
			_veh setVariable [QGVAR(meter_pos),nil];
			[_veh] spawn _fnc_show;
		};
		case "reset": {
			if (! scriptDone _sh) then {
				terminate _sh;
			};
			_veh setVariable [QGVAR(meter_pos),nil];
			_veh setVariable [QGVAR(meter_dist), 0];
			[_veh] spawn _fnc_show;
		};
		default {
			WARNING("Invalid action parameter.");
		};
	};

	GVAR(meter_inpro) = nil;
};

true
