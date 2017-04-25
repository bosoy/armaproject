/* ace_sys_rangefinder (.pbo) (c) 2010 by tcp */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_optr,_rfweapon);

private ["_run", "_cfg", "_battery", "_dbattery", "_count", "_batchg", "_batswp"];

_run = false;
if(_optr == player) then {
	if(EMP_RF_RUN) then {
		EMP_RF_STP = true;
	} else {
		_run = true;
	};
};
if(_run) then {
	_cfg = configFile >> "CfgWeapons" >> _rfweapon;
	_battery = (getArray(_cfg >> "magazines")) select 0;
	_dbattery = "ACE_Battery_Rangefinder_D";
	if(_optr hasWeapon "Laserdesignator") then {
		_dbattery = "ACE_Laserbatteries_D";
	};
	//Convert to Dummy Batt
	_count = 0;
	_batchg = true;
	while {_batchg} do {
		_batchg = [_optr,_battery] call CBA_fnc_removeMagazine;
		if(_batchg) then {_count = _count + 1;};
	};
	for "_x" from 0 to _count - 1 do {
		[_optr,_dbattery] call CBA_fnc_addMagazine;
	};
	//Load Battery
	_batswp = [_optr,_dbattery] call CBA_fnc_removeMagazine;
	if(_batswp) then {
		if(EMP_RF_UNL) then {
			[localize "STR_EMP_RF_USED_BATTERY_LOAD",nil,true,4] spawn ace_fnc_visual;
			EMP_RF_UNL = false;
		} else {
			EMP_RF_BAT = 1;
			if (time > 1) then {
				[localize "STR_EMP_RF_BATTERY_LOAD",nil,true,4] spawn ace_fnc_visual;
			};
		};
	} else {
		[localize "STR_EMP_RF_OUT_BATTERY",[1,0,0,1],true,4] spawn ace_fnc_visual;
	};
};
