/*
===============================================================================================
Day&Weather Script - by Moerderhoschi
Version: 1.0
Date: 30.01.2011

===============================================================================================
*/

//VariableToForcePermanentWeather
if (IsServer and IsNil "DW_ForceWeather") then {DW_ForceWeather=true;publicvariable "DW_ForceWeather"};

//GlobalWindSettings
if (IsServer and IsNil "DW_w1x") then {DW_w1x = (-10+(random 20));publicvariable "DW_w1x"};
if (IsServer and IsNil "DW_w1y") then {DW_w1y = (-10+(random 20));publicvariable "DW_w1y"};
if (IsServer and IsNil "DW_w2x") then {DW_w2x = ((-0.5)+(random 1));publicvariable "DW_w2x"};
if (IsServer and IsNil "DW_w2y") then {DW_w2y = ((-0.5)+(random 1));publicvariable "DW_w2y"};
if (IsServer and IsNil "DW_w3x") then {DW_w3x = (-1+(random 2));publicvariable "DW_w3x"};
if (IsServer and IsNil "DW_w3y") then {DW_w3y = (-1+(random 2));publicvariable "DW_w3y"};
if (IsServer and IsNil "DW_w4x") then {DW_w4x = (-2.5+(random 5));publicvariable "DW_w4x"};
if (IsServer and IsNil "DW_w4y") then {DW_w4y = (-2.5+(random 5));publicvariable "DW_w4y"};
if (IsServer and IsNil "DW_w5x") then {DW_w5x = (-5+(random 10));publicvariable "DW_w5x"};
if (IsServer and IsNil "DW_w5y") then {DW_w5y = (-5+(random 10));publicvariable "DW_w5y"};
if (IsServer and IsNil "DW_w6x") then {DW_w6x = (-10+(random 20));publicvariable "DW_w6x"};
if (IsServer and IsNil "DW_w6y") then {DW_w6y = (-10+(random 20));publicvariable "DW_w6y"};

//ServerDaytimeSettings
if (IsServer and paramsArray select 0 == 1) then {skiptime (random -96)};
if (IsServer and paramsArray select 0 == 2) then {setDate [2020, 7, 20, 1, 0]};
if (IsServer and (paramsArray select 0 != 1) and (paramsArray select 0 != 2)) then {skiptime (paramsArray select 0)};

//ServerWeatherSettings
if (IsServer and paramsArray select 1 == 2) then {if (IsNil "DW_aktweather") then {DW_aktweather = (random 1);publicvariable "DW_aktweather"};0 setOvercast DW_aktweather};
if (IsServer and paramsArray select 1 == 3) then {0 setOvercast (0.25)};
if (IsServer and (paramsArray select 1 != 2) and (paramsArray select 1 != 3)) then {0 setOvercast (paramsArray select 1)};

//ServerRainSettings
if (IsServer and paramsArray select 1 == 2) then {0 setrain DW_aktweather};
if (IsServer and paramsArray select 1 == 3) then {0 setrain (0.25)};
if (IsServer and (paramsArray select 1 != 2) and (paramsArray select 1 != 3)) then {0 setrain (paramsArray select 1)};

//WaitUntil Player exists
waitUntil {!(isNull player)};

//ClientWeatherSettings
if (paramsarray select 1 == 2) then {0 setOvercast DW_aktweather};
if (paramsarray select 1 == 3) then {0 setOvercast (0.25)};
if ((paramsarray select 1 != 2) and (paramsarray select 1 != 3)) then {0 setOvercast (paramsarray select 1)};

sleep 0.5;

//ClientWetaherSettingsForLongTime
if (paramsarray select 1 == 2) then {36000 setOvercast DW_aktweather};
if (paramsarray select 1 == 3) then {36000 setOvercast (0.25)};
if ((paramsarray select 1 != 2) and (paramsarray select 1 != 3)) then {36000 setOvercast (paramsarray select 1)};

//PermanentForcedClientWindAndRainSettings
while {DW_ForceWeather} do {

sleep 1;

if (paramsArray select 1 == 2) then {setwind [DW_w1x,DW_w1y,true]};
if (paramsArray select 1 == 0) then {setwind [DW_w2x,DW_w2y,true]};
if (paramsArray select 1 == 3) then {setwind [DW_w3x,DW_w3y,true]};
if (paramsArray select 1 == (0.5)) then {setwind [DW_w4x,DW_w4y,true]};
if (paramsArray select 1 == (0.75)) then {setwind [DW_w5x,DW_w5y,true]};
if (paramsArray select 1 == 1) then {setwind [DW_w6x,DW_w6y,true]};

if (paramsArray select 1 == 2) then {3 setrain DW_aktweather};
if (paramsArray select 1 == 3) then {3 setrain (0.25)};
if ((paramsArray select 1 != 2) and (paramsArray select 1 != 3)) then {3 setrain (paramsArray select 1)};

};