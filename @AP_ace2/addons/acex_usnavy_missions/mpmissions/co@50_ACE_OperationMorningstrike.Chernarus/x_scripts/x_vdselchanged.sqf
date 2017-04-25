// by Xeno
private ["_selection", "_control", "_selectedIndex", "_rarray", "_index"];

disableSerialization;

_selection = _this select 0;

_control = _selection select 0;
_selectedIndex = _selection select 1;

if (_selectedIndex == -1) exitWith {};

_rarray = [900, 1000, 1200, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 10000];

if (d_viewdistance != (_rarray select _selectedIndex)) then {
	d_viewdistance = _rarray select _selectedIndex;
	setViewDistance d_viewdistance;
	(format ["Viewdistance set to: %1",d_viewdistance]) call XfGlobalChat;
};

if (true) exitWith {};