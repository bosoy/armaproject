// mando missile launch FX example
// mando_missilelaunch1a.sqf v1.0
// March 2007 Mandoble
//
// Example of missile launch time FX 
//
//
private ["_mis"];
_mis = _this select 0;

// _water = "\Ca\Data\ParticleEffects\watereffects\watereffects";
_water = "\Ca\Data\cl_water";

_color = [[1,1,1,1],[1,1,1,0.8],[1,1,1,0.5],[1,1,1,0.1]];
_size = [1,2,3];

_dur = 5;
_rot  = 1;
_mass = 2.0;
_vol  = 1;

waitUntil {(getPosASL _mis select 2)>-5};

while {(getPosASL _mis select 2)< 10} do
{
   for [{_i = 0},{_i < 20},{_i = _i + 1}] do
   {
      _ang = random(359);
      _pos = [(getPos _mis select 0)+sin(_ang)*2, (getPos _mis select 1)+cos(_ang)*2, 0];
      _vel = [sin(_ang)*5+random(3), cos(_ang)*5+random(3), 40+random(20)];
      drop[_water,"","Billboard",100,_dur,_pos,_vel,_rot,_mass,_vol,0.5,_size,_color,[1,0],1,0.1,"","",""];
   };
   Sleep(0.01);
};

_color = [[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,0.1]];
_size = [2,6];

while {((getPosASL _mis select 2)< 25) && (!isNull _mis)} do
{
   for [{_i = 0},{_i < 20},{_i = _i + 1}] do
   {
      _ang = random(359);
      _pos = [(getPos _mis select 0)+sin(_ang)*2, (getPos _mis select 1)+cos(_ang)*2, 0.2];
      _vel = [sin(_ang)*15+random(5), cos(_ang)*15+random(5), 0];
      drop[_water,"","Billboard",100,_dur,_pos,_vel,_rot,_mass,_vol,0.5,_size,_color,[1,0],1,0.1,"","",""];
   };
   Sleep(0.01);
};
