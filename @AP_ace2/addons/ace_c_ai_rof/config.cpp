////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Aug 24 17:37:44 2012 : Created on Fri Aug 24 17:37:44 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_ai_rof : config.bin{
class CfgPatches
{
	class ace_c_ai_rof
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ACE_MAIN","CAWeapons","CAWeapons_AK","CAweapons_ksvk","CAweapons_m107","CAWeapons_BAF","CAWeapons_E","CAWeapons_E_AK","CAWeapons_E_fnfal","CAWeapons_E_LeeEnfield","CAWeapons_E_M110","CAWeapons_E_M14","CAWeapons_E_M240","CAWeapons_E_scar","CAWeapons_PMC","CAWeapons_PMC_AA_12","CAWeapons_PMC_XM8","CAWeapons2","CACharacters2","CACharacters_E","CACharacters_BAF"};
		version = "1.13.0.568";
	};
};
class Mode_SemiAuto
{
	aiRateOfFire = 1;
	aiRateOfFireDistance = 550;
	minRange = 0;
	minRangeProbab = 0.7;
	midRange = 200;
	midRangeProbab = 0.5;
	maxRange = 500;
	maxRangeProbab = 0.1;
};
class Mode_Burst: Mode_SemiAuto
{
	aiRateOfFire = 1;
	aiRateOfFireDistance = 200;
	minRange = 0;
	minRangeProbab = 0.8;
	midRange = 150;
	midRangeProbab = 0.7;
	maxRange = 250;
	maxRangeProbab = 0.1;
};
class Mode_FullAuto: Mode_SemiAuto
{
	aiRateOfFire = 0.1;
	aiRateOfFireDistance = 50;
	minRange = 0;
	minRangeProbab = 0.9;
	midRange = 60;
	midRangeProbab = 0.7;
	maxRange = 120;
	maxRangeProbab = 0.1;
};
class CfgWeapons
{
	class Default
	{
		aiRateOfFire = 1;
		aiRateOfFireDistance = 550;
		minRange = 0;
		minRangeProbab = 0.7;
		midRange = 200;
		midRangeProbab = 0.5;
		maxRange = 500;
		maxRangeProbab = 0.1;
	};
	class MGunCore: Default
	{
		aiRateOfFire = 0.2;
		aiRateOfFireDistance = 600;
	};
	class MGun: MGunCore{};
	class M134: MGun
	{
		class LowROF: Mode_FullAuto{};
		class HighROF: LowROF{};
		class close: HighROF
		{
			aiRateOfFire = 0.1;
		};
		class short: close
		{
			aiRateOfFire = 0.2;
		};
		class medium: LowROF
		{
			aiRateOfFire = 0.4;
		};
		class far: medium
		{
			aiRateOfFire = 1;
		};
	};
	class GrenadeLauncher: Default{};
	class PistolCore: Default
	{
		aiRateOfFire = 0.6;
		aiRateOfFireDistance = 50;
		minRange = 0;
		minRangeProbab = 0.5;
		midRange = 20;
		midRangeProbab = 0.3;
		maxRange = 80;
		maxRangeProbab = 0.01;
	};
	class RifleCore: Default
	{
		aiRateOfFire = 1;
		aiRateOfFireDistance = 550;
		minRange = 0;
		minRangeProbab = 0.7;
		midRange = 200;
		midRangeProbab = 0.5;
		maxRange = 500;
		maxRangeProbab = 0.1;
	};
	class Pistol: PistolCore
	{
		aiRateOfFire = 0.6;
		aiRateOfFireDistance = 50;
		minRange = 0;
		minRangeProbab = 0.5;
		midRange = 20;
		midRangeProbab = 0.3;
		maxRange = 80;
		maxRangeProbab = 0.01;
	};
	class M9: Pistol
	{
		aiRateOfFire = 0.6;
		aiRateOfFireDistance = 50;
		minRange = 0;
		minRangeProbab = 0.5;
		midRange = 20;
		midRangeProbab = 0.3;
		maxRange = 80;
		maxRangeProbab = 0.01;
	};
	class M9SD: M9
	{
		aiRateOfFire = 0.6;
		aiRateOfFireDistance = 50;
		minRange = 0;
		minRangeProbab = 0.5;
		midRange = 20;
		midRangeProbab = 0.3;
		maxRange = 80;
		maxRangeProbab = 0.01;
	};
	class Makarov: Pistol
	{
		aiRateOfFire = 0.6;
		aiRateOfFireDistance = 50;
		minRange = 0;
		minRangeProbab = 0.5;
		midRange = 20;
		midRangeProbab = 0.3;
		maxRange = 80;
		maxRangeProbab = 0.01;
	};
	class MakarovSD: Makarov
	{
		aiRateOfFire = 0.6;
		aiRateOfFireDistance = 50;
		minRange = 0;
		minRangeProbab = 0.5;
		midRange = 20;
		midRangeProbab = 0.3;
		maxRange = 80;
		maxRangeProbab = 0.01;
	};
	class Rifle: RifleCore
	{
		class M203Muzzle: GrenadeLauncher
		{
			minRangeProbab = 0;
			midRangeProbab = 0;
			maxRangeProbab = 0;
		};
		class ACE_M203Muzzle_AI: M203Muzzle
		{
			minRange = 50;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.9;
			maxRange = 400;
			maxRangeProbab = 0.05;
			cameraDir = "";
			memoryPointCamera = "";
			showtoplayer = 0;
		};
	};
	class M16_base: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class M203Muzzle: M203Muzzle
		{
			minRangeProbab = 0;
			midRangeProbab = 0;
			maxRangeProbab = 0;
		};
		class ACE_M203Muzzle_AI: M203Muzzle
		{
			minRange = 50;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.9;
			maxRange = 400;
			maxRangeProbab = 0.05;
			cameraDir = "";
			memoryPointCamera = "";
			showtoplayer = 0;
		};
	};
	class M16A2: M16_base{};
	class M16A2GL: M16A2
	{
		muzzles[] = {"this","M203Muzzle","ACE_M203Muzzle_AI"};
	};
	class m16a4: M16A2
	{
		class Single;
		class Burst;
	};
	class m16a4_acg: m16a4
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
	};
	class M16A4_GL: m16a4
	{
		muzzles[] = {"this","M203Muzzle","ACE_M203Muzzle_AI"};
		class Single;
		class Burst;
	};
	class M16A4_ACG_GL: M16A4_GL
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
	};
	class M24: Rifle
	{
		aiRateOfFire = 6;
		aiRateOfFireDistance = 1100;
		minRange = 0;
		minRangeProbab = 0.4;
		midRange = 500;
		midRangeProbab = 0.8;
		maxRange = 1100;
		maxRangeProbab = 0.1;
	};
	class M240: Rifle
	{
		modes[] = {"manual","close","short","medium","ACE_long"};
		class manual: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = "30+ random 20";
			maxRangeProbab = 0.1;
		};
		class close: manual
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class short: close
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "300+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: close
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class far: close
		{
			burst = "2+round random 4";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 300;
			minRangeProbab = 0.8;
			midRange = "500+ random 50";
			midRangeProbab = 0.7;
			maxRange = "600+ random 50";
			maxRangeProbab = 0.1;
		};
		class ACE_long: far
		{
			burst = "8+round random 6";
			aiRateOfFire = 4;
			aiRateOfFireDistance = 1000;
			minRange = 400;
			minRangeProbab = 0.8;
			midRange = "700+ random 50";
			midRangeProbab = 0.2;
			maxRange = 800;
			maxRangeProbab = 0.1;
		};
	};
	class Mk_48: M240
	{
		class far: far{};
		class ACE_long: far
		{
			burst = "8+round random 6";
			aiRateOfFire = 4;
			aiRateOfFireDistance = 1000;
			minRange = 400;
			minRangeProbab = 0.8;
			midRange = "700+ random 50";
			midRangeProbab = 0.2;
			maxRange = 800;
			maxRangeProbab = 0.1;
		};
	};
	class M249: Rifle
	{
		modes[] = {"manual","close","short","medium","ACE_long"};
		class manual: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = "30+ random 20";
			maxRangeProbab = 0.1;
		};
		class close: manual
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class short: close
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "300+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: close
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class far: close
		{
			burst = "2+round random 4";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 300;
			minRangeProbab = 0.8;
			midRange = "500+ random 50";
			midRangeProbab = 0.7;
			maxRange = "600+ random 50";
			maxRangeProbab = 0.1;
		};
		class ACE_long: far
		{
			burst = "8+round random 6";
			aiRateOfFire = 4;
			aiRateOfFireDistance = 1000;
			minRange = 400;
			minRangeProbab = 0.8;
			midRange = "700+ random 50";
			midRangeProbab = 0.2;
			maxRange = 800;
			maxRangeProbab = 0.1;
		};
	};
	class M4A1: M16_base
	{
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
	};
	class M4A1_Aim: M4A1{};
	class M4A1_AIM_SD_camo: M4A1_Aim
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
		class Burst: FullAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			soundBurst = 0;
			showtoplayer = 0;
			burst = "2 + round random 4";
		};
	};
	class M4A1_HWS_GL_SD_Camo: M4A1_AIM_SD_camo
	{
		muzzles[] = {"this","M203Muzzle","ACE_M203Muzzle_AI"};
		class Single: Single{};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
	};
	class M4SPR: M4A1
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
	};
	class M4A1_RCO_GL: M4A1
	{
		muzzles[] = {"M4_ACOG_Muzzle","M203Muzzle","ACE_M203Muzzle_AI"};
		class M4_ACOG_Muzzle: M4A1
		{
			class Single: Single
			{
				aiRateOfFire = 2;
				aiRateOfFireDistance = 800;
				minRange = 0;
				minRangeProbab = 0.7;
				midRange = 200;
				midRangeProbab = 0.6;
				maxRange = 650;
				maxRangeProbab = 0.1;
			};
			class ACE_Burst: Single
			{
				aiRateOfFire = 1;
				aiRateOfFireDistance = 200;
				minRange = 0;
				minRangeProbab = 0.8;
				midRange = 150;
				midRangeProbab = 0.7;
				maxRange = 250;
				maxRangeProbab = 0.1;
				displayName = "$STR_DN_MODE_BURST";
				burst = 3;
				soundBurst = 0;
			};
			class ACE_Burst_AI: ACE_Burst
			{
				burst = "3 + round random 5";
				showtoplayer = 0;
			};
			class ACE_Burst_AI2: ACE_Burst_AI
			{
				burst = "3 + round random 5";
			};
			modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
		};
		class Single: Single{};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
	};
	class M4A1_HWS_GL: M4A1_RCO_GL
	{
		muzzles[] = {"this","M203Muzzle","ACE_M203Muzzle_AI"};
	};
	class PK: Rifle
	{
		modes[] = {"manual","close","short","medium","ACE_long"};
		class manual: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = "30+ random 20";
			maxRangeProbab = 0.1;
		};
		class close: manual
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class short: close
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "300+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: close
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class far: close
		{
			burst = "2+round random 4";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 300;
			minRangeProbab = 0.8;
			midRange = "500+ random 50";
			midRangeProbab = 0.7;
			maxRange = "600+ random 50";
			maxRangeProbab = 0.1;
		};
		class ACE_long: far
		{
			burst = "8+round random 6";
			aiRateOfFire = 4;
			aiRateOfFireDistance = 1000;
			minRange = 400;
			minRangeProbab = 0.8;
			midRange = "700+ random 50";
			midRangeProbab = 0.2;
			maxRange = 800;
			maxRangeProbab = 0.1;
		};
	};
	class Pecheneg: PK
	{
		modes[] = {"manual","close","short","medium","far","ACE_long"};
		class manual: manual
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = "30+ random 20";
			maxRangeProbab = 0.1;
		};
		class close: close
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class short: short
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "300+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: medium
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class far: far
		{
			burst = "2+round random 4";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 300;
			minRangeProbab = 0.8;
			midRange = "500+ random 50";
			midRangeProbab = 0.7;
			maxRange = "600+ random 50";
			maxRangeProbab = 0.1;
		};
		class ACE_long: far
		{
			burst = "8+round random 6";
			aiRateOfFire = 4;
			aiRateOfFireDistance = 1000;
			minRange = 400;
			minRangeProbab = 0.8;
			midRange = "700+ random 50";
			midRangeProbab = 0.2;
			maxRange = 800;
			maxRangeProbab = 0.1;
		};
	};
	class SVD: Rifle
	{
		aiRateOfFire = 3;
		aiRateOfFireDistance = 700;
		minRange = 0;
		minRangeProbab = 0.7;
		midRange = 300;
		midRangeProbab = 0.6;
		maxRange = 700;
		maxRangeProbab = 0.1;
	};
	class G36C: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 200;
			maxRangeProbab = 0.1;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
	};
	class G36_C_SD_eotech: G36C
	{
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
	};
	class G36a: Rifle
	{
		class MuzzleFar: G36C
		{
			modes[] = {"Single","Burst","Fullauto"};
			class Single: Mode_SemiAuto
			{
				aiRateOfFire = 2;
				aiRateOfFireDistance = 800;
				minRange = 0;
				minRangeProbab = 0.7;
				midRange = 200;
				midRangeProbab = 0.6;
				maxRange = 650;
				maxRangeProbab = 0.1;
			};
			class Burst: Mode_Burst
			{
				aiRateOfFire = 1;
				aiRateOfFireDistance = 200;
				minRange = 0;
				minRangeProbab = 0.8;
				midRange = 150;
				midRangeProbab = 0.7;
				maxRange = 250;
				maxRangeProbab = 0.1;
				burst = "3 + round random 5";
				showtoplayer = 0;
			};
			class FullAuto: Mode_FullAuto
			{
				aiRateOfFire = 0.1;
				aiRateOfFireDistance = 50;
				minRange = 0;
				minRangeProbab = 0.9;
				midRange = 60;
				midRangeProbab = 0.7;
				maxRange = 120;
				maxRangeProbab = 0.1;
			};
		};
	};
	class G36K: G36a
	{
		class MuzzleFar: MuzzleFar
		{
			class Single: Single
			{
				aiRateOfFire = 2;
				aiRateOfFireDistance = 800;
				minRange = 0;
				minRangeProbab = 0.7;
				midRange = 200;
				midRangeProbab = 0.6;
				maxRange = 650;
				maxRangeProbab = 0.1;
			};
			class Burst: Burst
			{
				aiRateOfFire = 1;
				aiRateOfFireDistance = 200;
				minRange = 0;
				minRangeProbab = 0.8;
				midRange = 150;
				midRangeProbab = 0.7;
				maxRange = 250;
				maxRangeProbab = 0.1;
			};
			class FullAuto: FullAuto
			{
				aiRateOfFire = 0.1;
				aiRateOfFireDistance = 50;
				minRange = 0;
				minRangeProbab = 0.9;
				midRange = 60;
				midRangeProbab = 0.7;
				maxRange = 120;
				maxRangeProbab = 0.1;
			};
		};
	};
	class MG36: G36C
	{
		modes[] = {"Single","Burst","FullAuto","close","medium","ACE_Burst_Far"};
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class close: FullAuto
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: close
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class far: close
		{
			burst = "2+round random 4";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 300;
			minRangeProbab = 0.8;
			midRange = "500+ random 50";
			midRangeProbab = 0.7;
			maxRange = "600+ random 50";
			maxRangeProbab = 0.1;
		};
		class ACE_Burst_Far: Burst
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 500;
			minRangeProbab = 0.05;
			midRange = 600;
			midRangeProbab = 0.1;
			maxRange = 700;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
	};
	class AK_BASE: Rifle
	{
		modes[] = {"FullAuto","Burst","Single","ACE_Burst_Far"};
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst_Far: Burst
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 500;
			minRangeProbab = 0.05;
			midRange = 600;
			midRangeProbab = 0.1;
			maxRange = 700;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class GP25Muzzle: GrenadeLauncher
		{
			minRangeProbab = 0;
			midRangeProbab = 0;
			maxRangeProbab = 0;
		};
		class ACE_GP25Muzzle_AI: GP25Muzzle
		{
			minRange = 50;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.9;
			maxRange = 400;
			maxRangeProbab = 0.05;
			cameraDir = "";
			memoryPointCamera = "";
			showtoplayer = 0;
		};
	};
	class AKS_BASE: AK_BASE
	{
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
	};
	class AK_107_BASE: AK_BASE
	{
		modes[] = {"FullAuto","Burst","Single","ACE_Burst_Far"};
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			burst = 3;
			showtoplayer = 1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst_Far: Burst
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 500;
			minRangeProbab = 0.05;
			midRange = 600;
			midRangeProbab = 0.1;
			maxRange = 700;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
	};
	class AK_107_GL_kobra: AK_107_BASE
	{
		muzzles[] = {"this","GP25Muzzle","ACE_GP25Muzzle_AI"};
	};
	class AK_107_GL_pso: AK_107_GL_kobra
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
	};
	class AK_107_pso: AK_107_BASE
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
	};
	class AKS_74_UN_kobra: AKS_BASE
	{
		modes[] = {"FullAuto","Burst","Single"};
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
	};
	class ksvk: Rifle
	{
		aiRateOfFire = 10;
		aiRateOfFireDistance = 1500;
		minRange = 1;
		minRangeProbab = 0.4;
		midRange = 500;
		midRangeProbab = 0.8;
		maxRange = 1800;
		maxRangeProbab = 0.1;
	};
	class m107: Rifle
	{
		aiRateOfFire = 10;
		aiRateOfFireDistance = 1500;
		minRange = 1;
		minRangeProbab = 0.4;
		midRange = 500;
		midRangeProbab = 0.8;
		maxRange = 1800;
		maxRangeProbab = 0.1;
	};
	class Sa61_EP1: Pistol
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 0.6;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.5;
			midRange = 20;
			midRangeProbab = 0.3;
			maxRange = 80;
			maxRangeProbab = 0.01;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.4;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.6;
			midRange = 10;
			midRangeProbab = 0.4;
			maxRange = 20;
			maxRangeProbab = 0.05;
		};
	};
	class UZI_EP1: Pistol
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 0.6;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.5;
			midRange = 20;
			midRangeProbab = 0.3;
			maxRange = 80;
			maxRangeProbab = 0.01;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.4;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.6;
			midRange = 10;
			midRangeProbab = 0.4;
			maxRange = 20;
			maxRangeProbab = 0.05;
		};
	};
	class UZI_SD_EP1: UZI_EP1
	{
		class Single: Single
		{
			aiRateOfFire = 0.6;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.5;
			midRange = 20;
			midRangeProbab = 0.3;
			maxRange = 80;
			maxRangeProbab = 0.01;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.4;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.6;
			midRange = 10;
			midRangeProbab = 0.4;
			maxRange = 20;
			maxRangeProbab = 0.05;
		};
	};
	class revolver_EP1: Pistol
	{
		aiRateOfFire = 0.6;
		aiRateOfFireDistance = 50;
		minRange = 0;
		minRangeProbab = 0.5;
		midRange = 20;
		midRangeProbab = 0.3;
		maxRange = 80;
		maxRangeProbab = 0.01;
	};
	class glock17_EP1: Pistol
	{
		aiRateOfFire = 0.6;
		aiRateOfFireDistance = 50;
		minRange = 0;
		minRangeProbab = 0.5;
		midRange = 20;
		midRangeProbab = 0.3;
		maxRange = 80;
		maxRangeProbab = 0.01;
	};
	class M60A4_EP1: Rifle
	{
		modes[] = {"manual","close","short","medium","ACE_long"};
		class manual: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = "30+ random 20";
			maxRangeProbab = 0.1;
		};
		class close: manual
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class short: close
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "300+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: close
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class far: close
		{
			burst = "2+round random 4";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 300;
			minRangeProbab = 0.8;
			midRange = "500+ random 50";
			midRangeProbab = 0.7;
			maxRange = "600+ random 50";
			maxRangeProbab = 0.1;
		};
		class ACE_long: far
		{
			burst = "8+round random 6";
			aiRateOfFire = 4;
			aiRateOfFireDistance = 1000;
			minRange = 400;
			minRangeProbab = 0.8;
			midRange = "700+ random 50";
			midRangeProbab = 0.2;
			maxRange = 800;
			maxRangeProbab = 0.1;
		};
	};
	class M249_m145_EP1: M249
	{
		modes[] = {"manual","close","short","medium","far","ACE_long"};
		class close: close
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class short: short
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "300+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: medium
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
	};
	class Sa58P_EP1: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
			burst = "3 + round random 4";
			showtoplayer = 0;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
	};
	class Sa58V_EP1: Sa58P_EP1{};
	class Sa58V_RCO_EP1: Sa58V_EP1
	{
		class Single: Single
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
			burst = "3 + round random 4";
			showtoplayer = 0;
		};
	};
	class M4A3_CCO_EP1: M16_base
	{
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
	};
	class M4A3_RCO_GL_EP1: M4A3_CCO_EP1
	{
		muzzles[] = {"this","M203Muzzle","ACE_M203Muzzle_AI"};
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
	};
	class MP5SD: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 75;
			midRangeProbab = 0.5;
			maxRange = 150;
			maxRangeProbab = 0.05;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 100;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 40;
			maxRangeProbab = 0.1;
		};
	};
	class MP5A5: MP5SD
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 75;
			midRangeProbab = 0.5;
			maxRange = 150;
			maxRangeProbab = 0.05;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 100;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 40;
			maxRangeProbab = 0.1;
		};
	};
	class AK_47_M: AK_BASE
	{
		modes[] = {"FullAuto","Burst","Single","ACE_Burst_Far"};
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 500;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.2;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 200;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 150;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst_Far: Burst
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 400;
			minRangeProbab = 0.05;
			midRange = 500;
			midRangeProbab = 0.1;
			maxRange = 600;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
	};
	class AK_74: AK_BASE
	{
		class Burst: Burst{};
		class ACE_Burst_Far: Burst
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 400;
			minRangeProbab = 0.05;
			midRange = 500;
			midRangeProbab = 0.1;
			maxRange = 600;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
	};
	class AK_74_GL: AK_BASE
	{
		muzzles[] = {"this","GP25Muzzle","ACE_GP25Muzzle_AI"};
		class Burst: Burst{};
		class ACE_Burst_Far: Burst
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 400;
			minRangeProbab = 0.05;
			midRange = 500;
			midRangeProbab = 0.1;
			maxRange = 600;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
	};
	class AKS_74_pso: AKS_BASE
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
	};
	class AKS_74_U: AKS_BASE
	{
		modes[] = {"FullAuto","Burst","Single","ACE_Burst_Far"};
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 200;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst_Far: Burst
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 600;
			minRange = 300;
			minRangeProbab = 0.05;
			midRange = 400;
			midRangeProbab = 0.1;
			maxRange = 600;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
	};
	class RPK_74: AK_74
	{
		modes[] = {"manual","close","short","medium","Single","ACE_Burst_Far"};
		class FullAuto: Mode_FullAuto{};
		class manual: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = "30+ random 20";
			maxRangeProbab = 0.1;
		};
		class close: manual
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class short: close
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "300+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: close
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class far: close
		{
			burst = "2+round random 4";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 300;
			minRangeProbab = 0.8;
			midRange = "500+ random 50";
			midRangeProbab = 0.7;
			maxRange = "600+ random 50";
			maxRangeProbab = 0.1;
		};
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst_Far: far
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 500;
			minRangeProbab = 0.05;
			midRange = 600;
			midRangeProbab = 0.1;
			maxRange = 700;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
	};
	class AKS_74_GOSHAWK: AKS_BASE
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
	};
	class FN_FAL: M16A2
	{
		modes[] = {"Single","Burst","Auto"};
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
			burst = "2 + round random 4";
			showtoplayer = 0;
		};
		class Auto: Single
		{
			displayName = "$STR_DN_MODE_FULLAUTO";
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			autoFire = 1;
		};
	};
	class LeeEnfield: Rifle
	{
		aiRateOfFire = 3;
		aiRateOfFireDistance = 400;
		minRange = 0;
		minRangeProbab = 0.4;
		midRange = 300;
		midRangeProbab = 0.8;
		maxRange = 500;
		maxRangeProbab = 0.1;
	};
	class M110_TWS_EP1: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 6;
			aiRateOfFireDistance = 1100;
			minRange = 0;
			minRangeProbab = 0.4;
			midRange = 500;
			midRangeProbab = 0.8;
			maxRange = 1100;
			maxRangeProbab = 0.1;
		};
	};
	class M14_EP1: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Auto: Single
		{
			displayName = "$STR_DN_MODE_FULLAUTO";
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			autoFire = 1;
		};
		modes[] = {"Single","Auto"};
	};
	class m240_scoped_EP1: m240
	{
		modes[] = {"manual","close","short","medium","far","ACE_long"};
	};
	class SCAR_Base: M16_base
	{
		class SCAR_L_Single: Single{};
		class SCAR_L_FullAuto: FullAuto{};
		class ACE_Burst: SCAR_L_Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		modes[] = {"SCAR_L_Single","SCAR_L_FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
		class EGLMMuzzle: M203Muzzle
		{
			minRangeProbab = 0;
			midRangeProbab = 0;
			maxRangeProbab = 0;
		};
		class ACE_EGLMMuzzle_AI: EGLMMuzzle
		{
			minRange = 50;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.9;
			maxRange = 400;
			maxRangeProbab = 0.05;
			cameraDir = "";
			memoryPointCamera = "";
			showtoplayer = 0;
		};
	};
	class SCAR_L_Base: SCAR_Base{};
	class SCAR_L_CQC: SCAR_L_Base
	{
		class SCAR_L_Single: SCAR_L_Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class SCAR_L_FullAuto: SCAR_L_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: SCAR_L_Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		modes[] = {"SCAR_L_Single","SCAR_L_FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
	};
	class SCAR_L_CQC_EGLM_Holo: SCAR_L_CQC
	{
		muzzles[] = {"this","EGLMMuzzle","ACE_EGLMMuzzle_AI"};
	};
	class SCAR_L_STD_Mk4CQT: SCAR_L_Base
	{
		class SCAR_L_Single: SCAR_L_Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
	};
	class SCAR_L_STD_EGLM_RCO: SCAR_L_STD_Mk4CQT
	{
		muzzles[] = {"this","EGLMMuzzle","ACE_EGLMMuzzle_AI"};
	};
	class SCAR_L_STD_EGLM_TWS: SCAR_L_STD_EGLM_RCO
	{
		muzzles[] = {"this","EGLMMuzzle","ACE_EGLMMuzzle_AI"};
		class SCAR_L_Single: SCAR_L_Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
	};
	class SCAR_L_CQC_CCO_SD: SCAR_L_CQC
	{
		class SCAR_L_SD_Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class SCAR_L_SD_FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: SCAR_L_SD_Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
		modes[] = {"SCAR_L_SD_Single","SCAR_L_SD_FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
	};
	class SCAR_H_Base: SCAR_Base
	{
		class SCAR_H_Single: Mode_SemiAuto
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class SCAR_H_FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: SCAR_H_Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 4";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 4";
		};
		modes[] = {"SCAR_H_Single","SCAR_H_FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
	};
	class SCAR_H_CQC_CCO: SCAR_H_Base
	{
		class SCAR_H_Single: SCAR_H_Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
	};
	class SCAR_H_CQC_CCO_SD: SCAR_H_CQC_CCO
	{
		class SCAR_H_SD_Single: SCAR_H_Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class SCAR_H_SD_FullAuto: SCAR_H_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: SCAR_H_SD_Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
		modes[] = {"SCAR_H_SD_Single","SCAR_H_SD_FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
	};
	class SCAR_H_STD_EGLM_Spect: SCAR_H_CQC_CCO
	{
		muzzles[] = {"this","EGLMMuzzle","ACE_EGLMMuzzle_AI"};
		class SCAR_H_Single: SCAR_H_Single
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
	};
	class SCAR_H_LNG_Sniper: SCAR_H_Base
	{
		class SCAR_H_Single: SCAR_H_Single
		{
			aiRateOfFire = 6;
			aiRateOfFireDistance = 1100;
			minRange = 0;
			minRangeProbab = 0.4;
			midRange = 500;
			midRangeProbab = 0.8;
			maxRange = 1100;
			maxRangeProbab = 0.1;
		};
	};
	class SCAR_H_LNG_Sniper_SD: SCAR_H_Base
	{
		class SCAR_H_SD_Single: Mode_SemiAuto
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		class SCAR_H_SD_FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: SCAR_H_SD_Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
		modes[] = {"SCAR_H_SD_Single","SCAR_H_SD_FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
	};
	class SCAR_H_STD_TWS_SD: SCAR_H_LNG_Sniper_SD
	{
		class SCAR_H_SD_Single: SCAR_H_SD_Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: SCAR_H_SD_Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
		modes[] = {"SCAR_H_SD_Single","SCAR_H_SD_FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
	};
	class BAF_AS50_scoped: Rifle
	{
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 10;
			aiRateOfFireDistance = 1500;
			minRange = 1;
			minRangeProbab = 0.4;
			midRange = 500;
			midRangeProbab = 0.8;
			maxRange = 1800;
			maxRangeProbab = 0.1;
		};
	};
	class BAF_LRR_scoped: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 8;
			aiRateOfFireDistance = 1200;
			minRange = 1;
			minRangeProbab = 0.4;
			midRange = 500;
			midRangeProbab = 0.8;
			maxRange = 1200;
			maxRangeProbab = 0.1;
		};
	};
	class BAF_L17_40mm: GrenadeLauncher{};
	class L85A2_base_BAF: Rifle
	{
		class BAF_L17_40mm: BAF_L17_40mm
		{
			minRangeProbab = 0;
			midRangeProbab = 0;
			maxRangeProbab = 0;
		};
		class ACE_L17_AI: BAF_L17_40mm
		{
			minRange = 50;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.9;
			maxRange = 400;
			maxRangeProbab = 0.05;
			cameraDir = "";
			memoryPointCamera = "";
			showtoplayer = 0;
		};
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
	};
	class BAF_L85A2_RIS_Holo: L85A2_base_BAF{};
	class BAF_L85A2_UGL_Holo: BAF_L85A2_RIS_Holo
	{
		muzzles[] = {"this","BAF_L17_40mm","ACE_L17_AI"};
	};
	class BAF_L85A2_RIS_SUSAT: L85A2_base_BAF
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
	};
	class BAF_L85A2_UGL_SUSAT: BAF_L85A2_RIS_SUSAT
	{
		muzzles[] = {"this","BAF_L17_40mm","ACE_L17_AI"};
	};
	class BAF_L85A2_RIS_ACOG: L85A2_base_BAF
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
	};
	class BAF_L85A2_UGL_ACOG: BAF_L85A2_RIS_ACOG
	{
		muzzles[] = {"this","BAF_L17_40mm","ACE_L17_AI"};
	};
	class BAF_L86A2_ACOG: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
	};
	class BAF_L110A1_Aim: Rifle
	{
		modes[] = {"manual","close","short","medium","ACE_long"};
		class manual: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = "30+ random 20";
			maxRangeProbab = 0.1;
		};
		class close: manual
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class short: close
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "300+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: close
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class far: close
		{
			burst = "2+round random 4";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 300;
			minRangeProbab = 0.8;
			midRange = "500+ random 50";
			midRangeProbab = 0.7;
			maxRange = "600+ random 50";
			maxRangeProbab = 0.1;
		};
		class ACE_long: far
		{
			burst = "8+round random 6";
			aiRateOfFire = 4;
			aiRateOfFireDistance = 1000;
			minRange = 400;
			minRangeProbab = 0.8;
			midRange = "700+ random 50";
			midRangeProbab = 0.2;
			maxRange = 800;
			maxRangeProbab = 0.1;
		};
	};
	class M1014: Rifle
	{
		class Single: Mode_SemiAuto
		{
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 60;
			midRangeProbab = 0.2;
			maxRange = 120;
			maxRangeProbab = 0.05;
		};
	};
	class Saiga12K: Rifle
	{
		class Single: Mode_SemiAuto
		{
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 60;
			midRangeProbab = 0.2;
			maxRange = 120;
			maxRangeProbab = 0.05;
		};
	};
	class AA12_PMC: Rifle
	{
		class Single: Mode_SemiAuto
		{
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 60;
			midRangeProbab = 0.2;
			maxRange = 120;
			maxRangeProbab = 0.05;
		};
		class FullAuto: Mode_FullAuto
		{
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.5;
			maxRange = 60;
			maxRangeProbab = 0.1;
		};
	};
	class m8_base: Rifle
	{
		modes[] = {"Single","Burst","FullAuto"};
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class XM320Muzzle: M203Muzzle{};
		class ACE_XM320Muzzle_AI: XM320Muzzle
		{
			minRange = 50;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.9;
			maxRange = 400;
			maxRangeProbab = 0.05;
			cameraDir = "";
			memoryPointCamera = "";
			showtoplayer = 0;
		};
	};
	class m8_carbine: m8_base
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
	};
	class m8_carbineGL: m8_base
	{
		muzzles[] = {"this","XM320Muzzle","ACE_XM320Muzzle_AI"};
	};
	class m8_compact: m8_base
	{
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 200;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
	};
	class m8_sharpshooter: m8_base
	{
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
	};
	class m8_SAW: m8_sharpshooter
	{
		modes[] = {"Manual","Close","Short","Medium","Far","ACE_Burst_Far"};
		class Manual: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = "30+ random 20";
			maxRangeProbab = 0.1;
		};
		class Close: Manual
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class Short: Close
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "300+ random 50";
			maxRangeProbab = 0.1;
		};
		class Medium: Close
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class Far: Close
		{
			burst = "2+round random 4";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 300;
			minRangeProbab = 0.8;
			midRange = "500+ random 50";
			midRangeProbab = 0.7;
			maxRange = "600+ random 50";
			maxRangeProbab = 0.1;
		};
		class ACE_Burst_Far: Far
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 500;
			minRangeProbab = 0.05;
			midRange = 600;
			midRangeProbab = 0.1;
			maxRange = 700;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
	};
	class m8_holo_sd: m8_base
	{
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
	};
	class m8_tws_sd: m8_base
	{
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
	};
	class VSS_vintorez: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 600;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Full: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
		modes[] = {"Single","Full","ACE_Burst_AI","ACE_Burst_AI2"};
	};
	class bizon: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 75;
			midRangeProbab = 0.5;
			maxRange = 150;
			maxRangeProbab = 0.05;
		};
		class Burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 100;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
			burst = "3+round random 3";
		};
		class FullAuto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 40;
			maxRangeProbab = 0.1;
		};
	};
	class DMR: Rifle
	{
		class Single: Mode_SemiAuto
		{
			aiRateOfFire = 6;
			aiRateOfFireDistance = 1100;
			minRange = 0;
			minRangeProbab = 0.4;
			midRange = 500;
			midRangeProbab = 0.8;
			maxRange = 1100;
			maxRangeProbab = 0.1;
		};
	};
	class CZ805_A1_ACR: Rifle
	{
		modes[] = {"single","burst","fullauto"};
		class single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
		};
		class fullauto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class M203Muzzle;
	};
	class CZ805_A1_GL_ACR: CZ805_A1_ACR
	{
		muzzles[] = {"this","M203Muzzle","ACE_CZ805G1Muzzle_AI"};
		class M203Muzzle: M203Muzzle
		{
			minRangeProbab = 0;
			midRangeProbab = 0;
			maxRangeProbab = 0;
		};
		class ACE_CZ805G1Muzzle_AI: M203Muzzle
		{
			minRange = 50;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.9;
			maxRange = 400;
			maxRangeProbab = 0.05;
			cameraDir = "";
			memoryPointCamera = "";
			showtoplayer = 0;
		};
	};
	class CZ805_A2_ACR: CZ805_A1_ACR
	{
		class single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 200;
			maxRangeProbab = 0.1;
		};
		class fullauto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
	};
	class CZ805_A2_SD_ACR: CZ805_A2_ACR
	{
		class single: Mode_SemiAuto
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class burst: Mode_Burst
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		class fullauto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
	};
	class CZ805_B_GL_ACR: CZ805_A1_ACR
	{
		muzzles[] = {"this","M203Muzzle","ACE_CZ805G1Muzzle_AI"};
		class M203Muzzle: M203Muzzle
		{
			minRangeProbab = 0;
			midRangeProbab = 0;
			maxRangeProbab = 0;
		};
		class ACE_CZ805G1Muzzle_AI: M203Muzzle
		{
			minRange = 50;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.9;
			maxRange = 400;
			maxRangeProbab = 0.05;
			cameraDir = "";
			memoryPointCamera = "";
			showtoplayer = 0;
		};
		class single: Mode_SemiAuto
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		class burst: Mode_Burst
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
		};
		class fullauto: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
	};
	class UK59_ACR: Rifle
	{
		modes[] = {"manual","close","short","medium","ACE_long"};
		class manual: Mode_FullAuto
		{
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = "30+ random 20";
			maxRangeProbab = 0.1;
		};
		class close: manual
		{
			burst = "6+round random 4";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 30;
			minRangeProbab = 0.8;
			midRange = "50+ random 50";
			midRangeProbab = 0.7;
			maxRange = "100+ random 50";
			maxRangeProbab = 0.1;
		};
		class short: close
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "300+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: close
		{
			burst = "4+round random 4";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "300+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class far: close
		{
			burst = "2+round random 4";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 300;
			minRangeProbab = 0.8;
			midRange = "500+ random 50";
			midRangeProbab = 0.7;
			maxRange = "600+ random 50";
			maxRangeProbab = 0.1;
		};
		class ACE_long: far
		{
			burst = "8+round random 6";
			aiRateOfFire = 4;
			aiRateOfFireDistance = 1000;
			minRange = 400;
			minRangeProbab = 0.8;
			midRange = "700+ random 50";
			midRangeProbab = 0.2;
			maxRange = 800;
			maxRangeProbab = 0.1;
		};
	};
};
class CfgVehicles
{
	class CAManBase;
	class SoldierWB: CAManBase
	{
		minFireTime = 5;
	};
	class SoldierEB: CAManBase
	{
		minFireTime = 5;
	};
	class SoldierGB: CAManBase
	{
		minFireTime = 5;
	};
	class Civilian: CAManBase
	{
		minFireTime = 20;
	};
	class TK_INS_Soldier_Base_EP1: SoldierEB
	{
		minFireTime = 10;
	};
	class TK_GUE_Soldier_Base_EP1: SoldierGB
	{
		minFireTime = 10;
	};
	class US_Delta_Force_Undercover_Takistani_Base_EP1: TK_GUE_Soldier_Base_EP1
	{
		minFireTime = 2.5;
	};
	class CZ_Soldier_base_EP1: SoldierWB
	{
		minFireTime = 5;
	};
	class CZ_Special_Forces_Scout_DES_EP1: CZ_Soldier_base_EP1
	{
		minFireTime = 2.5;
	};
	class CZ_Special_Forces_MG_DES_EP1: CZ_Soldier_base_EP1
	{
		minFireTime = 2.5;
	};
	class CZ_Special_Forces_DES_EP1: CZ_Soldier_base_EP1
	{
		minFireTime = 2.5;
	};
	class CZ_Special_Forces_TL_DES_EP1: CZ_Soldier_base_EP1
	{
		minFireTime = 2.5;
	};
	class CZ_Special_Forces_GL_DES_EP1: CZ_Soldier_base_EP1
	{
		minFireTime = 2.5;
	};
	class US_Soldier_Base_EP1: SoldierWB
	{
		minFireTime = 5;
	};
	class US_Delta_Force_EP1: US_Soldier_Base_EP1
	{
		minFireTime = 2.5;
	};
	class UN_CDF_Soldier_base_EP1: SoldierGB
	{
		minFireTime = 5;
	};
	class TK_Soldier_base_EP1: SoldierEB
	{
		minFireTime = 5;
	};
	class TK_Special_Forces_EP1: TK_Soldier_base_EP1
	{
		minFireTime = 2.5;
	};
	class GER_Soldier_base_EP1: SoldierWB
	{
		minFireTime = 2.5;
	};
	class BAF_Soldier_base_EP1: SoldierWB
	{
		minFireTime = 5;
	};
	class FR_Base: SoldierWB
	{
		minFireTime = 2.5;
	};
	class RUS_Soldier_Base: SoldierEB
	{
		minFireTime = 2.5;
	};
	class MVD_Soldier_Base: SoldierEB
	{
		minFireTime = 2.5;
	};
	class GUE_Soldier_Base: SoldierGB
	{
		minFireTime = 10;
	};
	class Ins_Soldier_Base: SoldierEB
	{
		minFireTime = 10;
	};
	class CDF_Soldier_Base: SoldierWB
	{
		minFireTime = 5;
	};
	class Policeman: Civilian
	{
		minFireTime = 5;
	};
};
//};
