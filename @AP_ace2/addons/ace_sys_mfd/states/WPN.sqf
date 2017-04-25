//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_mfd\script_component.hpp"

//_state = _this select 0;
PARAMS_1(_state);

switch(GVAR(lastKeyPressed)) do {
	case "1": {
		LOG("changing state: ammunition_status");
		_state = ["WPN", "ammunition_status"];
		GVAR(lastKeyPressed) = "-1";
	};
	case "2": {
		LOG("changing state: missile_fire_control");
		_state = ["WPN", "missile_fire_control"];
		GVAR(lastKeyPressed) = "-1";
	};
	/*case "3": {
		LOG("changing state: fire_control_system");
		_state = ["WPN", "fire_control_system"];
		GVAR(lastKeyPressed) = "-1";
	};*/
	/*
	case "3": {
		LOG("changing state: laser_designation_control");
		_state = ["WPN", "laser_designation_control"];
		GVAR(lastKeyPressed) = "-1";
	};*/
	default {
		[4, "1. Ammunition Status"] call FUNC(setRowText);
		[6, "2. Fire Control System"] call FUNC(setRowText);
		//[8, "3. Laser Designation"] call FUNC(setRowText);
		//[8, "3. Fire Control System"] call FUNC(setRowText);
	};
};

TRACE_1("", _state);
_state
