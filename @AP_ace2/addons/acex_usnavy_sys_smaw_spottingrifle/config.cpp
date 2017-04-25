////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 02 21:01:44 2012 : Created on Fri Nov 02 21:01:44 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_sys_smaw_spottingrifle : config.bin{
class CfgPatches
{
	class acex_usnavy_sys_smaw_spottingrifle
	{
		units[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CAWeapons","CAWeapons2","CAWeapons2_SMAW","CAData","acex_usnavy_main"};
		version = "1.14.0.76";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_usnavy_sys_smaw_spottingrifle
		{
			list[] = {"acex_usnavy_sys_smaw_spottingrifle"};
		};
	};
};
class CfgAmmo
{
	class R_SMAW_HEDP;
	class ACE_Rocket_SMAW_spotting: R_SMAW_HEDP
	{
		ace_ap = 0;
		ace_disp = 4;
		ACE_AT_FX = 0;
		ace_at_tracersize = 0.8;
		soundFly[] = {"",1e-008,1};
		soundDefault1[] = {"ca\sounds\weapons\hits\hit_concrete_01",0.316228,1,60};
		soundDefault2[] = {"ca\sounds\weapons\hits\hit_concrete_02",0.316228,1,60};
		soundDefault3[] = {"ca\sounds\weapons\hits\hit_concrete_03",0.316228,1,60};
		soundDefault4[] = {"ca\sounds\weapons\hits\hit_concrete_04",0.316228,1,60};
		soundDefault5[] = {"ca\sounds\weapons\hits\rico_hit_concrete_01",0.316228,1,60};
		soundDefault6[] = {"ca\sounds\weapons\hits\rico_hit_concrete_02",0.316228,1,60};
		soundDefault7[] = {"ca\sounds\weapons\hits\rico_hit_concrete_03",0.316228,1,60};
		soundDefault8[] = {"ca\sounds\weapons\hits\rico_hit_concrete_04",0.316228,1,60};
		soundGroundSoft1[] = {"ca\sounds\weapons\hits\hit_earth_01",0.0562341,1,60};
		soundGroundSoft2[] = {"ca\sounds\weapons\hits\hit_earth_02",0.0562341,1,60};
		soundGroundSoft3[] = {"ca\sounds\weapons\hits\hit_earth_03",0.0562341,1,60};
		soundGroundSoft4[] = {"ca\sounds\weapons\hits\hit_earth_04",0.0562341,1,60};
		soundGroundSoft5[] = {"ca\sounds\weapons\hits\rico_hit_earth_01",0.0562341,1,60};
		soundGroundSoft6[] = {"ca\sounds\weapons\hits\rico_hit_earth_02",0.0562341,1,60};
		soundGroundSoft7[] = {"ca\sounds\weapons\hits\rico_hit_earth_03",0.0562341,1,60};
		soundGroundSoft8[] = {"ca\sounds\weapons\hits\rico_hit_earth_04",0.0562341,1,60};
		soundGroundHard1[] = {"ca\sounds\weapons\hits\hit_concrete_01",0.125893,1,80};
		soundGroundHard2[] = {"ca\sounds\weapons\hits\hit_concrete_02",0.125893,1,80};
		soundGroundHard3[] = {"ca\sounds\weapons\hits\hit_concrete_03",0.125893,1,80};
		soundGroundHard4[] = {"ca\sounds\weapons\hits\hit_concrete_04",0.125893,1,80};
		soundGroundHard5[] = {"ca\sounds\weapons\hits\rico_hit_concrete_01",0.125893,1,80};
		soundGroundHard6[] = {"ca\sounds\weapons\hits\rico_hit_concrete_02",0.125893,1,80};
		soundGroundHard7[] = {"ca\sounds\weapons\hits\rico_hit_concrete_03",0.125893,1,80};
		soundGroundHard8[] = {"ca\sounds\weapons\hits\rico_hit_concrete_04",0.125893,1,80};
		soundMetal1[] = {"ca\sounds\weapons\hits\hit_metalplate_01",0.316228,1,90};
		soundMetal2[] = {"ca\sounds\weapons\hits\hit_metalplate_02",0.316228,1,90};
		soundMetal3[] = {"ca\sounds\weapons\hits\hit_metalplate_03",0.316228,1,90};
		soundMetal4[] = {"ca\sounds\weapons\hits\hit_metalplate_04",0.316228,1,90};
		soundMetal5[] = {"ca\sounds\weapons\hits\hit_metalplate_05",0.316228,1,90};
		soundMetal6[] = {"ca\sounds\weapons\hits\hit_metalplate_06",0.316228,1,90};
		soundMetal7[] = {"ca\sounds\weapons\hits\hit_metalplate_07",0.316228,1,90};
		soundMetal8[] = {"ca\sounds\weapons\hits\hit_metalplate_08",0.316228,1,90};
		soundMetal9[] = {"ca\sounds\weapons\hits\rico_hit_metalplate_01",0.316228,1,90};
		soundMetal10[] = {"ca\sounds\weapons\hits\rico_hit_metalplate_02",0.316228,1,90};
		soundMetal11[] = {"ca\sounds\weapons\hits\rico_hit_metalplate_03",0.316228,1,90};
		soundMetal12[] = {"ca\sounds\weapons\hits\rico_hit_metalplate_04",0.316228,1,90};
		soundGlass1[] = {"ca\sounds\weapons\hits\hit_glass_01",0.177828,1,50};
		soundGlass2[] = {"ca\sounds\weapons\hits\hit_glass_02",0.177828,1,50};
		soundGlass3[] = {"ca\sounds\weapons\hits\hit_glass_03",0.177828,1,50};
		soundGlass4[] = {"ca\sounds\weapons\hits\hit_glass_04",0.177828,1,50};
		soundGlass5[] = {"ca\sounds\weapons\hits\hit_glass_05",0.177828,1,50};
		soundGlass6[] = {"ca\sounds\weapons\hits\hit_glass_06",0.177828,1,50};
		soundGlass7[] = {"ca\sounds\weapons\hits\hit_glass_07",0.177828,1,50};
		soundGlass8[] = {"ca\sounds\weapons\hits\hit_glass_08",0.177828,1,50};
		soundGlass9[] = {"ca\sounds\weapons\hits\hit_glass_09",0.177828,1,50};
		soundGlass10[] = {"ca\sounds\weapons\hits\hit_glass_10",0.177828,1,50};
		soundIron1[] = {"ca\sounds\weapons\hits\hit_iron_01",0.316228,1,90};
		soundIron2[] = {"ca\sounds\weapons\hits\hit_iron_02",0.316228,1,90};
		soundIron3[] = {"ca\sounds\weapons\hits\hit_iron_03",0.316228,1,90};
		soundIron4[] = {"ca\sounds\weapons\hits\hit_iron_04",0.316228,1,90};
		soundIron5[] = {"ca\sounds\weapons\hits\hit_iron_05",0.316228,1,90};
		soundIron6[] = {"ca\sounds\weapons\hits\hit_iron_06",0.316228,1,90};
		soundIron7[] = {"ca\sounds\weapons\hits\hit_iron_07",0.316228,1,90};
		soundIron8[] = {"ca\sounds\weapons\hits\hit_iron_08",0.316228,1,90};
		soundIron9[] = {"ca\sounds\weapons\hits\rico_hit_iron_01",0.316228,1,90};
		soundIron10[] = {"ca\sounds\weapons\hits\rico_hit_iron_02",0.316228,1,90};
		soundIron11[] = {"ca\sounds\weapons\hits\rico_hit_iron_03",0.316228,1,90};
		soundIron12[] = {"ca\sounds\weapons\hits\rico_hit_iron_04",0.316228,1,90};
		soundGlassArmored1[] = {"ca\sounds\weapons\hits\hit_glass_armored_01",0.177828,1,60};
		soundGlassArmored2[] = {"ca\sounds\weapons\hits\hit_glass_armored_02",0.177828,1,60};
		soundGlassArmored3[] = {"ca\sounds\weapons\hits\hit_glass_armored_03",0.177828,1,60};
		soundGlassArmored4[] = {"ca\sounds\weapons\hits\hit_glass_armored_04",0.177828,1,60};
		soundGlassArmored5[] = {"ca\sounds\weapons\hits\hit_glass_armored_05",0.177828,1,60};
		soundGlassArmored6[] = {"ca\sounds\weapons\hits\hit_glass_armored_06",0.177828,1,60};
		soundGlassArmored7[] = {"ca\sounds\weapons\hits\hit_glass_armored_07",0.177828,1,60};
		soundGlassArmored8[] = {"ca\sounds\weapons\hits\hit_glass_armored_08",0.177828,1,60};
		soundVehiclePlate1[] = {"ca\sounds\weapons\hits\hit_vehicle_plate_01",0.562341,1,90};
		soundVehiclePlate2[] = {"ca\sounds\weapons\hits\hit_vehicle_plate_02",0.562341,1,90};
		soundVehiclePlate3[] = {"ca\sounds\weapons\hits\hit_vehicle_plate_03",0.562341,1,90};
		soundVehiclePlate4[] = {"ca\sounds\weapons\hits\hit_vehicle_plate_04",0.562341,1,90};
		soundVehiclePlate5[] = {"ca\sounds\weapons\hits\hit_vehicle_plate_05",0.562341,1,90};
		soundVehiclePlate6[] = {"ca\sounds\weapons\hits\hit_vehicle_plate_06",0.562341,1,90};
		soundVehiclePlate7[] = {"ca\sounds\weapons\hits\hit_vehicle_plate_07",0.562341,1,90};
		soundVehiclePlate8[] = {"ca\sounds\weapons\hits\hit_vehicle_plate_08",0.562341,1,90};
		soundVehiclePlate9[] = {"ca\sounds\weapons\hits\rico_hit_vehicle_plate_01",0.562341,1,90};
		soundVehiclePlate10[] = {"ca\sounds\weapons\hits\rico_hit_vehicle_plate_02",0.562341,1,90};
		soundVehiclePlate11[] = {"ca\sounds\weapons\hits\rico_hit_vehicle_plate_03",0.562341,1,90};
		soundVehiclePlate12[] = {"ca\sounds\weapons\hits\rico_hit_vehicle_plate_04",0.562341,1,90};
		soundWood1[] = {"ca\sounds\weapons\hits\hit_wood_01",0.316228,1,60};
		soundWood2[] = {"ca\sounds\weapons\hits\hit_wood_02",0.316228,1,60};
		soundWood3[] = {"ca\sounds\weapons\hits\hit_wood_03",0.316228,1,60};
		soundWood4[] = {"ca\sounds\weapons\hits\hit_wood_04",0.316228,1,60};
		soundWood5[] = {"ca\sounds\weapons\hits\hit_wood_05",0.316228,1,60};
		soundWood6[] = {"ca\sounds\weapons\hits\hit_wood_06",0.316228,1,60};
		soundWood7[] = {"ca\sounds\weapons\hits\hit_wood_07",0.316228,1,60};
		soundWood8[] = {"ca\sounds\weapons\hits\hit_wood_08",0.316228,1,60};
		soundWood9[] = {"ca\sounds\weapons\hits\rico_hit_wood_01",0.316228,1,60};
		soundWood10[] = {"ca\sounds\weapons\hits\rico_hit_wood_02",0.316228,1,60};
		soundWood11[] = {"ca\sounds\weapons\hits\rico_hit_wood_03",0.316228,1,60};
		soundWood12[] = {"ca\sounds\weapons\hits\rico_hit_wood_04",0.316228,1,60};
		soundHitBody1[] = {"ca\sounds\weapons\hits\hit_body_01",0.0177828,1,50};
		soundHitBody2[] = {"ca\sounds\weapons\hits\hit_body_02",0.0177828,1,50};
		soundHitBody3[] = {"ca\sounds\weapons\hits\hit_body_03",0.0177828,1,50};
		soundHitBody4[] = {"ca\sounds\weapons\hits\hit_body_04",0.0177828,1,50};
		soundHitBody5[] = {"ca\sounds\weapons\hits\hit_body_05",0.0177828,1,50};
		soundHitBody6[] = {"ca\sounds\weapons\hits\hit_body_06",0.0177828,1,50};
		soundHitBody7[] = {"ca\sounds\weapons\hits\hit_body_07",0.0177828,1,50};
		soundHitBody8[] = {"ca\sounds\weapons\hits\hit_body_08",0.0177828,1,50};
		soundHitBody9[] = {"ca\sounds\weapons\hits\hit_body_09",0.0177828,1,50};
		soundHitBody10[] = {"ca\sounds\weapons\hits\hit_body_10",0.0177828,1,50};
		soundHitBody11[] = {"ca\sounds\weapons\hits\hit_body_11",0.0177828,1,50};
		soundHitBody12[] = {"ca\sounds\weapons\hits\hit_body_12",0.0177828,1,50};
		soundHitBody13[] = {"ca\sounds\weapons\hits\hit_body_13",0.0177828,1,50};
		soundMetalPlate1[] = {"ca\sounds\weapons\hits\hit_metalplate_01",0.562341,1,90};
		soundMetalPlate2[] = {"ca\sounds\weapons\hits\hit_metalplate_02",0.562341,1,90};
		soundMetalPlate3[] = {"ca\sounds\weapons\hits\hit_metalplate_03",0.562341,1,90};
		soundMetalPlate4[] = {"ca\sounds\weapons\hits\hit_metalplate_04",0.562341,1,90};
		soundMetalPlate5[] = {"ca\sounds\weapons\hits\hit_metalplate_05",0.562341,1,90};
		soundMetalPlate6[] = {"ca\sounds\weapons\hits\hit_metalplate_06",0.562341,1,90};
		soundMetalPlate7[] = {"ca\sounds\weapons\hits\hit_metalplate_07",0.562341,1,90};
		soundMetalPlate8[] = {"ca\sounds\weapons\hits\hit_metalplate_08",0.562341,1,90};
		soundMetalPlate9[] = {"ca\sounds\weapons\hits\rico_hit_metalplate_01",0.562341,1,90};
		soundMetalPlate10[] = {"ca\sounds\weapons\hits\rico_hit_metalplate_02",0.562341,1,90};
		soundMetalPlate11[] = {"ca\sounds\weapons\hits\rico_hit_metalplate_03",0.562341,1,90};
		soundMetalPlate12[] = {"ca\sounds\weapons\hits\rico_hit_metalplate_04",0.562341,1,90};
		soundHitBuilding1[] = {"ca\sounds\weapons\hits\hit_wall_01",0.251189,1,60};
		soundHitBuilding2[] = {"ca\sounds\weapons\hits\hit_wall_02",0.251189,1,60};
		soundHitBuilding3[] = {"ca\sounds\weapons\hits\hit_wall_03",0.251189,1,60};
		soundHitBuilding4[] = {"ca\sounds\weapons\hits\hit_wall_04",0.251189,1,60};
		soundHitBuilding5[] = {"ca\sounds\weapons\hits\hit_wall_05",0.251189,1,60};
		soundHitBuilding6[] = {"ca\sounds\weapons\hits\rico_hit_wall_01",0.251189,1,60};
		soundHitBuilding7[] = {"ca\sounds\weapons\hits\rico_hit_wall_02",0.251189,1,60};
		soundHitBuilding8[] = {"ca\sounds\weapons\hits\rico_hit_wall_03",0.251189,1,60};
		soundHitBuilding9[] = {"ca\sounds\weapons\hits\rico_hit_wall_04",0.251189,1,60};
		soundHitBuilding10[] = {"ca\sounds\weapons\hits\rico_hit_wall_05",0.251189,1,60};
		soundHitFoliage1[] = {"ca\sounds\weapons\hits\hit_grass_01",0.177828,1,50};
		soundHitFoliage2[] = {"ca\sounds\weapons\hits\hit_grass_02",0.177828,1,50};
		soundHitFoliage3[] = {"ca\sounds\weapons\hits\hit_grass_03",0.177828,1,50};
		soundHitFoliage4[] = {"ca\sounds\weapons\hits\hit_grass_04",0.177828,1,50};
		soundPlastic1[] = {"ca\sounds\weapons\hits\hit_Rubber_01",0.177828,1,50};
		soundPlastic2[] = {"ca\sounds\weapons\hits\hit_Rubber_02",0.177828,1,50};
		soundConcrete1[] = {"ca\sounds\weapons\hits\hit_concrete_01",0.177828,1,70};
		soundConcrete2[] = {"ca\sounds\weapons\hits\hit_concrete_02",0.177828,1,70};
		soundConcrete3[] = {"ca\sounds\weapons\hits\hit_concrete_03",0.177828,1,70};
		soundConcrete4[] = {"ca\sounds\weapons\hits\hit_concrete_04",0.177828,1,70};
		soundConcrete5[] = {"ca\sounds\weapons\hits\rico_hit_concrete_01",0.177828,1,70};
		soundConcrete6[] = {"ca\sounds\weapons\hits\rico_hit_concrete_02",0.177828,1,70};
		soundConcrete7[] = {"ca\sounds\weapons\hits\rico_hit_concrete_03",0.177828,1,70};
		soundConcrete8[] = {"ca\sounds\weapons\hits\rico_hit_concrete_04",0.177828,1,70};
		soundRubber1[] = {"ca\sounds\weapons\hits\hit_Rubber_01",0.316228,1,50};
		soundRubber2[] = {"ca\sounds\weapons\hits\hit_Rubber_02",0.316228,1,50};
		soundRubber3[] = {"ca\sounds\weapons\hits\hit_Rubber_03",0.316228,1,50};
		soundRubber4[] = {"ca\sounds\weapons\hits\hit_Rubber_04",0.316228,1,50};
		soundRubber5[] = {"ca\sounds\weapons\hits\hit_Rubber_05",0.316228,1,50};
		hitGroundSoft[] = {"soundGroundSoft1",0.2,"soundGroundSoft2",0.2,"soundGroundSoft3",0.1,"soundGroundSoft4",0.1,"soundGroundSoft5",0.1,"soundGroundSoft6",0.1,"soundGroundSoft7",0.1,"soundGroundSoft8",0.1};
		hitGroundHard[] = {"soundGroundHard1",0.2,"soundGroundHard2",0.2,"soundGroundHard3",0.1,"soundGroundHard4",0.1,"soundGroundHard5",0.1,"soundGroundHard6",0.1,"soundGroundHard7",0.1,"soundGroundHard8",0.1};
		hitMan[] = {"soundHitBody1",0.077,"soundHitBody2",0.077,"soundHitBody3",0.077,"soundHitBody4",0.077,"soundHitBody5",0.077,"soundHitBody6",0.077,"soundHitBody7",0.077,"soundHitBody8",0.077,"soundHitBody9",0.077,"soundHitBody10",0.077,"soundHitBody11",0.077,"soundHitBody12",0.077,"soundHitBody13",0.077};
		hitArmor[] = {"soundVehiclePlate1",0.1,"soundVehiclePlate2",0.1,"soundVehiclePlate3",0.05,"soundVehiclePlate4",0.05,"soundVehiclePlate5",0.1,"soundVehiclePlate6",0.05,"soundVehiclePlate7",0.1,"soundVehiclePlate8",0.1,"soundVehiclePlate9",0.05,"soundVehiclePlate10",0.1,"soundVehiclePlate11",0.1,"soundVehiclePlate12",0.1};
		hitIron[] = {"soundIron1",0.1,"soundIron2",0.1,"soundIron3",0.1,"soundIron4",0.1,"soundIron5",0.1,"soundIron6",0.1,"soundIron7",0.05,"soundIron8",0.05,"soundIron9",0.1,"soundIron10",0.1,"soundIron11",0.05,"soundIron12",0.05};
		hitBuilding[] = {"soundHitBuilding1",0.1,"soundHitBuilding2",0.1,"soundHitBuilding3",0.1,"soundHitBuilding4",0.1,"soundHitBuilding5",0.1,"soundHitBuilding6",0.1,"soundHitBuilding7",0.1,"soundHitBuilding8",0.1,"soundHitBuilding9",0.1,"soundHitBuilding10",0.1};
		hitFoliage[] = {"soundHitFoliage1",0.25,"soundHitFoliage2",0.25,"soundHitFoliage3",0.25,"soundHitFoliage4",0.25};
		hitWood[] = {"soundWood1",0.1,"soundWood2",0.1,"soundWood3",0.1,"soundWood4",0.05,"soundWood5",0.05,"soundWood6",0.1,"soundWood7",0.1,"soundWood8",0.1,"soundWood9",0.1,"soundWood10",0.1,"soundWood11",0.05,"soundWood12",0.05};
		hitGlass[] = {"soundGlass1",0.1,"soundGlass2",0.1,"soundGlass3",0.1,"soundGlass4",0.1,"soundGlass5",0.1,"soundGlass6",0.1,"soundGlass7",0.1,"soundGlass8",0.1,"soundGlass9",0.1,"soundGlass10",0.1};
		hitGlassArmored[] = {"soundGlassArmored1",0.125,"soundGlassArmored2",0.125,"soundGlassArmored3",0.125,"soundGlassArmored4",0.125,"soundGlassArmored5",0.125,"soundGlassArmored6",0.125,"soundGlassArmored7",0.125,"soundGlassArmored8",0.125};
		hitConcrete[] = {"soundConcrete1",0.2,"soundConcrete2",0.2,"soundConcrete3",0.2,"soundConcrete4",0.05,"soundConcrete5",0.05,"soundConcrete6",0.1,"soundConcrete7",0.1,"soundConcrete8",0.1};
		hitRubber[] = {"soundRubber1",0.2,"soundRubber2",0.2,"soundRubber3",0.2,"soundRubber4",0.2,"soundRubber5",0.2};
		hitPlastic[] = {"soundPlastic1",0.5,"soundPlastic2",0.5};
		hitDefault[] = {"soundDefault1",0.2,"soundDefault2",0.2,"soundDefault3",0.1,"soundDefault4",0.1,"soundDefault5",0.1,"soundDefault6",0.1,"soundDefault7",0.1,"soundDefault8",0.1};
		hitMetal[] = {"soundMetal1",0.1,"soundMetal2",0.1,"soundMetal3",0.1,"soundMetal4",0.05,"soundMetal5",0.1,"soundMetal6",0.1,"soundMetal7",0.05,"soundMetal8",0.1,"soundMetal9",0.05,"soundMetal10",0.05,"soundMetal11",0.1,"soundMetal12",0.1};
		hitMetalplate[] = {"soundMetalPlate1",0.1,"soundMetalPlate2",0.1,"soundMetalPlate3",0.1,"soundMetalPlate4",0.05,"soundMetalPlate5",0.05,"soundMetalPlate6",0.05,"soundMetalPlate7",0.1,"soundMetalPlate8",0.1,"soundMetalPlate9",0.1,"soundMetalPlate10",0.1,"soundMetalPlate11",0.1,"soundMetalPlate12",0.05};
		bulletFly1[] = {"ca\sounds\weapons\hits\bullet_by1",1,1,50};
		bulletFly2[] = {"ca\sounds\weapons\hits\bullet_by2",1,1,50};
		bulletFly3[] = {"ca\sounds\weapons\hits\bullet_by3",1,1,50};
		bulletFly4[] = {"ca\sounds\weapons\hits\bullet_by4",1,1,50};
		bulletFly5[] = {"ca\sounds\weapons\hits\bullet_by5",1,1,50};
		bulletFly6[] = {"ca\sounds\weapons\hits\bullet_by6",1,1,50};
		bulletFly[] = {"bulletFly1",0.166,"bulletFly2",0.166,"bulletFly3",0.166,"bulletFly4",0.166,"bulletFly5",0.166,"bulletFly6",0.167};
		supersonicCrackNear[] = {"Ca\sounds\Weapons\explosions\supersonic_crack_close",1,1,150};
		supersonicCrackFar[] = {"Ca\sounds\Weapons\explosions\supersonic_crack_50meters",1,1,250};
		class HitEffects
		{
			Hit_Foliage = "ImpactLeaves";
			Hit_Glass = "ImpactGlass";
			Hit_Glass_Thin = "ImpactGlassThin";
			Hit_Wood = "ImpactWood";
			Hit_Metal = "ImpactMetal";
			Hit_Plaster = "ImpactPlaster";
			Hit_Rubber = "ImpactRubber";
			Hit_Concrete = "ImpactConcrete";
			Hit_Blood = "ImpactBlood";
		};
		muzzleEffect = "BIS_Effects_Rifle";
		cartridge = "FxCartridge";
		hit = 8;
		ace_hit = 3;
		indirectHit = 0;
		indirectHitRange = 0;
		tracerColor[] = {0.8,0.8,0.1,0.04};
		tracerColorR[] = {0.8,0.8,0.1,0.04};
		model = "\x\acex_usnavy\addons\sys_smaw_spottingrifle\ace_smaw_spotting_round";
		deflecting = 10;
		tracerScale = 1;
		tracerStartTime = 0.05;
		tracerEndTime = 1;
		explosive = 0;
		cost = 10;
		visibleFire = 18;
		audibleFire = 3;
		visibleFireTime = 3;
		whistleDist = 0;
		whistleOnFire = 0;
		explosionEffects = "ExplosionEffects";
		craterEffects = "ImpactEffectsBig";
		effectsMissile = "ACE_SMAW_SPOTTING";
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class SMAW: CA_Magazine{};
	class ACE_SMAW_Spotting: SMAW
	{
		scope = 2;
		reloadAction = "ManActReloadMagazine";
		picture = "\x\acex_usnavy\addons\sys_smaw_spottingrifle\data\equip\m_smaw_spotting_ca.paa";
		type = 16;
		ammo = "ACE_Rocket_SMAW_spotting";
		count = 5;
		initspeed = 325;
		displayName = "$STR_DN_ACE_SMAW_SPOTTINGMAG";
		descriptionShort = "$STR_DN_ACE_SMAW_SPOTTINGMAG";
		sound[] = {"\ca\Weapons\Data\Sound\Beretta_single_shot_v3",0.316228,1,700};
		model = "\x\acex_usnavy\addons\sys_smaw_spottingrifle\ace_smaw_spotting.p3d";
	};
};
class CfgWeapons
{
	class Launcher;
	class SMAW: Launcher
	{
		displayName = "Mk153 Mod 0 SMAW";
		reloadMagazineSound[] = {"\x\acex_usnavy\addons\sys_smaw_spottingrifle\smaw_reload.wss",0.000316228,1,20};
		Sound[] = {"\x\acex_usnavy\addons\sys_smaw_spottingrifle\smaw_fire.wss",10,1,2700};
		muzzles[] = {"this","SpottingRifle"};
		class Spottingrifle: Launcher
		{
			displayname = "$STR_DN_ACE_SMAW_SPOTTINGRIFLE";
			useAction = 1;
			useActionTitle = "$STR_DN_ACE_SMAW_SPOTTINGRIFLE";
			modelOptics = "\ca\weapons\optika_TOW";
			modelSpecial = "";
			minRange = 20;
			midRange = 250;
			maxRange = 500;
			aiRateOfFire = 10;
			aiRateOfFireDistance = 250;
			opticsPPEffects[] = {"OpticsCHAbera3","OpticsBlur3"};
			opticsZoomMin = 0.0625;
			opticsZoomMax = 0.0625;
			distanceZoomMin = 100;
			distanceZoomMax = 100;
			magazines[] = {"ACE_SMAW_Spotting"};
			reloadtime = 0.3;
			begin1[] = {"\x\acex_usnavy\addons\sys_smaw_spottingrifle\spottingrifle_fire.wss",0.001,1.09,150};
			begin2[] = {"\x\acex_usnavy\addons\sys_smaw_spottingrifle\spottingrifle_fire.wss",0.001,1,150};
			begin3[] = {"\x\acex_usnavy\addons\sys_smaw_spottingrifle\spottingrifle_fire.wss",0.001,0.93,150};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			drySound[] = {"\ca\Weapons\Data\Sound\T33_dry_v1",0.01,1,20};
			reloadMagazineSound[] = {"\ca\Weapons\Data\Sound\pistol_reload",0.1,1,20};
			recoil = "recoil_single_pistol_prone_3outof3";
		};
	};
};
class CfgCloudlets
{
	class Default;
	class ACE_SMAW_SPOTTING: Default
	{
		interval = "0";
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		angleVar = 1;
		particleFSLoop = 0;
		particleShape = "\ca\Data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0;
		moveVelocity[] = {0,0,0};
		rotationVelocity = 1;
		weight = 1;
		volume = 0.8;
		rubbing = 0.5;
		size[] = {0,0,0};
		color[] = {{0.3,0.3,0.3,0.35},{0.4,0.4,0.4,0.1},{0.8,0.8,0.8,0}};
		animationSpeed[] = {1};
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.1;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 1;
		positionVar[] = {0.3,0.3,0.3};
		MoveVelocityVar[] = {1,1,1};
		rotationVelocityVar = 1;
		sizeVar = 0.4;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
};
class ACE_SMAW_SPOTTING
{
	class Light1
	{
		simulation = "light";
		type = "RocketLight";
		position[] = {0,0,0};
		intensity = 0;
		interval = 0;
		lifeTime = 0;
	};
	class MissileEffects1
	{
		simulation = "particles";
		type = "ACE_SMAW_SPOTTING";
		position[] = {0,0,0};
		intensity = 0;
		interval = 0;
		lifeTime = 0;
	};
};
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class UserActions
		{
			class ACE_SMAWSpottingRifle
			{
				displayName = "$STR_DN_ACE_SMAW_SPOTTINGRIFLE";
				position = "pilot";
				radius = 2;
				condition = "this == player && {('SMAW' in (weapons this))} && {((currentWeapon this) == 'SMAW')}";
				statement = "this selectWeapon 'SpottingRifle'";
				onlyForPlayer = 1;
				priority = -2;
			};
		};
	};
};
//};
