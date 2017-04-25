/* ace_fx_fnc_ring

Plays a ring sound for player

Parameters:
_unit - Needed to check against player unit
_alt - Choose between an alternative sound to play
_distance - Distance, needed for some other calculations
_sound1 - Specify the first sound to be played
_sound2 - Specify the second sound to be played
_deafen - Deafen afterwards

*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __MAX 12

private ["_sound","_sound_length"];

PARAMS_6(_unit,_alt,_distance,_sound1,_sound2,_deafen);

if !(isPlayer _unit) exitWith { TRACE_1("Not player",nil); };
if !(alive _unit) exitWith { TRACE_1("Not alive",nil); };
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith { TRACE_1("Uncon",nil); };
_crpt2 = _unit getVariable "ACE_CrewProtection_combatdeaf";if (isNil "_crpt2") then {_crpt2 = false};
if (_crpt2) exitWith {};

if (isNil "_alt") then { _alt = false };
if (isNil "_distance") then { _distance = -1 };
if (isNil "_sound1") then { _sound1 = "ACE_Ring_Backblast" };
if (isNil "_sound2") then { _sound2 = _sound1 };
if (isNil "_deafen") then { _deafen = false };

if (_distance >= __MAX && {(_unit call ACE_fnc_hasCrewProtection)}) exitWith {};
if (_distance >= __MAX && {([_unit] call ace_sys_goggles_fnc_earprotection)}) exitWith {};

_sound = if (_alt) then { _sound2 } else { _sound1 };
if (isClass (configFile >> "CfgSounds" >> _sound)) then {
	_sound_length = getNumber (configFile >> "CfgSounds" >> _sound >> "ace_fx_sound_length");
} else {
	_sound_length = 15;
};

if (isnil {_unit getVariable QGVAR(ring)}) then {
	_unit setVariable[QGVAR(ring), time];
	playSound _sound;
	if (_deafen) then { [_unit,10] call ace_fx_fnc_deaf };
} else {
	if (((_unit getVariable QGVAR(ring)) + _sound_length) < time) then {
		_unit setVariable[QGVAR(ring), time];
		playSound _sound;
		if (_deafen) then { [_unit,10] call ace_fx_fnc_deaf };
	};
};