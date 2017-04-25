// by Xeno
#define THIS_FILE "x_artiradiocheck.sqf"
#include "x_setup.sqf"
private "_artinum";
PARAMS_1(_artinum);
while {true} do {
	waitUntil {sleep 0.213;alive player};
	waitUntil {sleep 0.312; isNumber(configFile >> "CfgWeapons" >> secondaryWeapon player >> "ACE_is_radio")};
	switch (_artinum) do {
		case 1: {GVAR(player_can_call_arti) = 1};
		case 2: {GVAR(player_can_call_arti) = 2};
	};
	while {isNumber(configFile >> "CfgWeapons" >> secondaryWeapon player >> "ACE_is_radio")} do {
		sleep 0.52;
	};
	GVAR(player_can_call_arti) = 0;
	sleep 1.021;
};