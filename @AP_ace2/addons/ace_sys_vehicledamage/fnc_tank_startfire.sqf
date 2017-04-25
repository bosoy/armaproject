#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo


private["_tti","_type","_offset","_logic","_varname","_ex","_s","_intensity","_time_to_detonate","_time_to_injure","_p","_damage"];
PARAMS_5(_unit,_part,_partdamage,_injurer,_ammo);
if (! alive _unit) exitwith {};

_ex = false;
_s = _unit getvariable "ace_onfire";

if (! _s) then {
	// _unit setvariable ["ace_onfire",true,true];
	[_unit, "ace_onfire", true] call FUNC(setVar);
} else {
	_ex = true;
};
if (_ex) exitwith {/*["Fire aborting, already burning"] call CBA_fnc_debug */ };

#ifdef DEBUG_MODE_FULL1
["Fire starting"] call CBA_fnc_debug;
#endif

if (5 > random 10) then {
	_intensity = 0.5 + random 0.4;
	_s = random 0.5; //intensity gain/fade (+/-) per 3 seconds
} else {
	_intensity = 1 + random 5;
	_s = random 0.3; //intensity gain/fade (+/-) per 3 seconds

};
//coords offset for fire, and tti (time to injure) modifier
switch (_part) do {
	case "engine": {
		_p = getArray(__unitcfg >> "ace_firepos");
		_offset = [(_p select 0)-0.25 + random 0.5,(_p select 1)-0.25 + random 0.5,(_p select 2)-0.25 + random 0.5];
		_tti = 2;
	};
	case "hull": {_offset = [-0.8 + random 1.6,-2.2 + random 3.5,-1.2 + random 0.2];_tti = 1};
	default {_offset = [-0.4 + random 0.8,-0.6 + random 0.4,-0.1+ random 0.2];_tti = 1};
};
_time_to_detonate = 305 min (5 + (random 200)/(_intensity));
TRACE_1("Time to detonate",_time_to_detonate);
// AI crew will be forced to abandon tank after this time, player will get indication too
// after ~10 seconds kill everybody still inside
_time_to_injure = 305 min _tti*(5 + (random 100)/(10*_intensity));


_type = typeOf _unit;

//burning object attached to vehicle
_logic = "ACE_LogicDummy" createvehicle (getpos _unit);
[QGVAR(burn), [_logic,_intensity,time,false,true,_s,_type,_time_to_detonate+180]] call CBA_fnc_globalEvent;
_logic attachto [_unit,_offset]; //attachto selection doesnt work

//loop tracking fire damage to crew/vehicle on all machines
[QGVAR(fire), [_unit, _part,_intensity,_time_to_detonate,_time_to_injure,time]] call CBA_fnc_globalEvent;

//crew bails out immediately, unless they're not aware or decide to keep fighting
if (5 > random 10) then {
	_unit spawn FUNC(tank_abandon);
};
