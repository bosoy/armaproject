// by Xeno
private ["_marker"];

if (x_show_p_marker) then {
	x_show_p_marker = false;
} else {
	x_show_p_marker = true;
	Server globalChat "Player markers available";
};

if (!x_show_p_marker) then {
	Server globalChat "Hiding player markers, one moment";
	sleep 2.123;
	for "_i" from 0 to ((count x_show_player_marker) - 1) do {
		call compile format ["
			_marker = ""%1"";
			_marker setMarkerPosLocal [0,0];
			_marker setMarkerTextLocal """";
		", x_show_player_marker select _i];
		sleep 0.01;
	};
	Server globalChat "Player markers hidden";
};

if (true) exitWith {};
