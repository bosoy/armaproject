// mando missile launch FX example
// mando_scudlaunch.sqf v1.0
// March 2007 Mandoble
//
// Example of missile launch time FX 
//
//
private ["_mis", "_water", "_trail", "_colors", "_size", "_sizes", "_dur", "_rot", "_mass", "_vol", "_ang", "_pos", "_vel", "_poss", "_vels", "_i", "_drop", "_dropw", "_particle"];
_mis = _this select 0;


//_trail = "\ca\data\cl_basic";
_trail = "\Ca\Data\missileSmoke";

_colors = [[1,1,.6,1],[1,1,0.6,0.8],[1,1,0.6,0.5],[1,1,1,0]];
_sizes = [2,5, 10];

_dur = 2;
_rot  = 1;
_mass = 2.0;
_vol  = 1;


_mis say3D "mando_scud";
// _particle = ["\Ca\Data\ParticleEffects\FireAndSmokeAnim\SmokeAnim.p3d", 8, 3, 1];
_particle = ["\Ca\Data\ParticleEffects\Universal\Universal", 16, 12, 8];

_drop = "#particlesource" createVehicleLocal [getPos _mis select 0,getPos _mis select 1,0];
_drop setParticleCircle [5, [0,10,0]];
_drop setParticleParams [_particle,"","Billboard",100,3,[0,0,0],[0,0,0],2,25.50,20,1,[10,15,20],[[0.5,0.5,0.5,0],[0.5,0.5,0.4,0.5],   [0.5,0.4,0.4,0.3],[0.5,0.4,0.4,0]],[1,1],0,0,"","", ""];
_drop setDropInterval 0.05;

if (surfaceIsWater getPos _mis) then
{
//   _particle = "\Ca\Data\ParticleEffects\watereffects\watereffects";
   _particle = "\ca\data\cl_water";

   _dropw = "#particlesource" createVehicleLocal [getPos _mis select 0,getPos _mis select 1,-3];
   _dropw setParticleCircle [5, [0,6,0]];
   _dropw setParticleParams [_particle,"","Billboard",100,3,[0,0,0],[0,0,0],2,25.50,20,1,[5,10,15],[[1,1,1,0],   [1,1,1,0.5], [1,1,1,0.3],[1,1,1,0]],[1,1],0,0,"","", ""];
   _dropw setDropInterval 0.1;
}; 


if (local _mis) then
{
   _humans = (getPos _mis) nearObjects ["Man",20];
   for [{_i = 0},{_i < count _humans}, {_i = _i + 1}] do
   { 
      _human = _humans select _i;
      _dir = ((getPos _human select 0)-(getPos _mis select 0)) atan2 ((getPos _human select 1)-(getPos _mis select 1));
      _human setPos [getPos _human select 0,getPos _human select 1, (getPos _human select 2)+2];
      _human setVelocity [10*sin(_dir)*20/(_human distance _mis),10*cos(_dir)*20/(_human distance _mis), 0.25*20/(_human distance _mis)];
   };
};


while {((getPos _mis select 2)< 70) && (!isNull _mis)} do
{
   _poss = [(getPos _mis select 0), (getPos _mis select 1), (getPos _mis select 2)];
//   _vels = [(-(vectorDir _mis select 0))*(6-random(12)), (-(vectorDir _mis select 1))*(6-random(12)), (-(vectorDir _mis select 2))*(50+random(12))];
   _vels = [0,0,0];
   drop[_trail,"","Billboard",100,2-(getPos _mis select 2)/70,_poss,_vels,_rot,_mass,_vol,0.25,_sizes,_colors,[1,0],1,0.1,"","",""];

   Sleep(0.005);
};

deleteVehicle _drop;
deleteVehicle _dropw;