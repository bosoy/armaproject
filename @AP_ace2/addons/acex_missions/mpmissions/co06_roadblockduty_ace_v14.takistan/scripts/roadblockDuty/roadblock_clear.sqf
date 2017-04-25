//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// This script clears the roadblock
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith{};

reezo_roadblockDuty_CLEAR = 1;
publicVariable "reezo_roadblockDuty_CLEAR";

sleep 3;

reezo_roadblockDuty_CLEAR = 0;
publicVariable "reezo_roadblockDuty_CLEAR";

if (true) exitWith{};