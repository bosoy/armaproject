// by Xeno
#define THIS_FILE "x_dropradiocheck.sqf"
#include "x_setup.sqf"
while {true} do {
	waitUntil {sleep 0.323;alive player};
	waitUntil {sleep 0.312; isNumber(configFile >> "CfgWeapons" >> secondaryWeapon player >> "ACE_is_radio")};
	GVAR(player_can_call_drop) = 1;
	while {isNumber(configFile >> "CfgWeapons" >> secondaryWeapon player >> "ACE_is_radio")} do {
		sleep 0.512;
	};
	GVAR(player_can_call_drop) = 0;
	sleep 1.021;
};