#include "script_component.hpp"

PARAMS_2(_chute,_caller);

if (_caller in _chute) then {
	sleep 0.5;
	_caller setVariable [QGVAR(ChuteOpen), 2];
};