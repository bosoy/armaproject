// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_veh", "_repairVeh", "_busy"];
PARAMS_4(_object,_caller,_id,_option);
_veh = vehicle _caller;
_repairVeh = vehicle _object;

if (_veh in [_repairVeh, player]) then {
	_ar1 = (position _repairVeh) nearEntities [["LandVehicle", "Ship"], 15];
	_ar2 = (position _repairVeh) nearEntities ["Air", 20]; // Allow more distance to detect aircraft due to wingspan and size
	
	_ar = _ar1 + _ar2;
	//if (count _ar > 1) then { _veh = _ar select 1 };
	// Submitted fix: Dystopian, 01/28/2013 22:23
	if (count _ar > 1) then { 
		{
			if (_x != _repairVeh) exitWith { _veh = _x };
		} forEach _ar;
	};
};
if (_veh == _repairVeh) exitWith { hint (localize "STR_ACE_REPAIR_ERROR_NOVEHICLENEAR") };
if !(alive _repairVeh) exitWith { hint (localize "STR_ACE_REPAIRVEHBROKEN") };
if (_veh isKindOf "Man") exitWith { hint ((localize "STR_ACE_REPAIR_ERROR_ONLYVEHICLE") + " " + str(_veh)) };

// TODO: Lock the repairVeh too during operations?
_busy = _veh getVariable QGVAR(busy);
if (isNil "_busy") then { _busy = false; _veh setVariable [QGVAR(busy), _busy] };
if (_busy) exitWith { hint (localize "STR_ACE_REPAIR_ERROR_BUSYBEE") };
_veh setVariable [QGVAR(busy), true, true];

switch _option do {
	case "rearm": {
		[_veh, _repairVeh] spawn FUNC(rearm);
	};
	case "repair": {
		[_veh, _repairVeh] spawn FUNC(repair);
	};
	case "refuel": {
		[_veh, _repairVeh] spawn FUNC(refuel);
	};
	default {
		hint ( localize "STR_ACE_REPAIR_ERROR_UNKNOWNACTION" + str(_option));
	};
};

_veh setVariable [QGVAR(busy), false, true];
