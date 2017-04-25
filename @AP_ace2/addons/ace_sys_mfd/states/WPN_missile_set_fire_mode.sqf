//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_mfd\script_component.hpp"

TRACE_1("ENTER","");
private["_state", "_maxRows", "_fireMode", "_fireModeString"];

//_state = _this select 0;
PARAMS_1(_state);

[] call FUNC(clearAllText);
switch (GVAR(lastKeyPressed)) do {
	case "1": {
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN", "missile_fire_control"];
	};
	case "2": {
		(vehicle player) setVariable ["ace_sys_missileguidance_hellfire_mode", 0, false];
	
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN", "missile_fire_control"];
	};
	case "3": {
		(vehicle player) setVariable ["ace_sys_missileguidance_hellfire_mode",1, false];
	
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN", "missile_fire_control"];
	};
	case "4": {
		(vehicle player) setVariable ["ace_sys_missileguidance_hellfire_mode", 2, false];
		
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN", "missile_fire_control"];
	};
	case "5": {
		(vehicle player) setVariable ["ace_sys_missileguidance_hellfire_mode", 3, false];
		
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN", "missile_fire_control"];
	};
	default {
		_maxRows = ([] call FUNC(getMaxRows)) - 2;
		TRACE_1("", _maxRows);
		
		_fireMode = (vehicle player) getVariable QUOTE(ace_sys_missileguidance_hellfire_mode);
		switch (_fireMode) do {
			case 1: {_fireModeString = "LOAL - DIR"; };
			case 2: {_fireModeString = "LOAL - DIR LOW"; };
			case 3: {_fireModeString = "LOAL - DIR HI"; };
			default	{_fireModeString = "LOBL"; };
		};
	
		[1, " Current Fire Mode: "] call FUNC(setRowText);
		[2, format["     %1", _fireModeString] ] call FUNC(setRowText);
		[4, "2. LOBL"] call FUNC(setRowText);
		[5, "3. LOAL - DIR"] call FUNC(setRowText);
		[6, "4. LOAL - LOW"] call FUNC(setRowText);
		[7, "5. LOAL - HI"] call FUNC(setRowText);
		
		[(_maxRows),"Back .1"] call FUNC(setRowText_AlignRight);
	};
};

_state
