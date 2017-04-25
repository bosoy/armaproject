/* ace_sys_explosives | SLAM Arming | (c) 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

private ["_mine", "_z", "_pos", "_x1", "_x2", "_y1", "_y2", "_pi", "_angle", "_midpoint", "_distance", "_c", "_trigger", "_ace_dum"];

// This arms the SLAM. Before you can change detonation modes.

closeDialog 0;

_mine = GVAR(slam);

_attackmode = _mine getVariable QGVAR(attackmode);
if (isNil "_attackmode") exitWith {};

[_mine,false] call FUNC(set_ready);

_z = [_mine] call CBA_fnc_realHeight;

if (_attackmode == "TIMED") then {
	_mine animate ["flip",1];
	private ["_timer","_time"];
	#ifndef DEBUG_MODE_FULL
		_timer = (_mine getVariable QGVAR(timer)) * 60;
	#else
		_timer = 10;
	#endif
	_time = time;
	// Arm SLAM
	// Disable sight-in action
	while { alive _mine && {time < (_time + _timer)} } do {
		sleep 1;
		TRACE_3("",time,_time,(_time + _timer));
	};
	[_mine] spawn FUNC(detonate_M2_command);
};

if (_attackmode == "COMMAND") then {
	_mine animate ["flip",1];
	_mine animate ["cap",0];
	_mine spawn COMPILE_FILE2_SYS(PATH+"attach_clacker.sqf");
};

if (_attackmode == "SIDE") then {
	_mine animate ["flip",1];
	_mine animate ["pirs",1];
	sleep 5; // 5 seconds delay before SLAM is armed
	_pos = position _mine;
	GVAR(tripwire_point_a) = [_pos select 0, _pos select 1, _z];
	GVAR(tripwire_point_b) = [(_pos select 0) + ((sin direction _mine) * 20),(_pos select 1) + ((cos direction _mine) * 20),_z];
	_x1 = GVAR(tripwire_point_a) select 0;
	_x2 = GVAR(tripwire_point_b) select 0;
	_y1 = GVAR(tripwire_point_a) select 1;
	_y2 = GVAR(tripwire_point_b) select 1;
	_pi = 3.14159265;
	_angle = (sin(_x2-_x1)*cos(_y2)) atan2 (cos(_y1)*sin(_y2)-sin(_y1)*cos(_y2)*cos(_x2-_x1));
	_midpoint = [((_x1 + _x2) / 2), ((_y1 + _y2) / 2), _z];
	_distance = sqrt((_x2 - _x1) ^ 2 + (_y2 - _y1) ^ 2);
	_distance = _distance * 0.5;
	if (_angle < 0) then { _angle = 360 + _angle; };
	_trigger = createTrigger ["EmptyDetector", _midpoint];
	_trigger setpos _midpoint;
	_trigger setTriggerArea [__WIDTH_SLAM, _distance, _angle, true];
	_trigger setTriggerActivation ["ANY", "PRESENT", false];
	_trigger setTriggerStatements [
		format["({ _x isKindOf 'Land' && {abs(((getPos _x) select 2) - %1)<0.4} } count thisList) > 0", _z],
		"[thisTrigger,thisList] spawn ace_sys_explosives_fnc_detonate_M2_side", ""
	];
	[_mine,_trigger] call FUNC(store_trigger);
	[_mine,_trigger] call FUNC(store_mine);

	#ifdef DEBUG_MODE_FULL
		_mine call FUNC(Debug_Trigger);
	#endif	
	// Anti Tamper mode
};

if (_attackmode == "BOTTOM") then {
	sleep 5; // 5 seconds delay before SLAM is armed
	_trigger = createTrigger ["EmptyDetector", (position _mine)];
	_trigger setpos (position _mine);
	_trigger setTriggerArea [__WIDTH, __LENGTH, 0, true];
	_trigger setTriggerActivation ["ANY", "PRESENT", false];
	_trigger setTriggerStatements [
		format["({ _x isKindOf 'LandVehicle' && {abs(((getPos _x) select 2) - %1)<0.4} } count thisList) > 0", _z],
		"[thisTrigger,thisList] spawn ace_sys_explosives_fnc_detonate_M2_bottom", ""
	];
	[_mine,_trigger] call FUNC(store_trigger);
	[_mine,_trigger] call FUNC(store_mine);

	#ifdef DEBUG_MODE_FULL
		_mine call FUNC(Debug_Trigger);
	#endif	
	// Anti Tamper mode
};
