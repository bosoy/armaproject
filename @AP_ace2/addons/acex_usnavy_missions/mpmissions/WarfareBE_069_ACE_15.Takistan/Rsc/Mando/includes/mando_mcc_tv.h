class MandoMissileTVDlg
{
   idd = 23900;
   movingEnable = true;
   onLoad = "[""onLoad"", _this] call mando_missile_tv";
   onKeyDown = "[""onKeyDown"", _this] call mando_missile_tv";

   controlsBackground[] = {MMA_TV_BLACK_UP, MMA_TV_BLACK_DOWN, MMA_TV_BLACK_LEFT, MMA_TV_BLACK_RIGHT,MMA_TV_CAMERA,MMA_TV_CAMERATEXT,MMA_TV_CAMERAPIC,MMA_TV_CAMERATARGET,MMA_TV_CAMERATARGETROMBE, MMA_TV_CAMERATARGETRECT, MMA_TV_CAMERATARGETRECT1, MMA_TV_CAMERATARGETRECT2, MMA_TV_CAMERATARGETRECT3, MMA_TV_CAMERATARGETRECT4, MMA_TV_CAMERATARGETRECT5, MMA_TV_CAMERATARGETRECT6, MMA_TV_CAMERATARGETTEXT1, MMA_TV_CAMERATARGETTEXT2, MMA_TV_CAMERATARGETTEXT3,MMA_TV_CAMERATARGETTEXT4,MMA_TV_CAMERATARGETTEXT5,MMA_TV_CAMERATARGETTEXT6,MMA_TV_CAMERA_LEFTARROW, MMA_TV_CAMERA_RIGHTARROW, MMA_TV_CAMERADIR_N, MMA_TV_CAMERADIR_E, MMA_TV_CAMERADIR_S, MMA_TV_CAMERADIR_W, MMA_TV_CAMERATARGETDATA,MMA_LINE,MMA_TV_INFO};

   class MMA_TV_BLACK_UP
   {
        type = 0;
        idc = -1;
        style = 0;
        x = -1.5;
        y = -0.5;
        w = 3.5;
        h = 0.31;
        text = "";
        colorBackground[] = {0, 0, 0, 1};
        colorText[] = {1, 1, 1, 1};
        font = FontMandM;
        sizeEx = 0.02;
   };

   class MMA_TV_BLACK_DOWN
   {
        type = 0;
        idc = -1;
        style = 0;
        x = -1.5;
        y = 1.19;
        w = 3.5;
        h = 0.31;
        text = "";
        colorBackground[] = {0, 0, 0, 1};
        colorText[] = {1, 1, 1, 1};
        font = FontMandM;
        sizeEx = 0.02;
   };

   class MMA_TV_BLACK_LEFT
   {
        type = 0;
        idc = -1;
        style = 0;
        x = -1.5;
        y = -0.2;
        w = 1.41;
        h = 1.4;
        text = "";
        colorBackground[] = {0, 0, 0, 1};
        colorText[] = {1, 1, 1, 1};
        font = FontMandM;
        sizeEx = 0.02;
   };

   class MMA_TV_BLACK_RIGHT
   {
        type = 0;
        idc = -1;
        style = 0;
        x = 1.09;
        y = -0.2;
        w = 1.41;
        h = 1.4;
        text = "";
        colorBackground[] = {0, 0, 0, 1};
        colorText[] = {1, 1, 1, 1};
        font = FontMandM;
        sizeEx = 0.02;
   };


   class MMA_TV_CAMERA
   {
      idc = 23901;
      x = -0.1;
      y = -0.2;
      w = 1.2;
      h = 1.4;
      text = "";
      type = 0;
//      style = 2;
      style = 48;
      colorBackground[] = {0, 0, 0, 0};
      colorText[] = {1, 1, 1, 1};
      font = "TahomaB";
      sizeEx = 0.04;
   };

   class MMA_TV_CAMERATEXT
   {
      access = 0;
      type = 13;
      idc = 23902;
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

   class MMA_TV_CAMERAPIC
   {
        idc = 23903;
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


   class MMA_TV_CAMERATARGET
   {
        idc = 23904;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = -2+0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MMA_TV_CAMERATARGETRECT
   {
        idc = 23905;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = -2+0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MMA_TV_CAMERATARGETROMBE
   {
        idc = 23929;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = -2+0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };


   class MMA_TV_CAMERATARGETRECT1
   {
        idc = 23930;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = -2+0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MMA_TV_CAMERATARGETRECT2
   {
        idc = 23931;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = -2+0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MMA_TV_CAMERATARGETRECT3
   {
        idc = 23932;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = -2+0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MMA_TV_CAMERATARGETRECT4
   {
        idc = 23933;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = -2+0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MMA_TV_CAMERATARGETRECT5
   {
        idc = 23934;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = -2+0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MMA_TV_CAMERATARGETRECT6
   {
        idc = 23935;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0.5};
        text = "";
        x = 0.5-0.03/2;
        y = -2+0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };


   class MMA_TV_CAMERATARGETTEXT1
   {
      idc = 23940;
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

   class MMA_TV_CAMERATARGETTEXT2
   {
      idc = 23941;
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

   class MMA_TV_CAMERATARGETTEXT3
   {
      idc = 23942;
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

   class MMA_TV_CAMERATARGETTEXT4
   {
      idc = 23943;
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

   class MMA_TV_CAMERATARGETTEXT5
   {
      idc = 23944;
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

   class MMA_TV_CAMERATARGETTEXT6
   {
      idc = 23945;
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

   class MMA_TV_CAMERA_LEFTARROW
   {
        idc = 23950;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 0, 0, 0.75};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MMA_TV_CAMERA_RIGHTARROW
   {
        idc = 23951;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 0, 0, 0.75};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };



   class MMA_TV_CAMERADIR_N
   {
      idc = 23912;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = -0.2 - 0.05;
      w = 0.02;
      h = 0.02;
      colorText[] = {0.5, 1, 0.5, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "N";
   };

   class MMA_TV_CAMERADIR_E
   {
      idc = 23913;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = -0.2 - 0.05;
      w = 0.02;
      h = 0.02;
      colorText[] = {0.5, 1, 0.5, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "E";
   };

   class MMA_TV_CAMERADIR_S
   {
      idc = 23914;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = -0.2 - 0.05;
      w = 0.02;
      h = 0.02;
      colorText[] = {0.5, 1, 0.5, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "S";
   };

   class MMA_TV_CAMERADIR_W
   {
      idc = 23915;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = -0.2 - 0.05;
      w = 0.02;
      h = 0.02;
      colorText[] = {0.5, 1, 0.5, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "W";
   };


   class MMA_TV_CAMERATARGETDATA
   {
      access = 0;
      type = 13;
      idc = 23916;
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

   class MMA_LINE
   {
      idc = 23917;
      type = 0;
      style = 176;
      x = 0.5;
      y = 0.5;
      w = 0.001;
      h = 0.001;
      colorText[] = {0.5, 1, 0.5, 1};
      colorBackground[] = {1, 0, 0, 1};
      font = "Bitstream";
      sizeEx = 0.02;
      text = "";
   };

   class MMA_TV_INFO
   {
      idc = 23923;
      type = 0;
      style = 2;
      x = 0.5 - 0.2;
      y = 0.85;
      w = 0.4;
      h = 0.06;
      colorText[] = {1, 1, 1, 1};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.05;
      text = "";
   };


   controls[]= {MMA_TV_MOUSE,MMA_TV_FIRE,MMA_TV_XMIT,MMA_TV_MODE,MMA_TV_TARGETS,MMA_TV_FLIR,MMA_TV_MAPONOFF,MMA_TV_HELP,MMA_TV_MAP_SMALL,MMA_TV_HELPHTML,MMA_TV_UP,MMA_TV_DOWN};


class MMA_TV_HELPHTML
{
   idc = 23924;
      x = 0.5-0.432;
      y = 0.497-0.4845-0.0005;
      w = 0.432*2;
      h = 0.4845*2;

   access = 0;
   type = 9;

   style = 0;

   filename = "";
   colorBackground[] = {0, 0, 0, 1};
   colorText[] = {1,1,1,1};
   colorLink[] = {0.6,0.8392,0.4706,1};
   colorBold[] = {0.543,0.5742,0.4102,1};
   colorLinkActive[] = {1,0.537,0,1};

   colorPicture[] = {1, 1, 1, 1};
   colorPictureSelected[] = {1, 1, 1, 1};
   colorPictureBorder[] = {0, 0, 0, 0};
   colorPictureLink[] = {0.5, 0.5, 1, 1};
   tooltipColorText[] = {0, 0, 0, 1};
   tooltipColorBox[] = {0, 0, 0, 0.5};
   tooltipColorShade[] = {1, 1, 0.7, 1};

 sizeEx = 0.03921;
 prevPage = "\ca\ui\data\arrow_left_ca.paa";
 nextPage = "\ca\ui\data\arrow_right_ca.paa";
 class H1
 {
  font = "Zeppelin32";
  fontBold = "Zeppelin33";
  sizeEx = 0.041;
  align = "left";
 };
 class H2
 {
  font = "Zeppelin32";
  fontBold = "Zeppelin33";
  sizeEx = 0.03921;
  align = "left";
 };
 class H3
 {
  font = "Zeppelin32";
  fontBold = "Zeppelin33";
  sizeEx = 0.03921;
  align = "left";
 };
 class H4
 {
  font = "Zeppelin33Italic";
  fontBold = "Zeppelin33";
  sizeEx = 0.03921;
  align = "left";
 };
 class H5
 {
  font = "Zeppelin32";
  fontBold = "Zeppelin33";
  sizeEx = 0.03921;
  align = "left";
 };
 class H6
 {
  font = "Zeppelin32";
  fontBold = "Zeppelin33";
  sizeEx = 0.03921;
  align = "left";
 };
 class P
 {
  font = "Zeppelin32";
  fontBold = "Zeppelin33";
  sizeEx = 0.03921;
  align = "left";
 };


};



   class MMA_TV_FIRE
   {
        type = 1;
        idc = 23918;
        style = 2;
        x = 1.02; 
        y = 0.17-0.004-1;
  	w   = 0.075;
  	h   = 0.075*4/3;


        sizeEx = 0.02;
  	text = "Fire";
  	action = "[""CALL_TV_FIRE"", []] call mando_missile_tv";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0.0};
        colorBackground[] = {0.8, 0, 0, 0.0};
        colorBackgroundActive[] = {1,0,0,0.0};
        colorBackgroundDisabled[] = {0.8, 0, 0, 0.0};
        colorFocused[] = {0.8,0,0,0.0};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.0024;
        offsetPressedX = 0.000;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };

   class MMA_TV_XMIT
   {
        type = 1;
        idc = 23927;
        style = 2;
        x = 1.02; 
        y = 0.315-1;
  	w   = 0.075;
  	h   = 0.075*4/3;


        sizeEx = 0.02;
  	text = "XMT F6";
  	action = "[""CALL_TV_XMIT"", []] call mando_missile_tv";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0.0};
        colorBackground[] = {0.8, 0, 0, 0.0};
        colorBackgroundActive[] = {1,0,0,0.0};
        colorBackgroundDisabled[] = {0.8, 0, 0, 0.0};
        colorFocused[] = {0.8,0,0,0.0};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.0024;
        offsetPressedX = 0.000;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };

   class MMA_TV_UP
   {
        type = 1;
        idc = 23960;
        style = 2;
        x = 1.02; 
        y = 0.61-1;
  	w   = 0.075;
  	h   = 0.075*4/3;


        sizeEx = 0.02;
  	text = "UP F7";
  	action = "[""CALL_TV_UP"", []] call mando_missile_tv";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0.0};
        colorBackground[] = {0.8, 0, 0, 0.0};
        colorBackgroundActive[] = {1,0,0,0.0};
        colorBackgroundDisabled[] = {0.8, 0, 0, 0.0};
        colorFocused[] = {0.8,0,0,0.0};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.0024;
        offsetPressedX = 0.000;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };

   class MMA_TV_DOWN
   {
        type = 1;
        idc = 23961;
        style = 2;
        x = 1.02; 
        y = 0.755-1;
  	w   = 0.075;
  	h   = 0.075*4/3;


        sizeEx = 0.02;
  	text = "DWN F8";
  	action = "[""CALL_TV_DOWN"", []] call mando_missile_tv";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0.0};
        colorBackground[] = {0.8, 0, 0, 0.0};
        colorBackgroundActive[] = {1,0,0,0.0};
        colorBackgroundDisabled[] = {0.8, 0, 0, 0.0};
        colorFocused[] = {0.8,0,0,0.0};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.0024;
        offsetPressedX = 0.000;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };


   class MMA_TV_MODE
   {
        type = 1;
        idc = 23921;
        style = 2;
        x = -0.090; 
        y = 0.61-1;
  	w   = 0.076;
  	h   = 0.075*4/3;


        sizeEx = 0.02;
  	text = "S.Au F4";
  	action = "[""CALL_TV_MODE"", []] call mando_missile_tv";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 1};
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

   class MMA_TV_HELP
   {
        type = 1;
        idc = 23925;
        style = 2;
        x = -0.094; 
        y = 0.17-0.004-1;
  	w   = 0.076;
  	h   = 0.075*4/3;


        sizeEx = 0.02;
  	text = "HELP F1";
  	action = "[""CALL_TV_HELP"", []] call mando_missile_tv";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 0.0};
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
        borderSize = 0.00;
   };


   class MMA_TV_MAPONOFF
   {
        type = 1;
        idc = 23926;
        style = 2;
        x = -0.093; 
        y = 0.315 - 1;
  	w   = 0.076;
  	h   = 0.075*4/3;



        sizeEx = 0.02;
  	text = "MAP F2";
  	action = "[""CALL_TV_MAP"", []] call mando_missile_tv";
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


   class MMA_TV_TARGETS
   {
        type = 1;
        idc = 23922;
        style = 2;
        x = -0.089; 
        y = 0.46-1;
  	w   = 0.0765;
  	h   = 0.075*4/3;



        sizeEx = 0.02;
  	text = "Local F3";
  	action = "[""CALL_TV_TARGETS"", []] call mando_missile_tv";
	access = ReadAndWrite;
        colorText[] = {1, 1, 1, 1};
        font = "Bitstream";
	soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
        soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
        soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
        soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
        default = false;

        colorDisabled[] = {0.3, 0.3, 0.3, 1};
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


   class MMA_TV_FLIR
   {
        type = 1;
        idc = 23919;
        style = 2;
        x = -0.090; 
        y = 0.755-1;
  	w   = 0.076;
  	h   = 0.075*4/3;


        sizeEx = 0.02;
  	text = "FLIR F5";
  	action = "[""CALL_TV_FLIR"", []] call mando_missile_tv";
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
        colorBackground[] = {0.2, 0.3, 0.5, 0.0};
        colorBackgroundActive[] = {0.2,0.3,0.5,0.0};
        colorBackgroundDisabled[] = {0.5, 0.5, 0.5, 0.0};
        colorFocused[] = {0.2,0.3,0.5,0.2};
        colorShadow[] = {0,0,0,0.1};
        colorBorder[] = {0,0,0,1};

        offsetX = 0.000;
        offsetY = 0.002;
        offsetPressedX = 0.000;
        offsetPressedY = 0.002;
        borderSize = 0.0;
   };


   class MMA_TV_MOUSE
   {
      type = 15;
      idc = -1;
      style = 0;
      x = 0; y = 0;
      w = 0.75; h = 1;

      onMouseMoving = "[""onMouseMoving"", _this] call mando_missile_tv";
      onMouseZChanged  = "[""onMouseZChanged"", _this] call mando_missile_tv";
      onMouseButtonDown  = "[""onCameraClick"", _this] call mando_missile_tv";

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


   class MMA_TV_MAP_SMALL
   {
      access = 0;
      type = 101;
      style = 48;

      idc = 23920;

      x = 0.5-0.429;
      y = 0.497-0.484-0.002;
      w = 0.429*2;
      h = 0.484*2;

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
      onMouseButtonDown = "[""onMapClick"", _this] call mando_missile_tv";     


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
};
