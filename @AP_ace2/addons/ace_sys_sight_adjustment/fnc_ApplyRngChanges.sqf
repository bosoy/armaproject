#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
private ["_w","_t","_veh","_p","_range","_wind","_table","_el"];

_range = parseNumber (ctrlText 3033);
_wind = parseNumber (ctrlText 3097);
_table = ACE_SYS_SA_WCFG_TABLE;
_el = 0;
{
	if ((_x select 0) == _range) exitwith { _el = _x select 1 };
} foreach _table;

ACE_SYS_SA_SET_CURELEVATION(_el);
ACE_SYS_SA_SET_CURWINDAGE(_wind);
call FUNC(SetDegrees);

//recording the settings into the vehicles array

_el = ACE_SYS_SA_CURELEVATION_DEG;
_wind = ACE_SYS_SA_CURWINDAGE_DEG;
_w = ACE_SYS_SA_CURWEAPON;
_t = ACE_SYS_SA_CURTURRET;
_p = [_el,_wind,_w,_t,false,ACE_SYS_SA_CURELEVATION,ACE_SYS_SA_CURWINDAGE];
_veh = vehicle player;
// Syncing elev/windage with other machines
//[QGVAR(setadj), [_veh,_p]] call CBA_fnc_globalEvent;
_veh setVariable ["ace_sys_sight_adjustment_params", _p, true];  //global

closeDialog 1;
