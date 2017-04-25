/* ace_fx_explosions | (c) 2013 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private["_p","_ar","_i"];

PARAMS_5(_projectile,_ihr,_ammo,_m,_d);
_p = getPosASL _projectile;

// Always sleep at least 0.3 to give other scripts a chance to take away the projectile, without us thinking the round has exploded..
if (_d < 0.3) then {
	_d = 0.3;
};
// player sideChat format["d: %1", _d];
_delay = diag_tickTime + _d;

if !(alive _projectile) exitwith {};

_funcTrack = {
	private ["_delay", "_pos", "_ammo", "_ammoType", "_ihr", "_m"];
	_params = _this select 0;
	
	_delay = _params select 0;
	_pos = _params select 1;
	_ammo = _params select 2;
	_ammoType = _params select 3;
	_ihr = _params select 4;
	_m = _params select 5;
	if (diag_tickTime > _delay) then {
		if (alive _ammo && {!isNull _ammo}) then {
			_pos = getPosASL _ammo;
			// player sideChat format["p: %1", _pos];
			_params set[1, _pos];
		} else {
			TRACE_3("",_pos,_ammoType,_ammoType isKindOf "Grenade");

			if (_ammoType isKindOf "Grenade") then {
				// Grenades only fired eventhandler where the unit is local, so we have to public it
				[QGVAR(trigger), [_pos,_ihr,_ammoType,_m]] call CBA_fnc_globalEvent;
			} else {
				[_pos,_ihr,_ammoType,_m] call FUNC(trigger);
			};
			// player sideChat format["DF"];
			[_this select 1] call cba_fnc_removePerFramehandler;
		};
	};
};

[_funcTrack, 0, [_delay, _p, _projectile, _ammo, _ihr, _m]] call cba_fnc_addPerFramehandler;
