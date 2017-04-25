// F2 - Mission Conditions Selector
// Credits: Please see the F2 online manual (http://www.ferstaberinde.com/f2/en/)
// ====================================================================================

// DECLARE VARIABLES AND FUNCTIONS

private ["_MissionOvercast","_MissionFog"];

// ====================================================================================

// SET KEY VARIABLE
// Conditions are set using the value of f_var_Param1. Usually, f_var_Param1 == Param1.

f_var_Param1 = Param1;
if (isNil "f_var_Param1") then {
	f_var_Param1 = defValueParam1;
};
_setDate = [2007, 5, 11, 12, 30];

// ====================================================================================

// SELECT MISSION CONDITIONS
// Using the value of f_var_Param1, new values for _MissionOvercast and
// _MissionFog are set.

switch (f_var_Param1) do
{
// Noon | Clear
	case 1:
	{
		_setDate = [2007, 5, 11, 12, 0];
		_MissionOvercast = 00.00;
		_MissionFog = 00.00;
	};
// Noon | Overcast
	case 2:
	{
		_setDate = [2007, 5, 11, 12, 0];
		_MissionOvercast = 00.60;
		_MissionFog = 00.10;
	};
// Noon | Storm
	case 3:
	{
		_setDate = [2007, 5, 11, 12, 0];
		_MissionOvercast = 01.00;
		_MissionFog = 00.50;
	};
// Noon | Light Fog
/*	case 4:
	{
		_setDate = [2007, 5, 11, 12, 0];
		_MissionOvercast = 00.60;
		_MissionFog = 00.8125;
	};
// Noon | Heavy Fog
	case 5:
	{
		_setDate = [2007, 5, 11, 12, 0];
		_MissionOvercast = 00.60;
		_MissionFog = 00.96;
	};
*/
// ====================================================================================

// Dusk | Clear
	case 6:
	{
		_setDate = [2007, 5, 11, 18, 50];
		_MissionOvercast = 00.00;
		_MissionFog = 00.00;
	};
// Dusk | Overcast
	case 7:
	{
		_setDate = [2007, 5, 11, 18, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.10;
	};
// Dusk | Storm
	case 8:
	{
		_setDate = [2007, 5, 11, 18, 50];
		_MissionOvercast = 01.00;
		_MissionFog = 00.50;
	};
// Dusk | Light Fog
/*	case 9:
	{
		_setDate = [2007, 5, 11, 18, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.8125;
	};
// Dusk | Heavy Fog
	case 10:
	{
		_setDate = [2007, 5, 11, 18, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.96;
	};
*/
// ====================================================================================

// Night | Clear
	case 11:
	{
		_setDate = [2007, 5, 11, 0, 0];
		_MissionOvercast = 00.00;
		_MissionFog = 00.00;
	};
// Night | Overcast
	case 12:
	{
		_setDate = [2007, 5, 11, 0, 0];
		_MissionOvercast = 00.60;
		_MissionFog = 00.10;
	};
// Night | Storm
	case 13:
	{
		_setDate = [2007, 5, 11, 0, 0];
		_MissionOvercast = 01.00;
		_MissionFog = 00.50;
	};
// Night | Light Fog
/*	case 14:
	{
		_setDate = [2007, 5, 11, 0, 0];
		_MissionOvercast = 00.60;
		_MissionFog = 00.8125;
	};
// Night | Heavy Fog
	case 15:
	{
		_setDate = [2007, 5, 11, 0, 0];
		_MissionOvercast = 00.60;
		_MissionFog = 00.96;
	};
*/
// ====================================================================================

// Dawn | Clear
	case 16:
	{
		_setDate = [2007, 5, 11, 4, 50];
		_MissionOvercast = 00.00;
		_MissionFog = 00.00;
	};
// Dawn | Overcast
	case 17:
	{
		_setDate = [2007, 5, 11, 4, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.10;
	};
// Dawn | Storm
	case 18:
	{
		_setDate = [2007, 5, 11, 4, 50];
		_MissionOvercast = 01.00;
		_MissionFog = 00.50;
	};
// Dawn | Light Fog
/*	case 19:
	{
		_setDate = [2007, 5, 11, 4, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.8125;
	};
// Dawn | Heavy Fog
	case 20:
	{
		_setDate = [2007, 5, 11, 4, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.96;
	};
*/
// ====================================================================================

// Early Morning | Clear
	case 21:
	{
		_setDate = [2007, 5, 11, 5, 50];
		_MissionOvercast = 00.00;
		_MissionFog = 00.00;
	};
// Early Morning | Overcast
	case 22:
	{
		_setDate = [2007, 5, 11, 5, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.10;
	};
// Early Morning | Storm
	case 23:
	{
		_setDate = [2007, 5, 11, 5, 50];
		_MissionOvercast = 01.00;
		_MissionFog = 00.50;
	};
// Early Morning | Light Fog
/*	case 24:
	{
		_setDate = [2007, 5, 11, 5, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.8125;
	};
// Early Morning | Heavy Fog
	case 25:
	{
		_setDate = [2007, 5, 11, 5, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.96;
	};
*/
// ====================================================================================

// Morning | Clear
	case 26:
	{
		_setDate = [2007, 5, 11, 9, 00];
		_MissionOvercast = 00.00;
		_MissionFog = 00.00;
	};
// Morning | Overcast
	case 27:
	{
		_setDate = [2007, 5, 11, 9, 00];
		_MissionOvercast = 00.60;
		_MissionFog = 00.10;
	};
// Morning | Storm
	case 28:
	{
		_setDate = [2007, 5, 11, 9, 00];
		_MissionOvercast = 01.00;
		_MissionFog = 00.50;
	};
// Morning | Light Fog
/*	case 29:
	{
		_setDate = [2007, 5, 11, 9, 00];
		_MissionOvercast = 00.60;
		_MissionFog = 00.8125;
	};
// Morning | Heavy Fog
	case 30:
	{
		_setDate = [2007, 5, 11, 9, 00];
		_MissionOvercast = 00.60;
		_MissionFog = 00.96;
	};
*/
// ====================================================================================

// Afternoon | Clear
	case 31:
	{
		_setDate = [2007, 5, 11, 15, 00];
		_MissionOvercast = 00.00;
		_MissionFog = 00.00;
	};
// Afternoon | Overcast
	case 32:
	{
		_setDate = [2007, 5, 11, 15, 00];
		_MissionOvercast = 00.60;
		_MissionFog = 00.10;
	};
// Afternoon | Storm
	case 33:
	{
		_setDate = [2007, 5, 11, 15, 00];
		_MissionOvercast = 01.00;
		_MissionFog = 00.50;
	};
// Afternoon | Light Fog
/*	case 34:
	{
		_setDate = [2007, 5, 11, 15, 00];
		_MissionOvercast = 00.60;
		_MissionFog = 00.8125;
	};
// Afternoon | Heavy Fog
	case 35:
	{
		_setDate = [2007, 5, 11, 15, 00];
		_MissionOvercast = 00.60;
		_MissionFog = 00.96;
	};
*/
// ====================================================================================

// Evening | Clear
	case 36:
	{
		_setDate = [2007, 5, 11, 17, 50];
		_MissionOvercast = 00.00;
		_MissionFog = 00.00;
	};
// Evening | Overcast
	case 37:
	{
		_setDate = [2007, 5, 11, 17, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.10;
	};
// Evening | Storm
	case 38:
	{
		_setDate = [2007, 5, 11, 17, 50];
		_MissionOvercast = 01.00;
		_MissionFog = 00.50;
	};
// Evening | Light Fog
/*	case 39:
	{
		_setDate = [2007, 5, 11, 17, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.8125;
	};
// Evening | Heavy Fog
	case 40:
	{
		_setDate = [2007, 5, 11, 17, 50];
		_MissionOvercast = 00.60;
		_MissionFog = 00.96;
	};
*/
// ====================================================================================

// Random
	case 90:
	{
		Param1 = 0;
		if (isServer) then
		{
			_weather = [21,22,23,26,27,28,1,2,3,31,32,33,36,37,38,6,7,8,11,12,13,16,17,18];
			Param1 = _weather select floor(random(count _weather));
			publicVariable "Param1";
		}
		else
		{
			waitUntil { Param1 != 0 };
		};
		[] execVM "f\common\f_setMissionConditions.sqf";
	};


// ====================================================================================

// Debug Mode
	case 99:
	{
		_setDate = [2007, 5, 11, 12, 0];
		_MissionOvercast = 00.00;
		_MissionFog = 00.00;
	};
};

// ====================================================================================

// SET MISSION CONDITIONS
// Use new values for _MissionOvercast and _MissionFog to set
// mission conditions on server and all clients (including JIP clients).

0 setOvercast _MissionOvercast;
0 setFog _MissionFog;
if(isServer) then {
	setDate _setDate;
	[] spawn {
		while{true} do{
			serverTime = [date, fogForecast, overcastForecast, rain];
			publicVariable "serverTime";
			sleep 60;
		};
	};
} else {
	waitUntil{!isNil "serverTime"};
	waitUntil{typeName serverTime == "ARRAY"};
	_stime = serverTime select 0;
	_sfog = serverTime select 1;
	_sover = serverTime select 2;
	_srain = serverTime select 3;
	setDate _stime;
	0 setFog _sfog;
	0 setOvercast _sover;
	0 setRain _srain;
};

// DEBUG
if (f_var_debugMode == 1) then
{
	player sideChat format ["DEBUG (f\common\f_setMissionConditions.sqf): _MissionOvercast: %1",_MissionOvercast];
	player sideChat format ["DEBUG (f\common\f_setMissionConditions.sqf): _MissionFog: %1",_MissionFog];
};

// ====================================================================================

if (true) exitWith {};