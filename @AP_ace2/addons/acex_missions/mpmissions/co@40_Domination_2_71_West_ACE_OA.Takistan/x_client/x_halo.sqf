// by Xeno
#define THIS_FILE "x_halo.sqf"
#include "x_setup.sqf"

#ifdef __ACE__
if !(player hasWeapon "ACE_ParachutePack") exitWith {
	[vehicle player, (localize "STR_DOM_MISSIONSTRING_66")] call FUNC(VehicleChat);
};
player removeWeapon "ACE_ParachutePack";
#endif

player action ["EJECT", _this select 0];

if (vehicle player isKindOf "ParachuteBase") then {
	_vec = vehicle player;
	player action ["EJECT", _vec];
	deleteVehicle _vec;
};

#ifndef __ACE__
[player, player call FUNC(GetHeight)] spawn bis_fnc_halo;
#else
[player] execVM "x\ace\addons\sys_eject\jumpout_cord.sqf";
#endif