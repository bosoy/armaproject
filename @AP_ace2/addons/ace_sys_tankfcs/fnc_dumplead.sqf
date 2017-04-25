// set lead angle to 0 for all ammo types, conserving elevation settings

#include "script_component.hpp"

#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh

private ["_fired","_c","_veh","_offset"];

_veh = vehicle player;
_fired = _veh getvariable "ace_tankfcs_fired";
if(isNil "_fired")exitWith{};

_c = [];

_offset = _veh getvariable "ace_tankfcs_boreoffsetangleh";

for "_i" from 1 to (count _fired) - 1 step 2 do {
	_c = _fired select _i;
	_c set [0,_offset];	//setting lead angle to zero
	_fired set [_i,_c];
};

_veh setvariable ["ace_tankfcs_fired",_fired];