//////////////////////////////
//    Dynamic-AI-Creator    //
//    Version 3.0 - 2010    //
//--------------------------//
//    DAC_Config_Objects    //
//--------------------------//
//    Script by Silola      //
//    silola@freenet.de     //
//////////////////////////////

private ["_TypNumber","_TempArray","_Object_Pool"];

_TypNumber = _this select 0;_TempArray = [];

switch (_TypNumber) do
{
//-------------------------------------------------------------------------------------------------
	// use this config no. if you want to create positions only
	case 0:
	{
		_Object_Pool =	[
							[12,1],
							["LOGIC",1,0,0,0,0,""]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 1:
	{
		_Object_Pool =	[
							[12,1],
							["MAP_R2_RockWall",1,0,0,-30,0,"",[0,"ColorBlack"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 2:
	{
		_Object_Pool =	[
							[12,1],
							["MAP_c_picea",2,0,0,0,0,""],
							["MAP_b_betulaHumilis",2,0,0,0,0,""],
							["MAP_b_canina2s",3,0,0,0,0,""],
							["MAP_b_craet1",2,0,0,0,0,""],
							["MAP_b_pmugo",0,0,0,0,0,""],
							["MAP_b_prunus",2,0,0,0,0,""],
							["MAP_R2_Stone",5,0,0.1,0,0,""],
							["MAP_t_picea1s",1,0,0.03,0,0,""],
							["MAP_t_betula2f",0,0,0.05,0,0,""],
							["MAP_R2_Boulder1",2,0,0.05,0,0,""],
							["MAP_R2_Boulder2",2,0,0.05,0,0,""]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 3:
	{
		_Object_Pool =	[
							[12,1],
							["MAP_t_picea1s",2,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea2s",2,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea3f",2,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_pinusN1s",1,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_t_pinusN2s",2,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_t_pinusS2f",1,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_R2_Stone",5,0,0.1,0,0,"",[0,"ColorBlack"]],
							["MAP_c_picea",5,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_t_betula2f",1,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_R2_Boulder1",2,0,0.05,0,0,"",[0,"ColorBlack"]],
							["MAP_R2_Boulder2",1,0,0.05,0,0,"",[0,"ColorBlack"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 4:
	{
		_Object_Pool =	[
							[12,1],
							["MAP_c_picea",4,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea2s",1,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_b_betulaHumilis",5,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_canina2s",5,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_craet1",5,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_pmugo",2,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_prunus",2,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_misc_FallenTree2",1,0,0,0,0,"",[0,"ColorBlue"]],
							["MAP_t_picea1s",4,0,0.03,0,0,"",[0,"ColorGreen"]],
							["MAP_t_betula2f",1,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_R2_Boulder1",5,0,0.05,0,0,"",[0,"ColorBlack"]],
							["MAP_ruin_corner_1",1,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_ruin_corner_2",1,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_ruin_wall",1,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_ruin_walldoor",1,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_R2_Boulder2",5,0,0.05,0,0,"",[0,"ColorBlack"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 5:
	{
		_Object_Pool =	[
							[12,1],
							["MAP_t_picea1s",5,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea2s",2,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea3f",2,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_pinusN1s",1,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_t_pinusN2s",2,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_t_pinusS2f",1,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_t_betula2f",1,0,0.05,0,0,"",[0,"ColorGreen"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 6:
	{
		_Object_Pool =	[
							[12,1],
							["MAP_cihlovej_dum_in",2,0,0,0,1,"",[1,"ColorRed"]],
							["hruzdum",2,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_deutshe_mini",2,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_dum_m2",2,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_sara_domek_ruina",2,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_sara_domek_sedy",2,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_Statek_kulna",2,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_hut06",1,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_Shed_W01",1,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_Shed_W02",1,0,0,0,1,"",[1,"ColorRed"]],
							["MAP_Shed_W03",1,0,0,0,1,"",[1,"ColorRed"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 7:
	{
		_Object_Pool =	[
							[12,1],
							["MAP_dum_mesto2",1,0,1,0,0,"",[1,"ColorBlue"]],
							["MAP_dum_mesto_in",1,0,1,0,0,"",[1,"ColorBlue"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 8:
	{
		_Object_Pool =	[
							[12,1],
							["MAP_t_picea1s",3,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea2s",3,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea3f",3,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_R2_Stone",3,0,0.1,0,0,"",[0,"ColorBlack"]],
							["MAP_c_picea",3,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_betulaHumilis",8,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_canina2s",8,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_craet1",8,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_pmugo",7,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_prunus",9,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_t_betula2f",5,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_R2_Boulder1",3,0,0.05,0,0,"",[0,"ColorBlack"]],
							["MAP_R2_Boulder2",5,0,0.05,0,0,"",[0,"ColorBlack"]],
							["MAP_R2_RockWall",0,0,0,-30,0,"",[0,"ColorBlack"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 9:
	{
		_Object_Pool =	[
							[12,1],
							["MAP_t_picea1s",5,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea2s",2,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea3f",2,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_pinusN1s",1,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_t_pinusN2s",2,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_t_pinusS2f",1,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_R2_Stone",5,0,0.1,0,0,"",[0,"ColorBlack"]],
							["MAP_R2_RockWall",1,0,0,-30,0,"",[0,"ColorBlack"]],
							["MAP_t_betula2f",1,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_R2_Boulder1",5,0,0.05,0,0,"",[0,"ColorBlack"]],
							["MAP_R2_Boulder2",5,0,0.05,0,0,"",[0,"ColorBlack"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 10:
	{
		_Object_Pool =	[
							[3,1],
							["MAP_R2_Boulder1",5,0,0.05,0,0,"",[0,"ColorBlack"]],
							["MAP_R2_Boulder2",5,0,0.05,0,0,"",[0,"ColorBlack"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 11:
	{
		_Object_Pool =	[
							[0,1],
							["MAP_c_fern",1,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_c_fernTall",1,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_c_GrassCrooked",0,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_c_GrassCrookedForest",0,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_c_GrassCrookedGreen",0,0,0,0,0,"",[0,"ColorGreen"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 12:
	{
		_Object_Pool =	[
							[0,1],
							["MAP_b_betulaHumilis",0,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_canina2s",1,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_craet1",0,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_pmugo",2,0,0,0,0,"",[0,"ColorGreen"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 13:
	{
		_Object_Pool =	[
							[0,1],
							["MAP_R2_Boulder1",5,0,0.05,0,0,"",[0,"ColorBlack"]],
							["MAP_t_picea1s",2,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea2s",1,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_R2_Boulder2",5,0,0.05,0,0,"",[0,"ColorBlack"]],
							["MAP_R2_Stone",5,0,0.1,0,0,"",[0,"ColorBlack"]],
							["MAP_b_betulaHumilis",6,0,0,0,0,"",[0,"ColorGreen"]],
							["MAP_b_canina2s",6,0,0,0,0,"",[0,"ColorGreen"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	case 14:
	{
		_Object_Pool =	[
							[12,1],
							["MAP_t_picea1s",5,0,0.05,0,0,"",[0,"ColorGreen"]],
							["MAP_t_picea2s",2,0,0.05,0,0,"",[0,"ColorGreen"]]
						];
	};
//-------------------------------------------------------------------------------------------------
	Default {
				if(DAC_Basic_Value != 5) then
				{
					DAC_Basic_Value = 5;publicvariable "DAC_Basic_Value";
					hintc "Error: DAC_Config_Objects > No valid config number";
				};
				if(true) exitwith {};
			};
};

_TempArray = _Object_Pool;
_TempArray