//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo and Demonized
// This script makes sure the player lowers his weapon at the beginning of the mission
// and when pointing his weapon to allied units.
// You stupid noobs will now stop pointing your freaking gun at everyone's face
//////////////////////////////////////////////////////////////////

if (isDedicated) exitWith{};
if !(local player) exitWith{};

waitUntil {!(isNull player)};
waitUntil {player==player};

player action ["WEAPONONBACK", player];

while {alive player} do {
  if (side cursorTarget == side player AND (cursorTarget distance player) < 50) then {
    _aimAt = cursorTarget;
    _cntTime = 0;
    while {cursorTarget == _aimAt} do {
      sleep 1;
      _cntTime = _cntTime +1;
    };
   if (_cntTime >= 5) then {
      player action ["WEAPONONBACK", player];
      if (cameraView == "Gunner") then { player switchCamera "Internal" };
    } else {
      sleep 5;
    };
  };  
};

if (true) exitWith{};