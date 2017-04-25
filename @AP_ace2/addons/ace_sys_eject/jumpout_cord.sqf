//#define DEBUG_MODE_FULL
#include "script_component.hpp"
// BIS Style HALO
/* THIS script handles the player (and maybe AI) once they jumped out of an aircraft WITHOUT using an ejection seat
   At first this script handles HALO'in if a parachute pack is carried.
   If not a looped panicing freefall animation is played until the jumper smashes into the ground
*/
#define ACE_TEXT_RED(Text) ("<t color='#FF0000'>" + ##Text + "</t>")
private ["_action"];
PARAMS_1(_jumper);
_jumper setVariable [QGVAR(ChuteOpen), 0, false];
#ifdef DEBUG_MODE_FULL
_debugMsg = format["JUMPOUT_CORD: Should only be called once for _jumper %1 starting ATL:%2 at tickTime:%3",name _jumper, getPosATL _jumper, diag_tickTime];
LOG(_debugMsg);
#endif
/*
if (_jumper == player) then {
	_jumper say3D "BIS_HALO_Flapping";
	[] spawn {
		titleCut ["", "BLACK FADED", 50];
		sleep 0.5;
		titleCut ["", "BLACK IN", 2];
	};
};
*/

_jumper spawn {
	_t1 = time;
	waitUntil {!alive _this || {vehicle _this != _this} || {(position _this select 2) < 1}};
	if (vehicle _this == _this) exitWith {
		//_this switchMove "aidlppnemstpsraswrfldnon0s"; // switch player to a prone anim so they don't stand up and die, but stay "horizontal"
		[QGVAR(dieanim), _this] call CBA_fnc_globalEvent;
	};
};

// If jumper has NO parachutepack: Exit with panic animation
if (_jumper == player && {!((_jumper hasWeapon "ACE_ParachutePack") || {(_jumper hasWeapon "ACE_ParachuteRoundPack")})}) exitWith {
	[QGVAR(anim), _jumper] call CBA_fnc_globalEvent; // FreeFall animation needs to be added for NO Chute
};

[QGVAR(anim), _jumper] call CBA_fnc_globalEvent;

// If jumper is not a human player then automatically deploy chute and exit the script without continuing.
if (_jumper != player) exitWith {
	// HALO for AI (vanilla BIS version - may be replaced or improved later on)
	if (_jumper hasWeapon "ACE_ParachutePack") then {
		[_jumper] exec "ca\air2\halo\data\Scripts\HALO_AI.sqs";
	} else {
        if (_jumper hasWeapon "ACE_ParachuteRoundPack") then {
			sleep 2; // Delay in auto-open of T-10 canopy after jumping out. This may need to be adjusted.
			[_jumper,_jumper] spawn COMPILE_FILE(ripcord);
		};
	};
};

// All code from this point forward only runs if the jumper is a human player.

if (_jumper hasWeapon "ACE_ParachutePack") then {
	_action = _jumper addAction [ACE_TEXT_RED(localize "STR_ACE_EJECT2"), QPATHTO_F(ripcord), [], 10, true, true, "SALUTE"];
	// Run skydive control:
	GVAR(HALO_KEYSDN) = ["KeyDown", QUOTE(_this call FUNC(keypressed_halo))] call CBA_fnc_addDisplayHandler;
	GVAR(HALO_KEYSUP) = ["KeyUp", QUOTE(_this call FUNC(keyreleased_halo))] call CBA_fnc_addDisplayHandler;
	_jumper spawn COMPILE_FILE(fnc_skydive);

	// Visual effects:
	"RadialBlur" ppEffectAdjust [0.0, 0.0, 0.0, 0.0];
	"RadialBlur" ppEffectCommit 1;
	"RadialBlur" ppEffectEnable true;

	// SCRIPT TO CREATE GAMELOGICS PLAYING SKYDIVING AIR-RUSH SOUND BELOW PLAYER -- why did I do it this way for ACE 1? why not just use a playsound or something? I will look into this later - Homer J.
	_jumper spawn {
		// Create sound dummies - used 2 so that the sound overlaps better... if just one, you could hear a blip when it repeated;
		// POTENTIAL TO-DO: use one long (60 second?) sound file that will last the entire skydive
		_dummy1 = "ACE_LogicDummy" createVehicleLocal [getPos _this select 0,getPos _this select 1,0];
		_dummy2 = "ACE_LogicDummy" createVehicleLocal [getPos _this select 0,getPos _this select 1,0];
		//TRACE_2("Dummy Check",_dummy1,_dummy2);
		// SPAWN script which relocates dummy sound makers to directly below the player
		[_this,_dummy1,_dummy2] spawn {
			PARAMS_1(_jumper);
			while {vehicle _jumper == _jumper && {alive _jumper} && {(position _jumper select 2) > 5}} do {
				_pos = [getpos _jumper select 0,getpos _jumper select 1,0];
				(_this select 1) setPos _pos;
				(_this select 2) setPos _pos;
				sleep 0.1;
			};
			// Now player is in a parachute, or dead on the ground
			sleep 0.5;
			deleteVehicle (_this select 1);
			deleteVehicle (_this select 2);
		};
		// SPAWN script which makes dummy sound makers say the wind sound
		[_this,_dummy1,_dummy2] spawn {
			PARAMS_3(_jumper,_dummy1,_dummy2);
			_i = 0;
			_dar = [_dummy1,_dummy2];
			while {vehicle _jumper == _jumper} do {
				(_dar select _i) say3D "SkyDiveWind";
				_i = abs (_i - 1);
				sleep 15;
			};
		};
	};
} else {
	sleep 1.5; // Delay in auto-open of T-10 canopy after jumping out. This may need to be adjusted.
	[_jumper,_jumper] spawn COMPILE_FILE(ripcord);
};
TRACE_1("Exiting Script",_jumper);