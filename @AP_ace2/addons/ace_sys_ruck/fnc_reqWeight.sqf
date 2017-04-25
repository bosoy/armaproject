//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_def", "_oth"];
PARAMS_1(_unit);

/*
Request broadcasted weight when in the gear dialog of a non-local unit.
This is not common, only on _non_local_unit action ["GEAR",""];
For example, cycling unit gear as squad leader.
*/

_def = [_unit,0];
ISNILS(GVAR(wgttim_oth),_def);
_oth = GVAR(wgttim_oth);

if ( (_oth select 0) == _unit ) then {
    if ( time > (_oth select 1) ) then {
        [QGVAR(brcwgt), [_unit]] call ACE_fnc_receiverOnlyEvent;
        _oth set [1, time + 30];
    };
} else {
    [QGVAR(brcwgt), [_unit]] call ACE_fnc_receiverOnlyEvent;
    _oth set [0, _unit];
    _oth set [1, time + 30];
};
