/* mando_getlaser.sqf
By Mandoble June 2007


*/
private["_side", "_object"];

_side    = _this select 0;
_object  = _this select 1;

if (isNil "_object") exitWith {};

switch (_side) do
{
   case west:
   {
      mando_remote_w = _object;
      publicVariable "mando_remote_w";
   };

   case east:
   {
      mando_remote_e = _object;
      publicVariable "mando_remote_e";
   };

   case resistance:
   {
      mando_remote_r = _object;
      publicVariable "mando_remote_r";
   };

   case civilian:
   {
      mando_remote_c = _object;
      publicVariable "mando_remote_c";
   };
};