//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_altitude"];

/* This script is executed by a GetOut event handler for aircrafts. */

// Argument(s) passed from the GetOut event handler. 0 = the vehicle the event handler is assigned to.
PARAMS_3(_vehicle,_role,_unit);

if !(_unit getVariable [QGVAR(jumpedout),false]) then {
	TRACE_1("Not Jumped out","");
	[_vehicle] call FUNC(retrieveWeapon);
} else {
	TRACE_1("Jumped out","");
};

// If the vehicle is one of the air vehicles that have ejection capability or is a parachute exit the script wthout continuing.

#define __isUAV (configfile >> "CfgVehicles" >> typeOf _vehicle >> "ACE_isUAV")

if ((getNumber __isUAV == 1) && {!isPlayer _unit}) exitWith {
	[_unit] spawn FUNC(nopilots_uav);
};

#define __eject (configfile >> "CfgVehicles" >> typeOf _vehicle >> "ACE_SYS_EJECT_EJECT")

_altitude = (getPos vehicle _unit) select 2;
if (_altitude > 3 || {((velocity vehicle _unit) call ACE_fnc_magnitude) > 5}) then {
	if (getNumber __eject == 1) then {
		[_vehicle,_unit] spawn FUNC(eject);
	} else {
		[_vehicle,_unit] spawn {
			private ["_v","_u","_c"];
			_v = _this select 0;
			_u = _this select 1;
			waitUntil {sleep 0.1; (vehicle _u != _v || {((getPos (vehicle _u)) select 2 < 2)})};
			_c = vehicle _u;
			if (_c isKindOf "ParachuteBase") then {
				[_c] spawn FUNC(parachute_round); // Use Pre-compiled function via "PREP" instead of compiling on the fly.
			};
		};
	};
};
