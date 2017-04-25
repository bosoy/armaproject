//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// Random Weather Conditions
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith {};

//waitUntil {!(isNull player)};
//waitUntil {player==player};

if (isMultiplayer) then {
  _weather = paramsArray select 7;
  _forecast = paramsArray select 8;
} else {
  _weather = 2;
  _forecast = 2;
};

switch (_weather) do
{
  case 0:
  {
    0 setOvercast (random 1);
    0 setFog (random 1);
  };
  case 1:
  {
    0 setOvercast (random 0.5);
    0 setFog (random 0.50);
  };
  case 2:
  {
    0 setOvercast (random 0.20 + 0.40);
    0 setFog (random 0.25);
  };
  case 3:
  {
    0 setOvercast (random 0.5 + 0.5);
    0 setFog (random 0.125);
  };
};

switch (_forecast) do
{
  case 0:
  {
    3600 setOvercast (random 1);
    3600 setFog (random 1);
  };
  case 1:
  {
    3600 setOvercast (random 0.5);
    3600 setFog (random 0.5);
  };
  case 2:
  {
    3600 setOvercast (random 0.20 + 0.40);
    3600 setFog (random 0.25);
  };
  case 3:
  {
    3600 setOvercast (random 0.5 + 0.5);
    3600 setFog (random 0.125);
  };
};

if (!isDedicated && isServer && !isMultiplayer) then {
  player globalChat "RANDOM WEATHER INITIALIZED";
};

if (true) exitWith {};