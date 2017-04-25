// takes: unit,part type(engine,hull etc),damage to add, damage cap, setvar for mp or not
// finds needed selection name, adds damage, caps it at _cap, sets damage var
// will not add damage if part is already damaged beyond _cap

#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo


PARAMS_5(_unit,_part,_hit,_cap,_mp);
private ["_name","_var","_mp","_pdamage"];
//[format["AddHit args %1",_this]] call CBA_fnc_debug;

_name = [_unit,_part] call FUNC(getpartname);	//selection name

_var = "ace_damage_"+_part;
_pdamage = _unit getvariable _var;
if (_pdamage >= _cap) exitwith {};
_hit = (_hit + _pdamage) min _cap;

_unit sethit[_name,_hit];
_unit setvariable [_var,_hit,_mp];