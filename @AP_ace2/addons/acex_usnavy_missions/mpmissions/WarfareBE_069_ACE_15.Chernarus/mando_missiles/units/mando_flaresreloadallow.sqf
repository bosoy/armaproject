/* mando_flaresreloadallow.sqf v1.1
  Jun 2007 Mandoble

  mando basic script to allow units to reload other mando missile equiped units.
  Execute this script in every machine with a player

  Arguments:
    Ammo vehicle types array
    Distance to activate load action

  Example: 
  [["Truck5tReammo", "UralReammo"], 12]execVM"mando_missiles\units\mando_missilereloadallow.sqf"

*/

private["_ammotypes", "_distload", "_var", "_continue", "_ammos", "_vehicle", "_unit", "_ammoleft", "_damage", "_actionidx"];

_ammotypes = _this select 0;
_distload  = _this select 1;


while {true} do
{
   Sleep 3;
   _continue = true;
   _var = (vehicle player) getVariable "mando_flaresleft";
   if (isNil "_var") then 
   {
      _continue = false;
   }
   else
   {
      if (((vehicle player) getVariable "mando_maxflares") == 0) then 
      {
         _continue = false;
      };
   };

   if (_continue) then
   {
      _ammos = nearestObjects [vehicle player, _ammotypes, _distload];
      if (count _ammos == 0) then 
      {
         _continue = false;
      }
      else
      {
         if (damage (_ammos select 0) > 0.1) then 
         {
            _continue = false;
         };
      };

      if (_continue) then
      {
         _vehicle = _ammos select 0;
         _damage = damage _vehicle;
         if (_damage > 0.1) then 
         {
            _ammoleft = 0;
         }
         else
         {
            _ammoleft = floor(100 - 100*_damage/0.1);
         };

         titleText[format["\n\n\n\n\nFlares/Chaff cargo: %1%2", _ammoleft, "%"], "PLAIN DOWN"];

         _actionidx = -1;
         _unit = vehicle player;

         if (_ammoleft > 0) then
         {
            _actionidx = _unit addAction ["Reload chaff/flares", mando_missile_path+"units\mando_flaresreload.sqf", [_vehicle]];
            while {(!isNull _vehicle) && ((vehicle player distance _vehicle) < _distload) && !(isNil "_var") && (damage _vehicle <= 0.1)} do
            {
               Sleep 2;
               _var = (vehicle player) getVariable "mando_flaresleft";
            };

            if (_actionidx != -1) then 
            {
               _unit removeAction _actionidx;
            };
         };
      };
   };
};