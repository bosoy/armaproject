#include "script_component.hpp"
private ["_do", "_weather"];
PARAMS_1(_mod);
if (count _this>1) then { _do = _this select 1 } else { _do = "n" };
_weather = [overCast, fog, rain];

switch _do do {
	case "up": { if (rain <= (1 - _mod)) then { _weather set [2, rain + _mod] } };
	case "dn": { if (rain >= _mod) then { _weather set [2, rain - _mod] } };
	case "n": { if ((_mod <= 1) && {(_mod >= 0)}) then { _weather set [2, _mod] } };
};

["cba_network_weather", _weather] call CBA_fnc_globalEvent;
hint ("Rain set to: "+str(_weather select 2));
