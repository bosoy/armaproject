// mando missile tow smoke trail
// mando_towsmoke.sqf v1.0
// Oct 2007 Mandoble
//
// General smoke trail script for mando missiles TOW type 
// This script may be used as smoke trail argument for mando_missile.sqf
//

private ["_mis", "_pos", "_dir", "_vol", "_wei", "_smoketrail1", "_smoketrail2","_exhaustlight", "_vel", "_delta"];

_mis = _this select 0;

if (isDedicated) exitWith {};

_pos  = [0,0,0];
_vec1 = [0.0,0.0];
_vec2 = [0.0,0.0];
_dir  = 0;



_vol = 1.0;
_wei = 1.27;
_vel = 5;
_delta = 90;

_exhaustlight = "#lightpoint" createVehicleLocal [0,0,0];
_exhaustlight setLightColor [0.7,0.8,1];

_exhaustlight setLightAmbient [0.7,0.8,1];
_exhaustlight setLightBrightness 0.2;
_exhaustlight LightAttachObject [_mis,[0,-1,0]];

_i = 0.0;
while {(!isNull _mis)&&(damage _mis < 0.05)} do
{
   _dir = getDir _mis;
   drop ["\ca\data\koulesvetlo","","Billboard",100,0.1,_mis modelToWorld [0.05,-1,0],[_vel*sin(_dir+_delta),_vel*cos(_dir+_delta),-_vel*(vectorDir _mis select 2)],0,_wei,_vol,0.05,[0.9,1,0.8,0.5],[[1,0.5,0,0.6],[1,1,1,0.5],[1,1,1,0.1]],[0],0,0,"","",""];
   drop ["\ca\data\missileSmoke","","Billboard",100,0.4, _mis modelToWorld [0.1,-1,0],[_vel*sin(_dir+_delta),_vel*cos(_dir+_delta),-_vel*(vectorDir _mis select 2)],0,_wei,_vol,0.05,[1,2,3,4],[[0.5,0.5,0.5,0.1],[0.5,0.5,0.5,0.5],[0.5,0.5,0.5,0]],[0],0,0,"","",""];


   drop ["\ca\data\koulesvetlo","","Billboard",100,0.1,_mis modelToWorld[-0.1,-1,0],[_vel*sin(_dir-_delta),_vel*cos(_dir-_delta),-_vel*(vectorDir _mis select 2)],0,_wei,_vol,0.05,[0.9,1,0.8,0.5],[[1,0.5,0,0.6],[1,1,1,0.5],[1,1,1,0.1]],[0],0,0,"","",""];
   drop ["\ca\data\missileSmoke","","Billboard",100,0.4, _mis modelToWorld [-0.05,-1,0],[_vel*sin(_dir-_delta),_vel*cos(_dir-_delta),-_vel*(vectorDir _mis select 2)],0,_wei,_vol,0.05,[1,2,3,4],[[0.5,0.5,0.5,0.1],[0.5,0.5,0.5,0.5],[0.5,0.5,0.5,0]],[0],0,0,"","",""];


   sleep 0.005;
};
deleteVehicle _exhaustlight;