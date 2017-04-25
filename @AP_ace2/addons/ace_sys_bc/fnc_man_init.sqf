//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_unit,_groupId,_desc);

_pos = getPos _unit;
_unit setPos [_pos select 0, _pos select 1, 0.5];
diag_log [diag_frameNo, diag_TickTime, time, format["Man Init: %1, group: %2, local: %3, type: %4", _unit, group _unit, local _unit, typeOf _unit]];

[_unit, _desc, _groupId] spawn {
	PARAMS_3(_unit,_desc,_groupId);

	if !(isServer) then { waitUntil { !(isNull player) } };
	(group _unit) setGroupId [_groupId];
	_unit setVariable ["SIX_BC_UNITTYPE", _desc, false];

	if (player == _unit) then {
		[format["Matching Player found, %1 (%2, %3)", _unit, typeOf _unit, local _unit], "ace_sys_bc", [false, true, false]] call CBA_fnc_debug;

/*
		ace_sys_bc_vh0 = 'Zodiac' createVehicleLocal (getPos _unit);
		ace_sys_bc_vh0 setFuel 0;
		ace_sys_bc_vh0 setVehicleAmmo 0;
		_unit moveInCargo ace_sys_bc_vh0;
		sleep 1;
		hintC "Battle Center Mission is Initializing\nPlease be Patient, or Setup the Mission";
*/
	};
};
