/* ace_sys_irstrobe (.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */
#include "script_component.hpp"

private "_type";

_type = getText(configFile >> "CfgVehicles" >> typeOf _this >> "ACE" >> "ACE_IRSTROBE" >> "magazine");

deleteVehicle _this;
[player, _type] call CBA_fnc_addMagazine;
