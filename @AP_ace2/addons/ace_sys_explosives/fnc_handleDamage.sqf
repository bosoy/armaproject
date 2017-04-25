/* ace_sys_explosives (.pbo)| handleDamage | (c) 2011 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

_this spawn {
	private ["_force", "_path"];

	PARAMS_5(_mine,_selectionName,_damage,_source,_projectile);
	if (isNull _mine) exitWith { TRACE_1("No mine found","");0 };
	
	// TODO: Do mines get damaged when placed in water?
	// TODO: Filter self inflicted damage running this function
	
	// No projectile found
	if (_projectile == "") exitWith { TRACE_1("No projectile found",""); 0 }; //Default processing
	if (_projectile == "ACE_DetCordLineGrenade") exitWith { if (!isnil "pzn_delete_mine") then {_mine call pzn_delete_mine};deletevehicle _mine; };
	if (_damage < 0.1) then { _damage = 0.1; };
	if (_damage > 1000) then { _damage = 1; };
	TRACE_2("", (typeName _damage),_damage);
	
	// Check if handleDamage was triggered from an explosion e.g using C4 to detonate a mine
	if (isNumber(configFile >> "CfgAmmo" >> _projectile >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(force))) then {
		_force = getNumber(configFile >> "CfgAmmo" >> _projectile >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(force));
		TRACE_1("explosion",_force);
	} else {
		// Get force value (caliber) from projectile
		_force = getNumber(configFile >> "CfgAmmo" >> _projectile >> "caliber");
		TRACE_1("projectile",_force);
	};

	// Only high caliber can set off an explosive, minimum to set off explosives or repeated firing on them, depending on type of mine resulting in a disabled mine
	_force_needed = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(armor));
	TRACE_1("",_force_needed);

	_explosion_type = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(explosion_type));
	_onDestroyScript = "onDestroyed.sqf";
	_onDestroyPath = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(mine_type));
	TRACE_2("",_onDestroyScript,_onDestroyPath);

	// Apply slightly damage to mine until it becomes disabled (If mine can become disabled)
	if (_force < 3) then {
		TRACE_1("low caliber - applying damage","");
		_cur_damage = _mine getVariable [QGVAR(damage),0];
		_new_damage = _cur_damage + (_damage * 2);
		TRACE_1("",_new_damage);
		_mine setVariable [QGVAR(damage),_new_damage,true];

		// Apply real damage to change mine appearance for defusing attempts, regardless of real damage
		_mine setDamage (0.59 + random 0.39);
		
		if (_new_damage > _force_needed) then {
			// If mine is setup, disable it
			if !(_mine call FUNC(check_disabled)) then {
				[_mine] call FUNC(disabled);
				TRACE_1("Mine disabled","");
			};
			if (random 100 > 50) then {
				TRACE_1("Random explosion caused by shooting mine","");
				if !(isNull _mine) then {
					_path = format ["x\ace\addons\sys_explosives\%1\%2",_onDestroyPath,_onDestroyScript];
					[_mine,_explosion_type] spawn COMPILE_FILE2_SYS(_path);
				};
				sleep 0.1;
				if (!isnil "pzn_delete_mine") then {_mine call pzn_delete_mine};deletevehicle _mine;
			};
		};
	} else {
		// Initiate detonation by high caliber
		_mine setVariable [QGVAR(damage),0,true];
		[_mine] call FUNC(disabled);
		if !(isNull _mine) then {
			_path = format ["x\ace\addons\sys_explosives\%1\%2",_onDestroyPath,_onDestroyScript];
			[_mine,_explosion_type] spawn COMPILE_FILE2_SYS(_path);
		};
		sleep 0.1;
		if (!isnil "pzn_delete_mine") then {_mine call pzn_delete_mine};deletevehicle _mine;
	};
};
0