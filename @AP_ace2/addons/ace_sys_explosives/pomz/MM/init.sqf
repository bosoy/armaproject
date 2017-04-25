/* rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

PARAMS_1(_mine);
[_mine,false] call FUNC(set_ready);

_dir = _mine getVariable [QUOTE(direction),(direction _mine)];
_lmax = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(tripwire_length));
_l = _mine getVariable [QUOTE(length),_lmax];

_pos = getPos _mine;
_z = [_mine] call CBA_fnc_realHeight;
_real_pos = [_pos select 0, _pos select 1, _z];
_x1 = _real_pos select 0;
_x2 = _x1 + ((sin _dir)*(_l min _lmax));
_y1 = _real_pos select 1;
_y2 = _y1 + ((cos _dir)*(_l min _lmax));
_midpoint = [((_x1 + _x2) / 2), ((_y1 + _y2) / 2), _z];
_l = (_l min _lmax) * 0.5;

_stake = "ACE_Stake" createVehicle [_x2,_y2,0]; _stake setVariable ["mine",_mine,true];
_stake setPos [_x2,_y2,0];

_trigger = createTrigger ["EmptyDetector", _midpoint];
_trigger setTriggerArea [__WIDTH_TRIPWIRE, _l, _dir, true];
_trigger setTriggerActivation ["ANY", "PRESENT", false];
_trigger setTriggerStatements [
	format["({ _x isKindOf 'Land' && {abs((getposatl _x select 2) - %1)<0.4} } count thisList) > 0", _z],
	"[thisTrigger,thisList] spawn ace_sys_explosives_fnc_detonate_POMZ", ""
];

[_mine,_trigger] call FUNC(store_trigger);
[_mine,_trigger] call FUNC(store_mine);

#ifdef DEBUG_MODE_FULL
	_mine call FUNC(Debug_Trigger);
#endif
