#include "script_component.hpp"

// Normalize a 3d Vector.

private "_mag";
PARAMS_3(_vx,_vy,_vz);

_mag = _this call ACE_fnc_magnitude;
if (_mag == 0) then {_mag = 1};
[_vx/_mag, _vy/_mag, _vz/_mag]
