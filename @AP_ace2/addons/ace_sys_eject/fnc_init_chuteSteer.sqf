//#define DEBUG_MODE_FULL
#include "script_component.hpp"
/* This script is executed by an Init event handler for the BIS_Steerable_Parachute, as defined in ACE sys_eject\cfgVehicles.hpp
The script will either initialize a control script for the parachute (player or AI), or delete the parachute if noone is moved into it within few seconds of its creation. */

private ["_time", "_pos", "_dir", "_vel","_para_unit"];
PARAMS_1(_vehicle);

_time = time;
waitUntil {sleep 0.1;((time - _time) > 5) || {(count (crew _vehicle) != 0)}};

if (count crew _vehicle != 0) then {
	// Check locality of parachute driver - exit if not local:
	LOG("Check locality of parachute driver - exit if not local:");
	_para_unit = (crew _vehicle) select 0;
	TRACE_1("",(crew _vehicle));
	if !(local _para_unit) exitWith {};

	// Initialize HALO variables and items as required:
	_para_unit setVariable [QGVAR(Chute_Unconc), false];
	if !("ACE_ParachutePack" in (weapons _para_unit)) then {_para_unit addWeapon "ACE_ParachutePack";};

	// Empty vehicle placed in mission editor is local to server. Delete & spawn a new one to change locality:
	_vel = velocity _vehicle;
	if !(local _vehicle) then {
		TRACE_1("_vehicle is not local. Could be Empty as in mission editor placed.",_vehicle);
		_pos = getPosASL _vehicle;
		_dir = direction _vehicle;
		deleteVehicle _vehicle;
		waitUntil {isNull _vehicle};
		#ifdef DEBUG_MODE_FULL
		_debugMsg = format["Chute _pos ATL:%1 at tickTime:%2",getPosATL _pos, diag_tickTime];
		LOG(_debugMsg);
		#endif
		_vehicle = createVehicle ["BIS_Steerable_Parachute", [0,0,100],[],0,"NONE"];
		_vehicle setDir _dir;
		_vehicle setPosASL _pos;
		_vehicle setVelocity _vel;
		waitUntil {!isNull _vehicle};

		_vel = velocity _para_unit;
		_vehicle setPosASL (getPosASL _para_unit);
		_para_unit moveinCargo _vehicle;
		_vehicle setVelocity _vel;
		waitUntil {_para_unit in _vehicle};
	} else {
		TRACE_1("_vehicle is local as expected. Good.",_vehicle);
	};

	// If it's a player in the parachute, start up the ACE steering script; else, start up the BIS AI script.
	LOG("Adding DisplayHandlers");
	if (_para_unit == player) then {
		GVAR(HALO_KEYSDN) = ["KeyDown", QUOTE(_this call FUNC(keypressed_halo))] call CBA_fnc_addDisplayHandler;
		GVAR(HALO_KEYSUP) = ["KeyUp", QUOTE(_this call FUNC(keyreleased_halo))] call CBA_fnc_addDisplayHandler;
		TRACE_2("Added DisplayHandlers",GVAR(HALO_KEYSDN),GVAR(HALO_KEYSUP));
		//[_vehicle, _para_unit, _vel] call FUNC(parachute_steer);
		#ifdef DEBUG_MODE_FULL
		_debugMsg = format["Spawning parachute_steer. Chute _pos ATL:%1 at tickTime:%2",getPosATL _vehicle, diag_tickTime];
		LOG(_debugMsg);
		#endif
		[_vehicle, _para_unit, _vel] spawn FUNC(parachute_steer);
	} else {
		_debugMsg = format["Spawning Parachute_AI. Chute _pos ATL:%1 at tickTime:%2",getPosATL _vehicle, diag_tickTime];
		LOG(_debugMsg);
		[_vehicle, _para_unit] spawn COMPILE_FILE2(ca\air2\halo\data\Scripts\Parachute_AI.sqf);
	};

} else {
	// If noone enters the chute within the first 5 seconds of its creation, just delete the chute.
	if (local _vehicle) then {
		#ifdef DEBUG_MODE_FULL
		_debugMsg = format["Player didn't enter the chute: %1 for first 5 seconds at ATL:%2 at tickTime:%3",_vehicle, getPosATL _vehicle, diag_tickTime];
		LOG(_debugMsg);
		#endif
		deleteVehicle _vehicle;
	};
};
TRACE_2("Exiting Script",_para_unit,_vehicle);