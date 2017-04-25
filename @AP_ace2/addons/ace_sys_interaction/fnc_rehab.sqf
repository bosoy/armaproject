/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

PARAMS_1(_receiver);

if (rating _receiver >= 0) exitWith {
	format["%1 needs no rehab", name _receiver] spawn ace_fnc_visual; // TODO: localize
};
if (rankId player <= rankId _receiver) exitWith {
	format["No rank to rehab %1", name _receiver] spawn ace_fnc_visual; // TODO: localize
};
if (leader _receiver != player && rankId player <= rankId _receiver) exitWith {
	format["You are not %1's leader", name _receiver] spawn ace_fnc_visual; // TODO: localize
};

[QGVAR(rehab), _receiver] call ACE_fnc_receiverOnlyEvent;

false
