//discern between direct/indirect hit by given ammo, and tell if damage passes threshold
//discern between hedp(heat) and HE ammo direct hit (both explosive=1) using "ace_heat" parameter


#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo

#define __tc 0.5		//tolerance coef to consider it direct hit

private["_d0","_hit0","_heat","_ihit","_pass","_expl","_minhit","_type","_hit","_bc","_dist","_af"];
PARAMS_4(_unit,_ammo,_dmg,_injurer);

_expl = getNumber(__ammocfg >> "explosive");
_heat = getNumber(__ammocfg >> "ace_heat");
_minhit = getArray(__unitcfg >> "ace_minimalhit"); //[for direct,for HE]
_hit = if (isNumber(__ammocfg >> "ace_hit")) then {getNumber(__ammocfg >> "ace_hit")} else {getNumber(__ammocfg >> "hit")};
_d0 = getNumber(__ammocfg >> "ace_hit_distance");
_hit0 = _hit;
_ihit = (getNumber(__ammocfg >> "indirecthit")); //*_expl

if (_hit < (_minhit select 0)) exitwith {/*["Threshold function: var 0 (cutoff)"] call CBA_fnc_debug;*/[false,0,_hit,_minhit select 0]};	//quick cutoff

switch (true) do {
	case (_expl <= 0.1): {
		//AP
		if !(isNull _injurer) then {
			//penetration decreasing over dist (ghetto exponential formula)
			_af = - getNumber(__ammocfg >> "airfriction");
			_dist = _injurer distance _unit;
			//_bc = (_af/0.00004)*(ln(1/0.9))/1000;	//90% conserved at 1 km for sabots
			//_bc = 2.64*_af;
			_bc = 2.1*_af;
			_hit = (1 - _expl)*_hit*exp(-_bc*(_dist-_d0));
		#ifdef DEBUG_MODE_FULL1
			[format["hit %1 dist %2 bc %3",_hit,_dist,_bc]] call cba_fnc_debug;
		#endif
		};
		_minhit = _minhit select 0;

		//t90 model is penetrable, retaining little damage from sabots
		_pass = (_hit >= _minhit /* && (_dmg >= 0.4*_hit || _unit isKindOf "T90")*/);
		_type = 0;
		#ifdef DEBUG_MODE_FULL1
			["Threshold function: var 1"] call CBA_fnc_debug;
		#endif
	};
	case (_heat == 0): {
		//pure HE damage
		_minhit = _minhit select 1;
		_pass = (_dmg >= 0.8*_minhit);
		_type = 1;
		_hit = _dmg;		//to return to setFX
	#ifdef DEBUG_MODE_FULL1
		["Threshold function: var 1.5 (HE)"] call CBA_fnc_debug;
	#endif
	};

	default {  //HEAT direct or HE indirect
	if (_ihit > __tc*_hit) then {
		switch (true) do {
			case (_dmg > _ihit + 0.01): {
				//direct HEAT or APHE or HE damage
				_minhit = _minhit select 0;
				_pass = (_dmg >= __tc*_minhit);
				_type = 0;
			#ifdef DEBUG_MODE_FULL1
				["Threshold function: var 2 (HEAT-dir)"] call CBA_fnc_debug;
			#endif
			};
			case ((_dmg >= __tc*_hit) && {(_dmg < _ihit - 0.01 )}): {
				//direct HEAT or APHE or HE damage
				_minhit = _minhit select 0;
				_pass = (_dmg >= __tc*_minhit);
				_type = 0;
			#ifdef DEBUG_MODE_FULL1
				["Threshold function: var 3 (HEAT-dir)"] call CBA_fnc_debug;
			#endif
			};
			case (_dmg == _ihit && {getNumber(__ammocfg >> "ace_minetype") == 2}): {
				//HEAT bottom attack mine
				_minhit = _minhit select 0;
				_pass = (_dmg >= __tc*_minhit);
				_type = 0;
			#ifdef DEBUG_MODE_FULL1
				["Threshold function: var 3.5 (HEAT-dir (bottom attck mine)"] call CBA_fnc_debug;
			#endif
			};
			default {	//indirect HE damage
				_minhit = _minhit select 1;
				_pass = (_dmg >= 0.8*_minhit);
				_type = 1;
				_hit = _dmg;		//to return to setFX
			#ifdef DEBUG_MODE_FULL1
				["Threshold function: var 4 (HE)"] call CBA_fnc_debug;
			#endif
			};
		};
	} else {
		if (_dmg > _ihit) then {
			//direct HEAT or APHE or HE damage
			_minhit = _minhit select 0;
			_pass = (_dmg >= __tc*_minhit);
			_type = 0;
		#ifdef DEBUG_MODE_FULL1
			["Threshold function: var 5 (HEAT-dir)"] call CBA_fnc_debug;
		#endif
		} else {
			_minhit = _minhit select 1;
			_pass = (_dmg >= 0.8*_minhit);
			_type = 1;
			_hit = _dmg;		//to return to setFX
		#ifdef DEBUG_MODE_FULL1
			["Threshold function: var 6 (HE)"] call CBA_fnc_debug;
		#endif
		};
	}; //end if

	}; //end default

}; //end switch
#ifdef DEBUG_MODE_FULL1
	[format["Threshold function: args %1 minhit %2 hit %3 ih %4 heat %5 res %6",_this,_minhit,_hit,_ihit,_heat,[_pass,_type]]] call CBA_fnc_debug;
#endif

// Blast mine override to check _pass value always
if (getNumber(__ammocfg >> "ace_minetype") == 1) then {
	_pass = true;
	_type = 2;
	_hit = _dmg*1.25;
};

[_pass,_type,_hit,_minhit]