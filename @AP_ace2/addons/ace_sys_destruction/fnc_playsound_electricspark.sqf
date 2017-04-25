#include "script_component.hpp"
private ["_c","_sound"];

if (random 5 > 1) exitWith {};

_c = {isPlayer _x} count (crew _this);

_sound = ["ace_electricspark1","ace_electricspark2","ace_electricspark3","ace_electricspark4","ace_electricspark5","ace_electricspark6","ace_electricspark7","ace_electricspark8"] select (floor random 8);

if !(isDedicated) then {
	if (_c == 1 && {(player in _this)} && {(cameraView in ["GUNNER","INTERNAL"])}) then {
		playSound _sound;
	} else {
		[QGVAR(handle_playsound_electricspark), [_this,_sound]] call CBA_fnc_globalEvent;
	};
} else {
	[QGVAR(handle_playsound_electricspark), [_this,_sound]] call CBA_fnc_globalEvent;
};
