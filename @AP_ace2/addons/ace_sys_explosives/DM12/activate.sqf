// DM12 arming

#include "\x\ace\addons\sys_explosives\script_component.hpp"

PARAMS_1(_mine);

[_mine,false] call FUNC(set_ready);

_z = [_mine] call CBA_fnc_realHeight;
_x1 = (_mine getVariable QGVAR(tw_start)) select 0;
_x2 = (_mine getVariable QGVAR(tw_end)) select 0;
_y1 = (_mine getVariable QGVAR(tw_start)) select 1;
_y2 = (_mine getVariable QGVAR(tw_end)) select 1;
_pi = 3.14159265;

_angle = (sin(_x2-_x1)*cos(_y2)) atan2 (cos(_y1)*sin(_y2)-sin(_y1)*cos(_y2)*cos(_x2-_x1));
_midpoint = [((_x1 + _x2) / 2), ((_y1 + _y2) / 2), _z];
_distance = sqrt((_x2 - _x1) ^ 2 + (_y2 - _y1) ^ 2);
_distance = _distance * 0.5;
if (_angle < 0) then { _angle = 360 + _angle; };

sleep 5;

_trigger = createTrigger ["EmptyDetector", _midpoint];
_trigger setTriggerArea [__WIDTH_TRIPWIRE, _distance, _angle, true];
_trigger setTriggerActivation ["ANY", "PRESENT", false];
_trigger setTriggerStatements [
	format["({ _x isKindOf 'LandVehicle' && {abs((getposatl _x select 2) - %1)<0.4} } count thisList) > 0", _z],
	"[thisTrigger,thisList] spawn ace_sys_explosives_fnc_detonate_DM12", ""
];

[_mine,_trigger] call FUNC(store_trigger);
[_mine,_trigger] call FUNC(store_mine);

_mine setVariable [QGVAR(arm),true,true];
_mine setVariable [QGVAR(active),true,true];
