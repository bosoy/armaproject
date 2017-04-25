/* 
 mando_gun.sqf v1.3
 Jan 2008 Mandoble 

_v = gun selectionposition "Usti hlavne"
*/

private ["_launcher", "_posini", "_firinggun", "_log", "_target", "_posm", "_speedmax", "_distance", "_barrellength", "_maxdisp", "_detonate", "_ammotype", "_wdir", "_dispersion_h", "_dispersion_v", "_offset_y", "_muzzlevel", "_vel", "_vel1", "_vel2", "_vel3","_mis", "_effects", "_mcoords", "_anghanim", "_animcode", "_post", "_rtarget", "_selection_name"];

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

if ((count _this) > 10) then
{
   _animcode = _this select 10;
}
else
{
   _animcode = {};
};

_offset_y = 2;

if (typeName _barrellength == "STRING") then
{
   _selection_name = _barrellength;
   _barrellength = 3;
}
else
{
   _selection_name = "";
};

if (typeName _target == "ARRAY") then
{
   _post = [_target select 0, _target select 1,_target select 2];
   _rtarget = _target select 3;
}
else
{
   _post = getPos _target;
   if (_target isKindOf "Man") then
   {
      _offset_y = 0.5;
   };
   _rtarget = _target;
};

_var = _launcher getVariable "mando_gun_extrah";
if (!isNil "_var") then
{
   _post set [2, (_post select 2) + _var];
};

_speedmax     = _muzzlevel;

_posini = _launcher modelToWorld _posini;


// _wdir = _launcher weaponDirection _firinggun;
_wdir = [0,0,0];
_ang = ((_post select 0)-(_posini select 0)) atan2 ((_post select 1)-(_posini select 1));
// _posini = [(_posini select 0)+sin(_ang)*_barrellength,(_posini select 1)+cos(_ang)*_barrellength,(_posini select 2)+(_wdir select 2)*_barrellength];

//_mis = _ammotype createVehicleLocal _posini;
_mis = "logic" createVehicleLocal _posini;
_mis setPos _posini;

_log = "logic" createVehicleLocal [0,0,0];
_posm = getPosASL _mis;

if (typeName _target != "ARRAY") then
{
   if (abs((_posm select 2) - (getPosASL _target select 2)) < (_target distance _mis)/2)then
   {

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
   }
   else
   {
      _post = getPos _target;
   };
};

_log setPosASL _post;
gunner _launcher doWatch getPos _log;
_altmasl = getPosASL _mis select 2;
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


_wcoords = [(_posini select 0)+sin(_ang)*cos(_angv)*_barrellength,
            (_posini select 1)+cos(_ang)*cos(_angv)*_barrellength,
            (_posini select 2)+sin(_angv)*_barrellength];
_mcoords = _launcher worldToModel _wcoords;

_anghanim = ((_mcoords select 0) - ((_this select 1) select 0)) atan2 ((_mcoords select 1) - ((_this select 1) select 1));
_angvanim = asin (((_mcoords select 2)-((_this select 1) select 2))/_barrellength);

//_launcher animate ["x_base", _anghanim/180];
//_launcher animate ["y_base", _angvanim/-180];
[_launcher, _anghanim, _angvanim] spawn _animcode;


deleteVehicle _mis;

_wcoords spawn 
{
   _exhaustlight = "#lightpoint" createVehicleLocal _this;
   _exhaustlight setLightColor [0.7,0.8,1];

   _exhaustlight setLightAmbient [0.7,0.8,1];
   _exhaustlight setLightBrightness 0.01;
   Sleep 0.1;
   deleteVehicle _exhaustlight;
};

_mis = _ammotype createVehicle _wcoords;
_mis setVectorUp[_ux, _uy, _uz];
_mis setVectorDir[sin(_ang), cos(_ang), sin(_angv)];
_mis setVelocity [_vx, _vy, _vz];


if (_effects) then 
{
   if (_selection_name != "") then
   {
      _wcoords = _launcher modelToWorld (_launcher selectionposition _selection_name);
   };


   mando_gun_shell = _mis;
   mando_gun_x = _wcoords select 0;
   mando_gun_y = _wcoords select 1;
   mando_gun_z = _wcoords select 2;
   mando_gun_vx = _vx;
   mando_gun_vy = _vy;
   mando_gun_vz = _vz;

   {publicVariable _x} forEach ["mando_gun_x","mando_gun_y","mando_gun_z","mando_gun_vx","mando_gun_vy","mando_gun_vz","mando_gun_shell"];

   _vel = [_vx, _vy, _vz];
   _vel1 = [-(_vel select 0)/100,-(_vel select 1)/100,-(_vel select 2)/100];
   _vel2 = [(_vel select 0)/10,(_vel select 1)/10,(_vel select 2)/10];
   _vel3 = [(_vel select 0)/40,(_vel select 1)/40,(_vel select 2)/40];
   drop["\Ca\Data\missileSmoke","","Billboard",100,5,_wcoords,_vel1,1,1.24,1,0.15,[0.5,2,6],[[1,1,1,0.3]],[1,0],1,0.1,"","",""];

//   drop["\ca\data\koulesvetlo","","Billboard",100,1,_wcoords,_vel2,1,1.245,1,0,[0.3,0.05],[[0,1,0,1]],[1,0],0,0,"","",""];

   drop["\Ca\Data\missileSmoke","","Billboard",0.05,0.5,_wcoords,_vel3,1,1.24,1,0.005,[0.3,0.05],[[1,1,1,0.4]],[1,0],0,0,"mando_missiles\mando_gun\tracer_smoke.sqs","",""];
};



_boom = false;
_dist_old = _mis distance _rtarget;
while {!isNull _mis} do
{
   _posm = getPos _mis;
   _mis setVectorUp[_ux, _uy, _uz];
   _mis setVectorDir[sin(_ang), cos(_ang), sin(_angv)];
   _mis setVelocity [_vx, _vy, _vz];
//   if (((_mis distance _post) < 50) && _detonate) then
   _dist = _mis distance _rtarget;
   if (((_dist > _dist_old) || (_dist < 10)) && _detonate) then
   {
      deleteVehicle _mis;
      _pos2 = [_posm select 0, _posm select 1, _posm select 2];
      _b2 = "RoadCone" createVehicle _pos2;
      _b2 setPos _pos2;
      _b1 = "B_30mm_HE" createVehicle (_b2 modelToworld [0,0,0]);

      sleep 0.1;
      deleteVehicle _b2;

      _boom = true;

      if (!(_rtarget isKindOf "Man")) then 
      {
         if (damage _rtarget == 0) then
         {
            _rtarget setDamage 0.11;
         };
      };
   };
   _dist_old = _mis distance _rtarget;
   Sleep 0.001;
};

/*
if (_boom) then
{
   _pos2 = [_posm select 0, _posm select 1, (_posm select 2)];
   _b2 = "RoadCone" createVehicle _pos2;
   _b2 setPos _pos2;
   _b1 = "B_30mmA10_AP" createVehicle (_b2 modelToworld [0,0,0]);

   sleep 0.1;
   deleteVehicle _b2;
};
*/
deleteVehicle _log;