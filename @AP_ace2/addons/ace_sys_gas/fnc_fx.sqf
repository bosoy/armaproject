/* ace_sys_gas (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

private["_combatMode", "_behaviour"];

PARAMS_2(_unit,_type);

if ((_unit getVariable "ACE_Identity") in ["ACE_GlassesGasMask_US","ACE_GlassesGasMask_RU"] && {!(_unit getVariable "ace_gas_time" > 3)}) exitWith {};

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
		sleep 5;
		if (alive _unit) then {
			_unit enableAI "AUTOTARGET";
			_unit enableAI "TARGET";
			_unit setCombatMode _combatMode;
			_unit setBehaviour _behaviour;
			_unit dowatch objNull;
		};
	};
	// 2: PLAYER
	case 2:	{
		135210 cutText["", "WHITE IN"];
		135210 cutFadeOut (0.5);

		GVAR(blur) ppEffectEnable true;
		_i = 1;
		[player,120,10] spawn ace_fx_fnc_cough;
		while { _i < 10 } do {
			if (!alive player || {ace_sys_spectator_SPECTATINGON}) exitWith {};
			GVAR(blur) ppEffectAdjust [_i + 10];
			GVAR(blur) ppEffectCommit 2;
			_i = _i + 1;
			sleep 0.2;
		};
		if (alive player && {!ace_sys_spectator_SPECTATINGON}) then {
			sleep 4;
		};
		GVAR(blur) ppEffectEnable false;
		call ace_fx_fnc_blind_view;
	};
};
