//figure out hit part for wheeled vehicles based on selections' damages
//deal with wheels damage

#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

#define __whthreshold 0.2

private["_heat","_hit","_fuel","_mh","_abort","_expl","_mp","_mw","_eng","_hull","_wh","_t","_part","_dmg"];
PARAMS_5(_unit,_part,_partdamage,_injurer,_ammo);
if (! alive _unit) exitwith {};

_wh = _unit getvariable "ace_d_wheels";
_t = _unit getvariable "ace_d_parts";
_mp = ["",0,0];
_mw = ["",0,0];
_eng = 0;	//engine damage
_hull = 0;	//hull damage
_fuel = 0;	//turret damage
_abort = true;
_dmg = 0;

_mh = getArray(__unitcfg >> "ace_minimalhit");

{ // _mw - wheel with max damage and its damage
	if ((_x select 1) > (_mw select 1)) then {_mw = _x};

} foreach _wh;


{ // _mp - hard part with max damage and its damage
	if ((_x select 1) > (_mp select 1)) then {_mp = _x};
	switch (_x select 0) do {
		case "engine": {_eng = _x select 1};
		case "hull": {_hull = _x select 1};
		case "palivo": {_fuel = _x select 1};
		default {};
	};

} foreach _t;

if ((_mp select 1) >= (_mw select 1)) then {
	_part = _mp select 0;
	_dmg = _mp select 1;
	if (_part == "fuel") then {_part = "hull"};

} else { // if wheels have max damage, then hull is hit - decide which part
	if (_eng > (_hull max _fuel)) then {
		_part = "engine";
		//_dmg = _eng;
	} else {
		_part = "hull";
		//_dmg = _hull;
	};
	_dmg = _mp select 1;
};
if (_dmg > 0 || {0.7 > (random 1)}) then {_abort = false};

//setting wheels damage - only 1 at a time if KE and all if HE
if ((_mw select 1) > 0) then {
	_expl = getNumber(__ammocfg >> "explosive");
	_heat = getNumber(__ammocfg >> "ace_heat");
	if (_expl <= 0.1) then {
		_hit = if (isNumber(__ammocfg >> "ace_hit")) then {getNumber(__ammocfg >> "ace_hit")} else {getNumber(__ammocfg >> "hit")};
		if (_hit >= 11/*0.5*(_mh select 0)*/) then
		{
			[_unit,_mw select 0,0.2*_hit/(_mh select 0),(0.94 max _hit/100) min 1,false] call FUNC(addhit);
		};
	} else {
		if (_heat == 1 && {(_ammo isKindOf "RocketBase" || {_ammo isKindOf "MissileBase"})}) then	//HEAT hit - no more than 1 wheel damaged
		{
			if ((_mw select 1) >= 0.8*(_mh select 1)) then {
				[_unit,_mw select 0,_mw select 2,false] call FUNC(sethit);
			};
		} else {	//HE hit
			{
				if ((_x select 1) >= 0.4*(_mh select 1)) then {
					if ((_x select 1) >= 0.8*(_mw select 1)) then {
						[_unit,_x select 0,(_x select 2),false] call FUNC(sethit);
					};
				};
			} foreach _wh;
		};
	};
};
[_part,_dmg,_abort]