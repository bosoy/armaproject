class MandoAirSupportDlgSetUp
{
   idd = 24000;
   movingEnable = true;
   onLoad = "[""onLoad"", _this] call mando_airsupportdlgsetup";
   controlsBackground[] = {COMMANDSETUP_BACKGROUND,COMMANDSETUP_TOPBAR,COMMANDSETUP_BOTTOMBAR,COMMANDSETUP_LEFTBAR,COMMANDSETUP_RIGHTBAR,COMMANDSETUP_LAPTOP,COMMANDSETUP_FRAME,COMMANDSETUP_INFO};

   class COMMANDSETUP_BACKGROUND
   {
      type = 0;
      colorBackground[] = {0, 0.1, 0.3, 1};
      colorText[] = {1, 1, 1, 1};
      text = "";
      idc = 24001;
      style = 80 + 2;
      sizeEx = 0.05;
      font = "Bitstream";

      x = -0.5;
      y = 0;
      w = 2;
      h = 1;
   };


   class COMMANDSETUP_TOPBAR
   {
      type = 0;
      colorBackground[] = {0, 0, 0, 1};
      colorText[] = {1, 1, 1, 1};
      text = ;
      idc = -1;
      style = 0;
      sizeEx = 0.015;
      font = "Bitstream";

      x = -2;
      y = -2;
      w = 5;
      h = 2;
   };

   class COMMANDSETUP_BOTTOMBAR
   {
      type = 0;
      colorBackground[] = {0, 0, 0, 1};
      colorText[] = {1, 1, 1, 1};
      text = ;
      idc = -1;
      style = 0;
      sizeEx = 0.015;
      font = "Bitstream";

      x = -2;
      y = 1;
      w = 5;
      h = 2;
   };


   class COMMANDSETUP_LEFTBAR
   {
      type = 0;
      colorBackground[] = {0, 0, 0, 1};
      colorText[] = {1, 1, 1, 1};
      text = ;
      idc = -1;
      style = 0;
      sizeEx = 0.015;
      font = "Bitstream";

      x = -2;
      y = -2;
      w = 2;
      h = 4;
   };

   class COMMANDSETUP_RIGHTBAR
   {
      type = 0;
      colorBackground[] = {0, 0, 0, 1};
      colorText[] = {1, 1, 1, 1};
      text = ;
      idc = -1;
      style = 0;
      sizeEx = 0.015;
      font = "Bitstream";

      x = 1;
      y = -2;
      w = 2;
      h = 4;
   };



   class COMMANDSETUP_LAPTOP
   {
        idc = 100;
        x = (0.5-(safeZoneW/2)) min (0.5 - 0.65);
        y = (0.5-safeZoneH/2) min (0.5 - 0.48*4/3);
        w = safeZoneW max 1.3;
        h = safeZoneH max (.96*4/3);

	text = "";
        type = 0;
        style = 48;
        colorBackground[] = {1, 1, 1, 1};
        colorText[] = {1, 1, 1, 1};
        font = "TahomaB";
        sizeEx = 0.04;
   };

   class COMMANDSETUP_FRAME
   {
      idc = 24002;
      type = 0;
      style = 64;
      colorBackground[] = {0, 0, 0, 0};
      colorText[] = {1, 1, 1, 1};
      text = "Mando Air Support Setup and Info";
      font = "Bitstream";
      sizeEx = 0.02;
      x = 0.005;
      y = 0.0;
      w = 0.99;
      h = 0.99;
   };

   class COMMANDSETUP_INFO
   {
      access = 0;
      type = 13;
      idc = 24004;
      style = 2 + 16;
      lineSpacing = 1;
      x = 0.05;
      y = 0.05;
      w = 0.9;
      h = 0.4;
      size = 0.020;
      colorBackground[] = {0,0,0,0};
      colorText[] = {0,0,0,0};
      text = "";
      font = "BitStream";
      class Attributes 
      {
         font = "BitStream";
         color = "#ffffff";
         align = "left";
         shadow = true;
      };

   };


   controls[] = {COMMANDSETUP_CLOSE,COMMANDSETUP_OPT1_FRAME,COMMANDSETUP_OPT1,COMMANDSETUP_OPT2_FRAME,COMMANDSETUP_OPT2,COMMANDSETUP_OPT3_FRAME,COMMANDSETUP_OPT3,COMMANDSETUP_OPT4_FRAME,COMMANDSETUP_OPT4,COMMANDSETUP_OPT5_FRAME,COMMANDSETUP_OPT5};


   class COMMANDSETUP_OPT1_FRAME
   {
      idc = 24005;
      type = 0;
      style = 64;
      colorBackground[] = {0, 0, 0, 0};
      colorText[] = {1, 1, 1, 1};
      text = "Option 1";
      font = "Bitstream";
      sizeEx = 0.02;
      x = 0.01;
      y = 0.5;
      w = 0.19;
      h = 0.4;
   };

   class COMMANDSETUP_OPT1
   {
        type = 5;
        style = 0;
 	idc = 24006;

	x   = 0.015;
	y   = 0.52;
  	w   = 0.18;
  	h   = 0.37;
        onLBSelChanged = "[""onItemChanged1"", _this] call mando_airsupportdlgsetup";
        colorSelect[] = {0, 1.0, 0, 1};
        colorSelectBackground[] = {0.4, 0.4, 0.4, 0.4};
        colorText[] = {0.2, 0.85, 0, 1};
        colorBackground[] = {0.0, 0.0, 1.0, 0.8};
        font = "Bitstream";
        sizeEx = 0.02;
        rowHeight = 0.03;
        soundSelect[] = {"", 0.1, 1};

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


   class COMMANDSETUP_OPT2_FRAME
   {
      idc = 24007;
      type = 0;
      style = 64;
      colorBackground[] = {0, 0, 0, 0};
      colorText[] = {1, 1, 1, 1};
      text = "Option 1";
      font = "Bitstream";
      sizeEx = 0.02;
      x = 0.01 + 0.2;
      y = 0.5;
      w = 0.19;
      h = 0.4;
   };

   class COMMANDSETUP_OPT2
   {
        type = 5;
        style = 0;
 	idc = 24008;

	x   = 0.015+0.2;
	y   = 0.52;
  	w   = 0.18;
  	h   = 0.37;
        onLBSelChanged = "[""onItemChanged2"", _this] call mando_airsupportdlgsetup";
        colorSelect[] = {0, 1.0, 0, 1};
        colorSelectBackground[] = {0.4, 0.4, 0.4, 0.4};
        colorText[] = {0.2, 0.85, 0, 1};
        colorBackground[] = {0.0, 0.0, 1.0, 0.8};
        font = "Bitstream";
        sizeEx = 0.02;
        rowHeight = 0.03;
        soundSelect[] = {"", 0.1, 1};

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

   class COMMANDSETUP_OPT3_FRAME
   {
      idc = 24009;
      type = 0;
      style = 64;
      colorBackground[] = {0, 0, 0, 0};
      colorText[] = {1, 1, 1, 1};
      text = "Option 1";
      font = "Bitstream";
      sizeEx = 0.02;
      x = 0.01 + 0.2*2;
      y = 0.5;
      w = 0.19;
      h = 0.4;
   };

   class COMMANDSETUP_OPT3
   {
        type = 5;
        style = 0;
 	idc = 24010;

	x   = 0.015+0.2*2;
	y   = 0.52;
  	w   = 0.18;
  	h   = 0.37;
        onLBSelChanged = "[""onItemChanged3"", _this] call mando_airsupportdlgsetup";
        colorSelect[] = {0, 1.0, 0, 1};
        colorSelectBackground[] = {0.4, 0.4, 0.4, 0.4};
        colorText[] = {0.2, 0.85, 0, 1};
        colorBackground[] = {0.0, 0.0, 1.0, 0.8};
        font = "Bitstream";
        sizeEx = 0.02;
        rowHeight = 0.03;
        soundSelect[] = {"", 0.1, 1};

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

   class COMMANDSETUP_OPT4_FRAME
   {
      idc = 24011;
      type = 0;
      style = 64;
      colorBackground[] = {0, 0, 0, 0};
      colorText[] = {1, 1, 1, 1};
      text = "Option 1";
      font = "Bitstream";
      sizeEx = 0.02;
      x = 0.01 + 0.2*3;
      y = 0.5;
      w = 0.19;
      h = 0.4;
   };

   class COMMANDSETUP_OPT4
   {
        type = 5;
        style = 0;
 	idc = 24012;

	x   = 0.015+0.2*3;
	y   = 0.52;
  	w   = 0.18;
  	h   = 0.37;
        onLBSelChanged = "[""onItemChanged4"", _this] call mando_airsupportdlgsetup";
        colorSelect[] = {0, 1.0, 0, 1};
        colorSelectBackground[] = {0.4, 0.4, 0.4, 0.4};
        colorText[] = {0.2, 0.85, 0, 1};
        colorBackground[] = {0.0, 0.0, 1.0, 0.8};
        font = "Bitstream";
        sizeEx = 0.02;
        rowHeight = 0.03;
        soundSelect[] = {"", 0.1, 1};

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


   class COMMANDSETUP_OPT5_FRAME
   {
      idc = 24013;
      type = 0;
      style = 64;
      colorBackground[] = {0, 0, 0, 0};
      colorText[] = {1, 1, 1, 1};
      text = "Option 1";
      font = "Bitstream";
      sizeEx = 0.02;
      x = 0.01 + 0.2*4;
      y = 0.5;
      w = 0.179;
      h = 0.4;
   };

   class COMMANDSETUP_OPT5
   {
        type = 5;
        style = 0;
 	idc = 24014;

	x   = 0.015+0.2*4;
	y   = 0.52;
  	w   = 0.169;
  	h   = 0.37;
        onLBSelChanged = "[""onItemChanged5"", _this] call mando_airsupportdlgsetup";
        colorSelect[] = {0, 1.0, 0, 1};
        colorSelectBackground[] = {0.4, 0.4, 0.4, 0.4};
        colorText[] = {0.2, 0.85, 0, 1};
        colorBackground[] = {0.0, 0.0, 1.0, 0.8};
        font = "Bitstream";
        sizeEx = 0.02;
        rowHeight = 0.03;
        soundSelect[] = {"", 0.1, 1};

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


   class COMMANDSETUP_CLOSE
   {
        type = 1;
        idc = 24003;
        style = 2;

	x   = 0.765+0.055*3;
  	y   = 1-0.06;
  	w   = 0.055;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "Close";
  	action = "CloseDialog 24000";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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
};



class MandoAirSupportDlg
{
   idd = 23900;
   movingEnable = true;
   onLoad = "[""onLoad"", _this] call mando_airsupportdlg";


   controlsBackground[] = {COMMAND_TOPBAR,COMMAND_BOTTOMBAR, COMMAND_LEFTBAR,COMMAND_RIGHTBAR,COMMAND_LAPTOP, COMMAND_BACKGROUND,COMMAND_BACKGROUND2, COMMAND_FRAME1,COMMAND_FRAME2,COMMAND_LEFTT,COMMAND_CAMERA, COMMAND_STATE1,COMMAND_STATE2,COMMAND_STATE3,COMMAND_STATE4,COMMAND_CURRENT,COMMAND_DIR,COMMAND_ALTT,COMMAND_RECCAMERA,COMMAND_RECCAMERATEXT, COMMAND_RECCAMERAPIC,COMMAND_RECCAMERATARGET,COMMAND_RECCAMERATARGETRECT, COMMAND_RECCAMERATARGETRECT1, COMMAND_RECCAMERATARGETRECT2, COMMAND_RECCAMERATARGETRECT3, COMMAND_RECCAMERATARGETTEXT1, COMMAND_RECCAMERATARGETTEXT2, COMMAND_RECCAMERATARGETTEXT3,COMMAND_RECCAMERADIR_N, COMMAND_RECCAMERADIR_E, COMMAND_RECCAMERADIR_S, COMMAND_RECCAMERADIR_W, COMMAND_RECCAMERATARGETDATA, COMMAND_MSG, COMMAND_LINE};

   class COMMAND_LAPTOP
   {
        idc = 100;
/*
        x = 0.5 - 0.65;
        y = 0.5 - 0.48*4/3;
        w = 1.3;
        h = .96*4/3;
*/
        x = (0.5-(safeZoneW/2)) min (0.5 - 0.65);
        y = (0.5-safeZoneH/2) min (0.5 - 0.48*4/3);
        w = safeZoneW max 1.3;
        h = safeZoneH max (.96*4/3);

	text = "";
        type = 0;
        style = 48;
        colorBackground[] = {1, 1, 1, 1};
        colorText[] = {1, 1, 1, 1};
        font = "TahomaB";
        sizeEx = 0.04;
   };

   class COMMAND_BACKGROUND
   {
      type = 0;
      colorBackground[] = {0, 0.1, 0.3, 1};
      colorText[] = {1, 1, 1, 1};
      text = ;
      idc = 23933;
      style = 80;
      sizeEx = 0.015;
      font = "Bitstream";

      x = 0.75;
      y = 0.0;
      w = 0.25;
      h = 0.7;
   };

   class COMMAND_TOPBAR
   {
      type = 0;
      colorBackground[] = {0, 0, 0, 1};
      colorText[] = {1, 1, 1, 1};
      text = ;
      idc = -1;
      style = 0;
      sizeEx = 0.015;
      font = "Bitstream";

      x = -2;
      y = -2;
      w = 5;
      h = 2;
   };

   class COMMAND_BOTTOMBAR
   {
      type = 0;
      colorBackground[] = {0, 0, 0, 1};
      colorText[] = {1, 1, 1, 1};
      text = ;
      idc = -1;
      style = 0;
      sizeEx = 0.015;
      font = "Bitstream";

      x = -2;
      y = 1;
      w = 5;
      h = 2;
   };


   class COMMAND_LEFTBAR
   {
      type = 0;
      colorBackground[] = {0, 0, 0, 1};
      colorText[] = {1, 1, 1, 1};
      text = ;
      idc = 23962;
      style = 0;
      sizeEx = 0.015;
      font = "Bitstream";

      x = -2;
      y = -2;
      w = 2;
      h = 4;
   };

   class COMMAND_RIGHTBAR
   {
      type = 0;
      colorBackground[] = {0, 0, 0, 1};
      colorText[] = {1, 1, 1, 1};
      text = ;
      idc = 23963;
      style = 0;
      sizeEx = 0.015;
      font = "Bitstream";

      x = 1;
      y = -2;
      w = 2;
      h = 4;
   };

   class COMMAND_BACKGROUND2
   {
      type = 0;
      colorBackground[] = {0, 1, 0, 0.5};
      colorText[] = {1, 1, 1, 1};
      text = ;
      idc = 23934;
      style = 80;
      sizeEx = 0.015;
      font = "Bitstream";

      x = 0.75;
      y = 0.7;
      w = 0.25;
      h = 0.3;
   };

   class COMMAND_FRAME1
   {
      idc = 23935;
      type = 0;
      style = 64;
      colorBackground[] = {0, 0, 0, 0};
      colorText[] = {1, 1, 1, 1};
      text = "Mando Air Support Console";
      font = "Bitstream";
      sizeEx = 0.02;
      x = 0.755;
      y = 0.0;
      w = 0.24;
      h = 0.7;
   };

   class COMMAND_FRAME2
   {
      idc = 23936;
      type = 0;
      style = 64;
      colorBackground[] = {0, 0, 0, 0};
      colorText[] = {1, 1, 1, 1};
      text = "Target area";
      font = "Bitstream";
      sizeEx = 0.02;
      x = 0.755;
      y = 0.7;
      w = 0.24;
      h = 0.29;
   };

   class COMMAND_LEFTT
   {
  	idc = 23902;
	x   = 0.765;
	y   = 0.09+0.043*3 - 0.04;
  	w = 0.2;
  	h = 0.04;
	text = "Aircrafts available:";
        type = 0;
        style = 0;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class COMMAND_CAMERA
   {
  	idc = 23904;
        x = 0.755;
        y = 0.7;
        w = 0.24;
        h = 0.29;
	text = "No Line Of Sight";
        type = 0;
        style = 2;
        colorBackground[] = {0, 0.2, 0, 1};
        colorText[] = {0, 1, 0, 1};
        font = "TahomaB";
        sizeEx = 0.04;
   };

   class COMMAND_RECCAMERA
   {
        idc = 23931;
        x = 0;
        y = 0;
        w = 0.75;
        h = 1;
	text = "";
        type = 0;
        style = 2;
        colorBackground[] = {0, 0, 1, 0.2};
        colorText[] = {1, 1, 1, 0.3};
        font = "TahomaB";
        sizeEx = 0.04;
   };

   class COMMAND_RECCAMERATEXT
   {
      access = 0;
      type = 13;
      idc = 23954;
      style = 2 + 16;
      lineSpacing = 1;
      x = 0.5 - 0.35;
      y = 0.5 - 0.2-0.04;
      w = 0.7;
      h = 0.05;
      size = 0.020;
      colorBackground[] = {0,0,0,0};
      colorText[] = {0,0,0,0};
      text = "Camera steerable area (left click to mark, right click to hide console)";
      font = "BitStream";
      class Attributes 
      {
         font = "BitStream";
         color = "#ffffff";
         align = "center";
         shadow = true;
      };
   };

   class COMMAND_RECCAMERAPIC
   {
        idc = 23943;
        x = 0.5 - 0.2;
        y = 0.5 - 0.2;
        w = 0.4;
        h = 0.4;
	text = "";
        type = 0;
        style = 48;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0, 0, 1};
        font = "TahomaB";
        sizeEx = 0.04;
   };


   class COMMAND_RECCAMERATARGET
   {
        idc = 23938;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class COMMAND_RECCAMERATARGETRECT
   {
        idc = 23940;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };


   class COMMAND_RECCAMERATARGETRECT1
   {
        idc = 23948;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class COMMAND_RECCAMERATARGETRECT2
   {
        idc = 23949;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class COMMAND_RECCAMERATARGETRECT3
   {
        idc = 23950;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class COMMAND_RECCAMERATARGETTEXT1
   {
      idc = 23951;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.1;
      h = 0.03;
      colorText[] = {0, 1, 0, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "";
   };

   class COMMAND_RECCAMERATARGETTEXT2
   {
      idc = 23952;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.1;
      h = 0.03;
      colorText[] = {0, 1, 0, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "";
   };

   class COMMAND_RECCAMERATARGETTEXT3
   {
      idc = 23953;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.1;
      h = 0.03;
      colorText[] = {0, 1, 0, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "";
   };


   class COMMAND_RECCAMERADIR_N
   {
      idc = 23955;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.02;
      h = 0.02;
      colorText[] = {0.5, 1, 0.5, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "N";
   };

   class COMMAND_RECCAMERADIR_E
   {
      idc = 23956;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.02;
      h = 0.02;
      colorText[] = {0.5, 1, 0.5, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "E";
   };

   class COMMAND_RECCAMERADIR_S
   {
      idc = 23957;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.02;
      h = 0.02;
      colorText[] = {0.5, 1, 0.5, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "S";
   };

   class COMMAND_RECCAMERADIR_W
   {
      idc = 23958;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.02;
      h = 0.02;
      colorText[] = {0.5, 1, 0.5, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "W";
   };


   class COMMAND_RECCAMERATARGETDATA
   {
      access = 0;
      type = 13;
      idc = 23939;
      style = 2 + 16;
      lineSpacing = 1;
      x = 0.38; 
      y = 0.7;
      w = 0.6;
      h = 0.12;
      size = 0.020;
      colorBackground[] = {0,0,0,0};
      colorText[] = {0,0,0,0};
      text = "";
      font = "BitStream";
      class Attributes 
      {
         font = "BitStream";
         color = "#ffffff";
         align = "left";
         shadow = true;
      };
   };

   class COMMAND_LINE
   {
      idc = 23947;
      type = 0;
      style = 176;
      x = 0.5;
      y = 0.5;
      w = 0.1;
      h = 0.1;
      colorText[] = {0.5, 1, 0.5, 1};
      colorBackground[] = {1, 0, 0, 1};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "";
   };


   class COMMAND_STATE1
   {
  	idc = 23905;
	x   = 0.765;
	y   = 0.09+0.043*7 - 0.04;
  	w = 0.2;
  	h = 0.04;
	text = "Plane 1: ----";
        type = 0;
        style = 0;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class COMMAND_STATE2
   {
  	idc = 23906;
	x   = 0.765;
	y   = 0.09+0.043*7.5 - 0.04;
  	w = 0.2;
  	h = 0.04;
	text = "Plane 2: ----";
        type = 0;
        style = 0;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class COMMAND_STATE3
   {
  	idc = 23907;
	x   = 0.765;
	y   = 0.09+0.043*8 - 0.04;
  	w = 0.2;
  	h = 0.04;
	text = "Plane 3: ----";
        type = 0;
        style = 0;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class COMMAND_STATE4
   {
  	idc = 23908;
	x   = 0.765;
	y   = 0.09+0.043*8.5 - 0.04;
  	w = 0.2;
  	h = 0.04;
	text = "Plane 4: ----";
        type = 0;
        style = 0;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class COMMAND_CURRENT
   {
  	idc = 23912;
	x   = 0.765;
  	y   = 0.09+0.043*9 - 0.04;
  	w = 0.2;
  	h = 0.04;
	text = "";
        type = 0;
        style = 0;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class COMMAND_DIR
   {
  	idc = 23911;
	x   = 0.765;
  	y   = 0.041*0+0.02;
  	w = 0.2;
  	h = 0.04;
	text = "Ingress direction: 0";
        type = 0;
        style = 0;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class COMMAND_ALTT
   {
  	idc = 23921;
	x   = 0.765;
  	y   = 0.041*2+0.02;
  	w = 0.2;
  	h = 0.04;
	text = "Ingress min alt: 0";
        type = 0;
        style = 0;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

   class COMMAND_MSG
   {
  	idc = 23942;
	x   = 0.;
	y   = 1-0.04;
  	w = 0.75;
  	h = 0.04;
	text = "MSG:";
        type = 0;
        style = 0;
        colorBackground[] = {0, 0, 0, 1};
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };



   controls[]={ COMMAND_LEFT,COMMAND_DUMMY,COMMAND_CAS,COMMAND_BOMBRUN,COMMAND_FREEFALL,COMMAND_SADARM,COMMAND_SETUP,COMMAND_LZ,COMMAND_REC_MOUSE,COMMAND_REC_FIRE,COMMAND_REC_FLIR,COMMAND_MAP_SMALL,COMMAND_MAP,COMMAND_CAS_CA,COMMAND_PARA,COMMAND_CRUISEM,COMMAND_MISSAT,COMMAND_AMMO,COMMAND_VEH,COMMAND_REINF,COMMAND_CAP,COMMAND_RC,COMMAND_EV,COMMAND_LA,COMMAND_ZOOMIN,COMMAND_ZOOMOUT,COMMAND_INGRESS,COMMAND_ALT,COMMAND_REC_ON,COMMAND_REC_OFF,COMMAND_CLOSE,COMMAND_OVERLAY};

   class COMMAND_INGRESS
   {
      type = 3;
      idc = 23920;
      style = 1024;

      angle = 0;
      sizeEx = 0.025;
      selection="display";

      x   = 0.765;
      y   = 0.041*1+0.02;
      w   = 0.22;
      h   = 0.03;
      color[] = {0, 1, 0, 1};
      colorActive[] = {0, 1, 0, 1};
      text = "";
      onSliderPosChanged = "[""INGRESS_CHANGE"", []] call mando_airsupportdlg";
   };


   class COMMAND_ALT
   {
      type = 3;
      idc = 23922;
      style = 1024;

      angle = 0;
      sizeEx = 0.025;
      selection="display";

      x   = 0.765;
      y   = 0.041*3+0.02;
      w   = 0.22;
      h   = 0.03;
      color[] = {0, 1, 0, 1};
      colorActive[] = {0, 1, 0, 1};
      text = "";
      onSliderPosChanged = "[""INGRESS_ALT_CHANGE"", []] call mando_airsupportdlg";
   };


   class COMMAND_LEFT
   {
        type = 5;
        style = 0;
 	idc = 23901;

	x   = 0.765;
	y   = 0.08+0.043*4 - 0.04;
  	w   = 0.22;
  	h   = 0.125;

        colorSelect[] = {0, 1.0, 0, 1};
        colorSelectBackground[] = {0.4, 0.4, 0.4, 0.4};
        colorText[] = {0.2, 0.85, 0, 1};
        colorBackground[] = {0.0, 0.0, 1.0, 0.8};
        font = "Bitstream";
        sizeEx = 0.02;
        rowHeight = 0.03;
        soundSelect[] = {"", 0.1, 1};

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


   class COMMAND_CAS
   {
        type = 1;
        idc = 23909;
        style = 2;
/*
	x   = 0.765;
  	y   = 0.043*5+0.3 - 0.04;
  	w   = 0.04;
  	h   = 0.04;
*/
	x   = 0.765+0.001;
  	y   = 0.043*5+0.3 - 0.04;
  	w   = 0.051;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "CAS";
  	action = "[""CALL_CAS"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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


   class COMMAND_DUMMY
   {
        type = 1;
        idc = -1;
        style = 2;

	x   = -2;
  	y   = -2;
  	w   = 0.051;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "-";
  	action = "";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = true;

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


   class COMMAND_BOMBRUN
   {
        type = 1;
        idc = 23910;
        style = 2;
/*
	x   = 0.765 + 0.04 + 0.003;
  	y   = 0.043*5+0.3 - 0.04;
  	w   = 0.05;
  	h   = 0.04;
*/
	x   = 0.765+0.055;
  	y   = 0.043*5+0.3 - 0.04;
  	w   = 0.053;
  	h   = 0.04;


        sizeEx = 0.02;
  	text = "B. RUN";
  	action = "[""CALL_BOMB_RUN"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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

   class COMMAND_SETUP
   {
        type = 1;
        idc = 23944;
        style = 2;

	x   = 0.765;
  	y   = 0.043*6+0.3 - 0.04;
  	w   = 0.22-0.057;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "Setup and info";
  	action = "createDialog ""MandoAirSupportDlgSetUp""";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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

   class COMMAND_LZ
   {
        type = 1;
        idc = 23961;
        style = 2;
	x   = 0.765+0.055*3;
  	y   = 0.043*6+0.3 - 0.04;
  	w   = 0.055;
  	h   = 0.04;

        sizeEx = 0.018;

  	text = "JUMP";
  	action = "[""CALL_JUMP"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
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


   class COMMAND_REC_FIRE
   {
        type = 1;
        idc = 23946;
        style = 2;
        x = 0.30; 
        y = 0.7;
  	w   = 0.08;
  	h   = 0.04;


        sizeEx = 0.02;
  	text = "Fire";
  	action = "[""CALL_REC_FIRE"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 1};
        colorBackground[] = {0.8, 0, 0, 0.5};
        colorBackgroundActive[] = {1,0,0,0.5};
        colorBackgroundDisabled[] = {0.8, 0, 0, 1};
        colorFocused[] = {0.8,0,0,0.7};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.004;
        offsetY = 0.004;
        offsetPressedX = 0.002;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };

   class COMMAND_REC_FLIR
   {
        type = 1;
        idc = 23960;
        style = 2;
        x = 0.62; 
        y = 0.7;
  	w   = 0.08;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "FLIR";
  	action = "[""CALL_REC_FLIR"", []] call mando_airsupportdlg";
        SetFocus = "false";

	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 1};
        colorBackground[] = {0.8, 0, 0, 0.5};
        colorBackgroundActive[] = {1,0,0,0.5};
        colorBackgroundDisabled[] = {0.8, 0, 0, 1};
        colorFocused[] = {0.8,0,0,0.7};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.004;
        offsetY = 0.004;
        offsetPressedX = 0.002;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };


   class COMMAND_CAS_CA
   {
        type = 1;
        idc = 23915;
        style = 2;

	x   = 0.765;
  	y   = 0.043*7+0.3 - 0.04;
  	w   = 0.053;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "GS (-)";
  	action = "[""CALL_CAS_CA"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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

   class COMMAND_PARA
   {
        type = 1;
        idc = 23916;
        style = 2;

	x   = 0.765+0.055;
  	y   = 0.043*7+0.3 - 0.04;
  	w   = 0.053;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "AB (-)";
  	action = "[""CALL_PARAS"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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

   class COMMAND_CRUISEM
   {
        type = 1;
        idc = 23917;
        style = 2;

	x   = 0.765+0.055*2;
  	y   = 0.043*7+0.3 - 0.04;
  	w   = 0.053;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "CM (-)";
  	action = "[""CALL_CRUISEMISSILE"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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

   class COMMAND_MISSAT
   {
        type = 1;
        idc = 23928;
        style = 2;

	x   = 0.765+0.055*3;
  	y   = 0.043*7+0.3 - 0.04;
  	w   = 0.055;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "SA (-)";
  	action = "[""CALL_MISSILESAT"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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


   class COMMAND_RC
   {
        type = 1;
        idc = 23923;
        style = 2;

//	x   = 0.765+0.055*3;
	x   = 0.765;
//  	y   = 0.043*7+0.3 - 0.04;
  	y   = 0.043*8+0.302;
  	w   = 0.053;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "RC (-)";
  	action = "[""CALL_RECO"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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


   class COMMAND_EV
   {
        type = 1;
        idc = 23941;
        style = 2;

//	x   = 0.765+0.055*3;
	x   = 0.765 + 0.055;
//  	y   = 0.043*7+0.3 - 0.04;
  	y   = 0.043*8+0.302;
  	w   = 0.053;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "EV (-)";
  	action = "[""CALL_EVAC"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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

   class COMMAND_LA
   {
        type = 1;
        idc = 23945;
        style = 2;

//	x   = 0.765+0.055*3;
	x   = 0.765+0.055*2;
//  	y   = 0.043*7+0.3 - 0.04;
  	y   = 0.043*8+0.302;
  	w   = 0.053;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "LA (-)";
  	action = "[""CALL_LASER"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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



   class COMMAND_AMMO
   {
        type = 1;
        idc = 23924;
        style = 2;

	x   = 0.765;
  	y   = 0.043*8+0.3 - 0.04;
  	w   = 0.053;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "AM (-)";
  	action = "[""CALL_AMMO"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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

   class COMMAND_VEH
   {
        type = 1;
        idc = 23925;
        style = 2;

	x   = 0.765+0.055;
  	y   = 0.043*8+0.3 - 0.04;
  	w   = 0.053;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "VE (-)";
  	action = "[""CALL_VEH"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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

   class COMMAND_REINF
   {
        type = 1;
        idc = 23926;
        style = 2;

	x   = 0.765+0.055*2;
  	y   = 0.043*8+0.3 - 0.04;
  	w   = 0.053;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "RE (-)";
  	action = "[""CALL_REINF"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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

   class COMMAND_CAP
   {
        type = 1;
        idc = 23927;
        style = 2;

	x   = 0.765+0.055*3;
  	y   = 0.043*8+0.3 - 0.04;
  	w   = 0.055;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "CP (-)";
  	action = "[""CALL_CAP"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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


   class COMMAND_FREEFALL
   {
        type = 1;
        idc = 23913;
        style = 2;
/*
	x   = 0.765 + 0.04 + 0.003*2 + 0.05 ;
  	y   = 0.043*5+0.3 - 0.04;
  	w   = 0.06;
  	h   = 0.04;
*/
	x   = 0.765+0.055*2;
  	y   = 0.043*5+0.3 - 0.04;
  	w   = 0.053;
  	h   = 0.04;


        sizeEx = 0.02;
  	text = "Free f.";
  	action = "[""FREE_FALL"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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


   class COMMAND_SADARM
   {
        type = 1;
        idc = 23914;
        style = 2;
	x   = 0.765+0.055*3;
  	y   = 0.043*5+0.3 - 0.04;
  	w   = 0.055;
  	h   = 0.04;

        sizeEx = 0.018;

  	text = "SADARM";
  	action = "[""SADARM"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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


   class COMMAND_CLOSE
   {
        type = 1;
        idc = 23937;
        style = 2;

//	x   = 0.765;
	x   = 0.765+0.055*3;
  	y   = 0.043*8+0.302;
//   	w  = 0.055;
  	w   = 0.055;
  	h   = 0.04;

        sizeEx = 0.02;
  	text = "CB (-)";
  	action = "[""CALL_CARPET"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {0, 0, 0, 1};
        font = "Bitstream";
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


   class COMMAND_ZOOMIN
   {
        type = 1;
        idc = 23918;
        style = 2;

        x = 0.756;
        y = 0.7 + 0.02;
  	w   = 0.02;
  	h   = 0.02;

        sizeEx = 0.02;
  	text = "+";
  	action = "[""ZOOM_IN"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0};
        colorBackground[] = {0.6, 0.6, 0.6, 0.1};
        colorBackgroundActive[] = {0.8,0.8,0.8,0.1};
        colorBackgroundDisabled[] = {0.6, 0.6, 0.6, 0.1};
        colorFocused[] = {0.6,0.6,0.6,0.7};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.004;
        offsetY = 0.004;
        offsetPressedX = 0.002;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };

   class COMMAND_ZOOMOUT
   {
        type = 1;
        idc = 23919;
        style = 2;

        x = 0.756 + 0.02;
        y = 0.7 + 0.02;
  	w   = 0.02;
  	h   = 0.02;

        sizeEx = 0.02;
  	text = "-";
  	action = "[""ZOOM_OUT"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0};
        colorBackground[] = {0.6, 0.6, 0.6, 0.1};
        colorBackgroundActive[] = {0.8,0.8,0.8,0.1};
        colorBackgroundDisabled[] = {0.6, 0.6, 0.6, 0.1};
        colorFocused[] = {0.6,0.6,0.6,0.7};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.004;
        offsetY = 0.004;
        offsetPressedX = 0.002;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };


   class COMMAND_REC_ON
   {
        type = 1;
        idc = 23929;
        style = 2;

        x = 0.756 + 0.021*2;
        y = 0.7 + 0.02;
  	w   = 0.056;
  	h   = 0.02;


        sizeEx = 0.02;
  	text = "RC ON+";
        action = "[""CALL_RC_ON"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0.2};
        colorBackground[] = {0.6, 0.6, 0.6, 0.2};
        colorBackgroundActive[] = {0.8,0.8,0.8,0.2};
        colorBackgroundDisabled[] = {0.6, 0.6, 0.6, 0.2};
        colorFocused[] = {0.6,0.6,0.6,0.7};
        colorShadow[] = {0,0,0,0};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.004;
        offsetY = 0.004;
        offsetPressedX = 0.002;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };

   class COMMAND_REC_OFF
   {
        type = 1;
        idc = 23930;
        style = 2;

        x = 0.756 + 0.021*2 + 0.057;
        y = 0.7 + 0.02;
  	w   = 0.056;
  	h   = 0.02;

        sizeEx = 0.02;
  	text = "RC OFF";
  	action = "[""CALL_RC_OFF"", []] call mando_airsupportdlg";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0.2};
        colorBackground[] = {0.6, 0.6, 0.6, 0.2};
        colorBackgroundActive[] = {0.8,0.8,0.8,0.2};
        colorBackgroundDisabled[] = {0.6, 0.6, 0.6, 0.2};
        colorFocused[] = {0.6,0.6,0.6,0.7};
        colorShadow[] = {0,0,0,0};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.004;
        offsetY = 0.004;
        offsetPressedX = 0.002;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };


   class COMMAND_REC_MOUSE
   {
      type = 15;
      idc = 23932;
      style = 0;
      x = 1; y = 1;
      w = 0.75; h = 1;

      onMouseMoving = "[""onMouseMoving"", _this] call mando_airsupportdlg";
      onMouseZChanged  = "[""onMouseZChanged"", _this] call mando_airsupportdlg";
      onMouseButtonDown  = "[""onCameraClick"", _this] call mando_airsupportdlg";

      class VScrollbar
      {
         autoScrollSpeed = -1;
         autoScrollDelay = 5;
         autoScrollRewind = 0;

         color[] = {0,0,0,0};
         width = 0.021;
      };
 
      class HScrollbar
      {
         color[] = {0,0,0,0};
         height = 0.028;
      };
 
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

      class Controls {};
   };


   class COMMAND_MAP
   {
      access = 0;
      type = 101;
      style = 48;

      idc = 23903;
      x = 0;
      y = 0;
      w = 0.75;
      h = 1-0.04;
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
      onMouseButtonDown = "[""onMapClick"", _this] call mando_airsupportdlg";
//      onMouseButtonDown = "if ((_this select 1) == 0) then {mando_com_coords = ((findDisplay 23900) displayCtrl 23903) ctrlMapScreenToWorld [_this select 2, _this select 3]}";
     


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

   class COMMAND_MAP_SMALL
   {
      access = 0;
      type = 101;
      style = 48;

      idc = 23959;
      x = 0;
      y = 0;
      w = 0.25*3/4;
      h = 0.25;
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
      onMouseButtonDown = "[""onMapClick"", _this] call mando_airsupportdlg";
//      onMouseButtonDown = "if ((_this select 1) == 0) then {mando_com_coords = ((findDisplay 23900) displayCtrl 23903) ctrlMapScreenToWorld [_this select 2, _this select 3]}";
     


      colorBackground[] = {0, 0.7, 0, 1};
      colorText[] = {0, 0, 0, 1};
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
      colorRailWay[] = {0.0,0.8,0,1};
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

   class COMMAND_OVERLAY
   {
  	idc = 25000;
	x   = 0;
	y   = 0;
  	w = 1;
  	h = 1;
	text = "";
        type = 0;
        style = 0;
        colorBackground[] = {0, 0, 0, 1};
        colorText[] = {0, 1, 0, 1};
        font = "Bitstream";
        sizeEx = 0.02;
   };

};