/* ace_fx_fnc_blind

Bind player

Parameters:
_unit

*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);

// Flash
[_unit,5,4] call ace_fx_fnc_flash;
// Blurry
[_unit,12] call ace_fx_fnc_blurry;
// Make dizzy
[_unit,30,0.08] call ace_fx_fnc_dizzy;