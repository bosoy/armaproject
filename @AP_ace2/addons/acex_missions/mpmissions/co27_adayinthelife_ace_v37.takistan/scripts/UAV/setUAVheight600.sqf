//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// This script changes the UAV flying height via an action
//////////////////////////////////////////////////////////////////

private ["_uav","_title","_text","_hint"];
_uav = _this select 0;
_uav flyinheight 600;
(driver _uav) flyinheight 600;
(gunner _uav) flyinheight 600;

_title  = "<t color='#0000FF' size='1.2' shadow='1' shadowColor='#DEDEDE' align='center'>UAV STATUS</t><br/><br/>";
_text   = "Altitude Orbit Changed to 600m";
_hint = parseText (_title + _text);
hintSilent _hint;

if (true) exitWith{};