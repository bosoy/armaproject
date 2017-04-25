/* ace_sys_sniper_tools (.pbo) | (c) 2009 by rocko */
#include "script_component.hpp"

PARAMS_2(_scope,_unit);

_scopeType = typeOf _scope;
if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
	_unit playMove "AmovPercMstpSrasWrflDnon_diary";
};
sleep 1;
_unit addWeapon _scopeType;
deleteVehicle _scope;
