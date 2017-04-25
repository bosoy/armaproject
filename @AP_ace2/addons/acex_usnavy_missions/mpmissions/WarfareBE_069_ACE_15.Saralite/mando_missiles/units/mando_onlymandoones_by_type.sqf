/* mando_onlymandoones_by_type.sqf
By Mandoble Sep 2009

Replaces ArmA stock missiles fired to this unit by mando missiles
This script must be executed only in the server.

*/

private ["_types", "_var", "_some"];
_types = _this select 0;
while {true} do
{
   _some = false;
   {
      if (((typeOf _x) in _types) || (count _types == 0)) then
      {
         _var = _x getVariable "mando_replaced";
         if (isNil "_var") then
         {
            _x setVariable ["mando_replaced", true];
            _x SetVehicleInit "res = [This] execVM mando_missile_path+""units\mando_onlymandoones.sqf""";
            _some = true;
         };
      };
   } forEach vehicles;

   if (_some) then
   {
      processInitCommands;
   };
   Sleep 5;
};
