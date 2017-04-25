#include "\x\ace\addons\sys_explosives\script_component.hpp"

if (GVAR(tripwire_lock)) exitWith {};
waitUntil { !GVAR(tripwire_lock) };
GVAR(tripwire_lock) = true;

_mine = _this;

_z = [_mine] call CBA_fnc_realHeight;
_pos = position _mine;
GVAR(tripwire_point_a) = [_pos select 0, _pos select 1, _z];

_A_ID = player addAction [localize "STR_ACE_EXPL_CTRIPE", (PATH + "end_tripwire.sqf"),[_mine],-1,false,true,"","_target == player"];
GVAR(waiting_for_tripwire) = true;
waitUntil { !GVAR(waiting_for_tripwire) || {!alive player} };
if !(alive player) exitWith {
	GVAR(tripwire_lock) = false;
	player removeAction _A_ID;
};
player removeAction _A_ID;

[_mine,false] call FUNC(set_ready);

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

sleep 5;

_trigger = createTrigger ["EmptyDetector", _midpoint];
_trigger setpos _midpoint;
_trigger setTriggerArea [__WIDTH_TRIPWIRE, _distance, _angle, true];
_trigger setTriggerActivation ["ANY", "PRESENT", false];
_trigger setTriggerStatements [
	format["({ _x isKindOf 'Land' && {abs((getposatl _x select 2) - %1)<0.4} } count thisList) > 0", _z],
	"['ace_sys_explosives_trip', [thisTrigger]] call CBA_fnc_globalEvent",
	""
];

[_mine,_trigger] call FUNC(store_trigger);
[_mine,_trigger] call FUNC(store_mine);

#ifdef DEBUG_MODE_FULL
	_mine call FUNC(Debug_Trigger);
#endif

GVAR(tripwire_lock) = false;
