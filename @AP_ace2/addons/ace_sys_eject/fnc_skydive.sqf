// #define DEBUG_MODE_FULL
#include "script_component.hpp"

/*
This script controls the skydiving player until they either a)open a parachute or b)die

TODO:
update this script to account for player/avatar switching (even though no one should be dumb enough to want to do that)
Right now, if you switch players then the script will continue to run and you can control the AI skydiver as if through remote control
*/

PARAMS_1(_jumper);
_jumper setVariable [QGVAR(skydiving),true];

private "_curheight";

_weight = _jumper call ACE_SYS_RUCK_FNC_GEARWEIGHT; // for MC 5 max 163kg

ACEChute_Steer = "CENTER";
ACEChute_Pitch = "CENTER";

_Hdg = getDir _jumper;
_DsdHdg = _Hdg;
_Pitch = 0;
_NewPitch = 0;
_Drop = -55 - (_weight / 1.65);
_StartVel = velocity (vehicle _jumper);
_vX = _StartVel select 0;
_DsdvX = 0;
_vY = _StartVel select 1;
_DsdvY = 0;
_vZ = _StartVel select 2;
_DsdvZ = 0;
_Fwd = 0;
_DsdFwd = 0;

// SCRIPT LOOPS UNTIL SKYDIVER IS IN A PARACHUTE OR DEAD

_dT = 0.01;

_curheight = {
	private "_p";
	_p = getPosATL _this;
	if (surfaceIsWater _p) then {_p = getPosASL _this};
	_p select 2 > 5
};

while {(vehicle _jumper == _jumper) && {(alive _jumper)} && {(_jumper call _curheight)}} do {
	if (_jumper == player) then {
		switch (toUpper ACEChute_Steer) do {
			case "LEFT": {_DsdHdg = _DsdHdg - 100 * _dT};
			case "RIGHT": {_DsdHdg = _DsdHdg + 100 * _dT};
		};
	};

	_Hdg = _Hdg + (1 min (0.75*_dT))*(_DsdHdg - _Hdg);
	
	_HdgX = sin(_Hdg); // WHEN you are heading 0, this is MINIMUM
	_HdgY = cos(_Hdg); // when you are heading 0, this is MAXIMUM

	switch (toUpper ACEChute_Pitch) do {
		case "FORWARD": {
			if (_Pitch < 0.95) then {
				_Pitch = (_Pitch + 0.5*_dT) min 0.95;
			};
		};
		case "BACK": {
			if (_Pitch > -0.12) then {
				_Pitch = (_Pitch - 0.5 * _dT) max -0.12;
			};
		};
	};

	_NewPitch = _NewPitch + (1 min (2.5*_dT))*(-_Pitch - _NewPitch); GVAR(newPitch) = _NewPitch;

	_DsdVZ = _Drop - 20*sin((180*_NewPitch)-90);
	if (_DsdVZ < _VZ) then {
		_VZ = _VZ + (1 min (0.2*_dT))*(_DsdVZ - _VZ); // if you're diving, gravity will speed you up slowly
	} else {
		_VZ = _VZ + (1 min (0.4*_dT))*(_DsdVZ - _VZ); // if you're braking, air will slow you down quickly
	};

	_DsdFwd = -32 * cos((180 * _NewPitch) - 90);
	_Fwd = _Fwd + (1 min (0.5*_dT))*(_DsdFwd - _Fwd);

	_vX = _vX + (1 min (0.5*_dT))*(_HdgX * _Fwd - _vX);
	_vY = _vY + (1 min (0.5*_dT))*(_HdgY * _Fwd - _vY);

	_jumper setVelocity [_vX, _vY, _VZ];
	_jumper setDir _Hdg;
	_jumper SetVectorUp [_HdgX * (sin(-90 * _NewPitch)), _HdgY * (sin(-90 * _NewPitch)),cos(-90 * _NewPitch)];

	_t1 = time;
	sleep 0.01;
	_dT = time - _t1;
};

TRACE_1("Exiting Script",_jumper);
_jumper setVariable [QGVAR(skydiving),false];