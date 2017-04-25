// by Xeno
disableSerialization;

private ["_control","_display","_index","_rarray"];
lbClear 101113;
_display = findDisplay 75335;
_control = _display displayCtrl 101117;

_rarray = ["No Gras", "Medium Gras", "Full Gras"];

for "_i" from 0 to (count _rarray - 1) do {
	call compile format ["_index = _control lbAdd ""%1"";",_rarray select _i];
};

_control lbSetCurSel 0;

if (true) exitWith {};
