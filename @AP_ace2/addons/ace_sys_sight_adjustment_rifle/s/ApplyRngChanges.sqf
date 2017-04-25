#include "Script_SightAdjustmentConfig.hpp"
#include "\x\ace\addons\sys_sight_adjustment_rifle\script_component.hpp"
private ["_range","_wind","_table","_el"];
//hint "Changes Applied";

_range = parseNumber (ctrlText 3033);
_wind = parseNumber (ctrlText 3097);
_table = ACE_SYS_SA_RFL_WCFG_TABLE;
_el = 0;
{
	if ((_x select 0) == _range) exitwith { _el = _x select 1 };
} foreach _table;

//player groupchat format ["set windage %1 elev %2", _wind, _el];

ACE_SYS_SA_RFL_SET_CURELEVATION(_el);
ACE_SYS_SA_RFL_SET_CURWINDAGE(_wind);
call FUNC(setDegrees);

{ // recording the settings into the weapons array
	if (ACE_SYS_SA_RFL_CURWEAPON == _x select 0) exitwith {
		_x set [1,ACE_SYS_SA_RFL_CURELEVATION];
		_x set [2,ACE_SYS_SA_RFL_CURWINDAGE];
	};
} foreach ACE_SYS_SA_RFL_WPN_LIST;

closeDialog 1;
