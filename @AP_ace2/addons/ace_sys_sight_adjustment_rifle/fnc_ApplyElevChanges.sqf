#include "Script_SightAdjustmentConfig2.hpp"
#include "\x\ace\addons\sys_sight_adjustment_rifle\script_component.hpp"
private ["_range","_wind","_table","_el","_stepel","_stepwnd"];
//hint "Changes Applied";

_el = parseNumber (ctrlText 3033);
_wind = parseNumber (ctrlText 3097);
_stepel = ACE_SYS_SA_RFL_WCFG_ADJELEVATION;
_stepwnd = ACE_SYS_SA_RFL_WCFG_ADJWINDAGE;
//player groupchat format ["setting windage %1 elev %2 minelev %3 maxelev %4", _wind, _el, ACE_SYS_SA_WCFG_MINELEVATION,ACE_SYS_SA_WCFG_MAXELEVATION];
//_table = ACE_SYS_SA_WCFG_TABLE;

if (_el < ACE_SYS_SA_RFL_WCFG_MINELEVATION) then { _el = ACE_SYS_SA_RFL_WCFG_MINELEVATION };
if (_el > ACE_SYS_SA_RFL_WCFG_MAXELEVATION) then { _el = ACE_SYS_SA_RFL_WCFG_MAXELEVATION };
_el = [_el,_stepel] call FUNC(roundNumber);
ACE_SYS_SA_RFL_SET_CURELEVATION(_el);

if (_wind < - ACE_SYS_SA_RFL_WCFG_MAXWINDAGE) then { _wind = - ACE_SYS_SA_RFL_WCFG_MAXWINDAGE };
if (_wind > ACE_SYS_SA_RFL_WCFG_MAXWINDAGE) then { _wind = ACE_SYS_SA_RFL_WCFG_MAXWINDAGE };
_wind = [_wind,_stepwnd] call FUNC(roundNumber);
ACE_SYS_SA_RFL_SET_CURWINDAGE(_wind);

call FUNC(setDegrees);

//player groupchat format ["set windage %1 elev %2", _wind, _el];

{ // recording the settings into the vehicles array
	if (ACE_SYS_SA_RFL_CURWEAPON == _x select 0) exitwith {
		_x set [1,ACE_SYS_SA_RFL_CURELEVATION];
		_x set [2,ACE_SYS_SA_RFL_CURWINDAGE];
	};
} foreach ACE_SYS_SA_RFL_WPN_LIST;

closeDialog 1;
