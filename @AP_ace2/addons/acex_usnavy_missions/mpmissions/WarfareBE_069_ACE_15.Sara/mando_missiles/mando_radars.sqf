/*
mando_radars.sqf v1.0
July 2007 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/
private["_old_radar_off", "_old_radar_on"];

mando_radar_on   = objNull;
mando_radar_off  = objNull;
mando_radars     = [];

_old_radar_off   = objNull;
_old_radar_on    = objNull;

while {true} do
{
   waitUntil {!(isNull mando_radar_on) || !(isNull mando_radar_off)};

   if (!isNull mando_radar_off) then
   {
      mando_radars = mando_radars - [mando_radar_off];
      mando_radar_off = objNull;
   };

   if (!isNull mando_radar_on) then
   {
      if (!(mando_radar_on in mando_radars)) then
      {
         mando_radars = mando_radars + [mando_radar_on];
      };
      mando_radar_on = objNull;
   };

//   titleText[format["Radars: %1", mando_radars], "PLAIN DOWN"];
};
