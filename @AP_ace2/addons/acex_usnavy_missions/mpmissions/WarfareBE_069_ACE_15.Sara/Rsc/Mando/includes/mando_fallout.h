class Mando_mapfallout
{
   idd = 24000;
   movingEnable = true;
   onLoad = "[""onLoad"", _this] call mando_mapfallout";
   onUnload =  "[""onUnload"", _this] call mando_mapfallout";

   controlsBackground[] = {MMA_MAPFALLOUT_BACK_BACKGROUND,MMA_MAPFALLOUT_BACKGROUND,MMA_MAPFALLOUT_TEXT};

   class MMA_MAPFALLOUT_BACK_BACKGROUND
   {
        type = 0;
        style = 128;
        idc = -1;
        x = 0.25-0.01;
        y = 0.25-0.01;
        w = 0.5+0.02;
        h = (0.5+0.02)*4/3;

        text = "";
        colorBackground[] = {0, 0, 0, 1};
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class MMA_MAPFALLOUT_TEXT
   {
        type = 0;
        style = 128 + 2;
        idc = 99;
        x = 0.25;
        y = 0.355 + 0.315*4/3;
        w = 0.5;
        h = 0.02;

        text = "Fallout areas";
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0.8, 0.8, 0.8, 0.8};
        font = "Bitstream";
        sizeEx = 0.02;
   };



   controls[]={MMA_MAPFALLOUT_MAP,MMA_MAPFALLOUT_BTN1,MMA_MAPFALLOUT_BTN2};

   class MMA_MAPFALLOUT_MAP
   {
      access = 0;
      type = 101;
      style = 48;

      idc = 23903;
      x = 0.325 + 0.01;
      y = 0.35 + 0.02;
      w = 0.35 - 0.01*2;
      h = (0.315 - 0.01*2)*4/3;
      font = "TahomaB";
      sizeEx = 0.04;

      sizeExLabel = 0.02;
      sizeExGrid = 0.02;
      sizeExUnits = 0.02;
      sizeExNames = 0.04;
      sizeExInfo = 0.02;
      sizeExLevel = 0.02;



      showCountourInterval = "false";			
      onMouseZChanged = "";
      onMouseButtonDown = "[""onMapClick"", _this] call mando_mapfallout";

      colorBackground[] = {0.7, 0.7, 0.8, 1};
      colorText[] = {0, 0, 0, 1};
      colorSea[] = {0.3, 0.3, 0.4, 0.5};
      colorForest[] = {0.8, 0.8, 0.9, 0.5};
      colorRocks[] = {0.5, 0.5, 0.6, 0.5};
      colorCountlines[] = {0.45, 0.45, 0.55, 0.5};
      colorMainCountlines[] = {0.45, 0.45, 0.55, 1};
      colorCountlinesWater[] = {0.53, 0.53, 0.63, 0.5};
      colorMainCountlinesWater[] = {0.53, 0.53, 0.63, 1};
      colorForestBorder[] = {0.8, 0.8, 0.9, 1};
      colorRocksBorder[] = {0.5, 0.5, 0.6, 1};
      colorPowerLines[] = {0, 0, 0, 1};
      colorRailWay[] = {0.8,0.8,0.9,1};
      colorNames[] = {0, 0, 0, 1};
      colorInactive[] = {1, 1, 1, 0.5};
      colorOutside[] = {0,0,0,1};
      colorLevels[] = {0, 0, 0, 1};


      maxSatelliteAlpha = 0.75;
      alphaFadeStartScale = 0.15;
      alphaFadeEndScale = 0.29;

      fontLabel = "Zeppelin32";
      fontGrid = "Zeppelin32";
      fontUnits = "Zeppelin32";
      fontNames = "Zeppelin32";
      fontInfo = "Zeppelin32";
      fontLevel = "Zeppelin32";
      text = "#(argb,8,8,3)color(1,1,1,1)";
      stickX[] = {0.2, {"Gamma", 1, 1.5}};
      stickY[] = {0.2, {"Gamma", 1, 1.5}};
      ptsPerSquareSea = 6;
      ptsPerSquareTxt = 8;
      ptsPerSquareCLn = 8;
      ptsPerSquareExp = 8;
      ptsPerSquareCost = 8;
      ptsPerSquareFor = "4.0f";
      ptsPerSquareForEdge = "10.0f";
      ptsPerSquareRoad = 2;
      ptsPerSquareObj = 10;

 class Task
 {
  icon = "\ca\ui\data\ui_taskstate_current_CA.paa";
  iconCreated = "\ca\ui\data\ui_taskstate_new_CA.paa";
  iconCanceled = "#(argb,8,8,3)color(0,0,0,0)";
  iconDone = "\ca\ui\data\ui_taskstate_done_CA.paa";
  iconFailed = "\ca\ui\data\ui_taskstate_failed_CA.paa";
  color[] = {0.863,0.584,0,1};
  colorCreated[] = {0.95,0.95,0.95,1};
  colorCanceled[] = {0.606,0.606,0.606,1};
  colorDone[] = {0.424,0.651,0.247,1};
  colorFailed[] = {0.706,0.0745,0.0196,1};
  size = 27;
  importance = 1;
  coefMin = 1;
  coefMax = 1;
 };

 class CustomMark
 {
  icon = "\ca\ui\data\map_waypoint_ca.paa";
  color[] = {0.6471,0.6706,0.6235,1};
  size = 18;
  importance = 1;
  coefMin = 1;
  coefMax = 1;
 };

			
      class Command 
      {
         icon = "#(argb,8,8,3)color(1,1,1,1)";
         color[] = {0, 0, 0, 1};
         size = 18;
         importance = 1;
         coefMin = 1;
         coefMax = 1;
      };
      class ActiveMarker
      {
         color[] = {0, 0.1, 0, 1};
         size = 50;
      };

      class Bunker 
      {
		icon = "\ca\ui\data\map_bunker_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 16;
		importance = 1.5 * 14 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
      };
	
      class Bush 
      {
		icon = "\ca\ui\data\map_bush_ca.paa";
		color[] = {0.64, 0.64, 0.74, 1};
		size = 16;
		importance = 0.2 * 14 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
      };
	
      class BusStop 
      {
	        icon = "\ca\ui\data\map_busstop_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 10;
		importance = 1 * 10 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
      };
	
	class Cross 
        {
		icon = "\ca\ui\data\map_cross_ca.paa";
		color[] = {0.64, 0.64, 0.74, 1};
		size = 16;
		importance = 0.7 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Fortress 
        {
		icon = "\ca\ui\data\map_bunker_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Fuelstation 
        {
		icon = "\ca\ui\data\map_fuelstation_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.75;
		coefMax = 4;
	};
	
	class Fountain 
        {
		icon = "\ca\ui\data\map_fountain_ca.paa";
		color[] = {0.35, 0.35, 0.45, 1};
		size = 12;
		importance = 1 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Hospital 
        {
		icon = "\ca\ui\data\map_hospital_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Chapel 
        {
		icon = "\ca\ui\data\map_chapel_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 16;
		importance = 1 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Church 
        {
		icon = "\ca\ui\data\map_church_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Lighthouse 
        {
		icon = "\ca\ui\data\map_lighthouse_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 20;
		importance = 3 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Quay 
        {
		icon = "\ca\ui\data\map_quay_ca.paa";
		color[] = {0.64, 0.64, 0.74, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Rock 
        {
		icon = "\ca\ui\data\map_rock_ca.paa";
		color[] = {0.64, 0.64, 0.74, 1};
		size = 12;
		importance = 0.5 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Ruin 
        {
		icon = "\ca\ui\data\map_ruin_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 16;
		importance = 1.2 * 16 * 0.05;
		coefMin = 1;
		coefMax = 4;
	};
	
	class SmallTree 
        {
		icon = "\ca\ui\data\map_smalltree_ca.paa";
		color[] = {0.7, 0.7, 0.8, 1};
		size = 16;
		importance = 0.6 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Stack 
        {
		icon = "\ca\ui\data\map_stack_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 20;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Tree 
        {
		icon = "\ca\ui\data\map_tree_ca.paa";
		color[] = {0.7, 0.7, 0.8, 1};
		size = 16;
		importance = 0.9 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;	
	};
	
	class Tourism 
        {
		icon = "\ca\ui\data\map_tourism_ca.paa";
		color[] = {1, 1, 1, 1};
		size = 16;
		importance = 1 * 16 * 0.05;
		coefMin = 0.7;
		coefMax = 4;
	};
	
	class Transmitter 
        {
		icon = "\ca\ui\data\map_transmitter_ca.paa";
		size = 20;
		color[] = {0.35, 0.35, 0.45, 1};
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class ViewTower 
        {
		icon = "\ca\ui\data\map_viewtower_ca.paa";
		size = 16;
		color[] = {0.35, 0.35, 0.45, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Watertower 
        {
		icon = "\ca\ui\data\map_watertower_ca.paa";
		color[] = {0.35, 0.35, 0.45, 1};
		size = 32;
		importance = 1.2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	class Waypoint 
        {
		icon = "\ca\ui\data\map_waypoint_ca.paa";
		size = 16;
		color[] = {0.35, 0.35, 0.45, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;		
	};
	
	class WaypointCompleted 
        {
		icon = "\ca\ui\data\map_waypoint_completed_ca.paa";
		size = 16;
		color[] = {0.35, 0.35, 0.45, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;		
	};
   };


   class MMA_MAPFALLOUT_BACKGROUND
   {
        idc = 100;
        x = 0.25;
        y = 0.25;
        w = 0.5;
        h = 0.5*4/3;

	text = "";
        type = 0;
        style = 48;
        colorBackground[] = {1, 1, 1, 1};
        colorText[] = {1, 1, 1, 1};
        font = "TahomaB";
        sizeEx = 0.04;
   };


   class MMA_MAPFALLOUT_BTN1
   {
        type = 1;
        idc = 102;
        style = 2;
        x = 0.25+0.12; 
        y = 0.25+0.025;
  	w   = 0.02;
  	h   = 0.02;

        sizeEx = 0.02;
  	text = "G";
    
  	action = "[""on_btn1"", _this] call mando_mapfallout";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0};
        colorBackground[] = {0.2, 0.3, 0.5, 0.0};
        colorBackgroundActive[] = {0.2,0.3,0.5,0.0};
        colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 0.0};
        colorFocused[] = {0.2,0.3,0.5,0.0};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.002;
        offsetPressedX = 0.000;
        offsetPressedY = 0.002;

        borderSize = 0.0;
   };

   class MMA_MAPFALLOUT_BTN2
   {
        type = 1;
        idc = 103;
        style = 2;
        x = 0.25+0.12+0.06; 
        y = 0.25+0.025;
  	w   = 0.02;
  	h   = 0.02;

        sizeEx = 0.02;
  	text = "%";
    
  	action = "[""on_btn2"", _this] call mando_mapfallout";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0};
        colorBackground[] = {0.2, 0.3, 0.5, 0.0};
        colorBackgroundActive[] = {0.2,0.3,0.5,0.0};
        colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 0.0};
        colorFocused[] = {0.2,0.3,0.5,0.0};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.002;
        offsetPressedX = 0.000;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };

};