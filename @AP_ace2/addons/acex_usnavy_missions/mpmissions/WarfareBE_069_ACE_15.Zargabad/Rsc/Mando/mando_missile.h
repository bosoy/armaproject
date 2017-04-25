#define MANDCT_STATIC                0
#define MANDCT_BUTTON                1
#define MANDCT_EDIT                  2
#define MANDCT_SLIDER                3
#define MANDCT_COMBO                 4
#define MANDCT_LISTBOX               5
#define MANDCT_TOOLBOX               6
#define MANDCT_CHECKBOXES            7
#define MANDCT_PROGRESS              8
#define MANDCT_HTML                  9
#define MANDCT_STATIC_SKEW          10
#define MANDCT_ACTIVETEXT           11
#define MANDCT_TREE                 12
#define MANDCT_STRUCTURED_TEXT      13
#define MANDCT_CONTEXT_MENU         14
#define MANDCT_CONTROLS_GROUP       15
#define MANDCT_3DSTATIC             20
#define MANDCT_3DACTIVETEXT         21
#define MANDCT_3DLISTBOX            22
#define MANDCT_3DHTML               23
#define MANDCT_3DSLIDER             24
#define MANDCT_3DEDIT               25
#define MANDCT_XKEYDESC             40
#define MANDCT_XBUTTON              41
#define MANDCT_XLISTBOX             42
#define MANDCT_XSLIDER              43
#define MANDCT_XCOMBO               44
#define MANDCT_ANIMATED_TEXTURE     45
#define MANDCT_OBJECT               80
#define MANDCT_OBJECT_ZOOM          81
#define MANDCT_OBJECT_CONTAINER     82
#define MANDCT_OBJECT_CONT_ANIM     83
#define MANDCT_LINEBREAK            98
#define MANDCT_USER                 99
#define MANDCT_MAP                 100
#define MANDCT_MAP_MAIN            101

#define MANDST_LEFT                  0
#define MANDST_RIGHT                 1
#define MANDST_CENTER                2
#define MANDST_MULTI                16
#define MANDST_TITLE_BAR            32
#define MANDST_PICTURE              48
#define MANDST_FRAME                64
#define MANDST_BACKGROUND           80
#define MANDST_GROUP_BOX            96
#define MANDST_GROUP_BOX2          112
#define MANDST_HUD_BACKGROUND      128
#define MANDST_TILE_PICTURE        144
#define MANDST_WITH_RECT           160
#define MANDST_LINE                176
#define MANDST_NO_RECT           0x200
#define MANDST_SHADOW              256

#define FontMandM               "Bitstream"
#define FontMandHTML            "Bitstream"
#define FontMandMAIN            "TahomaB"

// MISSILE TRACK DLG CONTROLS IDS
#define MISST_DLGMISSILETRACK	20900
#define MISST_MISMANDST_FRAME	20901
#define MISST_CLOSEDLG		20902
#define MISST_MODE		20903
#define MISST_FOLLOW1		20904
#define MISST_FOLLOW2		20915
#define MISST_FOLLOW3		20916
#define MISST_DISTANCE		20907
#define MISST_SPEED		20908
#define MISST_ALTITUDE		20909
#define MISST_ENGINEON		20910
#define MISST_ENGINEOFF		20911
#define MISST_ENDURANCE		20912
#define MISST_GROUNDNO		20913
#define MISST_GROUNDYES		20914





// MCC CONTROLS IDS
#define MCC_DLGMISSILECENTER	21900
#define MCC_FRAME		21901
#define MCC_MAP			21902
#define MCC_CONTACTLIST		21903
#define MCC_CONTACT		21904
#define MCC_TRACK		21905
#define MCC_NOMAP		21906
#define MCC_MAPCONTACT		21907
#define MCC_MAPTARGET		21908
#define MCC_CLOSECONTROL	21909
#define MCC_TARGET		21910
#define MCC_DISTANCE		21911
#define MCC_TTI			21912
#define MCC_ASLT		21913
#define MCC_SPEEDT		21914
#define MCC_DIRT		21915
#define MCC_ANGDT		21916
#define MCC_TYPET		21917
#define MCC_MISSILESLEFT	21918
#define MCC_ACTIVERADAR		21919
#define MCC_ENDURANCE		21920
#define MCC_MAXSPEED		21921
#define MCC_FIREMISSILE		21922
#define MCC_MODE0ALT		21923
#define MCC_MODE0ALTE		21924
#define MCC_CAMERAONOFF		21925
#define MCC_MODE 		21926
#define MCC_FOLLOW1		21927
#define MCC_FOLLOW2		21928
#define MCC_FOLLOW3		21929
#define MCC_DISTANCEM		21930
#define MCC_SPEEDM		21931
#define MCC_ALTITUDEM		21932
#define MCC_ENGINEON		21933
#define MCC_ENGINEOFF		21934
#define MCC_ENDURANCEM		21935
#define MCC_GROUNDNO		21936
#define MCC_GROUNDYES		21937
#define MCC_BACKLEFT            21938
#define MCC_BACKRIGHT           21939
#define MCC_AIMCIRCLE           21940  
#define MCC_MAPMCC              21941
#define MCC_NAVMARK             21942
#define MCC_INRGN               21943
#define MCC_HELP                21944 



#define MISST_DLGMISSILEKEYS    22900
#define MISKEY_OK               22901
#define MISKEY_CANCEL           22902
#define MISKEY_ECM              22903
#define MISKEY_ECMKEY           22904
#define MISKEY_FIRE             22905
#define MISKEY_FIREKEY          22906
#define MISKEY_FLARES           22907
#define MISKEY_FLARESKEY        22908
#define MISKEY_ACTION           22909  
#define MISKEY_REPEAT           22910
#define MISKEY_MODE             22911
#define MISKEY_MODEKEY          22912




class RscMandText
{
        type = MANDCT_STATIC;
        idc = -1;
        style = MANDST_LEFT;
        h = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 1, 1, 1};
        font = FontMandM;
        sizeEx = 0.02;
};


class RscMandPicture
{
        type = MANDCT_STATIC;
        idc = -1;
        style = MANDST_PICTURE;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 1, 1, 1};
        font = FontMandM;
        sizeEx = 0.04;
};


class RscMandButton
{
        type = MANDCT_BUTTON;
        idc = -1;
        style = MANDST_CENTER;
	access = 0;
        colorText[] = {0, 0, 0, 1};
        font = FontMandHTML;
        sizeEx = 0.025;
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;
        colorDisabled[] = {0.3, 0.3, 0.3, 1};
        colorBackground[] = {0.6, 0.6, 0.6, 0.5};
        colorBackgroundActive[] = {0.8,0.8,0.8,0.5};
        colorBackgroundDisabled[] = {0.6, 0.6, 0.6, 1};
        colorFocused[] = {0.6,0.6,0.6,0.7};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};
        offsetX = 0.004;
        offsetY = 0.004;
        offsetPressedX = 0.002;
        offsetPressedY = 0.002;
        borderSize = 0.0;
};

class RscMandBackground
{
        type = MANDCT_STATIC;
        idc = -1;
        style = MANDST_HUD_BACKGROUND;
        colorBackground[] = {0, 0, 0, 0.2};
        colorText[] = {1, 1, 1, 1};
        font = FontMandHTML;
        sizeEx = 0.04;
};


class RscMandFrame
{
        type = MANDCT_STATIC;
        idc = -1;
        style = MANDST_FRAME;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 1, 1, 1};
        font = FontMandM;
        sizeEx = 0.04;
};

class RscMandEdit
{
       type = MANDCT_EDIT;
       idc = -1;
       style = MANDST_LEFT;
       font = FontMandHTML;
       sizeEx = 0.02;
       colorBackground[] = {0,0,0,0};
       colorText[] = {0, 0, 0, 1};
       colorSelection[] = {0.5, 0.5, 0.5, 1};
       autocomplete = false;
       text = "";
};


class RscMandListBox
{
        type = MANDCT_LISTBOX;
        style = MANDST_LEFT;
        idc = -1;
        colorSelect[] = {1.0, 1.0, 1.0, 1};
        colorSelectBackground[] = {0.2, 0.2, 0.2, 0.1};
        colorText[] = {0.0, 0.0, 1.0, 1};
        colorBackground[] = {0.0, 0.0, 0.0, 1};
        font = FontMandHTML;
        sizeEx = 0.025;
        rowHeight = 0.03;
        soundSelect[] = {"", 0.1, 1};
};

class RscMandCombo
{
	access = 0;
	type = MANDCT_COMBO;
	style = 0;
	h = 0.05;
	wholeHeight = 0.25;
        colorSelect[] = {0.0, 0.0, 0.0, 1};
        colorText[] = {1.0, 1.0, 1.0, 1};
        colorBackground[] = {0.0, 0.0, 0.0, 1};
        colorScrollbar[] = {0.2, 0.2, 0.2, 0.1};
        font = FontMandHTML;
	sizeEx = 0.025;
        soundSelect[] = {"", 0.1, 1};
        soundExpand[] = {"", 0.1, 1};
        soundCollapse[] = {"", 0.1, 1};
};


class RscMandSlider
{
	type = MANDCT_SLIDER;
	style = 1024;
	color[] = {0, 0, 0, 1};
//        colorBackground[] = {0, 0, 0, 0};
//        colorText[] = {0, 0, 0, 1};
	angle = 0;
	idc = -1;
	sizeEx = 0.025;
	selection="display";
	w = 0.2;
	h = 0.025;
};


class RscMandMap {
	access = 0;
//	type = MANDCT_MAP_MAIN;
        type = MANDCT_MAP;
	idc = -1;
	style = MANDST_PICTURE;
	colorBackground[] = {1, 1, 1, 1};
	colorText[] = {0, 0, 0, 1};
	font = "TahomaB";
	sizeEx = 0.04;
	colorSea[] = {0.51, 0.8, 0.98, 0.5};
	colorForest[] = {0.6, 0.8, 0.2, 0.5};
	colorRocks[] = {0.5, 0.5, 0.5, 0.5};
	colorCountlines[] = {0.65, 0.45, 0.27, 0.5};
	colorMainCountlines[] = {0.65, 0.45, 0.27, 1};
	colorCountlinesWater[] = {0, 0.53, 1, 0.5};
	colorMainCountlinesWater[] = {0, 0.53, 1, 1};
	colorForestBorder[] = {0.4, 0.8, 0, 1};
	colorRocksBorder[] = {0.5, 0.5, 0.5, 1};
	colorPowerLines[] = {0, 0, 0, 1};
	colorNames[] = {0, 0, 0, 1};
	colorInactive[] = {1, 1, 1, 0.5};
	colorLevels[] = {0, 0, 0, 1};
	fontLabel = "Zeppelin32";
	sizeExLabel = 0.027;
	fontGrid = "Zeppelin32";
	sizeExGrid = 0.027;
	fontUnits = "Zeppelin32";
	sizeExUnits = 0.027;
	fontNames = "Zeppelin32";
	sizeExNames = 0.027;
	fontInfo = "Zeppelin32";
	sizeExInfo = 0.027;
	fontLevel = "Zeppelin32";
	sizeExLevel = 0.027;
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


	class Bunker 
        {
		icon = "\ca\ui\data\map_bunker_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 1.5 * 14 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Bush 
        {
		icon = "\ca\ui\data\map_bush_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 0.2 * 14 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class BusStop 
        {
		icon = "\ca\ui\data\map_busstop_ca.paa";
		color[] = {0, 0, 1, 1};
		size = 10;
		importance = 1 * 10 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Cross 
        {
		icon = "\ca\ui\data\map_cross_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 0.7 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Fortress 
        {
		icon = "\ca\ui\data\map_bunker_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Fuelstation 
        {
		icon = "\ca\ui\data\map_fuelstation_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.75;
		coefMax = 4;
	};
	
	class Fountain 
        {
		icon = "\ca\ui\data\map_fountain_ca.paa";
		color[] = {0, 0.35, 0.7, 1};
		size = 12;
		importance = 1 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Hospital 
        {
		icon = "\ca\ui\data\map_hospital_ca.paa";
		color[] = {0.78, 0, 0.05, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Chapel 
        {
		icon = "\ca\ui\data\map_chapel_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 1 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Church 
        {
		icon = "\ca\ui\data\map_church_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Lighthouse 
        {
		icon = "\ca\ui\data\map_lighthouse_ca.paa";
		color[] = {0.78, 0, 0.05, 1};
		size = 20;
		importance = 3 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Quay 
        {
		icon = "\ca\ui\data\map_quay_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 2 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Rock 
        {
		icon = "\ca\ui\data\map_rock_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 12;
		importance = 0.5 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Ruin 
        {
		icon = "\ca\ui\data\map_ruin_ca.paa";
		color[] = {0.78, 0, 0.05, 1};
		size = 16;
		importance = 1.2 * 16 * 0.05;
		coefMin = 1;
		coefMax = 4;
	};
	
	class SmallTree 
        {
		icon = "\ca\ui\data\map_smalltree_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 0.6 * 12 * 0.05;
		coefMin = 0.25;
		coefMax = 4;
	};
	
	class Stack 
        {
		icon = "\ca\ui\data\map_stack_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 20;
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class Tree 
        {
		icon = "\ca\ui\data\map_tree_ca.paa";
		color[] = {0.55, 0.64, 0.43, 1};
		size = 16;
		importance = 0.9 * 16 * 0.05;
		coefMin = 0.25;
		coefMax = 4;	
	};
	
	class Tourism 
        {
		icon = "\ca\ui\data\map_tourism_ca.paa";
		color[] = {0.78, 0, 0.05, 1};
		size = 16;
		importance = 1 * 16 * 0.05;
		coefMin = 0.7;
		coefMax = 4;
	};
	
	class Transmitter 
        {
		icon = "\ca\ui\data\map_transmitter_ca.paa";
		size = 20;
		color[] = {0, 0.35, 0.7, 1};
		importance = 2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	
	class ViewTower 
        {
		icon = "\ca\ui\data\map_viewtower_ca.paa";
		size = 16;
		color[] = {0, 0.35, 0.7, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;
	};
	
	class Watertower 
        {
		icon = "\ca\ui\data\map_watertower_ca.paa";
		color[] = {0, 0.35, 0.7, 1};
		size = 32;
		importance = 1.2 * 16 * 0.05;
		coefMin = 0.9;
		coefMax = 4;
	};
	class Waypoint 
        {
		icon = "\ca\ui\data\map_waypoint_ca.paa";
		size = 16;
		color[] = {0, 0.35, 0.7, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;		
	};
	
	class WaypointCompleted 
        {
		icon = "\ca\ui\data\map_waypoint_completed_ca.paa";
		size = 16;
		color[] = {0, 0.35, 0.7, 1};
		importance = 2.5 * 16 * 0.05;
		coefMin = 0.5;
		coefMax = 4;		
	};	
};



//HTML control
class RscMandHTML
{
   access = 0;
   type = MANDCT_HTML;
   idc = -1;
   style = 0;
   filename = "";
   colorBackground[] = {0.5, 0.7, 1, 1};
   colorText[] = {0, 0, 0, 1};
   colorBold[] = {0, 0, 0.2, 1};
   colorLink[] = {1, 0.5, 0, 1};
   colorLinkActive[] = {1, 0.5, 0, 1};
   colorPicture[] = {1, 1, 1, 1};
   colorPictureLink[] = {0, 0, 1, 1};
   colorPictureSelected[] = {1, 1, 1, 1};
   colorPictureBorder[] = {0, 0, 0, 0};
   tooltipColorText[] = {0, 0, 0, 1};
   tooltipColorBox[] = {0, 0, 0, 0.5};
   tooltipColorShade[] = {1, 1, 0.7, 1};

   prevPage = "\ca\ui\data\arrow_left_ca.paa";
   nextPage = "\ca\ui\data\arrow_right_ca.paa";

   class H1
   {
      font = FontMandMAIN;
      fontBold = FontMandMAIN;
      sizeEx = 0.02;
   };

   class H2
   {
      font = FontMandMAIN;
      fontBold = FontMandMAIN;
      sizeEx = 0.02;
   };

   class H3
   {
      font = FontMandMAIN;
      fontBold = FontMandMAIN;
      sizeEx = 0.02;

   };

   class H4
   {

      font = FontMandMAIN;

      fontBold = FontMandMAIN;

      
sizeEx = 0.02;
   };

   class H5
   {

      font = FontMandMAIN;

      fontBold = FontMandMAIN;

      sizeEx = 0.02;
   };

   class H6
   {

      font = FontMandMAIN;

      fontBold = FontMandMAIN;

      sizeEx = 0.02;
   };

   class P
   {

      font = FontMandMAIN;

      fontBold = FontMandMAIN;

      sizeEx = 0.02;
   };
};


class DlgMissileTrack
{
  idd = MISST_DLGMISSILETRACK;
  movingEnable = true;
  
  controlsBackground[] = { MISMANDST_BACKGROUND, MISMANDST_FRAME };
  class MISMANDST_BACKGROUND : RscMandBackground
  {
     colorBackground[] = {0, 0.2, 0.4, 0.1};
     text = ;
     sizeEx = 0.015;
     x = 0.0;
     y = 0.0;
     w = 0.22;
     h = 0.215;
  };
  class MISMANDST_FRAME : RscMandText
  {
     idc = MISST_MISMANDST_FRAME;
     style = MANDST_FRAME;
     colorText[] = {1, 1, 0, 1};
     text = "Weapon data";
     font = "Bitstream";
     sizeEx = 0.02;
     x = 0.01;
     y = 0.01;
     w = 0.20;
     h = 0.195;
  };
  objects[] = { };
  controls[] = {CLOSEDLG, MODE, FOLLOW1, FOLLOW2, FOLLOW3, DISTANCE, SPEED, ALTITUDE, ENGINEON, ENGINEOFF, ENDURANCE, GROUNDNO, GROUNDYES};
  class CLOSEDLG : RscMandButton
  {
  	idc = MISST_CLOSEDLG;
  	x = 0.036;
  	y = 0.160;
  	w = 0.14;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "Close dialog";
  	action = "closeDialog 0";
  };
  class MODE : RscMandText
  {
  	idc = MISST_MODE;
  	x = 0.021;
  	y = 0.021;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class FOLLOW1 : RscMandText
  {
  	idc = MISST_FOLLOW1;
  	x = 0.021;
  	y = 0.036;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class FOLLOW2 : RscMandText
  {
  	idc = MISST_FOLLOW2;
  	x = 0.021;
  	y = 0.036;
  	w = 0.2;
  	h = 0.04;
	colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class FOLLOW3 : RscMandText
  {
  	idc = MISST_FOLLOW3;
  	x = 0.021;
  	y = 0.036;
  	w = 0.2;
  	h = 0.04;
	colorText[] = {1, 0, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class DISTANCE : RscMandText
  {
  	idc = MISST_DISTANCE;
  	x = 0.021;
  	y = 0.051;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class SPEED : RscMandText
  {
  	idc = MISST_SPEED;
  	x = 0.021;
  	y = 0.065;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class ALTITUDE : RscMandText
  {
  	idc = MISST_ALTITUDE;
  	x = 0.021;
  	y = 0.080;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class ENGINEON : RscMandText
  {
  	idc = MISST_ENGINEON;
  	x = 0.021;
  	y = 0.095;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class ENGINEOFF : RscMandText
  {
  	idc = MISST_ENGINEOFF;
  	x = 0.021;
  	y = 0.095;
  	w = 0.2;
  	h = 0.04;
	colorText[] = {1, 0, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class ENDURANCE : RscMandText
  {
  	idc = MISST_ENDURANCE;
  	x = 0.021;
  	y = 0.110;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class GROUNDNO : RscMandText
  {
  	idc = MISST_GROUNDNO;
  	x = 0.021;
  	y = 0.125;
  	w = 0.2;
  	h = 0.04;
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
  class GROUNDYES : RscMandText
  {
  	idc = MISST_GROUNDYES;
  	x = 0.021;
  	y = 0.125;
  	w = 0.2;
  	h = 0.04;
        colorText[] = {1, 0, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
	text = "";
  };
};


class DlgMissileKeys
{
  idd = MISST_DLGMISSILEKEYS;
  movingEnable = true;

  onKeyDown = "[""onKeyDown"", _this] call mando_keyconfighandlerfunc";

  controlsBackground[] = { MISKEY_BACKGROUND, MISKEY_FRAME, MISKEY_MODE, MISKEY_MODEKEY, MISKEY_ECM, MISKEY_ECMKEY,MISKEY_FIRE, MISKEY_FIREKEY,MISKEY_FLARES, MISKEY_FLARESKEY, MISKEY_ACTION};
  class MISKEY_BACKGROUND : RscMandBackground
  {
     colorBackground[] = {0, 0.5, 1, 0.9};
     text = ;
     sizeEx = 0.015;
     x = 0.5-0.15;
     y = 0.5-0.15;
     w = 0.30;
     h = 0.32;
  };
  class MISKEY_FRAME : RscMandText
  {
     idc = -1;
     style = MANDST_FRAME;
     colorText[] = {1, 1, 1, 1};
     text = "Mando Missile Key configurator";
     font = "Bitstream";
     sizeEx = 0.025;
     x = 0.5-0.142;
     y = 0.5-0.142;
     w = 0.284;
     h = 0.304;
  };

  class MISKEY_MODE : RscMandText
  {
     idc = MISKEY_MODE;
     colorText[] = {1, 1, 0, 1};
     text = "HUD Mode:";
     font = "Bitstream";
     sizeEx = 0.03;
     x = 0.5-0.145+0.005;
     y = 0.5-0.105+0.03;
     w = 0.12;
     h = 0.02;
  };
  class MISKEY_MODEKEY : RscMandText
  {
     idc = MISKEY_MODEKEY;
     colorText[] = {1, 1, 0, 1};
     text = "?";
     font = "Bitstream";
     sizeEx = 0.03;
     x = 0.48;
     y = 0.5-0.105+0.03;
     w = 0.13;
     h = 0.02;
  };

  class MISKEY_FIRE : RscMandText
  {
     idc = MISKEY_FIRE;
     colorText[] = {1, 1, 0, 1};
     text = "Fire missile:";
     font = "Bitstream";
     sizeEx = 0.03;
     x = 0.5-0.145+0.005;
     y = 0.5-0.105+0.03*2;
     w = 0.14;
     h = 0.02;
  };
  class MISKEY_FIREKEY : RscMandText
  {
     idc = MISKEY_FIREKEY;
     colorText[] = {1, 1, 0, 1};
     text = "?";
     font = "Bitstream";
     sizeEx = 0.03;
     x = 0.48;
     y = 0.5-0.105+0.03*2;
     w = 0.14;
     h = 0.02;
  };

  class MISKEY_FLARES : RscMandText
  {
     idc = MISKEY_FLARES;
     colorText[] = {1, 1, 0, 1};
     text = "Flares/Chaff:";
     font = "Bitstream";
     sizeEx = 0.03;
     x = 0.5-0.145+0.005;
     y = 0.5-0.105+0.03*3;
     w = 0.12;
     h = 0.02;
  };
  class MISKEY_FLARESKEY : RscMandText
  {
     idc = MISKEY_FLARESKEY;
     colorText[] = {1, 1, 0, 1};
     text = "?";
     font = "Bitstream";
     sizeEx = 0.03;
     x = 0.48;
     y = 0.5-0.105+0.03*3;
     w = 0.14;
     h = 0.02;
  };

  class MISKEY_ECM : RscMandText
  {
     idc = MISKEY_ECM;
     colorText[] = {1, 1, 0, 1};
     text = "ECM:";
     font = "Bitstream";
     sizeEx = 0.03;
     x = 0.5-0.145+0.005;
     y = 0.5-0.105+0.03*4;
     w = 0.12;
     h = 0.02;
  };
  class MISKEY_ECMKEY : RscMandText
  {
     idc = MISKEY_ECMKEY;
     colorText[] = {1, 1, 0, 1};
     text = "?";
     font = "Bitstream";
     sizeEx = 0.03;
     x = 0.48;
     y = 0.5-0.105+0.03*4;
     w = 0.13;
     h = 0.02;
  };

  class MISKEY_ACTION : RscMandText
  {
     idc = MISKEY_ACTION;
     style = MANDST_CENTER;
     colorText[] = {1, 1, 1, 1};
     text = "Press key to switch HUD mode";
     font = "Bitstream";
     sizeEx = 0.03;
     x = 0.5-0.12;
     y = 0.5-0.105+0.03*6;
     w = 0.24;
     h = 0.02;
  };


  objects[] = { };
  controls[] = {MISKEY_OK, MISKEY_REPEAT, MISKEY_CANCEL};
  class MISKEY_OK : RscMandButton
  {
  	idc = MISKEY_OK;
  	x = 0.5-0.105+0.005;
  	y = 0.5-0.105+0.032*7;
  	w = 0.065;
  	h = 0.03;
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "Accept";
	action =  "[""onAccept"", []] call mando_keyconfighandlerfunc";  
  };

  class MISKEY_REPEAT : RscMandButton
  {
  	idc = MISKEY_REPEAT;
  	x = 0.5-0.105+0.005+0.068;
  	y = 0.5-0.105+0.032*7;
  	w = 0.065;
  	h = 0.03;
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "Repeat";
	action =  "[""onRepeat"", []] call mando_keyconfighandlerfunc";  
  };

  class MISKEY_CANCEL : RscMandButton
  {
  	idc = MISKEY_CANCEL;
  	x = 0.5-0.105+0.005+0.068*2;
  	y = 0.5-0.105+0.032*7;
  	w = 0.065;
  	h = 0.03;
        font = "Bitstream";
        sizeEx = 0.02;
  	text = "Cancel";
	action =  "[""onCancel"", []] call mando_keyconfighandlerfunc";
  };
};

#include "includes\mando_mcc.h"
#include "includes\mando_mcc_tv.h"
#include "includes\mando_mcc_lrr.h"
#include "includes\mando_rearm.h"
#include "includes\mando_airsupportdlg.h"
#include "includes\mando_getmaptgt.h"
#include "includes\mando_fallout.h"