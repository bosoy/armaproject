/* ace_sys_explosives | Pipebomb Arming | (c) 2011 by rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

private ["_mine", "_z", "_c", "_timer", "_time"];

_mine = _this;
_c = count GVAR(items);
PUSH(GVAR(items),_mine);

_timer = _mine getVariable [QGVAR(timer),-1];
if (_timer < 0) exitWith {};

_z = [_mine] call CBA_fnc_realHeight;

_time = time;
// Arm
[_mine,false] call FUNC(set_ready);
while { time < (_time + _timer) && {alive _mine} } do {
	sleep 1;
	TRACE_3("",time,_time,(_time + _timer));
};
// Boom
[GVAR(items) select _c] spawn FUNC(detonate_SATCHEL);
