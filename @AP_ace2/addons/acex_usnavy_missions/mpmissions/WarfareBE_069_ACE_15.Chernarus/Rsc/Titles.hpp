/* Titles */

#ifdef VANILLA
	#define usflag "\ca\data\flag_usa_co.paa"
	#define ruflag "\ca\data\flag_rus_co.paa"
#endif

#ifdef ARROWHEAD
	#define usflag "\ca\ca_e\data\flag_us_co.paa"
	#define ruflag "\ca\ca_e\data\flag_tkg_co.paa"
#endif

#ifdef COMBINEDOPS
	#define usflag "\ca\ca_e\data\flag_us_co.paa"
	#define ruflag "\ca\data\flag_rus_co.paa"
#endif

#ifndef usflag
	#define usflag "\ca\ca_e\data\flag_us_co.paa"
	#define ruflag "\ca\ca_e\data\flag_tkg_co.paa"
#endif

class RscTitles {
	
	titles[] = {OptionsAvailable,EndOfGameStats};

	//--- Mando Missiles - Titles.
	#include "Mando\mando_missiletitles.h"
	
	class OptionsAvailable {
		idd = 10200;
		movingEnable = 0;
		objects[] = {};
		duration = 15000;
		name = "OptionsAvailable";
		onLoad = "_this ExecVM ""Client\GUI\GUI_SetCurrentCutDisplay.sqf""";
		onUnload = "_this ExecVM ""Client\GUI\GUI_ClearCurrentCutDisplay.sqf""";
		controls[] = {"ProgressBarBackground","ProgressBar","CA_Progress_Label","OptionsIcon0", "OptionsIcon1", "OptionsIcon2", "OptionsIcon3", "OptionsIcon4", "OptionsIcon5", "OptionsIcon6", "OptionsIcon7", "OptionsIcon8", "OptionsIcon9", "OptionsIcon10",
		"OptionsIcon11", "OptionsIcon12", "OptionsIcon13", "OptionsIcon14", "OptionsIcon15", "OptionsIcon16", "OptionsIcon17"};
		controlsBackground[] = {};
		
		class ProgressBarBackground : RscText {
			style = 128;
			idc = 3600;
			x = 0.3;
			y = "((SafeZoneH + SafeZoneY) - (1 + 0.165))*-1";
			w = 0.4;
			h = 0.06;
			colorBackground[] = {0,0,0,0.001};
		};
			
		class ProgressBar : RscText {
			style = 128;
			idc = 3800;
			x = 0.31;
			y = "((SafeZoneH + SafeZoneY) - (1 + 0.175))*-1";
			w = 0.38;
			h = 0.04;
			colorBackground[] = {0,0,0,0.001};
		};
		
		class CA_Progress_Label: RscText {
			idc = 3900;
			text = "";
			x = 0.44;
			w = 0.2;
			y = "((SafeZoneH + SafeZoneY) - (1 + 0.175))*-1";
		};
		
		class OptionsImageAspectRatio : RscPicture {
			w = 0.0784314;
			h = 0.104575;
			style = 0x30+0x800;
		};
			
		class OptionsIcon0 : OptionsImageAspectRatio {
			idc = 3500;
			x = "(SafeZoneW + SafeZoneX) - (0.0392157)";
			y = 0+(0.0522876*17);
			w = 0.0392157;
			h = 0.0522876;
			colorText[] = {1, 1, 1, 0.4};
			text = "";
		};
			
		class OptionsIcon1 : OptionsIcon0 {
			idc = 3500 + 1;
			y = 0+(0.0522876*16);
		};
		
		class OptionsIcon2 : OptionsIcon0 {
			idc = 3500 + 2;
			y = 0+(0.0522876*15);
		};
		
		class OptionsIcon3 : OptionsIcon0 {
			idc = 3500 + 3;
			y = 0+(0.0522876*14);
		};
		
		class OptionsIcon4 : OptionsIcon0 {
			idc = 3500 + 4;
			y = 0+(0.0522876*13);
		};
		
		class OptionsIcon5 : OptionsIcon0 {
			idc = 3500 + 5;
			y = 0+(0.0522876*12);
		};
		
		class OptionsIcon6 : OptionsIcon0 {
			idc = 3500 + 6;
			y = 0+(0.0522876*11);
		};
		
		class OptionsIcon7 : OptionsIcon0 {
			idc = 3500 + 7;
			y = 0+(0.0522876*10);
		};
		
		class OptionsIcon8 : OptionsIcon0 {
			idc = 3500 + 8;
			y = 0+(0.0522876*9);
		};
		
		class OptionsIcon9 : OptionsIcon0 {
			idc = 3500 + 9;
			y = 0+(0.0522876*8);
		};
		
		class OptionsIcon10 : OptionsIcon0 {
			idc = 3500 + 10;
			y = 0+(0.0522876*7);
		};
		
		class OptionsIcon11 : OptionsIcon0 {
			idc = 3500 + 11;
			y = 0+(0.0522876*6);
		};
		
		class OptionsIcon12 : OptionsIcon0 {
			idc = 3500 + 12;
			y = 0+(0.0522876*5);
		};
		
		class OptionsIcon13 : OptionsIcon0 {
			idc = 3500 + 13;
			y = 0+(0.0522876*4);
		};
		
		class OptionsIcon14 : OptionsIcon0 {
			idc = 3500 + 14;
			y = 0+(0.0522876*3);
		};
		
		class OptionsIcon15 : OptionsIcon0 {
			idc = 3500 + 15;
			y = 0+(0.0522876*2);
		};
		
		class OptionsIcon16 : OptionsIcon0 {
			idc = 3500 + 16;
			y = 0+(0.0522876*1);
		};
		
		class OptionsIcon17 : OptionsIcon0 {
			idc = 3500 + 17;
			y = 0.0522876;
		};
	};
	
	class EndOfGameStats {
		idd = 90000;
		duration = 15000;
		movingEnable = 0;
		objects[] = {};
		name = "EndOfGameStats";

		onLoad = "_this ExecVM ""Client\GUI\GUI_SetCurrentCutDisplay.sqf""";
		onUnload = "_this ExecVM ""Client\GUI\GUI_ClearCurrentCutDisplay.sqf"""; 

		controls[] = {StatsBackGroundHeader,SideWinsText,StatsBackGround,EastImage,WestImage,SoldiersRecruitedLabel,SoldiersLostLabel,VehiclesCreatedLabel,VehiclesLostLabel,
					  EastSoldiersRecruitedBar,EastSoldiersRecruitedCount,WestSoldiersRecruitedBar,WestSoldiersRecruitedCount,
					  EastSoldiersLostBar,EastSoldiersLostCount,WestSoldiersLostBar,WestSoldiersLostCount,
					  EastVehiclesCreatedBar,EastVehiclesCreatedCount,WestVehiclesCreatedBar,WestVehiclesCreatedCount,
					  EastVehiclesLostBar,EastVehiclesLostCount,WestVehiclesLostBar,WestVehiclesLostCount};

		controlsBackground[] = {};
		
		class StatsBackGroundHeader : RscText {
			style = 128;
			idc = 90002;
			x = 0;
			y = 0.06;
			w = 1;
			h = 0.18;
			colorBackground[] = {0.1882, 0.2588, 0.149, 0.76};
		};
		
		class SideWinsText : RscText {
			idc = 90001;
			style = 2;
			sizeEx = 0.05;
			x = 0.3;
			y = 0.1;
			w = 0.3;
			h = 0.08;
			colorText[] = {1.0,1.0,1.0,1};
		};
		
		class StatsBackGround : RscText {
			style = 128;
			idc = 90003;
			x = 0;
			y = 0.24;
			w = 1;
			h = 0.62;
			colorBackground[] = {0.1882, 0.2588, 0.149, 0.76};
		};

		class EastImage : RscPicture {
			style = 48 + 0x800;
			x = 0.1;
			y = 0.05;
			w = 0.2;
			h = 0.2;
			text = ruflag;
		};
		
		class WestImage:EastImage {
			x = 0.6;
			text = usflag;
		};

		class SoldiersRecruitedLabel : RscText {
			style = 2;
			sizeEx = 0.03;
			x = 0.05;
			y = 0.25;
			w = 0.9;
			h = 0.04;
			colorText[] = {1.0,1.0,1.0,1};
			text = $STR_WF_Soldier_Recruited;
		};

		class SoldiersRecruitedCountBase : RscText {
			idc = 90100;
			style = 0;
			sizeEx = 0.06;
			x = 0.05;
			y = 0.3;
			w = 0.2;
			h = 0.1;
			colorText[] = {1.0,1.0,1.0,1};
		};

		class EastSoldiersRecruitedCount : SoldiersRecruitedCountBase {
			idc = 90101;
		};

		class EastSoldiersRecruitedBar : RscText {
			style = 128;
			idc = 90102;
			x = 0.05;
			y = 0.31;
			w = 0.4;
			h = 0.08;
			colorBackground[] = {0.0,0.7,0.0,0.7};
		};

		class WestSoldiersRecruitedCount : SoldiersRecruitedCountBase {
			idc = 90200;
			x = 0.55;
		};

		class WestSoldiersRecruitedBar : EastSoldiersRecruitedBar {
			idc = 90201;
			x = 0.55;
		};

		class SoldiersLostLabel : SoldiersRecruitedLabel {
			y = 0.4;
			text = $STR_WF_Soldier_Lost;
		};

		class EastSoldiersLostCount : SoldiersRecruitedCountBase {
			idc = 90103;
			y = 0.45;
		};

		class EastSoldiersLostBar : EastSoldiersRecruitedBar {
			idc = 90104;
			y = 0.46;
			colorBackground[] = {0.7,0.0,0.0,0.7};
		};

		class WestSoldiersLostCount : SoldiersRecruitedCountBase {
			idc = 90202;
			y = 0.45;
			x = 0.55;
		};

		class WestSoldiersLostBar : EastSoldiersLostBar	{
			idc = 90203;
			x = 0.55;
		};

		class VehiclesCreatedLabel : SoldiersRecruitedLabel {
			y = 0.55;
			text = $STR_WF_Vehicle_Built;
		};

		class EastVehiclesCreatedCount : SoldiersRecruitedCountBase	{
			idc = 90105;
			y = 0.6;
		};

		class EastVehiclesCreatedBar : EastSoldiersRecruitedBar	{
			idc = 90106;
			y = 0.61;
			colorBackground[] = {0.0,0.7,0.0,0.7};
		};

		class WestVehiclesCreatedCount : SoldiersRecruitedCountBase {
			idc = 90204;
			x = 0.55;
			y = 0.6;
		};

		class WestVehiclesCreatedBar : EastVehiclesCreatedBar {
			idc = 90205;
			x = 0.55;
		};

		class VehiclesLostLabel : SoldiersRecruitedLabel {
			y = 0.7;
			text = $STR_WF_Vehicle_Lost;
		};

		class EastVehiclesLostCount : SoldiersRecruitedCountBase {
			idc = 90107;
			y = 0.75;
		};

		class EastVehiclesLostBar : EastSoldiersRecruitedBar {
			idc = 90108;
			y = 0.76;
			colorBackground[] = {0.7,0.0,0.0,0.7};
		};

		class WestVehiclesLostCount : SoldiersRecruitedCountBase {
			idc = 90206;
			x = 0.55;
			y = 0.75;
		};

		class WestVehiclesLostBar : EastVehiclesLostBar	{
			idc = 90207;
			x = 0.55;
		};
	};
};