// _cos = [vector1, vector2] call this_function
//
#define __a0  (_v select 0)
#define __b0  (_v select 1)
#define __c0  (_v select 2)
#define __a1  (_v1 select 0)
#define __b1  (_v1 select 1)
#define __c1  (_v1 select 2)

private ["_v","_v1","_vmag","_v1mag"];

_v = _this select 0;
_vmag = _v call ACE_fnc_magnitude;
if (_vmag == 0) exitWith {2};
_v1 = _this select 1;
_v1mag = _v1 call ACE_fnc_magnitude;
if (_v1mag == 0) exitWith {2};

(__a0*__a1 + __b0*__b1 + __c0*__c1)/(_vmag*_v1mag)
