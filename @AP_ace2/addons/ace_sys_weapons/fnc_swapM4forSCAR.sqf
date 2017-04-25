/* ----------------------------------------------------------------------------
Function: ACE_fnc_swapM4forSCAR

Description:
	Switches M4 weapons for SCAR's

Parameters:
	_unit - Unit to apply to [Object]

Returns:
	Array of old and new weapon.
	Empty array incase weapon has no counterpart

Examples:
	(begin example)
		// in mission init.sqf
		if !(isDedicated) then {
			waitUntil {player == player};
			[player] call ACE_fnc_swapM4forSCAR;
		};
	(end)

	(begin example)
		// in unit init field
		vdummy = [this] spawn ACE_fnc_swapM4forSCAR;
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
// #define DEBUG_MODE_FULL
#include "script_component.hpp";


private ["_current", "_idx", "_new", "_m4", "_scar"];
PARAMS_1(_unit);

_m4 = ["ACE_M4_Eotech", "ACE_M4_AIM_GL", "ACE_M4", "ACE_M4_RCO_GL"];
_scar = ["SCAR_L_STD_HOLO", "SCAR_L_CQC_EGLM_Holo", "SCAR_L_CQC", "SCAR_L_STD_EGLM_RCO"];

_current = primaryWeapon _unit;
_idx = _m4 find _current;
if (_idx > -1) then {
	_new = _scar select _idx;
	_unit removeWeapon _current;
	_unit addWeapon _new;
	[_unit, _new] call CBA_fnc_selectWeapon;
	[_old,_new];
} else {
	[];
};
