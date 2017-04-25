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

#define IDCPLAYER 5200
#define IDCDEFAULT 5000
#define IDCUNDEFINED -1
#define SECONDARY_FONT "Bitstream"

// ####
class RscTitles
{
	class Titel1
	{
		idd=0;
		movingEnable=0;
		duration=10;
		name="titel1";
		controls[]={"titel1"};
		class titel1: XC_RscText
		{
			style="16+2+512";
			lineSpacing=0.950000;
			text="Made 2009 by Xeno";
			//x=0.39000000;
			x=0.40000000;
			y=0.9100000;
			w=0.900000;
			h=0.700000;
			colorBackground[]={0,0,0,0};
			colorText[]={0.8,0.9,0.9,0.7};
			size=0.8;
			sizeEx = 0.026;
		};
	};

	class PlayerNameHud
	{
		idd = IDCDEFAULT;
		duration = 1e+011;
		name="PlayerNameHud";
		controls[]={"PlayerNameDisp","Player00","Player01","Player02","Player03","Player04","Player05","Player06","Player07","Player08","Player09","Player10",
			"Player11","Player12","Player13","Player14","Player15","Player16","Player17","Player18","Player19","Player20","Player21","Player22","Player23",
			"Player24","Player25","Player26","Player27","Player28","Player29","Player30","Player31","Player32","Player33","Player34","Player35","Player36",
			"Player37","Player38","Player39","Player40","Player41","Player42","Player43","Player44","Player45","Player46","Player47","Player48","Player49","Player50"};
		onLoad = "uiNamespace setVariable [""X_PHUD"", _this select 0];";
		objects[] = {};

		class PlayerNameDisp
		{
			type = 0;
			idc = IDCUNDEFINED;
			style = ST_LEFT;
			colorText[] = {0.75,0.75,0.75,1};
			colorBackground[] = {0,0,0,0};
			font = SECONDARY_FONT;
			text = "";
			sizeEx = 0.020;
			w = 0.165;
			h = 0.018;
			x = 0.5;
			y = 0.5;
		};

		class Player00:PlayerNameDisp { idc = IDCPLAYER +  0; };
		class Player01:PlayerNameDisp { idc = IDCPLAYER +  1; };
		class Player02:PlayerNameDisp { idc = IDCPLAYER +  2; };
		class Player03:PlayerNameDisp { idc = IDCPLAYER +  3; };
		class Player04:PlayerNameDisp { idc = IDCPLAYER +  4; };
		class Player05:PlayerNameDisp { idc = IDCPLAYER +  5; };
		class Player06:PlayerNameDisp { idc = IDCPLAYER +  6; };
		class Player07:PlayerNameDisp { idc = IDCPLAYER +  7; };
		class Player08:PlayerNameDisp { idc = IDCPLAYER +  8; };
		class Player09:PlayerNameDisp { idc = IDCPLAYER +  9; };
		class Player10:PlayerNameDisp { idc = IDCPLAYER + 10; };
		class Player11:PlayerNameDisp { idc = IDCPLAYER + 11; };
		class Player12:PlayerNameDisp { idc = IDCPLAYER + 12; };
		class Player13:PlayerNameDisp { idc = IDCPLAYER + 13; };
		class Player14:PlayerNameDisp { idc = IDCPLAYER + 14; };
		class Player15:PlayerNameDisp { idc = IDCPLAYER + 15; };
		class Player16:PlayerNameDisp { idc = IDCPLAYER + 16; };
		class Player17:PlayerNameDisp { idc = IDCPLAYER + 17; };
		class Player18:PlayerNameDisp { idc = IDCPLAYER + 18; };
		class Player19:PlayerNameDisp { idc = IDCPLAYER + 19; };
		class Player20:PlayerNameDisp { idc = IDCPLAYER + 20; };
		class Player21:PlayerNameDisp { idc = IDCPLAYER + 21; };
		class Player22:PlayerNameDisp { idc = IDCPLAYER + 22; };
		class Player23:PlayerNameDisp { idc = IDCPLAYER + 23; };
		class Player24:PlayerNameDisp { idc = IDCPLAYER + 24; };
		class Player25:PlayerNameDisp { idc = IDCPLAYER + 25; };
		class Player26:PlayerNameDisp { idc = IDCPLAYER + 26; };
		class Player27:PlayerNameDisp { idc = IDCPLAYER + 27; };
		class Player28:PlayerNameDisp { idc = IDCPLAYER + 28; };
		class Player29:PlayerNameDisp { idc = IDCPLAYER + 29; };
		class Player30:PlayerNameDisp { idc = IDCPLAYER + 30; };
		class Player31:PlayerNameDisp { idc = IDCPLAYER + 31; };
		class Player32:PlayerNameDisp { idc = IDCPLAYER + 32; };
		class Player33:PlayerNameDisp { idc = IDCPLAYER + 33; };
		class Player34:PlayerNameDisp { idc = IDCPLAYER + 34; };
		class Player35:PlayerNameDisp { idc = IDCPLAYER + 35; };
		class Player36:PlayerNameDisp { idc = IDCPLAYER + 36; };
		class Player37:PlayerNameDisp { idc = IDCPLAYER + 37; };
		class Player38:PlayerNameDisp { idc = IDCPLAYER + 38; };
		class Player39:PlayerNameDisp { idc = IDCPLAYER + 39; };
		class Player40:PlayerNameDisp { idc = IDCPLAYER + 40; };
		class Player41:PlayerNameDisp { idc = IDCPLAYER + 41; };
		class Player42:PlayerNameDisp { idc = IDCPLAYER + 42; };
		class Player43:PlayerNameDisp { idc = IDCPLAYER + 43; };
		class Player44:PlayerNameDisp { idc = IDCPLAYER + 44; };
		class Player45:PlayerNameDisp { idc = IDCPLAYER + 45; };
		class Player46:PlayerNameDisp { idc = IDCPLAYER + 46; };
		class Player47:PlayerNameDisp { idc = IDCPLAYER + 47; };
		class Player48:PlayerNameDisp { idc = IDCPLAYER + 48; };
		class Player49:PlayerNameDisp { idc = IDCPLAYER + 49; };
		class Player50:PlayerNameDisp { idc = IDCPLAYER + 50; };
	};
};
