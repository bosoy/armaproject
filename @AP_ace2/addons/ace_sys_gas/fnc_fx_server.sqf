/* ace_sys_gas (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

private["_combatMode", "_behaviour"];

PARAMS_2(_unit,_type);

if ((_unit getVariable "ACE_Identity") in ["ACE_GlassesGasMask_US","ACE_GlassesGasMask_RU"]) exitWith {};

_combatMode = combatMode _unit;
_behaviour = behaviour _unit;

switch(_type) do {
	// 1: AI
	case 1:	{
		_unit setCombatMode "Green";
		_unit setBehaviour "SAFE";
		_unit disableAI "AUTOTARGET";
		_unit disableAI "TARGET";
		_unit doWatch [(position _unit) select 0,(position _unit) select 1, 1000];

		// Create a viewblock for AI on the server // Locality stuff bla bla
		_ace_vb_type = "ACE_Viewblock_Gas"; //"ACE_Viewblock_Gas_Debug"
		_ace_vb_ai = _ace_vb_type createVehicleLocal getPos _unit;
		_ace_vb_ai attachTo [_unit, [0,0,0], ""];
		sleep 5;
		if (alive _unit) then {
			_unit enableAI "AUTOTARGET";
			_unit enableAI "TARGET";
			_unit setCombatMode _combatMode;
			_unit setBehaviour _behaviour;
			_unit dowatch objNull;
		};
		detach _ace_vb_ai;
		deleteVehicle _ace_vb_ai;
	};
};
