/* ace_sys_groundmarker | (c) 2010,2011,2012 by rocko */

#include "script_component.hpp"

ADDON = false;

PREP(place);
PREP(flip);
PREP(pickup);

FUNC(attach_chemlight) = {
	PARAMS_1(_panel);
	private ["_knicklicht_objekt","_knicklicht_attach"];
	_knicklicht = currentMagazine player;
	if (_knicklicht in (magazines player)) then { player removeMagazine _knicklicht; };
	_color = getText(configFile >> "CfgMagazines" >> _knicklicht >> "ammo");	
	switch (toUpper _color) do {
		case "ACE_KNICKLICHT_R": { _knicklicht_objekt = "ACE_Knicklicht_Object_R"; };
		case "ACE_KNICKLICHT_G": { _knicklicht_objekt = "ACE_Knicklicht_Object_G"; };
		case "ACE_KNICKLICHT_W": { _knicklicht_objekt = "ACE_Knicklicht_Object_W"; };
		case "ACE_KNICKLICHT_Y": { _knicklicht_objekt = "ACE_Knicklicht_Object_Y"; };
		case "ACE_KNICKLICHT_B": { _knicklicht_objekt = "ACE_Knicklicht_Object_B"; };
		case "ACE_KNICKLICHT_IR": { _knicklicht_objekt = "ACE_Knicklicht_Object_IR"; };
	};	
	_knicklicht_attach = _knicklicht_objekt createVehicle [0,0,0];
	_knicklicht_attach attachTo [_panel, [0.1,0,0],"clp1"];
	_knicklicht_attach setDir (getDir _panel + 90);
	_panel setVariable [QGVAR(hasCL),true,true];
	_panel setVariable [QGVAR(CL),_knicklicht_attach,true];
};

ADDON = true;
