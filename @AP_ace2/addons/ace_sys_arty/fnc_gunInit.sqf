#include "script_component.hpp"

private["_isAceArty"];
PARAMS_1(_gun);

_isAceArty = getNumber (configFile >> "CfgVehicles" >> typeOf _gun >> "ACE_ARTY_ISARTY");
if (!isNil "_isAceArty") then {
	if (_isAceArty == 1) then {
		_gun setVariable ["ace_sys_arty_roundData", []];
		_gun setVariable ["ace_sys_arty_currentRound", []];
		//_gun addEventhandler ["fired", { _this call FUNC(fired) }];
	};
};

// old style Illum/WP
_gun addEventhandler ["fired", { _this call FUNC(firedEh) }];
