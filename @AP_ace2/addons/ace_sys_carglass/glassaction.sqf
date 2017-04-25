#include "script_component.hpp"

private ["_v", "_sel"];

_v = _this select 0;
_sel = _this select 3;

_v setHit [_sel, 1];
_v setVariable ["ACE_glass_broken", true, true];
[_v, "ace_break_glass"] call CBA_fnc_globalSay3d;
