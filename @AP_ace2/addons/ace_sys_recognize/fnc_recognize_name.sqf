/* ace_sys_spacebar | (c) 2009 by rocko */

#include "script_component.hpp"

#define __DN getText (configFile >> "CfgVehicles" >> typeOf _target >> "displayName")
#define __DNA ([_target, player knowsAbout _target] call FUNC(recognize_accuracy))
#define __DNAO getNumber (configFile >> "CfgVehicles" >> typeOf _target >> QGVAR(accuracyOnly))

PARAMS_2(_target,_type);

private["_name","_name_mod","_identity","_displayName"];
_name = [""];
_name_mod = 1;
switch (toUpper _type) do {
	case "MAN": {
		if (_target in (units group player)) then {
			_identity = name (vehicle _target);
			if (__DNAO == 1 || {isPlayer _target} || {GVAR(info_complex) == 0}) then {	// Handle BIS campaign characters
				_displayName = __DNA;	// players and campaign characters need more generic DNs
			} else {
				_displayName = __DN;	// default
			};
			if (_target == leader group player) then {
				_name = ["^" + (_target call FUNC(rankString)) + _identity + "*", lineBreak, _displayName];	// ^Sgt Moody* \ Officer
			} else {
				_name = [(_target call FUNC(rankString)) + _identity + "*", lineBreak, _displayName];	// Pvt Kozlovski \ Rifleman
			};
			if (isPlayer _target && {GVAR(info_players) == 0}) then {
				_name = [_name select 0];
			};
		} else {
			_identity = name (vehicle _target);
			_displayName = __DNA;
			if (player distance (vehicle _target) < 20) then {
				_name = [(_target call FUNC(rankString)) + _identity, lineBreak, _displayName];	// Pvt Kozlovski \ Rifleman
			} else {
				if (isPlayer _target) then {
					_name = if (GVAR(info_players) == 0) then {
						[_identity]	// Kozlovski
					} else {
						[_identity, lineBreak, _displayName]	// Kozlovski \ Rifleman
					};
				} else {
					_name = [_displayName];	// Rifleman
				};
			};
		};
	};
	case "VEHICLE": {
		// Nur effektiver Kommandant
		_ef_com = effectiveCommander(vehicle _target);
		if !(isNull _ef_com) then {
			if (alive _ef_com) then {
				if (player distance (vehicle _target) < 20) then {
					_name = [(_ef_com call FUNC(rankString)) + (name _ef_com), lineBreak, __DNA];	// Pvt Kozlovski \ M151 MUTT
				} else {
					if (isPlayer _ef_com) then {
						_name = [name _ef_com, lineBreak, __DNA];	// Kozlovski \ M151 MUTT
					} else {
						_name = [__DNA];	//M151 MUTT
					};
				};
			};
		} else {
			_name = [""];
		};
		_name_mod = 1.2;
	};
	case "TANK": {
		// Nur effektiver Kommandant
		_ef_com = effectiveCommander (vehicle _target);
		if !(isNull _ef_com) then {
			if (alive _ef_com) then {
				if ([_ef_com] call ACE_fnc_isTurnedOut) then {
					if (player distance (vehicle _target) < 20) then {
						_name = [(_ef_com call FUNC(rankString)) + (name _ef_com), lineBreak, __DNA];	// Pvt Kozlovski \ M60 Patton
					} else {
						if (isPlayer _ef_com) then {
							_name = [name _ef_com, lineBreak, __DNA];	// Kozlovski  \ M60 Patton
						} else {
							_name = [__DNA];	// M60 Patton
						};
					};
				} else {
					_name = [__DNA];	// M60 Patton
				};
			};
		} else {
			_name = [""];
		};
		_name_mod = 1.2;
	};
	case "AMMO": {
		_name = [_target getVariable "ace_sys_cargo_name"];
		if (isNil "_name") then {
			_name = [__DN];
		};
	};

	case "RUCK": {
		_name = [_target getVariable ["ACE_RuckOwner", ""]];
	};
};

if (visibleMap) then {
	_name = [""];
};

[_name,_name_mod]
