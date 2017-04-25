#include "script_component.hpp"

if (GVAR(plrinburn)) exitwith {};
GVAR(plrinburn) = true;
PARAMS_1(_unit);
[_unit] spawn {
	PARAMS_1(_unit);
	_unit = _this select 0;
	while { player in _unit && {alive player} } do {
		135411 cutRsc ["ace_burn_indicator_1", "PLAIN"];
		sleep 0.99;
		135411 cutRsc ["ace_burn_indicator_2", "PLAIN"];
		sleep 0.99;
	};
	GVAR(plrinburn) = false;
};