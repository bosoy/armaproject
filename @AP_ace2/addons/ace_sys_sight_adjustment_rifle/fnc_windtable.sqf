#include "script_component.hpp"
//processes the drift table from [distance(m), drift(m)] to [distance(m), drift(mil/moa)] format
#include "Script_SightAdjustmentConfig.hpp"

private ["_t","_angle","_w","_d","_x"];

_t = _this select 0;
for "_i" from 0 to (count _t - 1) do {
	_x = _t select _i;
	if ((_x select 0) != 0) then {
		_d = _x select 0; //distance, meters
		_w = _x select 1;	//drift, meters
		_angle = 1000*_w/_d; //drift, mil
		if (ACE_SYS_SA_RFL_WCFG_WINDAGE_UNITS == "moa") then {
			_angle = 3.4377*_angle;
		};
		_angle = [_angle,0.1] call FUNC(roundNumber);
		_t set [_i,[(_t select _i) select 0,_angle]];
	};
};
_t
