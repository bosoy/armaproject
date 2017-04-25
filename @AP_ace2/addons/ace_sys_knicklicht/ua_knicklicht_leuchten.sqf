/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

GVAR(getin_used) = {
	_unit = _this select 0;
	_anim = _this select 1;
	if (_anim in [
					"amovpercmstpsnonwnondnon_acrgpknlmstpsnonwnondnon_getinlow",
					"amovpercmstpsnonwnondnon_acrgpknlmstpsnonwnondnon_getinmedium",
					"amovpercmstpsnonwnondnon_acrgpknlmstpsnonwnondnon_getinhigh"
				]
		) then {
		sleep .5;
		_knl = _unit getVariable "ace_used_knicklicht_object";
		detach _knl;
		_attach_pos = (vehicle _unit) worldToModel (getPos _unit);
		_attach_pos set [2, ((vehicle _unit worldToModel (getpos _unit) select 2) - (_unit worldToModel (getpos vehicle _unit) select 2))];
		_knl attachTo [(vehicle _unit), _attach_pos, ""];
		_unit setVariable ["ace_knicklicht_using_in_vehicle", true, false];
	};

	if (_anim in [
					"acrgpknlmstpsnonwnondnon_amovpercmstpsraswrfldnon_getoutlow",
					"acrgpknlmstpsnonwnondnon_amovpercmstpsraswrfldnon_getoutmedium",
					"acrgpknlmstpsnonwnondnon_amovpercmstpsraswrfldnon_getouthigh",
					"acrgpknlmstpsnonwnondnon_amovpercmstpsraswpstdnon_getoutlow",
					"acrgpknlmstpsnonwnondnon_amovpercmstpsraswpstdnon_getoutmedium",
					"acrgpknlmstpsnonwnondnon_amovpercmstpsraswpstdnon_getouthigh",
					"acrgpknlmstpsnonwnondnon_amovpercmstpsnonwnondnon_getoutlow",
					"acrgpknlmstpsnonwnondnon_amovpercmstpsnonwnondnon_getoutmedium",
					"acrgpknlmstpsnonwnondnon_amovpercmstpsnonwnondnon_getouthigh"
				]
		) then {
		sleep .5;
		_knl = _unit getVariable "ace_used_knicklicht_object";
		detach _knl;
		_knl attachTo [_unit, [0,-0.06,0], "Granat"];
		_unit setVariable ["ace_knicklicht_using_in_vehicle", false, false];
	};
};

private ["_knicklicht_objekt"];
_knicklicht = currentMagazine player;
if (_knicklicht in (magazines player)) then { player removeMagazine _knicklicht; };
_color = getText(configFile >> "CfgMagazines" >> _knicklicht >> "ammo");

GVAR(animchanged_used) = player addEventhandler ["animdone", "_this spawn ace_sys_knicklicht_getin_used"];

switch (toUpper _color) do {
	case "ACE_KNICKLICHT_R": { _knicklicht_objekt = "ACE_Knicklicht_Object_R_I"; };
	case "ACE_KNICKLICHT_G": { _knicklicht_objekt = "ACE_Knicklicht_Object_G_I"; };
	case "ACE_KNICKLICHT_W": { _knicklicht_objekt = "ACE_Knicklicht_Object_W_I"; };
	case "ACE_KNICKLICHT_Y": { _knicklicht_objekt = "ACE_Knicklicht_Object_Y_I"; };
	case "ACE_KNICKLICHT_B": { _knicklicht_objekt = "ACE_Knicklicht_Object_B_I"; };
	case "ACE_KNICKLICHT_IR": { _knicklicht_objekt = "ACE_Knicklicht_Object_IR_I"; };
};

_pistol = [player] call ACE_fnc_getPistol;

private["_rifle"];
{
	if ((getNumber (configFile >> "CfgWeapons" >> _x >> "Type")) in [1,5]) exitWith {
		_rifle = _x;
	};
} forEach (weapons player);

private["_weapon"];
if (_pistol != "") then { _weapon = _pistol; };
if (_rifle != "") then { _weapon = _rifle; };

player setVariable ["ace_used_knicklicht_weapon", _weapon, false];
player setVariable ["ace_used_knicklicht_pistol", nil, false];
player setVariable ["ace_used_knicklicht_pistol_mag", nil, false];
if (_pistol != "") then {
	player setVariable ["ace_used_knicklicht_pistol", _pistol, false];
	player removeWeapon _pistol;
};

player addWeapon "ACE_Knicklicht_Proxy";

sleep 1;

player selectWeapon "ACE_Knicklicht_Proxy";

_knicklicht_attach = _knicklicht_objekt createVehicle [0,0,0];
_knicklicht_attach attachTo [player, [0,-0.06,0], "Granat"];

player setVariable ["ace_used_knicklicht", true, false];
player setVariable ["ace_used_knicklicht_object", _knicklicht_attach, false];
player setVariable ["ace_used_knicklicht_magazine", _knicklicht, false];

// Setvariable the chemlight to prevent others interacting with it
_knicklicht_attach setVariable [QGVAR(locked), true, true];

waitUntil { currentWeapon player == "ACE_Knicklicht_Proxy" };
player setVariable ["ace_knicklicht_using_in_vehicle", false, false];
while { (currentWeapon player == "ACE_Knicklicht_Proxy") || {(player getVariable "ace_knicklicht_using_in_vehicle")} } do {
	sleep 1.5;
};
[player] spawn COMPILE_FILE(ua_knicklicht_leuchten_ende);
