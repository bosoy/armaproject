//#define DEBUG_MODE_FULL
#include "script_component.hpp"

_velFnc = {
	sqrt((_this select 0)^2 + (_this select 1)^2 + (_this select 2)^2)
};

_gun = _this select 0;
_shell = _this select 6;

_heatIndex = _gun getVariable [QGVAR(heatIndex), 0];
_heatTime = _gun getVariable [QGVAR(heatTime), time - 10000];
_heatLossPerSecond = 0.0003;
_heatLoss = (time - _heatTime) * _heatLossPerSecond;
_heatIndex = (_heatIndex - _heatLoss) max 0;
_heatIndex = (_heatIndex + random 0.007) min 0.5;

_gun setVariable [QGVAR(heatIndex), _heatIndex, true];
_gun setVariable [QGVAR(heatTime), time, true];

_shellVelocity = velocity _shell;
_totalVelocity = _shellVelocity call _velFnc;

_percentage = 1;
_percentage = _percentage + (_heatIndex*(random 0.02));

_powderRange = (random 0.1)/100;

_dir = round (random 1);

if (_dir == 0) then {
	_dir = -1;
};

_percentage = _percentage + (_powderRange*_dir);
_newVelVec = [_shellVelocity, _percentage] call ACE_fnc_vectorMultiply;
_newVelTotal = _newVelVec call _velFnc;

_shell setVelocity _newVelVec;

GVAR(wx) = 0;
GVAR(wy) = 0;
_fnc = {
	_shell = (_this select 0) select 0;
	if (alive _shell) then {
		_coef = (_this select 0) select 1;
		_vel = velocity _shell;
		_wind = ACE_wind;
		_x = (_wind select 0) * _coef * accTime;
		GVAR(wx) = GVAR(wx) + _x;
		_y = (_wind select 1) * _coef * accTime;
		GVAR(wy) = GVAR(wy) + _y;
		_newVel = [
					(_vel select 0) + _x,
					(_vel select 1) + _y,
					(_vel select 2)
				];
		_shell setVelocity _newVel;
		_shell setVectorDir _newVel;
	} else {
		TRACE_2("",GVAR(wx),GVAR(wy));
		[_this select 1] call cba_fnc_removePerFrameHandler;
	};
};
_coef = 0.25;
_time = 0.1;

//[_fnc, _time, [_shell,_coef*_time]] call CBA_fnc_addPerFrameHandler;
_windVec = "Not defined";
TRACE_4("",_percentage,_totalVelocity,_newVelTotal,_windVec);