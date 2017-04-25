/* mando_rearm_by_type.sqf
By Mandoble Dec 2009

Purpose:
   Waits until a player is in a vehicle which type is in the provided array, and then gives an action to rearm vehicles/planes/choppers/ships

mando_rearm_sources_classes global array contains the valid set of classes to be used as rearming sources.

Arguments: 
   Min distance to any of these to allow rearming

Example:
   [30]execVM"mando_missiles\units\mando_rearm_by_type.sqf";
*/

private["_ammotypes", "_distload", "_var", "_ammos", "_vehicle", "_ammo", "_actionidx"];

_distload  = _this select 0;

while {true} do
{
   Sleep 3;

   if (alive player) then
   {
      if ((vehicle player != player) && ((player == driver vehicle player)  || (player == gunner vehicle player))) then
      {
         _vehicle = vehicle player;
         if (((speed _vehicle) < 1) && !isEngineOn _vehicle) then
         {

            _var = _Vehicle getVariable "mando_rearm_allow";

            if (!isNil "_var") then 
            {
               _ammos = nearestObjects [_vehicle, mando_rearm_sources_classes, _distload];

               if (count _ammos > 0) then 
               {
                  mando_rearm_sources = [];
                  mando_rearm_sources = mando_rearm_sources + _ammos;

                  mando_rearm_source = objNull;
                  _actionidx = _vehicle addAction ["<t color=""#ffffff"">MMA Rearm", mando_missile_path+"units\mando_rearm_dlg.sqf","",200];


                  while {(alive player) && ((driver _vehicle == player) || (gunner _vehicle == player)) && (!isEngineOn _vehicle) && (speed _vehicle < 1)} do
                  {

                     mando_rearm_sources = nearestObjects [_vehicle, mando_rearm_sources_classes, _distload];

                     Sleep 1;
                  };
                  _vehicle removeAction _actionidx;
               };
            };
         };
      };
   };
};