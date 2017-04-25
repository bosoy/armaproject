// by Xeno
#define THIS_FILE "x_heli_release.sqf"
#include "x_setup.sqf"
private ["_vehicle","_caller","_id"];
PARAMS_3(_vehicle,_caller,_id);

if (_caller == driver _vehicle) then {
	_vehicle removeAction _id;
	_vehicle setVariable [QGVAR(Vehicle_Released), true];
};