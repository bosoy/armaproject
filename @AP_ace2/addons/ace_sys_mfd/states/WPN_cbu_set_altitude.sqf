//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_mfd\script_component.hpp"

TRACE_1("ENTER","");
private["_maxRows", "_currentAlt"];

//_state = _this select 0;
PARAMS_1(_state);

[] call FUNC(clearAllText);
switch (GVAR(lastKeyPressed)) do {
	case "1": {
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN", "missile_fire_control"];
	};
	case "2": {
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN", "missile_fire_control"];
	};
	default {
		_currentAlt = (vehicle player) getVariable QUOTE(ace_sys_clusterbombs_burst_altitude);
		
		if (!isNil QGVAR(lastKeyPressed)) then {
			// do our key-presses for up/down here
			if(GVAR(lastKeyPressed) == "7") then {
				_currentAlt = _currentAlt + 10;
				(vehicle player) setVariable [QUOTE(ace_sys_clusterbombs_burst_altitude), _currentAlt, false];
			} else {
				if(GVAR(lastKeyPressed) == "4") then {
					_currentAlt = _currentAlt - 10;
					(vehicle player) setVariable [QUOTE(ace_sys_clusterbombs_burst_altitude), _currentAlt, false];
				};
			};
		};
		
		_maxRows = ([] call FUNC(getMaxRows)) - 2;
		TRACE_1("", _maxRows);
		[1, "Cluster Burst Altitude"] call FUNC(setRowText);
		[2, format["       %1m", _currentAlt]] call FUNC(setRowText);
		[(_maxRows-3), "+ 10m .7"] call FUNC(setRowText_AlignRight);
		[(_maxRows-2), "- 10m .4"] call FUNC(setRowText_AlignRight);
		//[(_maxRows-1), "Enter Code .2"] call FUNC(setRowText_AlignRight);
		[(_maxRows),"Back .1"] call FUNC(setRowText_AlignRight);
	};
};

_state
