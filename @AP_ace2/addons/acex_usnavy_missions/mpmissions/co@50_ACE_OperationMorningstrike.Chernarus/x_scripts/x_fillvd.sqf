// by Xeno
disableSerialization;

private ["_control","_display","_index","_rarray"];
lbClear 101113;
_display = findDisplay 11098;
_control = _display displayCtrl 101113;

_rarray = [900, 1000, 1200, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 10000];

for "_i" from 0 to (count _rarray - 1) do {
	call compile format ["_index = _control lbAdd ""%1"";",_rarray select _i];
};

_control lbSetCurSel 0;

if (true) exitWith {};
