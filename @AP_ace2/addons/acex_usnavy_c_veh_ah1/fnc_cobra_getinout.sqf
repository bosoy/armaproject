// Script by zGuba A.D. 2010
// Open door at get in and out

#include "script_component.hpp"

PARAMS_3(_vehicle,_position,_unit);

if !(alive _vehicle) exitWith {};

if (_position == "driver") exitWith {
	if (_vehicle animationPhase "PilotWindow" < 1) then {
		_vehicle animate ["PilotWindow", 1];
	//	[_vehicle, "doors"] call CBA_fnc_globalSay3D;
	};

	sleep 2;

	if (((_unit distance _vehicle) < 6) || (_unit in crew _vehicle)) then {
		_vehicle animate ["PilotWindow", 0];
	//	[_vehicle, "doors"] call CBA_fnc_globalSay3D;
	};
};

if (_position == "gunner") exitWith {
	if (_vehicle animationPhase "GunnerWindow" < 1) then {
		_vehicle animate ["GunnerWindow", 1];
	//	[_vehicle, "doors"] call CBA_fnc_globalSay3D;
	};

	sleep 2;

	if (((_unit distance _vehicle) < 6) || (_unit in crew _vehicle)) then {
		_vehicle animate ["GunnerWindow", 0];
	//	[_vehicle, "doors"] call CBA_fnc_globalSay3D;
	};
};
