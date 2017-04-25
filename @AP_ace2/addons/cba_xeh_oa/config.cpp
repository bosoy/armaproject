////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:58 2013 : Created on Thu Jan 03 12:00:58 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_xeh_oa : config.bin{
class CfgPatches
{
	class cba_xeh_oa
	{
		units[] = {};
		weapons[] = {};
		worlds[] = {};
		requiredAddons[] = {"CBA_Main","CBA_XEH","CAData","HALO_Test","CA_Modules","CA_Missions_AlternativeInjurySimulation","CA_Modules_Alice","CA_Missions_AmbientCombat","CA_Modules_Animals","CA_Missions_BattlefieldClearance","CA_Modules_clouds","CA_Modules_Coin","CA_Missions_FirstAidSystem","CA_Modules_Functions","CA_Missions_GarbageCollector","CA_HighCommand","CA_Modules_Marta","CA_Modules_Silvie","BI_SRRS","CA_Modules_UAV","CA_Modules_ZoRA","CA_Animals2_Chicken","CA_Modules_ARTY","CA_Missions_SecOps","CA_Modules_StratLayer","CAAir","CAMisc3","CAA10","CAAir2","CAAir3","CAUI","CA_CommunityConfigurationProject_E"};
		requiredVersion = 1.0;
		version = "1.0.1.196";
		versionStr = "1.0.1.196";
		versionAr[] = {1,0,1,196};
		author[] = {"CBA Team","Solus","Killswitch"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
	class CBA_OA_xeh
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {};
	};
};
class Extended_PreInit_EventHandlers
{
	class SLX_BIS_CCP
	{
		init = "call ('\ca\communityconfigurationproject_e\ai_madetankgunnersuseatandheammo\muzzle\init.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class StaticCannon
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	};
	class M252
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	};
	class 2b14_82mm
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	};
	class FR_Miles
	{
		SLX_BIS = "(_this select 0) setidentity ""Miles""";
	};
	class FR_Cooper
	{
		SLX_BIS = "(_this select 0) setidentity ""Cooper""";
	};
	class FR_Sykes
	{
		SLX_BIS = "(_this select 0) setidentity ""Sykes""";
	};
	class FR_OHara
	{
		SLX_BIS = "(_this select 0) setidentity ""Ohara""";
	};
	class FR_Rodriguez
	{
		SLX_BIS = "(_this select 0) setidentity ""Rodriguez""";
	};
	class TK_CIV_Takistani01_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\civil\Tak_civil01\Data\Tak_civil01_1_co.paa"",""\CA\characters_E\civil\Tak_civil01\Data\Tak_civil01_2_co.paa"",""\CA\characters_E\civil\Tak_civil01\Data\Tak_civil01_3_co.paa"",""\CA\characters_E\civil\Tak_civil01\Data\Tak_civil01_4_co.paa"",""\CA\characters_E\civil\Tak_civil01\Data\Tak_civil01_5_co.paa""] select floor random 5]";
	};
	class TK_CIV_Takistani02_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\civil\Tak_civil02\Data\Tak_civil02_1_co.paa"",""\CA\characters_E\civil\Tak_civil02\Data\Tak_civil02_2_co.paa"",""\CA\characters_E\civil\Tak_civil02\Data\Tak_civil02_3_co.paa"",""\CA\characters_E\civil\Tak_civil02\Data\Tak_civil02_4_co.paa"",""\CA\characters_E\civil\Tak_civil02\Data\Tak_civil02_5_co.paa""] select floor random 5]";
	};
	class TK_CIV_Takistani03_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\civil\Tak_civil03\Data\Tak_civil03_1_co.paa"",""\CA\characters_E\civil\Tak_civil03\Data\Tak_civil03_2_co.paa"",""\CA\characters_E\civil\Tak_civil03\Data\Tak_civil03_3_co.paa"",""\CA\characters_E\civil\Tak_civil03\Data\Tak_civil03_4_co.paa"",""\CA\characters_E\civil\Tak_civil03\Data\Tak_civil03_5_co.paa""] select floor random 5]";
	};
	class TK_CIV_Takistani04_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\civil\Tak_civil04\Data\Tak_civil04_1_co.paa"",""\CA\characters_E\civil\Tak_civil04\Data\Tak_civil04_2_co.paa"",""\CA\characters_E\civil\Tak_civil04\Data\Tak_civil04_3_co.paa"",""\CA\characters_E\civil\Tak_civil04\Data\Tak_civil04_4_co.paa"",""\CA\characters_E\civil\Tak_civil04\Data\Tak_civil04_5_co.paa""] select floor random 5]";
	};
	class TK_CIV_Takistani05_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\civil\Tak_civil05\Data\Tak_civil05_1_co.paa"",""\CA\characters_E\civil\Tak_civil05\Data\Tak_civil05_2_co.paa"",""\CA\characters_E\civil\Tak_civil05\Data\Tak_civil05_3_co.paa"",""\CA\characters_E\civil\Tak_civil05\Data\Tak_civil05_4_co.paa"",""\CA\characters_E\civil\Tak_civil05\Data\Tak_civil05_5_co.paa""] select floor random 5]";
	};
	class TK_CIV_Takistani06_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\civil\Tak_civil06\Data\Tak_civil06_1_co.paa"",""\CA\characters_E\civil\Tak_civil06\Data\Tak_civil06_2_co.paa"",""\CA\characters_E\civil\Tak_civil06\Data\Tak_civil06_3_co.paa"",""\CA\characters_E\civil\Tak_civil06\Data\Tak_civil06_4_co.paa"",""\CA\characters_E\civil\Tak_civil06\Data\Tak_civil06_5_co.paa""] select floor random 5]";
	};
	class TK_CIV_Woman01_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\Woman\Tak_Woman01\Data\Tak_Woman01_1_co.paa"",""\CA\characters_E\Woman\Tak_Woman01\Data\Tak_Woman01_2_co.paa"",""\CA\characters_E\Woman\Tak_Woman01\Data\Tak_Woman01_3_co.paa"",""\CA\characters_E\Woman\Tak_Woman01\Data\Tak_Woman01_4_co.paa"",""\CA\characters_E\Woman\Tak_Woman01\Data\Tak_Woman01_5_co.paa""] select floor random 5]";
	};
	class TK_CIV_Woman02_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\Woman\Tak_Woman02\Data\Tak_Woman02_1_co.paa"",""\CA\characters_E\Woman\Tak_Woman02\Data\Tak_Woman02_2_co.paa"",""\CA\characters_E\Woman\Tak_Woman02\Data\Tak_Woman02_3_co.paa"",""\CA\characters_E\Woman\Tak_Woman02\Data\Tak_Woman02_4_co.paa"",""\CA\characters_E\Woman\Tak_Woman02\Data\Tak_Woman02_5_co.paa""] select floor random 5]";
	};
	class TK_CIV_Woman03_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\Woman\Tak_Woman03\Data\Tak_Woman03_1_co.paa"",""\CA\characters_E\Woman\Tak_Woman03\Data\Tak_Woman03_2_co.paa"",""\CA\characters_E\Woman\Tak_Woman03\Data\Tak_Woman03_3_co.paa"",""\CA\characters_E\Woman\Tak_Woman03\Data\Tak_Woman03_4_co.paa"",""\CA\characters_E\Woman\Tak_Woman03\Data\Tak_Woman03_5_co.paa""] select floor random 5]";
	};
	class Dr_Annie_Baker_EP1
	{
		SLX_BIS = "(_this select 0) setidentity ""Dr_Annie_Baker""";
	};
	class Rita_Ensler_EP1
	{
		SLX_BIS = "(_this select 0) setidentity ""Rita_Ensler""";
	};
	class Haris_Press_EP1
	{
		SLX_BIS = "(_this select 0) setidentity ""Haris_Press_EP1""";
	};
	class Dr_Hladik_EP1
	{
		SLX_BIS = "(_this select 0) setidentity ""Dr_Hladik""";
	};
	class TK_INS_Soldier_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor01_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor01_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor01_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Soldier_2_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor04_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor04_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor04_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Soldier_3_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor02_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor02_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor02_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Soldier_4_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor05_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor05_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor05_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Soldier_AA_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor04_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor04_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor04_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Soldier_AT_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor01_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor01_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor01_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Soldier_TL_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor03_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor03_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor03_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Soldier_Sniper_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor03_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor03_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor03_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Soldier_AR_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor05_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor05_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor05_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Soldier_MG_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor02_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor02_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor02_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Bonesetter_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor05_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor05_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor05_3_co.paa""] select floor random 3]";
	};
	class TK_INS_Warlord_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_opfor02_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor02_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_opfor02_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind01_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind01_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind01_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_2_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind04_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind04_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind04_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_3_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind01_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind01_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind01_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_4_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind03_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind03_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind03_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_5_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind02_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind02_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind02_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_AA_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind04_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind04_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind04_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_AT_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind01_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind01_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind01_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_HAT_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind01_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind01_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind01_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_TL_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind04_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind04_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind04_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_Sniper_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind03_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind03_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind03_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_AR_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind05_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind05_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind05_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Soldier_MG_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind02_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind02_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind02_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Bonesetter_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind04_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind04_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind04_3_co.paa""] select floor random 3]";
	};
	class TK_GUE_Warlord_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\characters_E\LOC\Data\LOC_ind02_1_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind02_2_co.paa"",""\CA\characters_E\LOC\Data\LOC_ind02_3_co.paa""] select floor random 3]";
	};
	class Land_Fire_burning
	{
		SLX_BIS = "(_this select 0) inflame true";
	};
	class Land_Campfire_burning
	{
		SLX_BIS = "(_this select 0) inflame true";
	};
	class FlagCarrierUSA
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\data\flag_usa_co.paa""";
	};
	class FlagCarrierCDF
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\data\flag_Chernarus_co.paa""";
	};
	class FlagCarrierRU
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\data\flag_rus_co.paa""";
	};
	class FlagCarrierINS
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\data\flag_ChDKZ_co.paa""";
	};
	class FlagCarrierGUE
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\data\flag_NAPA_co.paa""";
	};
	class FlagCarrierChecked
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\structures\misc\armory\checkered_flag\data\checker_flag_co.paa""";
	};
	class Barrack2
	{
		SLX_BIS = "(_this select 0) setdir getdir (_this select 0)";
	};
	class Mass_grave
	{
		SLX_BIS = "dummy = _this spawn ('ca\characters2\OTHER\scripts\fly.sqf' call SLX_XEH_COMPILE)";
	};
	class AAV
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)};_this spawn ('\ca\tracked2\AAV\scripts\init.sqf' call SLX_XEH_COMPILE)";
	};
	class Pickup_PK_TK_GUE_EP1
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\CA\wheeled_E\Datsun_Armed\Data\datsun_trup1_EINS_CO"",""\CA\wheeled_E\Datsun_Armed\Data\datsun_trup2_EINS_CO"",""\CA\wheeled_E\Datsun_Armed\Data\datsun_trup3_EINS_CO""] select floor random 3]";
	};
	class A10
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	};
	class Su34
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	};
	class AH6X_EP1
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
		SLX_BIS2 = "(_this select 0) lockturret [[0],true];(_this select 0) lockturret [[1],true]";
	};
	class FlagCarrierUNO_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_uno_co.paa""";
	};
	class FlagCarrierRedCrystal_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_rcrystal_co.paa""";
	};
	class FlagCarrierTFKnight_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_knight_co.paa""";
	};
	class FlagCarrierCDFEnsign_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_cdf_co.paa""";
	};
	class FlagCarrierRedCross_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_rcross_co.paa""";
	};
	class FlagCarrierUSArmy_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_usarmy_co.paa""";
	};
	class FlagCarrierTKMilitia_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_tkm_co.paa""";
	};
	class FlagCarrierRedCrescent_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_rcrescent_co.paa""";
	};
	class FlagCarrierGermany_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_ger_co.paa""";
	};
	class FlagCarrierNATO_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_nato_co.paa""";
	};
	class FlagCarrierBIS_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_bis_co.paa""";
	};
	class FlagCarrierCzechRepublic_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_cz_co.paa""";
	};
	class FlagCarrierPOWMIA_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_pow_co.paa""";
	};
	class FlagCarrierBLUFOR_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_blufor_co.paa""";
	};
	class FlagCarrierOPFOR_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_opfor_co.paa""";
	};
	class FlagCarrierINDFOR_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_indfor_co.paa""";
	};
	class FlagCarrierTakistan_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_tka_co.paa""";
	};
	class FlagCarrierTakistanKingdom_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_tkg_co.paa""";
	};
	class FlagCarrierUSA_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_us_co.paa""";
	};
	class FlagCarrierCDF_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_cr_co.paa""";
	};
	class FlagCarrierWhite_EP1
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""ca\Ca_E\data\flag_white_co.paa""";
	};
	class FlagCarrierIONblack_PMC
	{
		SLX_BIS = "(_this select 0) setFlagTexture 'ca\Ca_PMC\flag_ion_black_co';";
	};
	class FlagCarrierIONwhite_PMC
	{
		SLX_BIS = "(_this select 0) setFlagTexture 'ca\Ca_PMC\flag_ion_white_co';";
	};
	class Soldier_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\Ca\Characters_PMC\PMC_soldier\Data\bauer_2_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\bauer_3_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\bauer_4_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\bauer_5_co.paa""] select floor random 4]; (_this select 0) setObjectTexture [1,[""ca\characters_pmc\pmc_soldier\data\bauer_gear_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\Bauer_Gear_1_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\Bauer_Gear_2_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\Bauer_Gear_3_co.paa""] select floor random 4]; (_this select 0) setObjectTexture [2,[""\Ca\Characters_PMC\PMC_soldier\Data\HeadGear_CO.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\HeadGear_1_CO.paa""] select floor random 2]";
	};
	class Soldier_Engineer_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\Ca\Characters_PMC\Frost\Data\Frost_1_co.paa"",""\Ca\Characters_PMC\Frost\Data\Frost_2_co.paa"",""\Ca\Characters_PMC\Frost\Data\Frost_3_co.paa""] select floor random 3];";
	};
	class Soldier_Crew_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\Ca\Characters_PMC\Frost\Data\Frost_1_co.paa"",""\Ca\Characters_PMC\Frost\Data\Frost_2_co.paa"",""\Ca\Characters_PMC\Frost\Data\Frost_3_co.paa""] select floor random 3];";
	};
	class Soldier_Medic_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\Ca\Characters_PMC\Frost\Data\Frost_1_co.paa"",""\Ca\Characters_PMC\Frost\Data\Frost_2_co.paa"",""\Ca\Characters_PMC\Frost\Data\Frost_3_co.paa""] select floor random 3];";
	};
	class Soldier_TL_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\Ca\Characters_PMC\Gracenko\Data\Gracenko_1_co.paa"",""\Ca\Characters_PMC\Gracenko\Data\Gracenko_2_co.paa"",""\Ca\Characters_PMC\Gracenko\Data\Gracenko_3_co.paa"",""\Ca\Characters_PMC\Gracenko\Data\Gracenko_4_co.paa""] select floor random 4];";
	};
	class Soldier_MG_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\Ca\Characters_PMC\Asano\Data\tex1_1_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_2_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_3_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_4_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_5_co.paa""] select floor random 5];(_this select 0) setObjectTexture [1,[""ca\characters_pmc\pmc_soldier\data\headgear_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\HeadGear_1_CO.paa""] select floor random 2];(_this select 0) setObjectTexture [2,[""ca\characters_pmc\asano\data\tex2_co.paa"",""ca\characters_pmc\asano\data\tex2_1_co.paa""] select floor random 2]";
	};
	class Soldier_Sniper_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\Ca\Characters_PMC\PMC_soldier\Data\bauer_2_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\bauer_3_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\bauer_4_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\bauer_5_co.paa""] select floor random 4]; (_this select 0) setObjectTexture [1,[""ca\characters_pmc\pmc_soldier\data\bauer_gear_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\Bauer_Gear_1_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\Bauer_Gear_2_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\Bauer_Gear_3_co.paa""] select floor random 4]; (_this select 0) setObjectTexture [2,[""\Ca\Characters_PMC\PMC_soldier\Data\HeadGear_CO.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\HeadGear_1_CO.paa""] select floor random 2]";
	};
	class Soldier_GL_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\Ca\Characters_PMC\Asano\Data\tex1_1_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_2_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_3_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_4_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_5_co.paa""] select floor random 5];(_this select 0) setObjectTexture [1,[""ca\characters_pmc\pmc_soldier\data\headgear_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\HeadGear_1_CO.paa""] select floor random 2];(_this select 0) setObjectTexture [2,[""ca\characters_pmc\asano\data\tex2_co.paa"",""ca\characters_pmc\asano\data\tex2_1_co.paa""] select floor random 2]";
	};
	class Soldier_Bodyguard_AA12_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""ca\characters_pmc\dixon\data\european-man_02_co.paa"",""ca\characters_pmc\dixon\data\european-man_03_co.paa"",""ca\characters_pmc\dixon\data\european-man_04_co.paa"",""ca\characters_pmc\dixon\data\european-man_05_co.paa""] select floor random 4]; (_this select 0) setObjectTexture [1,[""Ca\Characters_PMC\Dixon\Data\Dix_1_CO.paa"",""Ca\Characters_PMC\Dixon\Data\Dix_2_CO.paa"",""Ca\Characters_PMC\Dixon\Data\Dix_3_CO.paa"",""Ca\Characters_PMC\Dixon\Data\Dix_4_CO.paa"",""Ca\Characters_PMC\Dixon\Data\Dix_4_CO.paa""] select floor random 5]";
	};
	class Soldier_AA_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\Ca\Characters_PMC\Asano\Data\tex1_1_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_2_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_3_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_4_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_5_co.paa""] select floor random 5];(_this select 0) setObjectTexture [1,[""ca\characters_pmc\pmc_soldier\data\headgear_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\HeadGear_1_CO.paa""] select floor random 2];(_this select 0) setObjectTexture [2,[""ca\characters_pmc\asano\data\tex2_co.paa"",""ca\characters_pmc\asano\data\tex2_1_co.paa""] select floor random 2]";
	};
	class Soldier_AT_PMC
	{
		SLX_BIS = "(_this select 0) setObjectTexture [0,[""\Ca\Characters_PMC\Asano\Data\tex1_1_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_2_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_3_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_4_co.paa"",""\Ca\Characters_PMC\Asano\Data\tex1_5_co.paa""] select floor random 5];(_this select 0) setObjectTexture [1,[""ca\characters_pmc\pmc_soldier\data\headgear_co.paa"",""\Ca\Characters_PMC\PMC_soldier\Data\HeadGear_1_CO.paa""] select floor random 2];(_this select 0) setObjectTexture [2,[""ca\characters_pmc\asano\data\tex2_co.paa"",""ca\characters_pmc\asano\data\tex2_1_co.paa""] select floor random 2]";
	};
	class Poet_PMC
	{
		SLX_BIS = "(_this select 0) setidentity ""PMC_Poet""";
	};
	class Ry_PMC
	{
		SLX_BIS = "(_this select 0) setidentity ""PMC_Ry""";
	};
	class Reynolds_PMC
	{
		SLX_BIS = "(_this select 0) setidentity ""PMC_Reynolds_NoGlasses""";
	};
	class Tanny_PMC
	{
		SLX_BIS = "(_this select 0) setidentity ""PMC_Tanny""";
	};
	class Dixon_PMC
	{
		SLX_BIS = "(_this select 0) setidentity ""PMC_Dixon""";
	};
};
class Extended_firedBis_Eventhandlers
{
	class Car
	{
		SLX_BIS_CCP = "_this call BIS_CPP_Muzzle_ForceReload";
	};
	class Tank
	{
		SLX_BIS_CCP = "_this call BIS_CPP_Muzzle_ForceReload";
	};
	class StaticCannon
	{
		SLX_BIS = "_this call BIS_Effects_EH_Fired";
	};
	class M252
	{
		SLX_BIS = "_this call BIS_Effects_EH_Fired";
	};
	class 2b14_82mm
	{
		SLX_BIS = "_this call BIS_Effects_EH_Fired";
	};
	class A10
	{
		SLX_BIS = "_this call BIS_Effects_EH_Fired";
	};
	class Su34
	{
		SLX_BIS = "_this call BIS_Effects_EH_Fired";
	};
};
class Extended_firednear_Eventhandlers
{
	class CAAnimalBase
	{
		SLX_BIS = "_this execFSM ""CA\animals2\Data\scripts\reactFire.fsm""";
	};
};
class Extended_hit_Eventhandlers
{
	class TargetPopUpTarget
	{
		SLX_BIS = "[(_this select 0)] spawn ('ca\misc\scripts\PopUpTarget.sqf' call SLX_XEH_COMPILE)";
	};
	class TargetEpopup
	{
		SLX_BIS = "[(_this select 0)] spawn ('ca\misc\scripts\PopUpTarget.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_killed_Eventhandlers
{
	class A10
	{
		SLX_BIS = "_this call BIS_Effects_EH_Killed";
	};
	class Su34
	{
		SLX_BIS = "_this call BIS_Effects_EH_Killed";
	};
};
class DefaultEventHandlers;
class CfgVehicles
{
	class All
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Static: All
	{
		class EventHandlers{};
	};
	class LandVehicle;
	class Car: LandVehicle
	{
		class Eventhandlers: DefaultEventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Tank: LandVehicle
	{
		class Eventhandlers: DefaultEventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Air;
	class Helicopter: Air
	{
		class Eventhandlers: DefaultEventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Plane: Air
	{
		class Eventhandlers: DefaultEventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class AllVehicles;
	class Ship: AllVehicles
	{
		class Eventhandlers: DefaultEventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class StaticWeapon;
	class StaticCannon: StaticWeapon
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Animal;
	class CAAnimalBase: Animal
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class StaticMortar;
	class M252: StaticMortar
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class 2b14_82mm: StaticMortar
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class SoldierWB;
	class FR_Base: SoldierWB
	{
		class EventHandlers;
	};
	class FR_Miles: FR_Base
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FR_GL: FR_Base
	{
		class EventHandlers;
	};
	class FR_Cooper: FR_GL
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FR_Marksman: FR_Base
	{
		class EventHandlers;
	};
	class FR_Sykes: FR_Marksman
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FR_Corpsman: FR_Base
	{
		class EventHandlers;
	};
	class FR_OHara: FR_Corpsman
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FR_AR: FR_Base
	{
		class EventHandlers;
	};
	class FR_Rodriguez: FR_AR
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Civilian;
	class TK_CIV_Takistani_Base_EP1: Civilian
	{
		class EventHandlers;
	};
	class TK_CIV_Takistani01_EP1: TK_CIV_Takistani_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_CIV_Takistani02_EP1: TK_CIV_Takistani_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_CIV_Takistani03_EP1: TK_CIV_Takistani_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_CIV_Takistani04_EP1: TK_CIV_Takistani_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_CIV_Takistani05_EP1: TK_CIV_Takistani_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_CIV_Takistani06_EP1: TK_CIV_Takistani_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Woman_EP1: Civilian
	{
		class EventHandlers;
	};
	class TK_CIV_Woman01_EP1: Woman_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_CIV_Woman02_EP1: TK_CIV_Woman01_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_CIV_Woman03_EP1: TK_CIV_Woman01_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class CIV_EuroWoman01_EP1: Woman_EP1
	{
		class EventHandlers;
	};
	class Dr_Annie_Baker_EP1: CIV_EuroWoman01_EP1
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class CIV_EuroWoman02_EP1: CIV_EuroWoman01_EP1
	{
		class EventHandlers;
	};
	class Rita_Ensler_EP1: CIV_EuroWoman02_EP1
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class CIV_EuroMan01_EP1: Civilian
	{
		class EventHandlers;
	};
	class Haris_Press_EP1: CIV_EuroMan01_EP1
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class CIV_EuroMan02_EP1: CIV_EuroMan01_EP1
	{
		class EventHandlers;
	};
	class Dr_Hladik_EP1: CIV_EuroMan02_EP1
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class SoldierEB;
	class TK_INS_Soldier_Base_EP1: SoldierEB
	{
		class EventHandlers;
	};
	class TK_INS_Soldier_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Soldier_2_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Soldier_3_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Soldier_4_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Soldier_AA_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Soldier_AT_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Soldier_TL_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Soldier_Sniper_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Soldier_AR_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Soldier_MG_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Bonesetter_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_INS_Warlord_EP1: TK_INS_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class SoldierGB;
	class TK_GUE_Soldier_Base_EP1: SoldierGB
	{
		class EventHandlers;
	};
	class TK_GUE_Soldier_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_2_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_3_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_4_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_5_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_AA_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_AT_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_HAT_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_TL_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_Sniper_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_AR_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Soldier_MG_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Bonesetter_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TK_GUE_Warlord_EP1: TK_GUE_Soldier_Base_EP1
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class HelicopterWreck;
	class AH1ZWreck: HelicopterWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class MH60Wreck: HelicopterWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class PlaneWreck;
	class AV8BWreck: PlaneWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Mi17Wreck: HelicopterWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Land_Fire;
	class Land_Fire_burning: Land_Fire
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Land_Campfire;
	class Land_Campfire_burning: Land_Campfire
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrier;
	class FlagCarrierUSA: FlagCarrier
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierCDF: FlagCarrierUSA
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierRU: FlagCarrierUSA
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierINS: FlagCarrierUSA
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierGUE: FlagCarrierUSA
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierCore;
	class FlagCarrierChecked: FlagCarrierCore
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TargetBase;
	class TargetPopUpTarget: TargetBase
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class TargetEpopup: TargetBase
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Land_Barrack2;
	class Barrack2: Land_Barrack2
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Grave;
	class Mass_grave: Grave
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Tracked_APC;
	class AAV: Tracked_APC
	{
		class EventHandlers: DefaultEventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Pickup_PK_base: Car
	{
		class Eventhandlers;
	};
	class Pickup_PK_TK_GUE_EP1: Pickup_PK_base
	{
		class EventHandlers: Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class A10: Plane
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class A10Wreck: PlaneWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class SU25Wreck: PlaneWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Mi24Wreck: HelicopterWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class F35bWreck: PlaneWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class MQ9PredatorWreck: PlaneWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class MV22Wreck: PlaneWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class C130JWreck: PlaneWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Ka52Wreck: HelicopterWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class UH1YWreck: HelicopterWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Su34: Plane
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class AH6_Base_EP1: Helicopter{};
	class AH6X_EP1: AH6_Base_EP1
	{
		class EventHandlers: DefaultEventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class l39Wreck: PlaneWreck
	{
		class Eventhandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierUNO_EP1: FlagCarrier
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierRedCrystal_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierTFKnight_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierCDFEnsign_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierRedCross_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierUSArmy_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierTKMilitia_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierRedCrescent_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierGermany_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierNATO_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierBIS_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierCzechRepublic_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierPOWMIA_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierBLUFOR_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierOPFOR_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierINDFOR_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierTakistan_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierTakistanKingdom_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierUSA_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierCDF_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierWhite_EP1: FlagCarrierUNO_EP1
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class MQ9PredatorB;
	class CruiseMissile2: MQ9PredatorB
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierIONblack_PMC: FlagCarrier
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class FlagCarrierIONwhite_PMC: FlagCarrierIONblack_PMC
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_Base_PMC: SoldierGB
	{
		class EventHandlers;
	};
	class Soldier_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_Engineer_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_Crew_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_Medic_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_TL_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_MG_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_Sniper_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_GL_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_Bodyguard_AA12_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_AA_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Soldier_AT_PMC: Soldier_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Special_Character_Base_PMC: Soldier_Base_PMC
	{
		class EventHandlers;
	};
	class Poet_PMC: Special_Character_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Ry_PMC: Special_Character_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Reynolds_PMC: Special_Character_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Tanny_PMC: Special_Character_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
	class Dixon_PMC: Special_Character_Base_PMC
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
	};
};
//};
