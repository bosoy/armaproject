// set damage to individual soldiers, depending on distance to blast
#include "script_component.hpp"
#define DEBUG_MODE_FULL

PARAMS_3(_unit,_distance,_blastrange);
private ["_d","_t","_u","_du"];

if (isNull _unit) exitwith {};
if !(alive _unit) exitwith {};
if !(_unit isKindOf "Man") exitwith {};

if (local _unit) then {
	_du = damage _unit;
	_d = _du + (0.5+random 1)*((1 - _distance/(_blastrange max 0.1)) max 0);
	if (_d < 0.95) then {
		_t = 10+random 300;
		_u = _d >= 0.55;
		if (vehicle _unit != _unit && {_d > 0.55} && {!isplayer _unit}) then {_unit setskill 0.01; _d = 0.4}; //unc for AI not worky properly
		[_unit,_d,_u,_t] call ace_w_setunitdam;
		TRACE_2("Injured",_unit,([_d,_u,_t]));
	} else {
		[_unit,1,false,1] call ace_w_setunitdam;
		TRACE_1("Killed",_unit);
	};
};
