/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"
PARAMS_1(_unit);

_knicklicht_object = _unit getVariable "ace_used_knicklicht_object";
_knicklicht_magazin = _unit getVariable "ace_used_knicklicht_magazine";
if !(_knicklicht_magazin in ["ACE_Knicklicht_R_Used", "ACE_Knicklicht_W_Used", "ACE_Knicklicht_G_Used", "ACE_Knicklicht_Y_Used", "ACE_Knicklicht_B_Used", "ACE_Knicklicht_IR_Used"]) then {
	_knicklicht_magazin = format["%1_USED",(_unit getVariable "ace_used_knicklicht_magazine")];
};
detach _knicklicht_object;
deleteVehicle _knicklicht_object;

_unit removeWeapon "ACE_Knicklicht_Proxy";

_pistol = _unit getVariable "ace_used_knicklicht_pistol";
if !(isNil "_pistol") then {
	_unit addWeapon _pistol;
};
_weapon = (_unit getVariable "ace_used_knicklicht_weapon");

_muzzle = getArray(configFile >> "CfgWeapons" >> _weapon >> "muzzles");
if (count _muzzle > 1) then {
	_unit selectWeapon (_muzzle select 0);
} else {
	_unit selectWeapon _weapon;
};

_unit addMagazine _knicklicht_magazin;

_unit setVariable ["ace_used_knicklicht", false, false];
_unit setVariable ["ace_used_knicklicht_object", nil, false];
_unit setVariable ["ace_used_knicklicht_magazine", nil, false];
_unit setVariable ["ace_used_knicklicht_pistol", nil, false];
_unit setVariable ["ace_used_knicklicht_pistol_magazine", nil, false];
_unit setVariable ["ace_used_knicklicht_weapon", nil, false];
_unit removeEventhandler ["animdone",GVAR(animchanged_used)];
