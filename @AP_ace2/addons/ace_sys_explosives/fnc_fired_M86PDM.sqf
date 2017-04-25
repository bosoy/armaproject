/* ace_sys_explosives (.pbo)| M86 PDM Munition | (c) 2008, 2009 by rocko */
#include "script_component.hpp"

_pos = _this;

_mine = "ACE_M86PDM_Object" createVehicle _pos;
_mine setPos _pos;
_z = [_mine] call CBA_fnc_realHeight;

_trigger = createTrigger ["EmptyDetector", _pos];
_trigger setTriggerArea [(5 + (random 1.096)), (5 + (random 1.096)), (random 360), false];
_trigger setTriggerActivation ["ANY", "PRESENT", false];
_trigger setTriggerStatements [
	format["({ !(_x isKindOf 'ACE_Grenade_Geometry') && {!(_x isKindOf 'ACE_M86PDM_Object')} && {(_x isKindOf 'Land')} && {abs((getposatl _x select 2)- %1)<0.4} } count thisList) > 0", _z],	
	"[thisTrigger,thisList] spawn ace_sys_explosives_fnc_detonate_M86",
	""
];

[_mine,_trigger] call FUNC(store_trigger);
[_mine,_trigger] call FUNC(store_mine);

#ifdef DEBUG_MODE_FULL
	_mine call FUNC(Debug_Trigger);
#endif
