//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_unit","_pstartpos", "_seconds", "_textar", "_moved", "_notext", "_text", "_tcount", "_etime", "_stime", "_position","_distance","_focus","_withFocus"];

#define __check ((if (surfaceIsWater _pstartpos) then {getPosASL _unit} else {getPosATL _unit}) distance _pstartpos > _distance)

#define __CD closeDialog 0

_seconds = if (count _this > 0) then { _this select 0 } else { 1 };
_textar = if (count _this > 1) then { _this select 1 } else { [] };
_moved = if (count _this > 2) then { _this select 2 } else { false };
_anim = if (count _this > 3) then { _this select 3 } else { false };
_unit = if (count _this > 4) then { _this select 4 } else { player};
_withFocus = if (count _this > 5) then { _this select 5 } else { false };

_notext = false;

if (isNil "_text") then {_text = ""};
if (isNil "_textar") then {_textar = [localize "STR_ACE_LADEBALKEN_STANDBY"];_notext = true};
if (count _textar == 0) then {_textar = [localize "STR_ACE_LADEBALKEN_STANDBY"];_notext = true};
if (isNil "_moved") then {_moved = false;_notext = false};
if (_notext) then {_textar set [count _textar, localize "STR_ACE_LADEBALKEN_DONTMOVE"]};
if (isNil "_anim") then {_anim = false};
if (isNil "_unit") then { _unit = player };
if (isNil "_withFocus") then { _withFocus = false }; if (_withFocus && _unit != player) then { _withFocus = false };

// 0 = start state
// 1 = everything ok, normal ending
// 2 = player moved
// 3 = player died
_unit setVariable ["ACE_PB_Result", 0];
_unit setVariable ["ACE_PB_Abort", false];

if (_moved) then {
	_pstartpos = getPosATL _unit;
	if (surfaceIsWater _pstartpos) then {
		_pstartpos = getPosASL _unit;
	};
	TRACE_1("",_pstartpos);
	_distance = if (_unit isKindOf "CaManBase") then { 1 } else { 5 }; // Check Some Vehicles
};

_tcount = 0;

if (_anim) then {
	if (((_unit call CBA_fnc_getUnitAnim) select 0) == "stand") then {
		_unit playMove "AmovPercMstpSrasWrflDnon_diary";
	};
};

_etime = time + _seconds;
_stime = time;

if (_withFocus) then {
	_focus = createDialog "ACE_ProgressBarFocus"
};
135996 cutRsc ["ACE_ProgressBar", "PLAIN"];
while {true} do {
	if (!_withFocus && {time > _etime}) exitWith {_unit setVariable ["ACE_PB_Result", 1]; TRACE_1("Progressbar ended","");};
	if (_withFocus && {time > _etime}) exitWith {__CD; _unit setVariable ["ACE_PB_Result", 1]; TRACE_1("Progressbar ended","");};
	if (!alive _unit) exitWith {_unit setVariable ["ACE_PB_Result", 3]; TRACE_1("Unit died","");};
	if (_withFocus && {!alive _unit}) exitWith {__CD; _unit setVariable ["ACE_PB_Result", 3]; TRACE_1("Unit died","");};
	if (_moved && {(__check)}) exitWith {_unit setVariable ["ACE_PB_Result", 2]; TRACE_2("Unit moved",(_unit distance _pstartpos),_distance);};
	if (_unit getVariable ["ACE_PB_Abort",false]) exitWith {_unit setVariable ["ACE_PB_Result", 2]; TRACE_1("Aborted","");};
	if (_withFocus && {!dialog} && {time < _etime}) exitWith {__CD; _unit setVariable ["ACE_PB_Result", 2]; TRACE_1("Aborted","");};
	[_seconds, time - _stime, if (_tcount != -1) then {_textar select _tcount} else {""}, if (_tcount != -1) then {count (toArray (_textar select _tcount))} else {0}] call FUNC(progress);
	if (count _textar > 1) then {
		_tcount = _tcount + 1;
		if (_tcount >= count _textar) then {_tcount = 0};
	};
	sleep 1;
};

#define __disp (uiNameSpace getVariable "ACE_Rsc_Progressbar")
#define __control (__disp displayCtrl 2)
#define __text (__disp displayCtrl 3)
switch (_unit getVariable "ACE_PB_Result") do {
	case 1: {
		_len = count (toArray (localize "STR_ACE_LADEBALKEN_READY"));
		_offs = 0.01 + ((0.1805 - ((round (_len / 2)) * 0.00976)) max 0);
		__text ctrlSetPosition [SafeZoneX + _offs, SafeZoneY + 0.045, 0.361, 0.045];
		__text ctrlSetText (localize "STR_ACE_LADEBALKEN_READY");
		__text ctrlSetTextColor [0, 1, 0, 1];
		__text ctrlCommit 0;
	};
	case 2: {
		_len = count (toArray (localize "STR_ACE_LADEBALKEN_CANCELLED"));
		_offs = 0.01 + ((0.1805 - ((round (_len / 2)) * 0.00976)) max 0);
		__text ctrlSetPosition [SafeZoneX + _offs, SafeZoneY + 0.045, 0.361, 0.045];
		__text ctrlSetText (localize "STR_ACE_LADEBALKEN_CANCELLED");
		__text ctrlSetTextColor [1, 0, 0, 1];
		_position = ctrlPosition __control;
		_position set[2, 0];
		__control ctrlSetPosition _position;
		__control ctrlCommit 0;
	};
	case 3: {
		135996 cutText["", "PLAIN"];
	};
};

if (alive _unit) then {
	//sleep 5;
	135996 cutText["", "PLAIN"];
};
