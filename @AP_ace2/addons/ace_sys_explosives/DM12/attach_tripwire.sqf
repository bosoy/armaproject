#include "\x\ace\addons\sys_explosives\script_component.hpp"

if (GVAR(tripwire_lock)) exitWith {};

waitUntil { !GVAR(tripwire_lock) };

GVAR(tripwire_lock) = true;

_mine = _this;

_z = [_mine] call CBA_fnc_realHeight;
_pos = position _mine;
_tripwire_point_a = [_pos select 0, _pos select 1, _z];
_mine setVariable [QGVAR(tw_start),_tripwire_point_a,true];

_A_ID = player addAction [localize "STR_ACE_EXPL_CTRIPEOPTICAL", (PATH + "end_tripwire.sqf"),[_mine],-1,false,true,"","_target == player"];

GVAR(waiting_for_tripwire) = true;
waitUntil { !GVAR(waiting_for_tripwire) || {!alive player} };

if !(alive player) exitWith {
	GVAR(tripwire_lock) = false;
	player removeAction _A_ID;
};
player removeAction _A_ID;

GVAR(tripwire_lock) = false;

_mine setVariable [QGVAR(tw),true,true];
