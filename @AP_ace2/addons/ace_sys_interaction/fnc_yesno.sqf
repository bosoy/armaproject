/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

PARAMS_1(_sender);

private["_ar","_receiver","_action","_answer"];

_ar = _this select 3;
_receiver = _ar select 0;
_action = _ar select 1;
_answer = _ar select 2;

_sender removeAction GVAR(yes);
_sender removeAction GVAR(no);

GVAR(rec_has_answered) = "RESPONSE";

[QGVAR(confirmation), [_receiver, player, _answer, _action]] call ACE_fnc_receiverOnlyEvent;
// Unset busy state
_sender setVariable ["ace_sys_interaction_busy",false, true];
false