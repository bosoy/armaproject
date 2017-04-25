#include "script_component.hpp"

#define __vol 1.0
#define __wei 1.27
#define __life 0.15

_seat = _this;

_seat spawn {
	_smoketrail = "#particlesource" createVehicleLocal getPos _this;
	_smoketrail setParticleParams ["\ca\data\cl_exp","","Billboard",100,__life,[0,0,-.5],velocity _this,0,__wei,__vol,0.05,[2,2.8,1.5,0.25],[[0.95,0.95,0.8,0.6],[1,1,0.95,0.95],[1,1,0.9,0.5]],[0],0,0,"","",_this];
	_smoketrail setDropInterval 0.005;
	_smoketrail setParticleRandom [0.05, [0.05, 0.05, 0.05], [0.1, 0.1, 0.1], 5, 0.1, [0,0,0,0.1], 0.5, 0.5, 360];

	_light = "#lightpoint" createVehicleLocal getPos _smoketrail;
	_light setLightColor [1,1,0.5];
	_light setLightBrightness 0.05;
	_light setLightAmbient [0.3,0.2,0.1];
	_light LightAttachObject [_smoketrail,[0,0,-1]];

	sleep 0.25;

	deleteVehicle _light;
	deleteVehicle _smoketrail;
};

[_seat, "ACE_EjectionSeat"] spawn {
	// ACE Eject Sound by zGuba
	// [_vehicle, _sound] call ace_sys_eject_sound
	private ["_vehicle", "_sound", "_positionCamera", "_positionVehicle"];
	_vehicle = _this select 0;
	_sound = _this select 1;
	_positionCamera = positionCameraToWorld [0, 0, 0];
	_positionVehicle = _vehicle modelToWorld [0, 0, 0];

	// Don't play sound in global channel during cutscenes
	if ((_positionCamera distance _positionVehicle) < 150) then {
		_vehicle say _sound;
	};
};