//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

#define VEH_CFG configFile >> "CfgVehicles" >> typeOf _target
#define C_WEAPON configFile >> "CfgWeapons"
#define C_MAGAZINE configFile >> "CfgMagazines"

private ["_menuDef", "_target", "_params", "_menuName", "_menuRsc", "_menus"];

PARAMS_2(_target,_params);

_menuDef = [];
_menuName = "";
_menuRsc = "popup";

if (typeName _params == typeName []) then {
	if (count _params < 1) exitWith {diag_log format["Error: Invalid params: %1, %2", _this, __FILE__];};
	_menuName = _params select 0;
	_menuRsc = if (count _params > 1) then {_params select 1} else {_menuRsc};
} else {
	_menuName = _params;
};

if (_target isKindOf "Animal" || {_target isKindOf "ACE_Viewblock_Base"}) exitWith { _menuDef }; // Because CSW, grab AllVehicles... probably also CaManBase

//-----------------------------------------------------------------------------

GVAR(targets) = [_target,(typeOf _target)];

//-----------------------------------------------------------------------------

_menus = [];

// Get turrets
_cfg = (configFile >> "CfgVehicles" >> typeOf _target >> "Turrets");
_turrets = [_cfg] call BIS_fnc_returnVehicleTurrets;

// Get Weapons and magazines for the turrets, compatible with magXchange
_weapons = []; // Vehicle weapons
_magazines = []; // Vehicle magazines
_turretPaths = []; // Vehicle turretpaths
_ar = [];
_fncGetWeapons = {
	PARAMS_2(_data,_ar);
	for "_i" from 0 to (count _data) - 1 do {
		if (_i % 2 == 0) then {
			_turIdx = _data select _i;
			PUSH(_ar,_turIdx);
			_w = _target weaponsTurret _ar;
			PUSH(_weapons,_w);
			_m = _target magazinesTurret _ar; // getArray(_tur >> "magazines");
			PUSH(_magazines,_m);
			PUSH(_turretPaths,+_ar);
			_turs = _data select (_i + 1);
			[_turs, _ar] call _fncGetWeapons;
		} else {
			_ar reSize (count _ar - 1);
		};
	};
};

[_turrets, _ar] call _fncGetWeapons;
TRACE_3("",_weapons,_magazines,_turretPaths);

// Only CSW-support Static or whatever vehicle that has Crewserved interaction setup.
_CSW = getText(VEH_CFG >> "ACE" >> "ACE_CREWSERVED" >> "interaction");
_isCSW = _CSW != "";
_isNoCSW = _CSW == "XXX";
_fireOnLoad = getNumber(VEH_CFG >> "ACE" >> "ACE_CREWSERVED" >> "fireOnReload") == 1;

_isDragon = (typeof _target == "ACE_M47_Static" && {secondaryWeapon player == ""} && {_target animationPhase "missile_hide" != 1} && {count (crew _target) == 0});

//if (_isNoCSW && !_isDragon) exitWith {_menuDef};

if (_menuName != "ACE_xChange") then {
	_menus set [count _menus,
	[
		["main", "Crew served weapon", _menuRsc],
		[
			["CSW Menu",
				{ GVAR(targets) spawn COMPILE_FILE(MGCrewMenu) },
				"", "", "", DIK_C, 1, _isCSW && {!_isNoCSW} && {ACE_ASSEMBLE && ACE_DISASSEMBLE} && {ACE_SELFINTERACTION_RESTRICTED}],
				
			["Switch Fire on Load",
				{ [CBA_ui_target] call FUNC(swapFireReload) },
				"", "", "", -1, 1, _fireOnLoad],
				
			[localize "STR_ACE_CREW_UNMOUNTDRAGON",
				{ [player, CBA_ui_target] spawn FUNC(packDragon) },
				"","","", -1, 1, (_isDragon && {!(player call FUNC(busy))} && {ACE_SELFINTERACTION_RESTRICTED})],
				
			[(localize "STR_ACE_VEHICLE_EXCHANGE")+" >",
				"","", localize "STR_ACE_VEHICLE_EXCHANGE",
				[QUOTE(PATHTO_SYS(PREFIX,sys_crewserved,fnc_menuDef)), "ACE_xChange",1],
				DIK_E, (player in _target || {(count (crew _target) == 0)}), alive _target && {ACE_ASSEMBLE} && {ACE_DISASSEMBLE} && {!_isCSW} && {count _weapons > 0} && {ACE_SELFINTERACTION_RESTRICTED}]
		]
	]];
} else {
	_menus2 = []; _menus3 = [];

	_allWeps = [];
	_alltps = [];
	_weps = [];
	_mags = [];
	_tps = [];
	for "_i" from 0 to (count _weapons) - 1 do {
		_w = _weapons select _i;
		_m = _magazines select _i;
		_tp = _turretPaths select _i;
		{ PUSH(_allWeps,_x); PUSH(_allTps,_tp); } forEach _w;
		_tmp = [];
		{
			if !(_x in _tmp) then {
				_cfg = (C_MAGAZINE >> _x >> "ACE" >> "ACE_CREWSERVED" >> "ACE_magXchange");
				if (isText _cfg) then {
					PUSH(_tmp,_x);
					PUSH(_mags,_x);
					_mag = _x;
					_weap = "";
					{
						_cfg = C_WEAPON >> _x;
						if (_mag in (getArray(_cfg >> "magazines"))) exitWith {
							_weap = _x;
						};
					} forEach _w;
					PUSH(_weps,_weap);
					PUSH(_tps,_tp);
				};
			};
		} forEach _m;
	};
	TRACE_3("",_weps,_mags,_tps);

	// Build menu
	_menus2 = [];
	for "_i" from 0 to (count _weps) - 1 do {
		_weap = _weps select _i;
		_mag = _mags select _i;
		_tp = _tps select _i;
		_ammoCount = _target ammo _weap; // No muzzles handled yet for vehicles
		if (_ammoCount == 0 && {player in _target}) then {
			_ammoCount = player ammo _weap; // No muzzles handled yet for vehicles
		};

		_cfg = C_MAGAZINE >> _mag;
		_count = getNumber(_cfg >> "count");
		TRACE_3("",_mag,_count,_ammoCount);

		_cfg = configFile >> "CfgWeapons" >> _weap;
		_dn = if (isText(_cfg >> "displayNameShort")) then { getText(_cfg >> "displayNameShort") } else { getText (_cfg >> "displayName") };

		_entry = [
		format["<t size='0.75'>"+(localize "STR_ACE_VEHICLE_UNLOAD")+"</t>", (getText (configFile >> "CfgWeapons" >> _weap >> "displayNameShort")), getText([_target,_tp] call CBA_fnc_getTurret >> "gunnerName")],
			compile format["[CBA_ui_target, '%1', '%2', player, %3] spawn ace_sys_crewserved_fnc_exchangeMagazineFromVehicle", _weap, _mag, _tp],
			"", "", "", DIK_C,
			_ammoCount > 0, _ammoCount <= _count //&& !((player in (crew _target)) && (currentMagazine _target) != _mag && (currentMagazine _target) != "")
			// One last snag; if player is in the turret the currentmagazine command works, but when he's outside
			// it doesn't work, so we cannot confirm if there's currently a 100round mag loaded, or a 1200 round mag, when
			// the current count = 100. Yet would rather not have to force user to be in the tank, or should we?
		];
		PUSH(_menus2,_entry);
	};


	// Get Weapons and Magazines from the unit, compatible with magXchange_veh
	_dumMags = []; // Unit mags
	_dumMags2 = []; // Vehicle mags
	_dumMuzzles = []; // Unit muzzle
	_dumWeps = []; // Dummy weapons regardless if unit has them
	_dumWeps2 = []; // Vehicle weapons
	_dumTps = []; // Vehicle turretpaths
	{
		_magCfg = (C_MAGAZINE >> _x >> "ACE" >> "ACE_CREWSERVED" >> "ACE_magXchange_veh");
		if (isText _magCfg) then {
			_mag = _x;
			_weap = "";
			_muzzle = "";

			_weapsies = (weapons player + ["Put", "Throw"]);
			_cfg = (C_MAGAZINE >> _x >> "ACE" >> "ACE_CREWSERVED" >> "ACE_magXchange_wep");
			if (isText _cfg) then { _dw = getText(_cfg); if !(_dw in _weapsies) then { PUSH(_weapsies,_dw) } }; // add dummy weapon also

			{
				private "_cfg";
				_cfg = C_WEAPON >> _x;
				_w = _x;
				if (_mag in (getArray(_cfg >> "magazines"))) exitWith {
					_muzzle = _w;
					_weap = _w;
				};
				if (_weap != "") exitWith {};
				_muzzles = getArray(_cfg >> "muzzles") - ["this"];
				{
					if (_mag in (getArray(_cfg >> _x >> "magazines"))) exitWith {
						_muzzle = _x;
						_weap = _w;
					};
				} forEach _muzzles;
				if (_weap != "") exitWith {};
			} forEach _weapsies;

			_mag = getText(_magCfg);
			if (_mag == "this") then {
				_mag = _x;
			};
			if !(_x in _dumMags) then {
				PUSH(_dumMags,_x);
				PUSH(_dumMags2,_mag);
				PUSH(_dumweps,_weap);
				PUSH(_dumMuzzles,_muzzle);

				// Process vehicle weapons compatible to our mag
				// TODO: Muzzles, do vehicles have them?
				_weap2 = "";
				{
					private ["_cfg"];
					_cfg = C_WEAPON >> _x;
					if (_mag in (getArray(_cfg >> "magazines"))) exitWith {
						_weap2 = _x;
					};
				} forEach _allWeps;
				PUSH(_dumweps2,_weap2);
				_tp = if (_weap2 != "") then { _alltps select (_allWeps find _weap2) } else { [] };
				PUSH(_dumTps, _tp);
			};
		};

	} forEach (magazines player);
	TRACE_6("",_dumMags,_dumMags2,_dumWeps,_dumWeps2,_dumMuzzles,_dumTps);

	_turnedOut = [player] call ACE_fnc_isTurnedOut; // used with ace_magXchange_external = 1; mags.

	// Build menus
	_menus3 = [];
	for "_i" from 0 to (count _dumWeps) - 1 do {
		_weap2 = _dumWeps2 select _i;
		if (_weap2 != "") then {
			_weap = _dumWeps select _i;
			_muzzle = _dumMuzzles select _i;
			_mag = _dumMags select _i;
			_mag2 = _dumMags2 select _i;
			_needExternal = getNumber(configFile >> "CfgMagazines" >> _mag2 >> "ACE" >> "ACE_CREWSERVED" >> "ace_magXchange_external") == 1;
			_tp = _dumTps select _i;
			_cfg = configFile >> "CfgWeapons" >> _weap2;
			_dn = if (isText(_cfg >> "displayNameShort")) then { getText(_cfg >> "displayNameShort") } else { getText (_cfg >> "displayName") };
			_turner = !(player in _target) || {_turnedOut} || {getText([_target,_tp] call CBA_fnc_getTurret >> "gunnerAction") == animationState player};
			_weap2Max = getNumber(C_WEAPON >> _weap2 >> "ace_magXchange_max");
			_magCount = {_x == _mag2} count (_target magazinesTurret _tp);
			_maximized = if (_weap2Max > 0) then { (_magCount >= _weap2Max && {_target ammo _weap2 > 0}) } else { false };
			// SNAG: last magazine even when empty remains in the weapon, so we check for _target ammo _weap2 > 0 in the condition above,
			// however, if you shoot the magazine empty, and load a magazine, but don't hit 'reload', it will still add a 2nd mag because ammo count == 0
			// Perhaps remove empty magazines after fired?
			TRACE_5("",_needExternal,_turner,_weap2Max,_magCount,_maximized);
			_entry = [
			format["<t size='0.75'>"+(localize "STR_ACE_VEHICLE_LOAD")+"</t>", _dn, getText([_target,_tp] call CBA_fnc_getTurret >> "gunnerName")],
				compile format["[player, '%1', '%2', CBA_ui_target, %3, '%4'] spawn ace_sys_crewserved_fnc_exchangeMagazineToVehicle", _weap, _mag, _tp, _muzzle],
				"", "", "", DIK_C, !_maximized && {!(_needExternal && {!_turner})}, true
			];
			PUSH(_menus3,_entry);
		};
	};

	// TODO: Submenus per turret?
	_menus set [count _menus,
	[
		["ACE_xChange", localize "STR_ACE_VEHICLE_EXCHANGE", _menuRsc],
		_menus2 + _menus3
	]];
};

//-----------------------------------------------------------------------------

{
	if (_x select 0 select 0 == _menuName) exitWith {_menuDef = _x};
} forEach _menus;

if (count _menuDef == 0) then
{
	hintC format ["Error: Menu not found: %1\n%2\n%3", str _menuName, if (_menuName == "") then {_this} else {""}, __FILE__];
	diag_log format ["Error: Menu not found: %1, %2, %3", str _menuName, _this, __FILE__];
};

_menuDef // return value
