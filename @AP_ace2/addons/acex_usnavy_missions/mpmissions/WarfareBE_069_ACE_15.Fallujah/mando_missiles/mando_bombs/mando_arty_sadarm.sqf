/* Mando_arty_sadarm.sqf v1.0
   by Mandoble, March 2008

   Purpose:
      Provides SADARM capability to artillery and tank units. Players will have a display showing aiming data for SADARM bombardment. The player must pick the horizontal range to the target first (ground hit range), and then elevate the gun until SADARM activation range is close to the previously calculated ground hit range, and then fire a HEAT round.

   Arguments:
      Firing unit (usually a static gun).

   Note: This script requires the presence of mando_bombs_sadarm.sqf and mando_bombs_effects.sqf

   mando_sadarm_shell_types array contains the valid shell types for SADARM artillery shots, add more at will. 

   Example of init line of an arty gun:
   res=[this]execVM"mando_missiles\mando_bombs\mando_arty_sadarm.sqf";
*/

private ["_gun", "_log", "_vdir", "_posini", "_i"];
_gun = _this select 0;
if (!local _gun) exitWith {};
if (isNil "mando_arty_sadarm") then
{
   if (isNil "mando_sadarm_shell_types") then
   {
      mando_sadarm_shell_types = ["Sh_122_HE", "Sh_105_HE", "Sh_125_HE", "Sh_120_HE"];
   };

   mando_arty_sadarm = 
   {
      private ["_shell"];
      if ((_this select 4) in mando_sadarm_shell_types) then
      {
         _shell = nearestObject [(_this select 0), (_this select 4)];
         waitUntil {(isNull _shell) || ((getPos _shell select 2) > 150)};
         if (!isNull _shell) then
         {
            [objNull, getPos _shell]execVM"mando_missiles\mando_bombs\mando_bombs_sadarm.sqf";
            deleteVehicle _shell;
         };
      };
   };
};
_gun addEventHandler ["Fired", {_this spawn mando_arty_sadarm}];

_log = "logic" createVehicleLocal [0,0,0];
while {alive _gun} do
{
   if (player == gunner _gun) then
   {
      _posini = [getPosASL vehicle player select 0,getPosASL vehicle player select 1,(getPosASL vehicle player select 2)+1];
      _vdir = _gun weaponDirection (weapons vehicle player select 0); 

      for [{_i=0},{_i<1500},{_i=_i+10}] do
      {
         _pos = [(_posini select 0)+(_vdir select 0)*_i,(_posini select 1)+(_vdir select 1)*_i,(_posini select 2)+(_vdir select 2)*_i];
         _log setPosASL _pos;
         if ((getPos _log select 2) <= 0) then
         {
            hint format["Match ground hit range with SADARM activation range and fire.\nGround hit: %1m", floor(sqrt(((getPos _log select 0)-(getPos _gun select 0))^2+((getPos _log select 1)-(getPos _gun select 1))^2))];
            _i = 9999;
         }
         else
         {
            if ((getPos _log select 2) > 150) then
            {
               hint format["Match ground hit range with SADARM activation range and fire.\nSADARM activation range: %1m", floor(sqrt(((getPos _log select 0)-(getPos _gun select 0))^2+((getPos _log select 1)-(getPos _gun select 1))^2))];
               _i = 9999;
            };
         };
         Sleep 0.0001;
      }; 
      Sleep 0.1;
   }
   else
   { 
      Sleep 1;
   };
};
deleteVehicle _log;