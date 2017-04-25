// takes: unit,part type(engine,hull etc),damage to set, (optional) setvar for mp or not
// by default mp = true
// finds needed selection name, sets damage, caps it at 1, sets damage var

#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo


PARAMS_3(_unit,_part,_hit);
private ["_name","_var","_mp"];
//[format["SetHit args %1",_this]] call CBA_fnc_debug;

_name = [_unit,_part] call FUNC(getpartname);	//selection name

_var = "ace_damage_"+_part;
if (_hit > 1) then {_hit = 1};
_unit sethit[_name,_hit];
if ((_unit getvariable _var) == _hit) exitwith {};

if (count _this == 4) then {
	_mp = _this select 3;
	_unit setvariable [_var,_hit,_mp];
} else {
	_unit setvariable [_var,_hit,true];
};