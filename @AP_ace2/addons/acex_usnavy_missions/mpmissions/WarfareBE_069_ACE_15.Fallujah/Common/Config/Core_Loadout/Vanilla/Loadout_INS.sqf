/* USMC Loadout */

if (!isServer || local player) then {		
	if (side player == EAST) then {
		/* Magazines. */
		_m = ["30Rnd_762x39_AK47"];
		_m = _m + ["30Rnd_545x39_AK"];
		_m = _m + ["30Rnd_545x39_AKSD"];
		_m = _m + ["64Rnd_9x19_Bizon"];
		_m = _m + ["64Rnd_9x19_SD_Bizon"];
		_m = _m + ["100Rnd_762x54_PK"];
		_m = _m + ["75Rnd_545x39_RPK"];
		_m = _m + ["5x_22_LR_17_HMR"];
		_m = _m + ["10Rnd_762x54_SVD"];
		_m = _m + ["8Rnd_B_Saiga12_74Slug"];
		_m = _m + ["5Rnd_127x108_KSVK"];
		_m = _m + ["10Rnd_9x39_SP5_VSS"];
		_m = _m + ["20Rnd_9x39_SP5_VSS"];
		_m = _m + ["PG7V"];
		_m = _m + ["PG7VL"];
		_m = _m + ["OG7"];
		_m = _m + ["PG7VR"];
		_m = _m + ["RPG18"];
		_m = _m + ["AT13"];
		_m = _m + ["Igla"];
		_m = _m + ["Strela"];
		_m = _m + ["Laserbatteries"];
		_m = _m + ["8Rnd_9x18_Makarov"];
		_m = _m + ["8Rnd_9x18_MakarovSD"];

		WF_Logic setVariable ['magazineClasses',_m];

		/* Primary. */
		_w = ['AK_47_M'];
		_w = _w + ['AK_47_S'];
		_w = _w + ['AK_74'];
		_w = _w + ['AK_74_GL'];
		_w = _w + ['AKS_74_kobra'];
		_w = _w + ['AKS_74_pso'];
		_w = _w + ['AKS_74_U'];
		_w = _w + ['AKS_74_UN_kobra'];
		_w = _w + ['AKS_GOLD'];
		_w = _w + ['bizon'];
		_w = _w + ['bizon_silenced'];
		_w = _w + ['PK'];
		_w = _w + ['RPK_74'];
		_w = _w + ['huntingrifle'];
		_w = _w + ['SVD'];
		_w = _w + ['SVD_CAMO'];
		_w = _w + ['Saiga12K'];
		_w = _w + ['ksvk'];
		_w = _w + ['VSS_vintorez'];

		WF_Logic setVariable ['primaryClasses',_w];

		/* Secondary. */
		_w = ['RPG7V'];
		_w = _w + ['RPG18'];
		_w = _w + ['MetisLauncher'];
		_w = _w + ['Igla'];
		_w = _w + ['Strela'];
		_w = _w + ['Laserdesignator'];

		WF_Logic setVariable ['secondaryClasses',_w];

		/* Sidearms. */
		_w = ['Makarov'];
		_w = _w + ['MakarovSD'];

		WF_Logic setVariable ['sidearmClasses',_w];

		/* Misc. */
		_w = ['HandGrenade_East'];
		_w = _w + ['HandGrenade_Stone'];
		_w = _w + ['SmokeShell'];
		_w = _w + ['SmokeShellRed'];
		_w = _w + ['SmokeShellGreen'];
		_w = _w + ['SmokeShellBlue'];
		_w = _w + ['SmokeShellYellow'];
		_w = _w + ['SmokeShellOrange'];
		_w = _w + ['SmokeShellPurple'];
		_w = _w + ['FlareWhite_GP25'];
		_w = _w + ['FlareYellow_GP25'];
		_w = _w + ['FlareGreen_GP25'];
		_w = _w + ['FlareRed_GP25'];
		_w = _w + ['1Rnd_HE_GP25'];
		_w = _w + ['1Rnd_SMOKE_GP25'];
		_w = _w + ['1Rnd_SMOKERED_GP25'];
		_w = _w + ['1Rnd_SMOKEGREEN_GP25'];
		_w = _w + ['1Rnd_SMOKEYELLOW_GP25'];
		_w = _w + ['MineE'];
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

		_d = [getText(configFile >> 'CfgWeapons' >> 'AKS_74_kobra' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Makarov' >> 'displayName')];
		_p = [getText(configFile >> 'CfgWeapons' >> 'AKS_74_kobra' >> 'picture')];
		_t = [['AKS_74_kobra','Makarov']];
		_m = [['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK',
			'HandGrenade_East','HandGrenade_East','SmokeShellBlue','SmokeShellBlue','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov',
			'8Rnd_9x18_Makarov','8Rnd_9x18_Makarov']];
		_s = [['Binocular']];
		_i = [_items];
		_l = [0];
		_b = [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'AK_74_GL' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'AK_74_GL' >> 'picture')];
		_t = _t + [['AK_74_GL']];
		_m = _m + [['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK',
			'30Rnd_545x39_AK','30Rnd_545x39_AK','HandGrenade_East','HandGrenade_East','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25',
			'1Rnd_HE_GP25','1Rnd_HE_GP25']];
		_s = _s + [['Binocular']];
		_i = _i + [_items];
		_l = _l + [0];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'AKS_74_pso' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'RPG7V' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'AKS_74_pso' >> 'picture')];
		_t = _t + [['AKS_74_pso','RPG7V']];
		_m = _m + [['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','PG7VL','PG7VL','PG7VL']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [1];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'AK_74_GL' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'RPG7V' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'AK_74_GL' >> 'picture')];
		_t = _t + [['AK_74_GL','RPG7V']];
		_m = _m + [['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','PG7V',
			'PG7V','PG7V','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [1];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'AKS_74_U' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'RPG7V' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Makarov' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'AKS_74_U' >> 'picture')];
		_t = _t + [['AKS_74_U','RPG7V','Makarov']];
		_m = _m + [['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','PG7VL','PG7VL','PG7VL',
			'8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [1];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'AKS_74_kobra' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'MetisLauncher' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Makarov' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'AKS_74_kobra' >> 'picture')];
		_t = _t + [['AKS_74_kobra','MetisLauncher','Makarov']];
		_m = _m + [['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','AT13',
			'8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [3];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'AK_74' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Igla' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Makarov' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'AK_74' >> 'picture')];
		_t = _t + [['AK_74','Igla','Makarov']];
		_m = _m + [['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','Igla',
			'8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [2];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'Saiga12K' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Makarov' >> 'displayName') + '/' + getText(configFile >> 'CfgMagazines' >> 'MineE' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'Saiga12K' >> 'picture')];
		_t = _t + [['Saiga12K','Makarov']];
		_m = _m + [['8Rnd_B_Saiga12_74Slug','8Rnd_B_Saiga12_74Slug','8Rnd_B_Saiga12_74Slug','8Rnd_B_Saiga12_74Slug','8Rnd_B_Saiga12_74Slug','8Rnd_B_Saiga12_74Slug','MineE','MineE','MineE',
			'8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov']];
		_s = _s + [['Binocular']];
		_i = _i + [_items];
		_l = _l + [0];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'AKS_74_UN_kobra' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'MakarovSD' >> 'displayName') + '/' + getText(configFile >> 'CfgMagazines' >> 'PipeBomb' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'AKS_74_UN_kobra' >> 'picture')];
		_t = _t + [['AKS_74_UN_kobra','MakarovSD']];
		_m = _m + [['30Rnd_545x39_AKSD','30Rnd_545x39_AKSD','30Rnd_545x39_AKSD','30Rnd_545x39_AKSD','30Rnd_545x39_AKSD','30Rnd_545x39_AKSD','PipeBomb','PipeBomb','PipeBomb',
			'8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [2];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'PK' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Makarov' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'PK' >> 'picture')];
		_t = _t + [['PK','Makarov']];
		_m = _m + [['100Rnd_762x54_PK','100Rnd_762x54_PK','100Rnd_762x54_PK','100Rnd_762x54_PK','100Rnd_762x54_PK','SmokeShellBlue','SmokeShellBlue','8Rnd_9x18_Makarov',
			'8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov']];
		_s = _s + [['Binocular']];
		_i = _i + [_items];
		_l = _l + [0];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'SVD' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'MakarovSD' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'SVD' >> 'picture')];
		_t = _t + [['SVD','MakarovSD']];
		_m = _m + [['10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD',
			'10Rnd_762x54_SVD','10Rnd_762x54_SVD','HandGrenade_East','HandGrenade_East','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD',
			'8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD']];
		_s = _s + [['Binocular']];
		_i = _i + [_items];
		_l = _l + [1];
		_b = _b + [true];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'VSS_vintorez' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'Laserdesignator' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'MakarovSD' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'VSS_vintorez' >> 'picture')];
		_t = _t + [['VSS_vintorez','Laserdesignator','MakarovSD']];
		_m = _m + [['20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS',
			'20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','HandGrenade_East','Laserbatteries','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD',
			'8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD']];
		_s = _s + [['Binocular','NVGoggles']];
		_i = _i + [_items];
		_l = _l + [2];
		_b = _b + [false];

		_d = _d + [getText(configFile >> 'CfgWeapons' >> 'ksvk' >> 'displayName') + '/' + getText(configFile >> 'CfgWeapons' >> 'MakarovSD' >> 'displayName')];
		_p = _p + [getText(configFile >> 'CfgWeapons' >> 'ksvk' >> 'picture')];
		_t = _t + [['ksvk','MakarovSD']];
		_m = _m + [['5Rnd_127x108_KSVK','5Rnd_127x108_KSVK','5Rnd_127x108_KSVK','5Rnd_127x108_KSVK','5Rnd_127x108_KSVK','5Rnd_127x108_KSVK','5Rnd_127x108_KSVK','5Rnd_127x108_KSVK',
			'5Rnd_127x108_KSVK','5Rnd_127x108_KSVK','HandGrenade_East','HandGrenade_East','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD',
			'8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD']];
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

['WFBE_EASTDEFAULTWEAPONS',['AK_74','ItemCompass','ItemMap','ItemWatch','ItemRadio'],true] Call SetNamespace;
['WFBE_EASTDEFAULTAMMO',['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','HandGrenade_East','HandGrenade_East'],true] Call SetNamespace;

//--- AI Leaders Loadouts.
if (isServer) then {
	//--- No Upgrade.
	['WFBE_EASTLEADERWEAPONS01',['AKS_74_kobra','RPG18','Makarov','Binocular','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO01',['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','RPG18','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov'],true] Call SetNamespace;
	['WFBE_EASTLEADERWEAPONS02',['AKS_74_kobra','RPG18','Makarov','Binocular','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO02',['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','RPG18','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov'],true] Call SetNamespace;
	['WFBE_EASTLEADERWEAPONS03',['PK','Makarov','Binocular','ItemRadio','ItemMap'],true] Call SetNamespace;;
	['WFBE_EASTLEADERAMMO03',['100Rnd_762x54_PK','100Rnd_762x54_PK','100Rnd_762x54_PK','100Rnd_762x54_PK','100Rnd_762x54_PK','HandGrenade_East','HandGrenade_East','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov'],true] Call SetNamespace;
	//--- Upgrade 1.
	['WFBE_EASTLEADERWEAPONS11',['AK_74_GL','RPG7V','Makarov','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO11',['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','PG7VL','PG7VL','PG7VR','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov'],true] Call SetNamespace;
	['WFBE_EASTLEADERWEAPONS12',['RPK_74','RPG7V','Makarov','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO12',['75Rnd_545x39_RPK','75Rnd_545x39_RPK','75Rnd_545x39_RPK','75Rnd_545x39_RPK','75Rnd_545x39_RPK','75Rnd_545x39_RPK','PG7VL','PG7VL','PG7VR','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov'],true] Call SetNamespace;
	['WFBE_EASTLEADERWEAPONS13',['SVD','MakarovSD','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO13',['10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','HandGrenade_East','HandGrenade_East','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD','8Rnd_9x18_MakarovSD'],true] Call SetNamespace;
	//--- Upgrade 2.
	['WFBE_EASTLEADERWEAPONS21',['VSS_vintorez','RPG7V','Makarov','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO21',['20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','20Rnd_9x39_SP5_VSS','PG7VL','PG7VL','PG7VL','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov'],true] Call SetNamespace;
	['WFBE_EASTLEADERWEAPONS22',['AKS_74_pso','RPG7V','Makarov','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO22',['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','PG7VL','PG7VL','PG7VL','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov'],true] Call SetNamespace;
	['WFBE_EASTLEADERWEAPONS23',['RPK_74','Makarov','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO23',['75Rnd_545x39_RPK','75Rnd_545x39_RPK','75Rnd_545x39_RPK','75Rnd_545x39_RPK','75Rnd_545x39_RPK','75Rnd_545x39_RPK','HandGrenade_East','HandGrenade_East','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov'],true] Call SetNamespace;
	//--- Upgrade 3.
	['WFBE_EASTLEADERWEAPONS31',['AK_74_GL','RPG7V','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO31',['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','PG7VL','PG7VL','PG7VL','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25','1Rnd_HE_GP25'],true] Call SetNamespace;
	['WFBE_EASTLEADERWEAPONS32',['AKS_74_kobra','MetisLauncher','Makarov','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO32',['30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','30Rnd_545x39_AK','AT13','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov'],true] Call SetNamespace;
	['WFBE_EASTLEADERWEAPONS33',['SVD_CAMO','Makarov','Binocular','NVGoggles','ItemRadio','ItemMap'],true] Call SetNamespace;
	['WFBE_EASTLEADERAMMO33',['10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','10Rnd_762x54_SVD','HandGrenade_East','HandGrenade_East','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov','8Rnd_9x18_Makarov'],true] Call SetNamespace;
};