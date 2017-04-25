// mando missile smoke trail for ASROC (requires Mu90 torpedo addon)
// mando_missilesmoke_asroc.sqf v1.0
// Oct 2007 Mandoble
//
// General smoke trail script for mando missiles
// This script may be used as smoke trail argument for mando_missile.sqf
//
// Sea and ground water/dust trails too if flying below 40 and missile is not diving.
//
private ["_mis", "_altagl", "_altasl", "_pos", "_vec1", "_vec2", "_dir", "_vdir", "_water", "_trail", "_vol", "_wei", "_smoketrail1", "_smoketrail2", "_watertrail1", "_watertrail2", "_dusttrail", "_exhaustlight", "_i", "_lastdir", "_lastvel", "_lastup", "_posmis", "_mislocal", "_lastpos", "_torp"];

_mis = _this select 0;

_mislocal = local _mis;

_altagl = 0.0;
_altasl = 0.0;
_pos  = [0,0,0];
_vec1 = [0.0,0.0];
_vec2 = [0.0,0.0];
_dir  = 0;

_water = "\ca\data\cl_water";
_dust  = ["\Ca\Data\ParticleEffects\Universal\Universal", 16, 12, 8];
//_trail = "\ca\data\cl_basic";


//_water = "\Ca\Data\ParticleEffects\watereffects\watereffects";
_trail = "\ca\data\missileSmoke";


_vol = 1.0;
_wei = 1.27;

_smoketrail1 = "#particlesource" createVehicleLocal getPos _mis;
_smoketrail1 setParticleParams ["\ca\data\koulesvetlo","","Billboard",100,0.2,[0,0,0],[0,0,0],0,_wei,_vol,0.05,[1,2,1.5,0.5],[[1,0.5,0,0.6],[1,1,1,0.5],[1,1,1,0.1]],[0],0,0,"","",_mis];
//_smoketrail setParticleRandom [0.05,[0.0,0.0,0.0],[0.0,0.0,0.0],0,0.5,[1,1,1,0],0,0];
_smoketrail1 setDropInterval 0.005;


_smoketrail2 = "#particlesource" createVehicleLocal getPos _mis;
_smoketrail2 setParticleParams [_trail,"","Billboard",100,0.5,[0,0,0],[0,0,0],0,_wei,_vol,0.05,[1,2.5,3,3.5],[[0.5,0.5,0.5,1],[0.7,0.7,0.7,0.5],[0.8,0.8,0.8,0]],[0],0,0,"","",_mis];
_smoketrail2 setDropInterval 0.01;


_watertrail1 = "#particlesource" createVehicleLocal [0,0,0];
_watertrail1 setParticleParams [_water,"","Billboard",100,4,[0,0,0],[0,0,0],2,25.50,20,1,[4,6,8,10],[[1,1,1,1],[0.9,1,1,0.5],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
_watertrail1 setDropInterval 0;

_watertrail2 = "#particlesource" createVehicleLocal [0,0,0];
_watertrail2 setParticleParams [_water,"","Billboard",100,4,[0,0,0],[0,0,0],2,25.50,20,1,[4,6,8,10],[[1,1,1,1],[0.9,1,1,0.5],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
_watertrail2 setDropInterval 0;

_dusttrail = "#particlesource" createVehicleLocal [0,0,0];
_dusttrail setParticleParams [_dust,"","Billboard",100,3,[0,0,0],[0,0,0],2,25.50,20,1,[3,5,7,9],[[0.33,0.34,0.17,0.2],[0.33,0.34,0.17,0.1],[0.33,0.34,0.17,0]],[0,1],0,0,"","",""];
_dusttrail setDropInterval 0;

_exhaustlight = "#lightpoint" createVehicleLocal [0,0,0];
_exhaustlight setLightColor [0.7,0.8,1];

_exhaustlight setLightAmbient [0.7,0.8,1];
_exhaustlight setLightBrightness 0.2;
_exhaustlight LightAttachObject [_mis,[0,-1,0]];

asroc_target = objNull;
_i = 0.0;
while {(!isNull _mis)&&(damage _mis < 0.05)} do
{
   _posmis = getPos _mis;
   _i = _i + 0.05;

   if (_i < 2) then
   {
      drop[_trail,"","Billboard",100,2,[0,0,0],[0,0,0],0,_wei,_vol,0.05,[2,3,4,5.5],[[0.5,0.5,0.5,0.8],[0.7,0.7,0.7,0.6],[0.8,0.8,0.8,0]],[0],0,0,"","",_mis];
   };

   _smoketrail1 setPos _posmis;
   _smoketrail2 setPos _posmis;

   _altagl = _posmis select 2;
   if ((_altagl < 40)&&((velocity _mis select 2)>-14)) then 
   {
      _dir = getDir _mis;
      _vdir = vectorDir _mis;
      _pos = [(_posmis select 0)+_altagl*1.2*(-(_vdir select 0)),(_posmis select 1)+_altagl*1.2*(-(_vdir select 1)),0];

      if (surfaceIsWater _pos) then
      {
         _dusttrail setDropInterval 0;
         _vec1 = [sin(_dir+120)*4,cos(_dir+120)*4,0];
         _vec2 = [sin(_dir+240)*4,cos(_dir+240)*4,0];

         _watertrail1 setPos _pos;
         _watertrail1 setParticleParams[_water,"","Billboard",100,4,[0,-4,0],_vec1,2,25.50,20,1,[0.1,.4,1,1.5],[[1,1,1,1],[0.9,1,1,0.5],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
         _watertrail1 setDropInterval 0.01;

         _watertrail2 setPos _pos;
         _watertrail2 setParticleParams[_water,"","Billboard",100,4,[0,-4,0],_vec2,2,25.50,20,1,[0.1,.4,1,1.5],[[1,1,1,1],[0.9,1,1,0.3],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
         _watertrail2 setDropInterval 0.01;
      }
      else
      {
         _watertrail1 setDropInterval 0;
         _watertrail2 setDropInterval 0;
         _vec1 = [-(_vdir select 0)*4,-(_vdir select 1)*4,0];

         _dusttrail setPos _pos;
         _dusttrail setParticleParams[_dust,"","Billboard",100,3,[0,0,0],_vec1,2,25.50,20,1,[3,5,7,9],[[0.33,0.34,0.17,0.2],[0.33,0.32,0.17,0.1],[0.33,0.32,0.17,0]],[0,1],0,0,"","",""];
         _dusttrail setDropInterval 0.005;
      };
   }
   else
   {
         _dusttrail setDropInterval 0;
         _watertrail1 setDropInterval 0;
         _watertrail2 setDropInterval 0;
   };

   if (_mislocal) then
   {
      if (!isNull _mis) then
      {
         _lastdir = vectorDir _mis;
         _lastvel = velocity _mis;
         _lastup  = vectorUp _mis;
         _lastpos = _posmis;
      };
   };

   sleep 0.05;
};
deleteVehicle _smoketrail1;
deleteVehicle _smoketrail2;
deleteVehicle _watertrail1;
deleteVehicle _watertrail2;
deleteVehicle _dusttrail;
deleteVehicle _exhaustlight;

// The initial missile has been deleted (it reached its detonation point)
// Time to create a fake torpedo descending in chute
if (_mislocal) then
{
   waitUntil {!isNull asroc_target};
   _target           = asroc_target;
   asroc_target = objNull;

   _torp = "mu90" createVehicle _lastpos;
   _torp setPos _lastpos;

   _torp setVectorDir _lastdir;
   _torp setVectorUp _lastup;
   _torp setVelocity _lastvel;

   asroc_torp = _torp;

   waitUntil {(getPos _torp select 2) < 130};
   _laspos = getPos _torp;
   _lastdir = vectorDir _torp;
   _lastvel = velocity _torp;
   _lastup  = vectorUp _torp;
   _torp setVelocity [0,0,0];

   _torpchute = "ParachuteWest" createVehicle getPos _torp;
   _torpchute setPos getPos _torp;
   _torpchute setVectorDir _lastdir;
   _torpchute setVectorUp _lastup;
   _torpchute setVelocity _lastvel;



   while {(getPos _torp select 2) > 0} do
   {
      _torp setPos (_torpchute modelToWorld [0,0,-1]);
      _torp SetVectorUp (vectorUp _torpchute);
      sleep 0.01;
   };

   Sleep 2;

   _launcher         = objNull;
   _missilebody      = "mu90";
   _vangle           = -1.5;
   _speedini         = 0;
   _speedmax         = 26;
   _acceleration     = 8;
   _boomrange        = 10;
   _activerange      = 6000;
   _modeinit         = 2;
   _cruisealt        = 80;
   _boomscript       = mando_missile_path+"warheads\mando_missileheadtorp.sqf";
   _smokescript      = mando_missile_path+"exhausts\mando_torpedowater2a.sqf";
   _soundrsc         = "";
   _sounddur         = 29;
   _endurance        = 40;
   _terrainavoidance = false;
   _updatefreq       = 1;
   _delayinit        = 2;
   _controltime      = 0;
   _detectable       = false;


   _debug            = false;


   _launchscript     = "";
   _hagility         = 35;
   _vagility         = 10;
   _accuracy         = 1;
   _intercept        = false;
   _scanarch         = 180;
   _scanarcv         = 65;
   _offsety          = -3;

   [_launcher, _missilebody, [getPos _torp select 0, getPos _torp select 1, getPos _torp select 2], getDir _torp, _vangle, _speedini, _speedmax, _acceleration, _target, _boomrange, _activerange, _modeinit, _cruisealt, _boomscript, _smokescript, _soundrsc, _sounddur, _endurance, _terrainavoidance, _updatefreq, _delayinit, _controltime, _detectable, _debug, _launchscript,_hagility, _vagility, _accuracy, _intercept, _scanarch, _scanarcv,_offsety] execVM mando_missile_path+"mando_missile.sqf";

   deleteVehicle _torp;
};