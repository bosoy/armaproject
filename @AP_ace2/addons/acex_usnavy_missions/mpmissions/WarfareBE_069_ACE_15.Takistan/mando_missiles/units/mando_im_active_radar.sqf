/* mando_im_active_radar.sqf
By Mandoble Aug 2010

For non MMA systems, mark them as radar emitters by passing a class name array
*/

private ["_types"];
_types = _this select 0;

if (isServer) then
{
   while {true} do
   {
      {
         if ((typeOf _x) in _types) then
         {
            if (((count crew _x) > 0) && (alive _x)) then
            {
               mando_radar_on = _x;
               publicVariable "mando_radar_on";
               Sleep 0.5; 
            }
            else
            {
               mando_radar_off = _x;
               publicVariable "mando_radar_off";
               Sleep 0.5; 
            };
         };
         Sleep 0.05;
      } forEach vehicles;

      Sleep 2;
   };
};
