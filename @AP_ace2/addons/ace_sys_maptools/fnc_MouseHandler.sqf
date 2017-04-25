/////////////////////////////////////////////////////
// mouseHandler.sqf
// by nou
//
// please see the documentation in add_ruler.sqf
/////////////////////////////////////////////////////
#include "script_component.hpp"
_event	= _this select 0;
_down	= _this select 1;

if((_event select 1) == 0) then {
    if(_down) then {
        GVAR(MouseShift) = _event select 4;
        GVAR(MouseDown) = true;
    } else {
        GVAR(MouseDown) = false;
        GVAR(DragOK) = false;
        GVAR(OffDrag) = false;
        GVAR(LastDragPosition) = [];
        GVAR(MouseShift) = false;
        GVAR(LastDragAzimuth) = -1000;
        [] call GVAR(UpHandlerFnc);
        GVAR(UpHandlerFnc) = {};
        GVAR(DragAction) = "";
    };
};