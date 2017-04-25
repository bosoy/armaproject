/* ACE_Stretcher | (c) 2010 by rocko */

// Stretcher handling
#include "script_component.hpp"

PARAMS_1(_u);

private["_s"];

if !(_weapon in (weapons _u)) exitWith { false };
if ("ACE_Stretcher" in (weapons _u)) then { _u removeWeapon "ACE_Stretcher"; };

if (((_u call CBA_fnc_getUnitAnim) select 0) == "stand") then { _u playMove "AmovPercMstpSrasWrflDnon_diary"; };

sleep 1;

_p = _u modelToWorld [0,0,0];
_p set [0, (_p select 0) + (sin (direction _u) * 0.8)];
_p set [1, (_p select 1) + (cos (direction _u) * 0.8)];
_z = [_u] call CBA_fnc_realHeight;
_p set [2,_z];

_s = "ACE_Stretcher" createVehicle _p;
_u reveal _s;
_s setDir (direction _u);
_s setPos _p;
