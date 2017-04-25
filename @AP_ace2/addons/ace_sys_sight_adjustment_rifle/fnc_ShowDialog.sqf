#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
private ["_units","_c","_dlg","_i","_range","_table","_initelev"];

if (isNull (findDisplay 30830) && {isNull (findDisplay 30831)} && {isNull (findDisplay 30832)} && {cameraview != "GUNNER"}) then {
	GVAR(shiftdown) = false;
	if (ACE_SYS_SA_RFL_WCFG_ADJMODE == "range") then { //sa dialog with range settings
		_dlg = createDialog "ACE_SYS_SA_RFL_RNG_Dialog";
		waituntil { _dlg };

		_initelev = ACE_SYS_SA_RFL_CURELEVATION;
		//finding the range setting corresponding to the current elevation in mils (or whatever unit is being used)
		_table = ACE_SYS_SA_RFL_WCFG_TABLE;
		_range = 0;
		{
			if ((_x select 1) == _initelev) exitwith { _range = _x select 0 };
			//if (_initelev < (_x select 1)) exitwith { _range = _x select 0 };	//if no match found, take the closest value
		} foreach _table;

		ctrlSetText [3033, str(_range)];

		//setting current windage
		_initwindage = ACE_SYS_SA_RFL_CURWINDAGE;
		ctrlSetText [3097, str(_initwindage)];

		//setting measurement units
		_units = call FUNC(findUnitText);
		ctrlSetText [3501,(_units select 2)];
		ctrlSetText [3502, (_units select 1)];

		[] execVM "\x\ACE\Addons\sys_sight_adjustment_rifle\s\ShowRangeCard.sqf";
	};

	if (ACE_SYS_SA_RFL_WCFG_ADJMODE == "angle") then { //sa dialog with elev settings
		_dlg = createDialog "ACE_SYS_SA_RFL_ELEV_Dialog";
		waituntil { _dlg };
		//setting last recorded elevation
		_initelev = ACE_SYS_SA_RFL_CURELEVATION;
		ctrlSetText [3033, str(_initelev)];

		//setting current windage
		_initwindage = ACE_SYS_SA_RFL_CURWINDAGE;
		ctrlSetText [3097, str(_initwindage)];

		[] execVM "\x\ACE\Addons\sys_sight_adjustment_rifle\s\ShowRangeCard.sqf";
		
		_units = call FUNC(findUnitText);

		ctrlSetText [3501,(_units select 0)];
		ctrlSetText [3502, (_units select 1)];
	};

	if (ACE_SYS_SA_RFL_WCFG_ADJMODE == "range_and_angle") then { //sa dialog with both range and elev settings
		_dlg = createDialog "ACE_SYS_SA_RFL_RNG_ANGLE_Dialog";
		waituntil { _dlg };

		_initelev = ACE_SYS_SA_RFL_CURELEVATION;
		_range = ACE_SYS_SA_RFL_CURRANGE;
		_table = ACE_SYS_SA_RFL_WCFG_TABLE;

		ctrlSetText [3033, str(_range)];
		ctrlSetText [3670, str(_initelev)];
		//setting current windage
		_initwindage = ACE_SYS_SA_RFL_CURWINDAGE;
		ctrlSetText [3097, str(_initwindage)];

		//setting measurement units
		_units = call FUNC(findUnitText);
		ctrlSetText [3501,(_units select 2)];
		ctrlSetText [3502, (_units select 1)];
		ctrlSetText [3667, (_units select 0)];
	};
};
