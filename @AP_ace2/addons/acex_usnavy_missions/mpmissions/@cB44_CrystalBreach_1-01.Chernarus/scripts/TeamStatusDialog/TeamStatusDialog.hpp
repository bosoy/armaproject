// Desc: Team Status Dialog 2
// Features: Group joining, Team Leader selection, statistics for team/group/vehicle/opposition
// By: Dr Eyeball
//-----------------------------------------------------------------------------
// TSD9_ is the unique prefix associated with all unique classes for the TeamStatus dialog.
//-----------------------------------------------------------------------------
#ifndef _TSD9_TeamStatusDialog_hpp_
#define _TSD9_TeamStatusDialog_hpp_

//-----------------------------------------------------------------------------
// IDD's & IDC's
//-----------------------------------------------------------------------------
#define TSD9_IDD_TeamStatusDialog 385

#define TSD9_IDC_CloseButton 100
#define TSD9_IDC_MyTeamButton 103
#define TSD9_IDC_MyGroupButton 104
#define TSD9_IDC_VehicleButton 105
#define TSD9_IDC_OppositionButton 106
#define TSD9_IDC_FrameCaption 107
#define TSD9_IDC_CollapseAllButton 108
#define TSD9_IDC_ExpandAllButton 109
#define TSD9_IDC_Grid 110
//-----------------------------------------------------------------------------
// Constants to standardize and help simplify positioning and sizing
#define TSD9_ROWS 36
// modifiers
#define TSD9_TEXTHGT_MOD 0.76
#define TSD9_COLWID_MOD 1.01 // used to prevent single pixel gap between columns due to rounding
#define TSD9_ROWHGT_MOD 1.05 // used to prevent single pixel gap between rows due to rounding

// (Calculate proportion, then /100 to represent as percentage)
#define TSD9_CONTROLHGT ((safeZoneH*100/(TSD9_ROWS+1))/100) // +1 reserves bottom row
#define TSD9_TEXTHGT (TSD9_CONTROLHGT*TSD9_TEXTHGT_MOD)
#define TSD9_ROWHGT (TSD9_CONTROLHGT*TSD9_ROWHGT_MOD)

#define TSD9_FIRSTROW (safeZoneY+1*TSD9_CONTROLHGT)
#define TSD9_X (safeZoneX+((safeZoneW-TSD9_W)/2))
#define TSD9_W (safeZoneW-(TSD9_FillerW/BCW_Total))
//-------------------------------------
#define Dlg_ColorScheme_3DControlBackground 40/256, 51/256, 34/256 // A2 Dark green bg
#define Dlg_ColorScheme_3DControlBackgroundAlt (40/256)-0.02, (51/256)-0.02, (34/256)-0.02

//#define TSD9_color_cellABG 0.2, 0.2, 0.2
#define TSD9_color_cellABG Dlg_ColorScheme_3DControlBackgroundAlt
#define TSD9_color_cellBBG Dlg_ColorScheme_3DControlBackground

// Base Column Widths
#define BCW_1 3 //left border button
#define BCW_2 5 //#
#define BCW_3 26 //name
#define BCW_4 17 //vehicle
#define BCW_5 5 //seat
#define BCW_6 0 // 13 //role
#define BCW_7 15 //gear
#define BCW_8 0 // 7 //score - removed temporarily 2
#define BCW_9 0 // 8 //work - can't obtain info - removed temporarily
#define BCW_10 0 // 7 //kills - can't obtain info - removed temporarily
#define BCW_11 0 // 7 //deaths - can't obtain info - removed temporarily
#define BCW_12 0 // 6 //TKs - can't obtain info - removed temporarily
#define BCW_13 0 // 14 //cmd - removed temporarily 2
#define BCW_18 0 // 11 //Target -- rearranged - removed temporarily 2
#define BCW_14 0 // 9 //req - removed temporarily 2
#define BCW_15 7 //pos
#define BCW_16 0 // 9 //TL prox - removed temporarily
#define BCW_17 8 //My prox
#define BCW_19 11 //right border

#define TSD9_FillerW 30.29 // arbitrary value to squash overal table width
#define BCW_Total ((1/safeZoneW)*(BCW_1+BCW_2+BCW_3+BCW_4+BCW_5+BCW_6+BCW_7+BCW_8+BCW_9+BCW_10+BCW_11+BCW_12+BCW_13+BCW_14+BCW_15+BCW_16+BCW_17+BCW_18+BCW_19+TSD9_FillerW)) // final number is arbitrary to squash overal table width

// Column Width Perctages
#define CWP_1 (BCW_1/BCW_Total)*1.01
#define CWP_2 (BCW_2/BCW_Total)
#define CWP_3 (BCW_3/BCW_Total)
#define CWP_4 (BCW_4/BCW_Total)
#define CWP_5 (BCW_5/BCW_Total)
#define CWP_6 (BCW_6/BCW_Total)
#define CWP_7 (BCW_7/BCW_Total)
#define CWP_8 (BCW_8/BCW_Total)
#define CWP_9 (BCW_9/BCW_Total)
#define CWP_10 (BCW_10/BCW_Total)
#define CWP_11 (BCW_11/BCW_Total)
#define CWP_12 (BCW_12/BCW_Total)
#define CWP_13 (BCW_13/BCW_Total)
#define CWP_14 (BCW_14/BCW_Total)
#define CWP_15 (BCW_15/BCW_Total)
#define CWP_16 (BCW_16/BCW_Total)
#define CWP_17 (BCW_17/BCW_Total)
#define CWP_18 (BCW_18/BCW_Total)
#define CWP_19 (BCW_19/BCW_Total)

// BaseClassesExtract.hpp depends on some values above like TSD9_CONTROLHGT
#include "BaseClassesExtract.hpp"

//=============================================================================
class TSD9_CELL: TSD9_RscText
{
  h = TSD9_ROWHGT;
  sizeEx = TSD9_TEXTHGT;

  colorBackground[] = TSD9_ColorAttribute_Clear;
  colorText[] = {TSD9_ColorScheme_WindowText, 1};
};

class TSD9_CELLA: TSD9_CELL
{
  colorBackground[] = TSD9_ColorAttribute_Clear;
};

class TSD9_CELLB: TSD9_CELL
{
  colorBackground[] = TSD9_ColorAttribute_Clear;
};

class TSD9_CELLCombo: TSD9_RscCombo
{
  sizeEx = TSD9_TEXTHGT;
  h = TSD9_ROWHGT;
  rowHeight = TSD9_CONTROLHGT;

  /*
  color[] = {TSD9_Color_Gray_4, 1};
  colorBackground[] = {TSD9_Color_Gray_4, 1};
  colorSelectBackground[] = {TSD9_Color_Gray_4, 1};
  colorSelectBackground2[] = {TSD9_Color_Gray_4, 1};
  */

  color[] = TSD9_ColorAttribute_Clear;
  colorText[] = TSD9_ColorAttribute_Clear;
  colorBackground[] = TSD9_ColorAttribute_Clear;
  //colorSelect[] = TSD9_ColorAttribute_Clear;
  //colorSelect2[] = TSD9_ColorAttribute_Clear;
  colorScrollbar[] = TSD9_ColorAttribute_Clear;
  //colorSelectBackground[] = TSD9_ColorAttribute_Clear;
  //colorSelectBackground2[] = TSD9_ColorAttribute_Clear;
};
//------------------
class TSD9_CELLButton: TSD9_RscButton
{
  //x = 0.01;
  //y = 0.98;
  w = safeZoneW*0.08;
  h = TSD9_ROWHGT;
  sizeEx = TSD9_TEXTHGT;
  borderSize = 0.001;

  colorText[] = {TSD9_ColorScheme_3DControlText, 1};
  colorBackground[] = TSD9_ColorAttribute_Clear;
  colorFocused[] = {TSD9_ColorScheme_3DControlFocus, 1};
  colorBackgroundActive[] = {TSD9_ColorScheme_3DControlFocus, 1};
  colorShadow[] = TSD9_ColorAttribute_Clear;
  colorBorder[] = TSD9_ColorAttribute_Clear;
};

class TSD9_MainButton: TSD9_RscShortcutButton
{
  y = safeZoneY+safeZoneH-TSD9_CONTROLHGT;
  w = safeZoneW*0.09;
  //h = 1.5*TSD9_ROWHGT;
  //sizeEx = TSD9_CONTROLHGT;
  //borderSize = 0.001;

  /*
  colorText[] = {TSD9_ColorScheme_3DControlText,1};
  colorBackground[] = {TSD9_ColorScheme_3DControlBackground, 1};
  colorFocused[] = {TSD9_ColorScheme_3DControlFocus, 1};
  colorBackgroundActive[] = {TSD9_ColorScheme_3DControlFocus, 1};
  */
  //colorShadow[] = {TSD9_Color_Gray_7, 1};
  //colorBorder[] = {TSD9_Color_Gray_6, 1};
};

//-----------------------------------------------------------------
class TSD9_ColBase_01: TSD9_CELLA
{
  w = TSD9_COLWID_MOD*(CWP_1);
  x = TSD9_X+safeZoneW*0.0;
};

//---- test "image buttons" (picture with transparent button over it).
/*
class TSD9_ColBase_01_ButtonPicture: RscPicture
{
  w = TSD9_COLWID_MOD*(CWP_1);
  x = 0.0;
  h = TSD9_ROWHGT;
  sizeEx = TSD9_TEXTHGT;
	colorBackground[] = {TSD9_color_cellABG, 1};

  //"\CA\ui\data\i_prev_group_ca.paa";
  //text="\CA\ui\data\i_next_group_ca.paa";

  //text="\CA\ui\data\marker_x_ca.paa";

  //text="\CA\ui\data\ui_sipka.paa";

  text="\CA\ui\data\ui_map_arrow_close_ca.paa";
  //text="\CA\ui\data\ui_map_arrow_open_ca.paa";

  //text="\CA\ui\data\tankdir_right_ca.paa";
  //text="\CA\ui\data\tankdir_left_ca.paa";
};
*/

class TSD9_ColBase_01_Button: TSD9_CELLButton
{
  w = TSD9_COLWID_MOD*(CWP_1);
  x = TSD9_X;

  colorBackground[] = {TSD9_color_cellABG, 1};
  //colorBackground[] = TSD9_ColorAttribute_Clear; // overlay transparent button over picture control
  //colorShadow[] = TSD9_ColorAttribute_Clear;
};

class TSD9_ColBase_02: TSD9_CELLB
{
  w = TSD9_COLWID_MOD*(CWP_2);
  x = TSD9_X+CWP_1;
};

class TSD9_ColBase_03: TSD9_CELLA
{
  w = TSD9_COLWID_MOD*(CWP_3);
  x = TSD9_X+CWP_1+CWP_2;
};

class TSD9_ColBase_04: TSD9_CELLCombo
{
  w = TSD9_COLWID_MOD*(CWP_4);
  x = TSD9_X+CWP_1+CWP_2+CWP_3;
  //colorBackground[] = {TSD9_Color_Gray_4, 1};
};

//---- title variation
class TSD9_ColBase_04_combo: TSD9_CELLA
{
  w = TSD9_COLWID_MOD*(CWP_4);
  x = TSD9_X+CWP_1+CWP_2+CWP_3;
};

class TSD9_ColBase_05: TSD9_CELLCombo
{
  w = TSD9_COLWID_MOD*(CWP_5);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4;
  //colorBackground[] = {TSD9_Color_Gray_4, 1};
};

//---- title variation
class TSD9_ColBase_05_combo: TSD9_CELLA
{
  w = TSD9_COLWID_MOD*(CWP_5);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4;
};

/*
class TSD9_ColBase_06: TSD9_CELLB
{
  w = TSD9_COLWID_MOD*(CWP_6);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5;
};
*/

class TSD9_ColBase_07: TSD9_CELLCombo
{
  w = TSD9_COLWID_MOD*(CWP_7);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6;
  //colorBackground[] = {TSD9_Color_Gray_4, 1};
};

//---- title variation
class TSD9_ColBase_07_combo: TSD9_CELLA
{
  w = TSD9_COLWID_MOD*(CWP_7);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6;
};

class TSD9_ColBase_08: TSD9_CELLB
{
  style = TSD9_ST_RIGHT;
  w = TSD9_COLWID_MOD*(CWP_8);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7;
};

class TSD9_ColBase_09: TSD9_CELLA
{
  style = TSD9_ST_RIGHT;
  w = TSD9_COLWID_MOD*(CWP_9);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8;
};

class TSD9_ColBase_10: TSD9_CELLB
{
  style = TSD9_ST_RIGHT;
  w = TSD9_COLWID_MOD*(CWP_10);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9;
};

class TSD9_ColBase_11: TSD9_CELLA
{
  style = TSD9_ST_RIGHT;
  w = TSD9_COLWID_MOD*(CWP_11);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10;
};

class TSD9_ColBase_12: TSD9_CELLB
{
  style = TSD9_ST_RIGHT;
  w = TSD9_COLWID_MOD*(CWP_12);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10+CWP_11;
};

class TSD9_ColBase_13: TSD9_CELLA
{
  w = TSD9_COLWID_MOD*(CWP_13);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10+CWP_11+CWP_12;
};

class TSD9_ColBase_18: TSD9_CELLB
{
  w = TSD9_COLWID_MOD*(CWP_18);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10+CWP_11+CWP_12+CWP_13;
};

class TSD9_ColBase_14: TSD9_CELLCombo
{
  w = TSD9_COLWID_MOD*(CWP_14);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10+ CWP_11+CWP_12+CWP_13+CWP_18;
  //colorBackground[] = {TSD9_Color_Gray_4, 1};
};

//---- title variation
class TSD9_ColBase_14_combo: TSD9_CELLA
{
  w = TSD9_COLWID_MOD*(CWP_14);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10+ CWP_11+CWP_12+CWP_13+CWP_18;
};

class TSD9_ColBase_15: TSD9_CELLB
{
  w = TSD9_COLWID_MOD*(CWP_15);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10+ CWP_11+CWP_12+CWP_13+CWP_18+CWP_14;
};

/*
class TSD9_ColBase_16: TSD9_CELLA
{
  style = TSD9_ST_RIGHT;
  w = TSD9_COLWID_MOD*(CWP_16);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10+ CWP_11+CWP_12+CWP_13+CWP_18+CWP_14+CWP_15;
};
*/

class TSD9_ColBase_17: TSD9_CELLB
{
  style = TSD9_ST_RIGHT;
  w = TSD9_COLWID_MOD*(CWP_17);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10+CWP_11+CWP_12+CWP_13+CWP_18+CWP_14+CWP_15+CWP_16;
};

class TSD9_ColBase_19: TSD9_CELLA
{
  w = TSD9_COLWID_MOD*(CWP_19);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10+CWP_11+CWP_12+CWP_13+CWP_18+CWP_14+CWP_15+CWP_16+CWP_17;
  //x = TSD9_ColBase_18.x + CWP_18;
};

//---- variation
class TSD9_ColBase_19_Button: TSD9_CELLButton // : TSD9_RscShortcutButton
{
  w = TSD9_COLWID_MOD*(CWP_19);
  x = TSD9_X+CWP_1+CWP_2+CWP_3+CWP_4+CWP_5+CWP_6+CWP_7+CWP_8+CWP_9+CWP_10+CWP_11+CWP_12+CWP_13+CWP_18+CWP_14+CWP_15+CWP_16+CWP_17;
  //text = "New group";
  colorBackground[] = {TSD9_color_cellABG, 1};
};

//=============================================================================
  //TSD9_Col_00_Row_##RowX,\
#define ExpandMacro_RowControls(RowX) \
  TSD9_Col_01_Row_##RowX,\
  TSD9_Col_02_Row_##RowX,\
  TSD9_Col_03_Row_##RowX,\
  TSD9_Col_04_Row_##RowX,\
  TSD9_Col_05_Row_##RowX,\
  /*TSD9_Col_06_Row_##RowX,*/\
  TSD9_Col_07_Row_##RowX,\
  TSD9_Col_08_Row_##RowX,\
  /* TSD9_Col_09_Row_##RowX,\
  TSD9_Col_10_Row_##RowX,\
  TSD9_Col_11_Row_##RowX,\
  TSD9_Col_12_Row_##RowX,\
  */ TSD9_Col_13_Row_##RowX,\
  TSD9_Col_14_Row_##RowX,\
  TSD9_Col_15_Row_##RowX,\
  /*TSD9_Col_16_Row_##RowX,*/\
  TSD9_Col_17_Row_##RowX,\
  TSD9_Col_18_Row_##RowX,\
  TSD9_Col_19_Row_##RowX

//class TSD9_Col_00_Row_01: TSD9_ColBase_01_ButtonPicture { idc = -1; y = (TSD9_CONTROLHGT * 1)+TSD9_FIRSTROW; };
#define ExpandMacro_RowControlsClasses(RowX) \
  class TSD9_Col_01_Row_##RowX: TSD9_ColBase_01_Button { style = TSD9_ST_CENTER; idc = 1000+(##RowX*100)+01; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_02_Row_##RowX: TSD9_ColBase_02 { idc = 1000+(##RowX*100)+02; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_03_Row_##RowX: TSD9_ColBase_03 { idc = 1000+(##RowX*100)+03; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_04_Row_##RowX: TSD9_ColBase_04 { idc = 1000+(##RowX*100)+04; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_05_Row_##RowX: TSD9_ColBase_05 { idc = 1000+(##RowX*100)+05; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  /*class TSD9_Col_06_Row_##RowX: TSD9_ColBase_06 { idc = 1000+(##RowX*100)+06; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };*/\
  class TSD9_Col_07_Row_##RowX: TSD9_ColBase_07 { idc = 1000+(##RowX*100)+07; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_08_Row_##RowX: TSD9_ColBase_08 { idc = 1000+(##RowX*100)+08; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  /* class TSD9_Col_09_Row_##RowX: TSD9_ColBase_09 { idc = 1000+(##RowX*100)+09; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_10_Row_##RowX: TSD9_ColBase_10 { idc = 1000+(##RowX*100)+10; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_11_Row_##RowX: TSD9_ColBase_11 { idc = 1000+(##RowX*100)+11; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_12_Row_##RowX: TSD9_ColBase_12 { idc = 1000+(##RowX*100)+12; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };*/\
  class TSD9_Col_13_Row_##RowX: TSD9_ColBase_13 { idc = 1000+(##RowX*100)+13; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_14_Row_##RowX: TSD9_ColBase_14 { idc = 1000+(##RowX*100)+14; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_15_Row_##RowX: TSD9_ColBase_15 { idc = 1000+(##RowX*100)+15; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  /*class TSD9_Col_16_Row_##RowX: TSD9_ColBase_16 { idc = 1000+(##RowX*100)+16; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };*/\
  class TSD9_Col_17_Row_##RowX: TSD9_ColBase_17 { idc = 1000+(##RowX*100)+17; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_18_Row_##RowX: TSD9_ColBase_18 { idc = 1000+(##RowX*100)+18; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; };\
  class TSD9_Col_19_Row_##RowX: TSD9_ColBase_19_Button { style = TSD9_ST_LEFT; idc = 1000+(##RowX*100)+19; y = (TSD9_CONTROLHGT * ##RowX)+TSD9_FIRSTROW; }

//=============================================================================
class ICE_TeamStatusDialog
{
  idd = TSD9_IDD_TeamStatusDialog;

  movingEnable = true;
  controlsBackground[] = { MY_BACKGROUND, MY_FRAME };

  //-----------------------------------------------------------------------------
  class MY_BACKGROUND: TSD9_FullBackground
  {
    idc = -1;
    x = TSD9_X;
    w = TSD9_W;
    colorBackground[] = {TSD9_ColorScheme_MenuBackground, 0.4};
  };
  class MY_FRAME: TSD9_WindowCaption
  {
    idc = TSD9_IDC_FrameCaption;
    x = TSD9_X;
    w = TSD9_W;
    sizeEx = TSD9_CONTROLHGT;
    //colorBackground[] = TSD9_ColorAttribute_Clear;
    //colorText[] = {TSD9_ColorScheme_WindowText, 1};
    text = "";
  };
  //-----------------------------------------------------------------------------
  objects[] = { };
  controls[] = {

    //TSD9_Grid,
    TSD9_Col_01,
    TSD9_Col_02,
    TSD9_Col_03,
    TSD9_Col_04,
    TSD9_Col_05,
    //TSD9_Col_06,
    TSD9_Col_07,
    TSD9_Col_08,
    /*TSD9_Col_09,
    TSD9_Col_10,
    TSD9_Col_11,
    TSD9_Col_12,*/
    TSD9_Col_13,
    TSD9_Col_14,
    TSD9_Col_15,
    //TSD9_Col_16,
    TSD9_Col_17,
    TSD9_Col_18,
    TSD9_Col_19,

    ExpandMacro_RowControls(01),
    ExpandMacro_RowControls(02),
    ExpandMacro_RowControls(03),
    ExpandMacro_RowControls(04),
    ExpandMacro_RowControls(05),
    ExpandMacro_RowControls(06),
    ExpandMacro_RowControls(07),
    ExpandMacro_RowControls(08),
    ExpandMacro_RowControls(09),
    ExpandMacro_RowControls(10),
    ExpandMacro_RowControls(11),
    ExpandMacro_RowControls(12),
    ExpandMacro_RowControls(13),
    ExpandMacro_RowControls(14),
    ExpandMacro_RowControls(15),
    ExpandMacro_RowControls(16),
    ExpandMacro_RowControls(17),
    ExpandMacro_RowControls(18),
    ExpandMacro_RowControls(19),
    ExpandMacro_RowControls(20),
    ExpandMacro_RowControls(21),
    ExpandMacro_RowControls(22),
    ExpandMacro_RowControls(23),
    ExpandMacro_RowControls(24),
    ExpandMacro_RowControls(25),
    ExpandMacro_RowControls(26),
    ExpandMacro_RowControls(27),
    ExpandMacro_RowControls(28),
    ExpandMacro_RowControls(29),
    ExpandMacro_RowControls(30),
    ExpandMacro_RowControls(31),
    ExpandMacro_RowControls(32),
    ExpandMacro_RowControls(33),
    ExpandMacro_RowControls(34),
    ExpandMacro_RowControls(35),
    ExpandMacro_RowControls(36),
    ExpandMacro_RowControls(37),
    ExpandMacro_RowControls(38),
    ExpandMacro_RowControls(39),
    ExpandMacro_RowControls(40),

    //TSD9_Progress,
    TSD9_CloseButton,
    TSD9_MyTeamButton,
    TSD9_MyGroupButton,
    TSD9_VehicleButton,
    TSD9_OppositionButton,
    TSD9_CollapseAllButton,
    TSD9_ExpandAllButton
  };
  //---------------------------------------------------------------------------
  /*
  class TSD9_Progress: TSD9_RscText
  {
	idc = 99;
	x = 0.01;
    y = 0.98;
    h = TSD9_CONTROLHGT;
    w = 0.08;
    colorBackground[] = {TSD9_Color_Gray_1, 1};
    colorText[] = {TSD9_ColorScheme_WindowText, 1};
  };
  */
  //---------
  /*
  class TSD9_Grid: RscListNBox
  {
	idc = TSD9_IDC_Grid;
    columns[] = {0.0, 0.2, 0.6, 0.8};
  };
  */
  //---------
  class TSD9_CloseButton: TSD9_MainButton
  {
	idc = TSD9_IDC_CloseButton;
	x = TSD9_X+TSD9_W*0.01;
    text = "Close"; // ctrlSetText doesn't work for RscShortcutButton? So hard code it here in English for now.
  };
  //---------
  class TSD9_MyTeamButton: TSD9_MainButton
  {
	idc = TSD9_IDC_MyTeamButton;
	x = TSD9_X+TSD9_W*0.18;
    text = "My team";
    default = true;
  };
  //---------
  class TSD9_MyGroupButton: TSD9_MainButton
  {
	idc = TSD9_IDC_MyGroupButton;
	x = TSD9_X+TSD9_W*0.32;
    text = "My group";
  };
  //---------
  class TSD9_VehicleButton: TSD9_MainButton
  {
	idc = TSD9_IDC_VehicleButton;
	x = TSD9_X+TSD9_W*0.45;
    text = "Vehicle";
  };
  //---------
  class TSD9_OppositionButton: TSD9_MainButton
  {
	idc = TSD9_IDC_OppositionButton;
	x = TSD9_X+TSD9_W*0.58;
    text = "Opposition";
  };
  //---------
  class TSD9_CollapseAllButton: TSD9_MainButton
  {
	idc = TSD9_IDC_CollapseAllButton;
	x = TSD9_X+TSD9_W*0.74;
    text = "Collapse all";
  };
  //---------
  class TSD9_ExpandAllButton: TSD9_MainButton
  {
	idc = TSD9_IDC_ExpandAllButton;
	x = TSD9_X+TSD9_W*0.87;
    text = "Expand all";
  };
  //-----------------------------------------------------------------------------
  // title row
  class TSD9_Col_01: TSD9_ColBase_01 { idc = 1001; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"+/-"
  class TSD9_Col_02: TSD9_ColBase_02 { idc = 1002; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"#"
  class TSD9_Col_03: TSD9_ColBase_03 { idc = 1003; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Name"
  class TSD9_Col_04: TSD9_ColBase_04_combo { idc = 1004; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Vehicle +"
  class TSD9_Col_05: TSD9_ColBase_05_combo { idc = 1005; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Seat"
  //class TSD9_Col_06: TSD9_ColBase_06 { idc = 1006; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Role"
  class TSD9_Col_07: TSD9_ColBase_07_combo { idc = 1007; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Gear +"
  class TSD9_Col_08: TSD9_ColBase_08 { idc = 1008; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Score"
  class TSD9_Col_09: TSD9_ColBase_09 { idc = 1009; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Work"
  class TSD9_Col_10: TSD9_ColBase_10 { idc = 1010; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Kills"
  class TSD9_Col_11: TSD9_ColBase_11 { idc = 1011; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Deaths"
  class TSD9_Col_12: TSD9_ColBase_12 { idc = 1012; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"TK's"
  class TSD9_Col_13: TSD9_ColBase_13 { idc = 1013; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Command"
  class TSD9_Col_14: TSD9_ColBase_14_combo { idc = 1014; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Requires +"
  class TSD9_Col_15: TSD9_ColBase_15 { idc = 1015; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Pos"
  //class TSD9_Col_16: TSD9_ColBase_16 { idc = 1016; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"SL Prox"
  class TSD9_Col_17: TSD9_ColBase_17 { idc = 1017; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"My Prox"
  class TSD9_Col_18: TSD9_ColBase_18 { idc = 1018; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Target"
  class TSD9_Col_19: TSD9_ColBase_19 { idc = 1019; style = TSD9_ST_CENTER; y = safeZoneY+TSD9_CONTROLHGT * 1; text = ""; }; //"Actions"
  //---------------------------------------------
  // data rows
  ExpandMacro_RowControlsClasses(01);
  ExpandMacro_RowControlsClasses(02);
  ExpandMacro_RowControlsClasses(03);
  ExpandMacro_RowControlsClasses(04);
  ExpandMacro_RowControlsClasses(05);
  ExpandMacro_RowControlsClasses(06);
  ExpandMacro_RowControlsClasses(07);
  ExpandMacro_RowControlsClasses(08);
  ExpandMacro_RowControlsClasses(09);
  ExpandMacro_RowControlsClasses(10);
  ExpandMacro_RowControlsClasses(11);
  ExpandMacro_RowControlsClasses(12);
  ExpandMacro_RowControlsClasses(13);
  ExpandMacro_RowControlsClasses(14);
  ExpandMacro_RowControlsClasses(15);
  ExpandMacro_RowControlsClasses(16);
  ExpandMacro_RowControlsClasses(17);
  ExpandMacro_RowControlsClasses(18);
  ExpandMacro_RowControlsClasses(19);
  ExpandMacro_RowControlsClasses(20);
  ExpandMacro_RowControlsClasses(21);
  ExpandMacro_RowControlsClasses(22);
  ExpandMacro_RowControlsClasses(23);
  ExpandMacro_RowControlsClasses(24);
  ExpandMacro_RowControlsClasses(25);
  ExpandMacro_RowControlsClasses(26);
  ExpandMacro_RowControlsClasses(27);
  ExpandMacro_RowControlsClasses(28);
  ExpandMacro_RowControlsClasses(29);
  ExpandMacro_RowControlsClasses(30);
  ExpandMacro_RowControlsClasses(31);
  ExpandMacro_RowControlsClasses(32);
  ExpandMacro_RowControlsClasses(33);
  ExpandMacro_RowControlsClasses(34);
  ExpandMacro_RowControlsClasses(35);
  ExpandMacro_RowControlsClasses(36);
  ExpandMacro_RowControlsClasses(37);
  ExpandMacro_RowControlsClasses(38);
  ExpandMacro_RowControlsClasses(39);
  ExpandMacro_RowControlsClasses(40);
};

#endif // _TSD9_TeamStatusDialog_hpp_
