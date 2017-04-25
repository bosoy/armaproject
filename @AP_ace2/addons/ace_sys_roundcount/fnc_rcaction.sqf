//#define DEBUG_MODE_FULL
#include "script_component.hpp"

if (GVAR(disabled)) exitWith {}; // Global off

#define __cfgWeap configFile>>"CfgWeapons"
#define __cfgMag configFile>>"CfgMagazines"
#define __muzzles (getArray(__cfgWeap>>_curWeapon>>"muzzles"))
#define __magCount (getNumber(__cfgMag>>_curMag>>"count"))
#define __magType (getNumber(__cfgMag>>_curMag>>"type"))
#define __ammoLeft (_unit ammo _mainMuzzle)
#define __ammoLeftStatic ((vehicle _unit) ammo (currentWeapon (vehicle _unit)))
#define __magCountP (ceil((__ammoLeft/__magCount)*100))
#define __magCountPStatic (ceil((__ammoLeftStatic/__magCount)*100))
#define __disp1 (uiNamespace getVariable "ACE_RscRoundCount_Text")
#define __disp2 (uiNamespace getVariable "ACE_RscRoundCount_Icon")
#define __ctrl1 (__disp1 displayCtrl 18141)
#define __ctrl2 (__disp2 displayCtrl 18141)
#define __weaponReloadTime (3.8)
#define __green _color = [0,1,0,0.7];
#define __lightgreen _color = [0.5,1,0,0.7];
#define __yellow _color = [1,1,0,0.7];
#define __orange _color = [1,0.7,0,0.7];
#define __red _color = [1,0,0,0.7];

private ["_curWeapon", "_unit", "_curMag", "_mainMuzzle", "_color", "_key", "_ispistol", "_isrifle", "_ismg", "_magType", "_type", "_magcountP", "_fPR", "_cPR"];

PARAMS_2(_type,_key);
_unit = player;

if (_unit getVariable [QGVAR(disabled),false]) exitWith {}; // Unit off


if (player == vehicle player) then {
	_curWeapon = currentWeapon _unit;
	_curMag = currentMagazine _unit;

	_mainMuzzle = __muzzles select 0;
	if (_mainMuzzle == "THIS" || {_curWeapon in __muzzles}) then {_mainMuzzle = _curWeapon;};

	_ispistol = false;
	_ismg = false;
	_isrifle = [configFile >> "CfgWeapons" >> _curWeapon, configFile >> "CfgWeapons" >> "RifleCore"] call CBA_fnc_inheritsFrom;
	if (!_isrifle) then {
		_ispistol = [configFile >> "CfgWeapons" >> _curWeapon, configFile >> "CfgWeapons" >> "PistolCore"] call CBA_fnc_inheritsFrom;
	} else {
		_ismg = (([_curWeapon] call ACE_sys_weapons_fnc_getType == 5 || {[_curWeapon] call ACE_sys_weapons_fnc_getType == 6}) && {__magCount >= 100});
		if (_ismg) then { _isrifle = false };
	};

	sleep 0.1;

	if (!_isrifle && {!_ispistol} && {!_ismg}) exitWith {};

	if (__magCount == 0 || {__magCount == 1}) exitWith {};

	if (_type != 0 && {_key == (["CBA","events","ace_sys_roundcount","Roundcount","key"] call ace_settings_fnc_getNumber)}) then {player playActionNow "ReloadMagazine"};
	sleep (__weaponReloadTime+.3);

	if (!alive _unit) exitWith {};

	if (_curMag == "") then {_curMag = currentMagazine _unit};
	if (_curMag == "") exitWith {};

	_magType = __magType;
	_type = switch (true) do {
		case (_ispistol):  { "P" };
		case (_isrifle): { "R" };
		case (_ismg): { "MG" };
		default { "R"};
	};

	_magcountP = __magCountP;

	_color = [1,1,1,1];
	switch (true) do {
		case (_magcountP > 75 && {_magcountP <= 100}): { _fPR = localize "STR_ACE_RNDCNT1a";_cPR = localize "STR_ACE_RNDCNT1b"; __green;};
		case (_magcountP > 50 && {_magcountP <= 75}): { _fPR = localize "STR_ACE_RNDCNT2a";_cPR = localize "STR_ACE_RNDCNT2b"; __yellow;};
		case (_magcountP > 25 && {_magcountP <= 50}): { _fPR = localize "STR_ACE_RNDCNT3a";_cPR = localize "STR_ACE_RNDCNT3b"; __orange;};
		case (_magcountP > 0 && {_magcountP <= 25}): { _fPR = localize "STR_ACE_RNDCNT4a";_cPR = localize "STR_ACE_RNDCNT4b"; __red;};
		case (_magcountP == 0): { _fPR = localize "STR_ACE_RNDCNT5";_cPR = localize "STR_ACE_RNDCNT5"; __red;};
	};

	if ((["ACE", "ACE_ROUNDCOUNT","show_icon"] call ace_settings_fnc_getNumber) == 1) then {
		135173 cutRsc["ACE_RscRoundCount_Text","PLAIN"];
		switch (toUpper _type) do {
			case "P": { __ctrl1 ctrlSetText format["%1",_fPR]; };
			case "R": { __ctrl1 ctrlSetText format["%1",_fPR]; };
			case "MG": { __ctrl1 ctrlSetText format["%1",_cPR]; };
		};
		__ctrl1 ctrlSetTextColor _color;
	} else {
		135173 cutRsc["ACE_RscRoundCount_Icon","PLAIN"];
		switch (toUpper _type) do {
			case "P": { __ctrl2 ctrlSetText "\x\ace\addons\sys_roundcount\data\icon\icon_pistol_ca.paa"; };
			case "R": { __ctrl2 ctrlSetText "\x\ace\addons\sys_roundcount\data\icon\icon_rifle_ca.paa"; };
			case "MG": { __ctrl2 ctrlSetText "\x\ace\addons\sys_roundcount\data\icon\icon_mg_ca.paa"; };
		};
		__ctrl2 ctrlSetTextColor _color;
	};
} else {
	_curWeapon = currentWeapon (vehicle _unit);
	_curMag = currentMagazine (vehicle _unit);
	// Get ammo count from static weapon

	_magcountP = __magCountPStatic;

	_color = [1,1,1,1];
	switch (true) do {
		case (_magcountP > 75 && {_magcountP <= 100}): { _fPR = localize "STR_ACE_RNDCNT1a";_cPR = localize "STR_ACE_RNDCNT1b"; __green;};
		case (_magcountP > 50 && {_magcountP <= 75}): { _fPR = localize "STR_ACE_RNDCNT2a";_cPR = localize "STR_ACE_RNDCNT2b"; __yellow;};
		case (_magcountP > 25 && {_magcountP <= 50}): { _fPR = localize "STR_ACE_RNDCNT3a";_cPR = localize "STR_ACE_RNDCNT3b"; __orange;};
		case (_magcountP > 0 && {_magcountP <= 25}): { _fPR = localize "STR_ACE_RNDCNT4a";_cPR = localize "STR_ACE_RNDCNT4b"; __red;};
		case (_magcountP == 0): { _fPR = localize "STR_ACE_RNDCNT5";_cPR = localize "STR_ACE_RNDCNT5"; __red;};
	};	
	
	if ((["ACE", "ACE_ROUNDCOUNT","show_icon"] call ace_settings_fnc_getNumber) == 1) then {
		135173 cutRsc["ACE_RscRoundCount_Text","PLAIN"];
		__ctrl1 ctrlSetText format["%1",_cPR];
		__ctrl1 ctrlSetTextColor _color;
	} else {
		135173 cutRsc["ACE_RscRoundCount_Icon","PLAIN"];
		__ctrl2 ctrlSetText "\x\ace\addons\sys_roundcount\data\icon\icon_mg_ca.paa";
		__ctrl2 ctrlSetTextColor _color;
	};
};