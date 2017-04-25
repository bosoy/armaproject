/*mando MCC key event handler
 mando_mcckeys.sqf v1.0
 March 2007 Mandoble
*/
disableSerialization;

MCC_HELP                = 21944;


_key = _this select 1;
_delta = 0.02;

if ((_key == 78) || (_key == 74) || (_key == 55)) then
{
   if ((_key == 74) && ((mando_missile_camera_zoom + _delta) <= 1.0)) then {mando_missile_camera_zoom = mando_missile_camera_zoom + _delta;};
   if ((_key == 78) && ((mando_missile_camera_zoom - _delta) > 0.02)) then {mando_missile_camera_zoom = mando_missile_camera_zoom - _delta;};
   if (_key == 55) then {mando_missile_camera_zoom = 1.0;};

   cutText[format["Zoom level: %1%2", (1.0-(mando_missile_camera_zoom-_delta))*100.0,"%"], "PLAIN DOWN"];
};

// F1 HELP
if (_key == 59) then
{
   _mccdisplay = findDisplay MCC_DLGMISSILECENTER;
   _mcchelp = _mccdisplay displayCtrl MCC_HELP;
   if (ctrlVisible MCC_HELP) then
   {
      _mcchelp ctrlShow false;
   }
   else
   {
      _mcchelp ctrlShow true;
      _mcchelp htmlLoad "mando_missiles\mcc\mcc_help.html";
   };
};