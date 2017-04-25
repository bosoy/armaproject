////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 14:00:45 2011 : Created on Fri Oct 21 14:00:45 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_wep_impact : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_wep_hit
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAWeapons","CAWeapons2","acex_sm_s_wep_impact"};
		version = "1.12.0.97";
	};
};
class CfgAmmo
{
	class BulletCore;
	class BulletBase: BulletCore
	{
		soundDefault1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete1.wss",0.316228,1,60};
		soundDefault2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete2.wss",0.316228,1,60};
		soundDefault3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete3.wss",0.316228,1,60};
		soundDefault4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete4.wss",0.316228,1,60};
		soundDefault5[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete5.wss",0.316228,1,60};
		soundDefault6[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_rico1.wss",0.316228,1,60};
		soundDefault7[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_rico2.wss",0.316228,1,60};
		soundGroundSoft1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt1.wss",0.0562341,1,60};
		soundGroundSoft2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt2.wss",0.0562341,1,60};
		soundGroundSoft3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt1.wss",0.0562341,0.9,60};
		soundGroundSoft4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt2.wss",0.0562341,0.9,60};
		soundGroundSoft5[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt_rico1.wss",0.0562341,1,60};
		soundGroundSoft6[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt_rico2.wss",0.0562341,1,60};
		soundGroundSoft7[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt_rico3.wss",0.0562341,1,60};
		soundGroundHard1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete1.wss",0.125893,1,80};
		soundGroundHard2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete2.wss",0.125893,1,80};
		soundGroundHard3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete3.wss",0.125893,1,80};
		soundGroundHard4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete4.wss",0.125893,1,80};
		soundGroundHard5[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete5.wss",0.125893,1,80};
		soundGroundHard6[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete6.wss",0.125893,1,80};
		soundGroundHard7[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_rico1.wss",0.125893,1,80};
		soundGroundHard8[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_rico2.wss",0.125893,1,80};
		soundMetal1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metalplate1.wss",0.32,1,80};
		soundMetal2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metalplate2.wss",0.32,1,80};
		soundMetal3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metalplate3.wss",0.32,1,80};
		soundMetal4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metalplate4.wss",0.32,1,80};
		soundMetal5[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metalplate5.wss",0.32,1,80};
		soundMetal6[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico1.wss",0.32,1,80};
		soundMetal7[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico2.wss",0.32,1,80};
		soundMetal8[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico3.wss",0.32,1,80};
		soundIron1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_iron1.wss",0.32,1,80};
		soundIron2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_iron2.wss",0.32,1,80};
		soundIron3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_iron3.wss",0.32,1,80};
		soundIron4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_iron4.wss",0.32,1,80};
		soundIron5[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_iron5.wss",0.32,1,80};
		soundIron6[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico1.wss",0.32,1,80};
		soundIron7[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico2.wss",0.32,1,80};
		soundIron8[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico3.wss",0.32,1,80};
		soundVehiclePlate1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_vehplate1.wss",0.32,1,70};
		soundVehiclePlate2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_vehplate2.wss",0.32,1,70};
		soundVehiclePlate3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_vehplate3.wss",0.32,1,70};
		soundVehiclePlate4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_vehplate4.wss",0.32,1,70};
		soundVehiclePlate5[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_vehplate5.wss",0.32,1,70};
		soundVehiclePlate6[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico1.wss",0.32,1,70};
		soundVehiclePlate7[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico2.wss",0.32,1,70};
		soundVehiclePlate8[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico3.wss",0.32,1,70};
		soundWood1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_wood1.wss",0.32,1,60};
		soundWood2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_wood2.wss",0.32,1,60};
		soundWood3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_wood3.wss",0.32,1,60};
		soundWood4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_wood4.wss",0.32,1,60};
		soundWood5[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_wood5.wss",0.32,1,60};
		soundWood6[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_rico1.wss",0.32,1,60};
		soundWood7[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_rico2.wss",0.32,1,60};
		soundHitBody1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_flesh1.wss",0.02,1,30};
		soundHitBody2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_flesh2.wss",0.02,1,30};
		soundHitBody3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_flesh3.wss",0.02,1,30};
		soundHitBody4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_flesh4.wss",0.02,1,30};
		soundMetalPlate1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metalplate1.wss",0.56,1,80};
		soundMetalPlate2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metalplate2.wss",0.56,1,80};
		soundMetalPlate3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metalplate3.wss",0.56,1,80};
		soundMetalPlate4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metalplate4.wss",0.56,1,80};
		soundMetalPlate5[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metalplate5.wss",0.56,1,80};
		soundMetalPlate6[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico1.wss",0.56,1,80};
		soundMetalPlate7[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico2.wss",0.56,1,80};
		soundMetalPlate8[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_metal_rico3.wss",0.56,1,80};
		soundHitBuilding1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete1.wss",0.251189,1,60};
		soundHitBuilding2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete3.wss",0.251189,1,60};
		soundHitBuilding3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete4.wss",0.251189,1,60};
		soundHitBuilding4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete5.wss",0.251189,1,60};
		soundHitBuilding5[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete6.wss",0.251189,1,60};
		soundHitBuilding6[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt1.wss",0.251189,1,60};
		soundHitBuilding7[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt2.wss",0.251189,1,60};
		soundHitBuilding8[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt1.wss",0.251189,0.9,60};
		soundHitBuilding9[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt2.wss",0.251189,0.9,60};
		soundHitBuilding10[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_rico1.wss",0.251189,1,60};
		soundHitBuilding11[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_rico2.wss",0.251189,1,60};
		soundHitBuilding12[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt_rico2.wss",0.251189,1,60};
		soundHitBuilding13[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_dirt_rico3.wss",0.251189,1,60};
		soundConcrete1[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete1.wss",0.177828,1,70};
		soundConcrete2[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete2.wss",0.177828,1,70};
		soundConcrete3[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete3.wss",0.177828,1,70};
		soundConcrete4[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete4.wss",0.177828,1,70};
		soundConcrete5[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_concrete5.wss",0.177828,1,70};
		soundConcrete6[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_rico1.wss",0.177828,1,70};
		soundConcrete7[] = {"x\acex_sm\addons\s_wep_impact\bullet_hit_rico2.wss",0.177828,1,70};
		hitGroundSoft[] = {"soundGroundSoft1",0.175,"soundGroundSoft2",0.175,"soundGroundSoft3",0.175,"soundGroundSoft4",0.175,"soundGroundSoft5",0.6,"soundGroundSoft6",0.12,"soundGroundSoft7",0.12};
		hitGroundHard[] = {"soundGroundHard1",0.12,"soundGroundHard2",0.12,"soundGroundHard3",0.12,"soundGroundHard4",0.12,"soundGroundHard5",0.12,"soundGroundHard6",0.12,"soundGroundHard7",0.14,"soundGroundHard8",0.14};
		hitMan[] = {"soundHitBody1",0.25,"soundHitBody2",0.25,"soundHitBody3",0.25,"soundHitBody4",0.25};
		hitArmor[] = {"soundVehiclePlate1",0.14,"soundVehiclePlate2",0.14,"soundVehiclePlate3",0.14,"soundVehiclePlate4",0.14,"soundVehiclePlate5",0.14,"soundVehiclePlate6",0.1,"soundVehiclePlate7",0.1,"soundVehiclePlate8",0.1};
		hitIron[] = {"soundIron1",0.14,"soundIron2",0.14,"soundIron3",0.14,"soundIron4",0.14,"soundIron5",0.14,"soundIron6",0.1,"soundIron7",0.1,"soundIron8",0.1};
		hitBuilding[] = {"soundHitBuilding1",0.07,"soundHitBuilding2",0.07,"soundHitBuilding3",0.07,"soundHitBuilding4",0.07,"soundHitBuilding5",0.07,"soundHitBuilding6",0.0875,"soundHitBuilding7",0.0875,"soundHitBuilding8",0.0875,"soundHitBuilding9",0.0875,"soundHitBuilding10",0.075,"soundHitBuilding11",0.075,"soundHitBuilding12",0.075,"soundHitBuilding13",0.075};
		hitWood[] = {"soundWood1",0.14,"soundWood2",0.14,"soundWood3",0.14,"soundWood4",0.14,"soundWood5",0.14,"soundWood6",0.15,"soundWood7",0.15};
		hitConcrete[] = {"soundConcrete1",0.12,"soundConcrete2",0.12,"soundConcrete3",0.12,"soundConcrete4",0.12,"soundConcrete5",0.12,"soundConcrete6",0.12,"soundConcrete7",0.14,"soundConcrete8",0.14};
		hitDefault[] = {"soundDefault1",0.14,"soundDefault2",0.14,"soundDefault3",0.14,"soundDefault4",0.14,"soundDefault5",0.14,"soundDefault6",0.15,"soundDefault7",0.15};
		hitMetal[] = {"soundMetal1",0.14,"soundMetal2",0.14,"soundMetal3",0.14,"soundMetal4",0.14,"soundMetal5",0.14,"soundMetal6",0.1,"soundMetal7",0.1,"soundMetal8",0.1};
		hitMetalplate[] = {"soundMetalPlate1",0.14,"soundMetalPlate2",0.14,"soundMetalPlate3",0.14,"soundMetalPlate4",0.14,"soundMetalPlate5",0.14,"soundMetalPlate6",0.1,"soundMetalPlate7",0.1,"soundMetalPlate8",0.1};
	};
};
//};
