#include "script_component.hpp"

if !(isnil QUOTE(GVAR(noShellEjection))) exitWith {};

GVAR(cart_array) = [];
GVAR(cart_maxPresent) = 500; //Maximal number of cartridges present at once. If limit is reached the oldest cartridge gets deleted. 0 = unlimited.
GVAR(cart_lifetime) = 0; //Time before the spawned cartridge gets deleted (seconds). 0 = unlimited.

// TODO: Add support to ace_sys_cartridges instead?
acex_ru_veh_bmd2_cart_fired =
{
	_vehicle = _this select 0;
	_vehicleType = typeOf _vehicle;
	_muzzle = _this select 1;
	_ammo = _this select 4;
	_shell = _this select 6;

	if (_muzzle != "2A42") exitWith {};

	_turretDir = (getDir _shell) -90;

	_class = "ace_casing_30mm";
	_p3d = QUOTE(PATHTO_M(scripts\sa_casing_30mm));

	_turretOffset = [0,-0.4,-0.05];
	_ejectOffset = 0;
	_ejectSpeed = 5.5;
	_landOffset = [4.5,0,0.005];

	_turretDir = _turretDir + 90;
	_pos = _vehicle modelToWorld _turretOffset;
	_pos = [((_pos select 0) + ((sin _turretDir) * (_landOffset select 0)) + ((cos _turretDir) * (_landOffset select 1))) + ([3] call acex_ru_veh_bmd2_cart_random), ((_pos select 1) + ((cos _turretDir) * (_landOffset select 0)) + ((sin _turretDir) * (_landOffset select 1))) + ([3] call acex_ru_veh_bmd2_cart_random), _landOffset select 2];
//	_pos = [((_pos select 0) + ((sin _turretDir) * (_landOffset select 0)) + ((cos _turretDir) * (_landOffset select 1))) + ([3] call acex_ru_veh_bmd2_cart_random), ((_pos select 1) + ((cos _turretDir) * (_landOffset select 0)) + ((sin _turretDir) * (_landOffset select 1))) + ([3] call acex_ru_veh_bmd2_cart_random), 1];

	[_class, _pos, (random 360)] spawn {
		sleep 1;
		_this call acex_ru_veh_bmd2_cart_spawner;
	};

	[_vehicle, getDir _vehicle, _turretDir, _turretOffset, _ejectOffset, _ejectSpeed, 3, _p3d] call acex_ru_veh_bmd2_cart_eject;
};

acex_ru_veh_bmd2_cart_spawner =
{
	private ["_type", "_pos", "_turretDir", "_brass"];
	_type = _this select 0;
	_pos = _this select 1;
	_turretDir = _this select 2;

	_brass = _type createVehicleLocal _pos;
	_brass setDir _turretDir;
	_brass setPosATL _pos;

	PUSH(acex_ru_veh_bmd2_cart_array,_brass);

	// TODO: ACE FIFO instead
	if (acex_ru_veh_bmd2_cart_maxPresent != 0) then
	{ //Amount limit is on:
		if ((count acex_ru_veh_bmd2_cart_array) > acex_ru_veh_bmd2_cart_maxPresent) then
		{
			private "_delete";
			_delete = acex_ru_veh_bmd2_cart_array select 0;
			deleteVehicle _delete;
			acex_ru_veh_bmd2_cart_array = acex_ru_veh_bmd2_cart_array - [objNull];
		};
	};

	if (acex_ru_veh_bmd2_cart_lifetime != 0) then
	{ //Timed removal turned on:
		[_brass] spawn
		{
			sleep acex_ru_veh_bmd2_cart_lifetime;
			deleteVehicle (_this select 0);
			acex_ru_veh_bmd2_cart_array = acex_ru_veh_bmd2_cart_array - [_brass];
		};
	};
};

acex_ru_veh_bmd2_cart_eject =
{
	private ["_vehicle", "_vehicleDir", "_turretDir", "_offsetX", "_offsetY", "_offsetZ", "_offsetEject", "_ejectSpeed", "_ejectLifetime", "_p3d", "_pos", "_vel"];
	_vehicle = _this select 0;
	_vehicleDir = _this select 1;
	_turretDir = _this select 2;
	_offsetX = (_this select 3) select 0;
	_offsetY = (_this select 3) select 1;
	_offsetZ = (_this select 3) select 2;
	_offsetEject = _this select 4;
	_ejectSpeed = _this select 5;
	_ejectLifetime = _this select 6;
	_p3d = _this select 7;

	if (_vehicleDir > 45 && _vehicleDir <= 135) then
	{
		_pos = [((cos _turretDir) * (- _offsetEject)) + _offsetX, ((sin _turretDir) * _offsetEject) - _offsetY, _offsetZ];
		_vel = [(sin _turretDir) * _ejectSpeed, (cos _turretDir) * _ejectSpeed, 0];
	} else {
		if (_vehicleDir > 135 && _vehicleDir <= 225) then
		{
			_pos = [((sin _turretDir) * (- _offsetEject)) + _offsetX, ((cos _turretDir) * (- _offsetEject)) - _offsetY, _offsetZ];
			_vel = [(cos _turretDir) * (- _ejectSpeed), (sin _turretDir) * _ejectSpeed, 0];
		} else {
			if (_vehicleDir > 225 && _vehicleDir <= 315) then
			{
				_pos = [((cos _turretDir) * _offsetEject) + _offsetX, ((sin _turretDir) * (- _offsetEject)) - _offsetY, _offsetZ];
				_vel = [(sin _turretDir) * (- _ejectSpeed), (cos _turretDir) * (- _ejectSpeed), 0];
			} else {
				_pos = [((sin _turretDir) * _offsetEject) + _offsetX, ((cos _turretDir) * _offsetEject) - _offsetY, _offsetZ];
				_vel = [(cos _turretDir) * _ejectSpeed, (sin _turretDir) * (- _ejectSpeed), 0];
			};
		};
	};

	drop[_p3d,"","SpaceObject",1,_ejectLifetime,_pos,_vel,3,5,1,0,[1],[[1,1,1,1]],[0],0.1,0.5,"","",_vehicle];
};

acex_ru_veh_bmd2_cart_random =
{
	private ["_range", "_return"];
	_range = _this select 0;
	_return = _range - random (_range * 2);

	_return;
};
