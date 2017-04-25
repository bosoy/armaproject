/* mando_laserok.sqf
By Mandoble Oct 2007

Validates a scripted laser
*/

private ["_unit", "_params", "_laser", "_side"];

_unit = _this select 0;
_params = (_this select 3);
_laser = _params select 0;
_side = _params select 1;

switch (_side) do
{
   case west:
   {
      mando_remote_w = _laser;
      publicVariable "mando_remote_w";
      titleText["Laser target transmitted", "PLAIN DOWN"];
   };
     
   case east:
   {
      mando_remote_e = _laser;
      publicVariable "mando_remote_e";
      titleText["Laser target transmitted", "PLAIN DOWN"];
   };

   case resistance:
   {
      mando_remote_r = _laser;
      publicVariable "mando_remote_r";
      titleText["Laser target transmitted", "PLAIN DOWN"];
   };

};
