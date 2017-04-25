//XEH_postInit.sqf
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
"ACE_WIND_PARAMS" addPublicVariableEventHandler { ace_wind_period_start_time = time; };
"ACE_RAIN_PARAMS" addPublicVariableEventHandler { ace_wind_rain_period_start_time = time; };

_func = {
	_wind = ([] call ace_wind_fnc_getWind);
	setWind [_wind select 0, _wind select 1, true];
	// _nWind = wind;
	// _pW = [_nWind select 0, _nWind select 1, 0] call CBA_fnc_vect2polar;
	// _pAW = [_wind select 0, _wind select 1, 0] call CBA_fnc_vect2polar;
	// hint format["w: %1 %2\na: %3 %4", _pW select 1, _pw select 0, _pAW select 1, _pAW select 0];
	// diag_log text format["ACE_WIND,%1,%2,%3,%4,%5", time, _pW select 1, _pw select 0, _pAW select 1, _pAW select 0];
};

[_func, 1, []] call CBA_fnc_addPerFrameHandler;

_rainFunc = {
	if(GVAR(enableRain)) then {
		if(!isNil "ACE_RAIN_PARAMS" && {!isNil "ace_wind_rain_period_start_time"}) then {
			_oldStrength = ACE_RAIN_PARAMS select 0;
			_rainStrength = ACE_RAIN_PARAMS select 1;
			_transitionTime = ACE_RAIN_PARAMS select 2;
			_periodPosition = (time - ace_wind_rain_period_start_time) min _transitionTime;
			_periodPercent = (_periodPosition/_transitionTime) min 1;
			
			0 setRain ((_periodPercent*(_rainStrength-_oldStrength))+_oldStrength);
		};
	};
};

[_rainFunc, 0, []] call CBA_fnc_addPerFrameHandler;