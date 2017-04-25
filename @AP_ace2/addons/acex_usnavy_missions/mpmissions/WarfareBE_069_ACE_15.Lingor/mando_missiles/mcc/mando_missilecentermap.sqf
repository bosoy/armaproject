disableSerialization;

MCC_DLGMISSILECENTER	= 21900;
MCC_MCC_FRAME           = 21901;
MCC_MAP                 = 21902;

private["_launcher", "_posrelcam","_tofollow", "_mando_contact", "_display","_map", "_pos2d","_mando_target","_mkoff","_mkon", "_tofollowm", "_tofollowmap"];

_launcher  = _this select 0;
_posrelcam = _this select 1;
_tofollow  = objNull;
_mando_contact = objNull;

_display = findDisplay MCC_DLGMISSILECENTER;
_display displaySetEventHandler ["KeyDown", "_res = _this execVM mando_missile_path + ""mcc\mando_mcckeys.sqf"""];
_map     = _display displayCtrl MCC_MAP;


_pos2d = [getPos _launcher select 0, getPos _launcher select 1];

createMarkerLocal ["mk_launcher", _pos2d];
"mk_launcher" setMarkerColorLocal "ColorGreen";
"mk_launcher" setMarkerSizeLocal [0.5, 0.5];
"mk_launcher" setMarkerTypeLocal "Flag";

createMarkerLocal ["mk_mccmark", _pos2d];
"mk_mccmark" setMarkerColorLocal "ColorYellow";
"mk_mccmark" setMarkerSizeLocal [0.5, 0.5];
"mk_mccmark" setMarkerTypeLocal "Destroy";


createMarkerLocal ["mk_contact", [0,0]];
createMarkerLocal ["mk_target", [0,0]];
createMarkerLocal ["mk_ipoint", [0,0]];
"mk_contact" setMarkerColorLocal "ColorGreen";
"mk_contact" setMarkerSizeLocal [0.5, 0.5];
"mk_target" setMarkerColorLocal "ColorGreen";
"mk_target" setMarkerSizeLocal [0.5, 0.5];
"mk_ipoint" setMarkerColorLocal "ColorGreen";
"mk_ipoint" setMarkerSizeLocal [0.25, 0.25];

[_launcher, _posrelcam]execVM mando_missile_path+"mcc\mando_missilecentercam.sqf";


while {ctrlVisible MCC_MCC_FRAME} do
{
   _mando_contact = _launcher getVariable "mando_contact";
   _mando_target = _launcher getVariable "mando_target";

   _pos2d = [getPos _launcher select 0, getPos _launcher select 1];
   "mk_launcher" setMarkerPosLocal _pos2d;

   _pos2d = [getPos mando_mccmark select 0, getPos mando_mccmark select 1];
   "mk_mccmark" setMarkerPosLocal _pos2d;

   _tofollow = _mando_contact;
   _tofollowmap = _mando_contact;
   if ((mando_map == 0) || (mando_map == 3)) then
   {
      if (mando_map == 3) then
      {
         _tofollowmap = _launcher;
      }
      else
      {
         _tofollowmap = objNull;
      };  

      if (!isNull _mando_target) then
      {
         _tofollow = _mando_target;
      }
      else
      {
         if (!isNull _mando_contact) then
         {
            _tofollow = _mando_contact;
         };
      };
   }
   else
   {
      if ((mando_map == 2) && (!isNull _mando_target)) then
      {
         _tofollow = _mando_target;
         _tofollowmap = _mando_target;
         _tofollowm = "mk_target";
         _mkoff=["mk_contact"];
         _mkon=["mk_target","mk_ipoint"];
      }
      else
      {
         if ((mando_map == 1)&&(!isNull _mando_contact)) then 
         {
            _tofollow = _mando_contact;
            _tofollowmap = _mando_contact;
            _tofollowm = "mk_contact";
            _mkon=["mk_contact"];
            _mkoff=["mk_target","mk_ipoint"];
         };
      };
   };

   _launcher setVariable ["mando_camfollow", _tofollow];

   if (isNull _tofollow) then 
   {
      "mk_target" setMarkerTypeLocal "Empty";
      "mk_contact" setMarkerTypeLocal "Empty";
      "mk_ipoint" setMarkerTypeLocal "Empty";
   }
   else
   {
      {_x setMarkerTypeLocal "Dot"} forEach _mkon;

      "mk_target" setMarkerTypeLocal "Arrow";
      "mk_target" setMarkerDirLocal getDir _tofollow;

      {_x setMarkerTypeLocal "Empty"} forEach _mkoff;
      _tofollowm setMarkerPosLocal getPos _tofollow;
   };

   if ((mando_map != 0)&&(!isNull _tofollowmap)) then
   {
      _map ctrlMapAnimAdd [1, 1, getPos _tofollowmap];
      ctrlMapAnimCommit _map;
   };

   Sleep 1;
};

_display displaySetEventHandler ["KeyDown", ""];
deleteMarkerLocal "mk_contact";
deleteMarkerLocal "mk_target";
deleteMarkerLocal "mk_ipoint";
deleteMarkerLocal "mk_launcher";
deleteMarkerLocal "mk_mccmark";