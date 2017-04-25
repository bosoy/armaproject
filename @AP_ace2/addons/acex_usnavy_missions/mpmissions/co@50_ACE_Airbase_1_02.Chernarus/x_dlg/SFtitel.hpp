// Control types
#define CT_STATIC 0
#define CT_BUTTON 1
#define CT_EDIT 2
#define CT_SLIDER 3
#define CT_COMBO 4
#define CT_LISTBOX 5
#define CT_TOOLBOX 6
#define CT_CHECKBOXES 7
#define CT_PROGRESS 8
#define CT_HTML 9
#define CT_STATIC_SKEW 10
#define CT_ACTIVETEXT 11
#define CT_TREE 12
#define CT_STRUCTURED_TEXT 13
#define CT_CONTEXT_MENU 14
#define CT_CONTROLS_GROUP 15
#define CT_XKEYDESC 40
#define CT_XBUTTON 41
#define CT_XLISTBOX 42
#define CT_XSLIDER 43
#define CT_XCOMBO 44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT 80
#define CT_OBJECT_ZOOM 81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK 98
#define CT_USER 99
#define CT_MAP 100
#define CT_MAP_MAIN 101 // Static styles
#define ST_POS 0x0F
#define ST_HPOS 0x03
#define ST_VPOS 0x0C
#define ST_LEFT 0x00
#define ST_RIGHT 0x01
#define ST_CENTER 0x02
#define ST_DOWN 0x04
#define ST_UP 0x08
#define ST_VCENTER 0x0c
#define ST_TYPE 0xF0
#define ST_SINGLE 0
#define ST_MULTI 16
#define ST_TITLE_BAR 32
#define ST_PICTURE 48
#define ST_FRAME 64
#define ST_BACKGROUND 80
#define ST_GROUP_BOX 96

#define ST_GROUP_BOX2 112
#define ST_HUD_BACKGROUND 128
#define ST_TILE_PICTURE 144
#define ST_WITH_RECT 160
#define ST_LINE 176
#define FontM "Zeppelin32"

class XD_RscText
{
	type = CT_STATIC;
	idc = -1;
	style = ST_LEFT;

	x = 0.0;
	y = 0.0;
	w = 0.3;
	h = 0.03;
	sizeEx = 0.023;

	colorBackground[] = {0.5, 0.5, 0.5, 0.75};
	colorText[] = { 0, 0, 0, 1 };
	font = FontM;

	text = "";
};

class RscText_1
{
	type = CT_STATIC;
	idc = -1;
	style = ST_LEFT;
	h = 0.04;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {TextColor, 0.65};
	font = FontS;
	sizeEx = 0.02;
};

class RscPicture
{
	type = CT_STATIC;
	idc = -1;
	style = ST_PICTURE;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {1, 1, 1, 1};
	font = FontM;
	sizeEX = 0;
};





class RscTitles
{
	titles[] = {GFLogo,SFtiteltext,SFtiteltext2};

class GFLogo
	{
		idd=-1;
		movingEnable=0;
		duration=6;
		fadein=2;
		name="GFLogo";
		controls[]={"Picture"};

		class Picture : RscPicture
		{
			x=0.85;y=0.85;w=0.16;h=0.20;
			text="GF_logo.paa";
			sizeEx = 256;
		};
	};




class SFtiteltext
	{
		idd=0;
		movingEnable=0;
		duration=10;
		name="SFtitel1";
		controls[]={"text1"};

		class text1: XD_RscText
		{
			style="16+2+512";
			lineSpacing=0.950000;
			text="Made 2009 by Thom0001\n\nScripts by Xeno\n\nfor www.germany-fun.net";
			//x=0.35000000;
			x=0.50000000;y=0.8400000;w=0.900000;h=0.700000;
			colorBackground[]={0,0,0,0};
			colorText[]={0.8,0.9,0.9,0.7};
			size=0.47;
			sizeEx = 0.030;
		};
	};

class SFtiteltext2
         {
            idd=-1;
            movingEnable=true;
            duration=3;
            name="SFtitel2";
            controls[]={"text2"};

            class text2: RscText_1
            {
               idc = -1;
               type = 0;
               style = 2;
               x = 0.005;
               y = 0.252;
               w = 0.995;
               h = 0.2;
               font = "Zeppelin32";
               sizeEx = 0.06;
               colorBackground[] = {0, 0, 0, 0};
               colorText[] = {0,0,0,1};
               text = "Airbase ACE";
             };
       };
};