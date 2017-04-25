#include "script_component.hpp"

#define VEH_TYPES "AllVehicles", "HouseBase", "Strategic", "Structure"
#define DISTANCE 12

private "_nearMedicFacility";
PARAMS_1(_unit);

_nearMedicFacility = false;

if (isNull _unit) then {
	TRACE_1("Null Unit!",_unit);
} else {
	{ if ([_x] call FUNC(isMedicalFacility)) exitWith { _nearMedicFacility = true; } } forEach nearestObjects [_unit, [VEH_TYPES], DISTANCE];
};

_nearMedicFacility;
