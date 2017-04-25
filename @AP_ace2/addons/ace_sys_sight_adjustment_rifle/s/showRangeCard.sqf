#include "Script_SightAdjustmentConfig.hpp"
#include "\x\ace\addons\sys_sight_adjustment_rifle\script_component.hpp"

private ["_c","_st","_i","_drift","_st1","_k","_d"];
_i = 0;
_st = "";
_st1 = "  ";
_d = 0;
_drift = getArray (configFile >> "cfgWeapons" >> ACE_SYS_SA_RFL_CURWEAPON >> "ace_drift");
_drift = [_drift] call FUNC(windTable);
lnbClear 4005;
{
	if ((_x select 0) != 0) then {
		_i = _i + 1;

		//if range table has 50 m step and wind table 100 m step
		if ( ((_drift select _i) select 0) == (_x select 0) ) then {
			_d = (_drift select _i) select 1;
		} else {	//interpolate the drift for intermediate ranges
			_d = (((_drift select _i) select 1) + ((_drift select (_i-1)) select 1))/2;
			//_d = "-";
			_i = _i - 1;
		};
		lnbAddRow[4005,[str(_x select 0),str(_x select 1),str _d]];
	};
} foreach ACE_SYS_SA_RFL_WCFG_TABLE;
