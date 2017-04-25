#include "script_component.hpp"
// Desc: Debug output dialog functions
// By: Dr Eyeball
// Version: 1.0 (May 2007)
//-----------------------------------------------------------------------------
DBG3_DebugData = [];
//-----------------------------------------------------------------------------
// Debug initialization only - remove for final version
//_Action = player addAction ["> Debug Output", "Scripts\Debug\ShowDebugDialog.sqf", [player], 0, false, false, "" /* "teamSwitch" */ ];
//-----------------------------------------------------------------------------
fn_DebugAppend = {
  PARAMS_1(_desc);
  _item = _this select 1;
  _level = 0;
  if (count _this > 2) then { _level = _this select 2 };

  // create a string of spaces to represent indentation
  _fn_GetIndent = {
    _indent2 = "";
    if (_level > 0) then {
      for "_i" from 0 to (_level - 1) do {
        _indent2 = _indent2+"  ";
      };
    };
    _indent2;
  };

  // determine whether this has nested arrays, which requires recursion to display
  _containsSubArrays = false;
  if (typeName _item == "ARRAY") then {
    {
      if (typeName _x == "ARRAY") then { _containsSubArrays = true };
    } forEach _item;
  };

  // add debug data to array - either recursively or as simple data
  if (typeName _item == "ARRAY" && _containsSubArrays) then {
    // recursively process nested array
    _indent = [] call _fn_GetIndent;
    if (_level == 0) then { DBG3_DebugData = DBG3_DebugData+[format["%1: (array)", _desc]] };
    DBG3_DebugData = DBG3_DebugData+[_indent+format["[", _level]];
 {
      [_desc, _x, _level+1] call fn_DebugAppend; // WARNING: recursive call
      _level = _level-1; // recursion seems to overwrite local function values and doesn't restore/pop them
    } forEach _item;

    _indent = [] call _fn_GetIndent;
    DBG3_DebugData = DBG3_DebugData+[_indent+format["]", _level]];
  }
  else {
    // display simple data - eg: string, value or 1 level array
    _indent = [] call _fn_GetIndent;
    _quote = """"; if (typeName _item != "STRING") then { _quote = "" };

    if (_level > 0) then {
      DBG3_DebugData = DBG3_DebugData+[format["%3%6%1%6", _item, time, _indent, _level, _desc, _quote]];
    }
    else {
      DBG3_DebugData = DBG3_DebugData+[format["%5: %3%2: %6%1%6", _item, time, _indent, _level, _desc, _quote]];
    };
  };

  // trim excessive output.
  while { count DBG3_DebugData > 2000 } do {
    // delete array index 0 - first entries are oldest
    DBG3_DebugData set [0, "<DeleteMyArrayEntry>"]; // convert to plain text to mark for deletion
    DBG3_DebugData = DBG3_DebugData - ["<DeleteMyArrayEntry>"];
  };

  // Idea: trim based on output time (add time to array)
};
//-----------------------------------------------------------------------------
/*
fn_DebugOutputArray = {
  _array = _this;

  _i = 0; {
    [format["%1: %2", _i, _x]] call CBA_fnc_debug;
    _i = _i + 1;
  } forEach _array;
};
*/
//-----------------------------------------------------------------------------
