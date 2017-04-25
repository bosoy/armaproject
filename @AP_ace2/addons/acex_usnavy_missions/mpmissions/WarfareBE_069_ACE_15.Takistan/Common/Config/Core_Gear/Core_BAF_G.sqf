private ["_config","_element","_get","_i","_info","_prefix","_proceed","_u"];

_u = [];
_i = [];

/* _i = _i + [[label, picture, config, belong to type, cost, upgrade level, allowed in camps, belong to the handgun pool, magazines, magazine space, allow two weapons]]*/

/* Magazines - West */
_u = _u + ['5Rnd_127x99_AS50'];
_i = _i + [['','','CfgMagazines','primary',14,0,true,false,0,0,true]];

_u = _u + ['5Rnd_86x70_L115A1'];
_i = _i + [['','','CfgMagazines','primary',8,0,true,false,0,0,true]];	

_u = _u + ['200Rnd_556x45_L110A1'];
_i = _i + [['','','CfgMagazines','primary',12,0,true,false,0,0,true]];

_u = _u + ['NLAW'];
_i = _i + [['','','CfgMagazines','secondary',225,0,false,false,0,0,true]];

/* Primary Weapons - West */
_u = _u + ['BAF_AS50_scoped'];
_i = _i + [['','','CfgWeapons','',380,2,true,false,0,0,false]];

_u = _u + ['BAF_AS50_TWS'];
_i = _i + [['','','CfgWeapons','',460,3,false,false,0,0,false]];

_u = _u + ['BAF_LRR_scoped'];
_i = _i + [['','','CfgWeapons','',350,2,true,false,0,0,true]];

_u = _u + ['BAF_LRR_scoped_W'];
_i = _i + [['','','CfgWeapons','',330,2,true,false,0,0,true]];

_u = _u + ['BAF_L85A2_RIS_Holo'];
_i = _i + [['','','CfgWeapons','',250,1,true,false,0,0,true]];

_u = _u + ['BAF_L85A2_UGL_Holo'];
_i = _i + [['','','CfgWeapons','',265,2,true,false,0,0,true]];

_u = _u + ['BAF_L85A2_RIS_SUSAT'];
_i = _i + [['','','CfgWeapons','',280,1,true,false,0,0,true]];

_u = _u + ['BAF_L85A2_UGL_SUSAT'];
_i = _i + [['','','CfgWeapons','',290,2,true,false,0,0,true]];

_u = _u + ['BAF_L85A2_RIS_ACOG'];
_i = _i + [['','','CfgWeapons','',300,1,true,false,0,0,true]];

_u = _u + ['BAF_L85A2_UGL_ACOG'];
_i = _i + [['','','CfgWeapons','',320,2,true,false,0,0,true]];

_u = _u + ['BAF_L85A2_RIS_CWS'];
_i = _i + [['','','CfgWeapons','',400,3,false,false,0,0,true]];

_u = _u + ['BAF_L86A2_ACOG'];
_i = _i + [['','','CfgWeapons','',330,2,true,false,0,0,true]];

_u = _u + ['BAF_L110A1_Aim'];
_i = _i + [['','','CfgWeapons','',350,2,false,false,0,0,false]];

_u = _u + ['BAF_L7A2_GPMG'];
_i = _i + [['','','CfgWeapons','',210,0,false,false,0,0,false]];

/* Secondary weapons - West */
_u = _u + ['BAF_NLAW_Launcher'];
_i = _i + [['','','CfgWeapons','',500,2,false,false,0,0,false]];

_u = _u + ['BAF_AssaultPack_RifleAmmo'];
_i = _i + [['','','CfgVehicles','',95,2,true,false,0,0,false]];

_u = _u + ['BAF_L2A1_ACOG_minitripod_bag'];
_i = _i + [['','','CfgVehicles','',165,1,false,false,0,0,false]];

_u = _u + ['BAF_L2A1_ACOG_tripod_bag'];
_i = _i + [['','','CfgVehicles','',175,1,false,false,0,0,false]];

_u = _u + ['BAF_GPMG_Minitripod_D_bag'];
_i = _i + [['','','CfgVehicles','',175,0,false,false,0,0,false]];

_u = _u + ['BAF_GMG_ACOG_minitripod_bag'];
_i = _i + [['','','CfgVehicles','',175,1,false,false,0,0,false]];

/* Misc - West */
_u = _u + ['BAF_L109A1_HE'];
_i = _i + [['','','CfgMagazines','CfgMagazines',12,0,true,false,0,0,true]];

/* Misc - East */
_u = _u + ['BAF_ied_v1'];
_i = _i + [['','','CfgMagazines','CfgMagazines',25,0,true,false,0,0,true]];

_u = _u + ['BAF_ied_v2'];
_i = _i + [['','','CfgMagazines','CfgMagazines',35,1,true,false,0,0,true]];

_u = _u + ['BAF_ied_v3'];
_i = _i + [['','','CfgMagazines','CfgMagazines',45,2,true,false,0,0,true]];

_u = _u + ['BAF_ied_v4'];
_i = _i + [['','','CfgMagazines','CfgMagazines',55,2,true,false,0,0,true]];

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
				diag_log Format ["[WFBE (INIT)][frameno:%3 | ticktime:%4] Core_BAF_G: Duplicated Loadout Element found '%1' for class '%2'",_element,_config,diag_frameno,diag_tickTime];
			} else {
				//--- Is it a special class?
				_get = (_element+'_W') Call GetNamespace;
				if (isNil '_get') then {
					_prefix = '_W';
					_proceed = true;
				} else {
					diag_log Format ["[WFBE (INIT)][frameno:%3 | ticktime:%4] Core_BAF_G: Duplicated Loadout Element found '%1' for class '%2'",_element,_config,diag_frameno,diag_tickTime];
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
		diag_log Format ["[WFBE (ERROR)][frameno:%3 | ticktime:%4] Core_BAF_G: Loadout Element '%1' with class '%2' is not a defined a class!",_element,_config,diag_frameno,diag_tickTime];
	};
};

diag_log Format ["[WFBE (INIT)][frameno:%2 | ticktime:%3] Core_BAF_G: Loadout Initialization (%1 Elements) - [Done]",count _u,diag_frameno,diag_tickTime];