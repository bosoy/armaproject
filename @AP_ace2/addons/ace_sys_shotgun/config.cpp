////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:07:27 2013 : Created on Sat Jun 08 13:07:27 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_shotgun : config.bin{
class CfgPatches
{
	class ace_sys_shotgun
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon","ace_sys_cartridges"};
		version = "1.14.0.593";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_shotgun
	{
		init = "call ('\x\ace\addons\sys_shotgun\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgAmmo
{
	class BulletBase;
	class B_12Gauge_74Slug: BulletBase
	{
		airfriction = -0.0037;
	};
	class ACE_Pellet_Buck_00: BulletBase
	{
		hit = 6;
		typicalSpeed = 390;
		airfriction = -0.0065;
		deflecting = 10;
		ace_disp = 16;
		ace_pelletcount = 9;
		cartridge = "FxCartridge_Shotgun";
		visibleFire = 18;
		audibleFire = 18;
		visibleFireTime = 3;
	};
	class ACE_Pellet_Buck_4_40mm: ACE_Pellet_Buck_00
	{
		hit = 6;
		typicalSpeed = 269;
		airfriction = -0.0075;
		deflecting = 10;
		ace_disp = 25;
		ace_pelletcount = 20;
		cartridge = "";
		visibleFire = 18;
		audibleFire = 18;
		visibleFireTime = 3;
		ACE_Simulation = "shotSpread";
	};
	class ACE_Slug_12_1: BulletBase
	{
		hit = 12;
		typicalSpeed = 438;
		airfriction = -0.0037;
		deflecting = 10;
		ace_disp = 6;
		ace_pelletcount = 1;
		cartridge = "FxCartridge_Shotgun";
		visibleFire = 18;
		audibleFire = 18;
		visibleFireTime = 3;
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class 8Rnd_B_Beneli_74Slug: CA_Magazine
	{
		displayname = "$STR_DN_ACE_8RND_12GA_SLUG";
		displayNameShort = "$STR_DNS_ACE_SLUG";
		picture = "\x\ace\addons\sys_shotgun\data\equip\m_slug_ca.paa";
		descriptionShort = "$STR_DSS_ACE_SHITGUN_8RND";
		ACE_weight = 0.4;
		ACE_Size = 600;
	};
	class 8Rnd_B_Beneli_Pellets: CA_Magazine
	{
		displayname = "$STR_DN_ACE_8RND_12GA_BUCK00";
		displayNameShort = "$STR_DNS_ACE_PELLETS";
		picture = "\x\ace\addons\sys_shotgun\data\equip\m_buckshot_ca.paa";
		ACE_weight = 0.4;
		ACE_Size = 600;
	};
	class 8Rnd_B_Saiga12_Pellets: CA_Magazine
	{
		displayname = "$STR_DN_ACE_8RND_12GA_BUCK00";
		displayNameShort = "$STR_DNS_ACE_PELLETS";
	};
	class ACE_8Rnd_12Ga_Buck00_Saiga12: 8Rnd_B_Saiga12_Pellets
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
	};
	class 1Rnd_HE_M203;
	class ACE_M576: 1Rnd_HE_M203
	{
		scope = 2;
		displayName = "M576";
		displayNameShort = "$STR_DNS_ACE_PELLETS";
		picture = "\x\ace\addons\sys_shotgun\data\equip\m_M576_ca.paa";
		ammo = "ACE_Pellet_Buck_4_40mm";
		initspeed = 269;
		class Library
		{
			libTextDesc = "";
		};
		ACE_Weight = 0.12;
		descriptionShort = "$STR_DSS_ACE_40mm_Buck_M79";
	};
	class ACE_40mm_Buck_M79: ACE_M576
	{
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_8Rnd_12Ga_Slug: 8Rnd_B_Beneli_74Slug
	{
		class Library
		{
			libTextDesc = "";
		};
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_8Rnd_12Ga_Buck00: 8Rnd_B_Beneli_Pellets
	{
		class Library
		{
			libTextDesc = "";
		};
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_9Rnd_12Ga_Slug: ACE_8Rnd_12Ga_Slug
	{
		displayname = "$STR_DN_ACE_9RND_12GA_SLUG";
		count = 9;
		descriptionShort = "$STR_DSS_ACE_SHITGUN_9RND";
		ACE_Weight = 0.45;
		ACE_Size = 675;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_9Rnd_12Ga_Buck00: ACE_8Rnd_12Ga_Buck00
	{
		displayname = "$STR_DN_ACE_9RND_12GA_BUCK00";
		count = 9;
		descriptionShort = "$STR_DSS_ACE_SHITGUN_9RND";
		ACE_Weight = 0.45;
		ACE_Size = 675;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_6Rnd_12Ga_Slug: ACE_8Rnd_12Ga_Slug
	{
		displayname = "$STR_DN_ACE_6RND_12GA_SLUG";
		count = 6;
		descriptionShort = "$STR_DSS_ACE_SHITGUN_6RND";
		ACE_Weight = 0.3;
		ACE_Size = 450;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_6Rnd_12Ga_Buck00: ACE_8Rnd_12Ga_Buck00
	{
		displayname = "$STR_DN_ACE_6RND_12GA_BUCK00";
		count = 6;
		descriptionShort = "$STR_DSS_ACE_SHITGUN_6RND";
		ACE_Weight = 0.3;
		ACE_Size = 450;
		class Armory
		{
			disabled = 1;
		};
	};
};
class CfgWeapons
{
	class Rifle;
	class Saiga12K: Rifle
	{
		magazines[] = {"8Rnd_B_Saiga12_74Slug","8Rnd_B_Saiga12_Pellets","ACE_8Rnd_12Ga_Buck00_Saiga12"};
	};
	class M1014: Rifle
	{
		magazines[] = {"8Rnd_B_Beneli_74Slug","8Rnd_B_Beneli_Pellets","ACE_8Rnd_12Ga_Slug","ACE_8Rnd_12Ga_Buck00"};
	};
	class GrenadeLauncher_EP1;
	class M79_EP1: GrenadeLauncher_EP1
	{
		ace_shotgun = 1;
	};
};
//};
