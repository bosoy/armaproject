	class RscMandLine
	{
            idc = 0;
            type = 0;
            style = 176;
            x = 0.5;
            y = -2;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
	};



   class mandonomissiles
   {
      idd=-1;
      movingEnable=true;
      duration     =10;
      fadein       =  0;
      fadeout      =  0;

      name="mandonomissiles";
      controls[]={"mandonomissiles_back", "mandonomissiles_text"};

      class mandonomissiles_back : RscMandBackground
      {
         colorBackground[] = {0, 0, 1, 0.5};
         text = ;
         style = MANDST_HUD_BACKGROUND;
         sizeEx = 0.015;
         x = 0.4;
         y = 0.4 + 0.2 + 0.025*3 + 0.2;
         w = 0.2;
         h = 0.04;
      };

      class mandonomissiles_text : RscMandText
      {
         style = MANDST_CENTER + MANDST_SHADOW;
         x = 0;
         y = 0.4 + 0.2 + 0.025*3 + 0.2 + 0.006;
         w = 1;
         h = 0.030;
	 font = "Bitstream";
         sizeEx = 0.035;
   	 colorText[] = {1, 1, 1, 1};
  	 text = "No missiles left";
      };
   };

   class mandonoflares
   {
      idd=-1;
      movingEnable=true;
      duration     =10;
      fadein       =  0;
      fadeout      =  0;

      name="mandonoflares";
      controls[]={"mandonoflares_back", "mandonoflares_text"};

      class mandonoflares_back : RscMandBackground
      {
         colorBackground[] = {0, 0, 1, 0.5};
         text = ;
         style = MANDST_HUD_BACKGROUND;
         sizeEx = 0.015;
         x = 0.4;
         y = 0.4 + 0.2 + 0.025*3 + 0.2;
         w = 0.2;
         h = 0.04;
      };

      class mandonoflares_text : RscMandText
      {
         style = MANDST_CENTER + MANDST_SHADOW;
         x = 0;
         y = 0.4 + 0.2 + 0.025*3 + 0.2 + 0.006;
         w = 1;
         h = 0.030;
	 font = "Bitstream";
         sizeEx = 0.032;
   	 colorText[] = {1, 1, 1, 1};
  	 text = "No chaff/flares left";
      };
   };


   class mandonolock
   {
      idd=-1;
      movingEnable=true;
      duration     =10;
      fadein       =  0;
      fadeout      =  0;

      name="mandonolock";
      controls[]={"mandonolock_back", "mandonolock_text"};

      class mandonolock_back : RscMandBackground
      {
         colorBackground[] = {0, 0, 1, 0.5};
         text = ;
         style = MANDST_HUD_BACKGROUND;
         sizeEx = 0.015;
         x = 0.4;
         y = 0.4 + 0.2 + 0.025*3 + 0.2;
         w = 0.2;
         h = 0.04;
      };

      class mandonolock_text : RscMandText
      {
         style = MANDST_CENTER + MANDST_SHADOW;
         x = 0;
         y = 0.4 + 0.2 + 0.025*3 + 0.2 + 0.006;
         w = 1;
         h = 0.035;
	 font = "Bitstream";
         sizeEx = 0.030;
   	 colorText[] = {1, 1, 1, 1};
  	 text = "No Lock!";
      };
   };


   class mandosystems
   {
      idd=-1;
      movingEnable=true;
      duration     =10;
      fadein       =  0;
      fadeout      =  0;

      name="mandosystems";
      controls[]={"mandosystems_back", "mandosystems_text"};

      class mandosystems_back : RscMandBackground
      {
         colorBackground[] = {0, 0, 1, 0.5};
         text = ;
         style = MANDST_HUD_BACKGROUND;
         sizeEx = 0.015;
         x = 0.35;
         y = 0.80;
         w = 0.30;
         h = 0.05;
      };

      class mandosystems_text : RscMandText
      {
         style = MANDST_CENTER + MANDST_SHADOW;
         x = 0;
         y = 0.806;
         w = 1;
         h = 0.035;
	 font = "Bitstream";
         sizeEx = 0.035;
   	 colorText[] = {1, 1, 1, 1};
  	 text = "Activating Mando Systems";
      };
   };

   class mandolockedon
   {
      idd=-1;
      movingEnable=true;
      duration     = 10;
      fadein       =  0;
      fadeout      =  0;

      name="mandolockedon";
      controls[]={"mandolockedon_back", "mandolockedon_text"};

      class mandolockedon_back : RscMandBackground
      {
         colorBackground[] = {0.5, 0, 0, 0.5};
         text = ;
         style = MANDST_HUD_BACKGROUND;
         sizeEx = 0.015;
         x = 0.4;
         y = 0.4 + 0.2 + 0.025*3 + 0.2;
         w = 0.2;
         h = 0.04;
      };

      class mandolockedon_text : RscMandText
      {
         style = MANDST_CENTER + MANDST_SHADOW;
         x = 0;
         y = 0.4 + 0.2 + 0.025*3 + 0.2 + 0.006;
         w = 1;
         h = 0.035;
	 font = "Bitstream";
         sizeEx = 0.030;
   	 colorText[] = {1, 1, 1, 1};
  	 text = "RADAR LOCK";
      };
   };

   class mandoincoming
   {
      idd=-1;
      movingEnable=true;
      duration     = 10;
      fadein       =  0;
      fadeout      =  0;

      name="mandoincoming";
      controls[]={"mandoincoming_back", "mandoincoming_text"};

      class mandoincoming_back : RscMandBackground
      {
         colorBackground[] = {1, 0, 0, 0.5};
         text = ;
         style = MANDST_HUD_BACKGROUND;
         sizeEx = 0.015;
         x = 0.4;
         y = 0.4 + 0.2 + 0.025*3 + 0.2;
         w = 0.2;
         h = 0.04;
      };

      class mandoincoming_text : RscMandText
      {
         style = MANDST_CENTER + MANDST_SHADOW;
         x = 0;
         y = 0.4 + 0.2 + 0.025*3 + 0.2 + 0.006;
         w = 1;
         h = 0.035;
	 font = "Bitstream";
         sizeEx = 0.030;
   	 colorText[] = {1, 1, 1, 1};
  	 text = "INCOMING MISSILE";
      };
   };


class mando_target
{
  idd = 100;
  movingEnable =  1;
  duration     =  10000;
  fadein       =  0;
  fadeout      =  0;
  name = "mando_target";

//  onLoad = "with uiNameSpace do {mandotarget_disp = (_this select 0); (mandotarget_disp displayCtrl 102) ctrlSetText (mando_missile_path + ""mandotarget_circle.paa"");(mandotarget_disp displayCtrl 107) ctrlSetText (mando_missile_path +""mandotarget_cross.paa"");}";

  onLoad = "with uiNameSpace do {mandotarget_disp = (_this select 0);}";


  class controls 
  {
	class MANDOTARGET_CUSTOMLINE0 : RscMandLine
	{
		idc = 30;
	};
	class MANDOTARGET_CUSTOMLINE1 : RscMandLine
	{
		idc = 31;
	};
	class MANDOTARGET_CUSTOMLINE2 : RscMandLine
	{
		idc = 32;
	};
	class MANDOTARGET_CUSTOMLINE3 : RscMandLine
	{
		idc = 33;
	};
	class MANDOTARGET_CUSTOMLINE4 : RscMandLine
	{
		idc = 34;
	};

	class MANDOTARGET_CUSTOMLINE5 : RscMandLine
	{
		idc = 35;
	};
	class MANDOTARGET_CUSTOMLINE6 : RscMandLine
	{
		idc = 36;
	};
	class MANDOTARGET_CUSTOMLINE7 : RscMandLine
	{
		idc = 37;
	};
	class MANDOTARGET_CUSTOMLINE8 : RscMandLine
	{
		idc = 38;
	};
	class MANDOTARGET_CUSTOMLINE9 : RscMandLine
	{
		idc = 39;
	};
	class MANDOTARGET_CUSTOMLINE10 : RscMandLine
	{
		idc = 40;
	};
	class MANDOTARGET_CUSTOMLINE11: RscMandLine
	{
		idc = 41;
	};
	class MANDOTARGET_CUSTOMLINE12: RscMandLine
	{
		idc = 42;
	};
	class MANDOTARGET_CUSTOMLINE13: RscMandLine
	{
		idc = 43;
	};
	class MANDOTARGET_CUSTOMLINE14 : RscMandLine
	{
		idc = 44;
	};

      class MANDOTARGET_CUSTOM0
      {
         idc = 50;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };

      class MANDOTARGET_CUSTOM17
      {
         idc = 67;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };


      class MANDOTARGET_CUSTOM1
      {
         idc = 51;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM2
      {
         idc = 52;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM3
      {
         idc = 53;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM4
      {
         idc = 54;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM5
      {
         idc = 55;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM6
      {
         idc = 56;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM7
      {
         idc = 57;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM8
      {
         idc = 58;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM9 
      {
         idc = 59;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM10 
      {
         idc = 60;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM11 
      {
         idc = 61;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM12 
      {
         idc = 62;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM13
      {
         idc = 63;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM14
      {
         idc = 64;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM15
      {
         idc = 65;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM16
      {
         idc = 66;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };


	  class MANDOTARGET_CUSTOM18
	  {
            idc = 68;
            type = 0;
            style = 176;
            x = 0.5;
            y = -2;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
          };
	  class MANDOTARGET_CUSTOM19
	  {
            idc = 69;
            type = 0;
            style = 176;
            x = 0.5;
            y = -2;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
          };
	  class MANDOTARGET_CUSTOM20
	  {
            idc = 70;
            type = 0;
            style = 176;
            x = 0.5;
            y = -2;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
          };
	  class MANDOTARGET_CUSTOM21
	  {
            idc = 71;
            type = 0;
            style = 176;
            x = 0.5;
            y = -2;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
          };
	  class MANDOTARGET_CUSTOM22
	  {
            idc = 72;
            type = 0;
            style = 176;
            x = 0.5;
            y = -2;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
          };
	  class MANDOTARGET_CUSTOM23
	  {
            idc = 73;
            type = 0;
            style = 176;
            x = 0.5;
            y = -2;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
          };
	  class MANDOTARGET_CUSTOM24
	  {
            idc = 74;
            type = 0;
            style = 176;
            x = 0.5;
            y = -2;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
          };
	  class MANDOTARGET_CUSTOM25
	  {
            idc = 75;
            type = 0;
            style = 176;
            x = 0.5;
            y = -2;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
          };


	  class MANDOTARGET_CUSTOM26
	  {
             access = 0;
	     type = 13;
	     idc = 76;
	     style = 16;
	     lineSpacing = 1;

  	     x = safeZoneX;
  	     y = safeZoneY + safeZoneH - 0.1;
  	     w = 0.25;
  	     h = 0.1;

	     size = 0.020;
	     colorBackground[] = {0,0,0,0};
	     colorText[] = {1,1,1,0.7};
	     text = "";
	     font = "BitStream";
	     class Attributes 
	     {
	        font = "BitStream";
        	color = "#808080";
	        align = "left";
	        shadow = false;
	     };
          };


	  class MANDOTARGET_CUSTOM27
	  {
             access = 0;
	     type = 13;
	     idc = 77;
	     style = 16;
	     lineSpacing = 1;

  	     x = safeZoneX;
  	     y = safeZoneY + safeZoneH - 0.1;
  	     w = 0.25;
  	     h = 0.1;

	     size = 0.020;
	     colorBackground[] = {0,0,0,0};
	     colorText[] = {1,1,1,0.7};
	     text = "";
	     font = "BitStream";
	     class Attributes 
	     {
	        font = "BitStream";
        	color = "#808080";
	        align = "left";
	        shadow = false;
	     };
          };


	  class MANDOTARGET_CUSTOM28
	  {
             access = 0;
	     type = 13;
	     idc = 78;
	     style = 16;
	     lineSpacing = 1;

  	     x = safeZoneX;
  	     y = safeZoneY + safeZoneH - 0.1;
  	     w = 0.25;
  	     h = 0.1;

	     size = 0.020;
	     colorBackground[] = {0,0,0,0};
	     colorText[] = {1,1,1,0.7};
	     text = "";
	     font = "BitStream";
	     class Attributes 
	     {
	        font = "BitStream";
        	color = "#808080";
	        align = "left";
	        shadow = false;
	     };
          };


	  class MANDOTARGET_CUSTOM29
	  {
             access = 0;
	     type = 13;
	     idc = 79;
	     style = 16;
	     lineSpacing = 1;

  	     x = safeZoneX;
  	     y = safeZoneY + safeZoneH - 0.1;
  	     w = 0.25;
  	     h = 0.1;

	     size = 0.020;
	     colorBackground[] = {0,0,0,0};
	     colorText[] = {1,1,1,0.7};
	     text = "";
	     font = "BitStream";
	     class Attributes 
	     {
	        font = "BitStream";
        	color = "#808080";
	        align = "left";
	        shadow = false;
	     };
          };

/*
// Two extra image controls over everthing else
      class MANDOTARGET_CUSTOM30
      {
         idc = 88;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
      class MANDOTARGET_CUSTOM31
      {
         idc = 89;
         type = 0;
         style = 48;
         font = "Bitstream";
         sizeEx = 0.04;
         colorBackground[] = {0, 0, 0, 0};
         colorText[] = {0, 0.5, 0, 0};
         text = "";
         x = 0.5-0.03/2;
         y = -2;
         w = 0.04;
         h = 0.05;
      };
*/

      class MANDOTARGET_NORADARLEFT
      {
         type = 0;
         idc = 90;
         style = 128;
         x = 0.295;
         y = 0.042;
         w = 0.16;
         h = 0.1;
	 font = "Bitstream";
         sizeEx = 0.08;
   	 colorText[] = {0.2, 0.2, 0.2, 0};
         colorBackground[] = {0.7, 0, 0, 0};
  	 text = "";
      };


      class MANDOTARGET_NORADARRIGHT
      {
         type = 0;
         idc = 91;
         style = 128;
         x = 0.545;
         y = 0.042;
         w = 0.16;
         h = 0.1;
	 font = "Bitstream";
         sizeEx = 0.08;
   	 colorText[] = {0.2, 0.2, 0.2, 0};
         colorBackground[] = {0.7, 0, 0, 0};
  	 text = "";
      };
 

// HUD CIRCLE
	  class MANDOTARGET_BACKGROUND1
	  {
	     idc = 101;
             type = 0;
             colorText[] = {0.5, 1, 0.5, 0};
             font = "Bitstream";
	     colorBackground[] = {0, 0, 0, 0};
	     text = ;
//	     style = 128;
             style = 48;
	     sizeEx = 0.015;
	     x = 0.5 - (0.17*3/4)/2;
	     y = 0.5 - (0.17/2);
	     w = 0.17*3/4;
	     h = 0.17;
	  };

// RWR
	  class MANDOTARGET_BACKGROUND2
	  {
	     idc = 112;
             type = 0;
             colorText[] = {1, 1, 1, 1};
             font = "Bitstream";
	     colorBackground[] = {0, 0, 0, 0};
	     text = ;
	     style = 48;
	     sizeEx = 0.015;

             x = SafeZoneX;
             y = 0.1-1;
	     w = 0.2;
	     h = 0.2*4/3;
	  };

          class MANDOTARGET_INCM1
          {
             idc = 9000;
             type = 0;
             style = 176;
             x = -1;
             y = -0.5;
             w = 0.001;
             h = 0.001;
             colorText[] = {0.5, 1, 0.5, 1};
             colorBackground[] = {1, 0, 0, 1};
             font = "Bitstream";
             sizeEx = 0.02;
             text = "";
          };

          class MANDOTARGET_INCM2
          {
             idc = 9001;
             type = 0;
             style = 176;
             x = -1;
             y = -0.5;
             w = 0.001;
             h = 0.001;
             colorText[] = {0.5, 1, 0.5, 1};
             colorBackground[] = {1, 0, 0, 1};
             font = "Bitstream";
             sizeEx = 0.02;
             text = "";
          };

          class MANDOTARGET_INCM3
          {
             idc = 9002;
             type = 0;
             style = 176;
             x = -1;
             y = -0.5;
             w = 0.001;
             h = 0.001;
             colorText[] = {0.5, 1, 0.5, 1};
             colorBackground[] = {1, 0, 0, 1};
             font = "Bitstream";
             sizeEx = 0.02;
             text = "";
          };


	  class MANDOTARGET_AIMCIRCLE
	  {
	     idc = 102;
             type = 0;
             style = 48;
             font = "Bitstream";
             sizeEx = 0.04;
             colorBackground[] = {0, 0, 0, 0};
             colorText[] = {0, 0.5, 0, 0};
             text = "";
             x = 0.5-0.03/2;
             y = 0.5-0.05/2;
             w = 0.04;
             h = 0.05;
          };

	  class MANDOTARGET_TARGET
	  {
             access = 0;
	     type = 13;
	     idc = 103;
	     style = 16;
	     lineSpacing = 1;

  	     x = 0.5-0.09;
  	     y = 0.4 + 0.26;
  	     w = 0.18;
  	     h = 0.022 + 0.22;

	     size = 0.020;
	     colorBackground[] = {0,0,0,0};
	     colorText[] = {0,0,0,0};
	     text = "";
	     font = "BitStream";
	     class Attributes 
	     {
	        font = "BitStream";
        	color = "#80ff80";
	        align = "left";
	        shadow = false;
	     };
          };


	  class MANDOTARGET_CROSS
	  {
	     idc = 107;
             type = 0;
             style = 48;
             font = "Bitstream";
             sizeEx = 0.04;
             colorBackground[] = {0, 0, 0, 0};
             colorText[] = {0.5, 1, 0.5, 0.5};
             text = "";
             x = 0.5-0.02;
             y = 0.5-0.025;
             w = 0.04;
             h = 0.05;
          };


// Mode, center up
	  class MANDOTARGET_MODE
	  {
  	     idc = 108;
             type = 0;
	     style = 2;
  	     x = 0.5-0.1;
  	     y = 0.39;
  	     w = 0.2;
  	     h = 0.03;
             colorText[] = {0.5, 1, 0.5, 0};
             colorBackground[] = {0, 0, 0, 0};
             font = "Bitstream";
             sizeEx = 0.02;
	     text = "No mode";
          };

	  class MANDOTARGET_RANGES
	  {
  	     idc = 113;
             type = 0;
	     style = 2;
  	     x = 0;
  	     y = 0.4 + 0.2;
  	     w = 1;
  	     h = 0.03;
             colorText[] = {0.5, 1, 0.5, 0};
             colorBackground[] = {0, 0, 0, 0};
             font = "Bitstream";
             sizeEx = 0.02;
	     text = "";
          };

// AA Missiles left/max
	  class MANDOTARGET_MISSILES1
	  {
             access = 0;
	     type = 13;
	     idc = 109;
	     style = 16;
	     lineSpacing = 1;

  	     x = 0.5-0.1+0.005-0.005;
//  	     x = 0.5-0.1+0.005-0.01;
  	     y = 0.41;
//  	     w = 0.19;
  	     w = 0.08;
  	     h = 0.03+0.06;

	     size = 0.020;
	     colorBackground[] = {0,0,0,0};
	     colorText[] = {0,0,0,0};
	     text = "";
	     font = "BitStream";
	     class Attributes 
	     {
	        font = "BitStream";
        	color = "#80ff80";
	        align = "left";
	        shadow = false;
	     };
          };


	  class MANDOTARGET_ASPECT1
	  {
            idc = 110;
            type = 0;
            style = 176;
            x = 0.5;
            y = 0.5;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
          };

	  class MANDOTARGET_ASPECT2
	  {
            idc = 114;
            type = 0;
            style = 176;
            x = 0.5;
            y = 0.5;
            w = 0.001;
            h = 0.001;
            colorText[] = {0.5, 1, 0.5, 0};
            colorBackground[] = {1, 0, 0, 0};
            font = "Bitstream";
            sizeEx = 0.02;
            text = "";
          };


// Flares left/max - ECM
	  class MANDOTARGET_FLARES
	  {
             access = 0;
	     type = 13;
	     idc = 111;
	     style = 16;
	     lineSpacing = 1;

  	     x = 0.5 + 0.041;
  	     y = 0.41;
  	     w = 0.19;
  	     h = 0.06;

	     size = 0.020;
	     colorBackground[] = {0,0,0,0};
	     colorText[] = {0,0,0,0};
	     text = "";
	     font = "BitStream";
	     class Attributes 
	     {
	        font = "BitStream";
        	color = "#80ff80";
	        align = "left";
	        shadow = false;
	     };
          };

   class MANDOTARGET_TARGETROMBE
   {
        idc = 23929;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };


   class MANDOTARGET_TARGETRECT1
   {
        idc = 23930;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MANDOTARGET_TARGETRECT2
   {
        idc = 23931;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MANDOTARGET_TARGETRECT3
   {
        idc = 23932;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MANDOTARGET_TARGETRECT4
   {
        idc = 23933;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MANDOTARGET_TARGETRECT5
   {
        idc = 23934;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MANDOTARGET_TARGETRECT6
   {
        idc = 23935;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };


   class MANDOTARGET_TARGETTEXT1
   {
      idc = 23940;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.1;
      h = 0.03;
      colorText[] = {0, 1, 0, 0};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.019;
      text = "";
   };

   class MANDOTARGET_TARGETTEXT2
   {
      idc = 23941;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.1;
      h = 0.03;
      colorText[] = {0, 1, 0, 0};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.019;
      text = "";
   };

   class MANDOTARGET_TARGETTEXT3
   {
      idc = 23942;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.1;
      h = 0.03;
      colorText[] = {0, 1, 0, 0};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.015;
      text = "";
   };

   class MANDOTARGET_TARGETTEXT4
   {
      idc = 23943;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.1;
      h = 0.03;
      colorText[] = {0, 1, 0, 0};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.015;
      text = "";
   };

   class MANDOTARGET_TARGETTEXT5
   {
      idc = 23944;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.1;
      h = 0.03;
      colorText[] = {0, 1, 0, 0};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.015;
      text = "";
   };

   class MANDOTARGET_TARGETTEXT6
   {
      idc = 23945;
      type = 0;
      style = 0;
      x = 0.5 - 0.15;
      y = 0.2 - 0.05;
      w = 0.1;
      h = 0.03;
      colorText[] = {0, 1, 0, 0};
      colorBackground[] = {0, 0, 0, 0};
      font = "Bitstream";
      sizeEx = 0.015;
      text = "";
   };


   class MANDOTARGET_BRACKETUL
   {
        idc = 86;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MANDOTARGET_BRACKETDL
   {
        idc = 87;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MANDOTARGET_BRACKETUR
   {
        idc = 88;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   class MANDOTARGET_BRACKETDR
   {
        idc = 89;
        type = 0;
        style = 48;
        font = "Bitstream";
        sizeEx = 0.04;
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {0, 0.5, 0, 0};
        text = "";
        x = 0.5-0.03/2;
        y = 0.5-0.05/2;
        w = 0.04;
        h = 0.05;
   };

   };
};
