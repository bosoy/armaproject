// #include "script_component.hpp"

// private ["_unit", "_healer", "_healercanheal"];
// PARAMS_3(_unit,_healer,_healercanheal);

// TRACE_3(_unit,_healer,_healercanheal);

// _unit = _this select 0;
// _healer = _this select 1;
// _healercanheal = _this select 2;

if (isNil "ace_sys_wounds_enabled") exitWith {false};

// disables magic healing completely!
true
