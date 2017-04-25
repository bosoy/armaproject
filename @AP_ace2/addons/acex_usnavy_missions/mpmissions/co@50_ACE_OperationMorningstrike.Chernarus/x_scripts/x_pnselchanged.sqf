// by Xeno
private ["_selection", "_control", "_selectedIndex"];

disableSerialization;

_selection = _this select 0;

_control = _selection select 0;
_selectedIndex = _selection select 1;

if (_selectedIndex == -1) exitWith {};

if (d_show_player_namesx != _selectedIndex) then {
	d_show_player_namesx = _selectedIndex;
	if (d_show_player_namesx == 0) then {
		x_show_pname_hud = false;
		"Turning player names off..." call XfGlobalChat;
	} else {
		x_show_pname_hud = true;
		"Turning player names on..." call XfGlobalChat;
	};
};

if (true) exitWith {};