private ["_config","_element","_get","_i","_info","_prefix","_proceed","_u"];

_u = [];
_i = [];

/* _i = _i + [[label, picture, config, belong to type, cost, upgrade level, allowed in camps, belong to the handgun pool, magazines, magazine space, allow two weapons]]*/

/* Magazines - West */
_u = _u + ['20Rnd_B_AA12_Pellets'];
_i = _i + [['','','CfgMagazines','primary',8,0,true,false,0,0,true]];

_u = _u + ['20Rnd_B_AA12_74Slug'];
_i = _i + [['','','CfgMagazines','primary',10,0,true,false,0,0,true]];	

_u = _u + ['20Rnd_B_AA12_HE'];
_i = _i + [['','','CfgMagazines','primary',45,3,true,false,0,0,true]];

/* Primary Weapons - West */
_u = _u + ['AA12_PMC'];
_i = _i + [['','','CfgWeapons','',380,2,true,false,0,0,true]];

_u = _u + ['m8_carbine'];
_i = _i + [['','','CfgWeapons','',280,2,true,false,0,0,true]];

_u = _u + ['m8_carbineGL'];
_i = _i + [['','','CfgWeapons','',290,3,true,false,0,0,true]];

_u = _u + ['m8_compact'];
_i = _i + [['','','CfgWeapons','',285,2,false,false,0,0,true]];

_u = _u + ['m8_SAW'];
_i = _i + [['','','CfgWeapons','',310,3,false,false,0,0,false]];

_u = _u + ['m8_sharpshooter'];
_i = _i + [['','','CfgWeapons','',295,3,false,false,0,0,true]];

_u = _u + ['m8_carbine_pmc'];
_i = _i + [['','','CfgWeapons','',290,2,true,false,0,0,true]];

_u = _u + ['m8_compact_pmc'];
_i = _i + [['','','CfgWeapons','',295,2,false,false,0,0,true]];

_u = _u + ['m8_holo_sd'];
_i = _i + [['','','CfgWeapons','',335,3,false,false,0,0,true]];

_u = _u + ['m8_tws'];
_i = _i + [['','','CfgWeapons','',350,3,false,false,0,0,true]];

_u = _u + ['m8_tws_sd'];
_i = _i + [['','','CfgWeapons','',385,3,false,false,0,0,true]];

for '_z' from 0 to (count _u)-1 do {
	_info = (_i select _z);
	_element = (_u select _z);
	_config = (_info select 2);
	
	if (isClass (configFile >> _config >> _element)) then {
		//--- The loadout has a prefix since we can have two elements with the same name but with different class.
		_get = _element Call GetNamespace;
		_proceed = false;
		_prefix = "";
		
		if (isNil '_get') then {
			_proceed = true;
		} else {
			//--- Two elements can have the same name, like "Javelin(Weapon) >> Javelin (Magazine)", if two elements are found, we compare the class to see if they're already defined or not.
			if ((_get select 2) == _config) then {
				diag_log Format ["[WFBE (INIT)][frameno:%3 | ticktime:%4] Core_PMC_G: Duplicated Loadout Element found '%1' for class '%2'",_element,_config,diag_frameno,diag_tickTime];
			} else {
				//--- Is it a special class?
				_get = (_element+'_W') Call GetNamespace;
				if (isNil '_get') then {
					_prefix = '_W';
					_proceed = true;
				} else {
					diag_log Format ["[WFBE (INIT)][frameno:%3 | ticktime:%4] Core_PMC_G: Duplicated Loadout Element found '%1' for class '%2'",_element,_config,diag_frameno,diag_tickTime];
				};
			};
		};
		
		if (_proceed) then {
			//--- A custom loadout displayName can be set.
			if ((_info select 1) == '') then {_info set [0, [_element,'displayName',_config] Call GetConfigInfo]};
			_info set [1, [_element,'picture',_config] Call GetConfigInfo];
			
			if (_config == 'CfgWeapons') then {
				//--- A custom loadout magazine can be set.
				if (typeName (_info select 8) != 'ARRAY') then {
					_info set [8, getArray (configFile >> _config >> _element >> 'magazines')];
				};
			};
			
			//--- Set the magazine space.
			if (_config == 'CfgMagazines') then {
				if ((_info select 3) in ['CfgMagazines','primary','secondary','sidearm']) then {
					_info set [9, ceil(getNumber(configFile >> _config >> _element >> 'type') / 256)];
				};
			};

			[_element+_prefix,_info] Call SetNamespace;
		};
	} else {
		diag_log Format ["[WFBE (ERROR)][frameno:%3 | ticktime:%4] Core_PMC_G: Loadout Element '%1' with class '%2' is not a defined a class!",_element,_config,diag_frameno,diag_tickTime];
	};
};

diag_log Format ["[WFBE (INIT)][frameno:%2 | ticktime:%3] Core_PMC_G: Loadout Initialization (%1 Elements) - [Done]",count _u,diag_frameno,diag_tickTime];