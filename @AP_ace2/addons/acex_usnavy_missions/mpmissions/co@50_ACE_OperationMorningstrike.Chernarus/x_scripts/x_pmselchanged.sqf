// by Xeno
private ["_selection", "_control", "_selectedIndex"];

disableSerialization;

_selection = _this select 0;

_control = _selection select 0;
_selectedIndex = _selection select 1;

if (_selectedIndex == -1) exitWith {};

_name = d_namep_rarray select _selectedIndex;

_XD_display = findDisplay 11001;

_ctrl = _XD_display displayCtrl 1010;
_ctrl ctrlsettext _name;

if (true) exitWith {};