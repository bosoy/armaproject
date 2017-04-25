// by Xeno
#define THIS_FILE "x_dismissai.sqf"
#include "x_setup.sqf"

_units_player = units (group player);

if ((_units_player call FUNC(GetAliveUnits)) > 0) then {
	_has_ai = false;
	{
		if (!isPlayer _x) then {
			_has_ai = true;
			_x removeAllEventHandlers "killed";
			if (vehicle _x == _x) then {
				deleteVehicle _x;
			} else {
				moveOut _x;
				waitUntil {sleep 0.123;vehicle _x == _x};
				deleteVehicle _x;
			};
		};
	} forEach _units_player;
	if (_has_ai) then {(localize "STR_DOM_MISSIONSTRING_216") call FUNC(HQChat)};
};

GVAR(current_ai_num) = 0;