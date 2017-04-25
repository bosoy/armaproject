//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// IED Detection and Disposal Scripts
//////////////////////////////////////////////////////////////////

// INIT
private ["_IED","_beeping"];
//if (!isServer) exitWith{};
_IED = _this select 0;
_beeping = true;

// BEEPER SOUND
while { _beeping && alive _IED} do {
  _IED say3D "IEDdetect_beep3";
  sleep 2;
  if (_IED == reezo_IEDdetect_activeIED && reezo_IEDdetect_injection == 1) then { _beeping = false };
};

if (true) exitWith {};