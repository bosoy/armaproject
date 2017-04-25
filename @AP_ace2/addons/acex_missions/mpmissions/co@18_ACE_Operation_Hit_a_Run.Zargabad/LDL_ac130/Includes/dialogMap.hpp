class LDL_DialogMap
{
	idd = 2000;
	movingEnable = true;
	controlsBackground[] = {RscMapControl};
	controls[] = {TextRadius, EditRadius, TextHeight, EditHeight, Button, Display};
	onLoad = "LDL_MapShown = true;";
	onUnload = "LDL_MapShown = false;";
	onChildDestroyed = "LDL_MapShown = false;";

        class Display: LDL_RscPicture
  	{
   		idc = 2000;
   		font = "Bitstream";
  		text = "LDL_ac130\Pictures\TVMonitor.paa";
  		x = SafeZoneX;
  		y = SafeZoneY;
  		w = SafeZoneW;
  		h = SafeZoneH;
  	};

	class TextRadius: LDL_RscText
	{
		x = SafeZoneX + SafeZoneW/8; 
	        y = SafeZoneY + SafeZoneH/8;
		w = 0.06;
		h = 0.03;
		text = "Radius: ";
		colorText[] = {0.7,1,0.7,1};
		colorBackground[] = {0,0,0,0.5};
	};

	class EditRadius: LDL_RscEdit
	{
		idc = 2002;
		x = SafeZoneX + SafeZoneW/8 + 0.06; 
	        y = SafeZoneY + SafeZoneH/8;
		w = 0.06;
		h = 0.03;
		text = "1000";
		colorText[] = {1,0,0,1};
		colorSelection[] = {0,0,0,0.5}; 
	};

	class TextHeight: TextRadius
	{
		y = SafeZoneY + SafeZoneH/8 + 0.03;
		text = "Height: ";
	};

	class EditHeight: EditRadius
	{
		idc = 2003;
		y = SafeZoneY + SafeZoneH/8 + 0.03;
		text = "800";
	};

	class Button: LDL_RscButton
	{
		idc = 2004;
		x = SafeZoneX + SafeZoneW/8; 
	        y = SafeZoneY + SafeZoneH/8 + 0.06;
		w = 0.12;
		h = 0.03;
		text = "Confirm"; 
		action = ""; 
	};

class RscMapControl  
{
	access = 0;
	type = 101;
	idc = 2001;
	style = 48;
  	x = SafeZoneX;
  	y = SafeZoneY;
  	w = SafeZoneW;
  	h = SafeZoneH;
	colorBackground[] = {0.7,1,0.7,1};
	colorOutside[] = {0,0,0,1};
	colorText[] = {0,0,0,1 };
	font = "TahomaB";
	sizeEx = 0.040000;
	colorSea[] = {0.560000,0.800000,0.980000,0.500000 };
	colorForest[] = {0.600000,0.800000,0.200000,0.500000 };
	colorRocks[] = {0.500000,0.500000,0.500000,0.500000 };
	colorCountlines[] = {0.650000,0.450000,0.270000,0.500000 };
	colorMainCountlines[] = {0.650000,0.450000,0.270000,1 };
	colorCountlinesWater[] = {0,0.530000,1,0.500000 };
	colorMainCountlinesWater[] = {0,0.530000,1,1 };
	colorForestBorder[] = {0.400000,0.800000,0,1 };
	colorRocksBorder[] = {0.500000,0.500000,0.500000,1 };
	colorPowerLines[] = {0,0,0,1 };
	colorRailWay[] = {0.800000,0.200000,0.300000,1 };
	colorNames[] = {0,0,0,1 };
	colorInactive[] = {1,1,1,0.500000 };
	colorLevels[] = {0,0,0,1 };
	fontLabel = "TahomaB";
	sizeExLabel = 0.040000;
	fontGrid = "TahomaB";
	sizeExGrid = 0.040000;
	fontUnits = "TahomaB";
	sizeExUnits = 0.040000;
	fontNames = "TahomaB";
	sizeExNames = 0.040000;
	fontInfo = "TahomaB";
	sizeExInfo = 0.040000;
	fontLevel = "TahomaB";
	sizeExLevel = 0.040000;
	text = "#(argb,8,8,3)color(1,1,1,1)";
	stickX[] = {0.200000,{"Gamma",1,1.500000 } };
	stickY[] = {0.200000,{"Gamma",1,1.500000 } };
	ptsPerSquareSea = 6;
	ptsPerSquareTxt = 8;
	ptsPerSquareCLn = 8;
	ptsPerSquareExp = 8;
	ptsPerSquareCost = 8;
	ptsPerSquareFor = "4.0f";
	ptsPerSquareForEdge = "10.0f";
	ptsPerSquareRoad = 2;
	ptsPerSquareObj = 10;
	showCountourInterval = "true";
	maxSatelliteAlpha = 0.660000;
	alphaFadeStartScale = 0.050000;
	alphaFadeEndScale = 0.150000;

	class Legend  {
		x = 0.700000;
		y = 0.850000;
		w = 0.250000;
		h = 0.100000;
		font = "TahomaB";
		sizeEx = 0.040000;
		colorBackground[] = {1,1,1,0.5 };
		color[] = {0,0,0,1 };
	};

	class ActiveMarker  {
		color[] = {0.300000,0.100000,0.900000,1 };
		size = 50;
	};

	class Command  {
		icon = "#(argb,8,8,3)color(1,1,1,1)";
		color[] = {0,0,0,0 };
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};

	class Task  {
  		icon = "#(argb,8,8,3)color(0,1,0,1)";
  		iconCreated = "#(argb,8,8,3)color(1,1,1,1)";
  		iconCanceled = "#(argb,8,8,3)color(0,0,1,1)";
 		iconDone = "#(argb,8,8,3)color(0,0,0,1)";
  		iconFailed = "#(argb,8,8,3)color(1,0,0,1)";
  		colorCreated[] = {1,1,1,1};
  		colorCanceled[] = {1,1,1,1};
  		colorDone[] = {1,1,1,1};
  		colorFailed[] = {1,1,1,1};
  		color[] = {1,1,1,1};
  		size = 18;
  		importance = 1;
  		coefMin = 1;
  		coefMax = 1;
	};

	class CustomMark  {
		icon = "#(argb,8,8,3)color(1,0.5,0,1)";
		color[] = {1,1,1,1 };
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};

	class Tree  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class SmallTree  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "0.6 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Bush  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "0.2 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Church  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Chapel  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "1 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Cross  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "0.7 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Rock  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "1.5 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Bunker  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "1.5 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Fortress  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Fountain  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,1,1 };
		size = 16;
		importance = "1 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class ViewTower  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "2.5 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Lighthouse  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "3 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Quay  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Fuelstation  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Hospital  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {1,0,0,1 };
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class BusStop  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,1,1 };
		size = 8;
		importance = "1 * 8 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Transmitter  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,1,1 };
		size = 8;
		importance = "1 * 8 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Stack  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,1,1 };
		size = 8;
		importance = "1 * 8 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Ruin  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,1,1 };
		size = 8;
		importance = "1 * 8 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Tourism  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,1,1 };
		size = 8;
		importance = "1 * 8 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Watertower  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,1,1 };
		size = 8;
		importance = "1 * 8 * 0.05";
		coefMin = 0.250000;
		coefMax = 4;
	};

	class Waypoint  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 24;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};

	class WaypointCompleted  {
		icon = "#(argb,8,8,3)color(0,0,0,0)";
		color[] = {0,0,0,0 };
		size = 24;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
};
};