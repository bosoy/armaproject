// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __TANK 6
#define __TRACKED_APC 5
#define __WHEELED_APC 4
#define __TRUCK 3
#define __CAR 2
#define __MOTORCYLCE 1
#define __SHIP 0
#define __BICYCLE -1


LOG(MSG_INIT);

// Towing ability:
// If player has Rope
// Interaction; Attach Rope to Vehicle 1 (Tow-er)
// Interaction; Attach Rope to Vehicle 2 (Tow-ed)
// Interaction; Detach Rope from Vehicle 1
// Interaction; Detach Rope from Vehicle 2
// TOW Vehicle 2 out by driving Vehicle 1
// FUTURE: Improve animations, physics etc.

FUNC(type) = {
	PARAMS_1(_target);
	private "_type";
	{
		_type = -1;
		if (_target isKindOf (_x select 0)) exitWith {
			_type = (_x select 1);
		};
	} foreach [["Tracked_APC",__TRACKED_APC], ["Wheeled_APC",__WHEELED_APC], ["Tank",__TANK], ["Truck",__TRUCK], ["Car",__CAR], ["Ship",__SHIP], ["Motorcycle",__MOTORCYLCE], ["Bicycle",__BICYCLE],["ATV_Base_EP1",__BICYCLE]];
	TRACE_1("type",_type);
	_type
};


FUNC(attachRope) = {
	// #define DEBUG_MODE_FULL
	// #include "script_component.hpp"
	private ["_rope", "_exit", "_veh_rope", "_rope_veh", "_a", "_b", "_typeOfA", "_typeOfB", "_typeOfX", "_canTow"];
	PARAMS_2(_target,_type);

	// Abort if vehicle already has a rope attached
	_veh_rope = _target getVariable QGVAR(rope);
	_exit = false;
	if !(isNil "_veh_rope") then { if !(isNull _veh_rope) then { _exit = true; } }; // Already has a rope attached
	if (_exit) exitWith { hintSilent localize "STR_ACE_TOW_ERR_1" };

	if (_type == QGVAR(B) && {({alive _x} count (crew _target)) > 0}) exitWith {
		hintSilent localize "STR_ACE_TOW_ERR_8";
	};

	// Fetch existing or create new rope
	_rope = player getVariable QGVAR(rope);

	_exit = false;
	_mag = QUOTE(ROPE_M);
	if !(isNil "_rope") then { if (isNull _rope) then { _rope = nil } };
	if (isNil "_rope") then {
		if !(_mag in (magazines player)) exitWith { _exit = true };
		player removeMagazine _mag;
		// TODO: Allow magazine to be taken from vehicle - if vehicle has one?
		/*
		if !(_mag in ((getMagazineCargo _target) select 0)) then {
			if !(_mag in (magazines player)) then { _exit = true } else { player removeMagazine _mag };
		} else {
			_target removeMagazineCargo _mag;
		};
		if (_exit) exitWith {};
		*/

		_veh = getText(configFile >> "CfgMagazines" >> _mag >> QGVAR(veh));
		_rope = _veh createVehicle (getPos player);
		player setVariable [QGVAR(rope), _rope];
	};
	if (_exit) exitWith { hintSilent (localize "STR_ACE_TOW_ERR_2") };


	// Abort if rope is already attached to a vehicle with _type
	_rope_veh = _rope getVariable _type;
	_exit = false;
	if !(isNil "_rope_veh") then { if !(isNull _rope_veh) then { _exit = true; } }; // Already has a rope attached
	if (_exit) exitWith { hintSilent (localize "STR_ACE_TOW_ERR_3") };

	// First contact with TOWING and TOWED
	_rope setVariable [_type, _target];

	// Abort if already a vehicle attached, but distance too large
	_a = _rope getVariable QGVAR(A);
	_b = _rope getVariable QGVAR(B);
	_exit = false;
	if (!isNil "_a" && {!isNil "_b"}) then { if (!isNull _a && {!isNull _b}) then { if (_a distance _b > ROPE_DIST) then { _exit = true; }}};
	if (_exit) exitWith {
		_rope setVariable [_type, nil]; hintSilent format [(localize "STR_ACE_TOW_ERR_4"), ROPE_DIST];
	};

	// Abort if types don't match
	_a = _rope getVariable QGVAR(A);
	_b = _rope getVariable QGVAR(B);
	_exit = false;
	if (!isNil "_a" && {!isNil "_b"}) then { if (!isNull _a && {!isNull _b}) then {
			_typeOfA = [_a] call FUNC(type);
			_typeOfB = [_b] call FUNC(type);
			if (_typeOfB > _typeOfA) then {
				_exit = true;
			};
		};
	};
	if (_exit) exitWith {
		_rope setVariable [_type, nil];
		hintSilent localize "STR_ACE_TOW_ERR_9";
	};
	_useDiffK = true;
	_diffK = 0;
	_memoryPoint = gettext(configfile >> "cfgvehicles" >> (typeof _target) >> "memorypointsupply");
	if (isNil "_memoryPoint") then { _memoryPoint = ""; };
	_selP = _target selectionPosition _memoryPoint;
	_selPZ = abs(_selP select 2);
	if (_selPZ == 0) then {
		_selPZ = abs((_target modelToWorld [0,0,0]) select 2);
		_selPZ = _selPZ + ((getPosATL _target) select 2);
		//_selPZ = abs(((boundingCenter _target) select 2) * 1);
		_useDiffK = false;
	};
	_offset = 0.5;
	_diff = _offset - _selPZ;
	if (_useDiffK) then { _diffK = _offset + _selPZ; } else { _diffK = _offset - _selPZ; };

	TRACE_5("","",_selPZ,_offset,_diff,_diffK);
	//TRACE_4("",_memoryPoint,"","","");

	_rope setVariable [_type, _target, true];

	// Attach the rope to the target == TOWING VEHICLE
	if (_type == QGVAR(A)) then {
		_rope attachto [_target, [0,0,_diff], _memoryPoint];
	} else { // TOWED VEHICLE
		if !(_target call CBA_fnc_locked) then {
			_target setVariable [QGVAR(locked), false]; // Used to determine the vehicle wasn't locked before - can function as a reset for when it was set true earlier
			[QGVAR(lock), [_target, true]] call CBA_fnc_globalEvent;
		} else {
			_target setVariable [QGVAR(locked), true]; // Used to determine if the vehicle was locked before
		};
		_target attachto [_rope, [0,0,_diffK], "attach_pulled"]; // Z pos stays 0

		// Double check pos
		_posAttach = getPosATL _target; TRACE_1("",_posAttach);
		_target setPosATL [(_posAttach select 0),(_posAttach select 1), 0];
	};
	_target setVariable [QGVAR(rope), _rope, true];
	hintSilent (localize "STR_ACE_TOW_INFO_1");
};
FUNC(detachRope) = {
	// #define DEBUG_MODE_FULL
	// #include "script_component.hpp"
	private ["_rope", "_exit", "_veh_rope", "_rope_veh", "_a", "_b"];
	PARAMS_2(_target,_type);

	// Abort if vehicle doesn't have a rope attached
	_veh_rope = _target getVariable QGVAR(rope);
	if (isNil "_veh_rope") exitWith { hint (localize "STR_ACE_TOW_ERR_5") }; // Has no rope
	if (isNull _veh_rope) exitWith { hint (localize "STR_ACE_TOW_ERR_5") }; // Has no rope

	_rope = _veh_Rope;

	_rope_veh = _rope getVariable _type;
	if (isNil "_rope_veh") exitWith {
		hintSilent (localize "STR_ACE_TOW_ERR_6");
	};
	if (_rope_veh != _target) exitWith {
		hintSilent (localize "STR_ACE_TOW_ERR_7");
	};

	_rope setVariable [_type, nil, true];
	_target setVariable [QGVAR(rope), nil, true];

	// Detach the rope from the target
	if (_type == QGVAR(A)) then {
		detach _rope;
	} else {
		detach _target;
		if (_target call CBA_fnc_locked) then {
			_lockedBefore = _target getVariable [QGVAR(locked), false];
			if !(_lockedBefore) then {
				[QGVAR(lock), [_target, false]] call CBA_fnc_globalEvent;
			};
		};
	};

	hint "Rope Detached!";

	// Abort converting rope into mag, if still one vehicle attached
	_a = _rope getVariable QGVAR(A);
	_b = _rope getVariable QGVAR(B);
	_exit = false;
	if !(isNil "_a") then { if !(isNull _a) then { _exit = true } };
	if (!_exit) then {
		if !(isNil "_b") then { if !(isNull _b) then { _exit = true } };
	};
	if (_exit) exitWith {};

	// Convert Rope into Magazine
	player setVariable [QGVAR(rope), nil];
	_veh = typeOf _rope;
	_mag = getText(configFile >> "CfgVehicles" >> _veh >> QGVAR(mag));
	player addMagazine _mag;
	deleteVehicle _rope;
};

[QGVAR(lock), { PARAMS_2(_unit,_lock); _unit lock _lock } ] call CBA_fnc_addEventhandler;

// Add InteractionMenu Entry
[["Car", "Tank", "Ship"], [ace_sys_interaction_key], -2, [QPATHTO_F(fnc_menudef), "main"]] call CBA_ui_fnc_add; // Air cannot tow
