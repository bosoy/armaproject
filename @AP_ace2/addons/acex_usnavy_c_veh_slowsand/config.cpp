////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:58:58 2011 : Created on Fri Oct 21 13:58:58 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_c_veh_slowsand : config.bin{
class CfgPatches
{
	class acex_usnavy_c_veh_slowsand
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_usnavy_main","ace_c_vehicle"};
		author[] = {"conKORD"};
		version = "1.12.0.64";
	};
};
class CfgSurfaces
{
	class Default;
	class CRGrit1: Default
	{
		access = 2;
		files = "cr_sterk_*";
		rough = 0.13;
		dust = 0.25;
		soundEnviron = "gravel";
		character = "Empty";
		soundHit = "hard_ground";
	};
	class CRGrassW1: Default
	{
		access = 2;
		files = "cr_travad1_*";
		rough = 0.14;
		dust = 0.1;
		soundEnviron = "grass";
		character = "CRGrassWClutter";
		soundHit = "soft_ground";
	};
	class CRForest2: Default
	{
		access = 2;
		files = "cr_les2_*";
		rough = 0.3;
		dust = 0.15;
		soundEnviron = "forest";
		character = "CRForestFirClutter";
		soundHit = "soft_ground";
	};
	class CRTarmac: Default
	{
		access = 2;
		files = "cr_asfalt_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "road";
		character = "Empty";
		soundHit = "hard_ground";
	};
	class CRGrass1: Default
	{
		access = 2;
		files = "cr_trava1_*";
		rough = 0.14;
		dust = 0.1;
		soundEnviron = "grass";
		character = "CRGrassClutter";
		soundHit = "soft_ground";
	};
	class CRForest1: Default
	{
		access = 2;
		files = "cr_les1_*";
		rough = 0.3;
		dust = 0.2;
		soundEnviron = "forest";
		character = "CRForestMixedClutter";
		soundHit = "soft_ground";
	};
	class CRGrass2: Default
	{
		access = 2;
		files = "cr_trava2_*";
		rough = 0.14;
		dust = 0.1;
		soundEnviron = "grass";
		character = "CRTallGrassClutter";
		soundHit = "soft_ground";
	};
	class CRHeather: Default
	{
		access = 2;
		files = "cr_vres_*";
		rough = 0.18;
		dust = 0.1;
		soundEnviron = "forest";
		character = "CRHeatherClutter";
		soundHit = "soft_ground";
	};
	class CRField2: Default
	{
		access = 2;
		files = "cr_strniste_*";
		rough = 0.17;
		dust = 0.3;
		soundEnviron = "dirt";
		character = "CRStubbleClutter";
		soundHit = "soft_ground";
	};
	class CRField1: Default
	{
		access = 2;
		files = "cr_oranice_*";
		rough = 0.2;
		dust = 0.25;
		soundEnviron = "dirt";
		character = "Empty";
		soundHit = "soft_ground";
	};
	class CRConcrete: Default
	{
		access = 2;
		files = "cr_beton_*";
		rough = 0.08;
		dust = 0.05;
		soundEnviron = "concrete_ext";
		character = "Empty";
		soundHit = "concrete";
	};
	class CRRock: Default
	{
		access = 2;
		files = "cr_skala_*";
		rough = 0.4;
		dust = 0.07;
		soundEnviron = "rock";
		character = "Empty";
		soundHit = "hard_ground";
	};
	class UTGravel: Default
	{
		rough = 0.14;
		dust = 0.35;
	};
	class UTGrass: Default
	{
		rough = 0.15;
		dust = 0.1;
	};
	class UTGround: Default
	{
		rough = 0.14;
		dust = 0.2;
	};
	class UTWeeds: Default
	{
		rough = 0.15;
		dust = 0.1;
	};
	class UTHeather: Default
	{
		rough = 0.18;
		dust = 0.1;
	};
	class UTBoulders: Default
	{
		rough = 0.14;
		dust = 0.07;
	};
};
//};
