// mando torpedo water trail type 1
// mando_torpedowater1a.sqf v1.0
// Jan 2007 Mandoble
//
// General smoke trail script for mando missiles as torpedoes
// This script may be used as smoke trail argument for mando_missile.sqf
//
//
//
private ["_mis"];
_mis = _this select 0;

// _water = "\Ca\Data\ParticleEffects\watereffects\watereffects";
_water = "\Ca\Data\cl_water";

_watertrail1 = "#particlesource" createVehicle getPos _mis;
_watertrail1 setParticleParams [_water,"","Billboard",100,4,[0,0,0],[0,0,0],2,25.50,20,1,[1,3,2,1],[[1,1,1,1],[0.9,1,1,0.5],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
_watertrail1 setDropInterval 0;

_watertrail2 = "#particlesource" createVehicle getPos _mis;
_watertrail2 setParticleParams [_water,"","Billboard",100,4,[0,0,0],[0,0,0],2,25.50,20,1,[1,3,2,1],[[1,1,1,1],[0.9,1,1,0.5],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
_watertrail2 setDropInterval 0;



while {(!isNull _mis)&&(damage _mis == 0)} do
{
   _dir = getDir _mis;
//   _pos = [(getPos _mis select 0),(getPos _mis select 1),-1];
   _pos = getPos _mis;

   if (surfaceIsWater _pos) then
   {
      _dusttrail setDropInterval 0;
      _vec1 = [sin(_dir+120)*4,cos(_dir+120)*4,0];
      _vec2 = [sin(_dir+240)*4,cos(_dir+240)*4,0];

      _watertrail1 setPos _pos;
      _watertrail1 setParticleParams[_water,"","Billboard",100,4,[0,0,0],_vec1,2,25.50,20,1,[1,4,2,1],[[1,1,1,1],[0.9,1,1,0.3],[0.8,1,1,0.1]],[0,1],0.3,0.5,"","",""];
      _watertrail1 setDropInterval 0.01;

      _watertrail2 setPos _pos;
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
exit;