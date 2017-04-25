// by Xeno
//#define __DEBUG__
#define THIS_FILE "secondaryloop.sqf"
#include "x_setup.sqf"

private ["_v", "_data", "_list", "_curidx"];

while {true} do {
	waitUntil {sleep 0.412; count GVAR(BISsecondaries) > 0};
	{
		_v = _x select 0;
		_data = _x select 1;
		__TRACE_2("","_forEachIndex","_x");
		__TRACE_2("","_v","_data");
		
		if (((_data select 0) && alive _v) || isNull _v || ((getPosASL _v) select 2) < 0) then {
			GVAR(BISsecondaries) set [_forEachIndex, -1];
		} else {
			_list = _data select 1;
			_curidx = _data select 2;
			if (time >= _list select _curidx) then {
				"SmallSecondary" createVehicle (_v modelToWorld (_data select 3));
				__INC(_curidx);
				if (_curidx == count _list) then {
					GVAR(BISsecondaries) set [_forEachIndex, -1];
				} else {
					_data set [2, _curidx];
				};
			};
		};
	} forEach GVAR(BISsecondaries);
	GVAR(BISsecondaries) = GVAR(BISsecondaries) - [-1];
	sleep 1.316;
};