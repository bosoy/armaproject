while {true} do
{
   while {isNull mando_warning} do
   {
      Sleep 0.5;
   };

   if (mando_warning == vehicle player) then
   {
      titleRsc["mandoincoming", "PLAIN"];   
      playSound"mando_noammo1";
   };
   mando_warning = objNull;
};