/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

private ["_knicklicht_objekt"];
_knicklicht = currentMagazine player;
if (_knicklicht in (magazines player)) then { player removeMagazine _knicklicht; };
_color = getText(configFile >> "CfgMagazines" >> _knicklicht >> "ammo");

ace_sys_knicklicht_getin = {
	_unit = _this select 0;
	_anim = _this select 1;
	if (_anim in ["amovpercmstpsnonwnondnon_acrgpknlmstpsnonwnondnon_getinlow",
				"amovpercmstpsnonwnondnon_acrgpknlmstpsnonwnondnon_getinmedium",
				"amovpercmstpsnonwnondnon_acrgpknlmstpsnonwnondnon_getinhigh"]
		) then {
		sleep 1;
		_knl = _unit getVariable "ace_attached_knicklicht_object";
		detach _knl;
		_attach_pos = (vehicle _unit) worldToModel (getPos _unit);
		_attach_pos set [2, ((vehicle _unit worldToModel (getpos _unit) select 2) - (_unit worldToModel (getpos vehicle _unit) select 2))];
		_knl attachTo [vehicle _unit, _attach_pos, ""];
	};
	if (_anim in ["acrgpknlmstpsnonwnondnon_amovpercmstpsraswrfldnon_getoutlow",
				"acrgpknlmstpsnonwnondnon_amovpercmstpsraswrfldnon_getoutmedium",
				"acrgpknlmstpsnonwnondnon_amovpercmstpsraswrfldnon_getouthigh",
				"acrgpknlmstpsnonwnondnon_amovpercmstpsraswpstdnon_getoutlow",
			"acrgpknlmstpsnonwnondnon_amovpercmstpsraswpstdnon_getoutmedium",
				"acrgpknlmstpsnonwnondnon_amovpercmstpsraswpstdnon_getouthigh",
				"acrgpknlmstpsnonwnondnon_amovpercmstpsnonwnondnon_getoutlow",
				"acrgpknlmstpsnonwnondnon_amovpercmstpsnonwnondnon_getoutmedium",
			"acrgpknlmstpsnonwnondnon_amovpercmstpsnonwnondnon_getouthigh"]
		) then {
		sleep 1;
		_knl = _unit getVariable "ace_attached_knicklicht_object";
		detach _knl;
		_knl attachTo [_unit, [-0.025,-0.06,0.05], "LeftShoulder"];
		sleep 0.5;
	};
};

GVAR(animchanged_attached) = player addEventhandler ["animdone", "_this spawn ace_sys_knicklicht_getin"];

switch (toUpper _color) do {
	case "ACE_KNICKLICHT_R": { _knicklicht_objekt = "ACE_Knicklicht_Object_R"; };
	case "ACE_KNICKLICHT_G": { _knicklicht_objekt = "ACE_Knicklicht_Object_G"; };
	case "ACE_KNICKLICHT_W": { _knicklicht_objekt = "ACE_Knicklicht_Object_W"; };
	case "ACE_KNICKLICHT_Y": { _knicklicht_objekt = "ACE_Knicklicht_Object_Y"; };
	case "ACE_KNICKLICHT_B": { _knicklicht_objekt = "ACE_Knicklicht_Object_B"; };
	case "ACE_KNICKLICHT_IR": { _knicklicht_objekt = "ACE_Knicklicht_Object_IR"; };
};
sleep 0.5;

_knicklicht_attach = _knicklicht_objekt createVehicle [0,0,0];
_knicklicht_attach attachTo [player, [-0.025,-0.06,0.05], "LeftShoulder"];

player setVariable ["ace_attached_knicklicht", true, false];
player setVariable ["ace_attached_knicklicht_object", _knicklicht_attach, true];
player setVariable ["ace_attached_knicklicht_magazine", _knicklicht, false];

// Setvariable the chemlight to prevent others interacting with it
_knicklicht_attach setVariable [QGVAR(locked), true, true];
