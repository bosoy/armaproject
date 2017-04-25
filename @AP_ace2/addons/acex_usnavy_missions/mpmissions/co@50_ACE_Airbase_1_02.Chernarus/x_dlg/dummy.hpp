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
#define Size_Main_Small 0.027
#define Size_Main_Normal 0.04
#define Size_Text_Default Size_Main_Normal
#define Size_Text_Small Size_Main_Small
#define Color_White {1, 1, 1, 1}
#define Color_Main_Foreground1 Color_White
#define Color_Text_Default Color_Main_Foreground1

class RscText
{
    type = CT_STATIC;
    idc = -1;
    style = ST_LEFT;
	x = 0.12;
	y = 0.39;
	w = 0.4;
	h = 0.07;
	sizeEx = 0.06;
    colorBackground[] = {0, 0, 0, 0};
	colorText[] = { 0, 0, 1, 1};
    font = FontM;
    text ="";
};

class X3_RscText
{
	access = ReadAndWrite;
	type = CT_STATIC;
	idc = -1;
	style = ST_CENTER;
	w = 0.05;
	h = 0.05;
	font = FontM;
	sizeEx = Size_Text_Default;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = Color_Text_Default;
	text = "";

};

class RscListBox
{
	type = 5;
	style = ST_LEFT;
	idc = -1;
	colorSelect[] = {0, 0, 0, 0.9};
	colorSelectBackground[] = {0.1,0.6,0.9,1.3};
	colorText[] = {1, 1, 1, 1};
	colorBackground[] = {1,1,1,1};
	font = FontM;
	sizeEx = 0.04;
	rowHeight = 0.06;
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	colorFocused[] = {1, 1, 1, 1};
	colorShadow[] = {1, 1, 1, 1};
	colorBorder[] = {1, 1, 1, 1};
	borderSize = 0.99;
	soundEnter[] = {"\ca\ui\data\sound\mouse2", 0.5, 1};
	soundPush[] = {"\ca\ui\data\sound\new1", 0.5, 1};
	soundClick[] = {"\ca\ui\data\sound\mouse3", 0.5, 1};
	soundEscape[] = {"\ca\ui\data\sound\mouse1", 0.5, 1};
	soundExpand[]={"\ca\ui\data\sound\new1", 0.5, 1};
	SoundCollapse[]={"\ca\ui\data\sound\new1", 0.5, 1};
	soundselect[]={"\ca\ui\data\sound\mouse1", 0.5, 1};
	x = 0.12;
	y = 0.50;
	w = 0.4;
	h = 0.3;

};

class XC_RscText
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

