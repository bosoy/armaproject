// fo// for Arma 2 Combined Operations with ACE
// last update 19/1/2011

_vec = _this select 0;
_side = _this select 1;
_ammoOnly=false;
if (count _this > 2) then
{
	_ammoOnly = _this select 2;
};

_vec allowDamage false;

canSave=true;
_vec addAction ["Save Loadout" ,"saveLoadout.sqf", [] ,1,false,true,"", "canSave"];

while {true} do
{

clearWeaponCargo _vec;
clearMagazineCargo _vec;


if (_ammoOnly || _side == WEST || sideweapons>1) then
{

	if (launchers>2) then
	{

		// USMC heavy launchers

		if (!_ammoOnly) then
		{
			_vec addWeaponCargo ["JAVELIN",20];
			_vec addWeaponCargo ["Stinger",20];
			_vec addWeaponCargo ["SMAW",20];
			
			_vec addWeaponCargo ["M47Launcher_EP1", 20];
			_vec addWeaponCargo ["MAAWS", 20];
		};
		_vec addWeaponCargo ["ACE_Javelin_CLU",20];
		_vec addMagazineCargo ["Stinger",20];
		_vec addMagazineCargo ["SMAW_HEAA", 60];
		_vec addMagazineCargo ["ACE_SMAW_Spotting", 40];
		
		_vec addMagazineCargo ["Dragon_EP1", 20];
		_vec addMagazineCargo ["MAAWS_HEAT", 60]; //EP1
		
	};
	
	if (launchers>1) then
	{
		// US medium launchers
		if (!_ammoOnly) then
		{
			_vec addWeaponCargo ["M136",40];
		};
	};

	if (launchers>0) then
	{

		// US light launchers

		if (!_ammoOnly) then
		{
			_vec addWeaponCargo ["ACE_M72A2",40];
		};
	};

	if (explosives>0) then
	
	{
		// US light explosives
		
		_vec addMagazineCargo ["HandGrenade_West",80];
		
	};
	
	if (explosives>4) then
	{

		// US heavy explosives

		if (!_ammoOnly) then
		{
			_vec addWeaponCargo ["M32_EP1", 20];
			_vec AddWeaponCargo ["M79_EP1", 20];
			if (futureweapons>0) then
			{
				_vec addWeaponCargo ["Mk13_EP1", 20];
			};
		};
		_vec addMagazineCargo ["ACE_40mm_Buck_M79", 80];
		if (launchers>2) then
		{
			_vec addMagazineCargo ["SMAW_HEDP", 40];
			_vec addMagazineCargo ["ACE_SMAW_NE", 40];
			_vec addMagazineCargo ["MAAWS_HEDP", 40]; //EP1
			_vec addMagazineCargo ["ACE_MAAWS_HE", 40];
		};
		
		_vec addMagazineCargo ["6Rnd_HE_M203", 40]; //EP1
		_vec addMagazineCargo ["6Rnd_FlareGreen_M203", 20]; //EP1
		_vec addMagazineCargo ["6Rnd_FlareRed_M203", 20]; //EP1
		_vec addMagazineCargo ["6Rnd_FlareWhite_M203", 40]; //EP1
		_vec addMagazineCargo ["6Rnd_FlareYellow_M203", 20]; //EP1
		_vec addMagazineCargo ["6Rnd_Smoke_M203", 40]; //EP1
		_vec addMagazineCargo ["6Rnd_SmokeGreen_M203", 20]; //EP1
		_vec addMagazineCargo ["6Rnd_SmokeRed_M203", 35]; //EP1
		
		if (lessThanLethal>0) then
		{
			_vec addMagazineCargo ["ACE_6Rnd_CS_M32", 35];
		};
		
	};

	// US pistols

	if (!_ammoOnly) then
	{
		_vec AddWeaponCargo ["M9", 20];
		_vec AddWeaponCargo ["Colt1911", 20];
		_vec AddWeaponCargo ["ACE_L9A1", 20];
		
		if (sfweapons>0) then
		{
			_vec AddWeaponCargo ["ACE_Glock18", 20];
			_vec AddWeaponCargo ["ACE_P226", 20];
			_vec AddWeaponCargo ["ACE_P8", 20];
			_vec AddWeaponCargo ["ACE_USP", 20];
		
			_vec addWeaponCargo ["glock17_EP1", 20];
		};
	};
	_vec addmagazinecargo ["15rnd_9x19_m9", 60];
	_vec addMagazineCargo ["7Rnd_45ACP_1911", 60];
	_vec addMagazineCargo ["ACE_13Rnd_9x19_L9A1", 60];

	if (sfweapons>0) then
	{
		_vec addMagazineCargo ["ACE_33Rnd_9x19_G18", 60];
		_vec addMagazineCargo ["ACE_15Rnd_9x19_P226", 60];
		_vec addMagazineCargo ["ACE_15Rnd_9x19_P8", 60];
		_vec addMagazineCargo ["ACE_12Rnd_45ACP_USP", 60];
	
		_vec addMagazineCargo ["17Rnd_9x19_glock17", 60]; //EP1
	};
	if (sfweapons>1) then
	{
		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["M9SD", 20];
			_vec AddWeaponCargo ["ACE_USPSD", 20];
		};
		_vec addmagazinecargo ["15rnd_9x19_m9sd", 60];
		_vec addMagazineCargo ["ACE_12Rnd_45ACP_USPSD", 80];
	};
	
	// US SMGs
	
	if (weaponTypes>0) then
	{
		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["MP5A5", 20];
			_vec AddWeaponCargo ["ACE_MP5A4", 20];
			_vec AddWeaponCargo ["ACE_M3A1", 20];
			if (caliber>1) then
			{
				_vec AddWeaponCargo ["ACE_KAC_PDW", 20];
				_vec AddWeaponCargo ["ACE_MP7", 20];
				_vec AddWeaponCargo ["ACE_MP7_RSAS", 20];
			};
		};
		
		_vec addmagazinecargo ["30Rnd_9x19_MP5", 80];
		_vec addmagazinecargo ["ACE_30Rnd_1143x23_B_M3", 80];
		if (caliber>1) then
		{
			_vec addMagazineCargo ["ACE_30Rnd_6x35_B_PDW", 80];
			_vec addMagazineCargo ["ACE_40Rnd_B_46x30_MP7", 80];
		};

		if (sfweapons>1) then
		{
			if (!_ammoOnly) then
			{
				_vec AddWeaponCargo ["MP5SD", 20];
			};
		};
		
	};
	
	if (weaponTypes>1) then
	{
		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["M1014", 20];
			
			_vec addWeaponCargo ["ACE_M1014_Eotech", 20];
		};
		
		_vec addMagazineCargo ["8Rnd_B_Beneli_74Slug", 80];
	};
	
	if (weaponTypes>2 && caliber>2) then
	{
		// US rifles
		
		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["M16A2", 20];
			_vec AddWeaponCargo ["M16A2GL", 20];
			_vec AddWeaponCargo ["M16A4", 20];
			
			_vec AddWeaponCargo ["M4A1", 20];
			_vec AddWeaponCargo ["M4A1_HWS_GL", 20];
			_vec AddWeaponCargo ["M4A1_Aim", 20];
			_vec AddWeaponCargo ["M4A1_Aim_camo", 20];

			_vec AddWeaponCargo ["ACE_M16A4_Iron", 20];
			_vec AddWeaponCargo ["ACE_M16A4_CCO_GL", 20];
			_vec AddWeaponCargo ["ACE_M4A1_GL", 20];
			_vec AddWeaponCargo ["ACE_M4A1_Eotech", 20];
			_vec AddWeaponCargo ["ACE_M4A1_AIM_GL", 20];
			_vec AddWeaponCargo ["ACE_M4", 20];
			_vec AddWeaponCargo ["ACE_M4_Aim", 20];
			_vec AddWeaponCargo ["ACE_M4_AIM_GL", 20];
			_vec AddWeaponCargo ["ACE_M4_Eotech", 20];
			_vec addWeaponCargo ["ACE_M4_GL", 20];
		
			_vec AddWeaponCargo ["ACE_SOC_M4A1_Eotech", 20];
			_vec AddWeaponCargo ["ACE_SOC_M4A1_GL", 20];
			_vec AddWeaponCargo ["ACE_SOC_M4A1_GL_EOTECH", 20];
			_vec AddWeaponCargo ["ACE_SOC_M4A1_GL_AIMPOINT", 20];
			_vec AddWeaponCargo ["ACE_SOC_M4A1_Aim", 20];
			
			if (sfweapons>0) then
			{
				_vec AddWeaponCargo ["ACE_SOC_M4A1", 20];
				_vec AddWeaponCargo ["M4A1_HWS_GL_camo", 20];
				_vec AddWeaponCargo ["ACE_SOC_M4A1_GL_13", 20];
				_vec addWeaponCargo ["ACE_HuntIR_monitor", 20];
				_vec addWeaponCargo ["ACE_SOC_M4A1_Eotech_4x", 20];
				if (nightSights>1) then
				{
					_vec addWeaponCargo ["ACE_SOC_M4A1_TWS", 20];
				};
			};
			
			if (caliber>4) then
			{
				_vec AddWeaponCargo ["LeeEnfield", 20]; //EP1
			};
			
			if (scopes>0) then
			{
				_vec AddWeaponCargo ["M16A4_ACG", 20];
				_vec AddWeaponCargo ["M16A4_ACG_GL", 20];
				_vec AddWeaponCargo ["M4A1_RCO_GL", 20];
				_vec addWeaponCargo ["ACE_M4A1_RCO2_GL", 20];
				_vec addWeaponCargo ["ACE_M4_RCO_GL", 20];
				
				_vec addWeaponCargo ["ACE_m16a2_scope", 20];
				_vec addWeaponCargo ["ACE_m16a2gl_scope", 20];
				
				_vec AddWeaponCargo ["ACE_SOC_M4A1_RCO_GL", 20];
				_vec AddWeaponCargo ["ACE_M4A1_ACOG", 20];
				_vec addWeaponCargo ["ACE_M4_ACOG", 20];
				
				if (caliber>4) then
				{
					_vec AddWeaponCargo ["M24", 20];
					_vec AddWeaponCargo ["M40A3", 20];
					
					_vec addWeaponCargo ["M24_des_EP1", 20];
				};
				
				if (sfweapons>0) then
				{
					_vec AddWeaponCargo ["ACE_SOC_M4A1_SHORTDOT", 20];
					_vec addWeaponCargo ["ACE_SOC_M4A1_Eotech_4x", 20];
					
					_vec AddWeaponCargo ["M4SPR", 20];
					_vec AddWeaponCargo ["ACE_Mk12mod1", 20];
				};
			};
		};

		_vec addmagazinecargo ["30rnd_556x45_Stanag", 80];
		_vec addmagazinecargo ["20Rnd_556x45_Stanag", 80];
		
		_vec addMagazineCargo ["FlareWhite_M203",60];
		_vec addMagazineCargo ["FlareRed_M203",40];
		_vec addMagazineCargo ["FlareGreen_M203",40];
		_vec addMagazineCargo ["FlareYellow_M203",40];
		
		if (caliber>4) then
		{
			_vec addMagazineCargo ["10x_303", 80]; //EP1
			_vec addmagazinecargo ["5Rnd_762x51_M24", 80];
		};
		
		if (sfweapons>0) then
		{
			_vec addMagazineCargo ["ACE_HuntIR_M203", 60];
		};

		_vec addMagazineCargo ["1Rnd_Smoke_M203", 50];
		_vec addMagazineCargo ["1Rnd_SmokeGreen_M203", 35];
		_vec addMagazineCargo ["1Rnd_SmokeRed_M203", 35];
		_vec addMagazineCargo ["1Rnd_SmokeYellow_M203", 35];
		
		if (explosives>0) then
		{
			_vec addMagazineCargo ["1rnd_HE_M203",60];
			_vec addMagazineCargo ["ACE_1Rnd_HE_M203",60];
		};
		if (lessThanLethal>0) then
		{
			_vec addMagazineCargo ["ACE_1Rnd_CS_M203",50];
		};
		
		if (sfweapons>1) then
		{
			if (!_ammoOnly) then
			{
				_vec AddWeaponCargo ["M4A1_HWS_GL_SD_Camo", 20];
				_vec AddWeaponCargo ["M4A1_AIM_SD_camo", 20];
			
				_vec AddWeaponCargo ["ACE_M4A1_GL_SD", 20];
				_vec AddWeaponCargo ["ACE_M4A1_Aim_SD", 20];
			
				_vec AddWeaponCargo ["ACE_SOC_M4A1_GL_SD", 20];
				_vec AddWeaponCargo ["ACE_SOC_M4A1_AIM_SD", 20];
				_vec AddWeaponCargo ["ACE_SOC_M4A1_SD_9", 20];
				
				_vec AddWeaponCargo ["ACE_M4A1_AIM_GL_SD", 20];
				
				if (scopes>0) then
				{
					_vec AddWeaponCargo ["ACE_M4SPR_SD", 20];
					_vec AddWeaponCargo ["ACE_Mk12mod1_SD", 20];
					
					_vec AddWeaponCargo ["ACE_SOC_M4A1_SHORTDOT_SD", 20];
					_vec AddWeaponCargo ["ACE_M4A1_ACOG_SD", 20];
				};
			};
			
			_vec addmagazinecargo ["30Rnd_556x45_StanagSD", 80];
		};
		
		if (futureweapons>0 && sfweapons>0) then
		{
			if (!_ammoOnly) then
			{
				if (caliber>4) then
				{
					_vec AddWeaponCargo ["SCAR_H_CQC_CCO", 20]; //EP1
				};
				_vec AddWeaponCargo ["SCAR_L_CQC", 20];
				_vec AddWeaponCargo ["SCAR_L_CQC_EGLM_Holo", 20];
				_vec AddWeaponCargo ["SCAR_L_CQC_Holo", 20];
				
				_vec AddWeaponCargo ["SCAR_L_STD_HOLO", 20];
				
				
				if (scopes>0) then
				{
					_vec AddWeaponCargo ["SCAR_L_STD_Mk4CQT", 20];
					_vec AddWeaponCargo ["SCAR_L_STD_EGLM_RCO", 20];
					if (caliber>4) then
					{
						_vec AddWeaponCargo ["SCAR_H_STD_EGLM_Spect", 20];
						_vec AddWeaponCargo ["ACE_SCAR_H_STD_Spect", 20];
					};
				};
				
				if (nightSights>1) then
				{
					_vec AddWeaponCargo ["SCAR_L_STD_EGLM_TWS", 20];
				};
			};
			
			if (caliber>4) then
			{
				_vec addMagazineCargo ["20Rnd_762x51_B_SCAR", 80];
			};
			
			if (sfweapons>1) then
			{
				if (!_ammoOnly) then
				{
					if (caliber>4) then
					{
						_vec AddWeaponCargo ["SCAR_H_CQC_CCO_SD", 20];
					};
					_vec AddWeaponCargo ["SCAR_L_CQC_CCO_SD", 20];
				};
				if (caliber>4) then
				{
					_vec addMagazineCargo ["20Rnd_762x51_SB_SCAR", 80]; //may need to be removed
				};
			};
		};
		
	};

	if (sideweapons>0 && weaponTypes>2 && caliber>2) then
	{
		// Non-US west light rifles

		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["G36C", 20];
			
			//_vec AddWeaponCargo ["ACE_G36K", 20];
			//_vec AddWeaponCargo ["ACE_G36K_D", 20];
			_vec AddWeaponCargo ["ACE_G36K_EOTech", 20];
			_vec AddWeaponCargo ["ACE_G36K_EOTech_D", 20];
			_vec AddWeaponCargo ["ACE_G36K_iron", 20];
			_vec AddWeaponCargo ["ACE_G36K_iron_D", 20];
			
			//_vec AddWeaponCargo ["ACE_SA58", 20];
			
			if (caliber>4) then
			{
				//_vec AddWeaponCargo ["ACE_FAL_Para", 20];
				_vec AddWeaponCargo ["ACE_G3A3", 20];
				_vec addWeaponCargo ["ACE_G3A3_RSAS", 20];
				if (sfweapons>0) then
				{
					if (scopes>0) then
					{
						_vec addWeaponCargo ["ACE_HK417_Shortdot", 20];
						_vec addWeaponCargo ["ACE_HK417_leupold", 20];
						_vec AddWeaponCargo ["ACE_HK417_Eotech_4x", 20];
					};
					_vec addWeaponCargo ["ACE_HK417_micro", 20];
				};
			};
			
			if (sfweapons>0) then
			{
				_vec AddWeaponCargo ["ACE_HK416_D10", 20];
				_vec AddWeaponCargo ["ACE_HK416_D10_COMPM3", 20];
				_vec AddWeaponCargo ["ACE_HK416_D10_M320", 20];
				_vec AddWeaponCargo ["ACE_HK416_D10_AIM", 20];
				_vec AddWeaponCargo ["ACE_HK416_D14", 20];
				_vec AddWeaponCargo ["ACE_HK416_D14_COMPM3", 20];
				_vec AddWeaponCargo ["ACE_HK416_D14_COMPM3_M320", 20];
				_vec AddWeaponCargo ["ACE_HK416_D10_Holo", 20];
				
				if (nightSights>0) then
				{
					_vec addWeaponCargo ["ACE_HK416_D14_ACOG_PVS14", 20];
				};
				if (nightSights>1) then
				{
					_vec addWeaponCargo ["ACE_HK416_D14_TWS", 20];
				};
				if (futureweapons>0) then
				{
					_vec addWeaponCargo ["ACE_M27_IAR", 20];
					if (scopes>0) then
					{
						_vec addWeaponCargo ["ACE_M27_IAR_ACOG", 20];
					};
				};
			};
			
			if (caliber>4) then
			{
				_vec AddWeaponCargo ["FN_FAL", 20]; //EP1
				if (nightSights>0) then
				{
					_vec AddWeaponCargo ["FN_FAL_ANPVS4", 20]; //EP1
				};
			};
			
			_vec AddWeaponCargo ["M4A3_CCO_EP1", 20];
			
			if (scopes>0) then
			{
				_vec AddWeaponCargo ["G36a", 20];
				_vec AddWeaponCargo ["G36K", 20];
				
				_vec AddWeaponCargo ["huntingrifle", 20];
				
				_vec AddWeaponCargo ["ACE_G36A1_AG36A1", 20];
				_vec AddWeaponCargo ["ACE_G36A1_AG36A1_D", 20];
				_vec AddWeaponCargo ["ACE_G36A2", 20];
				_vec addWeaponCargo ["ACE_G36A2_D", 20];
				_vec AddWeaponCargo ["ACE_G36A2_Bipod", 20];
				_vec AddWeaponCargo ["ACE_G36A2_Bipod_D", 20];
				
				//_vec AddWeaponCargo ["ACE_G36", 20];
				//_vec AddWeaponCargo ["ACE_G36A1", 20];
				//_vec AddWeaponCargo ["ACE_G36A1_D", 20];
				
				_vec AddWeaponCargo ["G36C_camo", 20]; //EP1
				_vec AddWeaponCargo ["G36K_camo", 20]; //EP1
				
				_vec AddWeaponCargo ["M4A3_RCO_GL_EP1", 20];
			};
		};
		_vec addmagazinecargo ["30Rnd_556x45_G36",80];
		_vec addMagazineCargo ["5x_22_LR_17_HMR", 80];

		if (caliber>4) then
		{
			_vec addMagazineCargo ["ACE_20Rnd_762x51_B_G3", 80];
			
			if (sfweapons>0) then
			{
				_vec addMagazineCargo ["ACE_20Rnd_762x51_B_HK417", 80];
			};
		
			_vec addMagazineCargo ["20Rnd_762x51_FNFAL", 80]; //EP1
		};
		
		if (sfweapons>1) then
		{
			if (!_ammoOnly) then
			{
				_vec addWeaponCargo ["G36_C_SD_camo", 20]; //EP1
				
				_vec AddWeaponCargo ["G36_C_SD_eotech", 20];
				_vec AddWeaponCargo ["ACE_HK416_D10_COMPM3_SD", 20];
				_vec AddWeaponCargo ["ACE_HK416_D10_SD", 20];
				_vec AddWeaponCargo ["ACE_HK416_D14_SD", 20];
			};
			_vec addmagazinecargo ["30Rnd_556x45_G36SD",80];
		};

	};
	
	if (sideweapons>0 && weaponTypes>0) then
	{
	
		// Non-US west SMGs
		
		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["ACE_UMP45", 20];
			_vec AddWeaponCargo ["UZI_EP1", 20];
			_vec AddWeaponCargo ["UZI_SD_EP1", 20];
		};
		_vec addMagazineCargo ["ACE_25Rnd_1143x23_B_UMP45", 80];
		_vec addMagazineCargo ["30Rnd_9x19_UZI", 60]; //EP1
		_vec addMagazineCargo ["30Rnd_9x19_UZI_SD", 60]; //EP1, may need to remove
		
		if (sfweapons>1) then
		{
			if (!_ammoOnly) then
			{
				_vec AddWeaponCargo ["ACE_UMP45_SD", 20];
			};
		};
		
	};
	
	if (sideweapons>0 && weaponTypes>1) then
	{
	
		// Non-US west shotguns
		
		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["ACE_SPAS12", 20];	
		};
		_vec addMagazineCargo ["ACE_8Rnd_12Ga_Slug", 80];
		_vec addMagazineCargo ["ACE_8Rnd_12Ga_Buck00", 80];
		
	};

	if (weaponTypes>3) then
	{

		// US heavy weaponTypes

		if (!_ammoOnly) then
		{			
			_vec AddWeaponCargo ["M249", 20];
			//_vec AddWeaponCargo ["ACE_M249Para", 20];
			
			_vec addWeaponCargo ["M249_EP1", 20];
			
			if (nightSights>1) then
			{
				_vec addWeaponCargo ["M249_TWS_EP1", 20];
			};
			
			if (scopes>0) then
			{
				_vec addWeaponCargo ["M249_M145_EP1", 20];
				
				//_vec AddWeaponCargo ["ACE_M249Para_M145", 20];
			};
			
			if (caliber>4) then
			{
				if (sfweapons>0) then
				{
					_vec AddWeaponCargo ["M14_EP1", 20];
					if (scopes>0) then
					{
						_vec AddWeaponCargo ["ACE_M14_ACOG", 20];
					};
					if (nightSights>0 && futureweapons>0 && scopes>0) then
					{
						_vec AddWeaponCargo ["M110_NVG_EP1", 20];
					};
					if (nightSights>1 && futureweapons>0 && scopes>0) then
					{
						_vec AddWeaponCargo ["M110_TWS_EP1", 20];
					};
				};
				if (_scweaponTypes>1) then
				{
					_vec AddWeaponCargo ["ACE_M110_SD", 20];
				};
				if (scopes>0) then
				{
					_vec AddWeaponCargo ["DMR", 20];
					if (futureweapons>0 && sfweapons>0) then
					{
						_vec AddWeaponCargo ["ACE_M110", 20];
					};
				};
			};
		};
		if (scopes>0 && caliber>4) then
		{
			_vec addMagazineCargo ["20Rnd_762x51_DMR", 80];
		};
		
		_vec addmagazinecargo ["200Rnd_556x45_M249", 50];
		
		if (sideweapons>0 && scopes>0) then
		{
			// non-US west heavy weaponTypes
			
			if (!_ammoOnly) then
			{
				_vec AddWeaponCargo ["MG36_camo", 20]; //EP1
				_vec AddWeaponCargo ["MG36", 20];
				//_vec AddWeaponCargo ["ACE_MG36A1", 20];
				//_vec AddWeaponCargo ["ACE_MG36A1_D", 20];
				if (caliber>4) then
				{
					_vec AddWeaponCargo ["ACE_G3SG1", 20];
				};
			};
			if (hiCapMags>1) then
			{
				_vec addMagazineCargo ["100Rnd_556x45_BetaCMag", 50];
			};
		};
		
		if (futureweapons>0 && caliber>4 && sfweapons>0) then
		{
			if (!_ammoOnly) then
			{
				if (scopes>0) then
				{
					_vec AddWeaponCargo ["SCAR_H_LNG_Sniper", 20];
				};
			};
			
			if (sfweapons>1) then
			{
				if (!_ammoOnly) then
				{
					if (nightSights>1) then
					{
						_vec AddWeaponCargo ["SCAR_H_STD_TWS_SD", 20];
					};
					if (scopes>0) then
					{
						_vec AddWeaponCargo ["SCAR_H_LNG_Sniper_SD", 20];
					};
				};
			};
		};
	};
	
	if (weaponTypes>4 && caliber>4) then
	{
		
		// US very heavy weaponTypes
		
		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["M240", 20];
			_vec AddWeaponCargo ["Mk_48", 20];
			_vec AddWeaponCargo ["ACE_M60", 20];

			_vec addWeaponCargo ["M60A4_EP1", 20];
			_vec addWeaponCargo ["Mk_48_DES_EP1", 20];
			
			if (scopes>0) then
			{
				_vec addWeaponCargo ["m240_scoped_EP1", 20];
				
				if (caliber>5) then
				{
					_vec AddWeaponCargo ["M107", 20];
					
					if (sfweapons>0) then
					{
						_vec AddWeaponCargo ["ACE_AS50", 20];
						_vec AddWeaponCargo ["ACE_TAC50", 20];
					};
				};
				
				if (caliber>6) then
				{
					_vec AddWeaponCargo ["ACE_M109", 20];
				};

			};
			
			if (nightSights>1) then
			{
				_vec addWeaponCargo ["m107_TWS_EP1", 20];
			};
		};
		
		_vec addmagazinecargo ["100Rnd_762x51_M240", 80];

		if (scopes>0 || nightSights>1) then
		{
			_vec addmagazinecargo ["10Rnd_127x99_m107", 80];
		};
		
		if (scopes>0) then
		{
			if (caliber>6) then
			{
				_vec addMagazineCargo ["ACE_5Rnd_25x59_HEDP_Barrett", 80];
			};
			if (caliber>5 && sfweapons>0) then
			{
				_vec addMagazineCargo ["ACE_5Rnd_127x99_B_TAC50", 80];
				_vec addMagazineCargo ["ACE_5Rnd_127x99_S_TAC50", 80];
				_vec addMagazineCargo ["ACE_5Rnd_127x99_T_TAC50", 80];
			};
		};
		
		if (sfweapons>1) then
		{
			if (!_ammoOnly) then
			{

				if (caliber>5) then
				{
					_vec AddWeaponCargo ["ACE_TAC50_SD", 20];
				};
			};
		};
	};


	//_vec AddWeaponCargo ["ACE_Rucksack_MOLLE_Green", 20];
	//_vec AddWeaponCargo ["ACE_Rucksack_MOLLE_Brown", 20];
	//_vec AddWeaponCargo ["ACE_Rucksack_MOLLE_Wood", 20];
	//_vec AddWeaponCargo ["ACE_Rucksack_MOLLE_ACU", 20];
	//_vec AddWeaponCargo ["ACE_Rucksack_MOLLE_WMARPAT", 20];
	//_vec AddWeaponCargo ["ACE_Rucksack_MOLLE_DMARPAT", 20];
	
	if (csw>0) then
	{
		if (!_ammoOnly) then
		{
			_vec addWeaponCargo ["ACE_M2HBProxy", 10];
			_vec addWeaponCargo ["ACE_M3TripodProxy", 10];
		};
		_vec addMagazineCargo ["ACE_M2_CSWDM", 40];
	};
	if (csw>1) then
	{
		if (!_ammoOnly) then
		{
			if (explosives>0) then
			{
				_vec addWeaponCargo ["ACE_MK19MOD3Proxy", 10];
				_vec addWeaponCargo ["ACE_M3TripodProxy", 10];
			};
			if (launchers>2) then
			{
				_vec addWeaponCargo ["ACE_M220Proxy", 10];
				_vec addWeaponCargo ["ACE_M220TripodProxy", 10];
			};
		};
		if (explosives>0) then
		{
			_vec addMagazineCargo ["ACE_MK19_CSWDM", 30];
		};
		if (launchers>2) then
		{
			_vec addMagazineCargo ["ACE_TOW_CSWDM", 30];
		};
	};

};

if (_ammoOnly || _side == EAST || sideweapons>1) then
{

	if (launchers>2) then
	{

		// RU heavy launchers

		if (!_ammoOnly) then
		{
			_vec addWeaponCargo ["STRELA",20];
			_vec addWeaponCargo ["Igla",20];
			_vec addWeaponCargo ["MetisLauncher",20];
			_vec addWeaponCargo ["ACE_RPG29",20];
		};
		if (explosives>4) then
		{
			_vec addMagazineCargo ["ACE_AT13TB",20];
		};
		_vec addMagazineCargo ["STRELA",20];
		_vec addMagazineCargo ["Igla", 20];
		_vec addMagazineCargo ["AT13", 20];

		_vec addMagazineCargo ["ACE_RPG29_PG29", 40];
		
	};
	
	if (launchers>1) then
	{
		
		// RU medium launchers
		
		if (!_ammoOnly) then
		{
			_vec addWeaponCargo ["RPG7V",20];
			_vec addWeaponCargo ["ACE_RPG7V_PGO7",20];
			_vec AddWeaponCargo ["ACE_RPG27", 40];
			if (explosives>4) then
			{
				_vec addWeaponCargo ["ACE_RPOM",20];
				_vec addWeaponCargo ["ACE_RMG",20];
				_vec addWeaponCargo ["ACE_RSHG1",20];
			};
		};
		
		_vec addMagazineCargo ["PG7V",40];
		_vec addMagazineCargo ["PG7VR",40];
		_vec addMagazineCargo ["PG7VL",40];	
	
	};
	
	if (launchers>0) then
	{

		// RU light launchers

		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["RPG18", 40];
			_vec AddWeaponCargo ["ACE_RPG22", 40];
		};

	};

	if (explosives>0) then
	{

		// RU light explosives

		_vec addMagazineCargo ["HandGrenade",80];
		_vec addMagazineCargo ["HandGrenade_East",80];

	};

	if (explosives>4) then
	{

		// RU heavy explosives

		_vec addMagazineCargo ["OG7",60];
		
		_vec addMagazineCargo ["ACE_RPG29_TBG29", 40];
		_vec addMagazineCargo ["ACE_TBG7V", 40];

	};
	
	// RU pistols
	
	if (!_ammoOnly) then
	{
		_vec AddWeaponCargo ["Makarov", 20];
		_vec AddWeaponCargo ["ACE_TT", 20];
		_vec AddWeaponCargo ["ACE_APS", 20]; //test
	};
	_vec addmagazinecargo ["8Rnd_9x18_Makarov", 60];
	_vec addMagazineCargo ["ACE_8Rnd_762x25_B_Tokarev", 60];
	_vec addMagazineCargo ["ACE_20Rnd_9x18_APS", 60]; //test
	
	if (sfweapons>1) then
	{
		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["MakarovSD", 20];
			
			_vec AddWeaponCargo ["ACE_APSB", 20]; //test
		};
		
		_vec addmagazinecargo ["8Rnd_9x18_MakarovSD", 80];
		
		_vec addMagazineCargo ["ACE_20Rnd_9x18_APSB", 80]; //test
	};
	
	if (weaponTypes>0) then
	{
	
		// RU SMGs

		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["Bizon", 20];
			//_vec AddWeaponCargo ["ACE_Scorpion", 20];
			_vec addWeaponCargo ["Sa61_EP1", 20];
		};
		_vec addMagazineCargo ["64Rnd_9x19_Bizon", 80];
		
		//_vec addMagazineCargo ["ACE_20Rnd_765x17_vz61", 80];
		_vec addMagazineCargo ["20Rnd_B_765x17_Ball", 60]; //EP1
		_vec addMagazineCargo ["10Rnd_B_765x17_Ball", 60]; //EP1
		
		if (sfweapons>1) then
		{
			_vec addMagazineCargo ["64Rnd_9x19_SD_Bizon", 80];
			if (!_ammoOnly) then
			{
				_vec AddWeaponCargo ["bizon_silenced", 20];
			};
		};
		
	};
	
	if (weaponTypes>1) then
	{
	
		// RU Shotguns

		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["Saiga12K", 20];
		};
		_vec addMagazineCargo ["8Rnd_B_Saiga12_74Slug", 80];
		
	};

	if (weaponTypes>2 && caliber>2) then
	{

		// RU rifles

		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["AK_107_kobra", 20];
			_vec AddWeaponCargo ["AK_107_GL_kobra", 20];
			_vec AddWeaponCargo ["AK_74", 20];
			_vec AddWeaponCargo ["AK_74_GL", 20];	
			
			_vec addWeaponCargo ["AK_74_GL_kobra", 20]; //EP1
			_vec addWeaponCargo ["AKS_74", 20]; //EP1

			_vec AddWeaponCargo ["AKS_74_U", 20];
			_vec AddWeaponCargo ["AKS_74_kobra", 20];
			
			_vec addWeaponCargo ["ACE_AK105_KOBRA", 20];
			_vec addWeaponCargo ["ACE_AK74M", 20];
			_vec addWeaponCargo ["ACE_AK74M_GL", 20];
			_vec addWeaponCargo ["ACE_AK74M_GL_KOBRA", 20];
			_vec addWeaponCargo ["ACE_AK74M_KOBRA", 20];
			_vec addWeaponCargo ["ACE_AKS74_GP25", 20];
			_vec addWeaponCargo ["ACE_AKS74P", 20];
			_vec addWeaponCargo ["ACE_AKS74P_GL", 20];
			_vec addWeaponCargo ["ACE_AKS74P_GL_KOBRA", 20];
			_vec addWeaponCargo ["ACE_AKS74P_KOBRA", 20];
			
			_vec AddWeaponCargo ["RPK_74", 20];
			
			_vec addWeaponCargo ["ACE_RPK74M", 20];
			
			if (caliber>3) then
			{
				_vec AddWeaponCargo ["ACE_SKS", 20];
				_vec AddWeaponCargo ["AK_47_M", 20];
				
				_vec addWeaponCargo ["ACE_AKM", 20];
				_vec addWeaponCargo ["ACE_AKMS", 20];
				_vec addWeaponCargo ["ACE_AKM_GL", 20];
				
				_vec addWeaponCargo ["ACE_AK103", 20];
				_vec addWeaponCargo ["ACE_AK103_GL", 20];
				_vec addWeaponCargo ["ACE_AK103_GL_KOBRA", 20];
				_vec addWeaponCargo ["ACE_AK103_KOBRA", 20];
				
				_vec addWeaponCargo ["ACE_AK104", 20];
				_vec addWeaponCargo ["ACE_AK104_KOBRA", 20];
				
				_vec addWeaponCargo ["ACE_RPK", 20];
				
				if (sfweapons>0) then
				{
					_vec addWeaponCargo ["ACE_gr1", 20];
				};
				
				if (scopes>0) then
				{
					_vec addWeaponCargo ["ACE_AK103_1P29", 20];
					_vec addWeaponCargo ["ACE_AK103_GL_1P29", 20];
					_vec addWeaponCargo ["ACE_AK103_PSO", 20];
					_vec addWeaponCargo ["ACE_AK103_GL_PSO", 20];
					
					_vec addWeaponCargo ["ACE_AK104_1P29", 20];
					_vec addWeaponCargo ["ACE_AK104_PSO", 20];
				
					if (sfweapons>0) then
					{
						_vec addWeaponCargo ["ACE_gr1sp", 20];
						_vec addWeaponCargo ["ACE_gr1sdsp", 20];
						_vec addWeaponCargo ["ACE_oc14sdsp", 20];
					};
				};
				if (sfweapons>1) then
				{
					_vec addWeaponCargo ["ACE_gr1sd", 20];
					_vec addWeaponCargo ["ACE_AKMS_SD", 20];
				};
			};
			
			if (caliber>4) then
			{
				_vec addWeaponCargo ["ACE_oc14", 20];
				_vec addWeaponCargo ["ACE_oc14gl", 20];
				
				if (scopes>0) then
				{
					_vec AddWeaponCargo ["SVD", 20];
					_vec AddWeaponCargo ["SVD_CAMO", 20];
					_vec addWeaponCargo ["SVD_des_EP1", 20];
					_vec addWeaponCargo ["ACE_SVD_Bipod", 20];
					
					if (nightSights>0) then
					{
						_vec addWeaponCargo ["SVD_NSPU_EP1", 20];
					};
					
					if (sfweapons>0) then
					{
						_vec addWeaponCargo ["ACE_oc14glsp", 20];
						_vec addWeaponCargo ["ACE_oc14sp", 20];
					};
				};
				if (sfweapons>1) then
				{
					_vec addWeaponCargo ["ACE_oc14sd", 20];
				};
			};
			
			if (scopes>0) then
			{
				_vec AddWeaponCargo ["AK_107_GL_pso", 20];
				_vec AddWeaponCargo ["AK_107_pso", 20];
				_vec AddWeaponCargo ["AKS_74_PSO", 20];
				
				_vec addWeaponCargo ["ACE_AK105_PSO", 20];
				_vec addWeaponCargo ["ACE_AK105_1P29", 20];
				
				_vec addWeaponCargo ["ACE_AK74M_PSO", 20];
				_vec addWeaponCargo ["ACE_AK74M_1P29", 20];
				_vec addWeaponCargo ["ACE_AK74M_GL_1P29", 20];
				_vec addWeaponCargo ["ACE_AK74M_GL_PSO", 20];
				_vec addWeaponCargo ["ACE_AKS74P_1P29", 20];
				_vec addWeaponCargo ["ACE_AKS74P_PSO", 20];
				_vec addWeaponCargo ["ACE_AKS74P_GL_PSO", 20];
				_vec addWeaponCargo ["ACE_AKS74P_GL_1P29", 20];
			
				_vec addWeaponCargo ["ACE_RPK74M_1P29", 20];
			};
			
			if (nightSights>0) then
			{
				_vec addWeaponCargo ["AKS_74_NSPU", 20]; //EP1
			};
			if (nightSights>1) then
			{
				_vec addWeaponCargo ["AKS_74_GOSHAWK", 20]; //EP1
			};
		};
		
		if (caliber>3) then
		{
			_vec addMagazineCargo ["ACE_10Rnd_762x39_B_SKS", 80];
			_vec addMagazineCargo ["30Rnd_762x39_AK47",80];
			
			_vec addMagazineCargo ["ACE_40Rnd_762x39_B_AK47", 80];
		};
		
		if (caliber>4) then
		{
			if (scopes>0) then
			{
				_vec addmagazinecargo ["10Rnd_762x54_SVD", 80];
			};
			if (sfweapons>0) then
			{
				_vec addMagazineCargo ["ACE_20Rnd_9x39_B_OC14", 80];
			};
		};

		if (explosives>0) then
		{
			_vec addMagazineCargo ["1Rnd_HE_GP25", 60];
		};
		if (lessThanLethal>0) then
		{
			_vec addMagazineCargo ["ACE_1Rnd_CS_GP25", 50];
		};
		if (sfWeapons>1) then
		{
			_vec addmagazinecargo ["ACE_30Rnd_762x39_SD_AK47", 80];
			if (hiCapMags>1) then
			{
				_vec addmagazinecargo ["ACE_75Rnd_762x39_SD_AK47", 80];
			};
		};
		_vec addmagazinecargo ["30Rnd_545x39_AK", 80];
		_vec addMagazineCargo ["FlareWhite_GP25", 60];
		_vec addMagazineCargo ["FlareGreen_GP25", 40];
		_vec addMagazineCargo ["FlareRed_GP25", 40];
		_vec addMagazineCargo ["FlareYellow_GP25", 40];
		_vec addMagazineCargo ["1Rnd_SMOKE_GP25", 50];
		_vec addMagazineCargo ["1Rnd_SMOKERED_GP25", 35];
		_vec addMagazineCargo ["1Rnd_SMOKEGREEN_GP25", 35];
		_vec addMagazineCargo ["1Rnd_SMOKEYELLOW_GP25", 35];
		
		if (sfweapons>1) then
		{
			if (!_ammoOnly) then
			{
				_vec AddWeaponCargo ["AKS_74_UN_kobra", 20];
				_vec AddWeaponCargo ["ACE_AKS74_UN", 20];
				
				if (caliber>4) then
				{
					if (scopes>0) then
					{
						_vec AddWeaponCargo ["VSS_vintorez", 20];
						_vec addWeaponCargo ["ACE_VAL_PSO", 20];
					};

					_vec addWeaponCargo ["ACE_VAL", 20];
					_vec addWeaponCargo ["ACE_VAL_KOBRA", 20];
				};
			};
			
			_vec addMagazineCargo ["30Rnd_545x39_AKSD", 80];
			if (caliber>4) then
			{
				_vec addMagazineCargo ["20Rnd_9x39_SP5_VSS", 80];
			};
		};
	
	};
	
	if (weaponTypes>2 && sideweapons>0 && caliber>4) then
	{
		// non-RU east weapons
		
		if (!_ammoOnly) then
		{
			_vec addWeaponCargo ["Sa58P_EP1", 20];
			_vec addWeaponCargo ["Sa58V_CCO_EP1", 20];
			_vec addWeaponCargo ["Sa58V_EP1", 20];
			if (scopes>0) then
			{
				_vec addWeaponCargo ["Sa58V_RCO_EP1", 20];
			};
		};
		
		_vec addMagazineCargo ["30Rnd_762x39_SA58", 80]; // may need to be removed
	};

	if (weaponTypes>3) then
	{
		// RU heavy weapons
		
		if (caliber>4) then
		{
			if (hiCapMags>0) then
			{
				_vec addMagazineCargo ["75Rnd_545x39_RPK", 80];
			};
			if (hiCapMags>1) then
			{
				_vec addMagazineCargo ["ACE_75Rnd_762x39_B_AK47", 80];
			};		
		};
	};
	
	if (weaponTypes>4 && caliber>4) then
	{
		// RU very heavy weaponTypes
		
		if (!_ammoOnly) then
		{
			_vec AddWeaponCargo ["PK", 20];
			if (scopes>0) then
			{
				_vec AddWeaponCargo ["Pecheneg", 20];
			};
		};
		_vec addmagazinecargo ["100Rnd_762x54_PK", 80];
		
		if (scopes>0 && caliber>5) then
		{
			if (!_ammoOnly) then
			{
				_vec AddWeaponCargo ["KSVK", 20];
			};
			_vec addmagazinecargo ["5Rnd_127x108_KSVK", 80];
		};
	};
	
	if (csw>0) then
	{
		if (!_ammoOnly) then
		{
			_vec addWeaponCargo ["ACE_KORDProxy", 10];
			_vec addWeaponCargo ["ACE_6T7TripodProxy", 10];
			_vec addWeaponCargo ["ACE_DSHKMTripodProxy", 10];
			_vec addWeaponCargo ["ACE_DSHKMProxy", 10];
		};
		_vec addMagazineCargo ["ACE_DSHKM_CSWDM", 40];
	};
	if (csw>1) then
	{
		if (!_ammoOnly) then
		{
			if (explosives>0) then
			{
				_vec addWeaponCargo ["ACE_AGS30Proxy", 10];
				_vec addWeaponCargo ["ACE_AGS30TripodProxy", 10];
			};
			if (launchers>2) then
			{
				_vec addWeaponCargo ["ACE_KonkursTripodProxy", 10];
			};
		};
		if (explosives>0) then
		{
			_vec addMagazineCargo ["ACE_AGS30_CSWDM", 30];
		};
		if (launchers>2) then
		{
			_vec addMagazineCargo ["ACE_Konkurs_CSWDM", 30];
		};
	};
	
	if (lessThanLethal>0) then
	{
		_vec addMagazineCargo ["ACE_RG60A", 60];
	};
	
	_vec addMagazineCargo ["ACE_RDG2", 50];
	_vec addMagazineCargo ["ACE_RDGM", 50];


	//_vec AddWeaponCargo ["ACE_Rucksack_RD90", 20];
	//_vec AddWeaponCargo ["ACE_Rucksack_RD91", 20];
	//_vec AddWeaponCargo ["ACE_Rucksack_RD92", 20];
	//_vec AddWeaponCargo ["ACE_Rucksack_RD54", 20];
	//_vec AddWeaponCargo ["ACE_Rucksack_RD99", 20];
	//_vec AddWeaponCargo ["ACE_Rucksack_EAST", 20];

};

// revolver
if (sideweapons>1) then
{
	if (!_ammoOnly) then
	{
		_vec addWeaponCargo ["revolver_EP1", 20];
		_vec addWeaponCargo ["revolver_gold_EP1", 20];
	};
	
	_vec addMagazineCargo ["6Rnd_45ACP", 60]; //EP1
};

// global items

if (nightVision>0) then
{
	_vec addWeaponCargo ["NVGoggles",20];
};
if (nightVision>1) then
{
	_vec addWeaponCargo ["ACE_MX2A",20];
};

if (!_ammoOnly) then
{
	_vec AddWeaponCargo ["ACE_Flaregun", 20];
};
_vec addMagazineCargo ["ACE_SSWhite_FG", 60];
_vec addMagazineCargo ["ACE_SSRed_FG", 40];
_vec addMagazineCargo ["ACE_SSGreen_FG", 40];
_vec addMagazineCargo ["ACE_SSYellow_FG", 40];

_vec addWeaponCargo ["Laserdesignator",20];
_vec addMagazineCargo ["Laserbatteries",30];
_vec addWeaponCargo ["Binocular",20];
_vec addWeaponCargo ["Binocular_Vector", 20];
_vec addWeaponCargo ["ACE_Rangefinder_OD",20];
_vec addWeaponCargo ["Binocular_Vector",20];
_vec addWeaponCargo ["ACE_YardAge450", 20];
_vec addMagazineCargo ["ACE_Battery_Rangefinder",30];
_vec addWeaponCargo ["itemGPS",25];
_vec addMagazineCargo ["SmokeShell",50];
_vec addMagazineCargo ["SmokeShellRed",30];
_vec addMagazineCargo ["SmokeShellGreen",30];
_vec addMagazineCargo ["SmokeShellYellow",30];
_vec addMagazineCargo ["SmokeShellOrange",30];
_vec addMagazineCargo ["SmokeShellPurple",30];
_vec addMagazineCargo ["SmokeShellBlue",30];
_vec addWeaponCargo ["ACE_Earplugs",20];
_vec addWeaponCargo ["ACE_GlassesRoundGlasses",20];
_vec addWeaponCargo ["ACE_GlassesSunglasses",20];
_vec addWeaponCargo ["ACE_GlassesTactical",20];
_vec addWeaponCargo ["ACE_GlassesBlackSun",20];
_vec addWeaponCargo ["ACE_GlassesBlueSun",20];
_vec addWeaponCargo ["ACE_GlassesRedSun",20];
_vec addWeaponCargo ["ACE_GlassesGreenSun",20];
_vec addWeaponCargo ["ACE_GlassesLHD_glasses",20];
_vec addWeaponCargo ["ACE_GlassesGasMask_US",20];
_vec addWeaponCargo ["ACE_GlassesGasMask_RU",20];
_vec addWeaponCargo ["ACE_GlassesBalaklava",20];
_vec addWeaponCargo ["ACE_GlassesBalaklavaGray",20];
_vec addWeaponCargo ["ACE_GlassesBalaklavaOlive",20];
_vec addWeaponCargo ["ACE_SpottingScope", 20];
_vec addWeaponCargo ["ACE_WireCutter", 20];
//_vec addWeaponCargo ["ACE_Stretcher", 20];
//_vec addMagazineCargo ["ACE_Rope_M5", 10];

if (explosives>0) then
{
	_vec addMagazineCargo ["ACE_C4_M", 60];
};
if (explosives>1) then
{
	// satchel
	_vec addMagazineCargo ["pipebomb",60];
};
if (explosives>2) then
{
	// mine
	_vec addMagazineCargo ["mine",60];
	_vec addMagazineCargo ["MineE", 60];
};
if (explosives>3) then
{

	// global heavy explosives
	_vec addMagazineCargo ["ACE_M2SLAM_M", 60];
	_vec addMagazineCargo ["ACE_Claymore_M", 60];
	_vec addMagazineCargo ["ACE_BBetty_M", 60];
	_vec addMagazineCargo ["ACE_M34", 60];
	_vec addMagazineCargo ["ACE_M4SLAM_M", 60];
	_vec addMagazineCargo ["ACE_TripFlare_M", 60];
	_vec addMagazineCargo ["ACE_Pomz_M", 60];

};

if (lessThanLethal>0) then
{
	_vec addMagazineCargo ["ACE_M84", 60];
	_vec addMagazineCargo ["ACE_M7A3", 60];
};

if (sfweapons>0) then
{
//	_vec addMagazineCargo ["ACE_Rope_M_50", 10];
//	_vec addMagazineCargo ["ACE_Rope_M_60", 10];
//	_vec addMagazineCargo ["ACE_Rope_M_90", 10];
//	_vec addMagazineCargo ["ACE_Rope_M_120", 10];
};

sleep 300;
};

// _vec addMagazineCargo ["", 80];
// _vec addWeaponCargo ["",20];