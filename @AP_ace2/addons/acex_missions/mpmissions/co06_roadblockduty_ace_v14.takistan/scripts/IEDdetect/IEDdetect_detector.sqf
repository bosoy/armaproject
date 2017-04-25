//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// IED Detection and Disposal Scripts
//////////////////////////////////////////////////////////////////

// INIT
private ["_detector","_range","_interval","_skill","_fakeRatio"];
if (count _this != 5) exitWith {hint "REEZO_IEDDETECT: WRONG PARAMETERS, QUITTING.."};

_detector = _this select 0;
if (!local _detector) exitWith {};
waitUntil {reezo_IEDdetect_initComplete};

_range = _this select 1;
_interval = _this select 2;
_skill = _this select 3;
_fakeRatio = _this select 4;

waitUntil {!(isNull _detector)};
waitUntil {_detector == _detector};

if (_range < 5) then { _range = 5 };
if (_interval < 5) then { _interval = 5 };

reezo_IEDdetect_EODs = reezo_IEDdetect_EODs + [_detector];
publicVariable "reezo_IEDdetect_EODs";

_reezo_IEDdetect_EODrespawn = _detector addMPEventHandler ["MPrespawn", {nul0 = [_detector,_range,_interval,_skill,_fakeRatio] execVM "scripts\IEDdetect\IEDdetect_detector.sqf";}];

nul0 = [_detector,_range,_interval,_skill,_fakeRatio] execVM "scripts\IEDdetect\IEDdetect.sqf";

if (reezo_IEDdetect_debug) then { player globalChat "REEZO_IEDDETECT DEBUG: DETECTOR.SQF COMPLETE" };

if (true) exitWith {};