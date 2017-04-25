#include "script_component.hpp"

private ["_MG","_unit","_actor","_degree"];

if (count _this == 1) then {
	_MG = ACE_MG;
	_unit = player;
	if (!dialog) then { ACE_MG = nil };
	_actor = player;
	_degree = _this select 0;
} else {
	_unit  = _this select 0;
	_actor = _this select 1;
	_MG	= nearestObject [_unit, 'StaticWeapon'];
	_degree = (_this select 3) select 0;
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
	[_MG,_unit,_degree] spawn {
		PARAMS_3(_MG,_unit,_degree);
		sleep 2;
		_MG setDir (getDir _MG + _degree);
		_unit setVariable [QGVAR(busy), false];
		[_MG,false] call FUNC(setbusy);
	};
};
