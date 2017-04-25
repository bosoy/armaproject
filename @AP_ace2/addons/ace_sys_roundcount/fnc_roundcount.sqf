//#define DEBUG_MODE_FULL
/* ace_roundcount.sqf | (c) 2008 by rocko */
// ACE 2 ver 2010 by Xeno

#include "script_component.hpp"

private ["_keysar", "_reload", "_key", "_type"];

_notPlayer = vehicle player != player;
if (vehicle player isKindOf "StaticWeapon") then { _notPlayer = false };

if (!alive player || {_notPlayer} || {(player call ace_sys_wounds_fnc_isUncon)}) exitWith {false};

PARAMS_2(_type,_keysar);

_reload = actionKeys "ReloadMagazine";
_key = _keysar select 1;
TRACE_2("",_key,_reload);

if (_type == 0 && {!(_key in _reload)}) exitWith {
	TRACE_2("exiting, type = 0 and key not in _reload",_key,_reload);
	false
};

[_type,_key] spawn FUNC(rcaction);

if (_key in (actionKeys "SitDown")) exitWith {
	TRACE_2("returning true, in SitDown",_key,_reload);
	true
};
TRACE_2("returning false",_key,_reload);

false
