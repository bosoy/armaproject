/* ace_sys_goggles (.pbo) | (c) 2009, 2010 by rocko */

#include "script_component.hpp"

if !(player == player) exitWith {}; // SP Mode, no player ?

LOG(MSG_INIT);
ADDON = false;

_quit = false;
_text = "";

#define __check configFile >> "CfgIdentities" >> "ACE_Original_Identity" >> "name"

if (getText(__check) == "") then { _quit = true; _text = "YOU HAVE NOT ENTERED A VALID USERNAME IN ACE USERCONFIG."};
if (getText(__check) != name player) then { _quit = true; _text = format["YOUR PLAYER NAME DOES NOT MATCH NAME GIVEN IN ACE USERCONFIG. '%1' != '%2'", getText(__check), name player]};

player setVariable [QGVAR(earplugs), false];
player setVariable [QGVAR(protection), -1, false];

GVAR(configured) = false;

if (isMultiplayer && {_quit}) exitWith {
	private ["_row1", "_row2"];
	_row1 = "Initializing... FAILURE! Please check your ACE userconfig. ACE Goggles feature has been disabled on your computer!";
	_row2 = "Reason: " + str(_text);
	WARNING(_row1);
	WARNING(_row2);
	[_row1, _row2] spawn {
		sleep 5; // sleep beyond briefing + few secs
		player commandChat (_this select 0);
		player commandChat (_this select 1);
	};
};

GVAR(configured) = true;

["player", [ace_sys_interaction_key_self], -9235, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;

ADDON = true;
