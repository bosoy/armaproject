/* This function is called from: fnc_NewWeap.sqf */

#include "script_component.hpp"
//reads the absolute drop table and changes it into the table relative to zero
#include "Script_SightAdjustmentConfig.hpp"

private ["_t","_z","_elz","_rng","_el"];

_t = getArray (_this >> "ace_sa_table_elev");
_z = if (ACE_SYS_SA_RFL_WCFG_ADJMODE == "angle") then {
	getNumber (_this >> "ace_sa_defaultrange")
} else {
	getNumber (_this >> "ace_sa_zeroelev")
};
{
	if ((_x select 0)==_z) exitwith {_elz = _x select 1};
} foreach _t;
if (_z != 0) then {
	for "_i" from 0 to (count _t - 1) do {
		_rng = (_t select _i) select 0;
		_el = (_t select _i) select 1;
		_t set [_i, [_rng,_el - _elz]];
	};
};
_z = getNumber (_this >> "ace_sa_defaultrange");
{
	if ((_x select 0)==_z) exitwith {_elz = _x select 1};
} foreach _t;

//returning table and default elevation user should see
[_t,_elz];
