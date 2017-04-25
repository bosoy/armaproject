#include "script_component.hpp"
// Desc: Debug output dialog
// By: Dr Eyeball
// Version: 1.0 (May 2007)
//-----------------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------------
// The following IDD & IDC variables should match their equivalents for the dialog (from "Dialogs\DebugOutputDialog.hpp")
DBG3_IDD_DebugOutputDialog = 391;

DBG3_IDC_ListBox = 891;
DBG3_IDC_StructuredText = 892;
DBG3_IDC_DetailsButton = 893;

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
DBG3_CloseDetailControl = {
  _visible = ctrlVisible DBG3_IDC_StructuredText;

  ctrlShow [DBG3_IDC_ListBox, _visible];
  ctrlShow [DBG3_IDC_StructuredText, not _visible];

  if (_visible) then {
    buttonSetAction [DBG3_IDC_DetailsButton, "call DBG3_Select"];
    ctrlSetText [DBG3_IDC_DetailsButton, "Details"];
  }
  else {
    buttonSetAction [DBG3_IDC_DetailsButton, "call DBG3_CloseDetailControl"];
    ctrlSetText [DBG3_IDC_DetailsButton, "Back"];
  };
};
//-----------------------------------------------------------------------------
DBG3_Select = {
  _text = lbText[DBG3_IDC_ListBox, lbCurSel DBG3_IDC_ListBox];
  _ctrl = DBG3_display displayCtrl DBG3_IDC_StructuredText;
  _ctrl ctrlSetStructuredText parseText _text;
  //[format["x = %1, %2", _text, DBG3_IDC_StructuredText]] call CBA_fnc_debug; // optional output

  call DBG3_CloseDetailControl;
};
//----------------------
DBG3_Main = {
  _Params = _this;

  ctrlShow [DBG3_IDC_ListBox, true];
  ctrlShow [DBG3_IDC_StructuredText, false];
  //call DBG3_CloseDetailControl;

  _List = ["DebugData", _Params] call fn_GetParamByName;
  //[format["params = %1,%2", _Params, _List]] call CBA_fnc_debug; // debug

  [DBG3_IDC_ListBox, _List] call SIX_Dlg_FillListBoxLists;

  _count = lbSize DBG3_IDC_ListBox;

  // mark last row
  if (_count > 0) then {
    lbSetCurSel [DBG3_IDC_ListBox, _count-1];
  };
};
//-----------------------------------------------------------------------------
// Init
//-----------------------------------------------------------------------------

_ok = createDialog "DBG3_DebugOutputDialog";
if !(_ok) exitWith { hint "createDialog failed" };

DBG3_display = findDisplay DBG3_IDD_DebugOutputDialog;

_Params = _this;
_Params call DBG3_Main;
