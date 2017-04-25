//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);
private ["_target", "_ruck_cont"];

_target = GVAR(Ruck_Target);
if (isNil "_target") exitWith {};
GVAR(Ruck_Target) = nil;
_lock = _target getVariable ["ACE_Ruck_Lock","Team"];

TRACE_2("",_target,_lock);

if ( _lock == name _unit ) then {
    _ruck_cont = call FUNC(TmpGearUnload);
    if ( !isNil "_ruck_cont" ) then {
        [QGVAR(RuckNetUnload), [_target, _ruck_cont]] call ACE_fnc_receiverOnlyEvent;
    };
};
