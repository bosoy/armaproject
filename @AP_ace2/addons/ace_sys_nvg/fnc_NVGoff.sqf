#include "script_component.hpp"
GVAR(on) = false;
if (GVAR(rangelimit_enabled)) then {
	GVAR(trkcamview) = false;
	GVAR(trkvehpos) = false;
	if (typename GVAR(vd) == "scalar") then
	{
		setviewdistance GVAR(vd);
		player setVariable [QGVAR(vddd),-1];
	};
};

[] spawn { // Upper scope cannot be paused
	if (GVAR(settingon) && {!GVAR(on)}) then {
		setAperture (__MAX_APERTURE / GVAR(sensitivity)); // Introduces a delay between players eyes re-adjusting to darkness after the brightness of NVGs (Linear relationship between Sensitivity and delay)
	};
	sleep 1; // Delay
	if !(GVAR(on)) then { setAperture -1 }; // Delay over, start re-adjusting eyes to ambient light
};
