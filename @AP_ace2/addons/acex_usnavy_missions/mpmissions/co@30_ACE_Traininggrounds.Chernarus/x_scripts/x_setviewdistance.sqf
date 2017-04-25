// by Xeno
disableSerialization;

private ["_control","_display","_index"];
_vlist = [900, 1000, 1200, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 10000];

_display = findDisplay 11098;

_control = _display displayCtrl 101113;
_index = lbCurSel _control;

if (_index < 0) exitWith {};

setViewDistance (_vlist select _index);
Server globalChat format ["Viewdistance set to: %1",_vlist select _index];

closeDialog 11098;

if (true) exitWith {};
