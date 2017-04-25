// by Xeno
#define THIS_FILE "x_newflagclient.sqf"
#include "x_setup.sqf"
private ["_box", "_flag"];
if (!X_Client) exitWith {};

_flag = _this;

[format [QGVAR(paraflag%1), count __XJIPGetVar(resolved_targets)], getPosASL _flag,"ICON","ColorYellow",[0.5,0.5],"Parajump",0,"mil_flag"] call FUNC(CreateMarkerLocal);
player reveal _flag;

if (GVAR(jumpflag_vec) == "") then {
	_flag addAction [(localize "STR_DOM_MISSIONSTRING_296") call FUNC(BlueText),"AAHALO\x_paraj.sqf"];
} else {
	_flag addAction [(format [(localize "STR_DOM_MISSIONSTRING_297"),[GVAR(jumpflag_vec),0] call FUNC(GetDisplayName)]) call FUNC(BlueText),"x_client\x_bike.sqf",[GVAR(jumpflag_vec),1]];
};

#ifdef __ACE__
if (GVAR(jumpflag_vec) == "") then {
	_box = "ACE_RuckBox" createVehicleLocal (position _flag);
	clearMagazineCargo _box;
	clearWeaponCargo _box;
	_box addweaponcargo ["ACE_ParachutePack",10];
};
#endif