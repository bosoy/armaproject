//return angle of 2D vector (0-360), with 0 at 12 o'clock
private ["_v","_dir"];
_v = _this select 0;
_dir = (_v select 0) atan2 (_v select 1);
if (_dir < 0) then {_dir = _dir + 360};
//_dir = _dir + 360;
//player sidechat format ["%1",_dir];
_dir
