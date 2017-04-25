// by Xeno
disableSerialization;

private ["_control","_display","_index","_real_list"];
_vlist = ["No Gras", "Medium Gras", "Full Gras"];
_real_list = [50, 25, 12.5];

_display = findDisplay 75335;

_control = _display displayCtrl 101117;
_index = lbCurSel _control;

if (_index < 0) exitWith {};

setTerrainGrid (_real_list select _index);
Server globalChat format ["Gras layer set to: %1",_vlist select _index];

closeDialog 75335;

if (true) exitWith {};
