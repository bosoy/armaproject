private ["_unit","_mag","_magtoremove","_mag_sd","_weap_sd"];

_unit = player;
_mag = _x;

if ((!(_mag in _processedMagTypes)) && {_mag in _weapmags}) then {		//this type'o'mags hasn't been checked/replaced yet
	PUSH(_processedMagTypes,_mag);
	_mag_sd = getNumber (configFile >> "cfgMagazines" >> _mag >> "ace_suppressed");
	_weap_sd = getNumber (configFile >> "cfgWeapons" >> _lastweap >> "ace_suppressed");
	if (_mag_sd != _weap_sd) then { 	//the mag needs exchanging to a suppressed/unsuppressed version
		private ["_magtoremove","_comparefunc","_newmag","_abort"];
		//if (ACE_Sys_Magazines_Debug) then {player globalchat "Silenced"};
		_magtoremove = _mag;
		_abort = false;
		if (isText (configFile >> "cfgMagazines" >> _magtoremove >> "ace_suppmag")) then {
			if (_mag_sd == 0) then {
				_newmag = getText (configFile >> "cfgMagazines" >> _magtoremove >> "ace_suppmag");
				if (_magtoremove != configName (inheritsfrom (configFile >> "cfgMagazines" >> _newmag))) then {
					_abort = true;
				};
			} else {	//supp mags should inherit directly from their unsuppr. counterparts
				_newmag = configName (inheritsfrom (configFile >> "cfgMagazines" >> _magtoremove));
				if(_magtoremove != getText (configFile >> "cfgMagazines" >> _newmag >> "ace_suppmag")) then {
					_abort = true;
				};
			};
			if (!_abort) then {
				[_magtoremove,_newmag,_lastWeap,_lastMuzzle] call FUNC(magCheckAndReplace);
			};
		};
	};
};
