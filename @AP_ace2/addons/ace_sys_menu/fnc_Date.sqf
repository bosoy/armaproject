#include "script_component.hpp"
private ["_mod", "_do", "_d", "_day", "_month", "_mT"];
_mod = _this select 0; _d = date; _month = _d select 1; _day = _d select 2;
if (count _this>1) then { _do = _this select 1 } else { _do = "n" };
if (count _mod>1) then { _mT = true } else { _mT = false };

switch _do do {
	case "up": { _month = _month+(_mod select 0);if (_mT) then { _day = _day+(_mod select 1) } };
	case "dn": { _month = _month-(_mod select 0);if (_mT) then { _day = _day-(_mod select 1) } };
	case "n": { _month = _mod select 0;if (!_mT) then { _day = 0 } };
};
_d set [1, _month]; _d set [2, _day];

["cba_network_date", _d] call CBA_fnc_globalEvent;

hint ("Date set to: "+str(_d));
