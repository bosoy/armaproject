// by Xeno
#define THIS_FILE "x_pmselchanged.sqf"
#include "x_setup.sqf"
private ["_selection", "_control", "_selectedIndex"];

disableSerialization;

_selection = _this select 0;

_control = _selection select 0;
_selectedIndex = _selection select 1;

if (_selectedIndex == -1) exitWith {};

_name = GVAR(namep_rarray) select _selectedIndex;

(__uiGetVar(XD_MsgDialog) displayCtrl 1010) ctrlsettext _name;