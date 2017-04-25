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

private["_ignhit","_as","_wh","_type","_max","_ex","_p","_armor","_partarmor","_unitarmor","_prevdamage","_newpartdamage","_newpartdamage1","_s","_hit","_t","_dparts","_anim"];
PARAMS_5(_unit,_part,_partdamage,_injurer,_ammo);
if !(alive _unit) exitwith {
	_hdehv = _unit getVariable QGVAR(hdeh);
	if (!isNil "_hdehv") then {_unit removeEventHandler ["handleDamage", _hdehv]};
	false
};
if (_ammo == "") exitwith {
	_p = getpos _unit;
	if (surfaceiswater [_p select 0,_p select 1] && {(_p select 2) < -2.5}) then {_unit setfuel 0;true} else {false};
};	//underwater damageif (! alive _unit) exitwith {false};
//if (_unit == _injurer && _partdamage < 0.07) exitwith {}; //sometimes triggers out of the blue
if (getNumber(__ammocfg >> "ace_aa") == 1) exitwith {false};

if (_part != "") then {
	//if (0.001 > (_unit getvariable "ace_overalldamage")) exitwith {};
	//if (_unit getvariable "ace_ignorehit") exitwith {};
	_ignhit = (_unit getvariable "ace_ignorehit");
	_wh = true;
	_p = __unitcfg;
	_part = tolower _part;
	switch(_part) do {
		case __pt("ace_name_engine"): {_s = "HitEngine";_type = "engine";_wh = false};
		case __pt("ace_name_hull"): {_s = "HitHull";_type = "hull";_wh = false};
		case __pt("ace_name_fuel"): {_s = "HitFuel";_type = "fuel";_wh = false};
		case __pt("ace_name_lfwheel"): {_s = "hitlfwheel";_type = "lfwheel"};
		case __pt("ace_name_rfwheel"): {_s = "hitrfwheel";_type = "rfwheel"};
		case __pt("ace_name_lf2wheel"): {_s = "hitlf2wheel";_type = "lf2wheel"};
		case __pt("ace_name_rf2wheel"): {_s = "hitrf2wheel";_type = "rf2wheel"};
		case __pt("ace_name_lmwheel"): {_s = "hitlmwheel";_type = "lmwheel"};
		case __pt("ace_name_rmwheel"): {_s = "hitrmwheel";_type = "rmwheel"};
		case __pt("ace_name_lbwheel"): {_s = "hitlbwheel";_type = "lbwheel"};
		case __pt("ace_name_rbwheel"): {_s = "hitrbwheel";_type = "rbwheel"};
		case __pt("ace_name_turret"): {_s = "HitTurret";_type = "turret";_p = _p >> "Turrets" >> "MainTurret";_wh = false};
		case __pt("ace_name_gun"): {_s = "exit"};//{_s = "HitGun";_type = "gun";_p = _p >> "Turrets" >> "MainTurret";_wh = false};
		default  {_unit setHit [_part,_partdamage];_s = "exit"};
	};
	if (_s == "exit") exitwith {};	// irrelevant selections

	//finding damage received, setting it into the array of part damages for the current hit (ace_dparts)
	_prevdamage = _unit getvariable ("ace_damage_"+_type);
	_newpartdamage1 = _partdamage - _prevdamage;
	if (_newpartdamage1 < 0) then {
	 	//veh was repaired
		_unit setvariable [("ace_damage_"+_type),0,!_wh];
		_newpartdamage1 = _partdamage;
	};

	_partarmor = getNumber (_p >> "hitpoints" >> _s >> "armor");
	_armor = getNumber (__unitcfg >> "armor");
	_newpartdamage = _newpartdamage1*_partarmor*_armor; //pure hit received by selection

	//arrays of wheel damages/hard part damages
	if (_wh) then {
		if !(_ignhit) then {
			_wh = _unit getvariable "ace_d_wheels";
			_wh set [(count _wh),[_type,_newpartdamage,_partdamage,_newpartdamage1]];
			_unit setvariable ["ace_d_wheels",_wh];
		};
	} else {
		if (_newpartdamage > 0) then {
			_wh = _unit getvariable "ace_d_parts";
			if (_ignhit || {_type == "hull"}) then  //the "" part set hull damage already. for multiple triggering from 1 round accumulate damage
			{
				private ["_cur","_set"];
				_set = false;
				for "_i" from 0 to (count _wh) - 1 do {
					_cur = _wh select _i;
					if (_type == (_cur select 0)) exitwith {
						_wh set [_i,[_type,(_cur select 1)+_newpartdamage,(_cur select 2)+_partdamage]];
						_set = true;
					};
				};
				if !(_set) then {_wh set [count _wh,[_type,_newpartdamage,_partdamage]]};
			} else {
				_wh set [count _wh,[_type,_newpartdamage,_partdamage]];
			};
			_unit setvariable ["ace_d_parts",_wh];
		};
	};
#ifdef DEBUG_MODE_FULL1
	[format ["HandleDamage part %1 type %5 dmg %2 newdmg %3 d_part %4",_part,_partdamage,_newpartdamage,_wh,_type]] call CBA_fnc_debug;
#endif

} else { // ** first triggering of the EH
	//new damage received
	_newpartdamage = _partdamage - (damage _unit);
	if (_newpartdamage >= 20) exitwith {
		[_unit] call FUNC(killcrew);
		_unit setdamage 1;
	#ifdef DEBUG_MODE_FULL1
		[format ["%1 is killed immediately, damage ( %2 ) too high",_unit,_newpartdamage]] call CBA_fnc_debug;
	#endif
	};

	_ex = false;
	if (_newpartdamage >= 0 /*0.001*/) then
	{	//ignore small hits/false/double triggering

		//several triggerings at 1 hit
		_s = _unit getvariable "ace_hittime";
		if (isNil "_s") then {
			_unit setvariable ["ace_hittime",[time,_injurer]];
			_unit setvariable ["ace_ignorehit",false]

		} else {
			//_p = if (_unit isKindOf "T90") then {0.025} else {0}; //f.up t90 model
			if (time <= (_s select 0)+0.03 && {_injurer == (_s select 1)}) then {
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
		
		_armor = getNumber (__unitcfg >> "armor");
		//_as = getNumber (__unitcfg >> "armorstructural");
		_unit setvariable ["ace_d_parts",[["hull",_newpartdamage*_armor,_newpartdamage]]]; //incase further parts don't trigger
		_unit setvariable ["ace_hitpart",["",_newpartdamage]];
		_unit setvariable ["ace_d_wheels",[]];
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

			//dont MP sync wheels - too much data
			_unit setvariable ["ace_damage_lfwheel",_s];
			_unit setvariable ["ace_damage_rfwheel",_s];
			_unit setvariable ["ace_damage_lf2wheel",_s];
			_unit setvariable ["ace_damage_rf2wheel",_s];
			_unit setvariable ["ace_damage_lmwheel",_s];
			_unit setvariable ["ace_damage_rmwheel",_s];
			_unit setvariable ["ace_damage_lbwheel",_s];
			_unit setvariable ["ace_damage_rbwheel",_s];

			//vehicle capabilities vars
			_unit setvariable ["ace_canmove",true,true];
			_unit setvariable ["ace_canshoot",true,true];

			//is on fire
			_unit setvariable ["ace_onfire",false,true];

			//is knocked out
			_unit setvariable ["ace_ko",false,true];
		};

		//processing function should start after all parts processed
		//if (_unit getvariable "ace_ko") exitwith {};
		if (_ex) exitwith {};

		_this spawn FUNC(wapc_setfx);

#ifdef DEBUG_MODE_FULL1
		[format ["HandleDamage: part %1 dmg %2 this %3 local %4",_part,_newpartdamage,_this,(local _unit)]] call CBA_fnc_debug;
#endif
	};
};
false