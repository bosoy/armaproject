/* ace_fx_fnc_dizzy

Faint

Parameters:
_unit - Needed to check against player unit
_duration - How long dizzyness is played
_rate - Rate of dizzynes, 1 = max, fast erratic movement, 0.1 slow

*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define MAX_RTSPEED 150
#define DELTA_T     0.025
#define SPIN_RAD    0.07
#define SPIN_STEP   90

PARAMS_3(_unit,_duration,_rate);
DEFAULT_PARAM(1,_duration,30);
DEFAULT_PARAM(2,_rate,0.1);

if (_duration < 1) exitWith {};

if !(isPlayer _unit) exitWith { TRACE_1("Not player",nil); };
if !(alive _unit) exitWith { TRACE_1("Not alive",nil); };
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith { TRACE_1("Uncon",nil); };

if (_rate > 1) then { _rate = 1; };
if (_duration > 30) then { _duration = 30; };

[_unit,_duration,_rate] spawn {
	PARAMS_3(_unit,_duration,_rate);

	private ["_end","_sign","_stun","_skl","_prev","_durationLeft"];
	_skl = skill _unit;
	_start = time;

	_prev = _unit getvariable QGVAR(dizzy);
	if (!isNil "_prev") then {
		private ["_a","_b","_c","_e","_f"];

		_a = _prev select 0;
		_b = _prev select 1;
		_c = _prev select 2;
		_c = _c*((_b-time)/(_b-_a));
		_skl = _prev select 3;
		_e = 1-abs(_rate-_c);
		_f = 1-((time-_a)/(_b-_a));

		if (_b > (_start + _duration) || {_e > _rate}) then {
			_f = _e*_f;
			_b = _b + (_duration*_f)-1;
			_duration = 0;
			_unit setVariable [QGVAR(dizzy),[_a,_b,_c,_skl]];
		} else {
			_f = if (_c < _rate) then {_f*_e} else {_f + _f*(1-_e)};
			_duration = _duration + (_b-time)*_f;
		};
	};

	if (_duration > 0) then {
		private["_vup","_vdir","_dir","_radius","_step","_s1","_s2"];

		_end = _start + _duration;
		_durationLeft = _duration;
		_stun = ((_durationLeft) / _duration) * _rate;
		_dir = 0;

		_s1 = if (random 1 > 0.5) then { 1 } else { -1 };
		_s2 = if (random 1 > 0.5) then { 1 } else { -1 };

		_unit setvariable [QGVAR(dizzy), [_start,_end,_rate,_skl]];

		while { _durationLeft > 0 && {alive _unit} } do {
			_unit setskill (_skl - (_skl*0.80*_stun));

			_radius = SPIN_RAD*_stun;
			_step = SPIN_STEP*_stun;
			_dir = _dir + _s1*(0.5*_step + random (0.5*_step));

			if (vehicle _unit == _unit) then {
				_cdir = getdir _unit;
				_vup = [_radius*sin (_dir+_cdir), _radius*cos (_dir+_cdir), sqrt(1-_radius^2)];
				_vdir = [sqrt(1-(0.5*_radius*sin (_dir+_s2*90))^2),0.5*_radius*sin (_dir+_s2*90)];
				_vdir = [(sin _cdir)*(_vdir select 0), (cos _cdir)*(_vdir select 0), _vdir select 1];
				if (cameraView != "EXTERNAL") then { // TODO: maaaaaybe move to cough directly instead of here
					_unit setVectorDirAndUp [_vdir, _vup];
				};
			};

			sleep DELTA_T;

			_prev = _unit getvariable QGVAR(dizzy);
			if (isnil "_prev") then {
				_end = 0;
			} else {
				_end = _prev select 1;
				_duration = _end - (_prev select 0);
				if ((_prev select 0) > _start) then { _end = 0; };
			};
			_durationLeft = _end-time;
			_stun = ((_durationLeft) / _duration) * _rate;
		};
		if (_end > 0) then {
			_unit setskill _skl;
			_unit setvariable [QGVAR(dizzy), nil];
		};
	};
};