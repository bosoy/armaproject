/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

_knicklicht = _this;
if (_knicklicht getVariable QGVAR(locked)) exitWith {};
if (((player call CBA_fnc_getUnitAnim) select 0) == "stand") then {
	player playMove "AmovPercMstpSrasWrflDnon_diary";
};
deleteVehicle _knicklicht;
