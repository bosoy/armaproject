#include "script_component.hpp"

private["_el"];
PARAMS_2(_keyData,_type);
if !(GVAR(sightup_veh)) exitwith {false};
_el = if (_type == 1) then {1} else {-1};
if ((_this select 0) select 2) then {_el = _el*10}; //hold shift to move it faster
[_el,0] call FUNC(veh_move);

true