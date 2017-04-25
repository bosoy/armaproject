/* 
  A day in the life
  by Reezo - www.sr5tactical.net
  
  You are NOT authorized to make changes to this mission
  unless you've been formally authorized by me.
  
*/

"dynamicBlur" ppEffectEnable true;
"dynamicBlur" ppEffectAdjust [6];
"dynamicBlur" ppEffectCommit 0;
"dynamicBlur" ppEffectAdjust [0.0];
"dynamicBlur" ppEffectCommit 7;
titleCut ["", "BLACK IN", 5];

[3] execVM "revive\ReviveAceWounds.sqf";
nul0 = [] execVM "briefing.sqf";

if (isMultiplayer) then {
  setViewDistance (paramsArray select 2);
  if (paramsArray select 1 != 0) then { nul0 = [] execVM "init_ACM.sqf"; };  
  skipTime (paramsArray select 0);  // SKIP TIME TO DESIRED START HOUR
  nul0 = [] execVM "init_RNDweather.sqf";
};

nul0 = [] execVM "scripts\IEDdetect\IEDdetect_init.sqf";
nul0 = [200,4,10,60,"car",0,25,50,20,50,WEST] execVM "scripts\IEDdetect\IEDdetect_ambientBombers.sqf";
nul0 = [300,10,60,0,50,WEST] execVM "scripts\IEDdetect\IEDdetect_ambientProxyIEDs.sqf";
nul0 = [] execVM "scripts\gearing\safeweapon.sqf";

// CUT SCENE
sleep 0.1;
waitUntil{!(isNil "BIS_fnc_init")};
[str ("A Day In The Life") ,  str(date select 1) + "." + str(date select 2) + "." + str(date select 0), str("T A K I S T A N")] spawn BIS_fnc_infoText;
sleep 5;

// Debug
if (!isDedicated && isServer && !isMultiplayer) then
{
  player globalChat "Mission Initialization Complete";
};

if (true) exitWith {};