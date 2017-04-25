//track fire effect on vehicle/crew


#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

#ifdef DEBUG_MODE_FULL1
	[format["Fire loop starting (vh,pt,int,det,inj,t) %1",_this]] call CBA_fnc_debug;
#endif

private["_txt","_t","_dp","_step","_i","_s","_dp","_ex"];
PARAMS_6(_unit,_part,_intensity,_time_to_detonate,_time_to_injure,_starttime);
if (! alive _unit) exitwith {};

_t = 0;
_step = 5;
//detonation probability
_dp = getNumber (__unitcfg>>"ace_p_firedetonation");
_ex = false;

while {!_ex && {alive _unit}} do {
	_t = time - _starttime;

	//force crew out and kill ppl in after some time
	if (_t >= _time_to_injure) then {
		if ({alive _x} count (crew _unit) > 0) then {
			if (local _unit) then {_unit spawn FUNC(tank_abandon)};
			if (_t >= _time_to_injure + 10) then {
				[_unit] call FUNC(killcrew);
				//["Fire killed all inside"] call CBA_fnc_debug;
				if (local _unit) then {	_unit spawn FUNC(set_ko) };
			};
		};
	} else {
		if (player in _unit) then {
			//_txt = if (_part == "engine") then {"engine"} else {"crew"};
			//hint format ["Fire in %1 compartment!",_txt];
			[_unit] call FUNC(burnindicator);
		};
	};

	//detonate ammo/fuel
	if (_t >= _time_to_detonate) then {
		if (local _unit) then {
			if (_dp < random 1) then
			{	//no big splosion
				_unit setfuel 0;
				_unit setvehicleammo 0;
				_unit setdamage 1;
			} else {
				_unit setfuel (0.5 + random 0.5);
				_unit setvehicleammo (0.5 + random 0.5);
				[_unit,_part] call FUNC(detonate);
			};
			[_unit] call FUNC(killcrew);
		#ifdef DEBUG_MODE_FULL1
			["Fire destroyed the tank"] call CBA_fnc_debug;
		#endif
		};
	};

	sleep _step;
};
// if (local _unit) then {clearvehicleinit _unit}; //clearVehicleInit is useless