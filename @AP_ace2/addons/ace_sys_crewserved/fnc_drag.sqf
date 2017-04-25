#include "script_component.hpp"

private["_unit","_action","_mg","_pos2","_dir","_modelPos","_drag_action"];

if (dialog) then { closeDialog 0; };

_unit = player;
_action = (_this select 3) select 0;
_mg = (_this select 3) select 1; // TODO: should be (_this select 0)

if (_action == "start") then {
	call (_this select 4);

	if (count (crew _mg) > 0) exitWith {};
	if (_mg call CBA_fnc_locked) exitWith {};
	if (_unit distance _mg > 2.5) exitWith { [localize "STR_ACE_CREW_ERR_NOWEP",[1,0,0,1],true,0] spawn ace_fnc_visual; };
	if (_mg getVariable QGVAR(busy)) exitWith {
		[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	};
	if ((_unit distance _mg) <= 2.5) then {
		[_mg,true] call FUNC(setbusy);
		_unit playActionNow "grabDrag";
		_pos2 = getPosATL _mg;
		_dir = getDir _mg;
		_modelPos = _unit worldToModel _pos2; //is ATL format
		_mg attachTo [_unit,[_modelPos select 0,_modelPos select 1, 0.8],""];
		_unit setVariable [QGVAR(dragging), true, false];
		_mg setDir (_dir - getDir _unit);
		_mg lock true;
		#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")
		_drag_action = _unit addAction[ACE_TEXT_RED((localize "STR_ACE_CREW_RELASE")),QPATHTO_F(fnc_drag),["stop",_mg],-100];
	};

	waitUntil { animationState _unit == "ACINPKNLMSTPSRASWRFLDNON" };

	while { _unit getVariable QGVAR(dragging) } do {
		sleep 0.5;

		if !(animationState _unit in ["acinpknlmstpsraswrfldnon","acinpknlmwlksraswrfldb"]) exitWith {
			_unit setVariable [QGVAR(dragging), false, false];
			_unit switchMove "ACINPKNLMSTPSRASWRFLDNON";
			["","",_drag_action,["stop",_mg]] spawn FUNC(drag);
		};
	};
};
if (_action == "stop") then {
	// Dragging in building??
	_bldg = [_unit,0.1] call ACE_fnc_inBuilding;
	if (_bldg) then {
		_mg = (_this select 3) select 1;
		_unit setVariable [QGVAR(dragged_pos_end), (getPosATL _mg), false];
		_mg lock false;
		_unit playAction "released";
		detach _mg;
		_posZ = ((player modelToWorld [0,0,0]) select 2) - 0.05;
		_pos_end = _unit getVariable QGVAR(dragged_pos_end);
		_mg setPosATL [_pos_end select 0, _pos_end select 1, _posZ];
		_unit setVariable [QGVAR(dragged_pos_end), nil, false];
		_unit removeaction (_this select 2);
		_unit setVariable [QGVAR(dragging), false, false];
		[_mg,false] call FUNC(setbusy);
	} else {
		_mg = (_this select 3) select 1;
		_unit setVariable [QGVAR(dragged_pos_end), getPosATL _mg, false];
		_mg lock false;
		_unit playAction "released";
		detach _mg;
		_pos_end = _unit getVariable QGVAR(dragged_pos_end);
		_mg setPosATL [_pos_end select 0, _pos_end select 1, (getPosATL _unit) select 2];
		_unit setVariable [QGVAR(dragged_pos_end), nil, false];
		_unit removeaction (_this select 2);
		_unit setVariable [QGVAR(dragging), false, false];
		[_mg,false] call FUNC(setbusy);
	};
};

false
