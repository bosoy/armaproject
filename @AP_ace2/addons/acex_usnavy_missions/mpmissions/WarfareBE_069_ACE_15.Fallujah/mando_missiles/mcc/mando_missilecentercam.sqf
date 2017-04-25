/* mando missile control center camera.sqs
 mando_missilecentercam.sqf v2.3
 Jan 2007 Mandoble
 
 This script activates the camera of the launcher when no missile is being followed with mando_mccpredicam camera.
*/
MCC_MCC_FRAME = 21901;

private["_launcher", "_posrelcam", "_oldzoom", "_poscam", "_cam", "_camfollow", "_oldfollow", "_mando_camowner_old", "_mando_camowner"];



_launcher = _this select 0;
_posrelcam   = _this select 1;

_oldzoom = mando_missile_camera_zoom;
_poscam = _launcher modelToWorld _posrelcam;

[]spawn
{
   Sleep 1;
   4 cutText["", "BLACK IN"];
};

showCinemaborder false;

_cam = "camera" camcreate [0, 0, 0];
_cam cameraeffect ["internal", "back"];
//_cam camSetPos _poscam;
_cam camSetTarget (_launcher modelToWorld [0, 1500, 0.25]);
_cam camSetFov 1;
_cam camCommit 0;

_camfollow = false;
_mando_camfollow = objNull;
_oldfollow = objNull;
_cam attachTo [_launcher, _posrelcam];
_mando_camowner_old = objNull;
_mando_camowner = _launcher;

while {ctrlVisible MCC_MCC_FRAME} do
{
   if (mando_missile_camera && (!isNull mando_missile)) then
   {
      _mando_camowner = mando_missile;
   }
   else
   {
      _mando_camowner = _launcher;
   };

   if (_mando_camowner != _mando_camowner_old) then
   {
      if (_mando_camowner == _launcher) then
      {
         _cam cameraeffect ["terminate", "back"];
         camDestroy _cam;

_cam = "camera" camcreate [0, 0, 0];
_cam cameraeffect ["internal", "back"];
//_cam camSetPos _poscam;
_cam camSetTarget (_launcher modelToWorld [0, 1500, 0.25]);
_cam camSetFov 1;
_cam camCommit 0;

         _cam attachTo [_launcher, _posrelcam];
      }
      else
      {
         _cam attachTo [mando_missile, [0,15,0]];
      };
      _mando_camowner_old = _mando_camowner;
   };


   if (_mando_camowner == mando_missile) then
   {
      _cam camSetPos (mando_missile modelToWorld [0, 16, 0]);
      _cam camSetTarget (mando_missile modelToWorld [0, 1500, 0.25]);
      _cam camCommit 0;
      _oldfollow = objNull;
   }
   else
   {
      _mando_camfollow = _launcher getVariable "mando_camfollow";
      if (_oldfollow != _mando_camfollow) then 
      {
         if (!isNull _mando_camfollow) then 
         { 
            _cam camSetTarget _mando_camfollow;
         }
         else
         {
            _cam camSetTarget (_launcher modelToWorld [0, 1500, 0.25]);
         };
         _oldfollow = _mando_camfollow;
         _cam camCommit 0.25;
      };
   };

   _cam camPrepareFov (mando_missile_camera_zoom);
   _cam camCommitPrepared 0;

   sleep 0.01;
};

_cam cameraeffect ["terminate", "back"];
camDestroy _cam;