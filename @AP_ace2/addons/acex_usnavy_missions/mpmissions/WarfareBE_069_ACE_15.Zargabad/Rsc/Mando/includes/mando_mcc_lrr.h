class MandoMissileLRRDlg
{
   idd = 23900;
   movingEnable = true;
   onLoad = "[""onLoad"", _this] call mando_missile_lrr";
   onKeyDown = "[""onKeyDown"", _this] call mando_missile_lrr";

   controlsBackground[] = {MMA_LRR_BLACK_UP, MMA_LRR_BLACK_DOWN, MMA_LRR_BLACK_LEFT, MMA_LRR_BLACK_RIGHT,MMA_LRR_CAMERA,MMA_LRR_CAMERATEXT,MMA_LRR_CAMERAPIC,MMA_LRR_CAMERATARGET,MMA_LRR_CAMERATARGETROMBE, MMA_LRR_CAMERATARGETRECT, 
   MMA_LRR_CAMERATARGETRECT1, MMA_LRR_CAMERATARGETRECT2, MMA_LRR_CAMERATARGETRECT3, MMA_LRR_CAMERATARGETRECT4, MMA_LRR_CAMERATARGETRECT5, MMA_LRR_CAMERATARGETRECT6, MMA_LRR_CAMERATARGETRECT7,MMA_LRR_CAMERATARGETRECT8,MMA_LRR_CAMERATARGETRECT9,MMA_LRR_CAMERATARGETRECT10,
   MMA_LRR_CAMERATARGETTEXT1, MMA_LRR_CAMERATARGETTEXT2, MMA_LRR_CAMERATARGETTEXT3, MMA_LRR_CAMERATARGETTEXT4, MMA_LRR_CAMERATARGETTEXT5, MMA_LRR_CAMERATARGETTEXT6, MMA_LRR_CAMERATARGETTEXT7, MMA_LRR_CAMERATARGETTEXT8, MMA_LRR_CAMERATARGETTEXT9, MMA_LRR_CAMERATARGETTEXT10,
   MMA_LRR_CAMERA_LEFTARROW, MMA_LRR_CAMERA_RIGHTARROW, MMA_LRR_LSTATUS,MMA_LRR_CAMERADIR_N, MMA_LRR_CAMERADIR_E, MMA_LRR_CAMERADIR_S, MMA_LRR_CAMERADIR_W, MMA_LRR_CAMERATARGETDATA,MMA_LINE,MMA_LRR_INFO,
   MMA_LRR_MIS1,MMA_LRR_MIS2,MMA_LRR_MIS3,MMA_LRR_MIS4,MMA_LRR_MIS5,MMA_LRR_MIS6,MMA_LRR_LINE_DIR,MMA_LRR_LINE1};

   class MMA_LRR_BLACK_UP
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

   class MMA_LRR_BLACK_DOWN
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

   class MMA_LRR_BLACK_LEFT
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

   class MMA_LRR_BLACK_RIGHT
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


   class MMA_LRR_CAMERA
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

   class MMA_LRR_CAMERATEXT
   {
      idc = 23902;
      type = 0;
      style = 2;
      x = 0.5-0.429;
      y = 0.497-0.484-0.002;
      w = 0.429*2;
      h = 0.484*2;
      colorText[] = {1, 1, 1, 1};
      colorBackground[] = {0, 0, 0, 1};
      font = "Bitstream";
      sizeEx = 0.05;
      text = "";
   };

   class MMA_LRR_CAMERAPIC
   {
        idc = 23903;
        x = 0.137;
        y = 0.011;
        w = 0.726;
        h = 0.968;
		text = "";
        type = 0;
        style = 48;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 0.5};
        font = "TahomaB";
        sizeEx = 0.04;
   };


   class MMA_LRR_CAMERATARGET
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

   class MMA_LRR_CAMERATARGETRECT
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

   class MMA_LRR_CAMERATARGETROMBE
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


   class MMA_LRR_CAMERATARGETRECT1
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

   class MMA_LRR_CAMERATARGETRECT2
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

   class MMA_LRR_CAMERATARGETRECT3
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

   class MMA_LRR_CAMERATARGETRECT4
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

   class MMA_LRR_CAMERATARGETRECT5
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

   class MMA_LRR_CAMERATARGETRECT6
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

   class MMA_LRR_CAMERATARGETRECT7
   {
        idc = 23936;
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

   class MMA_LRR_CAMERATARGETRECT8
   {
        idc = 23937;
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

   class MMA_LRR_CAMERATARGETRECT9
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
        y = -2+0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MMA_LRR_CAMERATARGETRECT10
   {
        idc = 23939;
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


   
   class MMA_LRR_CAMERATARGETTEXT1
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

   class MMA_LRR_CAMERATARGETTEXT2
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

   class MMA_LRR_CAMERATARGETTEXT3
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

   class MMA_LRR_CAMERATARGETTEXT4
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

   class MMA_LRR_CAMERATARGETTEXT5
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

   class MMA_LRR_CAMERATARGETTEXT6
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

   class MMA_LRR_CAMERATARGETTEXT7
   {
      idc = 23946;
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

   class MMA_LRR_CAMERATARGETTEXT8
   {
      idc = 23947;
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

   class MMA_LRR_CAMERATARGETTEXT9
   {
      idc = 23948;
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
   
   class MMA_LRR_CAMERATARGETTEXT10
   {
      idc = 23949;
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
   
   
   class MMA_LRR_CAMERA_LEFTARROW
   {

      idc = 23950;		
      access = 0;
      type = 13;
      style = 2 + 16;
      lineSpacing = 1;
        x = 0.137;
        y = 0.015;
        w = 0.2;
        h = 0.2;
      size = 0.020;
      colorBackground[] = {0,0,0,0};
      colorText[] = {0,0,0,0};
      text = "";
      font = "EtelkaNarrowMediumPro";
      class Attributes 
      {
         font = "EtelkaNarrowMediumPro";
         color = "#00ff00";
         align = "left";
         shadow = false;
      };
   };

   class MMA_LRR_CAMERA_RIGHTARROW
   {
        idc = 23951;
      access = 0;
      type = 13;
      style = 2 + 16;
      lineSpacing = 1;
        x = 1-0.137-0.11;
        y = 0.015;
        w = 0.2;
        h = 0.2;
      size = 0.020;
      colorBackground[] = {0,0,0,0};
      colorText[] = {0,0,0,0};
      text = "";
      font = "BitStream";
      class Attributes 
      {
         font = "BitStream";
         color = "#00ff00";
         align = "left";
         shadow = false;
      };		
   };

   class MMA_LRR_LSTATUS
   {
      idc = 23952;		
      access = 0;
      type = 13;
      style = 2 + 16;
      lineSpacing = 1;
        x = 0.137;
        y = 0.915;
        w = 0.3;
        h = 0.2;
      size = 0.020;
      colorBackground[] = {0,0,0,0};
      colorText[] = {0,0,0,0};
      text = "";
      font = "EtelkaNarrowMediumPro";
      class Attributes 
      {
         font = "EtelkaNarrowMediumPro";
         color = "#00ff00";
         align = "left";
         shadow = false;
      };
   };


   class MMA_LRR_CAMERADIR_N
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

   class MMA_LRR_CAMERADIR_E
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

   class MMA_LRR_CAMERADIR_S
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

   class MMA_LRR_CAMERADIR_W
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


   class MMA_LRR_CAMERATARGETDATA
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

   class MMA_LRR_INFO
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

   class MMA_LRR_MIS1
   {
        idc = 22100;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        text = "";
        x = -2;
        y = -2;
        w = 0.01*3/4;
        h = 0.01;
   };
   class MMA_LRR_MIS2
   {
        idc = 22101;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        text = "";
        x = -2;
        y = -2;
        w = 0.01*3/4;
        h = 0.01;
   };
   class MMA_LRR_MIS3
   {
        idc = 22102;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        text = "";
        x = -2;
        y = -2;
        w = 0.01*3/4;
        h = 0.01;
   };
   class MMA_LRR_MIS4
   {
        idc = 22103;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        text = "";
        x = -2;
        y = -2;
        w = 0.01*3/4;
        h = 0.01;
   };
   class MMA_LRR_MIS5
   {
        idc = 22104;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        text = "";
        x = -2;
        y = -2;
        w = 0.01*3/4;
        h = 0.01;
   };
   class MMA_LRR_MIS6
   {
        idc = 22105;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 1, 0, 1};
        text = "";
        x = -2;
        y = -2;
        w = 0.01*3/4;
        h = 0.01;
   };
   
	class MMA_LRR_LINE_DIR
	{
		idc = 22119;
		type = 0;
		style = 176;
		x = 0.5;
		y = -2;
		w = 0.001;
		h = 0.001;
		colorText[] = {0, 1, 0, 1};
		colorBackground[] = {1, 0, 0, 0};
		font = "Bitstream";
		sizeEx = 0.02;
		text = "";
	};
   
	class MMA_LRR_LINE1
	{
		idc = 22120;
		type = 0;
		style = 176;
		x = 0.5;
		y = -2;
		w = 0.001;
		h = 0.001;
		colorText[] = {0, 1, 0, 1};
		colorBackground[] = {1, 0, 0, 0};
		font = "Bitstream";
		sizeEx = 0.02;
		text = "";
	};

   controls[]= {MMA_LRR_MOUSE,MMA_LRR_FIRE,MMA_LRR_XMIT,MMA_LRR_MODE,MMA_LRR_TARGETS,MMA_LRR_FLIR,MMA_LRR_MAPONOFF,MMA_LRR_HELP,MMA_LRR_HELPHTML,MMA_LRR_UP,MMA_LRR_DOWN};


class MMA_LRR_HELPHTML
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



   class MMA_LRR_FIRE
   {
        type = 1;
        idc = 23918;
        style = 2;
        x = 1.02; 
        y = 0.17-0.004-1;
		w   = 0.075;
		h   = 0.075*4/3;


        sizeEx = 0.02;
		text = "L1 F1";
		action = "[""CALL_LRR_SAM"", 0] call mando_missile_lrr";
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

   class MMA_LRR_XMIT
   {
        type = 1;
        idc = 23927;
        style = 2;
        x = 1.02; 
        y = 0.315-1;
		w   = 0.075;
		h   = 0.075*4/3;


        sizeEx = 0.02;
		text = "L2 F2";
		action = "[""CALL_LRR_SAM"", 1] call mando_missile_lrr";
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

   class MMA_LRR_UP
   {
        type = 1;
        idc = 23960;
        style = 2;
        x = 1.02; 
        y = 0.61-1;
		w   = 0.075;
		h   = 0.075*4/3;


        sizeEx = 0.02;
		text = "L3 F3";
		action = "[""CALL_LRR_SAM"", 2] call mando_missile_lrr";
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

   class MMA_LRR_DOWN
   {
        type = 1;
        idc = 23961;
        style = 2;
        x = 1.02; 
        y = 0.46-1;
		w   = 0.075;
		h   = 0.075*4/3;


        sizeEx = 0.02;
		text = "Help F9";
		action = "[""CALL_LRR_HELP"", []] call mando_missile_lrr";
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


   class MMA_LRR_MODE
   {
        type = 1;
        idc = 23921;
        style = 2;
        x = -0.090; 
        y = 0.61-1;
  	w   = 0.076;
  	h   = 0.075*4/3;


        sizeEx = 0.02;
  	text = "Zoom F8";
  	action = "[""CALL_LRR_ZOOM"", []] call mando_missile_lrr";
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

   class MMA_LRR_HELP
   {
        type = 1;
        idc = 23925;
        style = 2;
        x = -0.094; 
        y = 0.17-0.004-1;
		w   = 0.076;
		h   = 0.075*4/3;


        sizeEx = 0.02;
		text = "ON F6";
		action = "[""CALL_LRR_ONOFF"", []] call mando_missile_lrr";
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


   class MMA_LRR_MAPONOFF
   {
        type = 1;
        idc = 23926;
        style = 2;
        x = -0.093; 
        y = 0.315 - 1;
  	w   = 0.076;
  	h   = 0.075*4/3;



        sizeEx = 0.02;
  	text = "CAM F7";
  	action = "[""CALL_LRR_CAM"", []] call mando_missile_lrr";
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


   class MMA_LRR_TARGETS
   {
        type = 1;
        idc = 23922;
        style = 2;
        x = -0.089; 
        y = 0.46-1;
		w   = 0.0765;
		h   = 0.075*4/3;



        sizeEx = 0.02;
		text = "ENG F4";
		action = "[""CALL_LRR_ENG"", []] call mando_missile_lrr";
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


   class MMA_LRR_FLIR
   {
        type = 1;
        idc = 23919;
        style = 2;
        x = -0.090; 
        y = 0.755-1;
  	w   = 0.076;
  	h   = 0.075*4/3;


        sizeEx = 0.02;
  	text = "IFF F5";
  	action = "[""CALL_LRR_IFF"", []] call mando_missile_lrr";
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


   class MMA_LRR_MOUSE
   {
      type = 15;
      idc = -1;
      style = 0;
        x = 0.137;
        y = 0.011;
        w = 0.726;
        h = 0.968;

      onMouseMoving = "[""onMouseMoving"", _this] call mando_missile_lrr";
      onMouseZChanged  = "[""onMouseZChanged"", _this] call mando_missile_lrr";
      onMouseButtonDown  = "[""onCameraClick"", _this] call mando_missile_lrr";

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
};
