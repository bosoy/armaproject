//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_shooter,_weapon,_muzzle);

[gunner _shooter, _shooter, 0, _weapon, _muzzle] call FUNC(firedNear);
