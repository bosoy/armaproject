/* mando_haveialaser.sqf
By Mandoble June 2007

Check if the player has a laser, and if so, gives him actions to transmit current target to any 
friendly unit able to engange "REMOTE" targets.

Execute this script in every machine where there is a player

*/
private ["_player", "_ac"];

_player = objNull;
while {true} do
{
   while { !((currentWeapon vehicle player) in mando_lasers) || (!alive player) } do
   {
      Sleep 2;
   };
   _ac = vehicle player addAction ["<t color=""#ffffff"">MMA Transmit target", mando_missile_path+"units\mando_getlaser.sqf","",94];
   _player = vehicle player;


   while {((currentWeapon vehicle player) in mando_lasers) && (alive player) && (_player == vehicle player)} do
   {
      Sleep 2;
   };
   _player removeAction _ac;
};

