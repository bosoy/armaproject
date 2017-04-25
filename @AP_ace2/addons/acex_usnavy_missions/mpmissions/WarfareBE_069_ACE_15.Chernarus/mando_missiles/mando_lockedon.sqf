/*
mando_lockedon.sqf v1.0
April 2007 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/

while {true} do
{
   while {mando_lockedon != (vehicle player)} do
   {
      Sleep 0.2;
   };

   if ((getPos (vehicle player) select 2) > 10) then
   {
      playSound "mando_lockedon";
      titleRsc["mandolockedon", "PLAIN"];
   };

   mando_lockedon = objNull;
};
