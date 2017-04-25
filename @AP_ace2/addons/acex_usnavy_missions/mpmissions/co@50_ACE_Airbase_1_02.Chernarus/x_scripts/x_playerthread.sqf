if (!(local player)) exitWith{};

if (x_dynamic_weather) then {
	waitUntil {!isNil "XWeatherLoop"};
};

if (true) exitWith {};

XMarkerPlayers = {};

while {true} do {
	if (x_show_p_marker) then {
		//[] spawn XMarkerPlayers;
		sleep 0.01;
	};
	sleep 0.212;
	if (x_dynamic_weather) then {
		call XWeatherLoop;
		sleep 0.01;
	};
	sleep 1.12;
};

if (true) exitWith {};