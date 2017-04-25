#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

//damage tresholds
// 0..1 format
#define __threshold_turret 0.1
#define __threshold_engine 0.1
#define __threshold_hull 0.1
#define __threshold_gun 0.1
#define __threshold_tracks 0.1

#define __soundhit 200

private["_addpart","_ic","_ainj","_af","_hitleft","_pass","_type","_pkill","_receivedhit","_t","_pdet","_pfire","_ai","_ae","_minhit","_desc","_dummy","_max","_p","_totaldmg","_dmg","_ptvar","_s","_damage","_gd","_explosive","_armor","_hit","_hit0","_hit100","_pprob","_bc","_dist","_angles","_wpns","_i"];
PARAMS_5(_unit,_part,_partdamage,_injurer,_ammo);

if (! alive _unit) exitwith {};
//if (_unit getvariable "ace_ko") exitwith {};

_max = _unit getvariable "ace_hitpart";
//_gd = _unit getvariable "ace_damage_general";
if ((_max select 0) == "") then {_max set [0,"hull"]};
//{
#ifdef DEBUG_MODE_FULL1
	[format["Set FX starting for %1",_unit]] call CBA_fnc_debug;
#endif
	_part = tolower (_max select 0);
	_receivedhit = _max select 1;		//received part hit
	_damage = _max select 2;		//received part damage
	_totaldmg = _max select 3;	//resulting part damage

	//damage threshold and type
	_t = [_unit,_ammo,_receivedhit,_injurer] call FUNC(threshold);
	_pass = _t select 0;	//pass threshold or not
	_type = _t select 1;	//0-direct AP/HEAT hit | 1-direct/indirect HE hit | 2-direct/indirect BLAST mine hit
	_hit = _t select 2;	//modified hit
	_minhit = _t select 3;	//min hit

	if !(_pass) exitwith {
	#ifdef DEBUG_MODE_FXONLY
		[format["SetFX for %1 aborting, dmg below threshold",_unit]] call CBA_fnc_debug
	#endif
	};

	// HE destroying vehicle (with dmg > 4*minhit)
	if (_type == 1) then {
		if ((_hit - 4*_minhit)/(6*_minhit) > random 1) then {
			if !(_ammo isKindOf "MineCore") then {
				_unit setdamage 1;
				_pass = false;
			};
		};
	};
	if (_type == 2) then {
		_pass = true;
	};
	if !(_pass) exitwith {
	#ifdef DEBUG_MODE_FXONLY
		[format["SetFX for %1: destroyed by HE damage",_unit]] call CBA_fnc_debug
	#endif
	};

	//general ammo effectiveness when penetrated (prob it will strike smth critical)
	//HE effectiveness is 40% at threshold value
	//_ae = if (_type == 0) then {(_hit/200) min 1} else {0.4*_hit/_minhit};
	//_ae = if (_type == 0) then {(0.15*_hit/_minhit) min 1} else {(0.4*_hit/_minhit) min 1};
	_ae = if (_type == 0) then {(0.15 max (_hit/500)) min 1} else {(0.4*_hit/_minhit) min 1};
	//_ae = 0.4*_hit/_minhit;
	//incendiary/detonating properties of ammo
	_ai = _ae*getNumber(__ammocfg >> "ace_incendiary");
	//injuring potential:
	//_ainj - prob of hitting a person, _ic - max amt of ppl that can be injured
	switch (true) do {
		//HE
		case (_type == 1): {_ainj = _ae;_ic = 1 + _ae*round(random 9)};
		//KE
		case (getNumber(__ammocfg >> "explosive") <= 0.1): {_ainj = 0.1;_ic = 2};
		//HEAT
		default {_ainj = 4*_ae min 1;_ic = 2 + round(random 3)};
	};
	//accounting for some special cases to choose hit part
	_t = [_unit,_part,_damage,_injurer,_ammo] call FUNC(tank_modifypart);
	_part = _t select 0;
	_angles = _t select 1;
	_damage = _t select 2;
	_addpart = _t select 3;
	//[format["Set FX: modpart %1",_t]] call CBA_fnc_debug;

	_hit0 = 1.2*_hit;		//thickness that cant be penetrated by this ammo
	_hit100 = 0.8*_hit;	//thickness that will always get penetrated
	_s = false;
	_desc = _part;
	_ptvar = "ace_damage_" + _part;
	_pprob = 10;

	switch(_part) do
	{
		case "engine": {
			if (_type == 0) then {
				//effective armor at hit location
				_armor = [_unit,_part,_injurer,_ammo,_angles] call FUNC(tank_getarmor);

				//prob of penetration
				_pprob = (_hit0 - _armor)/(_hit0 - _hit100);
			};
			if (_pprob < random 1) exitwith {_s = true;__ADDINFO("_nopenetr")};

			__ADDINFO("_penetration")
			//sound
			if (_hit > __soundhit) then {[_unit,0,_type] spawn FUNC(playsound)} else {[_unit,1,_type] spawn FUNC(playsound)};

			//ammo storage or fuel tank detonation
			_pdet = getNumber(__unitcfg >> "ace_p_detonation_engine");
			if (_pdet*_ai > random 1) exitwith {
				[_unit] call FUNC(killcrew);
				[_unit,_part] call FUNC(detonate);
				_s = true;
				__ADDINFO("_detonation")
			};

			_dmg = 0.9 min _totaldmg;	//dmg over 0.9 blows'em up

			//80% engine/transmission dies if penetrated
			if (_dmg == 0.9 || {0.8*_ae > random 1}) then {
				//_unit setfuel 0;
				[_unit,"ace_canmove",false] call FUNC(setvar);
				_unit call FUNC(killengine);
				[_unit,_part,0.9] call FUNC(sethit);
				__ADDINFO("_enginedead")
			} else { //accumulate damage from penetrated rnds
				[_unit,_part,_dmg] call FUNC(sethit);
				__ADDINFO("_enginedamaged")
			};

			//turret cant move w/dead engine
			/*if (0.3*_ae > random 1) then {
				[_unit,"turret",1] call FUNC(sethit);
				[_unit,"ace_canshoot",false] call FUNC(setvar);
				__ADDINFO("_turretdead")
			};*/

			//engine in crew compartment on APCs
			if (getNumber(__unitcfg>>"transportSoldier")>0) then {
				[_unit,0.8*_ainj,_ic] call FUNC(injurecrew);
			};

			//start fire
			_pfire = getNumber(__unitcfg >> "ace_p_fire_engine");
			if (_pfire*_ai > random 1) then {
				[_unit,_part,_partdamage,_injurer,_ammo] call FUNC(tank_startfire);
				__ADDINFO("_enginefire")
			};
		};
		case "hull": {
			//tracks were hit
			if (_addpart in ["ltrack","rtrack"]) then {
				if (0.4 < random 1) exitwith {};
				_p = (0.1 max (0.1*_hit/_minhit)) min 1;
				[_unit,_addpart,_p,1,true] call FUNC(addhit);
				//_dmg = 1 min _totaldmg;
				//[_unit,_addpart,_dmg] call FUNC(sethit);
				//diag_log format ["addpt: %1_%2",_addpart,_p];
				//__ADDINFO(_addpart)
				if ((_unit getvariable ("ace_damage_" + _addpart)) >= 1) then {
					[_unit,"ace_canmove",false] call FUNC(setvar);
				};
			};

			if (_type == 0) then {
				//effective armor at hit location
				_armor = [_unit,_part,_injurer,_ammo,_angles] call FUNC(tank_getarmor);

				//prob of penetration
				_pprob = (_hit0 - _armor)/(_hit0 - _hit100);
			};
			if (_pprob < random 1) exitwith {_s = true;__ADDINFO("_nopenetr")};
			__ADDINFO("_penetration")
			//sound
			if (_hit > __soundhit) then {[_unit,0,_type] spawn FUNC(playsound)} else {[_unit,1,_type] spawn FUNC(playsound)};
			//ammo storage or fuel tank detonation
			_pdet = getNumber(__unitcfg >> "ace_p_detonation_hull");
			if (_pdet*_ai > random 1) exitwith {
				[_unit] call FUNC(killcrew);
				[_unit,_part] call FUNC(detonate);
				_s = true;
				__ADDINFO("_detonation")
			};

			//driver might be hit from front

			//if (0 == _angles select 0) then
			//{
			//	[_unit,0.5*_ae] call FUNC(tank_injurecrew);
			//	//+possibly jam the handling?

			[_unit,_ainj,_ic] call FUNC(injurecrew);

			//25-25-25% of 1.jam turret 2.mobility kill 3.both
			if (_ae > random 1) then {
				_p = random 1;
				switch (true) do {
					case (_p < 0.25): {
						//jam turret
						_pkill = ["turret"];
						[_unit,"ace_canshoot",false] call FUNC(setvar);
						[_unit,"hull",0.9] call FUNC(sethit);
						__ADDINFO("_turretdead")
					};
					case (_p < 0.5): {
						//kill mobility
						_pkill = ["ltrack","rtrack"];
						[_unit,"ace_canmove",false] call FUNC(setvar);
						[_unit,"hull",0.9] call FUNC(sethit);
						_unit call FUNC(killengine);
						[_unit,"engine",0.9] call FUNC(sethit);
						__ADDINFO("_tracksdead")
					};
					case (_p < 0.75): {
						//both
						_pkill = ["ltrack","rtrack","turret"];
						[_unit,"ace_canmove",false] call FUNC(setvar);
						[_unit,"ace_canshoot",false] call FUNC(setvar);
						[_unit,"hull",0.9] call FUNC(sethit);
						_unit call FUNC(killengine);
						[_unit,"engine",0.9] call FUNC(sethit);
						__ADDINFO("_turretdead_tracksdead")
					};
					default {_pkill = []};	//nothing
				};
				{
					[_unit,_x,1] call FUNC(sethit);
				} foreach _pkill;

			};


			//start fire
			_pfire = getNumber(__unitcfg >> "ace_p_fire_hull");
			if (_pfire*_ai > random 1) then {
				[_unit,_part,_partdamage,_injurer,_ammo,_angles] call FUNC(tank_startfire);
				__ADDINFO("_hullfire")
			};

		};
		case "turret": {
			if (_type == 0) then {
				//effective armor at hit location
				_armor = [_unit,_part,_injurer,_ammo,_angles] call FUNC(tank_getarmor);

				//prob of penetration
				_pprob = (_hit0 - _armor)/(_hit0 - _hit100);
			};
			if (_pprob < random 1) exitwith {_s = true;__ADDINFO("_nopenetr")};
			__ADDINFO("_penetration")
			//sound
			if (_hit > __soundhit) then {[_unit,0,_type] spawn FUNC(playsound)} else {[_unit,1,_type] spawn FUNC(playsound)};

			//detonate ammo (read prob from cfg)
			_pdet = getNumber(__unitcfg >> "ace_p_detonation_turret");
			if (_pdet*_ai > random 1) exitwith {
				[_unit] call FUNC(killcrew);
				[_unit,_part] call FUNC(detonate);
				_s = true;
				__ADDINFO("_detonation")
			};

			//crew damage
			[_unit,1.5*_ainj,_ic] call FUNC(injurecrew);

			//jam turret
			if (0.8*_ae > random 1) then {
				[_unit,_part,1] call FUNC(sethit);
				[_unit,"ace_canshoot",false] call FUNC(setvar);
				__ADDINFO("_turretdead")
			};

			//start fire
			_pfire = getNumber(__unitcfg >> "ace_p_fire_turret");
			if (_pfire*_ai > random 1) then {
				[_unit,_part,_partdamage,_injurer,_ammo] call FUNC(tank_startfire);
				__ADDINFO("_turretfire")
			};
			// FCS down
			if(_ae > random 1) then {
				[_unit,"ace_tankfcs_down",true] call FUNC(setvar);
				_unit setVariable ["ace_tankfcs_init",nil];
				_unit setVariable ["ace_tankfcs_com_init",nil];
			};
		};
		case "gun": {
			__ADDINFO("_penetration")
			//hit in main gun or turret near the gun (optics, mg)
			//disabling the gun simulates loss of optics too
			if (0.8*_ae > random 1) then {
				[_unit,_part,1] call FUNC(sethit);
				[_unit,"ace_canshoot",false] call FUNC(setvar);
				__ADDINFO("_gundead")
			};
		};
		case "ltrack": {
			if (_type == 2) then {
				[_unit,_part,0.9,1,true] call FUNC(addhit);
				if ((_unit getvariable _ptvar) >= 1) then {
					[_unit,"ace_canmove",false] call FUNC(setvar);
				};				
			} else {
				if (0.66 < random 1 && {_type != 2}) exitwith {_s = true};
				_p = (0.1 max (0.1*_hit/_minhit)) min 1;
				[_unit,_part,_p,1,true] call FUNC(addhit);
				//diag_log format ["%1_%2",_part,_p];
				//_dmg = 1 min _totaldmg;
				//[_unit,_part,_dmg] call FUNC(sethit);
				if ((_unit getvariable _ptvar) >= 1) then {
					[_unit,"ace_canmove",false] call FUNC(setvar);
				};
			};
		};
		case "rtrack": {
			//right track
			if (_type == 2) then {
				[_unit,_part,0.9,1,true] call FUNC(addhit);
				if ((_unit getvariable _ptvar) >= 1) then {
					[_unit,"ace_canmove",false] call FUNC(setvar);
				};				
			} else {			
				if (0.66 < random 1) exitwith {_s = true};
				_p = (0.1 max (0.1*_hit/_minhit)) min 1;
				[_unit,_part,_p,1,true] call FUNC(addhit);
				//diag_log format ["%1_%2",_part,_p];
				//_dmg = 1 min _totaldmg;
				//[_unit,_part,_dmg] call FUNC(sethit);
				if ((_unit getvariable _ptvar) >= 1) then {
					[_unit,"ace_canmove",false] call FUNC(setvar);
				};
			};
		};
		default {_s = true};
	};
	if (_s) exitwith {
	#ifdef DEBUG_MODE_FXONLY
		[format["SetFX for %1 aborting, dmg too low or detonated, effect %2 prob %3",_unit,_desc,_pprob]] call CBA_fnc_debug
	#endif
	};

	if ((_unit getvariable "ace_damage_turret") >= 1) then {
		//anti-JagdPanzer :)
		//{_unit removeMagazine _x} foreach (magazines _unit);
		_unit setvehicleammo 0;
		if (0.4 > random 1) then {[_unit,"gun",1] call FUNC(sethit)};
	};

	[_unit,_part,_injurer] spawn FUNC(tank_analyzedamage);

	#ifdef DEBUG_MODE_FXONLY
		[format ["SetFX for %1: part %2 armor %3 penetr prob %4 effect %5 ae %6",_unit,_part,_armor,_pprob,_desc,_ae]] call CBA_fnc_debug;
	#endif
//};