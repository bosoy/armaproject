#include "script_component.hpp"
#define __short		0.09
#define __medium	0.062
//#define __long		0.05

private ["_obj", "_oZoomMax", "_oZoomMin", "_muzzles", "_muzzle", "_a1", "_a2"];
_obj = (configFile >> "CfgWeapons" >> _this);
if (isArray(_obj >> "muzzles")) then {
	_muzzles = getArray(_obj >> "muzzles");
	if (count _muzzles > 0) then {
		_muzzle = _muzzles select 0;
		if (_muzzle == "this") then {
			_oZoomMax = getNumber(_obj >> "opticsZoomMax");
			_oZoomMin = getNumber(_obj >> "opticsZoomMin");
		} else {
			_oZoomMax = getNumber(_obj >> _muzzle >> "opticsZoomMax");
			_oZoomMin = getNumber(_obj >> _muzzle >> "opticsZoomMin");
		};
	} else {
		_oZoomMax = getNumber(_obj >> "opticsZoomMax");
		_oZoomMin = getNumber(_obj >> "opticsZoomMin");
	};
} else {
	_oZoomMax = getNumber(_obj >> "opticsZoomMax");
	_oZoomMin = getNumber(_obj >> "opticsZoomMin");
};

_a1 = "LONG";
if (true) then {
	if (_oZoomMax > __short) exitWith {
		_a1 = "SHORT";
	};

	if (_oZoomMax > __medium) exitWith {
		_a1 = "MEDIUM";
	};
};

_a2 = "LONG";
if (true) then {
	if (_oZoomMin > __short) exitWith {
		_a2 = "SHORT";
	};

	if (_oZoomMin > __medium) exitWith {
		_a2 = "MEDIUM";
	};
};

if (_a1 == _a2) then {
	[_a1]
} else {
	[_a1, _a2]
};
