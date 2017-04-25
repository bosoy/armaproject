#include "script_component.hpp"

if (!alive player || {player call ace_sys_wounds_fnc_isUncon}) exitWith {false};

if (GVAR(mag_check_open)) exitWith {true};
GVAR(mag_check_open) = true;

135923 cutRsc ["ACE_RscGearFast","PLAIN DOWN"];

true