//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// Disabled for now
//if (true) exitWith { closeDialog 0; };


private ["_MG","_unit","_actor","_pitch"];

if (count _this == 1) then {
	_MG = ACE_MG;
	_unit = player;
	if (!dialog) then { ACE_MG = nil };
	_actor = player;
	_pitch = _this select 0;
} else {
	_unit  = _this select 0;
	_actor = _this select 1;
	_MG	= nearestObject [_unit, 'StaticWeapon'];
	_pitch = (_this select 3) select 0;
};
if (_actor != _unit) exitWith { closeDialog 0; };
if (count crew _MG > 0) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};

if (_MG getVariable QGVAR(busy)) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};

if !(_unit getVariable [QGVAR(busy), false]) then {
	[_MG,true] call FUNC(setbusy);
	_unit setVariable [QGVAR(busy), true];
	_unit playMove "AmovPknlMstpSrasWrflDnon_AinvPknlMstpSlayWrflDnon";
	[_MG,_unit,_pitch] spawn {
		PARAMS_3(_MG,_unit,_pitch);
		_cur_pitch = [_MG] call FUNC(getPitch);
		TRACE_1("CSW menu",_cur_pitch);
		_new_pitch = _cur_pitch + _pitch;
		TRACE_1("CSW menu",_new_pitch);

		_allowed = true;
		switch (_pitch) do {
			case -2: {
				if (_new_pitch < -10) then { _allowed = false; };
			};
			case 2: {
				if (_new_pitch > 10) then { _allowed = false; };
			};
		};
		
		TRACE_1("CSW menu",_allowed);
		if (_allowed) then {
			sleep 2;
			[_MG,_pitch] call FUNC(setPitch);
			// Dragging resets setvectorUp, sys_cargo resets setvectorup // TODO: Check vectorup, store on veh, compare on interact and reset if necessary
		} else {
			[localize "STR_ACE_CREW_ERR_TOOSTEEP",[1,0,0,1],true,0] spawn ace_fnc_visual;
		};
		_unit setVariable [QGVAR(busy), false];
		[_MG,false] call FUNC(setbusy);
		
	};
};
