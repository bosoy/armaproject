/* 
  COOP 82 - The Taking of Fallujah
  by Reezo - www.sr5tactical.net
  
  You are NOT authorized to make changes to this mission
  unless you've been formally authorized by me.
  
*/

if (isMultiplayer && isServer) then {
  skipTime (paramsArray select 0);  // SKIP TIME TO DESIRED START HOUR
};

"dynamicBlur" ppEffectEnable true;
"dynamicBlur" ppEffectAdjust [6];
"dynamicBlur" ppEffectCommit 0;
"dynamicBlur" ppEffectAdjust [0.0];
"dynamicBlur" ppEffectCommit 7;
titleCut ["", "BLACK IN", 5];

[5] execVM "revive\ReviveAceWounds.sqf";
nul0 = [] execVM "briefing.sqf";
nul0 = [] execVM "init_OBJ.sqf";

if (isMultiplayer) then {
  setViewDistance (paramsArray select 2);
  if (paramsArray select 15 != 0) then { nul0 = [] execVM "init_ACM.sqf"; };
  if (paramsArray select 7 != 0) then { nul0 = [] execVM "init_RNDweather.sqf"; };
  if (paramsArray select 10 != 0) then { nul0 = ["loc_citycenter",1800] execVM "init_ARMORED.sqf"; };  
  if (paramsArray select 11 != 0) then { nul0 = ["loc_citycenter",1800] execVM "init_SNIPERS.sqf"; };  
  if (paramsArray select 12 != 0) then { nul0 = ["loc_citycenter",1800] execVM "init_PATROLS.sqf"; };  
  if (paramsArray select 13 != 0) then { nul0 = ["loc_citycenter",1800] execVM "init_CIVVIES.sqf"; };  
  if (paramsArray select 14 != 0) then { nul0 = ["loc_citycenter",1800] execVM "init_CIVVEH.sqf"; };  
};

if (!isMultiplayer) then { 
  nul0 = [] execVM "init_ACM.sqf";
  nul0 = ["loc_citycenter",1800] execVM "init_SNIPERS.sqf";
  nul0 = ["loc_citycenter",1800] execVM "init_ARMORED.sqf"; 
  nul0 = ["loc_citycenter",1800] execVM "init_PATROLS.sqf"; 
  nul0 = ["loc_citycenter",1800] execVM "init_CIVVIES.sqf";
  nul0 = ["loc_citycenter",1800] execVM "init_CIVVEH.sqf";
  nul0 = [] execVM "init_RNDweather.sqf";
};

nul0 = [] execVM "scripts\gearing\safeweapon.sqf";
nul0 = [] execVM "scripts\IEDdetect\IEDdetect_init.sqf";
nul0 = [200,4,10,60,"car",0,25,50,20,50,WEST] execVM "scripts\IEDdetect\IEDdetect_ambientBombers.sqf";
nul0 = [300,10,60,0,50,WEST] execVM "scripts\IEDdetect\IEDdetect_ambientProxyIEDs.sqf";

// CUT SCENE
sleep 0.1;
waitUntil{!(isNil "BIS_fnc_init")};
[str ("The Taking of Fallujah") ,  str(date select 1) + "." + str(date select 2) + "." + str(date select 0), str("A F T H A K I S T A N")] spawn BIS_fnc_infoText;
sleep 5;

// Debug
if (!isMultiplayer) then { player globalChat "INIT.SQF COMPLETED"; };

if (true) exitWith {};