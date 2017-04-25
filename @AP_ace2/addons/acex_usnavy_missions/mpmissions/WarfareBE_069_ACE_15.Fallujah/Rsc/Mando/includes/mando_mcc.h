// Missile control center dialog
class DlgMissileCenter
{
  idd = MCC_DLGMISSILECENTER;
  movingEnable = true;
  controlsBackground[] = {MCC_BACKGROUND,MCC_FRAME,MCC_BACKGROUNDT,MCC_FRAMET,MCC_FRAMEL,MCC_FRAMEM, MCC_FRAMEMAP, MCC_AIMCIRCLEP, MCC_INRGN};

  class MCC_BACKGROUND : RscMandBackground
  {
     colorBackground[] = {0, 0.1, 0.3, 0.6};
     text = ;
     idc = MCC_BACKLEFT;
     style = MANDST_HUD_BACKGROUND;
     sizeEx = 0.015;
     x = 0.0;
     y = 0.0;
     w = 0.32;
     h = 0.605 + 0.28;
  };
  class MCC_FRAME : RscMandText
  {
     idc = MCC_FRAME;
     style = MANDST_FRAME;
     colorText[] = {0, 1, 0, 1};
     text = "Contacts ( m.)";
     font = "Bitstream";
     sizeEx = 0.02;
     x = 0.01;
     y = 0.01;
     w = 0.30;
     h = 0.585 - 0.035;
  };

  class MCC_BACKGROUNDT : RscMandBackground
  {
     colorBackground[] = {0, 0.1, 0.3, 0.6};
     text = ;
     idc = MCC_BACKRIGHT;
     style = MANDST_HUD_BACKGROUND;
     sizeEx = 0.015;
     x = 1.0-0.32;
     y = 0.0;
     w = 0.32;
     h = 0.605 + 0.28;
  };

  class MCC_FRAMET : RscMandText
  {
     style = MANDST_FRAME;
     colorText[] = {0, 1, 0, 1};
     text = "Tracked target";
     font = "Bitstream";
     sizeEx = 0.02;
     x = 1.0-0.01-0.30;
     y = 0.01;
     w = 0.30;
     h = 0.260;
  };

  class MCC_FRAMEL : RscMandText
  {
     style = MANDST_FRAME;
     colorText[] = {0, 1, 0, 1};
     text = "Launcher";
     font = "Bitstream";
     sizeEx = 0.02;
     x = 1.0-0.01-0.30;
     y = 0.270;
     w = 0.30;
     h = 0.325;
  };

  class MCC_FRAMEMAP : RscMandText
  {
     style = MANDST_FRAME;
     colorText[] = {0, 1, 0, 1};
     text = "Map (+/- zoom in/out, * reset)";
     font = "Bitstream";
     sizeEx = 0.02;
     x = 0.01;
     y = 0.270 + 0.325 - 0.035;
     w = 0.30;
     h = 0.280 + 0.035;
  };


  class MCC_FRAMEM : RscMandText
  {
     style = MANDST_FRAME;
     colorText[] = {0, 1, 0, 1};
     text = "Current weapon Data";
     font = "Bitstream";
     sizeEx = 0.02;
     x = 1.0-0.01-0.30;
     y = 0.270 + 0.325;
     w = 0.30;
     h = 0.28;
  };

   class MCC_AIMCIRCLEP : RscMandPicture
   {
      idc = MCC_AIMCIRCLE;
      colorBackground[] = {0, 0, 0, 0};
      colorText[] = {0, 0.5, 0, 0.5};
      text = "";
      x = 0.5-0.3/2;
      y = 0.5-0.4/2;
      w = 0.3;
      h = 0.4;
   };


  class MCC_INRGN : RscMandText
  {
	idc = MCC_INRGN;
	style = MANDST_CENTER;
  	x = 0.5-0.06;
  	y = 0.6-0.015;
  	w = 0.12;
  	h = 0.03;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };




  objects[] = { };
  controls[] = {CONTACTLIST,CONTACT,TRACK,NOMAP,MAPCONTACT,MAPTARGET,CLOSECONTROL,TARGET,DISTANCE,TTI,ASLT,SPEEDT,TYPET,MISSILESLEFT,ACTIVERADAR,ENDURANCE,MAXSPEED,FIREMISSILE,CAMERAONOFF,MODE,FOLLOW1,FOLLOW2,FOLLOW3,DISTANCEM,SPEEDM,ALTITUDEM,ENGINEON,ENGINEOFF,ENDURANCEM,GROUNDNO,GROUNDYES,DIRT,ANGDT,MODE0ALT,MODE0ALTE,MAP,MCCHELP,MAPMCC,MAPNAV};


   class MAP : RscMandMap 
   {
//	type = MANDCT_MAP;
      type = MANDCT_MAP_MAIN;
      idc = MCC_MAP;
      x = 0.015;
      y = 0.270 + 0.325 + 0.020 - 0.035;
      w = 0.290;
      h = 0.280 - 0.025;

      //sizeEx = 0.02;
      sizeExLabel = 0.02;
      sizeExGrid = 0.02;
      sizeExUnits = 0.02;
      sizeExNames = 0.02;
      sizeExInfo = 0.02;
      sizeExLevel = 0.02;
//      showCountourInterval = "false";


      ShowCountourInterval = 0;

      scaleDefault = 0.100000;
      scaleMax = 1.000000;
      scaleMin = 0.010000;

		
      onMouseZChanged = "";
//      onMouseButtonDown = "_this execVM mando_missile_path+""mcc\mando_mccmousemap.sqf"";true";
//      onMouseButtonDown = "_this call mando_mccmousemap";
      onMouseButtonDown = "true";
      onMouseButtonClick = "true";
      onMouseButtonUp = "true";


      colorBackground[] = {0, 0.7, 0, 0.75};
      colorSea[] = {0, 0.3, 0, 0.5};
      colorForest[] = {0, 0.8, 0, 0.5};
      colorRocks[] = {0, 0.5, 0, 0.5};
      colorCountlines[] = {0, 0.45, 0, 0.5};
      colorMainCountlines[] = {0, 0.45, 0, 1};
      colorCountlinesWater[] = {0, 0.53, 0, 0.5};
      colorMainCountlinesWater[] = {0, 0.53, 0, 1};
      colorForestBorder[] = {0, 0.8, 0, 1};
      colorRocksBorder[] = {0, 0.5, 0, 1};
      colorPowerLines[] = {0, 0, 0, 1};
      colorNames[] = {0, 0, 0, 1};
      colorInactive[] = {1, 1, 1, 0.5};
      colorLevels[] = {0, 0, 0, 1};

      colorRailWay[] = {0.0,0.8,0,1};
      colorOutside[] = {0,0,0,1};
      maxSatelliteAlpha = 0.75;
      alphaFadeStartScale = 0.15;
      alphaFadeEndScale = 0.29;


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
		color[] = {0, 1, 0, 1};
		size = 16;
		importance = 1.5 * 14 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
      };
	
      class Bush 
      {
		icon = "\ca\ui\data\map_bush_ca.paa";
		color[] = {0, 0.64, 0, 1};
		size = 16;
		importance = 0.2 * 14 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
      };
	
      class BusStop 
      {
	        icon = "\ca\ui\data\map_busstop_ca.paa";
		color[] = {0, 1, 0, 1};
		size = 10;
		importance = 1 * 10 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
      };
	
	class Cross 
        {
		icon = "\ca\ui\data\map_cross_ca.paa";
		color[] = {0, 0.64, 0, 1};
		size = 16;
		importance = 0.7 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Fortress 
        {
		icon = "\ca\ui\data\map_bunker_ca.paa";
		color[] = {0, 1, 0, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Fuelstation 
        {
		icon = "\ca\ui\data\map_fuelstation_ca.paa";
		color[] = {0, 1, 0, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.75;
		coefMax = 4;
	};
	
	class Fountain 
        {
		icon = "\ca\ui\data\map_fountain_ca.paa";
		color[] = {0, 0.35, 0, 1};
		size = 12;
		importance = 1 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Hospital 
        {
		icon = "\ca\ui\data\map_hospital_ca.paa";
		color[] = {0, 1, 0, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Chapel 
        {
		icon = "\ca\ui\data\map_chapel_ca.paa";
		color[] = {0, 1, 0, 1};
		size = 16;
		importance = 1 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Church 
        {
		icon = "\ca\ui\data\map_church_ca.paa";
		color[] = {0, 1, 0, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Lighthouse 
        {
		icon = "\ca\ui\data\map_lighthouse_ca.paa";
		color[] = {0, 1, 0, 1};
		size = 20;
		importance = 3 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Quay 
        {
		icon = "\ca\ui\data\map_quay_ca.paa";
		color[] = {0, 0.64, 0, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Rock 
        {
		icon = "\ca\ui\data\map_rock_ca.paa";
		color[] = {0 0.64, 0, 1};
		size = 12;
		importance = 0.5 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Ruin 
        {
		icon = "\ca\ui\data\map_ruin_ca.paa";
		color[] = {0, 1, 0, 1};
		size = 16;
		importance = 1.2 * 16 * 0.05;
		coefMin = 1;
		coefMax = 4;
	};
	
	class SmallTree 
        {
		icon = "\ca\ui\data\map_smalltree_ca.paa";
		color[] = {0, 0.7, 0, 1};
		size = 16;
		importance = 0.6 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Stack 
        {
		icon = "\ca\ui\data\map_stack_ca.paa";
		color[] = {0, 1, 0, 1};
		size = 20;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Tree 
        {
		icon = "\ca\ui\data\map_tree_ca.paa";
		color[] = {0, 0.7, 0, 1};
		size = 16;
		importance = 0.9 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;	
	};
	
	class Tourism 
        {
		icon = "\ca\ui\data\map_tourism_ca.paa";
		color[] = {0, 1, 0, 1};
		size = 16;
		importance = 1 * 16 * 0.05;
		coefMin = 0.7;
		coefMax = 4;
	};
	
	class Transmitter 
        {
		icon = "\ca\ui\data\map_transmitter_ca.paa";
		size = 20;
		color[] = {0, 0.35, 0, 1};
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class ViewTower 
        {
		icon = "\ca\ui\data\map_viewtower_ca.paa";
		size = 16;
		color[] = {0, 0.35, 0, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Watertower 
        {
		icon = "\ca\ui\data\map_watertower_ca.paa";
		color[] = {0, 0.35, 0, 1};
		size = 32;
		importance = 1.2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	class Waypoint 
        {
		icon = "\ca\ui\data\map_waypoint_ca.paa";
		size = 16;
		color[] = {0, 0.35, 0, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;		
	};
	
	class WaypointCompleted 
        {
		icon = "\ca\ui\data\map_waypoint_completed_ca.paa";
		size = 16;
		color[] = {0, 0.35, 0, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;		
	};
   };

   class CONTACTLIST : RscMandListBox
   {
      idc = MCC_CONTACTLIST;
      style = MANDST_LEFT;
      x = 0.021;
      y = 0.030;
      w = 0.28;
      h = 0.4;
      colorText[] = {0.0, 1.0, 0, 1};
      font = "Bitstream";
      sizeEx = 0.02;
      onMouseButtonDown = "_this execVM mando_missile_path+""mcc\mando_mccmousetargets.sqf""";

      maxHistoryDelay = 1;
      autoScrollSpeed = -1;
      autoScrollDelay = 5;
      autoScrollRewind = 0;


      class ScrollBar
      {
         color[] = {1,1,1,0.6};
         colorActive[] = {1,1,1,1};
         colorDisabled[] = {1,1,1,0.3};
         thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
         arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
         arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
         border = "\ca\ui\data\ui_border_scroll_ca.paa";
      };


   };
   
   class CONTACT : RscMandText
   {
	idc = MCC_CONTACT;
	style = MANDST_CENTER + MANDST_WITH_RECT + MANDST_SHADOW;
  	x = 0.021;
  	y = 0.432;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
   };
 
   class TRACK : RscMandButton
   {
  	idc = MCC_TRACK;
   	x = 0.021;
  	y = 0.470;
  	w = 0.28;
  	h = 0.035;
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "Target selected contact";
  	action = "mando_gettarget=true";
   };

  class NOMAP : RscMandButton
  {
  	idc = MCC_NOMAP;
        x = 0.015;
        y = 0.270 + 0.325 + 0.020 - 0.035 + 0.280 - 0.025;
  	w = 0.057;
  	h = 0.035;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "Free";
  	action = "[MCC_NOMAP] execVM mando_missile_path+""mcc\mando_mccmapbuttons.sqf""";
  };
  class MAPCONTACT : RscMandButton
  {
  	idc = MCC_MAPCONTACT;
        x = 0.015+0.058;
        y = 0.270 + 0.325 + 0.020 - 0.035 + 0.280 - 0.025;
  	w = 0.057;
  	h = 0.035;
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "Contact";
  	action = "[MCC_MAPCONTACT] execVM mando_missile_path+""mcc\mando_mccmapbuttons.sqf""";
  };
  class MAPTARGET : RscMandButton
  {
  	idc = MCC_MAPTARGET;
        x = 0.015++0.058*2;
        y = 0.270 + 0.325 + 0.020 - 0.035 + 0.280 - 0.025;
  	w = 0.057;
  	h = 0.035;
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "Target";
  	action = "[MCC_MAPTARGET] execVM mando_missile_path+""mcc\mando_mccmapbuttons.sqf""";
  };
  class MAPMCC : RscMandButton
  {
  	idc = MCC_MAPMCC;
        x = 0.015++0.058*3;
        y = 0.270 + 0.325 + 0.020 - 0.035 + 0.280 - 0.025;
  	w = 0.057;
  	h = 0.035;
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "MCC";
  	action = "[MCC_MAPMCC] execVM mando_missile_path+""mcc\mando_mccmapbuttons.sqf""";
  };
  class MAPNAV : RscMandButton
  {
  	idc = MCC_NAVMARK;
        x = 0.015++0.058*4;
        y = 0.270 + 0.325 + 0.020 - 0.035 + 0.280 - 0.025;
  	w = 0.057;
  	h = 0.035;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "NAV";
  	action = "[MCC_NAVMARK] execVM mando_missile_path+""mcc\mando_mccmapbuttons.sqf""";
  };

  class CLOSECONTROL : RscMandButton
  {
  	idc = MCC_CLOSECONTROL;
  	x = 1.0-0.32+0.021;
  	y = 0.550;
  	w = 0.28;
  	h = 0.035;

        font = "Bitstream";
        sizeEx = 0.02;
  	text = "Exit Weapons Control Center";
  	action = "closeDialog 0";
  };







  class TARGET : RscMandText
  {
	idc = MCC_TARGET;
	style = MANDST_CENTER + MANDST_WITH_RECT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.030;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class DISTANCE : RscMandText
  {
	idc = MCC_DISTANCE;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.070;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class TTI : RscMandText
  {
	idc = MCC_TTI;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.110;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class ASLT : RscMandText
  {
	idc = MCC_ASLT;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.150;
  	w = 0.14;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class SPEEDT : RscMandText
  {
	idc = MCC_SPEEDT;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021+0.15;
  	y = 0.150;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class DIRT : RscMandText
  {
	idc = MCC_DIRT;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.190;
  	w = 0.14;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class ANGDT : RscMandText
  {
	idc = MCC_ANGDT;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021+0.15;
  	y = 0.190;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };

  class TYPET : RscMandText
  {
	idc = MCC_TYPET;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.230;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };





  class MISSILESLEFT : RscMandText
  {
	idc = MCC_MISSILESLEFT;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.290;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "Weapons left:";
  };

  class ACTIVERADAR : RscMandText
  {
	idc = MCC_ACTIVERADAR;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.330;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "Weapon active seeker range:";
  };

  class ENDURANCE : RscMandText
  {
	idc = MCC_ENDURANCE;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.370;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "Weapon endurance:";
  };
  class MAXSPEED : RscMandText
  {
	idc = MCC_MAXSPEED;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.410;
  	w = 0.28;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "Weapon max speed:";
  };

  class FIREMISSILE : RscMandButton
  {
  	idc = MCC_FIREMISSILE;
   	x = 0.021;
  	y = 0.550 - 0.035;
  	w = 0.28;
  	h = 0.035;
        font = "Bitstream";
        colorText[] = {1, 1, 1, 1};
        sizeEx = 0.02;
  	text = "FIRE";
  	action = "mando_firemissile = true";
  };

  class MODE0ALT : RscMandText
  {
  	idc = MCC_MODE0ALT;
	style = MANDST_LEFT + MANDST_SHADOW;
  	x = 1.0-0.32+0.021;
  	y = 0.470;
  	w = 0.14;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "Alt ASL modes 0/1";
  };

  class MODE0ALTE : RscMandEdit
  {
  	idc = MCC_MODE0ALTE;
	style = MANDST_RIGHT;
  	x = 1.0-0.32+0.021+0.15;
  	y = 0.470;
  	w = 0.07;
  	h = 0.037;
        colorText[] = {0, 1, 0, 1};
	text = "";
  };

  class CAMERAONOFF : RscMandButton
  {
  	idc = MCC_CAMERAONOFF;
  	x = 1.0-0.32+0.021;
  	y = 0.510;
  	w = 0.28;
  	h = 0.035;
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "Weapon Camera is OFF";
  	action = "[]exec mando_missile_path+""mcc\mando_misilcamonoff.sqs""";
  };





  class MODE : RscMandText
  {
  	idc = MCC_MODE;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.02;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class FOLLOW1 : RscMandText
  {
  	idc = MCC_FOLLOW1;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.05;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class FOLLOW2 : RscMandText
  {
  	idc = MCC_FOLLOW2;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.05;
  	w = 0.2;
  	h = 0.04;
	colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class FOLLOW3 : RscMandText
  {
  	idc = MCC_FOLLOW3;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.05;
  	w = 0.2;
  	h = 0.04;
	colorText[] = {1, 0, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class DISTANCEM : RscMandText
  {
  	idc = MCC_DISTANCEM;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.08;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class SPEEDM : RscMandText
  {
  	idc = MCC_SPEEDM;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.11;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class ALTITUDEM : RscMandText
  {
  	idc = MCC_ALTITUDEM;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.14;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class ENGINEON : RscMandText
  {
  	idc = MCC_ENGINEON;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.17;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class ENGINEOFF : RscMandText
  {
  	idc = MCC_ENGINEOFF;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.17;
  	w = 0.2;
  	h = 0.04;
	colorText[] = {1, 0, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class ENDURANCEM : RscMandText
  {
  	idc = MCC_ENDURANCEM;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.20;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class GROUNDNO : RscMandText
  {
  	idc = MCC_GROUNDNO;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.23;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class GROUNDYES : RscMandText
  {
  	idc = MCC_GROUNDYES;
        x = 1.0-0.32+0.021;
        y = 0.270 + 0.325 + 0.23;
  	w = 0.2;
  	h = 0.04;
        colorText[] = {1, 0, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };

  class MCCHELP : RscMandHTML
  {
  	idc = MCC_HELP;
        x = 0.32;
        y = 0.0;
  	w = 0.36;
  	h = 1.0;
  };
};
