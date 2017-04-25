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
_water = "\Ca\Data\cl_water";
_trail = "\ca\data\missileSmoke";


_vol = 1.0;
_wei = 1.27;

if (local _mis) then
{
   playSound "mando_radar2";
};



_smoketrail1 = "#particlesource" createVehicleLocal getPos _mis;
_smoketrail1 setParticleParams ["\ca\data\koulesvetlo","","Billboard",100,1,[0,0,0],[0,0,0],0,_wei,_vol,0.05,[1,3,0,3,0,3,0,3,0,3,0,3,0,3,0,1,0.5],[[1,0,1,0],[1,0,1,0.3],[1,0,1,0.2],[1,0,1,0.1]],[0],0,0,"","",_mis];
_smoketrail1 setDropInterval 0.002;


_exhaustlight = "#lightpoint" createVehicleLocal [0,0,0];
_exhaustlight setLightColor [0.7,0.8,1];

_exhaustlight setLightAmbient [0.7,0.8,1];
_exhaustlight setLightBrightness 0.2;
_exhaustlight LightAttachObject [_mis,[0,-1,0]];

_i = 0.0;
while {(!isNull _mis)&&(damage _mis < 0.05)} do
{
   _smoketrail1 setPos getPos _mis;
   sleep 0.05;
};
deleteVehicle _smoketrail1;
deleteVehicle _exhaustlight;