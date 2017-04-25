#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

#define __pt(value) (_unit getvariable ##value)

/*

0: injured [Object]
1: part hit [String]
2: new overall part damage [Number]
3: injurer [Object]
4: class of ammo causing the damage [String]

*/

private["_v","_wh","_type","_max","_ex","_p","_armor","_partarmor","_unitarmor","_prevdamage","_newpartdamage","_newpartdamage1","_s","_hit","_t","_dparts","_anim"];
PARAMS_5(_unit,_part,_partdamage,_injurer,_ammo);
if !(alive _unit) exitwith {_unit removealleventhandlers "handledamage"};

if (_part != "") then
{
	//if (0.001 > (_unit getvariable "ace_overalldamage")) exitwith {};
	if (_unit getvariable "ace_ignorehit") exitwith {};
	_wh = true;
	_p = __unitcfg;
	_part = tolower _part;
	switch(_part) do {
		case __pt("ace_name_engine"): {_s = "HitEngine";_type = "engine"};
		case __pt("ace_name_hull"): {_s = "HitHull";_type = "hull"};
		case __pt("ace_name_fuel"): {_s = "HitFuel";_type = "fuel"};
		case __pt("ace_name_avionics"): {_s = "hitavionics";_type = "avionics"};
		case __pt("ace_name_hrotor"): {_s = "hithrotor";_type = "hrotor"};
		case __pt("ace_name_vrotor"): {_s = "hitvrotor";_type = "vrotor"};
		case __pt("ace_name_turret"): {_s = "HitTurret";_type = "turret";_p = _p >> "Turrets" >> "MainTurret"};
		case __pt("ace_name_gun"): {_s = "HitGun";_type = "gun";_p = _p >> "Turrets" >> "MainTurret"};
		default  {_unit setHit [_part,_partdamage];_s = "exit"};
	};
	if (_s == "exit") exitwith {};	// irrelevant selections

	//finding damage received, setting it into the array of part damages for the current hit (ace_dparts)
	_prevdamage = _unit getvariable ("ace_damage_"+_type);
	_newpartdamage1 = _partdamage - _prevdamage;
	if (_newpartdamage1 < 0) then
	{ 	//veh was repaired
		_unit setvariable [("ace_damage_"+_type),0,!_wh];
		_newpartdamage1 = _partdamage;
	};

	_partarmor = getNumber (_p >> "hitpoints" >> _s >> "armor");
	_armor = getNumber (__unitcfg >> "armor");
	_newpartdamage = _newpartdamage1*_partarmor*_armor; //pure hit received by selection

	if (_newpartdamage > 0) then {
		_wh = _unit getvariable "ace_d_parts";
		_wh set [(count _wh),[_type,_newpartdamage,_partdamage]];
		_unit setvariable ["ace_d_parts",_wh];
	};
#ifdef DEBUG_MODE_FULL1
	[format ["HandleDamage part %1 type %5 dmg %2 newdmg %3 d_part %4",_part,_partdamage,_newpartdamage,_wh,_type]] call CBA_fnc_debug;
#endif

} else { // ** first triggering of the EH

	//new damage received
	_newpartdamage = _partdamage - (damage _unit);
	_ex = false;
	if (_newpartdamage >= 0 /*0.001*/) then
	{	//ignore small hits/false/double triggering

		//several triggerings at 1 hit
		_s = _unit getvariable "ace_hittime";
		if (isNil "_s") then {
			_unit setvariable ["ace_hittime",[time,_injurer]];
			_unit setvariable ["ace_ignorehit",false]

		} else {
			if (time == (_s select 0) && {_injurer == (_s select 1)}) then
			{
				_unit setvariable ["ace_ignorehit",true];
			} else {
				_unit setvariable ["ace_ignorehit",false];
				_unit setvariable ["ace_hittime",[time,_injurer]];
			};
		};
		//[format ["HandleDamage: unit %1 injurer %2 ht %3 ignore %4",_unit,_injurer,(_unit getvariable "ace_hittime"),(_unit getvariable "ace_ignorehit")]] call CBA_fnc_debug;

		if (_unit getvariable "ace_ignorehit") exitwith {_ex = true};
		_unit setvariable ["ace_overalldamage",_newpartdamage];
		//initializing damage vars
		_unit setvariable ["ace_d_parts",[]];
		_unit setvariable ["ace_hitpart",["",_newpartdamage]];
		_s = _unit getvariable "ace_damage_engine";
		if (isNil "_s") then {
			_s = damage _unit;
			//variables to later store damage set with 'sethit' as there's no 'gethit' :-)
			//_unit setvariable ["ace_damage_general",_s,true];
			_unit setvariable ["ace_damage_engine",_s,true];
			_unit setvariable ["ace_damage_hull",_s,true];
			_unit setvariable ["ace_damage_fuel",_s,true];
			_unit setvariable ["ace_damage_turret",_s,true];
			_unit setvariable ["ace_damage_gun",_s,true];

			_unit setvariable ["ace_damage_avionics",_s,true];
			_unit setvariable ["ace_damage_vrotor",_s,true];
			_unit setvariable ["ace_damage_hrotor",_s,true];

			//vehicle capabilities vars
			_unit setvariable ["ace_canmove",true,true];
			_unit setvariable ["ace_canshoot",true,true];

			//is on fire
			_unit setvariable ["ace_onfire",false,true];
		};

		//processing function should start after all parts processed
		if (_ex) exitwith {};

		//_s = _this spawn FUNC(heli_setfx);

#ifdef DEBUG_MODE_FULL1
		[format ["HandleDamage: part %1 dmg %2 this %3 local %4",_part,_newpartdamage,_this,(local _unit)]] call CBA_fnc_debug;
#endif
	};
};
false