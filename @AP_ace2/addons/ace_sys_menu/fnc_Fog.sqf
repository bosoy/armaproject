#include "script_component.hpp"
private ["_do", "_weather"];
PARAMS_1(_mod);
if (count _this>1) then { _do = _this select 1 } else { _do = "n" };
_weather = [overCast, fog, rain];

switch _do do {
	case "up": { if (fog <= (1 - _mod)) then { _weather set [1, fog + _mod] } };
	case "dn": { if (fog >= _mod) then { _weather set [1, fog - _mod] } };
	case "n": { if ((_mod <= 1) && {(_mod >= 0)}) then { _weather set [1, _mod] } };
};

["cba_network_weather", _weather] call CBA_fnc_globalEvent;
hint ("Fog set to: "+str(_weather select 1));
