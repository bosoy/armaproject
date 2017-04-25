#include "script_component.hpp"
#define __marker "ace_lasertracker"
[
	{ // 0 - laserMarkers
		_laser = objNull;
		while { true } do {
			if (isNull _laser) then {
				_lasers = call FUNC(findLaser);
				_lasersLocal = _lasers select 0;
				if (count _lasersLocal > 0) then {
					_laser = _lasersLocal select 0;
				};
			};
			// Can't use else since _laser might be updated
			if !(isNull _laser) then {
				__marker setMarkerPosLocal (getPos _laser);
				sleep 1;
			} else {
				// Slower refresh speed when no LaserMarker previously found
				sleep 4;
			};
		};
	}
];
