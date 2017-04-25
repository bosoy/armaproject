#include "script_component.hpp"

#define __MG_CFG configFile >> "CfgVehicles" >> (typeOf _MG)

private ["_unit","_actor","_statics","_tripod","_tripodType","_MG", "_newNumber"];

if (count _this == 1) then {
	call (_this select 0);
	_MG	= ACE_MG;
	ACE_MG = nil;
	_unit  = player;
	_actor = player;
} else {
	_unit  = _this select 0;
	_actor = _this select 1;
	_MG = nearestObject [_unit, "StaticWeapon"];
};

if (_unit != _actor) exitWith {};
if !(isPlayer _unit) then { _unit moveTo (getPos _MG); };

// get animationphase // TODO: Need an ACE standard animationsource thing!!
_number = _MG animationPhase "slide_down_tripod";
if (_number == 0) then {
	_newNumber = 1;
} else {
	_newNumber = 0;
};
{ _MG animate [_x,_newNumber] } foreach ["slide_down_tripod","retract_leg_1","retract_leg_2","retract_leg_3"];