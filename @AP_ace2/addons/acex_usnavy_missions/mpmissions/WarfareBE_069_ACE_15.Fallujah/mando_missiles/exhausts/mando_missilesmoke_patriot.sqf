// mando missile smoke trail type 1
// mando_missilesmoke1a.sqf v1.0
// Jan 2007 Mandoble
//
// General smoke trail script for mando missiles
// This script may be used as smoke trail argument for mando_missile.sqf
//
// Sea and ground water/dust trails too if flying below 40 and missile is not diving.
//
private ["_mis", "_altagl", "_altasl", "_pos", "_vec1", "_vec2", "_dir", "_vdir", "_water", "_trail", "_vol", "_wei", "_smoketrail1", "_smoketrail2", "_watertrail1", "_watertrail2", "_dusttrail", "_exhaustlight", "_i"];

_mis = _this select 0;

if (isDedicated) exitWith {};

_altagl = 0.0;
_altasl = 0.0;
_pos  = [0,0,0];
_vec1 = [0.0,0.0];
_vec2 = [0.0,0.0];
_dir  = 0;

_dust  = ["\Ca\Data\ParticleEffects\Universal\Universal", 16, 12, 8];
//_trail = "\ca\data\cl_basic";
_water = "\Ca\Data\cl_water";
_trail = "\ca\data\missileSmoke";


_vol = 1.0;
_wei = 1.27;

_smoketrail1 = "#particlesource" createVehicleLocal getPos _mis;
_smoketrail1 setParticleParams ["\ca\data\koulesvetlo","","Billboard",100,0.2,[0,0,0],[0,0,0],0,_wei,_vol,0.05,[1,2,1.5,0.5],[[1,0.5,0,0.6],[1,1,1,0.5],[1,1,1,0.1]],[0],0,0,"","",_mis];
//_smoketrail setParticleRandom [0.05,[0.0,0.0,0.0],[0.0,0.0,0.0],0,0.5,[1,1,1,0],0,0];
_smoketrail1 setDropInterval 0.002;


_smoketrail2 = "#particlesource" createVehicleLocal getPos _mis;
_smoketrail2 setParticleParams [_trail,"","Billboard",100,3,[0,0,0],[0,0,0],0,_wei,_vol,0.05,[1,5,8,9],[[0.9,0.9,0.9,1],[0.7,0.7,0.7,0.8],[0.6,0.6,0.6,0]],[0],0.01,0.4,"","",_mis];
_smoketrail2 setDropInterval 0.002;


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

_i = 0.0;
while {(!isNull _mis)&&(damage _mis < 0.05)} do
{
   _i = _i + 0.05;

   if (_i < 1) then
   {
      drop[_trail,"","Billboard",100,2,[0,0,0],[0,0,0],0,_wei,_vol,0.05,[2,3,4,5.5],[[0.5,0.5,0.5,0.8],[0.7,0.7,0.7,0.6],[0.8,0.8,0.8,0]],[0],0,0,"","",_mis];
   };

   _smoketrail1 setPos getPos _mis;
   _smoketrail2 setPos getPos _mis;

   _altagl = getPos _mis select 2;
   if ((_altagl < 40)&&((velocity _mis select 2)>-14)) then 
   {
      _dir = getDir _mis;
      _vdir = vectorDir _mis;
      _pos = [(getPos _mis select 0)+_altagl*1.2*(-(_vdir select 0)),(getPos _mis select 1)+_altagl*1.2*(-(_vdir select 1)),0];

      if (surfaceIsWater _pos) then
      {
         _dusttrail setDropInterval 0;
         _vec1 = [sin(_dir+120)*4,cos(_dir+120)*4,0];
         _vec2 = [sin(_dir+240)*4,cos(_dir+240)*4,0];

         _watertrail1 setPos _pos;
         _watertrail1 setParticleParams[_water,"","Billboard",100,4,[0,0,0],_vec1,2,25.50,20,1,[4,6,8,10],[[1,1,1,1],[0.9,1,1,0.5],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
         _watertrail1 setDropInterval 0.01;

         _watertrail2 setPos _pos;
         _watertrail2 setParticleParams[_water,"","Billboard",100,4,[0,0,0],_vec2,2,25.50,20,1,[4,6,8,10],[[1,1,1,0.6],[0.9,1,1,0.3],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
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
   sleep 0.05;
};
deleteVehicle _smoketrail1;
deleteVehicle _smoketrail2;
deleteVehicle _watertrail1;
deleteVehicle _watertrail2;
deleteVehicle _dusttrail;
deleteVehicle _exhaustlight;