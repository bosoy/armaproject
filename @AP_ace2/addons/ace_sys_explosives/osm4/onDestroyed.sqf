#include "\x\ace\addons\sys_explosives\script_component.hpp"

PARAMS_2(_mine,_ex);

if (_mine getVariable [QGVAR(canInteract), false]) then {
	_ex createVehicle [((position _mine) select 0),((position _mine) select 1), (0.8 + ([_mine] call CBA_fnc_realHeight))];
};
