// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_perframe.sqf"
#include "x_setup.sqf"

GVAR(perframe_store) = GVAR(HeliHEmpty) createVehicleLocal [0,0,0];
GVAR(perframe_array) = [];

FUNC(addPerFrame) = {
	private ["_name", "_code", "_time", "_ar"];
	PARAMS_3(_name,_code,_time); //_time = 0 = every frame
	__TRACE_3("addPerFrame","_name","_code","_time");
	_name = toLower _name;
	_ar = GV2(GVAR(perframe_store),_name);
	if (isNil "_ar") then {_ar = []}; // workaround for getVariable default bug
	_ar set [0, _code];
	_ar set [1, _time];
	_ar set [2, 0];
	GVAR(perframe_store) setVariable [_name, _ar];
	GVAR(perframe_array) set [count GVAR(perframe_array), _name];
};

FUNC(removePerFrame) = {
	private "_name";
	PARAMS_1(_name);
	_name = toLower _name;
	GVAR(perframe_store) setVariable [_name, nil];
	GVAR(perframe_array) = GVAR(perframe_array) - [_name];
};

FUNC(perFrame) = {
	private ["_ar", "_wf", "_nt"];
	if (count GVAR(perframe_array) > 0) then {
		{
			_ar = GV2(GVAR(perframe_store),_x);
			if (isNil "_ar") then {_ar = []};
			if (count _ar > 0) then {
				_wf = _ar select 1;
				if (_wf == 0) then {
					call (_ar select 0);
				} else {
					_nt = _ar select 2;
					if (time >= _nt) then {
						call (_ar select 0);
						_ar set [2, time + (_ar select 1)];
					};
				};
			};
		} forEach GVAR(perframe_array);
	};
};
173194 cutRsc [QGVAR(FrameHandlerRsc),"PLAIN"];
diag_log [diag_frameno, diag_ticktime, time, "Dom per frame handler initialized..."];
