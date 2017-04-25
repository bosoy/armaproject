Private ['_data','_get','_i','_index','_j','_old','_override','_tar','_tindex','_type','_vehicle','_z'];
_vehicle = _this select 0;
_index = _this select 1;
_tindex = _index;
_override = if (count _this > 2) then {_this select 2} else {false};

if (typeName _vehicle != 'OBJECT') exitWith {diag_log Format['[WFBE (ERROR)][frameno:%2 | ticktime:%3] EASA_Equip: Invalid Parameter (_vehicle), expected object instead of %1',_vehicle,diag_frameno,diag_tickTime]};

_type = ('WFBE_EASA_Vehicles' Call GetNamespace) find (typeOf _vehicle);
if (_type != -1) then {
	_get = _vehicle getVariable 'WFBE_EASA_Setup';
	//--- Vehicle Loadout check.
	if (isNil '_get') then {
		[_vehicle,('WFBE_EASA_Default' Call GetNamespace) select _type] Call EASA_RemoveLoadout;
	} else {
		//--- Override the index?.
		_tindex = if (_override) then {_index} else {(_get select 1)};
		
		//--- Grab the old loadout.
		_old = (('WFBE_EASA_Loadouts' Call GetNamespace) select (_get select 0)) select (_get select 1);
		_tar = [];
		for [{_i = 2},{_i < count(_old)},{_i = _i + 1}] do {
			_tar = _tar + [_old select _i];
		};
		_old = _tar;
		
		[_vehicle,('WFBE_EASA_Default' Call GetNamespace) select _type] Call EASA_RemoveLoadout;
		[_vehicle,_old] Call EASA_RemoveLoadout;
	};
	
	_data = (('WFBE_EASA_Loadouts' Call GetNamespace) select _type) select _tindex;

	for [{_j = 2},{_j < count(_data)},{_j = _j + 1}] do {
		_z = _data select _j;
		for [{_i = count(_z)-1},{_i >= 0},{_i = _i - 1}] do {
			if (_i > 0) then {
				_vehicle addMagazine (_z select _i);
			} else {
				_vehicle addWeapon (_z select _i);
			};
		};
	};

	_vehicle setVariable ['WFBE_EASA_Setup',[_type,_tindex],true];
};