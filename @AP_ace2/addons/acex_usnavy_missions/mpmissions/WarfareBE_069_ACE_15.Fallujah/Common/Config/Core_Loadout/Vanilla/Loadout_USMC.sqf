/* USMC Loadout */

if (!isServer || local player) then {		
	if (side player == WEST) then {
		/* Magazines. */
		_m = ["30Rnd_556x45_Stanag"];
		_m = _m + ["30Rnd_556x45_StanagSD"];
		_m = _m + ["20Rnd_556x45_Stanag"];
		_m = _m + ["30Rnd_556x45_G36"];
		_m = _m + ["30Rnd_556x45_G36SD"];
		_m = _m + ["100Rnd_556x45_BetaCMag"];
		_m = _m + ["5Rnd_762x51_M24"];
		_m = _m + ["20Rnd_762x51_DMR"];
		_m = _m + ["10Rnd_127x99_m107"];
		_m = _m + ["100Rnd_762x51_M240"];
		_m = _m + ["200Rnd_556x45_M249"];
		_m = _m + ["30Rnd_9x19_MP5"];
		_m = _m + ["30Rnd_9x19_MP5SD"];
		_m = _m + ["8Rnd_B_Beneli_74Slug"];
		_m = _m + ["M136"];
		_m = _m + ["SMAW_HEAA"];
		_m = _m + ["SMAW_HEDP"];
		_m = _m + ["Javelin"];
		_m = _m + ["Stinger"];
		_m = _m + ["Laserbatteries"];
		_m = _m + ["15Rnd_9x19_M9"];
		_m = _m + ["15Rnd_9x19_M9SD"];
		_m = _m + ["7Rnd_45ACP_1911"];

		WF_Logic setVariable ['magazineClasses',_m];

		/* Primary. */
		_w = ['M16A2'];
		_w = _w + ['M16A2GL'];
		_w = _w + ['m16a4'];
		_w = _w + ['m16a4_acg'];
		_w = _w + ['M16A4_GL'];
		_w = _w + ['M16A4_ACG_GL'];
		_w = _w + ['M24'];
		_w = _w + ['M40A3'];
		_w = _w + ['M240'];
		_w = _w + ['Mk_48'];
		_w = _w + ['M249'];
		_w = _w + ['M4A1'];
		_w = _w + ['M4A1_Aim'];
		_w = _w + ['M4A1_Aim_camo'];
		_w = _w + ['M4SPR'];
		_w = _w + ['M4A1_RCO_GL'];
		_w = _w + ['M4A1_AIM_SD_camo'];
		_w = _w + ['M4A1_HWS_GL_SD_Camo'];
		_w = _w + ['M4A1_HWS_GL'];
		_w = _w + ['M4A1_HWS_GL_camo'];
		_w = _w + ['MP5SD'];
		_w = _w + ['MP5A5'];
		_w = _w + ['G36C'];
		_w = _w + ['G36_C_SD_eotech'];
		_w = _w + ['G36a'];
		_w = _w + ['G36K'];
		_w = _w + ['MG36'];
		_w = _w + ['DMR'];
		_w = _w + ['M1014'];
		_w = _w + ['m107'];
		_w = _w + ['m8_carbine'];
		_w = _w + ['m8_carbineGL'];
		_w = _w + ['m8_compact'];
		_w = _w + ['m8_sharpshooter'];
		_w = _w + ['m8_SAW'];

		WF_Logic setVariable ['primaryClasses',_w];

		/* Secondary. */
		_w = ['M136'];
		_w = _w + ['SMAW'];
		_w = _w + ['Javelin'];
		_w = _w + ['Stinger'];
		_w = _w + ['Laserdesignator'];

		WF_Logic setVariable ['secondaryClasses',_w];

		/* Sidearms. */
		_w = ['Colt1911'];
		_w = _w + ['M9'];
		_w = _w + ['M9SD'];

		WF_Logic setVariable ['sidearmClasses',_w];

		/* Misc. */
		_w = ['HandGrenade_West'];
		_w = _w + ['HandGrenade_Stone'];
		_w = _w + ['SmokeShell'];
		_w = _w + ['SmokeShellRed'];
		_w = _w + ['SmokeShellGreen'];
		_w = _w + ['SmokeShellBlue'];
		_w = _w + ['SmokeShellYellow'];
		_w = _w + ['SmokeShellOrange'];
		_w = _w + ['SmokeShellPurple'];
		_w = _w + ['FlareWhite_M203'];
		_w = _w + ['FlareYellow_M203'];
		_w = _w + ['FlareGreen_M203'];
		_w = _w + ['FlareRed_M203'];
		_w = _w + ['1Rnd_HE_M203'];
		_w = _w + ['1Rnd_Smoke_M203'];
		_w = _w + ['1Rnd_SmokeRed_M203'];
		_w = _w + ['1Rnd_SmokeGreen_M203'];
		_w = _w + ['1Rnd_SmokeYellow_M203'];
		_w = _w + ['Mine'];
		_w = _w + ['PipeBomb'];
		_w = _w + ['Binocular'];
		_w = _w + ['NVGoggles'];
		_w = _w + ['ItemCompass'];
		_w = _w + ['ItemGPS'];
		_w = _w + ['ItemMap'];
		_w = _w + ['ItemRadio'];
		_w = _w + ['ItemWatch'];

		WF_Logic setVariable ['miscClasses',_w];

		//--- Templates.
		_items = ['ItemCompass','ItemGPS','ItemMap','ItemRadio','ItemWatch'];

		_d = [getText(configFile >> 'CfgWeapons' >> 'm16a4' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Colt1911' >> 'displayName')];
		_p = [getText(configFile >> 'CfgWeapons' >> 'm16a4' >> 'picture')];
		_t = [['m16a4','Colt1911']];
		_m = [['30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag',
			'HandGrenade_West','HandGrenade_West','SmokeShellBlue','SmokeShellBlue','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911',
			'7Rnd_45ACP_1911','7Rnd_45ACP_1911']];
		_s = [['Binocular']];
		_i = [_items];
		_l = [0];
		_b = [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'M16A4_GL' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'M16A4_GL' >> 'picture')];
		_t = _t + [['M16A4_GL']];
		_m = _m + [['30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag',
			'30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','HandGrenade_West','HandGrenade_West','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203',
			'1Rnd_HE_M203','1Rnd_HE_M203']];
		_s = _s + [['Binocular']];
		_i = _i + [_items];
		_l = _l + [0];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'G36C' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'M136' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'G36C' >> 'picture')];
		_t = _t + [['G36C','M136']];
		_m = _m + [['30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','M136']];
		_s = _s + [['Binocular']];
		_i = _i + [_items];
		_l = _l + [0];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'M4A1_HWS_GL_SD_Camo' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'SMAW' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'M4A1_HWS_GL_SD_Camo' >> 'picture')];
		_t = _t + [['M4A1_HWS_GL_SD_Camo','SMAW']];
		_m = _m + [['30Rnd_556x45_StanagSD','30Rnd_556x45_StanagSD','30Rnd_556x45_StanagSD','30Rnd_556x45_StanagSD','30Rnd_556x45_StanagSD','30Rnd_556x45_StanagSD','SMAW_HEAA',
			'SMAW_HEAA','SMAW_HEDP','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [3];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'm8_carbine' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'SMAW' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'M9' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'm8_carbine' >> 'picture')];
		_t = _t + [['m8_carbine','SMAW','M9']];
		_m = _m + [['30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','SMAW_HEAA','SMAW_HEAA','SMAW_HEDP',
			'15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [2];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'M4A1_Aim' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Javelin' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Colt1911' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'M4A1_Aim' >> 'picture')];
		_t = _t + [['M4A1_Aim','Javelin','Colt1911']];
		_m = _m + [['30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','Javelin',
			'7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [3];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'M16A2' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Stinger' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'M9' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'M16A2' >> 'picture')];
		_t = _t + [['M16A2','Stinger','M9']];
		_m = _m + [['30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','Stinger',
			'15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [2];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'M1014' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'M9' >> 'displayName') + '/' + getText(configFile >> 'CfgMagazines' >> 'Mine' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'M1014' >> 'picture')];
		_t = _t + [['M1014','M9']];
		_m = _m + [['8Rnd_B_Beneli_74Slug','8Rnd_B_Beneli_74Slug','8Rnd_B_Beneli_74Slug','8Rnd_B_Beneli_74Slug','8Rnd_B_Beneli_74Slug','8Rnd_B_Beneli_74Slug','Mine','Mine','Mine',
			'15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9','15Rnd_9x19_M9']];
		_s = _s + [['Binocular']];
		_i = _i + [_items];
		_l = _l + [0];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'MP5SD' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'M9SD' >> 'displayName') + '/' + getText(configFile >> 'CfgMagazines' >> 'PipeBomb' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'MP5SD' >> 'picture')];
		_t = _t + [['MP5SD','M9SD']];
		_m = _m + [['30Rnd_9x19_MP5SD','30Rnd_9x19_MP5SD','30Rnd_9x19_MP5SD','30Rnd_9x19_MP5SD','30Rnd_9x19_MP5SD','30Rnd_9x19_MP5SD','PipeBomb','PipeBomb','PipeBomb',
			'15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [1];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'M240' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Colt1911' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'M240' >> 'picture')];
		_t = _t + [['M240','Colt1911']];
		_m = _m + [['100Rnd_762x51_M240','100Rnd_762x51_M240','100Rnd_762x51_M240','100Rnd_762x51_M240','100Rnd_762x51_M240','SmokeShellRed','SmokeShellRed','7Rnd_45ACP_1911',
			'7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911']];
		_s = _s + [['Binocular']];
		_i = _i + [_items];
		_l = _l + [0];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'M249' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Colt1911' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'M249' >> 'picture')];
		_t = _t + [['M249','Colt1911']];
		_m = _m + [['200Rnd_556x45_M249','200Rnd_556x45_M249','200Rnd_556x45_M249','200Rnd_556x45_M249','200Rnd_556x45_M249','SmokeShellRed','SmokeShellRed','7Rnd_45ACP_1911',
			'7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [2];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'DMR' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'M9SD' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'DMR' >> 'picture')];
		_t = _t + [['DMR','M9SD']];
		_m = _m + [['20Rnd_762x51_DMR','20Rnd_762x51_DMR','20Rnd_762x51_DMR','20Rnd_762x51_DMR','20Rnd_762x51_DMR','20Rnd_762x51_DMR','20Rnd_762x51_DMR','20Rnd_762x51_DMR',
			'20Rnd_762x51_DMR','20Rnd_762x51_DMR','HandGrenade_West','HandGrenade_West','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD',
			'15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [2];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'M40A3' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Laserdesignator' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'M9SD' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'M40A3' >> 'picture')];
		_t = _t + [['M40A3','Laserdesignator','M9SD']];
		_m = _m + [['5Rnd_762x51_M24','5Rnd_762x51_M24','5Rnd_762x51_M24','5Rnd_762x51_M24','5Rnd_762x51_M24','5Rnd_762x51_M24','5Rnd_762x51_M24','5Rnd_762x51_M24',
			'5Rnd_762x51_M24','5Rnd_762x51_M24','HandGrenade_West','Laserbatteries','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD',
			'15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [2];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'm107' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'M9SD' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'm107' >> 'picture')];
		_t = _t + [['m107','M9SD']];
		_m = _m + [['10Rnd_127x99_m107','10Rnd_127x99_m107','10Rnd_127x99_m107','10Rnd_127x99_m107','10Rnd_127x99_m107','10Rnd_127x99_m107','10Rnd_127x99_m107','10Rnd_127x99_m107',
			'10Rnd_127x99_m107','10Rnd_127x99_m107','HandGrenade_West','HandGrenade_West','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD',
			'15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [3];
		_b = _b + [false];

		_c = [];
		_totalTemplates = count _d;

		for [{_count = 0},{_count < _totalTemplates},{_count = _count + 1}] do {
			_cost = 0;
			{
				_get = (_x+"_W") Call GetNamespace;
				if (isNil '_get') then {
					_get = _x Call GetNamespace;
				};
				if !(isNil '_get') then {_cost = _cost + (_get select QUERYGEARCOST)};
			} forEach (_t select _count);
			
			{
				_get = _x Call GetNamespace;
				if !(isNil '_get') then {_cost = _cost + (_get select QUERYGEARCOST)};
			} forEach ((_m select _count) + (_s select _count) + (_i select _count));
			
			_c = _c + [_cost];
		};

		WF_Logic setVariable ['templateClasses',_t];
		WF_Logic setVariable ['templateNames',_d];
		WF_Logic setVariable ['templateCosts',_c];
		WF_Logic setVariable ['templatePictures',_p];
		WF_Logic setVariable ['templateMags',_m];
		WF_Logic setVariable ['templateItems',_i];
		WF_Logic setVariable ['templateSpecs',_s];
		WF_Logic setVariable ['templateUpgrades',_l];
		WF_Logic setVariable ['templateAllowed',_b];
	};
};

['WFBE_WESTDEFAULTWEAPONS',['M16A2','ItemCompass','ItemMap','ItemWatch','ItemRadio'],true] Call SetNamespace;
['WFBE_WESTDEFAULTAMMO',['30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','HandGrenade_West','HandGrenade_West'],true] Call SetNamespace;

//--- AI Leaders Loadouts.
if (isServer) then {
	//--- No Upgrade.
	['WFBE_WESTLEADERWEAPONS01',['m16a4','M136','Colt1911','Binocular','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO01',['30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','M136','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911'],true] Call SetNamespace;
	['WFBE_WESTLEADERWEAPONS02',['G36C','M136','Colt1911','Binocular','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO02',['30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','M136','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911'],true] Call SetNamespace;
	['WFBE_WESTLEADERWEAPONS03',['M240','Colt1911','Binocular','ItemRadio','ItemMap'],true] Call SetNamespace;;
	['WFBE_WESTLEADERAMMO03',['100Rnd_762x51_M240','100Rnd_762x51_M240','100Rnd_762x51_M240','100Rnd_762x51_M240','100Rnd_762x51_M240','HandGrenade_West','HandGrenade_West','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911'],true] Call SetNamespace;
	//--- Upgrade 1.
	['WFBE_WESTLEADERWEAPONS11',['m16a4_acg','M136','Colt1911','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO11',['30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','M136','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911'],true] Call SetNamespace;
	['WFBE_WESTLEADERWEAPONS12',['G36K','M136','Colt1911','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO12',['30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','M136','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911'],true] Call SetNamespace;
	['WFBE_WESTLEADERWEAPONS13',['M4SPR','M9SD','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO13',['20Rnd_556x45_Stanag','20Rnd_556x45_Stanag','20Rnd_556x45_Stanag','20Rnd_556x45_Stanag','20Rnd_556x45_Stanag','20Rnd_556x45_Stanag','20Rnd_556x45_Stanag','20Rnd_556x45_Stanag','20Rnd_556x45_Stanag','20Rnd_556x45_Stanag','HandGrenade_West','HandGrenade_West','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD','15Rnd_9x19_M9SD'],true] Call SetNamespace;
	//--- Upgrade 2.
	['WFBE_WESTLEADERWEAPONS21',['M4A1_Aim_camo','SMAW','Colt1911','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO21',['30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','SMAW_HEAA','SMAW_HEAA','SMAW_HEDP','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911'],true] Call SetNamespace;
	['WFBE_WESTLEADERWEAPONS22',['m8_carbine','SMAW','Colt1911','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO22',['30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','SMAW_HEAA','SMAW_HEAA','SMAW_HEDP','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911'],true] Call SetNamespace;
	['WFBE_WESTLEADERWEAPONS23',['MG36','Colt1911','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO23',['100Rnd_556x45_BetaCMag','100Rnd_556x45_BetaCMag','100Rnd_556x45_BetaCMag','100Rnd_556x45_BetaCMag','100Rnd_556x45_BetaCMag','HandGrenade_West','HandGrenade_West','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911'],true] Call SetNamespace;
	//--- Upgrade 3.
	['WFBE_WESTLEADERWEAPONS31',['M4A1_HWS_GL','SMAW','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO31',['30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','30Rnd_556x45_Stanag','SMAW_HEAA','SMAW_HEAA','SMAW_HEDP','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203','1Rnd_HE_M203'],true] Call SetNamespace;
	['WFBE_WESTLEADERWEAPONS32',['m8_compact','Javelin','Colt1911','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO32',['30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','30Rnd_556x45_G36','Javelin','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911'],true] Call SetNamespace;
	['WFBE_WESTLEADERWEAPONS33',['Mk_48','Colt1911','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_WESTLEADERAMMO33',['100Rnd_762x51_M240','100Rnd_762x51_M240','100Rnd_762x51_M240','100Rnd_762x51_M240','100Rnd_762x51_M240','HandGrenade_West','HandGrenade_West','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911','7Rnd_45ACP_1911'],true] Call SetNamespace;
};