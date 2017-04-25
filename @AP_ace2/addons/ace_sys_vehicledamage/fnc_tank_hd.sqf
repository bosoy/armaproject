//#define DEBUG_MODE_FULL
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

private["_as","_pos","_type","_max","_ex","_p","_armor","_partarmor","_unitarmor","_prevdamage","_newpartdamage","_newpartdamage1","_s","_hit","_t","_dparts","_anim"];
PARAMS_5(_unit,_part,_partdamage,_injurer,_ammo);

if !(alive _unit) exitwith {
	_hdehv = _unit getVariable QGVAR(hdeh);
	// remove hd eh because it still triggers even for dead objects
	if (!isNil "_hdehv") then {_unit removeEventHandler ["handleDamage", _hdehv]};
	false
};

// Deep Water Fording 
if (_ammo == "") exitwith {
	_p = getpos _unit;
	// DWF Kit
	_dwf_ar = getArray(configFile >> "CfgVehicles" >> typeOf _unit >> "deepWaterFording"); TRACE_1("",_dwf_ar);
	// Can the vehicle ford
	_canFord = (_dwf_ar select 0) == 1; TRACE_1("",_canFord);
	// Continue check here if _canFord == 1
	if (_canFord) then {
		TRACE_1("Vehicle can ford","");
		
		// Check if animationPhase or Variable name
		_fordingType = if (typeName (_dwf_ar select 1) == "ARRAY") then { "ARRAY" } else { "STRING" }; TRACE_1("",_fordingType);
		_fordingKitInstalled = false;
		if (_fordingType == "STRING") then {
			_fordingKitInstalled = _unit getVariable [(_dwf_ar select 1),false]; // Should be Variable 'ACE_DWFK'
		} else {
			_fordingKitInstalled = (_unit animationPhase (_fordingType select 0) == (_fordingType select 1));
		};
		TRACE_1("",_fordingKitInstalled);
		
		// Depth of fording
		_fordingDepth = _dwf_ar select 2; TRACE_1("",_fordingDepth);
		
		// Sucking air through interior or from exterior nozzle
		_fordingAirsupport = _dwf_ar select 3; _fordingDepth = _dwf_ar select 2; TRACE_1("",_fordingAirsupport);
	
		// Check if driver hatch is closed...
		_driverHatchClosed = (_unit animationPhase "hatchDriver") == 0; TRACE_1("",_driverHatchClosed); // TODO: check animationphase
		
		// Check if nozzle is over water
		_nozzleFree = (_p select 2) > -_fordingDepth; TRACE_3("",_nozzleFree,(_p select 2),-_fordingDepth);
		
		// Check if vehicle is fully submerged
		// TODO: boundingBox ?
		// BoundingBox under water?
		// Check if nozzle is exterior then if BBOX submerged and hatches opened then crew drowns and vehicle gets damaged
		
		if ((surfaceiswater [_p select 0,_p select 1]) && {_fordingKitInstalled} && {_driverHatchClosed} && {_nozzleFree}) then { false } else { _unit setfuel 0;false }; // 1. false, can still drive/2. false, engine sucks water
	} else {
		TRACE_1("Vehicle cannot ford","");
		(surfaceiswater [_p select 0,_p select 1] && {(_p select 2) < -2.5});
		// TODO: Make crew drown
		// TODO: Check AI behaviour
	};
}; //underwater damage

if (getNumber(__ammocfg >> "ace_aa") == 1) exitwith {false};

//if (_unit == _injurer && _partdamage < 0.07) exitwith {}; //sometimes triggers out of the blue
//if (getNumber(__ammocfg >> "hit") < (getArray(__unitcfg >> "ace_minimalhit")) select 0 ) exitwith {false};

if (_part != "") then {
	//if (0.001 > (_unit getvariable "ace_overalldamage")) exitwith {};
	//if (_unit getvariable "ace_ignorehit") exitwith {};
	_p = __unitcfg;
	_part = tolower _part;
	switch(_part) do {
		case __pt("ace_name_engine"): {_s = "HitEngine";_type = "engine";_pos = 0};
		case __pt("ace_name_hull"): {_s = "HitHull";_type = "hull";_pos = 1};
		case __pt("ace_name_ltrack"): {_s = "HitLTrack";_type = "ltrack";_pos = 2};
		case __pt("ace_name_rtrack"): {_s = "HitRTrack";_type = "rtrack";_pos = 3};
		case __pt("ace_name_turret"): {_s = "HitTurret";_type = "turret"; _p = _p >> "Turrets" >> "MainTurret";_pos = 4};
		case __pt("ace_name_gun"): {_s = "exit"};//{_s = "HitGun";_type = "gun";_p = _p >> "Turrets" >> "MainTurret";_pos = 5};
		case "elektronika": {_unit setHit ["elektronika",_partdamage]; _unit call FUNC(playsound_electricspark); _s = "exit"};	// is there such part at all?
		default {_unit setHit [_part,_partdamage];_s = "exit"}; // irrelevant selections
	};
	if (_s == "exit") exitwith {};

	//finding damage received, setting it into the array of part damages for the current hit (ace_dparts)
	_prevdamage = _unit getvariable ("ace_damage_"+_type);
	_newpartdamage1 = _partdamage - _prevdamage;
	if (_newpartdamage1 < 0) then
	{ 	//veh was repaired
		_unit setvariable [("ace_damage_"+_type),0,true];
		_newpartdamage1 = _partdamage;
	};
	_partarmor = getNumber (_p >> "hitpoints" >> _s >> "armor");
	_armor = getNumber (__unitcfg >> "armor");
	_newpartdamage = _newpartdamage1*_partarmor*_armor; //pure hit received by selection

	//stores part with max damage
	_max = _unit getvariable "ace_hitpart";
	if (_newpartdamage > (_max select 1) || {(_max select 0) == ""}) then {
		_unit setvariable ["ace_hitpart",[_type,_newpartdamage,_newpartdamage1,_partdamage]];//[part type, received hit, received pt damage, total pt damage]
	};
	//ordered array storing only damages, with indices depending on part
	_dparts = _unit getvariable "ace_dparts";
	_dparts set [_pos,_newpartdamage];
	_unit setvariable ["ace_dparts",_dparts];
#ifdef DEBUG_MODE_FULL1
	[format ["HandleDamage part %1 type %5 dmg %2 newdmg %3 d_part %4",_part,_partdamage,_newpartdamage,(_unit getvariable "ace_hitpart"),_type]] call CBA_fnc_debug;
#endif

} else {		//  first triggering of the EH
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
	if (_newpartdamage >= 0 ) then //0.001
	{	//ignore small hits/false/double triggering

		//several triggerings at 1 hit
		_s = _unit getvariable "ace_hittime";
		if (isNil "_s") then {
			_unit setvariable ["ace_hittime",[time,_injurer]];
			_unit setvariable ["ace_ignorehit",false]

		} else {
			_p = 0.03;//if (_unit isKindOf "BMP2_Base" || _unit isKindOf "M1A1") then {0.06} else {0}; //f.up t90 model
			if (time <= (_s select 0)+_p && {_injurer == (_s select 1)}) then {
				_unit setvariable ["ace_ignorehit",true];
			} else {
				_unit setvariable ["ace_ignorehit",false];
				_unit setvariable ["ace_hittime",[time,_injurer]];
			};
		};
		//[format ["HandleDamage: unit %1 injurer %2 ht %3 ignore %4",_unit,_injurer,(_unit getvariable "ace_hittime"),(_unit getvariable "ace_ignorehit")]] call CBA_fnc_debug;

		if (_unit getvariable "ace_ignorehit") exitwith {
			_ex = true;
			_max = _unit getvariable "ace_hitpart";
			//diag_log format ["ignoring hit, var %1 newdam %2",_max,_newpartdamage];
			if ((_max select 0) == "") then //accumulate hit if only "" part triggered
			{
				_armor = getNumber (__unitcfg >> "armor");
				//_as = getNumber (__unitcfg >> "armorstructural");
				_p = _newpartdamage + (_max select 2);
				_unit setvariable ["ace_hitpart",["",_p*_armor,_p,_p]];
			};
		};
		_unit setvariable ["ace_overalldamage",_newpartdamage];
		//initializing damage vars
		_unit setvariable ["ace_dparts",[0,0,0,0,0,0]];

		_armor = getNumber (__unitcfg >> "armor");
		//_as = getNumber (__unitcfg >> "armorstructural");
		_unit setvariable ["ace_hitpart",["",_newpartdamage*_armor,_newpartdamage,_newpartdamage]];

		_s = _unit getvariable "ace_damage_engine";
		if (isNil "_s") then {
			_s = damage _unit;
			//variables to later store damage set with 'sethit' as there's no 'gethit' :-)
			//_unit setvariable ["ace_damage_general",_s,true];
			_unit setvariable ["ace_damage_engine",_s,true];
			_unit setvariable ["ace_damage_hull",_s,true];
			_unit setvariable ["ace_damage_turret",_s,true];
			_unit setvariable ["ace_damage_gun",_s,true];
			_unit setvariable ["ace_damage_ltrack",_s,true];
			_unit setvariable ["ace_damage_rtrack",_s,true];

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

		// why not call instead of spawn here ?
		_this spawn FUNC(tank_setfx);
		#ifdef DEBUG_MODE_FULL1
			[format ["HandleDamage: part %1 dmg %2 this %3 local %4",_part,_newpartdamage,_this,(local _unit)]] call CBA_fnc_debug;
		#endif
	};
};

false