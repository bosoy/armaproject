//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// IED Detection and Disposal Scripts
//////////////////////////////////////////////////////////////////

// INIT
private ["_detector","_vehicle","_range","_interval","_skill","_fakeRatio","_title","_text"];
if (count _this != 5) exitWith {hint "REEZO_IEDDETECT_DETECTOR_VEHICLE: WRONG PARAMETERS, QUITTING.."};
if (!isServer) exitWith {};

_vehicle = _this select 0;

_range = _this select 1;
_interval = _this select 2;
_skill = _this select 3;
_fakeRatio = _this select 4;

waitUntil {!(isNull _vehicle)};
waitUntil {_vehicle == _vehicle};

waitUntil {reezo_IEDdetect_initComplete};

if (_range < 5) then { _range = 5 };
if (_interval < 5) then { _interval = 5 };

while {alive _vehicle} do {
  while {isNull driver _vehicle} do { sleep (_interval * 2) };
  if !(driver _vehicle in reezo_IEDdetect_EODs && !(isNull driver _vehicle)) then {
    _detector = driver _vehicle;

    nul0 = [_detector,_range,_interval,_skill,_fakeRatio,_vehicle] execVM "scripts\IEDdetect\IEDdetect_vehicle.sqf";
     
    while {alive _vehicle && alive _detector && _detector == driver _vehicle} do { sleep (_interval); _detector = driver _vehicle;};
  };
};

_reezo_IEDdetect_EODvehiclerespawn = _vehicle addMPEventHandler ["MPrespawn", {nul0 = [_vehicle,_range,_interval,_skill,_fakeRatio] execVM "scripts\IEDdetect\IEDdetect_detector_vehicle.sqf";}];


if (reezo_IEDdetect_debug) then { player globalChat "REEZO_IEDDETECT DEBUG: DETECTOR.SQF COMPLETE" };

if (true) exitWith {};