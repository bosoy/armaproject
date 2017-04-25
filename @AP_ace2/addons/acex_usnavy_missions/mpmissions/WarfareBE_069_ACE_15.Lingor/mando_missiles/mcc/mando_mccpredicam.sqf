/*
Parameters:
   Object to follow
   Horizontal camera distance to object 
   Angle from where the camera tracks the object (0 = same dir as object, 90 right, 180 back, 270 left)
   Vertical camera distance to object
   Maximum time to keep the camera ON in seconds
   Return to previous camera true/false
*/

private["_unit", "_rangex", "_ang", "_rangey", "_maxtime", "_return", "_ground", "_delay", "_posu", "_angf", "_pos", "_cam", "_timecur", "_asl1", "_vel", "_asl2", "_angf", "_posc", "_als3", "_alt"];

_unit    = _this select 0;
_rangex  = _this select 1;
_ang     = _this select 2;
_rangey  = _this select 3;
_maxtime = _this select 4;
_return  = _this select 5;


_ground = "logic" createVehicleLocal [0,0,0];
_delay = 0.05;
_posu = getPos _unit;
showCinemaBorder false;
_angf = (getDir _unit) + _ang;
_pos = [(_posu select 0) + sin(_angf)*_rangex, (_posu select 1) + cos(_angf)*_rangex, (_posu select 2) + _rangey];


_cam = "camera" camcreate [0, 0, 0];
_cam cameraeffect ["internal", "back"];

_cam camSetPos _pos;
_cam camSetTarget _unit;
_cam camSetFov 1.0;
_cam camCommit 0;


mando_mccpredicam = true;
_timecur = 0.0;


while {(_timecur < _maxtime) && mando_mccpredicam && (!isNull _unit)} do
{
   _posu = getPos _unit;

   _asl1 = getPosASL _unit select 2;
   _vel = velocity _unit;
   _asl2 = _asl1+(_vel select 2)*_delay + _rangey;
   _angf = (getDir _unit)+_ang;
   _posc = [(_posu select 0)+(_vel select 0)*_delay+sin(_angf)*_rangex, (_posu select 1)+(_vel select 1)*_delay+cos(_angf)*_rangex,_asl2];
   _ground setPos [_posc select 0, _posc select 1, 0];
   _asl3 = getPosASL _ground select 2;
   _alt = _asl2 - _asl3;
   _posc = [_posc select 0, _posc select 1, _alt];
   _cam camSetPos _posc;
   _cam camCommit (_delay+0.5);
   Sleep _delay;
   _timecur = _timecur + _delay;
};

Sleep 2;


if (_return) then
{
   _cam cameraeffect ["terminate", "back"];
};

camDestroy _cam;
deleteVehicle _ground;
Sleep 2;
mando_mccpredicam = false;