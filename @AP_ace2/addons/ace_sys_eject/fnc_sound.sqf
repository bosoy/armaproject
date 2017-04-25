#include "script_component.hpp"
// ACE Eject Sound by zGuba
// [_vehicle, _sound] call ace_sys_eject_sound
private ["_positionCamera", "_positionVehicle"];
PARAMS_2(_vehicle,_sound);
_positionCamera = positionCameraToWorld [0, 0, 0];
_positionVehicle = _vehicle modelToWorld [0, 0, 0];

// Don't play sound in global channel during cutscenes
if ((_positionCamera distance _positionVehicle) < 150) then {
	_vehicle say _sound;
};