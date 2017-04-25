#include "script_component.hpp"

TRACE_1("",_this);

private ["_ar", "_r"];
_ar = [] + GVAR(cqb);
_r = false;
if (count _ar > 0) then {
	if (scriptDone GVAR(key_pid)) then {
		GVAR(key_pid) = _ar spawn {
			{
				if ((_x select 1) != primaryWeapon player) exitWith { // Exit forEach scope
					_x call FUNC(switchWep);
				};
			} forEach _this;
		};
		_r = true;
	};
};

_r;
