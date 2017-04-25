//fnc_getImpactPos.sqf
#include "script_component.hpp"

_velocityVec = _this select 0;
_pos = _this select 1;
_airFriction = _this select 2;
_initialVelocity = [0,0,0];
if((count _this) > 3) then {
	_initialVelocity = _this select 3;
};

_gravity = 9.80665;
if((count _this) > 4) then {
	_gravity = _this select 4;
};


_fps = 0.25;

_Px = _pos select 0;
_Py = _pos select 1;
_Pz = _pos select 2;

_Vx = (_velocityVec select 0)+(_initialVelocity select 0);
_Vy = (_velocityVec select 1)+(_initialVelocity select 1);
_Vz = (_velocityVec select 2)+(_initialVelocity select 2);

_Vmag = sqrt (_Vx^2 + _Vy^2 + _Vz^2);



_exit = false;
_result = [];
while {!_exit} do
{
	_Vmag = sqrt (_Vx^2 + _Vy^2 + _Vz^2);
	_Vx = _Vx + _fps*(_Vmag*_Vx*_airFriction);
	_Vy = _Vy + _fps*(_Vmag*_Vy*_airFriction);
	_Vz = _Vz + _fps*(_Vmag*_Vz*_airFriction-_gravity);

	_Px = _Px + _Vx*_fps;
	_Py = _Py + _Vy*_fps;
	_Pz = _Pz + _Vz*_fps;
	
	// _alt = getTerrainHeightASL [_Px, _Py];
	_atlPos = ASLtoATL [_Px, _Py, _Pz];
	if((_atlPos select 2) <= 30) then {
		_fps = 0.05;
	};
	if((_atlPos select 2) <= 5) then {
		_fps = 0.01;
	};
	if((_atlPos select 2) <= 0) then {
		_exit = true;
		_result = [_Px, _Py, _Pz];
		// drop ["\Ca\Data\Cl_basic","","Billboard",1,10,_atlPos,[0,0,0],1,1.275,1.0,0.0,[5],[[1,0,0,1]],[0],0.0,2.0,"","",""];
	} else {
		// drop ["\Ca\Data\Cl_basic","","Billboard",1,0.1,[_Px, _Py, _Pz-_alt],[0,0,0],1,1.275,1.0,0.0,[5],[[1,0,0,1]],[0],0.0,2.0,"","",""];
	};
};
_result