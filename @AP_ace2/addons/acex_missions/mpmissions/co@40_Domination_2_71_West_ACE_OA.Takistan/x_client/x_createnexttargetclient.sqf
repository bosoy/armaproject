// by Xeno
#define THIS_FILE "x_createnetxttargetclient.sqf"
#include "x_setup.sqf"
private ["_current_target_name","_current_target_pos","_marker","_t_array","_current_target_radius"];
if (!X_Client) exitWith{};

sleep 1.012;
_t_array = GVAR(target_names) select __XJIPGetVar(GVAR(current_target_index));
_current_target_pos = _t_array select 0;
_current_target_name = _t_array select 1;
_current_target_radius = _t_array select 2;

#ifndef __TT__
[_current_target_name, _current_target_pos,"ELLIPSE","ColorRed",[_current_target_radius,_current_target_radius]] call FUNC(CreateMarkerLocal);
#else
[_current_target_name, _current_target_pos,"ELLIPSE","ColorYellow",[_current_target_radius,_current_target_radius]] call FUNC(CreateMarkerLocal);
#endif
QGVAR(dummy_marker) setMarkerPosLocal _current_target_pos;

if (!isNil QGVAR(task1)) then {GVAR(task1) setTaskState "Succeeded"};

if (GVAR(current_seize) != _current_target_name) then {	
	private ["_dtnum", "_dtform", "_dtask"];
	_dtnum = __XJIPGetVar(GVAR(current_target_index)) + 2;
	_dtform = format ["d_task%1", _dtnum];
	__mNsSetVar [_dtform, player createSimpleTask [format ["obj%1", _dtnum]]];
	_dtask = __getMNsVar2(_dtform);
	
	_dtask setSimpleTaskDescription [format [(localize "STR_DOM_MISSIONSTRING_202"), _current_target_name], format [(localize "STR_DOM_MISSIONSTRING_203"), _current_target_name], format [(localize "STR_DOM_MISSIONSTRING_203"), _current_target_name]];
	_dtask setTaskState "Created";
	_dtask setSimpleTaskDestination _current_target_pos;
	GVAR(current_task) = _dtask;
};

playSound "IncomingChallenge2";
[GVAR(current_task), "CREATED"] spawn FUNC(TaskHint);

hint format [(localize "STR_DOM_MISSIONSTRING_204"), _current_target_name];
