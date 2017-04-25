#include "script_component.hpp"

#define __cfg configFile >> "CfgAmmo" >> _ammoType
#define __towsmoke (getNumber (__cfg >> "ace_towsmoke"))
#define __enginetime (getNumber (__cfg >> "thrustTime"))
#define __thrust (getNumber (__cfg >> "thrust"))

private ["_i", "_t0", "_dir", "_vol", "_wei", "_exhaustlight", "_vel", "_delta","_enginePoints","_lightPoints"];

PARAMS_2(_mis,_ammotype);

if !(__towsmoke > 0) exitWith {};

_dir = 0;
_vol = 1.0;
_wei = 1.27;
_vel = 5;
_delta = 90;

_t0 = time + __enginetime;

if (__towsmoke == 1) then
{
	_exhaustlight = "#lightpoint" createVehicleLocal [0,0,0];
	_exhaustlight setLightColor [0.7,0.8,1];
	_exhaustlight setLightAmbient [0.7,0.8,1];
	_exhaustlight setLightBrightness 0.2;
	_exhaustlight LightAttachObject [_mis,[0,-1,0]];

	while {alive _mis} do
	{
		_dir = getDir _mis;
		_vdir = vectorDir _mis;

		_lightPoints = [[[0.05,-1,0],[_vel*sin(_dir+_delta),_vel*cos(_dir+_delta),-_vel*(_vdir select 2)]],[[-0.1,-1,0],[_vel*sin(_dir-_delta),_vel*cos(_dir-_delta),-_vel*(_vdir select 2)]]];
		
		{
			drop ["\ca\data\kouleSvetlo","","Billboard",100,0.1,_mis modelToWorld (_x select 0),(_x select 1),0,_wei,_vol,0.05,[0.9],[[1,1,0.3,0.8]],[0],0,0,"","",""];
		} forEach _lightPoints;

		if ((time <= _t0) && {(_mis distance (positionCameraToWorld [0,0,0]) < viewDistance)}) then
		{	//while sustain motor works and the missile is visible
			_enginePoints = [[[0.2,-1,0],[-_vel*(_vdir select 0),-_vel*(_vdir select 1),-_vel*(_vdir select 2)]],[[-0.15,-1,0],[-_vel*(_vdir select 0),-_vel*(_vdir select 1),-_vel*(_vdir select 2)]]];
			
			{
				drop ["\ca\data\missileSmoke","","Billboard",100,4+random 2, _mis modelToWorld (_x select 0),(_x select 1),0,_wei,_vol,0.5,[1,2,3,4],[[0.35,0.35,0.35,0.3],[0.25,0.25,0.25,0.2],[0.2,0.2,0.2,0.1]],[0],0,0,"","",""];
			} forEach _enginePoints;
		};
		
		sleep 0.005;
	};
	
	deleteVehicle _exhaustlight;
}
else
{
	_delta = 0;
	_wei = 1.25;
	_vol = 1;
	_i = __thrust/140;
	while { (!isNull _mis) && {(damage _mis < 0.05)} } do
	{
		//_dir = getDir _mis;
		drop ["\ca\data\kouleSvetlo","","Billboard",100,0.03,_mis modelToWorld [0,0,0],[0,0,0],0,_wei,_vol,0.05,[0.5],[[1,1,0.3,0.7]],[0],0,0,"","",""];
		/*if (time <= _t0) then
		{
			drop ["\ca\data\missileSmoke","","Billboard",100,4+random 2, _mis modelToWorld [0,0,0],[-_vel*(vectorDir _mis select 0),-_vel*(vectorDir _mis select 1),-_vel*(vectorDir _mis select 2)],0,_wei,_vol,0.5,[1,2,4,6],[[0.3,0.3,0.3,0.25*_i],[0.25,0.25,0.25,0.15*_i],[0.2,0.2,0.2,0.08*_i]],[0],0,0,"","",""];
		};*/
		sleep 0.005;
	};
};