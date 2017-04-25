#include "script_component.hpp"

PARAMS_3(_vehicle,_caller,_id);

private "_isAHon";
_isAHon = isAutoHoverOn (vehicle _caller);
if (_isAHon) then {
	_vehicle action ["AutoHoverCancel", _vehicle];
	_vehicle setVariable [QGVAR(vtolon),false,true];
} else {
	_vehicle action ["Autohover", _vehicle];
	_vehicle setVariable [QGVAR(vtolon),true,true];
};
