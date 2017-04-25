/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __wave ["GestureHi","GestureHiB","GestureHiC"]

_listening = player getVariable [QGVAR(listening), 0];
if (time <= _listening) exitWith {false};
player setVariable [QGVAR(listening), time + 2.5];

private "_unit";
_unit = player;
//if (cameraView == "GUNNER") exitWith {TRACE_1("Gunnerview", nil); false};
if (_unit != vehicle _unit) exitWith {TRACE_1("Vehicle is not unit", nil);false};
if (ace_sys_wounds_drag || {ace_sys_wounds_carry}) exitWith {TRACE_1("Drag or Carry", nil); false};
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith {TRACE_1("Unconscious", nil); false};

private "_target";
_target = cursorTarget;
if (isNull _target) exitWith {TRACE_1("No target", nil); false};				// Target does not exist
if !(_target isKindOf "CAManBase") exitWith {false};

_distance = _target distance _unit;
if (_distance > 5 && {_distance <= 15}) then {
	if (!alive _target) exitwith { TRACE_1("Not alive", _target) }; // Error: No Unit Fix
	
	if (side (group _target) == playerSide) then { // Call friendlies to catch attention...
		player sidechat format[localize "STR_ACE_CALL_CALLFRIENDLY", name _target];
		player playActionNow (__wave select 0);
		if (isPlayer _target) then {
			[QGVAR(confirmation), [_target, player, 69, "friendly"]] call ACE_fnc_receiverOnlyEvent;
		};
	} else { // Call at enemies
		if (side (group _target) != CIVILIAN) then { // Remove annoying waving at civilians
			player globalchat (localize "STR_ACE_CALL_CALLHOSTILE");
			player playActionNow "GestureFollow";
			if (isPlayer _target) then {
				[QGVAR(confirmation), [_target, player, 69, "enemy"]] call ACE_fnc_receiverOnlyEvent;
			} else {
				if (!isNil "BIS_SRRS_init") then {
					if (local _target) then {
						[_target, player] spawn FUNC(surrender);
					} else {
						[QGVAR(surrender), [_target, player]] call ACE_fnc_receiverOnlyEvent;
					};
				};
			};
		};
	};
};

false
