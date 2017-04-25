//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// This script fills a crate will all the gear required for a Squad Leader Team
//////////////////////////////////////////////////////////////////

//INIT
private ["_object"];
_object = _this select 0;
waitUntil {!(isNull _object)};
waitUntil {_object == _object};

nul0 = [_object,1] execVM "scripts\gearing\RTFA_TL.sqf";
nul0 = [_object,1] execVM "scripts\gearing\RTFA_AAR.sqf";
nul0 = [_object,1] execVM "scripts\gearing\Marksman.sqf";


//END
if (!isMultiplayer && isServer) then {player globalChat "DEBUG: Gearing RTFA_TL complete"};
if (true) exitWith{};