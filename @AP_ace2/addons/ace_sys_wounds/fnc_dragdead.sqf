/* ace_sys_wounds(.pbo)  */
#include "script_component.hpp"

#define __LOAD (localize "STR_ACE_UA_LOAD")
#define __CARRY (localize "STR_ACE_UA_CARRYWOUNDED")
#define __DROP (localize "STR_ACE_UA_DROP")

// _this (c) by Xeno

closeDialog 0;

private ["_dragee", "_unit", "_found_anim"];
PARAMS_1(_dragee);

TRACE_1("Drag Dead", _dragee);

if (isNull _dragee) exitWith {};
if (!alive player) exitWith {};

_unit = player;
private ["_name_dragee"];
_name_dragee = localize "STR_ACE_NO_UNIT";

// fix from norrin
// Add "C" key down eventhandler
GVAR(drag_keyDownEHId) = (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call ace_sys_wounds_fnc_dragkeydown"];

// from norrins revive!

//player assumes dragging posture
_unit playMove "acinpknlmstpsraswrfldnon";
sleep 2;

//unconscious unit assumes dragging posture
[QGVAR(a3), _dragee] call CBA_fnc_globalEvent;

//attach unconscious unit
_dragee attachto [_unit,[0.1, 1.01, 0]];
sleep 0.02;
[QGVAR(dir), _dragee] call CBA_fnc_globalEvent;
GVAR(drag) 	= true;

// drop body added
if (GVAR(dropAction) != -3333) then {player removeAction GVAR(dropAction);GVAR(dropAction) = -3333};
GVAR(dropAction) = player addAction [format[__DROP,(_name_dragee)], QPATHTO_C(drop_body.sqf), [_dragee, 0], 0, false, true];
GVAR(carryAction) = player addAction [format[__CARRY,(_name_dragee)], QPATHTO_C(carrydead.sqf), _dragee, 0, false, true];
GVAR(loadAction) = - 3333;
sleep 1;

_found_anim = false;

// Stamina Boost while carrying wounded
// TODO: Get weight of wounded
[player, 35] call ace_sys_stamina_fnc_inc_mass; // 35 kg, randomly picked for weight impact of dragging action

while {GVAR(drag)} do {
	if (!_found_anim) then {
		if (animationState player in ["acinpknlmstpsraswrfldnon","acinpknlmwlksraswrfldb","acinpknlmstpsraswrfldnon"]) then {
			_found_anim = true;
		};
	};
	_pisuncon = _unit call FUNC(isUncon); // check if dragger is uncon
	//check that dragged unit still exists
	if (!alive _unit || {_pisuncon}) exitWith {
		player removeAction GVAR(dropAction);
		GVAR(dropAction) = -3333;
		if (GVAR(carryAction) != -3333) then {
			player removeAction GVAR(carryAction);
			GVAR(carryAction) = -3333;
		};
		detach _unit;
		sleep 0.5;
		[_dragee, 101] call FUNC(animator);
		if (!_pisuncon) then {
			[QGVAR(aswmnon), _unit] call CBA_fnc_globalEvent;
		};
		sleep 1;
		GVAR(drag) = false;
	};
	if (_found_anim && {!((animationState _unit) in ["acinpknlmstpsraswrfldnon","acinpknlmwlksraswrfldb","acinpknlmstpsraswrfldnon"])}) exitWith {
		player removeAction GVAR(dropAction);
		GVAR(dropAction) = -3333;
		if (GVAR(carryAction) != -3333) then {
			player removeAction GVAR(carryAction);
			GVAR(carryAction) = -3333;
		};
		detach _dragee;
		[_dragee, 101] call FUNC(animator);
		if (!_pisuncon) then {
			[QGVAR(aswmnon), _unit] call CBA_fnc_globalEvent;
		};
		sleep 1;
		GVAR(drag) = false;
	};
	if (isNull _dragee) then {
		player removeAction GVAR(dropAction);
		GVAR(dropAction) = -3333;
		if (GVAR(carryAction) != -3333) then {
			player removeAction GVAR(carryAction);
			GVAR(carryAction) = -3333;
		};
		detach _unit;
		if (!_pisuncon) then {
			[QGVAR(aswmnon), _unit] call CBA_fnc_globalEvent;
		};
		sleep 1;
		GVAR(drag) = false;
	};

	_nos = nearestObjects [player, ["Car","Tank","Helicopter","Plane","ACE_Stretcher"], 5];
	if (count _nos > 0) then {
		_vec = _nos select 0;
		if (!(_vec isKindOf "ParachuteBase") && {!(_vec isKindOf "BIS_Steerable_Parachute")} && {!(_vec isKindOf "UAV")}) then {
			// check for free cargo slots
			_cargocrew = 0;
			{
				_vecrole = assignedVehicleRole _x;
				if (count _vecrole > 0 && {(_vecrole select 0) == "Cargo"}) then {
					INC(_cargocrew);
				};
			} forEach (crew _vec);
			_tps = getNumber(configFile >> "CfgVehicles" >> typeOf _vec >> "transportSoldier");
			if (_cargocrew < _tps) then {
				if (GVAR(loadAction) == -3333) then {
					GVAR(loadAction) = player addAction [format[__LOAD,(_name_dragee), typeOf _vec], QPATHTO_C(load.sqf), [_dragee, _vec], 0, false, true];
				};
			} else {
				if (GVAR(loadAction) != -3333) then {
					player removeAction GVAR(loadAction);
					GVAR(loadAction) = -3333;
				};
			};
		};
	} else {
		if (GVAR(loadAction) != -3333) then {
			player removeAction GVAR(loadAction);
			GVAR(loadAction) = -3333;
		};
	};
	sleep 0.1;
};

// Remove "C" key down eventhandler
(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(drag_keyDownEHId)];

if (GVAR(carryAction) != -3333) then {
	player removeAction GVAR(carryAction);
	GVAR(carryAction) = -3333;
};

if (GVAR(loadAction) != -3333) then {
	player removeAction GVAR(loadAction);
	GVAR(loadAction) = -3333;
};

// Reset Stamina Boost while carrying wounded
[player, 0] call ace_sys_stamina_fnc_inc_mass;

false