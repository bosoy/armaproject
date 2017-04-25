//crew abandoning vehicle

#include "script_component.hpp"

private "_crew";
sleep (random 12);
if (! alive _this) exitwith {};
(vehicle _this) allowCrewInImmobile false;
_crew = crew _this;
if (count _crew == 0) exitwith {};
_crew = _crew - [player];
#ifdef DEBUG_MODE_FXONLY
	[format["Crew abandoning %1",_this]] call CBA_fnc_debug;
#endif
{
	if !(_x call ace_sys_wounds_fnc_isUncon) then {
		unassignvehicle _x;
		_x leavevehicle _this;
		_center = getPosASL _x;
		_center_x = _center select 0;_center_y = _center select 1;
		_angle = floor (random 360);
		_dist = (30 + (random 10));
		_x1 = _center_x + (_dist * sin _angle);
		_y1 = _center_y + (_dist * cos _angle);
		_x doMove [_x1, _y1, 0];
		_x setSpeedMode "FULL";
		//_x allowfleeing (random 0.7);
	};
} foreach _crew;

//_crew allowgetin false;
//_crew ordergetin false;

//waituntil {count (crew _this) == 0};
//sleep 3;
//_this spawn FUNC(set_ko);