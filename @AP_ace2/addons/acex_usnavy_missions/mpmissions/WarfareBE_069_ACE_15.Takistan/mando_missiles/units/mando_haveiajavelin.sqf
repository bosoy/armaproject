/* mando_haveiajavelin.sqf
By Mandoble July 2008

Check if the player has a Javeling, and if so, gives him actions to select firing mode

Execute this script in every machine where there is a player

*/
private ["_player", "_ac", "_mode"];

_player = objNull;
mando_javelin_ac = -1;
while {true} do
{
   while {((currentWeapon vehicle player) != "Javelin") || (!alive player) || (cameraView != "GUNNER")} do
   {
      Sleep 2;
   };
   _mode = vehicle player getVariable "mando_javelin_mode";
   if (isNil "_mode") then
   {
      vehicle player setVariable ["mando_javelin_mode", 0];
   };
   _mode = vehicle player getVariable "mando_javelin_mode";
   if (_mode == 0) then
   {   
      mando_javelin_ac = vehicle player addAction ["Javelin: Hi->Direct", mando_missile_path+"units\mando_javelin_mode.sqf", 1];
   }
   else
   {   
      mando_javelin_ac = vehicle player addAction ["Javelin: Direct->Hi", mando_missile_path+"units\mando_javelin_mode.sqf", 0];
   };
   _player = vehicle player;
   while {((currentWeapon vehicle player) == "Javelin") && (alive player) && (_player == vehicle player) && (cameraView == "GUNNER")} do
   {
      Sleep 2;
   };
   _player removeAction mando_javelin_ac;
};