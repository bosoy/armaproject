#include "script_component.hpp"
// Desc: Activate popup menu via onMapSingleClick event
//-----------------------------------------------------------------------------
//_Params = _this;
_MapSingleClickEvent =
'
  if (!dialog && count _units == 0) then { // bypass this dialog, if command is currently being ordered to selected units
    nul =
      [
        // optional onMapSingleClick params
        ["MapClickParams",
          [
            ["Pos", _pos],
            ["Units", _units],
            ["Shift", _shift],
            ["Alt", _alt]
          ]
        ]
      ] spawn COMPILE_FILE(CreatePopupMenu);
  };
';

onMapSingleClick _MapSingleClickEvent; //format["%1", _MapSingleClickEvent];
