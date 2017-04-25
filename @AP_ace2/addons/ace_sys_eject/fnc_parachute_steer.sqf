// #define DEBUG_MODE_FULL
#include "script_component.hpp"
/*
This script is the actual steering algorithm for the parachute. It is called after the player pulls his ripcord (Ripcord.sqf)
How it works (sort of): approx. 100 times a second it checks whether the player has a steering key pressed down by the
player vehicle variables ACE_ChuteSteer, and ACE_ChutePitch. Holding these keys change the position where the parachute "wants to point" ...
the parachute is always moved slowly towards that position.
*/

#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")

// THIS is the main "control script" -- everything in this .sqf is executed exactly in the order presented within:
private ["_chute", "_jumper", "_target", "_scripthandle"];
PARAMS_1(_chute);
// avoid running twice!
if !(isNil {_chute getVariable QGVAR(ChuteControlOn)}) exitWith {};
_chute setVariable [QGVAR(ChuteControlOn),true];
_jumper = _this select 1;
_chute lock true;
_jumper setVariable [QGVAR(ChuteHit), false, false];
_Para_HitEH = _jumper addEventHandler ["Hit", {if (vehicle (_this select 0) == vehicle (_this select 1)) then {(_this select 0) setVariable [QGVAR(ChuteHit), true]}}];
_chute addAction [ACE_TEXT_RED(localize "STR_ACE_CUTCHUTE"),QPATHTO_F(fnc_cutchute),[],100,false,false,"Eject"];
// SPAWN script which makes parachute say chuteflutter
[_chute, _jumper] spawn {
	private ["_chute", "_jumper"];
	_chute = _this select 0;
	_jumper = _this select 1;
	waitUntil {(vehicle _jumper) == _chute};
	while {vehicle _jumper == _chute} do {
		_chute say "ChuteFlutter2";
		sleep 10;
	};
};
hintSilent "";

if ((_jumper getVariable QGVAR(ChuteOpen)) == 4) then {cutText ["Reserve parachute open!", "PLAIN DOWN"]; _jumper removeWeapon "ACE_ParachutePack";};
_jumper setVariable [QGVAR(ChuteOpen),1];

_scripthandle = _this spawn FUNC(ChuteSteer); // start f_Chutesteer loop, and wait til it is done
waitUntil {scriptDone _scripthandle};
_jumper removeEventHandler ["Hit", _Para_HitEH];
if ((_jumper getVariable QGVAR(ChuteOpen)) == 2) then {
	_this spawn FUNC(CutChute)
} else {
	_this spawn FUNC(ChuteDelete)
};
