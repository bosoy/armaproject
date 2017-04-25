/* 
 mando_com_camera.sqf

 Sep 2007 Mandoble
*/

private ["_commanded", "_cam", "_selected", "_commdisplay", "_mando_command_idx"];

_commanded = _this select 0;
_mando_command_idx = -1;

_selected = vehicle player;

showCinemaBorder false;
_cam = "camera" camcreate [0, 0, 0];
_cam cameraeffect ["internal", "back"];
_cam camSetPos (_selected modelToWorld [-40,-40,10]);
_cam camSetTarget (_selected modelToWorld [-28,20,27]);
_cam camSetFov 1;
_cam camCommit 0;


_commdisplay = findDisplay 23900;
while {!isNull _commdisplay} do
{
   if (_mando_command_idx != mando_command_idx) then
   {
      _mando_command_idx = mando_command_idx;
      _selected = (_commanded select _mando_command_idx) select 0;
   };

   _cam camSetPos (_selected modelToWorld [-40,-40,10]);
   _cam camSetTarget (_selected modelToWorld [-28,20,27]);
   _cam camCommit 0;
   Sleep 0.01;
};

_cam cameraeffect ["terminate", "back"];
camDestroy _cam;