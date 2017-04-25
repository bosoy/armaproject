class RscBackground
{
        type = CT_STATIC;
        idc = -1;
        style = ST_BACKGROUND;
        colorBackground[] = {0, 0, 0, .75};
        colorText[] = {1, 1, 1, 1};
        font = FontM;
        sizeEx = 0.04;
};

// text
class RscText
{
	idc = -1;
	type = CT_STATIC;
	style = ST_CENTER;
	font = FontM;
	colorText[] = {1,1,1,1};
	colorBackground[] = {0, 0, 0, 0};
	sizeEx = 0.02;
	w = 0.2;
	h = 0.03;
};

class RscButton
{
  type = CT_BUTTON;
  idc = -1;
  style = ST_CENTER;

  x = 0.0;
  y = 0.0;
  w = 0.1;
  h = Dlg_CONTROLHGT;
  sizeEx = 0.0225;
  offsetX = 0;
  offsetY = 0.002;
  offsetPressedX = 0;
  offsetPressedY = 0.002;
  borderSize = 0;

  #define ClrWhite 1,1,1
  #define ClrBlack 0,0,0
  #define ClrGray 0.5,0.5,0.5
  #define ClrBlue 0.2,0.5,1

  colorText[] = {ClrWhite,1};
  colorBackground[] = {ClrGray, 0};
  colorFocused[] = {ClrGray,0.2};

  colorShadow[] = {ClrBlack,0};
  colorBorder[] = {ClrWhite,0.2};
  colorBackgroundActive[] = {ClrGray,0.4};
  colorDisabled[] = {ClrGray, 0.7};
  colorBackgroundDisabled[] = {ClrGray,0.3};
  font = FontM;

  soundEnter[] = {"", 0.2, 1};
  soundPush[] = {"", 0.2, 1};
  soundClick[] = {"", 0.2, 1};
  soundEscape[] = {"", 0.2, 1};

  default = false;
  text = "";
  action = "";
};

class RscPicture
{
	type = CT_STATIC;
	idc = -1;
	style = ST_PICTURE;

  x = 0.1;
  y = 0.1;
  w = 0.4;
  h = 0.2;
	sizeEx = 0.1;

	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = FontM;
  text = "";
};

class RscLB_LIST
{
  // type = defined in derived class
  idc = -1;
  style = ST_LEFT;

  x = 0.1;
  y = 0.1;
  w = 0.2;
  h = 0.1;
  sizeEx = 0.1;
  rowHeight = 0.1;

  color[] = {ClrWhite,1};
  colorText[] = {ClrBlack,1};
  colorBackground[] = {ClrGray, 1}; // always clear?
  colorSelect[] = {ClrGray,1};
  colorSelect2[] = {ClrGray,1};
  colorScrollbar[] = {ClrWhite,1};
  colorSelectBackground[] = {ClrGray,1};
  colorSelectBackground2[] = {ClrGray,1};
  font = FontM;

  soundSelect[] = {"\ca\ui\data\sound\mouse3", 0.2, 1};
  soundExpand[] = {"\ca\ui\data\sound\mouse2", 0.2, 1};
  soundCollapse[] = {"\ca\ui\data\sound\mouse1", 0.2, 1};
};
//-------------------------------------
class RscListBox: RscLB_LIST
{
  type = CT_LISTBOX;

  onLBSelChanged = "";
  onLBDblClick = "";
};
class RscCombo: RscLB_LIST
{
  type = CT_COMBO;

  wholeHeight = 0.3;
};