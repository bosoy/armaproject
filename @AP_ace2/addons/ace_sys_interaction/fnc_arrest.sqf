/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_receiver,_type);

if !(alive _receiver) exitWith {};

_haskeycuffsleft = player getVariable [QGVAR(keycuffsleft),5];
_haskeycuffsleft = _haskeycuffsleft - 1;
player setVariable [QGVAR(keycuffsleft),_haskeycuffsleft];
if (_haskeycuffsleft <= 0 && {"ACE_KeyCuffs" in (weapons player)}) then {
	player removeWeapon "ACE_KeyCuffs";
};

if (_type) then {
	[QGVAR(cuff), _receiver] call ACE_fnc_receiverOnlyEvent;
} else {
	[QGVAR(uncuff), _receiver] call ACE_fnc_receiverOnlyEvent;
};