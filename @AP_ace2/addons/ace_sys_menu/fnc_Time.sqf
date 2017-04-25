#include "script_component.hpp"
private ["_mod", "_do", "_d", "_mn", "_hr", "_mT"];
_mod = _this select 0; _d = date; _hr = _d select 3; _mn = _d select 4;
if (count _this>1) then { _do = _this select 1 } else { _do = "n" };
if (count _mod>1) then { _mT = true } else { _mT = false };

switch _do do {
	case "up": { _hr = _hr+(_mod select 0);if (_mT) then { _mn = _mn+(_mod select 1) } };
	case "dn": { _hr = _hr-(_mod select 0);if (_mT) then { _mn = _mn-(_mod select 1) } };
	case "n": { _hr = _mod select 0;if (!_mT) then { _mn = 0 } };
};
_d set [3, _hr]; _d set [4, _mn];

["cba_network_date", _d] call CBA_fnc_globalEvent;

hint ("Time set to: "+str(_d));
