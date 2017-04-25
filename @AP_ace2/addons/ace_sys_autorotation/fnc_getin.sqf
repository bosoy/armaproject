#include "script_component.hpp"
PARAMS_1(_heli);

if (_heli isKindOf "ParachuteBase") exitwith {};

waituntil {
	sleep 5;
	((vehicle player == _heli && isEngineOn _heli) || (vehicle player != _heli))
};
if (vehicle player != _heli) exitwith {};
[] spawn FUNC(engineloop);
