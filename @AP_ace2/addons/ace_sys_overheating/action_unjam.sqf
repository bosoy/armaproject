#include "script_component.hpp"
_muz = (vehicle player) getVariable QGVAR(jammed);
if (isNil "_muz") then {_muz = currentMuzzle player};
[vehicle player, _muz, 0.3] spawn FUNC(unjam);
