#include "script_component.hpp"
private ["_mod", "_do"];
PARAMS_1(_mod);
if (count _this>1) then { _do = _this select 1 } else { _do = "n" };
if (isNil "math_snowDensity") then { math_snowDensity = 0 };
if (isNil "math_snow") then { math_snow = false };

switch _do do {
	case "up": { if (math_snowDensity <= (10 - _mod)) then { math_snowDensity = math_snowDensity + _mod } };
	case "dn": { if (math_snowDensity >= _mod) then { math_snowDensity = math_snowDensity - _mod } };
	case "n": { if ((_mod <= 10) && {(_mod >= 0)}) then { math_snowDensity = _mod; } };
};

if (math_snow) then {
	if (math_snowDensity == 0) then { math_snow = false; publicVariable "math_snow" };
} else {
	if (math_snowDensity > 0) then { math_snow = true; publicVariable "math_snow" };
};
publicVariable "math_snowDensity";
hint ("Snow set to: "+str(math_snowDensity));
