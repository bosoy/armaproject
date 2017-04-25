/*********************************************************************************
   mando_giveme_mapfallout.sqf v1.0

   Provides fallout mao to the player and player's vehicle.

   Parameters:
      Action text: text to be displayed in the action.  
      Condition extra: By default, the script check alive state of player + this condition.
                       This condition is code, for example {rank player == "CORPORAL"}, set this 
                       condition as if it were the body of an if then block. Use this to set any 
                       conditions you want to check to provide console. 

   Examples:

   // fallout console provided if player is corporal
   ["Fallout Map", {rank player == "CORPORAL"}]execVM"mando_missiles\warheads\echo\mando_giveme_mapfallout.sqf";

   // fallout console provided if player is driver inside an HMMWV
   ["Fallout Map", {(typeOf vehicle player == "HMMWV") && (player == driver vehicle player)}]execVM"mando_missiles\warheads\echo\mando_giveme_mapfallout.sqf";
*/

private["_acidx1", "_veh", "_condition_extra", "_text"];
_text = _this select 0;
_condition_extra = _this select 1;

_acidx1 = -1;

while {true} do
{
   while {!alive player || !call (_condition_extra)} do
   {
      Sleep 1;      
   };

   _veh = vehicle player;
   _acidx1 = _veh addAction ["<t color=""#ffffff"">"+_text, "mando_missiles\warheads\echo\mando_mapfallout_dlg.sqf", "",-100,false, true];

   while {(vehicle player == _veh) && call (_condition_extra)} do
   {
      Sleep 1;
   };
   _veh removeAction _acidx1;
}; 