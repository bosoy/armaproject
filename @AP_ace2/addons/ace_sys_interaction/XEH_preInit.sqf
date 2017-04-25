/* ace_sys_interaction (.pbo) | (c) 2008, 2009 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")

#define __DOFSM _unit doFSM [QUOTE(x\ace\addons\sys_interaction\ci_fsm.fsm),getPos _unit,_unit]
#define __DOFSM_X _x doFSM [QUOTE(x\ace\addons\sys_interaction\ci_fsm.fsm),getPos _x,_x]

ADDON = false;

LOG(MSG_INIT);

FUNC(surrender) = {
	PARAMS_2(_unit,_fiveO);
	if !(local _unit) exitWith {};
	_unit stop true;
	_unit doWatch _fiveO;
	sleep 5;
	_unit stop false;
};

// TODO: Set captives to captive true
FUNC(handcuff) = {
	private ["_g","_anim"];
	if (side group _this != CIVILIAN) then {
		_g = _this getVariable QUOTE(surrendered);
		if (isNil "_g") then {_g = false};
		if (!_g) then {
			_this setVariable [QUOTE(surrendered),true];
			[_this] execFSM "\ca\modules\SRRS\data\fsms\surrender.fsm";
		};
	}; 
	_anim = ["ActsPsitMstpSnonWunaDnon_sceneNikitinDisloyalty_Cooper","ActsPsitMstpSnonWunaDnon_sceneNikitinDisloyalty_Sykes","ActsPsitMstpSnonWunaDnon_sceneNikitinDisloyalty_Rodriguez","ActsPsitMstpSnonWunaDnon_sceneNikitinDisloyalty_Ohara"];
	
	if (!isPlayer _this) then {
		[QGVAR(swm2), [_this, "CivilLying01"]] call CBA_fnc_GlobalEvent;
		// If BIS wounding is on, then do not setUnconscious (-removes Actionmenu)
		if (!ACE_BIS_WOUNDING_ENABLED) then { _this setUnconscious true }; // Disable useractions on handcuffed players
	};
	_this setVariable [QGVAR(cuffed),true,true];
	_this setCaptive true;
};

/*
	_anim = ["boundCaptive_loop1","boundCaptive_loop2","boundCaptive_loop3","boundCaptive_loop4"];
	["CivilSitting03","CivilSitting02","CivilSitting01","CivilSitting","CivilLying01","boundCaptive_loop1","boundCaptive_loop2","boundCaptive_loop3","boundCaptive_loop4"]	
	_this switchmove "CivilLying01"; //(_anim select (abs random (count _anim - 1))); //"ACE_Keycuffed_Loop";
	_this setVariable [QGVAR(cuffed),true,true];
*/

FUNC(uncuff) = {
	[QGVAR(swm2), [_this, ""]] call CBA_fnc_GlobalEvent; // TODO: Make prone.
	[QGVAR(swm2), [_this, "amovppnemstpsnonwnondnon"]] call CBA_fnc_GlobalEvent;
	_this setVariable [QGVAR(cuffed),false,true];
	_this setCaptive false; // the SRRS FSM sets it to true
	if (isPlayer _this) then {
		if (!ACE_BIS_WOUNDING_ENABLED) then { _this setUnconscious false }; // Enable useractions again
	};
};

FUNC(tap) = {
	PARAMS_1(_unit);
	[QGVAR(confirmation), [_unit, player, 70, ""]] call ACE_fnc_receiverOnlyEvent
};

FUNC(toggle) = {
	cba_ui_holdKeyDown = ((["ace", "sys_interaction", "toggle"] call ace_settings_fnc_getNumber) == 1);
};

FUNC(ci_add) = {
	// TODO: Jerrycan
	#define __COND_BUILDING "alive cursorTarget && {cursorTarget isKindOf 'CaManBase'} && {player distance cursorTarget > 2.6} && {player distance cursorTarget < 30} && {count (nearestObjects [player, ['HOUSE'], 20]) > 0}"
	#define __COND_FREEZE "alive cursorTarget && {cursorTarget isKindOf 'CaManBase'} && {player distance cursorTarget > 2.6} && {player distance cursorTarget < 30} && {speed cursorTarget > 1}"
	#define __COND_MAN "alive cursorTarget && {cursorTarget isKindOf 'CaManBase'} && {player distance cursorTarget > 2.6} && {player distance cursorTarget < 30}"
	#define __COND_CARGETOUT "alive cursorTarget && {cursorTarget isKindOf 'Car'} && {{alive _x} count crew cursorTarget > 0} && {player distance cursorTarget > 2.6} && {player distance cursorTarget < 20} && {side group (driver cursorTarget) == CIVILIAN} && {speed cursorTarget <= 3}"
	#define __COND_CARSTOP "alive cursorTarget && {cursorTarget isKindOf 'Car'} && {{alive _x} count crew cursorTarget > 0} && {player distance cursorTarget > 2.6} && {player distance cursorTarget < 20} && {side group (driver cursorTarget) == CIVILIAN} && {speed cursorTarget > 3}"
	
	#define __COND_BUILDING_ALL "isNull cursorTarget && {count ((position player nearEntities ['CaManBase',15]) - [player]) > 0} && {count (nearestObjects [player, ['HOUSE'], 20]) > 0}"
	#define __COND_MAN_ALL "isNull cursorTarget && {count ((position player nearEntities ['CaManBase',15]) - [player]) > 0}"
	
	PARAMS_1(_unit);
	GVAR(CI_ID_AR) = [
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_CI_VERBALCOMMAND" +" "+ localize "STR_ACE_CI_VCFREEZE"), QPATHTO_F(fnc_exec), ["freeze",cursorTarget], 0, false, true, "", __COND_FREEZE],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_CI_VERBALCOMMAND" +" "+ localize "STR_ACE_CI_VCGETDOWN"), QPATHTO_F(fnc_exec), ["down",cursorTarget], 0, false, true, "", __COND_MAN],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_CI_VERBALCOMMAND" +" "+ localize "STR_ACE_CI_VCCLEARAREA"), QPATHTO_F(fnc_exec), ["away",cursorTarget], 0, false, true, "", __COND_MAN],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_CI_VERBALCOMMAND" +" "+ localize "STR_ACE_CI_VCGETINSIDE"), QPATHTO_F(fnc_exec), ["inside",cursorTarget], 0, false, true, "", __COND_BUILDING],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_CI_VERBALCOMMAND" +" "+ localize "STR_ACE_CI_VCSTOPCAR"), QPATHTO_F(fnc_exec), ["stop",cursorTarget], 0, false, true, "", __COND_CARSTOP],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_CI_VERBALCOMMAND" +" "+ localize "STR_ACE_CI_VCGETDOWN"), QPATHTO_F(fnc_exec), ["down",objNull], 0, false, true, "", __COND_MAN_ALL],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_CI_VERBALCOMMAND" +" "+ localize "STR_ACE_CI_VCCLEARAREA"), QPATHTO_F(fnc_exec), ["away",objNull], 0, false, true, "", __COND_MAN_ALL],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_CI_VERBALCOMMAND" +" "+ localize "STR_ACE_CI_VCGETINSIDE"), QPATHTO_F(fnc_exec), ["inside",objNull], 0, false, true, "", __COND_BUILDING_ALL]
	];
// TODO: Add and fix : _unit addAction [ACE_TEXT_RED(localize "STR_ACE_CI_VERBALCOMMAND" +" "+ localize "STR_ACE_CI_VCGETOUTCAR"), QPATHTO_F(fnc_exec), ["getout",cursorTarget], 0, false, true, "", __COND_CARGETOUT];
};

FUNC(ci_remove) = {
	PARAMS_1(_unit);
	{ _unit removeAction _x } forEach GVAR(CI_ID_AR);
};

// TODO: Fix recurring events
// TODO: Check AI waypoints
// TODO: Check civilian players (hints, stuff etc)

FUNC(ci_setVar) = {
	PARAMS_2(_unit,_var);
	_unit setVariable [QGVAR(ci_fsmcond),_var];
};
FUNC(ci_freeze) = {
	PARAMS_1(_unit);
	[_unit,QUOTE(freeze)] call FUNC(ci_setVar);
	__DOFSM;
};

FUNC(ci_down) = {
	PARAMS_1(_unit);
	[_unit,QUOTE(down)] call FUNC(ci_setVar);
	__DOFSM;
};

FUNC(ci_away) = {
	PARAMS_1(_unit);	
	[_unit,QUOTE(away)] call FUNC(ci_setVar);
	__DOFSM;
};

FUNC(ci_inside) = {
	PARAMS_1(_unit);	
	[_unit,QUOTE(inside)] call FUNC(ci_setVar);
	__DOFSM;
};

FUNC(ci_getout) = {
	PARAMS_1(_unit);
	[_unit,QUOTE(getout)] call FUNC(ci_setVar);
	__DOFSM;	
};

FUNC(ci_stop) = {
	PARAMS_1(_unit);
	[_unit,QUOTE(stop)] call FUNC(ci_setVar);
	__DOFSM;
};

FUNC(knockdown) = {
	private ["_wtype","_anim","_anims", "_playedanim", "_ransound"];
	PARAMS_3(_target,_weapon,_knocker);
	if ((_target call CBA_fnc_getUnitAnim) select 0 != "prone") then {
		_anims = ["AmelPercMstpSnonWnonDnon_zasah1","AmelPercMstpSnonWnonDnon_zasah2","AmelPercMstpSnonWnonDnon_zasah3hard","AmelPercMstpSnonWnonDnon_zasah4","AmelPercMstpSnonWnonDnon_zasah5hard","AmelPercMstpSnonWnonDnon_zasah6hlava","AmelPercMstpSnonWnonDnon_zasah7bricho"];
		_anim = _anims select (floor random (count _anims));
		_target playMoveNow _anim;
		_playedanim = true;
	} else {
		_playedanim = false;
		_target playActionNow "Die";
	};
	_target setVariable [QGVAR(knockeddown), true, true];
	_ransound = ["ACE_Melee1", "ACE_Melee2"] select (floor (random 2));
	[[_target], _ransound,5] call CBA_fnc_globalSay3D;
	
	_wtype = getNumber(configFile>>"CfgWeapons">>_weapon>>"type");
	_timespan = switch (true) do {
		case (_wtype == 1): {20 + random 5}; // rifle
		case (_wtype == 2): {10 + random 5}; // pistol
		case (_wtype > 2): {30 + random 5}; // MG?
		default {5 + random 5};
	};
	// TODO: Show message for knocked down player like "you were knocked down" ?
	diag_log text format["%1 ACE Knock Down: %2 Knocked You Down", diag_tickTime, (name _knocker)]; // This system is abused quite often, at least let people get a log of who did it to them.
	[_target, _timespan, _playedanim] spawn {
		private ["_timespan"];
		PARAMS_3(_target,_timespan,_playedanim);
		if (_playedanim) then {
			sleep 1.2;
			_target playActionNow "Die";
		};
		_timeend = time + _timespan;
		waitUntil {sleep 0.412; time >= _timeend || {!alive _target} || {_target call ace_sys_wounds_fnc_isUncon}};
		if (!isNull _target && {alive _target} && {!(_target call ace_sys_wounds_fnc_isUncon)} && {!(_target getVariable [QGVAR(cuffed),false])}) then {
			[QGVAR(swm), _target] call CBA_fnc_GlobalEvent;
			_target setVariable [QGVAR(knockeddown), false, true];
		};
	};
};

FUNC(loadinvehicle) = {
	PARAMS_3(_player,_object,_veh);
	_vehType = typeOf _veh;
	if (player == _player) then {
		_vehName = [configFile >> "CfgVehicles" >> _vehType >> "displayName", "text", "UNKNOWN"] call CBA_fnc_getConfigEntry;
		if (_vehName == "") then { _vehName = _vehType };
		hint format[localize "STR_DN_ACE_LOADINVEHICLE", name _object, _vehName];
	};
};

// Interaction Events
[QGVAR(rehab), { _this addRating abs(rating _this)}] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(remwe), { _this spawn {sleep 3;removeAllWeapons _this}}] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(cuff), { _this call FUNC(handcuff) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(uncuff), { _this call FUNC(uncuff) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(surrender), { _this spawn FUNC(surrender) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(swm), {_this switchmove "AmovPpneMstpSnonWnonDnon_healed"}] call CBA_fnc_addEventHandler;
[QGVAR(knd), {_this call FUNC(knockdown)}] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(swm2), {(_this select 0) switchmove (_this select 1)}] call CBA_fnc_addEventHandler;
[QGVAR(loadhint), { _this spawn FUNC(loadinvehicle) }] call CBA_fnc_addEventHandler;

// CI Events
[QGVAR(ci_freeze), { _this spawn FUNC(ci_freeze) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(ci_down), { _this spawn FUNC(ci_down) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(ci_away), { _this spawn FUNC(ci_away) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(ci_inside), { _this spawn FUNC(ci_inside) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(ci_getout), { _this spawn FUNC(ci_getout) }] call ACE_fnc_addReceiverOnlyEventhandler;
[QGVAR(ci_stop), { _this spawn FUNC(ci_stop) }] call ACE_fnc_addReceiverOnlyEventhandler;

ADDON = true;
