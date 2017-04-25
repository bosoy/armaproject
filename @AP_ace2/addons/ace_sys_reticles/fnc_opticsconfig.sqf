//return min and max fov for optics and (if present) back-up sight

#include "script_component.hpp"
#define __wcfg configfile>>"cfgweapons">>_wpn

private ["_wpn","_mz","_cfg","_res","_e"];
_wpn = _this select 0;
_mz = _this select 1;
_cfg = if (_mz == _wpn) then {__wcfg} else {__wcfg >> _mz};
_res = [];
if (isclass(_cfg >> "opticsmodes")) then {
	for "_i" from 0 to (count(_cfg >> "opticsmodes") -1) do {
		_e = (_cfg >> "opticsmodes") select _i;
		if (isClass _e) then {
			if (getNumber(_e >> "usemodeloptics")==1) then {
				_res set [0,getNumber(_e >> "opticszoomMin")];
				_res set [1,getNumber(_e>> "opticszoomMax")];
			} else {
				_res set [2,getNumber(_e >> "opticszoomMin")];
				_res set [3,getNumber(_e >> "opticszoomMax")];
			};
		};
	};
} else {
	_res = [getNumber(_cfg >> "opticszoomMin"),getNumber(_cfg >> "opticszoomMax")];
};
_res