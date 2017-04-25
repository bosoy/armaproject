#include "script_component.hpp"
private ["_c","_var","_i","_s","_type"];
_c = {isPlayer _x} count (crew (_this select 0));

if (_c > 0) then {
	_var = _this select 1;
	_type = _this select 2;
	if(_var == 0) then {_s = "ACE_TankPenetration"} else
	{
		if (_type == 0) then //dir impact
		{
			_i = ["1","2","3"] call ACE_fnc_selectrandom;
			_s = "ace_penetration_mediumcal_" + _i;
		} else {
			_s = ""; //no sound for low-powered explosions so far
		};
	};
	if (_s == "") exitwith {};
	if (_c == 1 && {player in _this}) then {
		playsound _s;
	} else {
		[QGVAR(handle_playsound), [_this select 0,_s]] call CBA_fnc_globalEvent;
	};
};
