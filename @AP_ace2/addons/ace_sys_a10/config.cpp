////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:31:28 2012 : Created on Fri Nov 09 22:31:28 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_a10 : config.bin{
class CfgPatches
{
	class ace_sys_a10
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main","ace_c_vehicle","CAAir","CAAir2","CAAir3","CAAir2_C130J","CAWeapons","CAAir_E_A10"};
		version = "1.14.0.581";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_a10
		{
			list[] = {"ace_sys_a10"};
		};
	};
};
class CfgAmmo
{
	class B_30mmA10_AP;
	class ACE_B_30mmA10_AP: B_30mmA10_AP
	{
		ace_hit = 170;
		hit = 220;
		ace_sys_camshake_coef = 0.1;
	};
};
class CfgMagazines
{
	class 1350Rnd_30mmAP_A10;
	class ACE_1350Rnd_30mmAP_A10: 1350Rnd_30mmAP_A10
	{
		ammo = "ACE_B_30mmA10_AP";
	};
};
class CfgWeapons
{
	class CannonCore;
	class GAU8: CannonCore
	{
		class manual;
	};
	class ACE_GAU8: GAU8
	{
		displayName = "$STR_ACE_WDN_GAU8";
		cursor = "\ca\Weapons\Data\clear_empty";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		magazines[] = {"ACE_1350Rnd_30mmAP_A10"};
		modes[] = {"burst1","burst2","close","short","medium","far"};
		class burst1: manual
		{
			displayName = "LO";
			begin01[] = {"\x\ace\addons\sys_a10\gau81sec2.wss",180,1,5000};
			begin02[] = {"\x\ace\addons\sys_a10\gau81sec2.wss",180,1.015,5000};
			begin03[] = {"\x\ace\addons\sys_a10\gau81sec1.wss",180,1.01,5000};
			begin04[] = {"\x\ace\addons\sys_a10\gau81sec2.wss",180,0.97,5000};
			begin05[] = {"\x\ace\addons\sys_a10\gau81sec1.wss",180,1,5000};
			begin06[] = {"\x\ace\addons\sys_a10\gau81sec2.wss",180,0.985,5000};
			begin07[] = {"\x\ace\addons\sys_a10\gau81sec1.wss",180,1.015,5000};
			begin08[] = {"\x\ace\addons\sys_a10\gau81sec1.wss",180,0.97,5000};
			begin09[] = {"\x\ace\addons\sys_a10\gau81sec1.wss",180,0.985,5000};
			begin10[] = {"\x\ace\addons\sys_a10\gau81sec2.wss",180,1.01,5000};
			soundBegin[] = {"begin01",0.1,"begin02",0.1,"begin03",0.1,"begin04",0.1,"begin05",0.1,"begin06",0.1,"begin07",0.1,"begin08",0.1,"begin09",0.1,"begin10",0.1};
			soundBurst = 1;
			soundContinuous = 0;
			burst = 32;
			multiplier = 2;
			reloadTime = 0.01;
			autoFire = 0;
			useAction = 1;
			useActionTitle = "1Sec Burst";
			showToPlayer = 1;
		};
		class burst2: burst1
		{
			displayName = "HI";
			begin01[] = {"\x\ace\addons\sys_a10\gau82sec2.wss",180,1,5000};
			begin02[] = {"\x\ace\addons\sys_a10\gau82sec2.wss",180,1.015,5000};
			begin03[] = {"\x\ace\addons\sys_a10\gau82sec1.wss",180,1.01,5000};
			begin04[] = {"\x\ace\addons\sys_a10\gau82sec2.wss",180,0.97,5000};
			begin05[] = {"\x\ace\addons\sys_a10\gau82sec1.wss",180,1,5000};
			begin06[] = {"\x\ace\addons\sys_a10\gau82sec2.wss",180,0.985,5000};
			begin07[] = {"\x\ace\addons\sys_a10\gau82sec1.wss",180,1.015,5000};
			begin08[] = {"\x\ace\addons\sys_a10\gau82sec1.wss",180,0.97,5000};
			begin09[] = {"\x\ace\addons\sys_a10\gau82sec1.wss",180,0.985,5000};
			begin10[] = {"\x\ace\addons\sys_a10\gau82sec2.wss",180,1.01,5000};
			burst = 65;
			useAction = 0;
			useActionTitle = "2Sec Burst";
			reloadTime = 0.009;
		};
		class close: burst1
		{
			showToPlayer = 0;
			aiRateOfFire = 0.5;
			aiRateOfFireDistance = 400;
			minRange = 0;
			midRange = 200;
			maxRange = 400;
			minRangeProbab = 0.04;
			midRangeProbab = 0.2;
			maxRangeProbab = 0.1;
		};
		class short: burst2
		{
			showToPlayer = 0;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 600;
			minRange = 200;
			midRange = 500;
			maxRange = 800;
			minRangeProbab = 0.1;
			midRangeProbab = 0.2;
			maxRangeProbab = 0.1;
		};
		class medium: burst2
		{
			showToPlayer = 0;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 600;
			midRange = 800;
			maxRange = 1000;
			minRangeProbab = 0.1;
			midRangeProbab = 0.2;
			maxRangeProbab = 0.1;
		};
		class far: burst1
		{
			showToPlayer = 0;
			aiRateOfFire = 3;
			aiRateOfFireDistance = 1000;
			minRange = 800;
			minRangeProbab = 0.1;
			midRange = 1000;
			midRangeProbab = 0.2;
			maxRange = 1500;
			maxRangeProbab = 0.4;
		};
	};
};
class CfgVehicles
{
	class A10_base;
	class A10_US_EP1: A10_base
	{
		weapons[] = {"ACE_GAU8","MaverickLauncher","SidewinderLaucher_AH1Z","BombLauncherA10","FFARLauncher_14","CMFlareLauncher"};
		magazines[] = {"ACE_1350Rnd_30mmAP_A10","2Rnd_Maverick_A10","2Rnd_Sidewinder_AH1Z","4Rnd_GBU12","14Rnd_FFAR","120Rnd_CMFlare_Chaff_Magazine"};
	};
};
//};
