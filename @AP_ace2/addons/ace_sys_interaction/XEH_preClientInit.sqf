/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

ADDON = false;

LOG(MSG_INIT);

PREP(keypressed);
PREP(onload);

PREP(confirmation);
PREP(answer);

PREP(gear);
PREP(s_and_d);
PREP(arrest);
PREP(rehab);
PREP(loadPris);
PREP(unloadPris);
PREP(disarm);

GVAR(presstime) = 0;

FUNC(keypressed_ci) = {
	private "_unit";
	if (!isNil "ACE_NoCivilianInteraction") exitWith { false };
	if (GVAR(presstime) == time) exitwith { false };
	GVAR(presstime) = time;	
	_unit = player;
	if (_unit getVariable [QGVAR(ci),false]) exitWith { false };
	_unit setVariable [QGVAR(ci),true];
	_unit spawn {
		_unit = _this;
		_unit call FUNC(ci_add);
		while { _unit getVariable QGVAR(ci) } do {
			sleep 0.001; 
		};
		_unit setVariable [QGVAR(ci),false];
		_unit call FUNC(ci_remove);
	};
	false
};

FUNC(keypressed_tap) = {
	private "_target";
	if (GVAR(presstime) == time) exitwith {false};
	GVAR(presstime) = time;

	if (vehicle player != player || {!alive player} || {player call ace_sys_wounds_fnc_isUncon}) exitWith { false };
	_target = cursorTarget;
	if (isNull _target) exitWith { false };
	if !(_target isKindOf "Man") exitWith { false };
	if (!isPlayer _target) exitWith { false };
	if (!alive _target) exitWith { false };
	if (player distance _target > 3) exitWith { true };
	if (side (group _target) != side (group player)) exitWith { true};
	if (local player) then { hintSilent localize "STR_DN_ACE_TAPSHOULDER" };
	[_target] spawn FUNC(tap);
	true	
};

FUNC(keypressed_knock) = {
	private "_target";
	if (GVAR(presstime) == time) exitwith { false };
	GVAR(presstime) = time;
	
	if (vehicle player != player || {!alive player} || {player call ace_sys_wounds_fnc_isUncon}) exitWith { false };
	_target = cursorTarget;
	if !(ACE_SELFINTERACTION_RESTRICTED) exitWith { false };
	if !(isNil "ACE_DisableKnockdown") exitWith { false };
	if (isNull _target) exitWith { false };
	if !(_target isKindOf "Man") exitWith { false };
	if (!alive _target) exitWith { false };
	if (_target getVariable [QGVAR(knockeddown), false]) exitWith { false };
	if (_target getVariable ["ace_w_busy", false] || {_target call ace_sys_wounds_fnc_isUncon}) exitWith { false };
	if !(getNumber(configFile >> "cfgweapons" >> currentweapon player >> "type") in [0,1]) exitWith { false };
	if !(((player call CBA_fnc_getUnitAnim) select 0) in ["stand"]) exitWith { false };
	if (side (group _target) == side (group player)) exitWith { false};
	[_target] call FUNC(knockknock);
	true
};

FUNC(knockknock) = {
	private ["_weapon","_wtype","_anims","_anim"];
	PARAMS_1(_target);
	_weapon = currentWeapon player;
	_wtype = getNumber(configFile>>"CfgWeapons">>_weapon>>"type");
	if (_wtype == 0) then {
		_anims = ["AmelPercMstpSnonWnonDnon_amaterUder1","AmelPercMstpSnonWnonDnon_amaterUder2","AmelPercMstpSnonWnonDnon_amaterUder3"];
		_anim = _anims select (floor random (count _anims));
		player playMoveNow _anim;
		[_target, _weapon, _anim] spawn {
			PARAMS_3(_target,_weapon,_anim);
			sleep 0.5;
			if ((visiblePosition player) distance (visiblePosition _target) < 2.5) then { // Target could have moved when we initiated the knockdown, so lets play animation but no effect on _target
				[QGVAR(knd), [_target, _weapon, player]] call ACE_fnc_receiverOnlyEvent;
			};
		};
	} else {
		player playMoveNow "AmelPercMstpSlowWrflDnon_StrokeGun";
		[_target, _weapon, _anim] spawn {
			PARAMS_3(_target,_weapon,_anim);
			sleep 1;
			if ((visiblePosition player) distance (visiblePosition _target) < 2.5) then { // Target could have moved when we initiated the knockdown, so lets play animation but no effect on _target
				[QGVAR(knd), [_target, _weapon, player]] call ACE_fnc_receiverOnlyEvent;
			};		
		};
	};
	// TODO: depending on weapon or no weapon longer/shorter knockdown phase
	// TODO: play sound when one player knocks the other ?
};

[QUOTE(ADDON), "Interaction_Menu", { _this call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;

[QUOTE(ADDON), "Interaction_Menu", { call FUNC(keypressed_ci) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Interaction_Menu", { player setVariable [QGVAR(ci),false]; false }, "keyUp"] call CBA_fnc_addKeyHandlerFromConfig;

[QUOTE(ADDON), "TapShoulder", { call FUNC(keypressed_tap) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Knockdown", { call FUNC(keypressed_knock) }] call CBA_fnc_addKeyHandlerFromConfig;

[QGVAR(confirmation), { _this call FUNC(confirmation) }] call ACE_fnc_addReceiverOnlyEventhandler;

GVAR(key) = ([QUOTE(ADDON), "Interaction_Menu"] call CBA_fnc_readKeyFromConfig);
if (GVAR(key) select 0 == -1) then { ERROR("No Interaction_Menu key defined. Falling back to default LWIN"); GVAR(key) = DIK_LWIN };

GVAR(key_self) = ([QUOTE(ADDON), "Self_Interaction_Menu"] call CBA_fnc_readKeyFromConfig);
if (GVAR(key_self) select 0 == -1) then { ERROR("No Self_Interaction_Menu key defined. Falling back to default APPS"); GVAR(key_self) = DIK_APPS };

[] call FUNC(toggle);

FUNC(checkTeamSwitch) = {
	disableSerialization;
	if (!dialog) exitWith {};
	if (vehicle player == player) then {
		if (dialog) then {
			closeDialog 0;
		};
	} else {
		private ["_disp", "_tsopen"];
		_disp = findDisplay 632;
		_tsopen = !isNull _disp;
		if (!_tsopen && {dialog}) exitWith {
			closeDialog 0;
		};
		[_disp] spawn {
			disableSerialization;
			PARAMS_1(_disp);
			waitUntil {isNull _disp};
			if (dialog) then {
				closeDialog 0;
			};
		};
	};
};

["CAManBase", [GVAR(key)], 5, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;
[["Car", "Tank", "Air", "Ship", "ACE_Stretcher"], [GVAR(key)], -10, [QPATHTO_F(fnc_menuDef), "vehicle"]] call CBA_ui_fnc_add;

//["player", [GVAR(key_self)], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add; // In case we need it again somewhen

ADDON = true;
