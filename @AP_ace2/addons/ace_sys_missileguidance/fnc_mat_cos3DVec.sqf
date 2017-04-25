// _cos = [vector1, vector2] call this_function
//
private ["_v","_v1","_a","_b","_c","_a1","_b1","_c1","_cos","_vm","_v1m"];

_v = _this select 0;
_v1 = _this select 1;

_vm = _v call ACE_fnc_magnitude;
if (_vm == 0) exitwith {2};
_v1m = _v1 call ACE_fnc_magnitude;
if (_v1m == 0) exitwith {2};

_a = _v select 0;
_b = _v select 1;
_c = _v select 2;
_a1 = _v1 select 0;
_b1 = _v1 select 1;
_c1 = _v1 select 2;

_cos = (_a*_a1 + _b*_b1 + _c*_c1)/(_vm*_v1m);

_cos