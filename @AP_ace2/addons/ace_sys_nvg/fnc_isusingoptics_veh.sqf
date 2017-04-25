//return true if currently looking through optics, false if ironsights

#include "script_component.hpp"
#define __vcfg configfile>>"cfgvehicles">>typeof _veh

private ["_curfov","_veh","_cfg","_res","_t","_turret","_vismode"];
_veh = _this select 0;
_turret = _this select 1;
_vismode = if ((_this select 2)==1) then {"NVG"} else {"Ti"};
_res = "";
_curfov = (call cba_fnc_getfov) select 0;
if (count _turret == 0) exitwith {false};
_t = [_veh,_turret] call CBA_fnc_getTurret;
if (isClass(_t>>"opticsin")) then {
	_t = _t>>"opticsIn";
	for "_i" from 0 to (count _t - 1) do {
		if (isClass (_t select _i)) then {
			if (0.9*_curfov <= getNumber((_t select _i)>>"maxfov") && {1.1*_curfov >= getNumber((_t select _i)>>"minfov")}) then {
				if ({_x == _vismode} count (getArray((_t select _i)>>"visionmode")) > 0) then {
					_res = getText((_t select _i)>>"gunnerOpticsModel");
				};
			};
		};
	};
} else {
	if (isClass(_t>>"viewoptics")) then {
		if (0.9*_curfov <= getNumber(_t>>"viewoptics">>"maxfov") && {1.1*_curfov >= getNumber(_t>>"viewoptics">>"minfov")}) then {
			if ({_x == _vismode} count (getArray(_t>>"viewoptics">>"visionmode")) > 0) then {
				_res = getText(_t>>"gunnerOpticsModel");
			};
		};
	};
};
_res = if ({_x==_res} count ["","-","\ca\weapons\optika_empty"] > 0) then {false} else {true};
_res