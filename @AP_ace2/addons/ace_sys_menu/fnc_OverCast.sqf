#include "script_component.hpp"
private ["_do", "_weather"];
PARAMS_1(_mod);
if (count _this>1) then { _do = _this select 1 } else { _do = "n" };
_weather = [overCast, fog, rain];

switch _do do {
	case "up": { if (overcast <= (1 - _mod)) then { _weather set [0, overcast + _mod] } };
	case "dn": { if (overcast >= _mod) then { _weather set [0, overcast - _mod] } };
	case "n": { if ((_mod <= 1) && {(_mod >= 0)}) then { _weather set [0, _mod] } };
};

["cba_network_weather", _weather] call CBA_fnc_globalEvent;
hint ("Overcast set to: "+str(_weather select 0));
