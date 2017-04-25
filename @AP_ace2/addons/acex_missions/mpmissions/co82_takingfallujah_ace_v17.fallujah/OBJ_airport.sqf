//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// Radio Tower creation script by Pirin
// Tweaks by Reezo
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith{};

  OBJ_AIRPORT = player createSimpleTask ["Capture the Airport"];
  OBJ_AIRPORT setSimpleTaskDescription ["<br />Fallujah Aiport is currently controlled by the enemy. Take control of the airport by neutralizing the enemy and we'll be able to send in additional support.","Capture the Airport","Capture the Airport"];
  OBJ_AIRPORT setSimpleTaskDestination (getMarkerPos "opfor_airport2");

if (true) exitWith{};