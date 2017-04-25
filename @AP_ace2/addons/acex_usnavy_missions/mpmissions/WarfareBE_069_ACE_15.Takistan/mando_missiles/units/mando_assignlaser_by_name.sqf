/* mando_assignlaser_by_name.sqf.sqf
By Mandoble June 2007

Purpose:
   Waits until a player is in a vehicle which name is in the provided array, and then gives that vehicle a scripted laser designator.
This script must be executed in every machine where there is a player.

Arguments: 
   Array of vehicle types ["Su34", "Su34B", ...]
   Player's position inside the vehicle: 0 = driver, 1 = gunner
   Name of the vehicle's weapon used to enslave the laser
*/


private ["_plane", "_alaser", "_inplane", "_names", "_vehiclename", "_position", "_weapon", "_gunner", "_driver"];

_names         = _this select 0;
_position      = _this select 1;
_weapon        = _this select 2;

mando_laseraction = -1;
mando_laseraction2 = -1;


_plane = objNull;
_ttypes = [];
while {true} do
{
   waitUntil {!isNull player};

   _inplane = false;

   while {!_inplane} do
   {
      Sleep 1;
      if ((vehicle player) != player) then
      {
         _vehiclename = vehicleVarName (vehicle player);

         if (_vehiclename in _names) then
         {
            _driver = driver vehicle player;
            _gunner = gunner vehicle player;
            if (((_position == 0) && (_driver == player)) || ((_position == 1) && (_gunner == player))) then
            {
               _inplane = true;
               _plane = vehicle player;
            };
         };
      };
   };

   mando_laseraction = _plane addAction ["Laser ON", mando_missile_path+"units\mando_laser.sqf", [_weapon, true]];

   if (_position == 0) then
   {
      while {driver _plane == player} do
      {
         Sleep 1;
      };
   }
   else
   {
      while {gunner _plane == player} do
      {
         Sleep 1;
      };
   };

   _plane removeAction mando_laseraction;
   _plane removeAction mando_laseraction2;
   mando_laseraction = -1;
   mando_laseraction2 = -1;
   mando_laser_on = false;

   _inplane = false;

   Sleep 2;
};