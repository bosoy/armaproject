// by Xeno
#define THIS_FILE "x_handleattackgroups.sqf"
#include "x_setup.sqf"
private ["_grps", "_allunits", "_grp", "_numdown"];

if (!isServer) exitWith {};

PARAMS_1(_grps);

_allunits = [];
{
	_grp = _x;
	_allunits = [_allunits , units _grp] call FUNC(arrayPushStack);
	sleep 0.011;
} forEach _grps;

sleep 1.2123;

_numdown =
	#ifndef __ACE__
		5;
	#else
		3;
	#endif

while {!__XJIPGetVar(GVAR(mt_radio_down))} do {
	__MPCheck;
	if ((_allunits call FUNC(GetAliveUnits)) < _numdown) exitWith {
		GVAR(c_attacking_grps) = [];
		GVAR(create_new_paras) = true;
	};
	sleep 10.623;
};

_allunits = nil;
_grps = nil;
