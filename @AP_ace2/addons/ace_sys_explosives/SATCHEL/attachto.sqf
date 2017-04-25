#include "\x\ace\addons\sys_explosives\script_component.hpp"

PARAMS_2(_mine,_vehicle);

_mine attachTo [_vehicle,[0,0,0],""];
_vehicle setVariable [QGVAR(VBIED), true, true];
