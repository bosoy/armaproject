////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:07:21 2013 : Created on Mon Oct 14 23:07:21 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_goggles : config.bin{
class CfgPatches
{
	class ace_sys_goggles
	{
		units[] = {};
		weapons[] = {"ACE_Earplugs","ACE_GlassesSpectacles","ACE_GlassesRoundGlasses","ACE_GlassesSunglasses","ACE_GlassesTactical","ACE_GlassesBlackSun","ACE_GlassesBlueSun","ACE_GlassesRedSun","ACE_GlassesGreenSun","ACE_GlassesLHD_glasses","ACE_GlassesGasMask_US","ACE_GlassesGasMask2_US","ACE_GlassesGasMask_S10","ACE_GlassesGasMask_RU","ACE_GlassesBalaklava","ACE_GlassesBalaklava_Skull","ACE_GlassesBalaklava_Pink","ACE_GlassesBalaklavaOlive","ACE_GlassesBalaklavaGray","ACE_GlassesDelta_glasses"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CBA_MAIN","CACharacters_E_Head","ace_main","ace_settings","ace_c_weapon","ace_sys_interaction","ace_sys_combatdeaf","Extended_EventHandlers"};
		version = "1.14.0.597";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_goggles
		{
			list[] = {"ace_sys_goggles"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_goggles
	{
		init = "call ('\x\ace\addons\sys_goggles\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_goggles
	{
		clientInit = "call ('\x\ace\addons\sys_goggles\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Killed_EventHandlers
{
	class CAManBase
	{
		class ace_sys_goggles
		{
			killedPlayer = "_this call ace_sys_goggles_fnc_killed";
		};
	};
};
class CfgWeapons
{
	class ACE_Item;
	class ACE_Earplugs: ACE_Item
	{
		scope = 2;
		displayName = "$STR_ACE_EARPLUGS";
		descriptionShort = "";
		model = "\x\ace\addons\sys_goggles\earplug.p3d";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_earplug_ca.paa";
		ACE_Weight = 0.02;
		ACE_Size = 1;
		ACE_IsGoggle = 1;
	};
	class ACE_GlassesSpectacles: ACE_Item
	{
		scope = 1;
		displayName = "$STR_CFG_GLASSES_SPECTACLES";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_generic_ca.paa";
		descriptionShort = "";
		model = "\Ca\characters\glasses\Spectacles";
		ACE_Weight = 0.05;
		ACE_Size = 1;
		ACE_IsGoggle = 1;
	};
	class ACE_GlassesRoundGlasses: ACE_GlassesSpectacles
	{
		scope = 1;
		displayName = "$STR_CFG_GLASSES_READING";
		descriptionShort = "";
		model = "\Ca\characters\glasses\RoundGlasses";
		ACE_Weight = 0.05;
		ACE_Size = 1;
	};
	class ACE_GlassesSunglasses: ACE_GlassesSpectacles
	{
		scope = 2;
		displayName = "$STR_CFG_GLASSES_AVIATOR_SUNGLASSES";
		descriptionShort = "";
		model = "\Ca\characters\glasses\sunGlasses";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_sunglasses_ca.paa";
		ACE_Weight = 0.05;
		ACE_Size = 1;
	};
	class ACE_GlassesTactical: ACE_GlassesSpectacles
	{
		scope = 2;
		displayName = "$STR_CFG_GLASSES_TACTICAL";
		descriptionShort = "";
		model = "\Ca\characters\glasses\TacticalGlasses";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_kampfbrille_ca.paa";
		ACE_Weight = 0.05;
		ACE_Size = 1.2;
	};
	class ACE_GlassesBlackSun: ACE_GlassesSpectacles
	{
		scope = 2;
		displayName = "$STR_CFG_GLASSES_SHADES_BLACK";
		descriptionShort = "";
		model = "\Ca\characters\glasses\BlackSun";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_sunglasses_ca.paa";
		ACE_Weight = 0.05;
		ACE_Size = 1;
	};
	class ACE_GlassesBlueSun: ACE_GlassesSpectacles
	{
		scope = 2;
		displayName = "$STR_CFG_GLASSES_SHADES_BLUE";
		descriptionShort = "";
		model = "\Ca\characters\glasses\BlueSun";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_sunglasses_ca.paa";
		ACE_Weight = 0.05;
		ACE_Size = 1;
	};
	class ACE_GlassesRedSun: ACE_GlassesSpectacles
	{
		scope = 2;
		displayName = "$STR_CFG_GLASSES_SHADES_RED";
		descriptionShort = "";
		model = "\Ca\characters\glasses\RedSun";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_sunglasses_ca.paa";
		ACE_Weight = 0.05;
		ACE_Size = 1;
	};
	class ACE_GlassesGreenSun: ACE_GlassesSpectacles
	{
		scope = 2;
		displayName = "$STR_CFG_GLASSES_SHADES_YELLOW";
		descriptionShort = "";
		model = "\Ca\characters\glasses\GreenSun";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_sunglasses_ca.paa";
		ACE_Weight = 0.05;
		ACE_Size = 1;
	};
	class ACE_GlassesLHD_glasses: ACE_GlassesSpectacles
	{
		scope = 2;
		displayName = "$STR_CFG_GLASSES_LHD";
		descriptionShort = "";
		model = "\ca\characters_e\Heads\Glasses\Delta1G.p3d";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_schutzbrille_ca.paa";
		ACE_Weight = 0.1;
		ACE_Size = 1.2;
	};
	class ACE_GlassesGasMask_US: ACE_GlassesSpectacles
	{
		scope = 2;
		displayName = "$STR_ACE_GASMASK";
		model = "\x\ace\addons\sys_goggles\g_gasmask.p3d";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_gasmask_ca.paa";
		ACE_Weight = 0.8;
		ACE_Size = 1000;
	};
	class ACE_GlassesGasMask2_US: ACE_GlassesGasMask_US
	{
		scope = 2;
		displayName = "M15 Gas Mask";
		model = "\x\ace\addons\sys_goggles\g_gasmask2.p3d";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_gasmask_ca.paa";
		ACE_Weight = 0.8;
		ACE_Size = 1000;
	};
	class ACE_GlassesGasMask_S10: ACE_GlassesGasMask2_US
	{
		displayName = "S10";
		model = "\x\ace\addons\sys_goggles\g_gasmask_S10.p3d";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_gasmask_ca.paa";
		ACE_Weight = 0.8;
		ACE_Size = 1000;
	};
	class ACE_GlassesGasMask_RU: ACE_GlassesGasMask_US
	{
		scope = 2;
		displayName = "GP-5 Gas Mask";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_gasmask_ca.paa";
		ACE_Weight = 0.8;
		ACE_Size = 1000;
	};
	class ACE_GlassesBalaklava: ACE_GlassesSpectacles
	{
		scope = 2;
		displayName = "$STR_ACE_BALAKLAVA";
		model = "\x\ace\addons\sys_goggles\g_balaklava.p3d";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_sturmhaube_ca.paa";
		ACE_Weight = 0.05;
		ACE_Size = 10;
	};
	class ACE_GlassesBalaklava_Skull: ACE_GlassesBalaklava
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_GlassesBalaklava_Pink: ACE_GlassesBalaklava
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_GlassesBalaklavaOlive: ACE_GlassesBalaklava
	{
		displayName = "$STR_ACE_BALAKLAVAOLIVE";
		model = "\x\ace\addons\sys_goggles\g_balaklava_olive.p3d";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_sturmhaube_oliv_ca.paa";
	};
	class ACE_GlassesBalaklavaGray: ACE_GlassesBalaklava
	{
		displayName = "$STR_ACE_BALAKLAVAGRAY";
		model = "\x\ace\addons\sys_goggles\g_balaklava_gray.p3d";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_sturmhaube_grau_ca.paa";
	};
	class ACE_GlassesSpecial: ACE_GlassesSpectacles
	{
		scope = 1;
	};
	class ACE_GlassesMFS: ACE_GlassesSpectacles
	{
		scope = 2;
		displayName = "MFS";
		descriptionShort = "";
		model = "\Ca\characters\glasses\TacticalGlasses";
		picture = "\x\ace\addons\sys_goggles\data\equip\g_mfs_ca.paa";
		ACE_Weight = 0.05;
		ACE_Size = 1.2;
		ACE_IsGoggle = 1;
	};
};
class CfgGlasses
{
	class None;
	class ACE_None: None
	{
		identityTypes[] = {};
	};
	class ACE_GasMask_US: ACE_None
	{
		scope = 1;
		name = "$STR_ACE_GASMASK";
		model = "\x\ace\addons\sys_goggles\g_gasmask.p3d";
	};
	class ACE_GasMask_RU: ACE_GasMask_US
	{
		displayName = "GP-5 Gas Mask";
	};
	class ACE_GasMask2_US: ACE_GasMask_US
	{
		displayName = "M15 Gas Mask";
		model = "\x\ace\addons\sys_goggles\g_gasmask2.p3d";
	};
	class ACE_GasMask_S10: ACE_GasMask_US
	{
		displayName = "S10 Gas Mask";
		model = "\x\ace\addons\sys_goggles\g_gasmask_s10.p3d";
	};
	class ACE_Balaklava: ACE_None
	{
		scope = 1;
		name = "$STR_ACE_BALAKLAVA";
		model = "\x\ace\addons\sys_goggles\g_balaklava.p3d";
	};
	class ACE_BalaklavaGray: ACE_Balaklava
	{
		name = "$STR_ACE_BALAKLAVAGRAY";
		model = "\x\ace\addons\sys_goggles\g_balaklava_gray.p3d";
	};
	class ACE_BalaklavaOlive: ACE_Balaklava
	{
		scope = 1;
		name = "$STR_ACE_BALAKLAVAOLIVE";
		model = "\x\ace\addons\sys_goggles\g_balaklava_olive.p3d";
	};
	class ACE_Balaklava_Skull: ACE_Balaklava
	{
		model = "\x\ace\addons\sys_goggles\g_balaklava_skull.p3d";
	};
	class ACE_Balaklava_Pink: ACE_Balaklava
	{
		model = "\x\ace\addons\sys_goggles\g_balaklava_gay.p3d";
	};
	class ACE_Balaklava_Skull_Day: ACE_Balaklava
	{
		model = "\x\ace\addons\sys_goggles\g_balaklava_skull_day.p3d";
	};
	class ACE_Haha: ACE_None
	{
		scope = 1;
		name = "";
		model = "\x\ace\addons\sys_goggles\g_haha.p3d";
	};
	class ACE_Visor: ACE_None
	{
		scope = 1;
		name = "Visor";
		model = "\x\ace\addons\sys_goggles\g_visor.p3d";
	};
	class ACE_MFS: ACE_None
	{
		scope = 1;
		name = "MFS";
		model = "\x\ace\addons\sys_goggles\g_mfs_visor.p3d";
	};
	class ACE_MFSVisor: ACE_MFS
	{
		model = "\x\ace\addons\sys_goggles\g_mfs_visor.p3d";
	};
	class ACE_MFS_R: ACE_MFS
	{
		model = "\x\ace\addons\sys_goggles\g_mfs_r_visor.p3d";
	};
	class ACE_MFS_RVisor: ACE_MFS_R
	{
		model = "\x\ace\addons\sys_goggles\g_mfs_r_visor.p3d";
	};
};
class RscTitles
{
	class ACE_Gasmask_US
	{
		idd = -1;
		duration = 9999999;
		fadeIn = "false";
		fadeOut = "false";
		name = "ACE_Gasmask";
		onLoad = "with uiNameSpace do { ACE_Gasmask = _this select 0 };";
		onUnload = "with uiNameSpace do { ACE_Gasmask = displayNull };";
		class controls
		{
			class ACE_Mask
			{
				idc = -1;
				type = 0;
				font = "BitStream";
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				text = "\x\ace\addons\sys_goggles\data\rsc\ACE_GasmaskUS_Rsc_ca.paa";
				style = 48;
				sizeEx = 1;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs";
				h = "SafeZoneH";
			};
		};
	};
	class ACE_Gasmask_RU: ACE_Gasmask_US{};
	class ACE_GlassesTactical: ACE_Gasmask_US
	{
		name = "";
		onLoad = "";
		onUnload = "";
		class controls: controls
		{
			class ACE_Tactical: ACE_Mask
			{
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_goggles\data\rsc\ACE_GlassesTactical_Rsc_ca.paa";
			};
		};
	};
	class ACE_GlassesLHD_glasses: ACE_GlassesTactical
	{
		name = "";
		onLoad = "";
		onUnload = "";
		class controls: controls
		{
			class ACE_Tactical: ACE_Mask
			{
				text = "\x\ace\addons\sys_goggles\data\rsc\ACE_GlassesLHD_glasses_Rsc_ca.paa";
			};
		};
	};
	class ACE_GlassesSunglasses: ACE_GlassesTactical
	{
		name = "";
		onLoad = "";
		onUnload = "";
		class controls: controls
		{
			class ACE_Tactical: ACE_Mask
			{
				text = "\x\ace\addons\sys_goggles\data\rsc\ACE_GlassesSunglasses_Rsc_ca.paa";
			};
		};
	};
	class ACE_GlassesHaha: ACE_GlassesTactical
	{
		name = "";
		onLoad = "";
		onUnload = "";
		class controls: controls
		{
			class ACE_Tactical: ACE_Mask
			{
				text = "\x\ace\addons\sys_goggles\data\rsc\ACE_GlassesHaha_Rsc_ca.paa";
			};
		};
	};
	class ACE_GlassesMFS: ACE_GlassesTactical
	{
		name = "";
		onLoad = "";
		onUnload = "";
		class controls: controls
		{
			class ACE_Tactical: ACE_Mask
			{
				text = "\x\ace\addons\sys_goggles\data\rsc\ACE_GlassesMFS_Rsc_ca.paa";
			};
		};
	};
};
class CfgSounds
{
	class ACE_Dull1
	{
		name = "ACE_Dull1";
		sound[] = {"\x\ace\addons\sys_goggles\sound\us_deaf_alt1.ogg","db+8",1};
		titles[] = {};
	};
	class ACE_Dull2: ACE_Dull1
	{
		name = "ACE_Dull2";
		sound[] = {"\x\ace\addons\sys_goggles\sound\us_deaf_alt2.ogg","db+8",1};
	};
	class ACE_Dull3: ACE_Dull1
	{
		name = "ACE_Dull3";
		sound[] = {"\x\ace\addons\sys_goggles\sound\us_deaf_alt2.ogg","db+8",1};
	};
};
//};
