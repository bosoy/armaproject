//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_mfd\script_component.hpp"

TRACE_1("ENTER","");
private["_maxRows", "_currentCode"];

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
		_currentCode = (vehicle player) getVariable "ACE_CURRENT_LASERTARGET_CODE";
		
		if (!isNil QGVAR(lastKeyPressed)) then {
			// do our key-presses for up/down here
			if(GVAR(lastKeyPressed) == "7") then {
				if(_currentCode == 1999) then {
					_currentCode = 1001;
				} else {
					_currentCode = _currentCode + 1;
				};
				(vehicle player) setVariable ["ACE_CURRENT_LASERTARGET_CODE", _currentCode, false];
			} else {
				if(GVAR(lastKeyPressed) == "4") then {
					if(_currentCode == 1001) then {
						_currentCode = 1999;
					} else {
						_currentCode = _currentCode - 1;
					};
					(vehicle player) setVariable ["ACE_CURRENT_LASERTARGET_CODE", _currentCode, false];
				};
			};
		};
		
		_maxRows = ([] call FUNC(getMaxRows)) - 2;
		TRACE_1("", _maxRows);
		[1, "   Seek Laser Code"] call FUNC(setRowText);
		[2, format["         %1", _currentCode]] call FUNC(setRowText);
		[(_maxRows-3), "Up .7"] call FUNC(setRowText_AlignRight);
		[(_maxRows-2), "Down .4"] call FUNC(setRowText_AlignRight);
		//[(_maxRows-1), "Enter Code .2"] call FUNC(setRowText_AlignRight);
		[(_maxRows),"Back .1"] call FUNC(setRowText_AlignRight);
	};
};

_state
