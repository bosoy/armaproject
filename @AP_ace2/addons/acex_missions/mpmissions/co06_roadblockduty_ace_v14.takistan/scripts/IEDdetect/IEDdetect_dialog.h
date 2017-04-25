//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// IED Detection and Disposal Scripts
//////////////////////////////////////////////////////////////////

#define CT_STATIC		0
#define CT_BUTTON		1
#define CT_EDIT			2
#define CT_SLIDER		3
#define CT_COMBO		4
#define CT_LISTBOX		5
#define CT_ACTIVETEXT		11
#define CT_STRUCTURED_TEXT	13
#define ST_LEFT			0
#define ST_RIGHT		1
#define ST_CENTER		2
#define ST_MULTI		16
#define ST_PICTURE		48
#define ST_FRAME		64
#define ST_SHADOW		256
#define ST_NO_RECT		512
#define SL_HORZ 		0x400
#define SL_VERT			0
#define FontM			"Bitstream"

class RscText
{
  type = CT_STATIC;
  idc = -1;
  style = ST_LEFT;
  colorBackground[] = {0, 0, 0, 0};
  colorText[] = {1, 1, 1, 1};
  font = FontM;
  sizeEx = 0.04;
  text = "";
};

class RscButton
{
  type = CT_BUTTON;
  idc = -1;
  style = ST_CENTER;
  font = FontM;
  sizeEx = 0.018;
  default = false;
  colorText[] = {1, 1, 1, 1};
  colorDisabled[] = {0.35, 0.35, 0.45, 1};
  colorBackground[] = {0.95, 0.95, 0.95, 1};
  colorBackgroundDisabled[] = {0.65, 0.65, 0.75, 1};
  colorBackgroundActive[] = {0.51, 1, 0.01, 1};
  offsetX = 0.004;
  offsetY = 0.004;
  offsetPressedX = 0.002;
  offsetPressedY = 0.002;
  colorFocused[] = {0, 0, 0, 0};
  colorShadow[] = {0, 0, 0, 0};
  colorBorder[] = {0, 0, 0, 0};
  borderSize = 0.008;
  soundEnter[] = {"", 0.1, 1};
  soundPush[] = {"", 0.1, 1};
  soundClick[] = {"", 0.1, 1};
  soundEscape[] = {"", 0.1, 1};
};

class RscButtonTextOnly: RscButton
{
  colorBackground[] = {1,1,1,0};
  colorBackgroundActive[] = {1,1,1,0};
  colorBackgroundDisabled[] = {1,1,1,0};
  colorFocused[] = {1,1,1,0};
  colorShadow[] = {1,1,1,0};
  borderSize = 0;
};

class RscPicture
{
  idc = -1;
  type = 0;
  style = 48;
  colorBackground[] = {0,0,0,0};
  colorText[] = {1,1,1,1};
  font = "TahomaB";
  sizeEx = 0;
  lineSpacing = 0;
  text = "";
};
  
class IEDdetect_injector {
  idd = 650;
  movingEnable = false;
  enableSimulation = true;
  duration     =  99999;
  fadein       =  0.33;
  fadeout      =  0.33;
  name = "IEDdetect_injector";
  //onUnload = ";
  class controlsBackground {};
  class objects {};
  class controls {
    class IEDdetect_tool: RscPicture {
      idc = 651;
      x = 0.2; y = 0.55; w = 0.4; h = 0.5;
      text = "scripts\IEDdetect\screens\IEDdetect_09.paa";
    };
    class IEDdetect_readings: RscText {
      idc = 660;
      x = 0.45; y = 0.72; w = 0.2; h = 0.1;
      sizeEx = 0.05;
      colorText[] = {1,1,1,1};
      text = "";
    };
    class IEDdetect_injectP : RscPicture {
      idc = 652;
      x = 0.422; y = 0.885; w = 0.12; h = 0.07;
      text = "scripts\IEDdetect\screens\IEDdetect_injectbutton.paa";
      action = "";
    };
    class IEDdetect_injectB : RscButtonTextOnly {
      idc = 653;
      x = 0.422; y = 0.885; w = 0.12; h = 0.07;
      text = "";
      action = "";
      onMouseButtonDown = "_dummy = [_this, ""MouseButtonDown"", [653], ""2""] execVM ""scripts\IEDdetect\IEDdetect_injection.sqf"";";
      onMouseButtonUp = "";
      onMouseButtonDblClick = "_dummy = [_this, ""MouseButtonDown"",  [653], ""2""] execVM ""scripts\IEDdetect\IEDdetect_injection.sqf"";";
      onMouseEnter = "";
      onMouseExit = "";
      onSetFocus = "";
      onKillFocus = "";
    }; 	
  };
};