#include "script_component.hpp"
// Desc: A popup menu dialog
// By: Dr Eyeball
// Version: 1.1 (May 2007)
//-----------------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------------
// The following IDD & IDC variables should match their equivalents for the dialog (from "Dialogs\PopupMenuDialog.hpp")
SIX_PUM3_IDD_PopupMenuDialog = 5390;

SIX_PUM3_IDC_Caption0 = 5892;
SIX_PUM3_IDC_Caption1 = 5893;
SIX_PUM3_IDC_Caption2 = 5894;

SIX_PUM3_IDC_Button000 = 5870;
SIX_PUM3_IDC_Button001 = 5871;
SIX_PUM3_IDC_Button002 = 5872;
SIX_PUM3_IDC_Button003 = 5873;
SIX_PUM3_IDC_Button004 = 5874;
SIX_PUM3_IDC_Button005 = 5875;
SIX_PUM3_IDC_Button006 = 5876;
SIX_PUM3_IDC_Button007 = 5877;
SIX_PUM3_IDC_Button008 = 5878;
SIX_PUM3_IDC_Button009 = 5879;
SIX_PUM3_IDC_Button010 = 5880;
SIX_PUM3_IDC_Button011 = 5881;
SIX_PUM3_IDC_Button012 = 5882;
SIX_PUM3_IDC_Button013 = 5883;
SIX_PUM3_IDC_Button014 = 5884;
SIX_PUM3_IDC_Button015 = 5885;
SIX_PUM3_IDC_Button016 = 5886;
SIX_PUM3_IDC_Button017 = 5887;
SIX_PUM3_IDC_Button018 = 5888;
SIX_PUM3_IDC_Button019 = 5889;

SIX_PUM3_IDC_Button100 = 51870;
SIX_PUM3_IDC_Button101 = 51871;
SIX_PUM3_IDC_Button102 = 51872;
SIX_PUM3_IDC_Button103 = 51873;
SIX_PUM3_IDC_Button104 = 51874;
SIX_PUM3_IDC_Button105 = 51875;
SIX_PUM3_IDC_Button106 = 51876;
SIX_PUM3_IDC_Button107 = 51877;
SIX_PUM3_IDC_Button108 = 51878;
SIX_PUM3_IDC_Button109 = 51879;
SIX_PUM3_IDC_Button110 = 51880;
SIX_PUM3_IDC_Button111 = 51881;
SIX_PUM3_IDC_Button112 = 51882;
SIX_PUM3_IDC_Button113 = 51883;
SIX_PUM3_IDC_Button114 = 51884;
SIX_PUM3_IDC_Button115 = 51885;
SIX_PUM3_IDC_Button116 = 51886;
SIX_PUM3_IDC_Button117 = 51887;
SIX_PUM3_IDC_Button118 = 51888;
SIX_PUM3_IDC_Button119 = 51889;

SIX_PUM3_IDC_Button200 = 52870;
SIX_PUM3_IDC_Button201 = 52871;
SIX_PUM3_IDC_Button202 = 52872;
SIX_PUM3_IDC_Button203 = 52873;
SIX_PUM3_IDC_Button204 = 52874;
SIX_PUM3_IDC_Button205 = 52875;
SIX_PUM3_IDC_Button206 = 52876;
SIX_PUM3_IDC_Button207 = 52877;
SIX_PUM3_IDC_Button208 = 52878;
SIX_PUM3_IDC_Button209 = 52879;
SIX_PUM3_IDC_Button210 = 52880;
SIX_PUM3_IDC_Button211 = 52881;
SIX_PUM3_IDC_Button212 = 52882;
SIX_PUM3_IDC_Button213 = 52883;
SIX_PUM3_IDC_Button214 = 52884;
SIX_PUM3_IDC_Button215 = 52885;
SIX_PUM3_IDC_Button216 = 52886;
SIX_PUM3_IDC_Button217 = 52887;
SIX_PUM3_IDC_Button218 = 52888;
SIX_PUM3_IDC_Button219 = 52889;

SIX_PUM3_MenuControls0 = [
  SIX_PUM3_IDC_Caption0,
  SIX_PUM3_IDC_Button000,
  SIX_PUM3_IDC_Button001,
  SIX_PUM3_IDC_Button002,
  SIX_PUM3_IDC_Button003,
  SIX_PUM3_IDC_Button004,
  SIX_PUM3_IDC_Button005,
  SIX_PUM3_IDC_Button006,
  SIX_PUM3_IDC_Button007,
  SIX_PUM3_IDC_Button008,
  SIX_PUM3_IDC_Button009,
  SIX_PUM3_IDC_Button010,
  SIX_PUM3_IDC_Button011,
  SIX_PUM3_IDC_Button012,
  SIX_PUM3_IDC_Button013,
  SIX_PUM3_IDC_Button014,
  SIX_PUM3_IDC_Button015,
  SIX_PUM3_IDC_Button016,
  SIX_PUM3_IDC_Button017,
  SIX_PUM3_IDC_Button018,
  SIX_PUM3_IDC_Button019
  ];
SIX_PUM3_MenuControls1 = [
  SIX_PUM3_IDC_Caption1,
  SIX_PUM3_IDC_Button100,
  SIX_PUM3_IDC_Button101,
  SIX_PUM3_IDC_Button102,
  SIX_PUM3_IDC_Button103,
  SIX_PUM3_IDC_Button104,
  SIX_PUM3_IDC_Button105,
  SIX_PUM3_IDC_Button106,
  SIX_PUM3_IDC_Button107,
  SIX_PUM3_IDC_Button108,
  SIX_PUM3_IDC_Button109,
  SIX_PUM3_IDC_Button110,
  SIX_PUM3_IDC_Button111,
  SIX_PUM3_IDC_Button112,
  SIX_PUM3_IDC_Button113,
  SIX_PUM3_IDC_Button114,
  SIX_PUM3_IDC_Button115,
  SIX_PUM3_IDC_Button116,
  SIX_PUM3_IDC_Button117,
  SIX_PUM3_IDC_Button118,
  SIX_PUM3_IDC_Button119
  ];
SIX_PUM3_MenuControls2 = [
  SIX_PUM3_IDC_Caption2,
  SIX_PUM3_IDC_Button200,
  SIX_PUM3_IDC_Button201,
  SIX_PUM3_IDC_Button202,
  SIX_PUM3_IDC_Button203,
  SIX_PUM3_IDC_Button204,
  SIX_PUM3_IDC_Button205,
  SIX_PUM3_IDC_Button206,
  SIX_PUM3_IDC_Button207,
  SIX_PUM3_IDC_Button208,
  SIX_PUM3_IDC_Button209,
  SIX_PUM3_IDC_Button210,
  SIX_PUM3_IDC_Button211,
  SIX_PUM3_IDC_Button212,
  SIX_PUM3_IDC_Button213,
  SIX_PUM3_IDC_Button214,
  SIX_PUM3_IDC_Button215,
  SIX_PUM3_IDC_Button216,
  SIX_PUM3_IDC_Button217,
  SIX_PUM3_IDC_Button218,
  SIX_PUM3_IDC_Button219
  ];
SIX_PUM3_MenuControlsList = [SIX_PUM3_MenuControls0, SIX_PUM3_MenuControls1, SIX_PUM3_MenuControls2];

SIX_PUM3_dlg_x = 0.05;
SIX_PUM3_dlg_y = 0.20;
SIX_PUM3_dlg_wid = 0.30;
SIX_PUM3_dlg_hgt = 0.9;

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
SIX_PUM3_Exit = {
  closeDialog SIX_PUM3_IDD_PopupMenuDialog;
};
//----------------------
SIX_PUM3_OnClose = {
};
//----------------------
SIX_PUM3_MenuItem00 = {
  call SIX_PUM3_Exit;
};
//----------------------
SIX_PUM3_MenuItem01 = {
  call SIX_PUM3_Exit;
};
//----------------------
SIX_PUM3_MenuItem02 = {
  call SIX_PUM3_Exit;
};
//----------------------
SIX_PUM3_MenuItem03 = {
  call SIX_PUM3_Exit;
};
//----------------------
SIX_PUM3_HideMenus = {
  PARAMS_1(_level);

  switch (_level) do {
    case 0: { { ctrlShow [_x, false] } forEach SIX_PUM3_MenuControls0+SIX_PUM3_MenuControls1+SIX_PUM3_MenuControls2 };
    case 1: { { ctrlShow [_x, false] } forEach SIX_PUM3_MenuControls1+SIX_PUM3_MenuControls2 };
    case 2: { { ctrlShow [_x, false] } forEach SIX_PUM3_MenuControls2 };
  };
};
//----------------------
SIX_PUM3_ShowMenu = {
  [
    _this,
    ["_Params", SIX_PUM3_Params]
  ] call SIX_PUM3_ProcessMenu;
};
//----------------------
SIX_PUM3_ClickButton = {
  PARAMS_1(_IDC);

  _MenuControls = [];
  if (_IDC in SIX_PUM3_MenuControls0) then { SIX_PUM3_Level = 1 };
  if (_IDC in SIX_PUM3_MenuControls1) then { SIX_PUM3_Level = 2 };
  if (_IDC in SIX_PUM3_MenuControls2) then { SIX_PUM3_Level = 3 };

  _MenuControls = SIX_PUM3_MenuControlsList select (SIX_PUM3_Level-1);
  [SIX_PUM3_Level] call SIX_PUM3_HideMenus;

  { // restore color of all menu items in selected menu back to default text color
    uiNameSpace setVariable ["SIX_PUM3_CTRL", (uiNameSpace getVariable "SIX_PUM3_DISPLAY") displayCtrl _x];
    (uiNameSpace getVariable "SIX_PUM3_CTRL")  ctrlSetTextColor [1, 1, 1, 1]; // SIX_Dlg_Color_white // SIX_Dlg_ColorScheme_3DControlText;
  } forEach _MenuControls;

  // mark selected menu item in special color
  uiNameSpace setVariable ["SIX_PUM3_CTRL", (uiNameSpace getVariable "SIX_PUM3_DISPLAY") displayCtrl _IDC];
  (uiNameSpace getVariable "SIX_PUM3_CTRL") ctrlSetTextColor [0.253906, 0.410156, 0.878906, 1]; // SIX_Dlg_Color_RoyalBlue // SIX_Dlg_ColorScheme_CaptionBackground;
  //(uiNameSpace getVariable "SIX_PUM3_CTRL") ctrlSetBackgroundColor [1, 0, 0, 1]; // doesn't work
};
//----------------------
SIX_PUM3_ReplaceCommonParams = {
  PARAMS_1(_action);
  if (_action == "-") then { _action = "------------------------------------------------------------" };
  _action
};
//----------------------
SIX_PUM3_ProcessMenu = {
  _MenuName = ["MenuName", _this, "MainMenu"] call fn_GetParamByName;
  _Params = ["_Params", _this, []] call fn_GetParamByName;
  //[format["ProcessMenu params = %1", _Params]] call CBA_fnc_debug; // debug

  _Menu = [_MenuName, _Params, []] call fn_GetParamByName;

  _MenuControls = SIX_PUM3_MenuControlsList select SIX_PUM3_Level;

  // Setup caption
  _IDC_CaptionControl = _MenuControls select 0;
  _caption = ["Caption", _Menu, "Menu"] call fn_GetParamByName;
  _caption = [_caption] call SIX_PUM3_ReplaceCommonParams;
  ctrlSetText [_IDC_CaptionControl, _caption];
  ctrlShow [_IDC_CaptionControl, true];

  // Setup menu items
  _items = ["Items", _Menu, "Menu"] call fn_GetParamByName;
  _i = 0; {
    _IDC = _x;
    uiNameSpace setVariable ["SIX_PUM3_CTRL", (uiNameSpace getVariable "SIX_PUM3_DISPLAY") displayCtrl _IDC];

    if (_i > 0) then {
      ctrlShow [_IDC, false];
      (uiNameSpace getVariable "SIX_PUM3_CTRL") ctrlSetTextColor [1, 1, 1, 1]; // SIX_Dlg_Color_white // SIX_Dlg_ColorScheme_3DControlText;
    };

    // set menu item caption and action
    if (typeName _items == "ARRAY") then {
      if (_i > 0 && count _items >= _i) then {
        _item = _items select (_i - 1);
        //[format["_Item %1 = %2", _i, _Item]] call CBA_fnc_debug; // debug

        if (count _item > 0) then {
          //if (_i == 1) then { ctrlSetFocus (uiNameSpace getVariable "SIX_PUM3_CTRL") };

          _caption = ["Item", _item, ""] call fn_GetParamByName;
          _separator = (_caption == "-");
          _caption = [_caption] call SIX_PUM3_ReplaceCommonParams;
          ctrlSetText [_IDC, _caption];
          //[format["_cap %1 = %2", _i, _caption]] call CBA_fnc_debug; // debug

          _SubMenuName = ["SubMenu", _item, ""] call fn_GetParamByName;
          //[format["_SubMenuName %1 = '%2' = %3", _i, _SubMenuName, _Item]] call CBA_fnc_debug; // debug
          _Close = ["Close", _item, true] call fn_GetParamByName;
          if (_SubMenuName != "") then { // SubMenu overrides Close
            _Close = false
          };

          _action = ["Action", _item, ""] call fn_GetParamByName;
          if (typeName _action == "CODE") then {
            _action = format["%1", _action];
          };
          _action = format["[%1] call SIX_PUM3_ClickButton; %2", _IDC, _action];
          if (_SubMenuName != "") then {
            _action = format["%2; ['MenuName', '%1'] call SIX_PUM3_ShowMenu", _SubMenuName, _action];
            //[format["_SubMenuName = %1; %2", _SubMenuName, _action]] call CBA_fnc_debug; // debug
          };
          if (_Close) then {
            _action = format["%1; [] call SIX_PUM3_Exit", _action];
          };

          _action = [_action] call SIX_PUM3_ReplaceCommonParams;

          buttonSetAction [_IDC, _action];
          //[format["_act %1 = %2 = %3", _i, typeName _action, _action]] call CBA_fnc_debug; // debug

          _Default = ["Default", _item, false] call fn_GetParamByName;
          if (_Default) then {
            ctrlSetFocus (uiNameSpace getVariable "SIX_PUM3_CTRL"); // doesn't work for buttons?
          };

          ctrlShow [_IDC, true];
          ctrlEnable [_IDC, true];

          _Enabled = ["Enabled", _item, true] call fn_GetParamByName;
          if (_separator) then { _Enabled = false };
          ctrlEnable [_IDC, _Enabled];

          _Hint = ["Hint", _item, ""] call fn_GetParamByName;
          if (_Hint != "") then {
            (uiNameSpace getVariable "SIX_PUM3_CTRL") ctrlSetToolTip _Hint;
          };
        };
      };
    };
    _i = _i + 1;

    (uiNameSpace getVariable "SIX_PUM3_CTRL") ctrlCommit 0; // commits ctrlSetPosition
  } forEach _MenuControls;
};
//----------------------
SIX_PUM3_Main = {
  SIX_PUM3_Level = 0;
  [0] call SIX_PUM3_HideMenus;

  ["MenuName", "MainMenu"] call SIX_PUM3_ShowMenu;

  (uiNameSpace getVariable "SIX_PUM3_DISPLAY") displaySetEventHandler["Unload", "call SIX_PUM3_OnClose"];
};
//-----------------------------------------------------------------------------
// Init
//-----------------------------------------------------------------------------
_ok = createDialog "SIX_PUM3_PopupMenuDialog";
if !(_ok) exitWith { hint "createDialog failed" };

uiNameSpace setVariable ["SIX_PUM3_DISPLAY", findDisplay SIX_PUM3_IDD_PopupMenuDialog];

_closeDialog = format["closeDialog %1", SIX_PUM3_IDD_PopupMenuDialog];

//["PopupMenu.sqf", SIX_PUM3_Params] call fn_DebugAppend; // debug
SIX_PUM3_Params = _this;
//["PopupMenu.sqf", SIX_PUM3_Params] call fn_DebugAppend; // debug
SIX_PUM3_Params call SIX_PUM3_Main;
