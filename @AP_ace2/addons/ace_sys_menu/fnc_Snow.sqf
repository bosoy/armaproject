#include "script_component.hpp"
private ["_mod", "_do"];
PARAMS_1(_mod);
if (count _this>1) then { _do = _this select 1 } else { _do = "n" };
if (isNil "ACE_environment_snow") then { ACE_environment_snow = 0 };

switch _do do {
	case "up": { if (ACE_environment_snow <= (5 - _mod)) then { ACE_environment_snow = ACE_environment_snow + _mod } };
	case "dn": { if (ACE_environment_snow >= _mod) then { ACE_environment_snow = ACE_environment_snow - _mod } };
	case "n": { if ((_mod <= 5) && {(_mod >= 0)}) then { ACE_environment_snow = _mod } };
};

publicVariable "ACE_environment_snow";
hint ("Snow set to: "+str(ACE_environment_snow));
