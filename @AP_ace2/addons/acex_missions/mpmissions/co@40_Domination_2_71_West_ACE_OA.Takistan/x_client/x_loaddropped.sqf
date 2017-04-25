// by Xeno
#define THIS_FILE "x_loaddropped.sqf"
#include "x_setup.sqf"
private ["_unit", "_caller", "_chatfunc", "_height", "_speed", "_hasbox", "_str", "_nobjs", "_box"];

if (!X_Client) exitWith {};

PARAMS_2(_unit,_caller);

_chatfunc = {
	if (vehicle (_this select 1) == (_this select 0)) then {
		[_this select 0, _this select 2] call FUNC(VehicleChat);
	} else {
		[_this select 1, _this select 2] call FUNC(SideChat);
	};
};

if (_unit == _caller) then {_unit = GVAR(curvec_dialog)};

if (_caller != driver _unit && !isNil {GV(_unit,GVAR(choppertype))}) exitWith {};

_height = _unit call FUNC(GetHeight);
if (_height > 3) exitWith {[_unit,(localize "STR_DOM_MISSIONSTRING_267")] call FUNC(VehicleChat)};
_speed = speed _unit;
if (_speed > 3) exitWith {[_unit,(localize "STR_DOM_MISSIONSTRING_268")] call FUNC(VehicleChat)};

_hasbox = GV(_unit,GVAR(ammobox));
if (isNil "_hasbox") then {_hasbox = false};
if (_hasbox) exitWith {[_unit, _caller, (localize "STR_DOM_MISSIONSTRING_269")] call _chatfunc};

_time_next = GV(_unit,GVAR(ammobox_next));
if (isNil "_time_next") then {_time_next = -1};
if (_time_next > time) exitWith {[_unit, _caller, format [(localize "STR_DOM_MISSIONSTRING_270"), round (_time_next - time)]] call _chatfunc};

_nobjs = nearestObjects [_unit, [GVAR(the_box)], 20];
if (count _nobjs == 0) exitWith {[_unit, _caller, (localize "STR_DOM_MISSIONSTRING_271")] call _chatfunc};
_box = _nobjs select 0;
[_unit, _caller, (localize "STR_DOM_MISSIONSTRING_272")] call _chatfunc;
[QGVAR(r_box), position _box] call FUNC(NetCallEvent);
_unit setVariable [QGVAR(ammobox), true, true];
_time_next = time + GVAR(drop_ammobox_time);
_unit setVariable [QGVAR(ammobox_next), _time_next, true];
[_unit, _caller, (localize "STR_DOM_MISSIONSTRING_273")] call _chatfunc;