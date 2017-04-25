#include "script_component.hpp"

//	This script is called on init. It checks unit's magazine space and when needed
//	changes the mags to the ones compatible with the unit's weapon. Thus there's no need to specify
//	magazines specific to this particular weapon in the soldier's config, as everything is done automatically.

//if (ACE_Sys_Magazines_Debug) then {player globalchat "Inv check started"};
TRACE_1("invInit","");

private ["_unit", "_lastWeap", "_lastMuzzle", "_curWeap", "_lastCount", "_cfg", "_weapMags", "_altMags", "_unitMags", "_muzzles"];
_unit = player; //_this select 0;
_curWeap = currentWeapon _unit;

{ // process primary and sidearm

	_lastWeap = _x;
	if (!(local _unit) || {(_lastWeap == "")}) exitWith {};
	_lastCount = count (magazines _unit);
	_cfg = (configFile >> "CfgWeapons" >> _lastWeap);
	_weapMags = getArray (_cfg >> "magazines");
	_lastMuzzle = _lastWeap;
	_muzzles = getArray (_cfg >> "muzzles");
	if ("this" != (_muzzles select 0)) then {
		_lastMuzzle = _muzzles select 0;
		if (_lastMuzzle != "this") then { _cfg = (_cfg >> _lastMuzzle) };
		_weapMags = getArray (_cfg >> "magazines");
	};

	// [format ["unit %1 weapon %2 muzzle %3", _unit, _lastWeap, _lastMuzzle]] call ACE_fDebug;
	//["check started"] call ACE_fDebug;
	_unitMags = magazines _unit;
	TRACE_6("",_unit,_lastWeap,_lastCount,_cfg,_weapMags,_lastMuzzle);
	{ [_unit,_lastWeap,_weapMags,_x] call FUNC(MagReplace) } forEach _unitMags;

	if (_unit ammo _lastMuzzle < 1 ) then { 		//re-adding the weapon so the mag is already loaded.
		[_unit, _lastWeap] call CBA_fnc_RemoveWeapon;
		[_unit, _lastWeap] call CBA_fnc_AddWeapon;
		_unit selectweapon _lastMuzzle;
	};

} forEach [[_unit] call ACE_fnc_getPistol, primaryWeapon _unit];

//if (ACE_Sys_Magazines_Debug) then {player globalchat "Inv check finished"};
