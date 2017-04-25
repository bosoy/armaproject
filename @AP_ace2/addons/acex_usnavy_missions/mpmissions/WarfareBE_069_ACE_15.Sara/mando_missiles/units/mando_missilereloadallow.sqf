/*
mando_missilereloadallow.sqf v1.1
 Jun 2007 Mandoble
 
Script to allow units to reload other mando missile equiped units, execute this script on every machine where there is a player.

 Arguments:
    Ammo vehicle types array
    Distance to activate load action

 Example: 
 [["Truck5tReammo", "UralReammo"], 12]execVM"mando_missiles\units\mando_missilereloadallow.sqf"
*/

private["_ammotypes", "_distload", "_missiles", "_vechile", "_unit", "_actionidx", "_i", "_ammos", "_damage", "_ammoleft", "_var"];

_ammotypes = _this select 0;
_distload  = _this select 1;

_missiles  = false;
_vechile   = objNull;
_unit      = objNull;
_actionidx = -1;
_i         = 0;
_ammos     = [];
_damage    = 0;
_ammoleft  = 0;

while {true} do
{
   _missiles = false;
   _vehicle    = objNull;

   while {!_missiles || (isNull _vehicle)} do
   {
      _missiles = false;
      _vehicle    = objNull;

      for [{_i = 0},{_i < 8},{_i = _i + 1}] do
      {
         _var = (vehicle player) getVariable format["mando_maxmissiles%1", _i];
         if (!isNil "_var") then
         {
            if (_var > 0) then
            {
               _missiles = true;
            };
         };
      };

      if (_missiles) then
      {
         _ammos = nearestObjects [vehicle player, _ammotypes, _distload];
 
         if (count _ammos > 0) then
         {
            for [{_i = 0},{_i < count _ammos},{_i = _i + 1}] do
            {            
               if (damage (_ammos select _i) < 0.1) then 
               {
                  _vehicle = _ammos select _i;
               };
            };
         };
      };

      if (!_missiles || (isNull _vehicle)) then
      {
         Sleep 3;
      };
   };

   _damage = damage _vehicle;
   _ammoleft = floor(100 - 100*_damage/0.1);
   titleText[format["\n\n\n\n\nMissile cargo: %1%2", _ammoleft, "%"], "PLAIN DOWN"];

   _actionidx = -1;
   _unit = vehicle player;
   if (_ammoleft > 0) then
   {
      _actionidx =  _unit addAction ["Reload missiles", mando_missile_path+"units\mando_missilereload.sqf", [_vehicle]];
   };


   while {(!isNull _vehicle) && ((_unit distance _vehicle) < _distload) && (damage _vehicle < 0.1) && (_unit == vehicle player)} do
   {
      Sleep 2;
   };

   if (_actionidx != -1) then
   {
      _unit removeAction _actionidx;
   };
};
