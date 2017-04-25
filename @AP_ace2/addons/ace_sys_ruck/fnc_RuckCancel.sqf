//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_target);
private ["_caller"];

if ( [_target] call FUNC(RuckBusy) ) then {
    _caller = _target getVariable ["ACE_Ruck_Lock_Unit", objNull];

    if (! isNull _caller) then { [QGVAR(GearClose), [_caller]] call ACE_fnc_receiverOnlyEvent; };
};
