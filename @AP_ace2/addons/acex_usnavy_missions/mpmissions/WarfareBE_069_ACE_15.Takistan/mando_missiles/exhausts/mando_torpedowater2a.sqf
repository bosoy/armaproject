// mando torpedo water trail type 2
// mando_torpedowater2a.sqf v1.0
// Jan 2007 Mandoble
//
// General smoke trail script for mando missiles as torpedoes
// This script may be used as smoke trail argument for mando_missile.sqf
//
//
//
private ["_mis", "_speed_old", "_pos_old", "_elapsed"];
_mis = _this select 0;

// _water = "\Ca\Data\ParticleEffects\watereffects\watereffects";
_water = "\Ca\Data\cl_water";

_watertrail1 = "#particlesource" createVehicle getPos _mis;
_watertrail1 setParticleParams [_water,"","Billboard",100,4,[0,0,0],[0,0,0],2,25.50,20,1,[1,3,2,1],[[1,1,1,1],[0.9,1,1,0.5],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
_watertrail1 setDropInterval 0;

_watertrail2 = "#particlesource" createVehicle getPos _mis;
_watertrail2 setParticleParams [_water,"","Billboard",100,4,[0,0,0],[0,0,0],2,25.50,20,1,[1,3,2,1],[[1,1,1,1],[0.9,1,1,0.5],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
_watertrail2 setDropInterval 0;


_speed_old = 0;
_elapsed = (dayTime * 3600);
_pos_old = getPos _mis;
while {(!isNull _mis)&&(damage _mis == 0)} do
{
   _dir = getDir _mis;

   if ((dayTime * 3600) > (_elapsed + 1)) then
   {
      _elapsed = (dayTime * 3600);
      _speed = ((getPos _mis) distance _pos_old);
      if (_speed < (_speed_old - 10)) then
      {
         _mis setDamage 1;
      };
      _speed_old = _speed;
   };

   _pos = getPosASL _mis;

   if (surfaceIsWater _pos) then
   {
      _dusttrail setDropInterval 0;
      _vec1 = [sin(_dir+120)*4,cos(_dir+120)*4,0];
      _vec2 = [sin(_dir+240)*4,cos(_dir+240)*4,0];

      _watertrail1 setPosASL _pos;
      _watertrail1 setParticleParams[_water,"","Billboard",100,4,[0,0,0],_vec1,2,25.50,20,1,[1,4,2,1],[[1,1,1,1],[0.9,1,1,0.3],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
      _watertrail1 setDropInterval 0.01;

      _watertrail2 setPosASL _pos;
      _watertrail2 setParticleParams[_water,"","Billboard",100,4,[0,0,0],_vec2,2,25.50,20,1,[1,3,2,1],[[1,1,1,1],[0.9,1,1,0.3],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
      _watertrail2 setDropInterval 0.01;
   }
   else
   {
      _mis setDamage 1;
   };
   sleep 0.05;
};
_mis setDamage 1;
deleteVehicle _watertrail1;
deleteVehicle _watertrail2;
