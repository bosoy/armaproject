//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

ADDON = false;
LOG(MSG_INIT);

GVAR(blur) = ppEffectCreate ["dynamicBlur", -13500];
GVAR(mor_intox) = ppEffectCreate ["wetDistortion", -13504];

// bleeding
0 spawn COMPILE_FILE(bleedFX);

// pain
0 spawn COMPILE_FILE(painFX);

// drug
0 spawn COMPILE_FILE(drugFX);

// bandage, morphine action player (fsm?)
if (!isMultiplayer) then {
	0 spawn COMPILE_FILE(playeractions);
};

// TODO: This is partially redundant now. FUNC(onRespawn). Just need to add some more of the respawn logic, as well as teamSwitch to the new handlers?
execFSM QPATHTO_C(WPlayerRespawn.fsm);

// Allow single players to make themselves medic, so they have medical items with them.
if !(isMultiplayer) then {
	if (["ace", "sys_wounds", "sp_player_medic"] call ace_settings_fnc_getNumber == 1) then {
		player setVariable ["ace_w_ismedic", true];
	};
};

if (!isNil "ace_sys_wounds_enabled") then {
	["player", [ace_sys_interaction_key_self], 4, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;
	
	["CAManBase", [ace_sys_interaction_key], 5, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;
	[["Car", "Tank", "Air", "Ship", "ACE_Stretcher"], [ace_sys_interaction_key], -2, [QPATHTO_F(fnc_menuDef), "vehicle"]] call CBA_ui_fnc_add;
} else {
	["player", [ace_sys_interaction_key_self], 4, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;

	["All", [ace_sys_interaction_key], 2, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;
};

// Players get burned from burn effects. - Enabled regardless of wounds
#define ITERATION_DAMAGE 0.015
#define VEHICLE_DISTANCE 3.75
#define OBJECT_DISTANCE 3
#define INFANTRY_DISTANCE 1.7

#define INF_LIMIT 6
#define CIV_LIMIT 2
#define DAM_LIMIT 2

[] spawn {
	private ["_i", "_j", "_unit", "_burn", "_ar", "_xtra", "_unitBurns", "_vehicle"];
	_i = 0; _j = 0;
	_unit = player;
	_bloss = 0; _lbl = 0;
	while {true} do {
		// Respawn fix
		waitUntil {alive player};
		if (_unit != player) then { _i = 0; _j = 0 };
		_unit = player;

		// Are we near burning objects?
		_burn = false; _vehicle = vehicle _unit;
		_ar = if (_vehicle != _unit) then { [_vehicle] } else { (nearestObjects [_unit, [], VEHICLE_DISTANCE]) - [_unit] };
		{
			_xtra = if (_x isKindOf "CAManBase") then { (_x distance _unit) <= INFANTRY_DISTANCE } else { if (_x isKindOf "AllVehicles") then { true } else { (_x distance _unit) <= OBJECT_DISTANCE } };
			if (_xtra && {_x call ACE_fnc_isBurning}) exitWith { _burn = true }; // We are near/in fire!
		} forEach _ar;

		_unitBurns = [_unit] call ACE_fnc_isBurning;
		if (_burn || {_unitBurns}) then {
			TRACE_3("",_unit,_burn,_unitBurns);
			// Apply damage
			// TODO: Damage based on distance to object-on-fire?
			if !(_unitBurns) then {
				if (_j > DAM_LIMIT) then { [_unit, ITERATION_DAMAGE] call FUNC(addDamage) } else { INC(_j) };
			} else { _j = 0 };

			// Show red markings
			135411 cutRsc ["ace_burn_indicator_1", "PLAIN"];

			// Set _unit on fire!
			_bc = if (_unit isKindOf "Civilian") then { CIV_LIMIT } else { INF_LIMIT };
			if (_i > _bc && {!_unitBurns}) then {
				TRACE_1("Initiate Burning",_unit);
				["ace_sys_wounds_checkburn", [_unit]] call ACE_fnc_receiverOnlyEvent; // LocalEvent; Burning runs everywhere, so we only process local units
				_i = 0;
			} else {
				INC(_i);
			};

			// Show burn markings
			if (_unitBurns) then {
				135411 cutRsc ["ace_burn_indicator_2", "PLAIN"];
			};
		} else { _i = 0; _j = 0; };
		sleep 1;
	};
};

// PoorMansRevive code
GVAR(slopeObj) = "ACE_LogicDummy" createVehicleLocal [0,0,0];

FUNC(GetSlope) = {
	private ["_pos", "_rad", "_centrH", "_height", "_i"];
	_pos = _this select 0;_rad = _this select 1;
	GVAR(slopeObj) setPos _pos;
	_centrH = getPosASL GVAR(slopeObj) select 2;
	_height = 0;
	for "_dir" from 0 to 315 step 45 do {
		GVAR(slopeObj) setPos [(_pos select 0) + ((sin _dir) * _rad), (_pos select 1) + ((cos _dir) * _rad),0];
		_height = _height + abs (_centrH - (getPosASL GVAR(slopeObj) select 2));
	};
	_height / 8
};

FUNC(DoSlope) = {
	private ["_pos", "_sl", "_unit", "_rad", "_found", "_cx", "_cy", "_ang", "_x1", "_y1"];
	PARAMS_3(_pos,_sl,_unit);
	_rad = 0;_found = false;
	while {_sl >= 0.78} do {
		_cx = _pos select 0;_cy = _pos select 1;
		_rad = _rad + 10;
		for "_ang" from 0 to 345 step 15 do {
			_x1 = _cx - (_rad * sin _ang);
			_y1 = _cy - (_rad * cos _ang);
			_sl = [[_x1, _y1, 0], 1] call FUNC(GetSlope);
			if (_sl < 0.78) exitWith {
				_pos = [_x1, _y1, 0];
				_found = true;
			};
		};
		if (_found) exitWith {};
	};
	if (_found) then {_unit setPos [_pos select 0, _pos select 1, _unit distance _pos]};
};

FUNC(MaxPRDam) = {
	_this setVariable [GVAR(parts) select 0, MAX_PMR_DAM];
	_this setVariable [GVAR(parts) select 1, MAX_PMR_DAM];
	_this setVariable [GVAR(parts) select 2, MAX_PMR_DAM2];
	_this setVariable [GVAR(parts) select 3, MAX_PMR_DAM2];
};

FUNC(AddPRDam) = {
	private ["_ee", "_pd"];
	PARAMS_2(_unit,_partdamage);
	for "_ee" from 2 to 3 do {
		_pd = (_unit getVariable (GVAR(parts) select _ee)) + _partdamage;
		_pd = MAX_PMR_DAM2 min _pd;
		[_unit, _ee, _pd] call FUNC(setHit);

	};
	for "_ee" from 0 to 1 do {
		_pd = (_unit getVariable (GVAR(parts) select _ee)) + _partdamage;
		_pd = MAX_PMR_DAM min _pd;
		[_unit, _ee, _pd] call FUNC(setHit);
	};
};

FUNC(PREject) = {
	private "_unit";
	_unit = _this;
	TRACE_1("PREject",_unit);
	waitUntil {vehicle _unit == _unit};
	if (_unit call FUNC(isUncon)) then {
		TRACE_1("PREject _unit is uncon, Die animation",_unit);
		[_unit, 100] call FUNC(animator2);
	};
	_unit setVariable [QGVAR(preject), false];
};

FUNC(PRInitU) = {
	PARAMS_2(_state,_unit);
	if (_state <= 802) then {
		_unit setVariable ["ace_w_unconlen", time + MAX_UNC_TIME];
		_unit setVariable ["ace_w_state",802]; // state 802 = complete blackout,
	};
	if (_unit getVariable "ace_w_revive" == -1) then {
		_unit setVariable ["ace_w_revive", time + ace_wounds_prevtime];
		[QGVAR(rev), [_unit]] call CBA_fnc_localEvent;
	};
};

ADDON = true;
