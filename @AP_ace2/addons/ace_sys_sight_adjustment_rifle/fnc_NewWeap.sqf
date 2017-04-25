/* This function is called from: fnc_keypressed.sqf */
#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

private["_t","_key","_wpn","_s","_wcfg","_wpn_in_the_list","_adjmode","_BDC"];

_wpn = _this;
_wpn_in_the_list = false;
_wcfg = configFile >> "cfgWeapons" >> _wpn;
_adjmode = getText (_wcfg >> "ace_sa_adj_mode");
// TODO: Change path
_BDC = (["ACE", "ACE_SIGHT_ADJUSTMENT_RIFLE_CONFIG", "enable_BDC"] call ace_settings_fnc_getNumber);
if (_BDC == 0 && {_adjmode == "range_and_angle"}) then {_adjmode = "angle"};
switch (toLower _adjmode) do {
	case "range": {
		ACE_SYS_SA_RFL_WCFG_SET_MINELEVATION(getNumber (_wcfg >> "ace_sa_minrange"));
		ACE_SYS_SA_RFL_WCFG_SET_MAXELEVATION(getNumber (_wcfg >> "ace_sa_maxrange"));
	};
	case "angle": {
		ACE_SYS_SA_RFL_WCFG_SET_MINELEVATION(getNumber (_wcfg >> "ace_sa_minelevation"));
		ACE_SYS_SA_RFL_WCFG_SET_MAXELEVATION(getNumber (_wcfg >> "ace_sa_maxelevation"));
		ACE_SYS_SA_RFL_WCFG_SET_ADJELEVATION(getNumber (_wcfg >> "ace_sa_stepelevation"));
	};
	case "range_and_angle": {
		ACE_SYS_SA_RFL_WCFG_SET_MINELEVATION(getNumber (_wcfg >> "ace_sa_minelevation"));
		ACE_SYS_SA_RFL_WCFG_SET_MAXELEVATION(getNumber (_wcfg >> "ace_sa_maxelevation"));
		ACE_SYS_SA_RFL_WCFG_SET_ADJELEVATION(getNumber (_wcfg >> "ace_sa_stepelevation"));
		ACE_SYS_SA_RFL_WCFG_SET_MINRANGE(getNumber (_wcfg >> "ace_sa_minrange"));
		ACE_SYS_SA_RFL_WCFG_SET_MAXRANGE(getNumber (_wcfg >> "ace_sa_maxrange"));
	};

	default {};
};

ACE_SYS_SA_RFL_WCFG_SET_ADJMODE(_adjmode);
ACE_SYS_SA_RFL_WCFG_SET_WEAPON(_wpn);
ACE_SYS_SA_RFL_WCFG_SET_DEFAULTELEVATION(getNumber (_wcfg >> "ace_sa_defaultelevation"));
ACE_SYS_SA_RFL_WCFG_SET_ZERO(getNumber (_wcfg >> "ace_sa_zerooffset"));
ACE_SYS_SA_RFL_WCFG_SET_DEFAULTWINDAGE(getNumber (_wcfg >> "ace_sa_defaultwindage"));
ACE_SYS_SA_RFL_WCFG_SET_MAXWINDAGE(getNumber (_wcfg >> "ace_sa_windage"));
ACE_SYS_SA_RFL_WCFG_SET_ADJWINDAGE(getNumber (_wcfg >> "ace_sa_stepwindage"));
ACE_SYS_SA_RFL_WCFG_SET_ELEVATION_UNITS(getText (_wcfg >> "ace_sa_elev_unit"));
ACE_SYS_SA_RFL_WCFG_SET_WINDAGE_UNITS(getText (_wcfg >> "ace_sa_wind_unit"));
ACE_SYS_SA_RFL_WCFG_SET_RANGE_UNITS(getText (_wcfg >> "ace_sa_range_unit"));
_t = _wcfg call FUNC(zeroTable);
ACE_SYS_SA_RFL_WCFG_SET_TABLE(_t select 0);


// Cur settings:

ACE_SYS_SA_RFL_SET_ENABLED(true);
ACE_SYS_SA_RFL_SET_CURUNIT(player);
ACE_SYS_SA_RFL_SET_CURWEAPON(_wpn);
ACE_SYS_SA_RFL_SET_CURRANGE(getNumber (_wcfg >> "ace_sa_defaultrange"));
ACE_SYS_SA_RFL_SET_CURELEVATION(_t select 1);
ACE_SYS_SA_RFL_SET_CURWINDAGE(ACE_SYS_SA_RFL_WCFG_DEFAULTWINDAGE);
call FUNC(setDegrees);

//looking if player has already used this weapon and setting last recorded elevation/windage
{
	if (_wpn == _x select 0) exitwith {
		ACE_SYS_SA_RFL_SET_CURELEVATION(_x select 1);
		ACE_SYS_SA_RFL_SET_CURWINDAGE(_x select 2);
		ACE_SYS_SA_RFL_SET_CURRANGE(_x select 3);
		call FUNC(setDegrees);
		_wpn_in_the_list = true;
	};
} foreach ACE_SYS_SA_RFL_WPN_LIST;

//if the weapon hasnt been used before, add it to the list
if !(_wpn_in_the_list) then {
	_entry = [_wpn, ACE_SYS_SA_RFL_CURELEVATION,ACE_SYS_SA_RFL_CURWINDAGE,ACE_SYS_SA_RFL_CURRANGE];
	PUSH(ACE_SYS_SA_RFL_WPN_LIST,_entry);
};

/*
if (_wpn == "ACE_M109") then {
	_action= player addaction ["Lase target", "\ace_sys_sight_adjustment_rifle\f\fAutoelev.sqf"];
};
*/
