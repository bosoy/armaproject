//automatically gives RF battery and loads it for all players
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);

#define __rangefinders ["ACE_Rangefinder_OD","Binocular_Vector","ACE_YardAge450"]
private["_hasvector","_vector"];

_hasvector = false;
{if (_unit hasWeapon _x) exitWith {_hasvector = true; _vector = _x}} forEach __rangefinders;

if (_hasvector) then {
	if !("ACE_Battery_Rangefinder" in magazines _unit) then {_unit addMagazine "ACE_Battery_Rangefinder"};
	if (isPlayer _unit) then {[_unit, _vector] call FUNC(chgBat)};
};
