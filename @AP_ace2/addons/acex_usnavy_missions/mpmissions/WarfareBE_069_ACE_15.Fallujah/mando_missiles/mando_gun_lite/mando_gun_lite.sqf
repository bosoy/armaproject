/* 
 mando_gun_lite.sqf v1.0 BETA
 October 2008 Mandoble 
*/

private ["_launcher", "_posini", "_firinggun", "_log", "_target", "_posm", "_speedmax", "_distance", "_barrellength", "_maxdisp", "_detonate", "_ammotype", "_wdir", "_dispersion_h", "_dispersion_v", "_offset_y", "_muzzlevel", "_vel", "_vel1", "_vel2", "_vel3","_mis", "_effects"];

_launcher     = _this select 0;
_posini       = _this select 1;
_firinggun    = _this select 2;
_barrellength = _this select 3;
_target       = _this select 4;
_maxdisp      = _this select 5;
_detonate     = _this select 6;
_ammotype     = _this select 7;
_muzzlevel    = _this select 8;
_effects      = _this select 9;

_speedmax     = _muzzlevel;

_posini = _launcher modelToWorld _posini;
_post = getPos _target;

if (_firinggun != "") then
{
   _wdir = _launcher weaponDirection _firinggun;
   _ang = ((_post select 0)-(_posini select 0)) atan2 ((_post select 1)-(_posini select 1));
   _posini = [(_posini select 0)+sin(_ang)*_barrellength,(_posini select 1)+cos(_ang)*_barrellength,(_posini select 2)+(_wdir select 2)*_barrellength];
};

//_mis = _ammotype createVehicle _posini;
_mis = _ammotype createVehicleLocal _posini;
_offset_y = 0;
if (_target isKindOf "Man") then
{
   _offset_y = 0.5;
};

_log = "logic" createVehicleLocal [0,0,0];
_posm = getPosASL _mis;


_ang = ((_posm select 0)-(getPos _target select 0)) atan2 ((_posm select 1)-(getPos _target select 1));
if (_ang < 0) then {_ang = 360 + _ang;};

_vt = (speed _target) / 3.6;
_vr = _speedmax;

_dirt = getDir _target;
_dif = abs(_ang - _dirt);
if (_dif > 180) then {_dif = 360 - _dif;};


_dir1 = _dirt + 2;
if (_dir1 > 360) then {_dir1 = _dir1 - 360;};
_dif1 = abs(_ang - _dir1);
if (_dif1 > 180) then {_dif1 = 360 - _dif1;};


_dir2 = _dirt - 2;
if (_dir2 < 0) then {_dir2 = 360 - _dir2;};
_dif2 = abs(_ang - _dir2);
if (_dif2 > 180) then {_dif2 = 360 - _dif2;};


_sig = 1;
if (_dif2 < _dif1) then {_sig = -1;};
_angi1 = asin((_vt/_vr)*sin(_dif));
_angi = (_ang + 180) + _sig*_angi1;

_tti = (_mis distance _target) / ((_vt*cos(_dif)+_vr*cos(_angi1))+0.0001);
_tti2 = _tti;
_post = [(_posm select 0)+sin(_angi)*(_speedmax*_tti2),(_posm select 1)+cos(_angi)*(_speedmax*_tti2), (getPosASL _target select 2)+(velocity _target select 2)*_tti2 + _offset_y];

_altmasl = getPosASL _mis select 2;
if ((abs(((getPosASL _target select 2)-_altmasl)/(_target distance _mis)) > 0.5) || (_vt < 0.5))then
{
   _post = getPosASL _target;
};

_log setPosASL _post;
_alttasl = getPosASL _log select 2;

_distance = _log distance _mis;
_angv = asin((_alttasl - _altmasl)/_distance);
_ang = ((_post select 0)-(_posm select 0)) atan2 ((_post select 1)-(_posm select 1));


 

_dispersion_h = (_maxdisp select 0) * 400 / _distance;
_dispersion_v = (_maxdisp select 1) * 400 / _distance;
_ang = _ang + (random _dispersion_h) - _dispersion_h/2;
_angv = _angv + (random _dispersion_v) - _dispersion_v/2;

//hint format["A:%1, AV:%2, AT:%3, AM:%4\n%5", _ang, _angv, _alttasl, _altmasl, _post];


_vz = (sin _angv)*_speedmax;
_vh = (cos _angv)*_speedmax;
_vx = (sin _ang)*_vh;
_vy = (cos _ang)*_vh;

_uz = sin(_angv+90);
_ur = cos(_angv+90);
_ux = sin(_ang)*_ur;
_uy = cos(_ang)*_ur;


deleteVehicle _mis;
_mis = _ammotype createVehicle [(_posini select 0)+sin(_ang)*_barrellength,(_posini select 1)+cos(_ang)*_barrellength,(_posini select 2)+sin(_angv)*_barrellength];

_mis setVectorUp[_ux, _uy, _uz];
_mis setVectorDir[sin(_ang), cos(_ang), sin(_angv)];
_mis setVelocity [_vx, _vy, _vz];

//_boom = true;
while {!isNull _mis} do
{
   _mis setVectorUp[_ux, _uy, _uz];
   _mis setVectorDir[sin(_ang), cos(_ang), sin(_angv)];
   _mis setVelocity [_vx, _vy, _vz];
   _posm = getPos _mis;
   Sleep 0.001;
};
deleteVehicle _log;