// Bouncing Betty arming

#include "\x\ace\addons\sys_explosives\script_component.hpp"

_mine = _this;

[_mine,false] call FUNC(set_ready);

_z = [_mine] call CBA_fnc_realHeight;

// 5 seconds arming time, for gameplay reasons. M16 is armed without delay normally !!
sleep 5;

_trigger = createTrigger ["EmptyDetector", (position _mine)];
_trigger setpos (position _mine);
_trigger setTriggerArea [__WIDTHPMN, __LENGTHPMN, 0, false];
_trigger setTriggerActivation ["ANY", "PRESENT", false];
_trigger setTriggerStatements [
	format["({ _x isKindOf 'Land' && {abs(([_x] call CBA_fnc_realHeight) - %1)<0.4} } count thisList) > 0", _z],
	"[thisTrigger,thisList] spawn ace_sys_explosives_fnc_detonate_PMN", ""
];
[_mine,_trigger] call FUNC(store_trigger);
[_mine,_trigger] call FUNC(store_mine);

#ifdef DEBUG_MODE_FULL
	_mine call FUNC(Debug_Trigger);
#endif
