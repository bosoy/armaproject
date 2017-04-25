class LDL_UAVDialog: LDL_DialogParent
{
	idd = 1000;
	movingEnable = true;
	controlsBackground[] = {};
	controls[] = 
	{
		/*Bottom*/Target10,Target9,Target8,Target7,Target6,Target5,Target4,Target3,Target2,Target1,TargetText,indicatorVerBar,indicatorVerFrame,indicatorVerText,indicatorHorText,indicatorHorBar,indicatorHorFrame,West,South,East,North,Range,Cross,Center2,Center,mouseHandler,Info4,Info3,Info2,Info1,Warning,
		/*Middle*/CircleTarget,Display,
		/*Top*/Info5
	};

        class Cross: LDL_RscPicture
  	{
   		idc = 1007;
  		text = "LDL_ac130\Pictures\VisTV.paa";
		w = SafeZoneW/4;
		h = SafeZoneH/4;
		x = SafeZoneX + SafeZoneW/2 - SafeZoneW/8;
		y = SafeZoneY + SafeZoneH/2 - SafeZoneH/8;
  	};

	class CircleTarget: LDL_RscPicture
  	{
   		idc = 1026;
  		text = "\CA\ui\data\cursor_circle_ca.paa";
		w = SafeZoneW/4;
		h = SafeZoneH/4;
		x = -1;
		y = -1;
  	};
};