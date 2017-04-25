#include "script_component.hpp"
// Desc: A Yes/No dialog
// By: Dr Eyeball
// Version: 1.0 (May 2007)
//-----------------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------------
// The following IDD & IDC variables should match their equivalents for the dialog (from "Dialogs\YesNoDialog.hpp")
YN3_IDD_YesNoDialog = 390;

YN3_IDC_Text = 894;
YN3_IDC_YesButton = 896;
YN3_IDC_NoButton = 897;

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
YN3_YesButton = {
  closeDialog 0;
};
//----------------------
YN3_NoButton = {
  closeDialog 0;
};
//----------------------
YN3_Main = {
  _Params = _this;
  //[format["_Params = %1", _Params]] call CBA_fnc_debug; // debug

  //_ActionParams = ["ActionParams", _Params, []] call fn_GetParamByName; // optional
  //["YesNoDialog.sqf", _ActionParams] call fn_DebugAppend; // debug

  _Question = ["Question", _Params, "Error: No question"] call fn_GetParamByName;
  _ctrl = YN3_display displayCtrl YN3_IDC_Text;
  _ctrl ctrlSetStructuredText parseText _Question;
};
//-----------------------------------------------------------------------------
// Init
//-----------------------------------------------------------------------------

_ok = createDialog "YN3_YesNoDialog";
if !(_ok) exitWith { hint "createDialog failed" };

YN3_display = findDisplay YN3_IDD_YesNoDialog;

_Params = _this;
//[format["_Params = %1", _this]] call CBA_fnc_debug; // debug
_Params call YN3_Main;
