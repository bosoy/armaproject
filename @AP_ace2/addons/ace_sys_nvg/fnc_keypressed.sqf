//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __HINT playSound "Counter"; hintSilent format ["%1 %2%3",localize "STR_DN_ACE_SYS_NVG_SENS",round abs(((GVAR(sensitivity)-(__MAX_APERTURE + __MIN_APERTURE))/(__MAX_APERTURE - __MIN_APERTURE))*100) - 4,"%"]
#define __INCREMENT 0.1
#define __CUR_V_MODE currentVisionMode player

if (dialog && {_this find "doNotCloseDialog" < 0}) exitwith { TRACE_1("Abort. Dialog", _this); false; };
if (visibleMap) exitwith { TRACE_1("Abort. Map", _this); false; };

PARAMS_1(_state);

// Also enable brightness adjustment while in scope view
if (__CUR_V_MODE == 1 && {GVAR(settingon)}) then {
	switch _state do {
		// INCREASE brightness
		case 1: {
			TRACE_1("Bright Up Key",_state);
			if (GVAR(sensitivity) > __MIN_APERTURE) then {
				GVAR(sensitivity) = (GVAR(sensitivity) - (__INCREMENT * GVAR(sensitivity))) max __MIN_APERTURE; // Linear relationship, sensitivity becomes less sensitive as it reaches min
				setAperture GVAR(sensitivity);
				__HINT;
				uiNamespace setVariable [QGVAR(sensitivity), GVAR(sensitivity)];
			};
		};
		// DECREASE brightness
		case 0: {
			TRACE_1("Bright Down Key",_state);
			if (GVAR(sensitivity) < __MAX_APERTURE) then {
				GVAR(sensitivity) = (GVAR(sensitivity) + (__INCREMENT * GVAR(sensitivity))) min __MAX_APERTURE; // Linear relationship, sensitivity becomes less sensitive as it reaches max
				setAperture GVAR(sensitivity);
				__HINT;
				uiNamespace setVariable [QGVAR(sensitivity), GVAR(sensitivity)];
			};
		};
	};
};

false
