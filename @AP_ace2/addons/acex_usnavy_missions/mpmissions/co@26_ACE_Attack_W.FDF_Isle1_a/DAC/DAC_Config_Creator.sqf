//////////////////////////////
//    Dynamic-AI-Creator    //
//    Version 3.0 - 2010    //
//--------------------------//
//    DAC_Config_Creator    //
//--------------------------//
//    Script by Silola      //
//    silola@freenet.de     //
//////////////////////////////

DAC_Activate 	= compile preprocessFile "DAC\Scripts\DAC_Activate_Zone.sqf";
DAC_Deactivate 	= compile preprocessFile "DAC\Scripts\DAC_Deactivate_Zone.sqf";
DAC_Weapons 	= compile preprocessFile "DAC\Scripts\DAC_Change_Weapons.sqf";
scalar = "any";DAC_Init_Camps = 0;

waituntil{time > 0.3};

if(isServer) then {if(local player) then {DAC_Code = 1} else {DAC_Code = 0}} else {if(isnull player) then {DAC_Code = 3} else {DAC_Code = 2}};

//===============|
// DAC_Settings	 |
//===============|=============================================================================================|

	if(isNil "DAC_STRPlayers")		then {		DAC_STRPlayers		= ["s1","s2","s3","s4","s5","s6","s7","s8","s9","s10","s11","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","s22","s23","s24","s25","s26"]};
	if(isNil "DAC_AI_Count_Level")	then {		DAC_AI_Count_Level  = [[2,4],[2,6],[2,8],[2,12],[5,0]]			};
	if(isNil "DAC_Dyn_Weather") 	then {		DAC_Dyn_Weather		= [300,120,1,0.7]							};
	if(isNil "DAC_Reduce_Value") 	then {		DAC_Reduce_Value	= [800,850,0.3]								};
	if(isNil "DAC_AI_Spawn") 		then {		DAC_AI_Spawn		= [[10,5,5],[10,5,15],0,120,250,0]			};
	if(isNil "DAC_Delete_Value") 	then {		DAC_Delete_Value	= [[120,150],[140,150],3600]				};
	if(isNil "DAC_Del_PlayerBody") 	then {		DAC_Del_PlayerBody	= [0,0]										};
	if(isNil "DAC_Com_Values") 		then {		DAC_Com_Values		= [1,2,0]									};
	if(isNil "DAC_AI_AddOn") 		then {		DAC_AI_AddOn		= 1											};
	if(isNil "DAC_AI_Level") 		then {		DAC_AI_Level		= 4											};
	if(isNil "DAC_Res_Side") 		then {		DAC_Res_Side		= 1											};
	if(isNil "DAC_VehAllowed") 		then {		DAC_VehAllowed 		= [0,1]										};
	if(isNil "DAC_Marker") 			then {		DAC_Marker			= 4											};
	if(isNil "DAC_WP_Speed") 		then {		DAC_WP_Speed		= 0.01										};
	if(isNil "DAC_Join_Action")		then {		DAC_Join_Action		= false										};
	if(isNil "DAC_Fast_Init") 		then {		DAC_Fast_Init		= false										};
	if(isNil "DAC_Player_Marker")	then {		DAC_Player_Marker	= false										};
	if(isNil "DAC_Direct_Start")	then {		DAC_Direct_Start	= false										};
	if(isNil "DAC_Activate_Sound")	then {		DAC_Activate_Sound	= false										};
	if(isNil "DAC_Auto_UnitCount")	then {		DAC_Auto_UnitCount	= [8,10]									};
	if(isNil "DAC_Player_Support")	then {		DAC_Player_Support	= [10,[10,2000,3,1000]]						};
	if(isNil "DAC_SaveDistance")	then {		DAC_SaveDistance	= [500,["DAC_Save_Pos"]]					};

	DAC_BadBuildings 	= 	["Camp","CampEast","Land_vez"];
	DAC_SP_Soldiers		= 	["RU_Soldier_MG","USMC_Soldier_MG","GUE_Soldier_MG","CDF_Soldier_MG","Ins_Soldier_MG"];
	DAC_GunAllowed 		= 	[
								"Stinger_Pod","M2StaticMG","M252","M2HD_mini_TriPod","MK19_TriPod","SearchLight","TOW_TriPod","M119",
								"USMC_WarfareBMGNest_M240","AGS_CDF","D30_CDF","DSHKM_CDF","DSHkM_Mini_TriPod_CDF","2b14_82mm_CDF",
								"SPG9_CDF","SearchLight_CDF","ZU23_CDF","CDF_WarfareBMGNest_PK","KORD_high","Minitripod KORD","AGS_RU",
								"D30_RU","Igla_AA_pod_East","Metis","2B14 2b14_82mm_RU","SearchLight_RUS","RU_WarfareBMGNest_PK","AGS_INS",
								"D30_INS","DSHKM_INS","DSHkM_Mini_TriPod_INS","2B14 2b14_82mm_INS","SPG9_INS","SearchLight_INS","ZU23_INS",
								"INS_WarfareBMGNest_PK","DSHKM_GUE","2B14 2b14_82mm_GUE","SPG9_GUE","SearchLight_GUE","ZU23_GUE",
								"GUE_WarfareBMGNest_PK","Fort_Nest_M240"
							];

	//=============================================================================================================|

	[]execVM "DAC\Scripts\DAC_Start_Creator.sqf";
	waituntil{format["%1",!isNil 'DAC_Basic_Value'] == "true"};
	sleep 0.1;
	waituntil {(DAC_Basic_Value > 0)};

if(DAC_Code < 2) then
{
	//===========================================|
	// StartScriptOnServer                       |
	//===========================================|
	//player sidechat "ServerStart"
	//[] execVM "myServerScript.sqf";
	//onMapSingleClick "_fun = [_pos,_shift]execVM ""Action.sqf""";
	//[[sec1,""]] execVM "DAC\Scripts\DAC_Init_Sector.sqf";
}
else
{
	if(DAC_Code == 3) then
	{
		//===========================================|
		// StartScriptOnJipClient                    |
		//===========================================|
		//player sidechat "JipClientStart"
		//[] execVM "myJipClientScript.sqf";
	}
	else
	{
		//===========================================|
		// StartScriptOnClient                       |
		//===========================================|
		//player sidechat "ClientStart"
		//[] execVM "myClientScript.sqf";
		//onMapSingleClick "_fun = [_pos,_shift]execVM ""Action.sqf""";
	};
};