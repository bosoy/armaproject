/* ace_sys_g_effects (.pbo) | (c) 2008, 2009 by rocko */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// Purpose of this addon is: only pilots are supposed to fly planes without being affected by G-Forces
// Flyboy grunts suffer or play BF

PARAMS_1(_o);

waitUntil {sleep 0.221;!alive _o || {(getpos _o) select 2 > 1} || {!(_o getVariable QGVAR(eon))}};
if (!alive _o || {!(_o getVariable QGVAR(eon))}) exitWith {};

private["_pfhandle","_blouthandle","_blurrhandle","_roundhandle","_resetneeded"];
if (_o getVariable ["ACE_pinplane", false]) exitWith {};
_o setVariable ["ACE_pinplane", false];
_o setVariable ["ACE_gforce", 0];
_o setVariable ["ACE_g_s", 0];

waitUntil {!isNil "CBA_fnc_addPerFrameHandler"};
_pfhandle = -9999;
_resetneeded = false;

while {alive _o && {(_o getVariable QGVAR(eon))}} do {
	while {alive _o && {(getpos _o) select 2 > 1}} do {
		if (alive player && {player in _o} && {!(_o isKindOf "BIS_Steerable_Parachute")} && {!(_o isKindOf "ParachuteBase")}) then {
			if !(_o getVariable "ACE_pinplane") then {
				GVAR(sleepend) = 0;
				GVAR(next_checkg) = -1;
				GVAR(v0) = [];
				GVAR(v1) = [];
				GVAR(b_blackout_timeend) = -1;
				GVAR(g_blurr_timeend) = -1;
				GVAR(g_blurr_reson) = false;
				GVAR(g_round_timeend) = -1;
				_pfhandle = [FUNC(g_func), 0, vehicle _o] call CBA_fnc_addPerFrameHandler;
				_blouthandle = [FUNC(g_blackout), 0, vehicle _o] call CBA_fnc_addPerFrameHandler;
				_blurrhandle = [FUNC(g_blurr), 0, vehicle _o] call CBA_fnc_addPerFrameHandler;
				_roundhandle = [FUNC(g_round), 0, _o] call CBA_fnc_addPerFrameHandler;
				_o setVariable ["ACE_pinplane", true];
				_resetneeded = true;
			};
		} else {
			if (_pfhandle != -9999) then {
				[_pfhandle] call CBA_fnc_removePerFrameHandler;
				[_blouthandle] call CBA_fnc_removePerFrameHandler;
				[_blurrhandle] call CBA_fnc_removePerFrameHandler;
				[_roundhandle] call CBA_fnc_removePerFrameHandler;
				_pfhandle = -9999;
				_o setVariable ["ACE_pinplane", false];
				_o setVariable ["ACE_gforce", 0];
				_o setVariable ["ACE_g_s", 0];
				_resetneeded = false;
				// turn off all effects because the g effects functions are no longer attached to the frame handler
				13526 cutFadeOut 0;
				"dynamicBlur" ppEffectEnable false; // not sure if sys eject uses dynamicBlurr too
				135887 cutRsc ["ACE_geffectsfb_nothing","PLAIN"];
			};
			sleep 1.01;
		};
	};
	sleep 0.01;
	if (_resetneeded) then {
		_o setVariable ["ACE_pinplane", false];
		_o setVariable ["ACE_gforce", 0];
		_o setVariable ["ACE_g_s", 0];
		_resetneeded = false;
	};
};

if (_pfhandle != -9999) then {
	[_pfhandle] call CBA_fnc_removePerFrameHandler;
	[_blouthandle] call CBA_fnc_removePerFrameHandler;
	[_blurrhandle] call CBA_fnc_removePerFrameHandler;
	[_roundhandle] call CBA_fnc_removePerFrameHandler;
	_pfhandle = -9999;
};

if (alive _o) then {
	_o setVariable [QGVAR(eon), false];
	_o setVariable ["ACE_pinplane", false];
	_o setVariable ["ACE_gforce", 0];
	_o setVariable ["ACE_g_s", 0];
};
