#include "script_component.hpp"

private "_holder";

PARAMS_1(_object);
_object setVariable [QGVAR(Parachute_Repack), true];
_type = getText(configFile >> "CfgVehicles" >> typeOf _object >> "ACE" >> "ACE_EJECT_PARACHUTE" >> "pack");

[25,[localize "STR_ACE_ADN_REPACK_PARACHUTE"],false,true,player,true] spawn ace_progressbar;
waitUntil { (player getVariable "ACE_PB_Result" != 0) };

if (player getVariable "ACE_PB_Result" == 1) then {
	sleep 3;

	// Create Parachute Pack on ground
	_holder = createVehicle ["WeaponHolder", getPosATL player, [], 0, "NONE"];
	_holder addWeaponCargoGlobal [_type, 1];
	_pos = getPos _holder;
	_holder setpos [_pos select 0, _pos select 1, (_pos select 2) + 0.1];
	sleep 0.5;
	deleteVehicle _object;
	player reveal _holder;
} else {
	player setVariable ["ACE_PB_Result", 0];
	_object setVariable [QGVAR(Parachute_Repack), false];
};

TRACE_1("Exiting Script",_jumper);