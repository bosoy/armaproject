/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"
PARAMS_1(_unit);

_unit removeEventhandler ["animdone",GVAR(animchanged_attached)];

_knicklicht_object = _unit getVariable "ace_attached_knicklicht_object";
_knicklicht_magazin = _unit getVariable "ace_attached_knicklicht_magazine";
if !(_knicklicht_magazin in ["ACE_Knicklicht_R_Used", "ACE_Knicklicht_W_Used", "ACE_Knicklicht_G_Used", "ACE_Knicklicht_Y_Used", "ACE_Knicklicht_B_Used", "ACE_Knicklicht_IR_Used"]) then {
	_knicklicht_magazin = format["%1_USED",(_unit getVariable "ace_attached_knicklicht_magazine")];
};

detach _knicklicht_object;
deleteVehicle _knicklicht_object;

player addMagazine _knicklicht_magazin;

player setVariable ["ace_attached_knicklicht", false, false];
player setVariable ["ace_attached_knicklicht_object", nil, false];
player setVariable ["ace_attached_knicklicht_magazine", nil, false];
