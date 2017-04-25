#include "script_component.hpp"
private ["_mod", "_do", "_vd", "_err"];
_mod = _this select 0; _err = false; _vd = 0;
if (count _this>1) then { _do = _this select 1 } else { _do = "" };
if (_do == "") then {
	_vd = _mod;
} else {
	if (isNil "SIX_LOCAL_VD") then {
		_err = true;hint "Cannot modify viewdistance before you first set a start viewdistance!";
	} else {
		switch _do do {
			case "up": { _vd = SIX_LOCAL_VD+_mod };
			case "dn": { _vd = SIX_LOCAL_VD-_mod };
		};
	};
};
if (_vd<1) then { _err = true;hint "Cannot modify viewdistance at or below 0!" };
if (!_err) then {
	setViewDistance _vd;SIX_LOCAL_VD = _vd;
	hint ("Viewdistance set to: "+str(_vd));
};
