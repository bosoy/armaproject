// by Xeno
private ["_ap","_as","_i","_marker"];
if (!(local player)) exitWith {};

sleep 3;

XMarkerPlayers = {
	for "_i" from 0 to ((count x_show_player_marker) - 1) do {
		call compile format ["
			_ap = %1;
			_as = ""%1"";
			if (!isNil ""_ap"" && alive _ap && isPlayer _ap) then {
				_as setMarkerPosLocal position _ap;
				_as setMarkerTextLocal name _ap;
			} else {
				_as setMarkerPosLocal [0,0];
				_as setMarkerTextLocal """";
			};
		", x_show_player_marker select _i];
		sleep 0.0123;
	};
};

for "_i" from 0 to ((count x_show_player_marker) - 1) do {
	call compile format ["
		_marker = ""%1"";
		createMarkerLocal [_marker,[0,0]];
		_marker setMarkerColorLocal ""ColorGreen"";
		_marker setMarkerTypeLocal ""dot"";
		_marker setMarkerSizeLocal [0.5, 0.5];
	", x_show_player_marker select _i];
	sleep 0.01;
};

if (true) exitWith {};
