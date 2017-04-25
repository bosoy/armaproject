//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfgW configFile >> "CfgWeapons" >> _wpn

TRACE_1("",_this);

private["_wpn","_type","_t","_snd"];
if (count _this != 2) exitwith {false};

if(player != vehicle player) exitwith {false};
if(currentWeapon player == "") exitWith {false}; //Exit if player has no weapon, refs #24316 ?

_type = _this select 1;
_t = player call FUNC(getunitanim);

_wpn = switch (_t) do {
	case -1: {""};
	case 0: {primaryweapon player};
	case 1: {[player] call ACE_fnc_getPistol};
	case 2: {primaryweapon player}; //launcher to rifle/GL fix
	default {""};
};

TRACE_3("action,anim,weapon",_type,_t,_wpn);

switch (_type) do {
	case -1: {//safety
		if (_wpn == "") exitwith {}; // If no weapon in hands no reason to switch to safe mode
		if (currentweapon player != "ace_safe") then {
			if !(player hasweapon "ace_safe") then {player addweapon "ace_safe"};
			_snd = "ace_switch_met_1";
			if (isText(__cfgW>>"ace_firemode_sound")) then {
				_snd = format ["ace_switch_%1_%2", gettext(__cfgW>>"ace_firemode_sound"),round (1 + random 1)];
			};
			_snd call GVAR(SwitchSound);
			player setVariable [QGVAR(safety),[(currentWeapon player),true]];
			player selectweapon "ace_safe";
		};
	};
	case 0: { //switch to rifle
		if (_wpn == "") exitwith {};
		private "_firstmuz";
		_firstmuz = {
			private "_muzzles";
			_muzzles = getArray (configFile >> "CfgWeapons" >> _this >> "muzzles");
			if (_muzzles select 0 != "this") exitWith	{_muzzles select 0};
			_this
		};
		if (currentweapon player == "ace_safe") then {
			_snd = format ["ace_switch_%1_%2", gettext(__cfgW>>"ace_firemode_sound"),round (1 + random 1)];
			_snd call GVAR(SwitchSound);
		};
		if (currentmuzzle player == (_wpn call _firstmuz)) then { // if first muzzle already selected
			private "_wob";
			_wob = player getVariable ["ACE_weapononback", ""];
			if (isClass(configFile >> "CfgWeapons" >> _wob)) then { // replace current with WOB rifle
				if (getNumber(configFile >> "CfgWeapons" >> _wob >> "type") == 1) then {
					if (isNil "ace_weapononback_inprogress") then {ace_weapononback_inprogress = false};
					if (!ace_weapononback_inprogress) then {
						ace_weapononback_inprogress = true;
						[_wpn,_wob] spawn {
							PARAMS_2(_wpn,_wob);
							private ["_dexfrom","_dexto","_state","_anim"];
							_dexfrom = getNumber(configFile >> "CfgWeapons" >> _wpn >> "dexterity");
							_dexto = getNumber(configFile >> "CfgWeapons" >> _wob >> "dexterity");
							if (cameraview == "GUNNER") then {player switchcamera "INTERNAL"};
							_state = animationState player;
							_anim =	(player call CBA_fnc_getUnitAnim) select 0; //"stand" "kneel" "prone"
							_delay = (0.9 max (4 - _dexfrom - _dexto));
							if (_anim == "prone") then {_delay = 0.2};
							switch (_anim) do {
								case "prone": {
									//TODO: find something that works nicely here
									//player playMove "WeaponMagazineReloadProne";
								};
								default {
									player action ["WeaponOnBack", player];
								};
							};
							sleep _delay;
							[player,_wob] call ace_sys_ruck_fnc_uiPutWeaponInHands;
							player switchmove _state;
							ace_weapononback_inprogress = false;
						};
					};
				};
			};
		} else {
			player selectweapon (_wpn call _firstmuz);
		};
		if (player hasweapon "ace_safe") then {player removeweapon "ace_safe"};
		player setVariable [QGVAR(safety),[(currentWeapon player),false]];
		
		if (ace_sys_goggles_mask_deh) then {
			["",-11] call ace_sys_goggles_overlay_change;
		};
	};

	case 1: { //GL
		if (_wpn == "") exitwith {};
		private ["_p"];
		_p = _wpn call FUNC(hasGL);
		if (_p select 0) then {
			if(currentmuzzle player == (_p select 1)) then { 0 = [] spawn FUNC(GL_sight) };
			if (player hasweapon "ace_safe") then {player removeweapon "ace_safe"};
			player selectweapon (_p select 1);
			if (ace_sys_goggles_mask_deh) then {
				["",-11] call ace_sys_goggles_overlay_change;
			};
			call ace_sys_sight_adjustment_gl_fnc_init; // initialize sa, to account for fine adjustment gl config
		};
	};

	case 2: { //Throw
		private ["_p"];
		_p = "Throw" call FUNC(hasStuff);
		TRACE_1("",_p);
		if (_p select 0) then {
			_prevweaponx = currentWeapon player;
			player removeWeapon "Throw";
			player addWeapon "Throw";
			if (_prevweaponx == "Throw") then {
				player selectweapon (_p select 1);
			};
			if (cameraview == "GUNNER") then {player switchcamera "INTERNAL"};
			if (player hasweapon "ace_safe") then {player removeweapon "ace_safe"};
			if (currentweapon player != "Throw") then {
				player selectweapon (_p select 1);
				TRACE_1("currentweapon player != Throw","");
				true call ace_sys_grenadethrow_fnc_throwselected;

			} else {
				TRACE_1("calling false","");
				false call ace_sys_grenadethrow_fnc_throwselected;
			};
			if (ace_sys_goggles_mask_deh) then {
				["",-11] call ace_sys_goggles_overlay_change;
			};
		};
	};
	case 3: { //was: Put - Disabled, Mines and Satchels are put now via Interaction menu | is now: Launcher
		private ["_p"];
		_p = secondaryWeapon player;
		if (!isNil "_p" && {!(isNumber(configFile >> "CfgWeapons" >> _p >> "ACE_PackSize"))}) then {
			if (player hasweapon "ace_safe") then {player removeweapon "ace_safe"};
			player selectweapon _p;
			if (ace_sys_goggles_mask_deh) then {
				["",-11] call ace_sys_goggles_overlay_change;
			};
		};
	};
	case 4: { //Swap IR/Flashlight
		private "_classes";
		if (isArray(__cfgW>>"ace_gunlight_classes")) then {
			_classes = getArray(__cfgW>>"ace_gunlight_classes");
			if ({_x==_wpn} count _classes == 1) then {
				[player, _wpn, _classes] spawn FUNC(changeLight);
			};
		};
	};
	default {};
};

//kill grenade indicator
if (currentweapon player != "Throw" /*|| {player call ace_sys_wounds_fnc_isUncon}*/) then {
		-2 call ace_sys_grenadethrow_fnc_indicator;
};

true
