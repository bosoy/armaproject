#include "script_component.hpp"

PARAMS_1(_heli);

if (_heli getVariable QGVAR(alarming)) exitWith {};
_heli setVariable [QGVAR(alarming), true];

_handle = [
	{
		_timePrev = diag_tickTime;
		if ((!canMove _vehicle || {isPlayer driver _vehicle}) && {cameraOn == _vehicle}) then {
			if (cameraView in ["GUNNER","INTERNAL"]) then {
				playSound "ACE_EngineFailureAlarm_1";	// Inside - loud
			} else {
				playSound "ACE_EngineFailureAlarm_2";	// Outside - quiet
			};
		};
	},
	[_heli], /* parameters */
	0, // delay	// realtime delay instead - sfx
	{ /* init code */
		_vehicle = _this select 0;
		_timePrev = diag_tickTime - 1;
	},
	{ /* exit code */
		_vehicle setVariable [QGVAR(alarming),false];
	},
	{ /* Run condition - default true */
		_r = false;
		if (diag_tickTime - _timePrev > 1) then {_r = player in _vehicle};
		_r;
	},
	{!(alive _vehicle) || {((canMove _vehicle) && {(isEngineOn _vehicle)})} || {(((getPos _vehicle) select 2 < 1) && {(velocity _vehicle call ACE_fnc_magnitude < 1)})}}, /* exit condition */
	[ /* Private variables, available throughout all states and conditions */
		"_timePrev","_vehicle"
	]
] call cba_common_fnc_addPerFrameHandlerLogic;
