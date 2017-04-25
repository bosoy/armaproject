/*mando MCC map mouse event handler
 mando_mccmouse.sqf v1.0
 March 2007 Mandoble
 
 
 
 Parameters:
 
*/

MCC_DLGMISSILECENTER	=21900;
MCC_MAP			=21902;

private ["_x", "_y", "_display", "_map", "_coords", "_driver"];

if ((_this select 1) == 0) then 
{
   _x = _this select 2;
   _y = _this select 3;
   _display = findDisplay MCC_DLGMISSILECENTER;
   _map     = _display displayCtrl MCC_MAP;

   _coords = _map ctrlMapScreenToWorld [_x,_y];
   if (mando_navmark == 0) then
   {
      _driver = driver vehicle player;

      _driver commandMove _coords;
   };
   mando_mccmark setPos _coords;
};

true