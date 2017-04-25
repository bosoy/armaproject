#include "script_component.hpp"
//sets current elevation and windage in degrees
#include "Script_SightAdjustmentConfig.hpp"

private ["_t","_wcfg","_z","_elz","_curelev","_curwind","_defaultelev","_defaultwind","_offset"];

_curelev = ACE_SYS_SA_RFL_CURELEVATION;
_defaultelev = ACE_SYS_SA_RFL_WCFG_DEFAULTELEVATION;
_offset = ACE_SYS_SA_RFL_WCFG_ZERO;
_curwind = ACE_SYS_SA_RFL_CURWINDAGE;
_defaultwind = ACE_SYS_SA_RFL_WCFG_DEFAULTWINDAGE;

// accounting for the previously 'zeroed' table
_wcfg = (configFile >> "cfgWeapons" >> (primaryweapon player));
_z = if (ACE_SYS_SA_RFL_WCFG_ADJMODE == "angle") then {
	getNumber (_wcfg >> "ace_sa_defaultrange")
} else {
	getNumber (_wcfg >> "ace_sa_zeroelev");
};
if (_z > 0) then {
	_t = getArray (_wcfg >> "ace_sa_table_elev");
	{
		if ((_x select 0)==_z) exitwith {_elz = _x select 1};
	} foreach _t;
	_curelev = _curelev + _elz;
	//player sidechat format ["zero %1, zeroelev %2, curelev %3 mode %4",_z,_elz,_curelev,ACE_SYS_SA_RFL_WCFG_ADJMODE];
};
if (getNumber(configfile>>"cfgweapons">>(ACE_SYS_SA_RFL_CURWEAPON)>>"ace_sys_reticles_enable_sa") == 1) then
{
	[pi*(_curelev-_defaultelev)/3,_curwind-_defaultwind] call ace_sys_reticles_fnc_move;
	//[(_curelev-_defaultelev),(_curwind-_defaultwind)] call ace_sys_reticles_fnc_move;
	_curelev = 0;
	_defaultelev = 0;
	_curwind = 0;
	_defaultwind = 0;
};
switch (toLower ACE_SYS_SA_RFL_WCFG_ELEVATION_UNITS) do {
	case "mil": { ACE_SYS_SA_RFL_SET_CURELEVATION_DEG(deg ((_curelev - _defaultelev - _offset)/1000)) };
	case "mil_e": { ACE_SYS_SA_RFL_SET_CURELEVATION_DEG((_curelev - _defaultelev - _offset)*0.06) };
	case "moa": { ACE_SYS_SA_RFL_SET_CURELEVATION_DEG((_curelev - _defaultelev - _offset)/60) };
	case "deg": { ACE_SYS_SA_RFL_SET_CURELEVATION_DEG(_curelev - _defaultelev - _offset) };
	default { ACE_SYS_SA_RFL_SET_CURELEVATION_DEG(_curelev - _defaultelev - _offset) };
};

switch (toLower ACE_SYS_SA_RFL_WCFG_WINDAGE_UNITS) do {
	case "mil": { ACE_SYS_SA_RFL_SET_CURWINDAGE_DEG(deg ((_curwind - _defaultwind)/1000)) };
	case "mil_e": { ACE_SYS_SA_RFL_SET_CURWINDAGE_DEG((_curwind - _defaultwind)*0.06) };
	case "moa": { ACE_SYS_SA_RFL_SET_CURWINDAGE_DEG((_curwind - _defaultwind)/60) };
	case "deg": { ACE_SYS_SA_RFL_SET_CURWINDAGE_DEG(_curwind - _defaultwind) };
	default { ACE_SYS_SA_RFL_SET_CURWINDAGE_DEG(_curwind - _defaultwind) };
};