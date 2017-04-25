#include "script_component.hpp"

private ["_abort","_unit","_mag","_lastWeap","_weapMags","_magtoremove","_mag_sd","_weap_sd", "_newMag", "_action"];

PARAMS_4(_unit,_lastWeap,_weapMags,_mag);

_mag_sd = getNumber (configFile >> "cfgMagazines" >> _mag >> "ace_suppressed");
_weap_sd = getNumber (configFile >> "cfgWeapons" >> _lastweap >> "ace_suppressed");
_abort = false;

if (_mag in _weapMags) then { //the mag is compatible, starting processing it
	if (_mag_sd != _weap_sd) then {
		_magtoremove = _mag;
		if (isText (configFile >> "cfgMagazines" >> _magtoremove >> "ace_suppmag")) then {
			if (_mag_sd == 0) then {
				_newmag = getText (configFile >> "cfgMagazines" >> _magtoremove >> "ace_suppmag");
				if (_magtoremove != configName (inheritsfrom (configFile >> "cfgMagazines" >> _newmag))) then {
					_abort = true;
				};
			} else {		//supp mags should inherit directly from their unsuppr. counterparts
				_newmag = configName (inheritsfrom (configFile >> "cfgMagazines" >> _magtoremove));
				if(_magtoremove != getText (configFile >> "cfgMagazines" >> _newmag >> "ace_suppmag")) then {
					_abort = true;
				};
			};
			if (!_abort) then {
				_action = [_unit, _magtoremove] call CBA_fnc_RemoveMagazine;
				_action = [_unit, _newmag] call CBA_fnc_AddMagazine;
			};
		};
	};
	TRACE_6("",_mag_sd,_weap_sd,_abort,_action,_magToRemove,_newMag);
};
