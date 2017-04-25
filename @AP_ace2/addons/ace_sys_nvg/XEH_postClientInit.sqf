//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

if (currentVisionMode player == 1 && {GVAR(sensitivity) != __INIT_APERTURE}) then { setAperture GVAR(sensitivity) };

// Loop check visionMode player and play events based on changes
[] spawn {
	private ["_oldVisionMode", "_currentVisionMode","_changedVD","_range_limit"];
	_oldVisionMode = 0;
	_changedVD = false;
	while {true} do {
		_currentVisionMode = currentVisionmode player;
		_range_limit = player getVariable [QGVAR(vddd),-1];
		if(isNil "_range_limit")then{_range_limit = -1;};
		_changedVD = (_range_limit > 0 && {viewDistance > _range_limit});
		TRACE_1("CHANGE DETECTED",_changedVD);
		if (_currentVisionMode != _oldVisionMode || {_changedVD}) then
		{
			// Generic event, for whatever purposes
			TRACE_2("Player Vision Change event", _currentVisionMode, _oldVisionMode);
			["ace_pvm", [_currentVisionMode, _oldVisionMode]] call CBA_fnc_localEvent;

			// Specific events
			switch _oldVisionMode do {
				case 1: {
					TRACE_2("NVG OFF event", _currentVisionMode, _oldVisionMode);
					["ace_nvg_off", [_currentVisionMode, _oldVisionMode]] call CBA_fnc_localEvent;
				};
				case 2: {
					TRACE_2("TI OFF event", _currentVisionMode, _oldVisionMode);
					["ace_ti_off", [_currentVisionMode, _oldVisionMode]] call CBA_fnc_localEvent;
				};
			};
			switch _currentVisionMode do {
				case 1: {
					TRACE_2("NVG ON event", _currentVisionMode, _oldVisionMode);
					["ace_nvg_on", [_currentVisionMode, _oldVisionMode]] call CBA_fnc_localEvent;
				};
				case 2: {
					TRACE_2("TI ON event", _currentVisionMode, _oldVisionMode);
					["ace_ti_on", [_currentVisionMode, _oldVisionMode]] call CBA_fnc_localEvent;
				};
			};
			_oldVisionMode = _currentVisionMode;
		};
		sleep 0.33;
	};
};

