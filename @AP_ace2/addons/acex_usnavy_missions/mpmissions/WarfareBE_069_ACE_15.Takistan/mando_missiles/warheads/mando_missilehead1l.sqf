// mando missile warhead type 1 light
// mando_missilehead1l.sqf v1.0
// Jan 2007 Mandoble
// 
// General explosion script for mando missiles
// This script may be used as explosion script argument for mando_missile.sqf
// 
// Big smoke and falling smoke debris
// low power explosion (equivalent to M_Strela_AA).

private ["_pos", "_target", "_targets", "_classtarget", "_rating", "_crewt", "_launcher", "_drop1", "_drop2", "_debris", "_maxspd", "_mass", "_vol", "_rubb", "_size", "_numdrops", "_i", "_angh", "_angv", "_rad", "_radv", "_radh", "_vel", "_size1", "_size2", "_pos2", "_b2", "_b1", "_dmgtarget", "_score", "_cost", "_side", "_unit", "_crew"];

_pos = _this select 0;
_target = _this select 1;
_side = _this select 2;
_launcher = _this select 3;

_targets = [];
if ((isNull _target) || ((typeOf _target) in ["LaserTargetW", "LaserTargetE", "LaserTargetC", "Logic"])) then
{
	_posl = _pos;
   if (!isNull _target) then
   {
		if ((_target distance _pos) < 30) then
		{
			_posl = getPos _target;   
		};
   };

   
   if ((_posl distance _pos) < 30) then
   {
      if ((_posl select 2) > 20) then
      {
         _targets = nearestObjects [_pos, ["Air"], 100];
      }
      else
      {
         _targets = nearestObjects [_posl, ["LandVehicle", "Air", "Ship"], 25];
      };
	  

	  
      if (count _targets > 0) then
      {
         _target = _targets select 0;
   	     switch (getNumber(configFile >> "CfgVehicles" >> typeOf _target >> "side")) do
	     {
	        case 0:
		    {
   		       _side = east;
		    };
		 
		    case 1:
		    {
		       _side = west;
		    };
		 
		    case 2:
		    {
		       _side = resistance;
		    };

		    default
		    {
		       _side = civilian;
		    };
	     };		 
      };	 	  
   };
};


_dmgtarget = damage _target;
_classtarget = typeOf _target;
_crewt = crew _target;
_cost = getNumber (configFile >> "CfgVehicles" >> _classtarget >> "cost");



_drop1 = ["\Ca\Data\ParticleEffects\Universal\Universal", 16, 12, 8];
_drop2 = "\ca\data\cl_exp";
_debris = "\ca\weapons\kusplechu2";

_maxspd = 30;
_mass  = 1.275 + 0.3;
_vol   = 1.0;
_rubb  = 1;
_size  = [0.25];
_numdrops = 6 + random 6;
for [{_i = 0},{_i < _numdrops},{_i = _i + 1}] do
{
   _angh = random 359;
   _angv = (random 180)-90;
   _rad  = 30 + random _maxspd;
   _radv = abs(_rad * sin(_angv));
   _radh = abs(_rad * cos(_angv));
   _vel = [sin(_angh)*_radh, cos(_angh)*_radh, sin(_angv)*_radv];
   drop [_drop1, "", "SpaceObject", 0.1, 6, _pos, _vel, 4, _mass, _vol, _rubb/8, _size, [[0,0,0,1]], [0,1,0], 5, 0.05, mando_missile_path+"warheads\smokedebrisa.sqs", "", ""];
};

_maxspd = 20;
_mass  = 1.275;
_vol   = 1.0;
_rubb  = 1;
_size1  = [3,7.5,11,15];
_size2  = [4,8,10,8];
_numdrops = 60;

for [{_i = 0},{_i < _numdrops},{_i = _i + 1}] do
{
   _angh = random 359;
   _angv = (random 180) - 90;
   _rad  = 20 + random _maxspd;

   _radv = abs(_rad * sin(_angv));
   _radh = abs(_rad * cos(_angv));
   _vel = [sin(_angh)*_radh, cos(_angh)*_radh, sin(_angv)*_radv];
   drop [_drop1, "", "Billboard", 1, 3, _pos, _vel, 0.5, _mass, _vol, _rubb/2, _size1, [[1,1,1,0.6],[0,0,0,0.5],[0,0,0,0.4],[0.5,0.5,0.5,0]], [0,1,0], 5, 0.05, "", "", ""];
   _vel = [sin(_angh)*_radh, cos(_angh)*_radh, sin(_angv)*_radv];
   drop [_drop2, "", "Billboard", 1, 1, _pos, _vel, 0.5, _mass, _vol, _rubb/1.5, _size2, [[1,0.5,0,0.6],[1,1,1,0.5],[1,1,1,0.4],[1,1,1,0]], [0,1,0], 5, 0.05, "", "", ""];
};


if (local _target) then
{
   _pos2 = [_pos select 0, _pos select 1, (_pos select 2)];
   _b2 = "RoadCone" createVehicle _pos2;
   _b2 setPos _pos2;
   _b1 = "Sh_122_HE" createVehicle (_b2 modelToworld [0,0,0]);
   sleep 0.5;
   deleteVehicle _b2;
};

Sleep 1;

call mando_scorefunc;