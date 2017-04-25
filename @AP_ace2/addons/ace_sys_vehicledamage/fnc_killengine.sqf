#include "script_component.hpp"
private ["_eh"];
_this engineOn false;
_this setfuel 0; //to initially stop vehicle
_eh = _this getvariable "ace_d_blockengine";
if (isNil "_eh") then {
	[QGVAR(handle_eh), _this] call CBA_fnc_globalEvent;
};
