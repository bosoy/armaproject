/* rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

_mine = _this select 0;
[_mine,false] call FUNC(set_ready);
[_mine] call FUNC(bury_mine); // Q&D blabla automate

_dir = 0;
_length = 0;

_pos = getPos _mine;
_z = [_mine] call CBA_fnc_realHeight;
_real_pos = [_pos select 0, _pos select 1, _z];
_x1 = _real_pos select 0;
_x2 = _x1 + ((sin _dir)*_length);
_y1 = _real_pos select 1;
_y2 = _y1 + ((cos _dir)*_length);
_midpoint = [((_x1 + _x2) / 2), ((_y1 + _y2) / 2), _z];

_trigger = createTrigger ["EmptyDetector", _midpoint];
_trigger setTriggerArea [__WIDTHPMN, __LENGTHPMN, 0, false];
_trigger setTriggerActivation ["ANY", "PRESENT", false];
_trigger setTriggerStatements [
	format["({ _x isKindOf 'Land' && {abs((getposatl _x select 2) - %1)<0.4} } count thisList) > 0", _z],
	"[thisTrigger,thisList] spawn ace_sys_explosives_fnc_detonate_PMN", ""
];

// Func to store trigger
[_mine,_trigger] call FUNC(store_trigger);
[_mine,_trigger] call FUNC(store_mine);
