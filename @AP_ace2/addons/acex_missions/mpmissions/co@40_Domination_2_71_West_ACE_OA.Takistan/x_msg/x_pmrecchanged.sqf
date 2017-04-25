// by Xeno
#define THIS_FILE "x_pmrecchanged.sqf"
#include "x_setup.sqf"
private ["_selection", "_control", "_selectedIndex"];

disableSerialization;

_selection = _this select 0;

_selectedIndex = _selection select 1;

if (_selectedIndex == -1) exitWith {};

_ar = x_pm_received_ar select _selectedIndex;

_XD_display = __uiGetVar(XD_MsgDialog);

_ctrl = _XD_display displayCtrl 1201;
_ctrl ctrlsettext (_ar select 1);

_index = GVAR(namep_rarray) find (_ar select 0);
if (_index != -1) then {
	_ctrl = _XD_display displayCtrl 1005;
	_ctrl lbSetCurSel _index;
};