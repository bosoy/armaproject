//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __pSetVar player setVariable
#define __pGetVar(pvarname) (player getVariable #pvarname)

private ["_rtype", "_p", "_oabackpackmags", "_oabackpackweaps", "_ubp", "_ubackp", "_hasruck", "_ruckmags", "_ruckweapons", "_backwep", "_ident", "_oldunit", "_primw", "_muzzles", "_bp", "_mags", "_mcount", "_weaps"];

PARAMS_1(_rtype);

if (_rtype == 0) then { // player died
	_p = player;
	_oabackpackmags = [[],[]];
	_oabackpackweaps = [[],[]];
	_ubp = unitBackpack _p;
	_ubackp = if (!isNull _ubp) then {typeOf _ubp} else {""};
	if (_ubackp != "") then {
		_oabackpackmags = getMagazineCargo _ubp;
		_oabackpackweaps = getWeaponCargo _ubp;
	};
	__pSetVar [QGVAR(respawn_oabackpackmags), _oabackpackmags];
	__pSetVar [QGVAR(respawn_oabackpackweaps), _oabackpackweaps];
	__pSetVar [QGVAR(respawn_ubackp), _ubackp];

	_hasruck = false;
	_ruckmags = [];
	_ruckweapons = [];
	if (_p call ace_sys_ruck_fnc_hasRuck) then {
		_ruckmags = __pGetVar(ACE_RuckMagContents);
		_hasruck = true;
		_ruckweapons = __pGetVar(ACE_RuckWepContents);
	};
	_backwep = __pGetVar(ACE_weapononback);
	_ident = __pGetVar(ACE_Identity);
	__pSetVar [QGVAR(respawn_hasruck), _hasruck];
	__pSetVar [QGVAR(respawn_ruckmags), _ruckmags];
	__pSetVar [QGVAR(respawn_ruckweapons), _ruckweapons];
	__pSetVar [QGVAR(respawn_backwep), _backwep];
	__pSetVar [QGVAR(respawn_ident), _ident];

	__pSetVar [QGVAR(respawn_weapons), weapons player];
	__pSetVar [QGVAR(respawn_magazines), magazines player];
	__pSetVar [QGVAR(respawn_items), items player];
} else { // _rtype = 1, player has respawned
	_oldunit = (_this select 1) select 1;
	TRACE_1("",_oldunit);
	removeBackpack player;
	_p = player;
	removeAllItems _p;
	removeAllWeapons _p;
	#define __addmx _p addMagazine _x
	#define __addwx _p addWeapon _x
	{__addmx} forEach __pGetVar(GVAR(respawn_magazines));
	{
		if (getNumber (configFile >> "CfgWeapons" >> _x >> "ace_isusedweapon") == 0) then {
			__addwx;
		};
	} forEach __pGetVar(GVAR(respawn_weapons));
	{if !(_p hasWeapon _x) then {__addwx}} forEach __pGetVar(GVAR(respawn_items));

	if (__pGetVar(GVAR(earwear)) && {!(_p hasWeapon "ACE_Earplugs")}) then {_p addWeapon "ACE_Earplugs"};

	_primw = primaryWeapon _p;
	if (_primw != "") then {
		_p selectWeapon _primw;
		_muzzles = getArray(configFile >> "cfgWeapons" >> _primw >> "muzzles");
		_p selectWeapon (_muzzles select 0);
	};

	_ubackp = __pGetVar(GVAR(respawn_ubackp));
	if (_ubackp != "") then {
		if (!isNull (unitBackpack _p)) then {removeBackpack _p};
		_p addBackpack _ubackp;
		_bp = unitBackpack _p;
		clearMagazineCargoGlobal _bp;
		clearWeaponCargoGlobal _bp;
		_oabackpackmags = __pGetVar(GVAR(respawn_oabackpackmags));
		_oabackpackweaps = __pGetVar(GVAR(respawn_oabackpackweaps));
		if (count (_oabackpackmags select 0) > 0) then {
			_mags = _oabackpackmags select 0;
			_mcount = _oabackpackmags select 1;
			{_bp addMagazineCargoGlobal [_x, _mcount select _forEachIndex]} forEach _mags;
		};
		if (count (_oabackpackweaps select 0) > 0) then {
			_weaps = _oabackpackweaps select 0;
			_mcount = _oabackpackweaps select 1;
			{_bp addWeaponCargoGlobal [_x, _mcount select _forEachIndex]} forEach _weaps;
		};
	};

	_hasruck = __pGetVar(GVAR(respawn_hasruck));
	if (_hasruck) then {
		_ruckmags = __pGetVar(GVAR(respawn_ruckmags));
		_ruckweapons = __pGetVar(GVAR(respawn_ruckweapons));
		if (!isNil "_ruckmags") then {__pSetVar ["ACE_RuckMagContents", _ruckmags]};
		if (!isNil "_ruckweapons") then {__pSetVar ["ACE_RuckWepContents", _ruckweapons]};
	};
	_backwep = __pGetVar(GVAR(respawn_backwep));
	if (!isNil "_backwep" && {typeName _backwep == "STRING"}) then {__pSetVar ["ACE_weapononback", _backwep]};
	_ident = __pGetVar(GVAR(respawn_ident));
	if (_ident != "") then {
		if (isClass(configFile>>"CfgWeapons">>_ident) && {!(player hasWeapon _ident)}) then {player addWeapon _ident};
		[player, _ident] execFSM '\x\ace\addons\sys_goggles\use_glasses.fsm';
/*
		[_ident] spawn {
			PARAMS_1(_ident);
			sleep 4 + (random 1);
			["ace_sys_goggles_setident2", [player, _ident]] call CBA_fnc_globalEvent;
			__pSetVar ["ACE_Identity",_ident];
		};
*/
	};
	if (!isNil QGVAR(dead_unit_deltime) && {GVAR(dead_unit_deltime) != -1}) then {
		[_oldunit] spawn {
			PARAMS_1(_oldunit);
			if (isNil QGVAR(dead_unit_deltime)) then {GVAR(dead_unit_deltime) = 60};
			sleep GVAR(dead_unit_deltime);
			deleteVehicle _oldunit;
		};
	};
};