#include "script_component.hpp"

PARAMS_4(_unit,_caller,_id,_params);

_action = _params select 0;

switch (_action) do {
	case "1": { // Stop
		[QGVAR(1), player] call CBA_fnc_LocalEvent;
	};
	case "2": { // Go
		[QGVAR(2), player] call CBA_fnc_LocalEvent;	
	};	
	case "3": { // Cover
		[QGVAR(3), player] call CBA_fnc_LocalEvent;	
	};
	case "4": { // Attack
		[QGVAR(4), player] call CBA_fnc_LocalEvent;	
	};
	case "5": { // CeaseFire
		[QGVAR(5), player] call CBA_fnc_LocalEvent;	
	};
	case "6": { // Follow
		[QGVAR(6), player] call CBA_fnc_LocalEvent;
	};
	case "7": { // Up
		[QGVAR(7), player] call CBA_fnc_LocalEvent;
	};
	case "8": { // Advance
		[QGVAR(8), player] call CBA_fnc_LocalEvent;
	};
	case "9": { // Point
		[QGVAR(9), player] call CBA_fnc_LocalEvent;
	};
	case "10": {
		call FUNC(TabShoulder);
	};
};
