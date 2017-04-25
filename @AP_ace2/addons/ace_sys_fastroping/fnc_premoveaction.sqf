#include "script_component.hpp"

if (_this == (GVAR(fr_state) select 0) && {(GVAR(fr_state) select 1) != -9999}) then {
	(GVAR(fr_state) select 0) removeAction (GVAR(fr_state) select 1);
	GVAR(fr_state) set [0, objNull];
	GVAR(fr_state) set [1, -9999];
};

if (player == driver _this) then {
	_this removeAction GVAR(action_abort);
};
