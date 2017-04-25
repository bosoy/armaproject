//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// This script initializes the UAV and makes it non-aggressive and reliable
//////////////////////////////////////////////////////////////////

private ["_UAV","_height","_UAVgroup","_UAVpil","_UAVgnr"];

_UAV = _this select 0;
_height = _this select 1;

waitUntil {!(isNull _UAV)};
waitUntil {_UAV==_UAV};

_UAV flyInHeight _height;
_UAV setposasl [(getpos _UAV) select 0, (getpos _UAV) select 1, _height];
_UAV setcaptive true;

_UAVgrp = createGroup West;

_UAVpil = _UAVgrp createUnit ["US_Pilot_Light_EP1", position _UAV, ["this setSkill 0"], 0, "NONE"];
_UAVgnr = _UAVgrp createUnit ["US_Pilot_Light_EP1", position _UAV, ["this setSkill 0"], 0, "NONE"];

removeAllWeapons _UAVpil;
//_UAVpil setSkill 0.0;
_UAVpil moveinDriver _UAV;
_UAVpil setBehaviour "CARELESS";
_UAVpil setCombatMode "BLUE";
_UAVpil setCaptive true;
_UAVpil disableAI "AUTOTARGET";
_UAVpil disableAI "TARGET";

removeAllWeapons _UAVgnr;
//_UAVgnr setSkill 0.0;
_UAVgnr moveinGunner _UAV;
_UAVgnr setBehaviour "CARELESS";
_UAVgnr setCombatMode "BLUE";
_UAVgnr setCaptive true;
_UAVgnr disableAI "AUTOTARGET";
_UAVgnr disableAI "TARGET";

_UAV addAction ["UAV Altitude to 600m","scripts\UAV\setUAVheight600.sqf"];
_UAV addAction ["UAV Altitude to 500m","scripts\UAV\setUAVheight500.sqf"];
_UAV addAction ["UAV Altitude to 400m","scripts\UAV\setUAVheight400.sqf"];

sleep 0.1;

nul = [] execVM "scripts\UAV\mpUavHandler.sqf";

// END
if (!isMultiplayer) then {player globalChat "DEBUG: INIT_UAV INITIALIZED"};
if (true) exitWith{};