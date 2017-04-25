/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */
#include "script_component.hpp"

PARAMS_1(_knicklicht);
if (_knicklicht getVariable QGVAR(locked)) exitWith {};
_knicklicht_magazin = getText(configFile >> "CfgVehicles" >> typeOf _knicklicht >> "ACE" >> "ACE_KNICKLICHT" >> "magazine");
if (((player call CBA_fnc_getUnitAnim) select 0) == "stand") then {
	player playMove "AmovPercMstpSrasWrflDnon_diary";
};
deleteVehicle _knicklicht;
sleep 1;
player addMagazine _knicklicht_magazin;
