#include "script_component.hpp"

private ["_lifeboat","_ir","_kn"];
_lifeboat = _this;
{ moveOut _x } foreach (crew _lifeboat);
_lifeboat lock true;
_lifeboat setVariable [QGVAR(deflate),true,true];
[_lifeboat, 300] call ACE_fnc_add2clean;
