/* rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

PARAMS_1(_mine);
[_mine,false] call FUNC(set_ready);

_pos = getPosATL _mine;
_z = [_mine] call CBA_fnc_realHeight;

_trigger = createTrigger ["EmptyDetector", _pos];
_trigger setPosATL _pos;
_trigger setTriggerArea [__WIDTH, __LENGTH, 0, false];
_trigger setTriggerActivation ["ANY", "PRESENT", false];
_trigger setTriggerStatements [
	format["({ !(_x isKindOf 'ACE_Grenade_Geometry') && {!(_x isKindOf 'Bicycle')} && {(_x isKindOf 'LandVehicle' || {_x isKindOf 'Air'})} && {abs((getposatl _x select 2)- %1)<0.4} } count thisList) > 0", _z],	
	"[thisTrigger,thisList] spawn ace_sys_explosives_fnc_detonate_MINE", ""
];

[_mine,_trigger] call FUNC(store_trigger);
[_mine,_trigger] call FUNC(store_mine);

#ifdef DEBUG_MODE_FULL
	_mine call FUNC(Debug_Trigger);
#endif
