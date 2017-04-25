//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// This script will trigger when the airport is clear from OPFOR forces
// Tweaks by Reezo
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith{};

_marker1pos = getMarkerPos "opfor_airport";
_marker2pos = getMarkerPos "opfor_airport2";

OBJ_AIRPORT setTaskState "SUCCEEDED";
taskhint ["COMPLETED TASK:\nControl the Airport", [0, 1, 0, 0.66], "taskDone"];

sleep 5;

deleteMarker "opfor_airport";
deleteMarker "opfor_airport2";

// Create a marker for the bluefor airport
_marker1 = createMarker["blufor_airport",_marker1pos];
_marker1 setMarkerShape "RECTANGLE";
_marker1 setMarkerColor "ColorBlue";
_marker1 setMarkerDir 240.457;
_marker1 setMarkerSize [800, 390];
_marker1 setMarkerAlpha 0.33; 

_marker2 = createMarker["blufor_airport2",_marker2pos];
_marker2 setMarkerShape "ICON";
_marker2 setMarkerColor "ColorWhite";
_marker2 setMarkerType "Airport";
_marker2 setMarkerDir 0;
_marker2 setMarkerSize [1, 1];
_marker2 setMarkerText "BLUFOR Airport";

OBJ_AIRPORT setSimpleTaskDestination _marker2pos;

sleep 10;

_title  = "<t color='#0000ff' size='1.2' shadow='1' shadowColor='#000000' align='center'>FALLUJAH AIRPORT</t><br/><br/>";
_text   = "Reinforcements on its way..";
hint parseText (_title + _text);

sleep 60 + (random 120);

"A10_US_EP1" createVehicle getMarkerPos "airport_support1a";
"A10_US_EP1" createVehicle getMarkerPos "airport_support1b";

"Stinger_Pod_US_EP1" createVehicle getMarkerPos "airport_support2a";
"TOW_TriPod_US_EP1" createVehicle getMarkerPos "airport_support2b";
"Stinger_Pod_US_EP1" createVehicle getMarkerPos "airport_support2c";
"TOW_TriPod_US_EP1" createVehicle getMarkerPos "airport_support2d";

"M1128_MGS_EP1" createVehicle getMarkerPos "airport_support3a";
"M1129_MC_EP1" createVehicle getMarkerPos "airport_support3b";

_title  = "<t color='#0000ff' size='1.2' shadow='1' shadowColor='#000000' align='center'>FALLUJAH AIRPORT</t><br/><br/>";
_text   = "Reinforcements have arrived";
hint parseText (_title + _text);

if (true) exitWith{};