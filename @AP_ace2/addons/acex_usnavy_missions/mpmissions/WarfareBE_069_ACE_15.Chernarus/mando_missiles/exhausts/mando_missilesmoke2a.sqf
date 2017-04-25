// mando missile smoke trail type 2
// mando_missilesmoke2a.sqf v1.0
// Jan 2007 Mandoble
//
// General smoke trail script for mando missiles
// This script may be used as smoke trail argument for mando_missile.sqf
//
//
//
private ["_mis", "_altagl", "_altasl", "_pos", "_vec1", "_vec2", "_dir", "_water", "_trail", "_vol", "_wei", "_smoketrail1", "_smoketrail2", "_watertrail1", "_watertrail2", "_dusttrail", "_exhaustlight", "_i"];

_mis = _this select 0;

if (isDedicated) exitWith {};

_altagl = 0.0;
_altasl = 0.0;
_pos  = [0,0,0];
_vec1 = [0.0,0.0];
_vec2 = [0.0,0.0];
_dir  = 0;


_dust  = "\ca\data\cl_basic";
_trail = "\ca\data\missileSmoke";


_vol = 1.0;
_wei = 1.27;

_smoketrail1 = "#particlesource" createVehicleLocal getPos _mis;
_smoketrail1 setParticleParams ["\ca\data\koulesvetlo","","Billboard",100,0.2,[0,0,0],[0,0,0],0,_wei,_vol,0.05,[1,2,1.5,0.5],[[1,0.5,0,0.6],[1,1,1,0.5],[1,1,1,0.1]],[0],0,0,"","",_mis];
//_smoketrail setParticleRandom [0.05,[0.0,0.0,0.0],[0.0,0.0,0.0],0,0.5,[1,1,1,0],0,0];
_smoketrail1 setDropInterval 0.005;


_smoketrail2 = "#particlesource" createVehicleLocal getPos _mis;
_smoketrail2 setParticleParams [_trail,"","Billboard",100,0.6,[0,0,0],[0,0,0],0,_wei,_vol,0.05,[1,2.5,3,3.5],[[0.5,0.5,0.5,1],[0.7,0.7,0.7,0.5],[0.8,0.8,0.8,0]],[0],0,0,"","",_mis];
_smoketrail2 setDropInterval 0.01;

_exhaustlight = "#lightpoint" createVehicleLocal [0,0,0];
_exhaustlight setLightColor [0.7,0.8,1];

_exhaustlight setLightAmbient [0.7,0.8,1];
_exhaustlight setLightBrightness 0.2;
_exhaustlight LightAttachObject [_mis,[0,-1,0]];

_i = 0.0;
while {(!isNull _mis)&&(damage _mis < 0.05)} do
{
   _i = _i + 0.05;

   if(_i < 2)then
   {
      drop[_trail,"","Billboard",100,2,[0,0,0],[0,0,0],0,_wei,_vol,0.05,[2,3,4,5.5],[[0.5,0.5,0.5,1],[0.7,0.7,0.7,0.8],[0.8,0.8,0.8,0]],[0,1,0,0.33,0.66],0,0,"","",_mis];
   };

   _smoketrail1 setPos getPos _mis;
   _smoketrail2 setPos getPos _mis;

   sleep 0.05;
};

deleteVehicle _smoketrail1;
deleteVehicle _smoketrail2;
deleteVehicle _exhaustlight;