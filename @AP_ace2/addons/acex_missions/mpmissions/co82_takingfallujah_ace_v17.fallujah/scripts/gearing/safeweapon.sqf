//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo and Demonized
// Simple safe weapon on startup script
//////////////////////////////////////////////////////////////////

if (isDedicated) exitWith{};
if !(local player) exitWith{};

waitUntil {!(isNull player)};
waitUntil {player==player};

player action ["WEAPONONBACK", player];

if (true) exitWith{};