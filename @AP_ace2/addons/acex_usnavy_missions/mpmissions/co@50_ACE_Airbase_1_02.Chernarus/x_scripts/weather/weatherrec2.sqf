private ["_fog","_pos","_rain","_rainmarkt","_rainy_height","_rainy_width","_rainy2_height","_rainy2_width","_rainy3_height","_rainy3_width","_trigger_side","_world_center","_x","_y"];
if (!x_dynamic_weather) exitWith {};

if (isNil "x_dynamic_weather_fog") then {x_dynamic_weather_fog = false;};
if (isNil "x_dynamic_weather_sandstorm") then {x_dynamic_weather_sandstorm = false;};
if (x_dynamic_weather_sandstorm) then {x_dynamic_weather_fog = false;};

if (isNil "x_weather_array") then {
	x_weather_array = [];
	waitUntil {count x_weather_array > 0};
};

_world_center = getArray(configFile>>"CfgWorlds">>worldName>>"centerPosition");
_x = (_world_center select 0) * 2;
_y = (_world_center select 1) * 2;

_pos = [0,0,0]; // defining pos out of a closed statement.

_trigger_side = format ["%1",playerSide];

_rainy_height = floor (_y / 6);
_rainy_width = floor (_x / 8);
_rainy2_height = floor (_y / 8);
_rainy2_width = floor (_x / 18);
_rainy3_height = _rainy2_height;
_rainy3_width = _rainy2_width;

// Weather triggers
rainy = createTrigger["EmptyDetector" ,(x_weather_array select 0)];
rainy setTriggerArea [_rainy_width, _rainy_height, 148.438, false];
rainy setTriggerActivation [_trigger_side, "PRESENT", false];
rainy setTriggerStatements["this", "", ""];
//if (x_dynamic_weather_sandstorm) then {
//	rainy setSoundEffect ["para", "", "", "sandstorm"];
//};

rainy2 = createTrigger["EmptyDetector" ,(x_weather_array select 1)];
rainy2 setTriggerArea [_rainy2_width, _rainy2_height, -413.41, false];
rainy2 setTriggerActivation [_trigger_side, "PRESENT", false];
rainy2 setTriggerStatements["this", "", ""];
//if (x_dynamic_weather_sandstorm) then {
//	rainy2 setSoundEffect ["para", "", "", "sandstorm"];
//};

rainy3 = createTrigger["EmptyDetector" ,(x_weather_array select 2)];
rainy3 setTriggerArea [_rainy3_width, _rainy3_height, 45, false];
rainy3 setTriggerActivation [_trigger_side, "PRESENT", false];
rainy3 setTriggerStatements["this", "", ""];
//if (x_dynamic_weather_sandstorm) then {
//	rainy3 setSoundEffect ["para", "", "", "sandstorm"];
//};

if (x_dynamic_weather_fog) then {
	foggy = createTrigger["EmptyDetector" ,(x_weather_array select 3)];
	foggy setTriggerArea [_rainy3_width, _rainy3_height, 0, false];
	foggy setTriggerActivation [_trigger_side, "PRESENT", false];
	foggy setTriggerStatements["this", "", ""];
};

_rainmarkt = createMarkerLocal ["rainmark", (x_weather_array select 0)];
_rainmarkt setMarkerShapeLocal "ELLIPSE";
if (!x_dynamic_weather_sandstorm) then {
	_rainmarkt setMarkerColorLocal "ColorBlue";
} else {
	_rainmarkt setMarkerColorLocal "ColorYellow";
};
_rainmarkt setMarkerSizeLocal [_rainy_width, _rainy_height];
_rainmarkt setMarkerDirLocal 148.438;
_rainmarkt setMarkerBrushLocal "FDiagonal";

_rainmarkt = createMarkerLocal ["rainmarkt", _pos];
_rainmarkt setMarkerTypeLocal "DOT";
_rainmarkt setMarkerColorLocal "ColorBlack";
if (!x_dynamic_weather_sandstorm) then {
	_rainmarkt setMarkerTextLocal "R A I N";
} else {
	_rainmarkt setMarkerTextLocal "Sandstorm";
};
_rainmarkt setMarkerSizeLocal [0, 0];

_rainmarkt = createMarkerLocal ["rainmark2", (x_weather_array select 1)];
_rainmarkt setMarkerShapeLocal "ELLIPSE";
if (!x_dynamic_weather_sandstorm) then {
	_rainmarkt setMarkerColorLocal "ColorBlue";
} else {
	_rainmarkt setMarkerColorLocal "ColorYellow";
};
_rainmarkt setMarkerSizeLocal [_rainy2_width, _rainy2_height];
_rainmarkt setMarkerDirLocal -413.41;
_rainmarkt setMarkerBrushLocal "FDiagonal";

_rainmarkt = createMarkerLocal ["rainmarkt2", _pos];
_rainmarkt setMarkerTypeLocal "DOT";
_rainmarkt setMarkerColorLocal "ColorBlack";
if (!x_dynamic_weather_sandstorm) then {
	_rainmarkt setMarkerTextLocal "R A I N";
} else {
	_rainmarkt setMarkerTextLocal "Sandstorm";
};
_rainmarkt setMarkerSizeLocal [0, 0];

_rainmarkt = createMarkerLocal ["rainmark3", (x_weather_array select 2)];
_rainmarkt setMarkerShapeLocal "ELLIPSE";
if (!x_dynamic_weather_sandstorm) then {
	_rainmarkt setMarkerColorLocal "ColorBlue";
} else {
	_rainmarkt setMarkerColorLocal "ColorYellow";
};
_rainmarkt setMarkerSizeLocal [_rainy3_width, _rainy3_height];
_rainmarkt setMarkerDirLocal 45;
_rainmarkt setMarkerBrushLocal "FDiagonal";

_rainmarkt = createMarkerLocal ["rainmarkt3", _pos];
_rainmarkt setMarkerTypeLocal "DOT";
_rainmarkt setMarkerColorLocal "ColorBlack";
if (!x_dynamic_weather_sandstorm) then {
	_rainmarkt setMarkerTextLocal "R A I N";
} else {
	_rainmarkt setMarkerTextLocal "Sandstorm";
};
_rainmarkt setMarkerSizeLocal [0, 0];

if (x_dynamic_weather_fog) then {
	_rainmarkt = createMarkerLocal ["fogmark", (x_weather_array select 3)];
	_rainmarkt setMarkerShapeLocal "ELLIPSE";
	_rainmarkt setMarkerColorLocal "ColorWhite";
	_rainmarkt setMarkerSizeLocal [_rainy3_width, _rainy3_height];
	_rainmarkt setMarkerDirLocal 0;
	_rainmarkt setMarkerBrushLocal "Solid";

	_rainmarkt = createMarkerLocal ["fogmarkt", _pos];
	_rainmarkt setMarkerTypeLocal "DOT";
	_rainmarkt setMarkerColorLocal "ColorBlack";
	_rainmarkt setMarkerTextLocal "F O G";
	_rainmarkt setMarkerSizeLocal [0, 0];

	_fog = [] execVM "x_scripts\weather\fog.sqf";
};
if (!x_dynamic_weather_sandstorm) then {
	_rain = [] execVM "x_scripts\weather\rain.sqf";
} else {
	x_dosandstorm = compile preprocessFile "\x_misc\scripts\weather\x_dosandstorm.sqf";
	switch (x_sandstorm_type) do {
		case 1: {[] execVM "\x_misc\scripts\weather\x_sandstorm.sqf";};
		case 2: {[] execVM "\x_misc\scripts\weather\x_sandstorm1.sqf";};
		case 3: {[] execVM "\x_misc\scripts\weather\x_sandstorm2.sqf";};
		case 4: {[] execVM "\x_misc\scripts\weather\x_sandstorm3.sqf";};
	}
};

XWeatherLoop = {
	rainy setPos (x_weather_array select 0);
	rainy2 setPos (x_weather_array select 1);
	rainy3 setPos (x_weather_array select 2);
	if (x_dynamic_weather_fog) then {
		foggy setPos (x_weather_array select 3);
	};
	"rainmark" setMarkerPosLocal (x_weather_array select 0);
	"rainmarkt" setMarkerPosLocal (x_weather_array select 0);
	"rainmark2" setMarkerPosLocal (x_weather_array select 1);
	"rainmarkt2" setMarkerPosLocal (x_weather_array select 1);
	"rainmark3" setMarkerPosLocal (x_weather_array select 2);
	"rainmarkt3" setMarkerPosLocal (x_weather_array select 2);
	if (x_dynamic_weather_fog) then {
		"fogmark" setMarkerPosLocal (x_weather_array select 3);
		"fogmarkt" setMarkerPosLocal (x_weather_array select 3);
	};
};

if (true) exitWith {};
