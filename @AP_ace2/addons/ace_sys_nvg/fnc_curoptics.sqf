#include "script_component.hpp"

private ["_vismode","_cfg","_res","_e","_curfov"];
_cfg = _this select 0;
_vismode = if ((_this select 1)==1) then {"NVG"} else {"Ti"};
_res = 0; //0 - NVG + back-up ironsights, 1 - NV/Ti-enabled optics, 2- NVG + optics (will exit scope mode)
_curfov = (call cba_fnc_getfov) select 0;
if (isclass(_cfg>>"opticsmodes")) then {
	for "_i" from 0 to (count(_cfg>>"opticsmodes") -1) do {
		_e = (_cfg>>"opticsmodes") select _i;
		if (isClass _e) then {
			if (getNumber(_e>>"usemodeloptics")==1) then {
				if (0.9*_curfov <= getNumber(_e>>"opticsZoomMax") && {1.1*_curfov >= getNumber(_e>>"opticsZoomMin")}) then {
					if (isArray(_e>>"visionmode")) then {
						_res = if ({_x == _vismode} count (getArray(_e>>"visionmode")) > 0) then {1} else {2};
					} else {
						_res = 2;
					};
				};
			};
		};
	};
} else {
	if (isArray(_cfg>>"visionmode")) then {
		_res = if ({_x == _vismode} count (getArray(_cfg>>"visionmode")) > 0) then {1} else {2};
	} else {
		_res = 2;
	};
};
_res