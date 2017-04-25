#include "script_component.hpp"
private ["_mod", "_do", "_d", "_year"];
_mod = _this select 0; _d = date; _year = _d select 0;
if (count _this>1) then { _do = _this select 1 } else { _do = "n" };

switch _do do {
	case "up": { _year = _year+(_mod select 0) };
	case "dn": { _year = _year-(_mod select 0) };
	case "n": { _year = _mod select 0 };
};
_d set [0, _year];

["cba_network_date", _d] call CBA_fnc_globalEvent;

hint ("Date set to: "+str(_d));
