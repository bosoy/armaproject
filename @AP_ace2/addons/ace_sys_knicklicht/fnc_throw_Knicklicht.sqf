/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */
#include "script_component.hpp"

private ["_knl","_pos","_col","_type","_knl_obj"];

_knl = _this select 6;

#define __vel ((velocity _knl) call ACE_fnc_magnitude)

while { alive _knl && {!isNull _knl} } do {
	sleep 0.1;
	if (__vel < 0.2) exitWith {
		false;
	};
};

_pos = getPosATL _knl;
_col = getText(configFile >> "CfgAmmo" >> (_this select 4) >> "ACE_Knicklicht_Farbe");
deleteVehicle _knl;

switch (toUpper _col) do {
	case "R": { _type = "ACE_Knicklicht_Object_R"; };
	case "G": { _type = "ACE_Knicklicht_Object_G"; };
	case "B": { _type = "ACE_Knicklicht_Object_B"; };
	case "W": { _type = "ACE_Knicklicht_Object_W"; };
	case "Y": { _type = "ACE_Knicklicht_Object_Y"; };
	case "IR": { _type = "ACE_Knicklicht_Object_IR"; };
};

_knl_obj = _type createVehicle _pos;
_knl_obj setPosATL _pos;
