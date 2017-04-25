//////////////////////////////
//    Dynamic-AI-Creator    //
//    Version 2.1 - 2009    //
//--------------------------//
//    DAC_Config_Units      //
//--------------------------//
//    Script by Silola      //
//    silola@freenet.de     //
//////////////////////////////

private [
			"_TypNumber","_TempArray",
			"_Unit_Pool_S","_Unit_Pool_V","_Unit_Pool_T","_Unit_Pool_A"
		];

			_TypNumber = _this select 0;_TempArray = [];

switch (_TypNumber) do
{
// DEFAULT - ID corresponds to a side ID (0-3)
// TODO: These can be changed to OA Units
//-------------------------------------------------------------------------------------------------------
	case 0:
	{
		_Unit_Pool_S = 	[

							"RU_Soldier_Crew","RU_Soldier_Pilot","RU_Soldier_SL","RU_Soldier","RU_Soldier_GL",
							"RU_Soldier_MG","RU_Soldier2","RU_Soldier_Medic","RU_Soldier_AT",
							"RU_Soldier_Sniper","RU_Soldier_AR","RU_Soldier_Marksman",
							"RUS_Soldier_Sab","RUS_Soldier_Marksman"
					];
		_Unit_Pool_V = 	[	"UAZMG","UralOpen_INS","UAZ_RU","UAZ_AGS30_RU","BRDM2_INS","UAZ_MG_INS","GAZ_Vodnik_HMG","GAZ_Vodnik"];
		_Unit_Pool_T = 	[	"T72_RU","ZSU_INS","BMP3","2S6M_Tunguska","T90","BMP3","BTR90"];
		_Unit_Pool_A = 	[	"Mi17_rockets_RU","Ka52","Mi24_V","Mi24_P"];
	};
//-------------------------------------------------------------------------------------------------
	case 1:
	{
		_Unit_Pool_S = 	[
							"USMC_Soldier_Crew","USMC_Soldier_Pilot","USMC_Soldier_SL","USMC_Soldier_HAT",
							"USMC_Soldier_AR","USMC_Soldier_Medic","USMC_Soldier_MG","USMC_Soldier_GL",
							"USMC_Soldier_AT","USMC_Soldier_LAT","USMC_SoldierS_Sniper","USMC_SoldierS_SniperH","USMC_SoldierS_Spotter",
							"USMC_SoldierS_Engineer","USMC_SoldierM_Marksman","USMC_Soldier_TL","USMC_Soldier_MG"
					];
		_Unit_Pool_V = 	[	"HMMWV","HMMWV_M2","MTVR","HMMWV_MK19","HMMWV_Armored","MTVR","LAV25","HMMWV_TOW","HMMWV_Avenger"];
		_Unit_Pool_T =	[	"M1A1","LAV25","M1A2_TUSK_MG","MLRS","AAV"];
		_Unit_Pool_A = 	[	"AH1Z","UH1Y","MH60S"];
	};
//-------------------------------------------------------------------------------------------------
	case 2:
	{
		_Unit_Pool_S = 	[
							"GUE_Soldier_Crew","GUE_Soldier_Pilot","GUE_Soldier_CO","GUE_Soldier_Medic",
							"GUE_Soldier_1","GUE_Soldier_2","GUE_Soldier_3","GUE_Soldier_AR","GUE_Soldier_MG",
							"GUE_Soldier_AT","GUE_Soldier_AA","GUE_Soldier_GL",
							"GUE_Soldier_Sniper","GUE_Soldier_Sab","GUE_Soldier_Scout"
					];
		_Unit_Pool_V = 	[	"Offroad_DSHKM_INS","Pickup_PK_INS","UAZ_INS","UAZ_AGS30_INS","UAZ_MG_INS","UAZ_SPG9_INS","Ural_INS","UralOpen_INS","Ural_ZU23_INS"];
		_Unit_Pool_T = 	[	"BMP2_INS","BRDM2_INS","BRDM2_ATGM_INS","T72_INS","ZSU_INS"];
		_Unit_Pool_A = 	[	"Mi17_MG","Ka52","Mi17_MG","Mi24_V","Mi24_D","mi171_Sh","Mi17","Mi24_P","Mi_8T_Hip_C"];
	};
//-------------------------------------------------------------------------------------------------
	case 3:
	{
		_Unit_Pool_S = 	[
							"Citizen1","Citizen2","Citizen3","Citizen4",
							"Woodlander1","Woodlander2","Woodlander3","Woodlander4",
							"Profiteer1","Profiteer2","Profiteer3","Profiteer4",
							"Rocker1","Rocker2","Rocker3","Rocker4",
							"Woodlander1","Woodlander2","Woodlander3","Woodlander4",
							"Villager1","Villager2","Villager3","Villager4"
					];
		_Unit_Pool_V = 	[	"datsun1_civil_2_covered","hilux1_civil_1_open","UralCivil","SkodaBlue","Bus_city","car_sedan","SkodaRed","Skoda","SkodaGreen","datsun1_civil_3_open","car_hatchback"];
		_Unit_Pool_T = 	[	"Tractor","UralCivil","	UralCivil2"];
		_Unit_Pool_A = 	[];
	};


// CUSTOM - Start at 1000 - East, 1100 - West, 1200 - Guer, 1300 - Civ
//--------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------(RUSSIAN ARMY)------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1000:
	{
		_Unit_Pool_S = 	[
							"RU_Soldier_Crew","RU_Soldier_Pilot","RU_Soldier_Officer","RU_Commander",
							"RU_Soldier","RU_Soldier2","RU_Soldier_GL","RU_Soldier_SL","RU_Soldier_MG",
							"RU_Soldier_Medic","RU_Soldier_AR","RU_Soldier_AT","RU_Soldier_HAT",
							"RU_Soldier_LAT","RU_Soldier_AA","RU_Soldier_TL","RU_Soldier_Marksman",

							"MVD_Soldier_TL","MVD_Soldier_MG","MVD_Soldier","MVD_Soldier_GL",
							"MVD_Soldier_Marksman","MVD_Soldier_Sniper","MVD_Soldier_AT",

							"RUS_Soldier1","RUS_Soldier2","RUS_Soldier3","RUS_Soldier_GL","RUS_Commander","RUS_Soldier_TL"
				];

		_Unit_Pool_V = 	[	"UAZ_RU","UAZMG","UAZ_AGS30_RU","Kamaz","KamazOpen","KamazRepair","KamazReammo","KamazRefuel",
							"GAZ_Vodnik","GAZ_Vodnik_HMG","GAZ_Vodnik_MedEvac","BTR90","BTR90_HQ"
				];
		_Unit_Pool_T = 	[	"BMP3","T72_RU","T90","2S6M_Tunguska"
				];
		_Unit_Pool_A = 	[	"Mi17_rockets_RU","Mi17_medevac_RU","Ka52","Ka52Black","Mi24_V","Mi24_P"
				];
		_Unit_Pool_U =  [  	"RU_Soldier_Light","RU_Soldier_Spotter","Su34","Su39","RU_Soldier_Sniper","RU_Soldier_SniperH","RUS_Soldier_Marksman","GRAD_RU"];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------(TAKISTANI ARMY)-------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1001:
	{
		_Unit_Pool_S = 	[
							"TK_Soldier_Crew_EP1","TK_Soldier_Pilot_EP1","TK_Soldier_AR_EP1",
							"TK_Soldier_AA_EP1","TK_Soldier_GL_EP1","TK_Soldier_Engineer_EP1",
							"TK_Commander_EP1","TK_Soldier_MG_EP1","TK_Soldier_Officer_EP1",
							"TK_Soldier_HAT_EP1","TK_Soldier_Medic_EP1","TK_Soldier_EP1",
							"TK_Soldier_LAT_EP1","TK_Soldier_AT_EP1","TK_Soldier_B_EP1",
							"TK_Soldier_Night_1_EP1","TK_Soldier_Night_2_EP1","TK_Soldier_TWS_EP1",
							"TK_Soldier_SL_EP1","TK_Soldier_AMG_EP1","TK_Soldier_AAT_EP1",

							"TK_Special_Forces_MG_EP1","TK_Special_Forces_EP1","TK_Special_Forces_TL_EP1"
				];
		_Unit_Pool_V = 	[	"LandRover_MG_TK_EP1","V3S_TK_EP1","SUV_TK_EP1","UAZ_Unarmed_TK_EP1","UAZ_AGS30_TK_EP1",
							"UAZ_MG_TK_EP1","V3S_Open_TK_EP1","Ural_ZU23_TK_EP1","UralSupply_TK_EP1","M113Ambul_TK_EP1",
							"UralSalvage_TK_EP1","UralReammo_TK_EP1","UralRepair_TK_EP1","UralRefuel_TK_EP1",
							"BRDM2_TK_EP1","BRDM2_ATGM_TK_EP1","BTR60_TK_EP1"
				];
		_Unit_Pool_T = 	[	"BMP2_TK_EP1","BMP2_HQ_TK_EP1","M113_TK_EP1","T34_TK_EP1","T55_TK_EP1","T72_TK_EP1","ZSU_TK_EP1"
				];
		_Unit_Pool_A = 	[	"Mi24_D_TK_EP1","Mi17_TK_EP1","UH1H_TK_EP1"
				];
		_Unit_Pool_U =  [  	"TK_Aziz_EP1","TK_Soldier_Sniper_EP1","TK_Soldier_SniperH_EP1","TK_Soldier_Sniper_Night_EP1",
							"TK_Soldier_Spotter_EP1","MAZ_543_SCUD_TK_EP1","GRAD_TK_EP1","TT650_TK_EP1","An2_TK_EP1",
							"L39_TK_EP1","Su25_TK_EP1"];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------(US ARMY DESERT CAMO)-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1100:
	{
		_Unit_Pool_S = 	[
							"US_Soldier_Crew_EP1","US_Soldier_Pilot_EP1","US_Soldier_AR_EP1",
							"US_Soldier_AA_EP1","US_Soldier_GL_EP1","US_Soldier_Engineer_EP1",
							"US_Soldier_MG_EP1","US_Soldier_Officer_EP1","US_Soldier_HAT_EP1",
							"US_Soldier_AT_EP1","US_Soldier_Medic_EP1","US_Soldier_EP1",
							"US_Soldier_LAT_EP1","US_Soldier_B_EP1","US_Soldier_TL_EP1",
							"US_Soldier_SL_EP1","US_Soldier_AAR_EP1","US_Soldier_AMG_EP1",
							"US_Soldier_AAT_EP1","US_Soldier_AHAT_EP1"
				];

		_Unit_Pool_V =	[	"HMMWV_DES_EP1","HMMWV_MK19_DES_EP1","HMMWV_TOW_DES_EP1","HMMWV_Avenger_DES_EP1",
							"HMMWV_M998_crows_M2_DES_EP1","HMMWV_M998_crows_MK19_DES_EP1","HMMWV_M1151_M2_DES_EP1",
							"HMMWV_M998A2_SOV_DES_EP1","HMMWV_Terminal_EP1","HMMWV_M1035_DES_EP1",
							"MTVR_DES_EP1","M1130_CV_EP1","M1129_MC_EP1","M1128_MGS_EP1","M1135_ATGMV_EP1",
							"M1126_ICV_M2_EP1","M1126_ICV_mk19_EP1","MtvrSupply_DES_EP1","HMMWV_Ambulance_DES_EP1",
							"MtvrReammo_DES_EP1","MtvrRefuel_DES_EP1","MtvrRepair_DES_EP1","MtvrSalvage_DES_EP1","M1133_MEV_EP1"
				];
		_Unit_Pool_T = 	[	"M1A1_US_DES_EP1","M1A2_US_TUSK_MG_EP1","M2A2_EP1","M2A3_EP1","M6_EP1"
				];
		_Unit_Pool_A = 	[	"AH64D_EP1","AH6J_EP1","AH6X_EP1","CH_47F_EP1","MH6J_EP1","UH60M_EP1","UH60M_MEV_EP1"
				];
		_Unit_Pool_U =  [  	"US_Pilot_Light_EP1","US_Soldier_Marksman_EP1","US_Soldier_Sniper_EP1",
							"US_Soldier_SniperH_EP1","US_Soldier_Light_EP1","US_Soldier_Spotter_EP1",
							"A10_US_EP1","C130J_US_EP1","MQ9PredatorB_US_EP1","MLRS_DES_EP1","ATV_US_EP1",
							"M1030_US_DES_EP1"];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------(US MARINE CORPS WOODLAND CAMO)-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1101:
	{
		_Unit_Pool_S = 	[
							"USMC_Soldier_Crew","USMC_Soldier_Pilot","USMC_Soldier_SL","USMC_Soldier_HAT",
							"USMC_Soldier_AR","USMC_Soldier_Medic","USMC_Soldier_MG","USMC_Soldier_GL",
							"USMC_Soldier_AA","USMC_Soldier_AT","USMC_Soldier_LAT","USMC_SoldierS",
							"USMC_Soldier","USMC_Soldier2","USMC_SoldierS_Engineer","USMC_SoldierM_Marksman",
							"USMC_Soldier_TL","USMC_Soldier_MG",

							"FR_Commander","FR_TL","FR_AC","FR_GL","FR_AR","FR_R","FR_Corpsman",
							"FR_Marksman","FR_Sapper","FR_Assault_R","FR_Assault_GL"
				];
		_Unit_Pool_V = 	[	"HMMWV","HMMWV_M2","MTVR","HMMWV_MK19","HMMWV_Armored","MTVR","LAV25","LAV25_HQ","HMMWV_TOW",
							"HMMWV_Avenger","HMMWV_Ambulance","MtvrReammo","MtvrRepair","MtvrRefuel"
				];
		_Unit_Pool_T =	[	"M1A1","M1A2_TUSK_MG","AAV"
				];
		_Unit_Pool_A = 	[	"AH1Z","UH1Y","MH60S","AH64D"
				];
		_Unit_Pool_U =  [  	"USMC_Soldier_Officer","USMC_SoldierS_Sniper","USMC_SoldierS_SniperH","USMC_SoldierS_Spotter",
							"USMC_Soldier_Light","A10","AV8B2","AV8B","C130J","F35B","MQ9PredatorB","MV22","MLRS","M1030",
							"MMT_USMC","TowingTractor","FR_Light"];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------(GERMAN KSK DESERT CAMO)-----------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1102:
	{
		_Unit_Pool_S = 	[
							"GER_Soldier_MG_EP1","GER_Soldier_Medic_EP1","GER_Soldier_EP1",
							"GER_Soldier_TL_EP1","GER_Soldier_Scout_EP1"
				];
		_Unit_Pool_V = 	[];
		_Unit_Pool_T = 	[];
		_Unit_Pool_A = 	[];
		_Unit_Pool_U =  [];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------(US ARMY DELTA FORCE)-----------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1103:
	{
		_Unit_Pool_S = 	[
							"US_Delta_Force_AR_EP1","US_Delta_Force_Air_Controller_EP1","US_Delta_Force_MG_EP1",
							"US_Delta_Force_EP1","US_Delta_Force_Assault_EP1","US_Delta_Force_M14_EP1",
							"US_Delta_Force_Night_EP1","US_Delta_Force_SD_EP1","US_Delta_Force_Medic_EP1",
							"US_Delta_Force_Marksman_EP1","US_Delta_Force_TL_EP1"
				];
		_Unit_Pool_V = 	[];
		_Unit_Pool_T = 	[];
		_Unit_Pool_A = 	[];
		_Unit_Pool_U =  [];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------(CHERNARUSSIAN DEFENCE FORCE)------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1200:
	{
		_Unit_Pool_S = 	[
							"CDF_Soldier_Crew","CDF_Soldier_Pilot","CDF_Soldier_Officer","CDF_Commander",
							"CDF_Soldier_SL","CDF_Soldier_GL","CDF_Soldier_AR","CDF_Soldier_Strela",
							"CDF_Soldier_MG","CDF_Soldier_Militia","CDF_Soldier_RPG","CDF_Soldier_Engineer",
							"CDF_Soldier_Medic","CDF_Soldier","CDF_Soldier_TL"
				];
		_Unit_Pool_V = 	[	"UAZ_CDF","UAZ_AGS30_CDF","UAZ_MG_CDF","Ural_CDF","UralOpen_CDF","UralReammo_CDF","UralRepair_CDF",
							"UralRefuel_CDF","Ural_ZU23_CDF","BRDM2_CDF","BRDM2_ATGM_CDF"
				];
		_Unit_Pool_T = 	[	"BMP2_CDF","BMP2_HQ_CDF","T72_CDF","ZSU_CDF","BMP2_Ambul_CDF"
				];
		_Unit_Pool_A = 	[	"Mi17_CDF","Mi24_D","Mi17_medevac_CDF"
				];
		_Unit_Pool_U =  [  	"CDF_Soldier_Spotter","CDF_Soldier_Light","CDF_Soldier_Sniper","CDF_Soldier_Marksman","Su25_CDF","GRAD_CDF"];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------(CHEDAKI INSURGENTS)----------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1201:
	{
		_Unit_Pool_S = 	[
							"Ins_Soldier_Crew","Ins_Soldier_Pilot","Ins_Soldier_GL","Ins_Commander","Ins_Soldier_AR",
							"Ins_Soldier_AA","Ins_Soldier_MG","Ins_Soldier_CO","Ins_Soldier_AT","Ins_Soldier_Sab",
							"Ins_Soldier_Medic","Ins_Soldier_Sapper","Ins_Soldier_1","Ins_Soldier_2","Ins_Soldier_Sniper",
							"Ins_Villager3","Ins_Villager4","Ins_Worker2","Ins_Woodlander3","Ins_Woodlander1","Ins_Woodlander2"
				];
		_Unit_Pool_V = 	[	"Offroad_DSHKM_INS","TT650_Ins","Pickup_PK_INS","UAZ_INS","UAZ_AGS30_INS","UAZ_SPG9_INS","UAZ_MG_INS","Ural_INS","UralOpen_INS",
							"Ural_ZU23_INS","UralReammo_INS","UralRepair_INS","UralRefuel_INS","BRDM2_INS","BRDM2_ATGM_INS"
				];
		_Unit_Pool_T = 	[	"BMP2_INS","BMP2_HQ_INS","T72_INS","ZSU_INS","BMP2_Ambul_INS"
				];
		_Unit_Pool_A = 	[	"Mi17_Ins","Mi17_medevac_Ins"];
		_Unit_Pool_U =  [  	"Ins_Bardak","Ins_Lopotev","Su25_Ins","GRAD_INS"];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------(NAPA GUERILLAS)-----------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1202:
	{
		_Unit_Pool_S = 	[
							"GUE_Soldier_Crew","GUE_Soldier_Pilot","GUE_Soldier_GL","GUE_Soldier_Sniper",
							"GUE_Soldier_CO","GUE_Soldier_AR","GUE_Soldier_MG","GUE_Soldier_Sab",
							"GUE_Soldier_Medic","GUE_Soldier_3","GUE_Soldier_2","GUE_Soldier_1",
							"GUE_Soldier_AT","GUE_Soldier_AA","GUE_Soldier_Scout","GUE_Commander",
							"GUE_Villager3","GUE_Villager4","GUE_Worker2","GUE_Woodlander1",
							"GUE_Woodlander2","GUE_Woodlander3"
				];
		_Unit_Pool_V = 	[	"Offroad_DSHKM_Gue","Offroad_SPG9_Gue","TT650_Gue","Pickup_PK_GUE","V3S_Gue","Ural_ZU23_Gue",
							"BRDM2_Gue","BRDM2_HQ_Gue"
				];
		_Unit_Pool_T = 	[	"BMP2_Gue","T34","T72_Gue"
				];
		_Unit_Pool_A = 	[];
		_Unit_Pool_U =  [];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------(TAKISTANI MILITA)-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1203:
	{
		_Unit_Pool_S = 	[
							"TK_GUE_Soldier_EP1","TK_GUE_Soldier_2_EP1","TK_GUE_Soldier_3_EP1",
							"TK_GUE_Soldier_4_EP1","TK_GUE_Soldier_5_EP1","TK_GUE_Soldier_AR_EP1",
							"TK_GUE_Bonesetter_EP1","TK_GUE_Soldier_AA_EP1","TK_GUE_Soldier_HAT_EP1",
							"TK_GUE_Soldier_AT_EP1","TK_GUE_Soldier_AAT_EP1","TK_GUE_Soldier_Sniper_EP1",
							"TK_GUE_Soldier_MG_EP1","TK_GUE_Soldier_TL_EP1","TK_GUE_Warlord_EP1"
				];
		_Unit_Pool_V = 	[	"Offroad_DSHKM_TK_GUE_EP1","Offroad_SPG9_TK_GUE_EP1","Pickup_PK_TK_GUE_EP1","V3S_TK_GUE_EP1",
							"Ural_ZU23_TK_GUE_EP1","V3S_Supply_TK_GUE_EP1","V3S_Salvage_TK_GUE_EP1","V3S_Reammo_TK_GUE_EP1",
							"V3S_Refuel_TK_GUE_EP1","V3S_Repair_TK_GUE_EP1","BRDM2_TK_GUE_EP1","BRDM2_HQ_TK_GUE_EP1",
							"BTR40_TK_GUE_EP1","BTR40_MG_TK_GUE_EP1"
				];
		_Unit_Pool_T = 	[	"T34_TK_GUE_EP1","T55_TK_GUE_EP1"
				];
		_Unit_Pool_A = 	[	"UH1H_TK_GUE_EP1"
				];
		_Unit_Pool_U =  [];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------(CZECH ARMY DESERT CAMO)------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1204:
	{
		_Unit_Pool_S = 	[
							"CZ_Soldier_Light_DES_EP1","CZ_Soldier_Pilot_EP1","CZ_Soldier_MG_DES_EP1",
							"CZ_Soldier_Office_DES_EP1","CZ_Soldier_DES_EP1","CZ_Soldier_AT_DES_EP1",
							"CZ_Soldier_B_DES_EP1","CZ_Soldier_Sniper_EP1","CZ_Soldier_SL_DES_EP1",
							"CZ_Soldier_AMG_DES_EP1","CZ_Special_Forces_GL_DES_EP1","CZ_Special_Forces_MG_DES_EP1",
							"CZ_Special_Forces_DES_EP1","CZ_Special_Forces_Scout_DES_EP1","CZ_Special_Forces_TL_DES_EP1"
				];
		_Unit_Pool_V = 	[	"ATV_CZ_EP1","HMMWV_M1151_M2_CZ_DES_EP1","LandRover_CZ_EP1","LandRover_Special_CZ_EP1",
							"HMMWV_Ambulance_CZ_DES_EP1"
				];
		_Unit_Pool_T = 	[];
		_Unit_Pool_A = 	[	"Mi171Sh_CZ_EP1","Mi171Sh_rockets_CZ_EP1"
				];
		_Unit_Pool_U =  [];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------(UNITED NATIONS)---------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1205:
	{
		_Unit_Pool_S = 	[
							"UN_CDF_Soldier_Crew_EP1","UN_CDF_Soldier_Pilot_EP1","UN_CDF_Soldier_MG_EP1",
							"UN_CDF_Soldier_Officer_EP1","UN_CDF_Soldier_EP1","UN_CDF_Soldier_AT_EP1",
							"UN_CDF_Soldier_B_EP1","UN_CDF_Soldier_Light_EP1","UN_CDF_Soldier_SL_EP1",
							"UN_CDF_Soldier_Guard_EP1","UN_CDF_Soldier_AMG_EP1","UN_CDF_Soldier_AAT_EP1"
				];
		_Unit_Pool_V = 	[	"SUV_UN_EP1","UAZ_Unarmed_UN_EP1","Ural_UN_EP1"
				];
		_Unit_Pool_T = 	[	"BMP2_UN_EP1","M113_UN_EP1","M113Ambul_UN_EP1"
				];
		_Unit_Pool_A = 	[	"Mi17_UN_CDF_EP1"
				];
		_Unit_Pool_U =  [];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------(CIVILIANS CHERNORUSSIA)-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1300:
	{
		_Unit_Pool_S = 	[
							"Villager1","Pilot","Worker1","Worker2","Worker3","Worker4","Citizen1",
							"Citizen2","Citizen3","Citizen4","Villager2","Villager3","Villager4",
							"Functionary1","Functionary2","Assistant","Profiteer1","Profiteer2",
							"Profiteer3","Profiteer4","SchoolTeacher","Policeman","Priest","Rocker1",
							"Rocker2","Rocker3","Rocker1","Woodlander1","Woodlander2","Woodlander3",
							"Woodlander4","WorkWoman1","WorkWoman2","WorkWoman3","WorkWoman4",
							"WorkWoman5","Farmwife1","Farmwife2","Farmwife3","Farmwife4","Farmwife5",
							"Madam1","Madam2","Madam3","Madam4","Madam5","Hooker1","Hooker2","Hooker3",
							"Hooker4","Hooker5","HouseWife1","HouseWife2","HouseWife3","HouseWife4",
							"HouseWife5","Damsel1","Damsel2","Damsel3","Damsel4","Damsel5","Secretary1",
							"Secretary2","Secretary3","Secretary4","Secretary5","Sportswoman1",
							"Sportswoman2","Sportswoman3","Sportswoman4","Sportswoman5"
				];
		_Unit_Pool_V = 	[	"car_hatchback","SkodaBlue","SkodaGreen","SkodaRed","Skoda","Ikarus","VWGolf",
							"hilux1_civil_1_open","hilux1_civil_2_covered","hilux1_civil_3_open","car_sedan",
							"TT650_Civ","MMT_Civ","datsun1_civil_2_covered","datsun1_civil_3_open","datsun1_civil_1_open",
							"V3S_Civ","Tractor","UralCivil2","UralCivil","LadaLM","Lada2","Lada1"
				];
		_Unit_Pool_T = 	[];
		_Unit_Pool_A = 	[	"Mi17_Civilian"
				];
		_Unit_Pool_U =  [  	"Doctor"];
	};
//--------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------(CIVILIANS TAKISTAN)---------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
	case 1301:
	{
		_Unit_Pool_S = 	[
							"TK_CIV_Worker01_EP1","TK_CIV_Worker02_EP1","TK_CIV_Takistani01_EP1",
							"TK_CIV_Takistani02_EP1","TK_CIV_Takistani03_EP1","TK_CIV_Takistani04_EP1",
							"TK_CIV_Takistani05_EP1","TK_CIV_Takistani06_EP1","TK_CIV_Woman01_EP1",
							"TK_CIV_Woman02_EP1","TK_CIV_Woman03_EP1"
				];
		_Unit_Pool_V = 	[	"Old_moto_TK_Civ_EP1","Old_bike_TK_CIV_EP1","Ikarus_TK_CIV_EP1","Lada1_TK_CIV_EP1",
							"Lada2_TK_CIV_EP1","LandRover_TK_CIV_EP1","hilux1_civil_3_open_EP1","TT650_TK_CIV_EP1",
							"S1203_TK_CIV_EP1","SUV_TK_CIV_EP1","UAZ_Unarmed_TK_CIV_EP1","Ural_TK_CIV_EP1",
							"V3S_Open_TK_CIV_EP1","Volha_1_TK_CIV_EP1","Volha_2_TK_CIV_EP1","VolhaLimo_TK_CIV_EP1",
							"S1203_ambulance_EP1"
				];
		_Unit_Pool_T = 	[];
		_Unit_Pool_A = 	[];
		_Unit_Pool_U =  [  	"An2_1_TK_CIV_EP1","An2_2_TK_CIV_EP1"];
	};
//--------------------------------------------------------------------------------------------------------------------------------
	Default {
				if(DAC_Basic_Value != 5) then
				{
					DAC_Basic_Value = 5;publicvariable "DAC_Basic_Value";
					hintc format["DAC_Config_Units > No valid config number = %1",_TypNumber];
				};
				if(true) exitwith {};
			};
};

if(count _this == 2) then
{
	_TempArray = _TempArray + [_Unit_Pool_S,_Unit_Pool_V,_Unit_Pool_T,_Unit_Pool_A];
}
else
{
	_TempArray = _Unit_Pool_V + _Unit_Pool_T + _Unit_Pool_A;
};
_TempArray