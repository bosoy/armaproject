// #define DEBUG_MODE_FULL
#include "script_component.hpp"
// Laser Target Initializer.

private ["_defaultCode", "_temp"];
// player sideChat format["hi!"];
_defaultCode = 1001;
PARAMS_1(_laserTarget);

// Spawn laserTarget custom position announce

// started at 0.5 // otherwise 0.33 ?
// TODO: Perhaps no need to update so often for AI (e.g deddy)
#define __TRACKINTERVAL 0.2

if (local _laserTarget) then {
	ace_laser_object = _laserTarget;
	_laserTarget setVariable ["ace_pos", getPosASL _laserTarget, true];
	_laserTarget spawn {
		if (isDedicated) then {
			while {alive _this} do {
				_pos = getPosASL _this;

				// TODO: Allow for minor deviations?
				if (str(_pos) != str(_this getVariable "ace_pos")) then {
					_this setVariable ["ace_pos", _pos, true];
				};


				sleep __TRACKINTERVAL;
			};
		} else {
			_handle = [
				{ /* run code */
					_pos = getPosASL _laserTarget;
					// TRACE_1("Run",_pos);

					// TODO: Allow for minor deviations "DeadZone"? 
					if (str(_pos) != str(_laserTarget getVariable "ace_pos")) then {
						TRACE_1("Set",_pos);
						_laserTarget setVariable ["ace_pos", _pos, true];
					};
				},
				[_this], /* parameters */
				__TRACKINTERVAL, // delay
				{ /* init code */
					_laserTarget = _this select 0;
				},
				{ /* exit code */
				},
				{ /* Run condition - default true */
					true
				},
				{isNull _laserTarget}, /* exit condition */
				[ /* Private variables, available throughout all states and conditions */
					"_laserTarget"
				]
			] call cba_common_fnc_addPerFrameHandlerLogic;

			_handle;
		};
	};
};

#ifdef DEBUG_MODE_FULL
	if (isNil QGVAR(marker_debug)) then { GVAR(marker_debug) = 0 };
	[_laserTarget, format["ace_debug_mrk_%1", GVAR(marker_debug)], [_laserTarget] call FUNC(getPosASL)] spawn {
		PARAMS_3(_laserTarget,_marker,_pos);
		_marker = createMarkerLocal [_marker, _pos];
		_marker setMarkerShapeLocal "ICON";
		_marker setMarkerTypeLocal "DOT";
		_marker setMarkerTextLocal format["%1", _laserTarget];
		_lastTime = time;
		while {alive _laserTarget} do {
			_pos = ([_laserTarget] call FUNC(getPosASL));
			if ((_pos select 0) != 0 && {(_pos select 1) != 0} && {(_pos select 2) != 0}) then {
				_marker setMarkerPosLocal _pos;
				// if (time > _lastTime + 1) then { TRACE_5("",_laserTarget,local _laserTarget,getPos _laserTarget,[_laserTarget] call FUNC(getPosASL),getPosASL _laserTarget); _lastTime = time; };
				sleep 0.001;
			};
		};
		_marker setMarkerColorLocal "ColorWhite";
		sleep 10;
		deleteMarkerLocal _marker;
	};
	ADD(GVAR(marker_debug),1);
#endif

if (isNil "ACE_LASERTARGET_ARRAY_INITIALIZED") then {
        ACE_LASERTARGET_ARRAY_INITIALIZED = true;
        ACE_LASERTARGET_ARRAY = [];
};

// make sure default code is localized on all clients
_laserTarget setVariable ["ACE_LASERTARGET_CODE", _defaultCode, false];

// Add target and ditch null targets.
_temp = +ACE_LASERTARGET_ARRAY;
ACE_LASERTARGET_ARRAY = [_laserTarget];
{
    if (!(isNull _x)) then {
		ACE_LASERTARGET_ARRAY set [count ACE_LASERTARGET_ARRAY, _x];
	};
} forEach _temp;
