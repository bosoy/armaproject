//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_mfd\script_component.hpp"

TRACE_1("Enter","");
private["_isLaserOn", "_isLaserDisabled"];

PARAMS_1(_state);

_isLaserOn = (vehicle player) getVariable QUOTE(ace_sys_missileguidance_laser_designation);
_isLaserDisabled = (vehicle player) getVariable QUOTE(ace_sys_missileguidance_laser_off);

[] call FUNC(clearAllText);
switch (GVAR(lastKeyPressed)) do {
	case "1": {		// back
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN"];
	};
	case "2": {		// toggle
		// turn on this setVariable ['ace_sys_missileguidance_laser_designation',true]; [this, currentWeapon this, true] spawn ace_sys_missileguidance_fnc_opt_laserloop
		GVAR(lastKeyPressed) = "-1";
		_state = ["WPN"];
	};
	default {};
};

_state
