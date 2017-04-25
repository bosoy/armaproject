/* ace_sys_lademeister (.pbo) | (c) 2009 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

_v = vehicle player;

// Speed ?
if (speed _v > 90) exitWith { (localize "STR_ACE_LADEMEISTER_AIRFLOW") spawn ace_fnc_visual; };

// Attack helicopter?
if (getNumber(configFile >> "CfgVehicles" >> typeof _v >> "ACE_Lademeister") != 1) exitWith { TRACE_1("Vehicle has no LADEMEISTER feature",""); false };

private"_turret";
for "_i" from 0 to ((count(configFile >> "CfgVehicles" >> (typeOf _v) >> "turrets")) - 1) do {
	if (player == (_v turretUnit [_i])) then { _turret = _i; };
};
if !(getNumber(((configFile >> "CfgVehicles" >> typeof _v >> "turrets") select _turret) >> "ACE_Lademeister") == 1) exitWith { TRACE_1("Your turret does not support LADEMEISTER",""); false };

13560 cutText ["","BLACK IN",2];

private ["_pos","_dir","_sign"];

GVAR(ABORT) = false;
GVAR(RUNNING) = true;

_dir_p = getNumber(((configFile >> "CfgVehicles" >> (typeof _v) >> "turrets") select _turret) >> "ACE_Viewport");
_sign = if (_dir_p < 0) then {-1} else {1};
_dir_v = getDir _v;
_dir_view = _dir_v + _dir_p;

TRACE_3("",_dir_p,_dir_v,_dir_view);
if (_dir_view < 0) then { _dir_view = _dir_view + 360; };

_lm_cam = "Camera" camcreate [0,0,0];
_lm_cam cameraEffect ["INTERNAL", "BACK"];
_lm_cam camSetTarget objNull;
_lm_cam setDir _dir_view;
showCinemaBorder false;
_lm_cam camCommit 0;

// Mausbewegung aktivieren
call GVAR(ADDMOUSEMOVEMENT);

GVAR(R) = {
	private["_v","_d","_x","_y"];
	_v = +(_this select 0);
	_d = _this select 1;
	_x = _v select 0;
	_y = _v select 1;
	_v set [0, (cos _d)*_x - (sin _d) *_y];
	_v set [1, (sin _d)*_y + (cos _d) *_y];
	_v
};

GVAR(SPB) = {
	private ["_yaw", "_sign", "_pitchbank", "_vdir", "_vup"];
	PARAMS_3(_cam,_pitch,_bank);
	_yaw = 360 - (getDir _cam);
	_sign = [1,-1] select (_pitch < 0);
	while { (abs _pitch) > 180 } do { _pitch = _sign*((abs _pitch) - 180); };
	if (abs _pitch == 90) then { _pitch = _sign*(89.9); };
	if (abs _pitch > 90) then {
		_cam setDir (getDir _cam) - 180;
		_yaw = 360 - (getDir _cam);
		_bank = _bank + 180;
		_pitch = (180 - abs _pitch)*_sign;
	};
	_vdir = [0, cos _pitch, sin _pitch];
	_vdir = [_vdir, _yaw] call GVAR(R);
	_sign = [1,-1] select (_bank < 0);
	while { abs _bank > 360 } do { _bank = _sign*(abs _bank - 360); };
	if(abs _bank > 360) then { _sign = -1*_sign; _bank = (360 - _bank) * _sign};
	_vup = [sin _bank, 0, cos _bank];
	_vup = [_vup select 0] + ([[_vup select 1, _vup select 2], _pitch] call GVAR(R));
	_vup = [_vup, _yaw] call GVAR(R);
	_cam setVectorDirAndUp [_vdir,_vup];
};

// Positionskontrolle
[_v,_lm_cam,_sign] spawn {
	PARAMS_3(_v,_lm_cam,_sign);

	while { !GVAR(ABORT) && {alive player} && {alive _v} && {player in _v}} do {
		_offset = getPosATL player;
		if (surfaceIsWater _offset) then {_offset = getposASL player}; // Over water camera would be much to high
		_offset_v = getPosATL _v; //0;
		if (surfaceIsWater _offset_v) then {_offset_v = getposASL _v}; // Over water camera would be much to high
		//_offset_v = [0,0,0];

		_offset_z = _offset select 2; //0;
		_offset_v_z = _offset_v select 2; //0;

		_dir = (getDir _v) + (_sign*90) +360;
		if (_dir > 360) then { _dir = _dir - 360; };
		// Offset Modifikator Vertikal
		_vector = 0; //vectorDir _v;
		_vector_z = 0; //_vector select 2;

		_pos = [(_offset select 0) + ((sin _dir) * 1.1), (_offset select 1) + ((cos _dir) * 1.1), (_offset_z + (0) + ((_offset_z - _offset_v_z)/5))];

		//TRACE_4("",_pos,_offset,_offset_v,((_offset select 2)+(1.2)+(_vector_z)+(_offset_z - _offset_v_z)));

		_lm_cam camSetPos _pos; //camSetRelPos _pos;
		_lm_cam camCommit 0;
		sleep 0.01;

		// TODO: Bank camera with helicopter
		// TODO: Pitch camera with helicopter

		// ABORT on high speeds
		if (speed _v > 90) then {GVAR(ABORT) = true};
	};
};

// Richtungskontrolle
[_v,_lm_cam,_sign] spawn {
	PARAMS_3(_v,_lm_cam,_sign);

	while { !GVAR(ABORT) && {alive player} && {alive _v} && {player in _v}} do {
		_veh_dir = getDir _v;
		_cam_dir_init = _veh_dir + (_sign * 90) + 360;
		if (_cam_dir_init > 360) then { _cam_dir_init = _cam_dir_init - 360; };

		_mouse_input = GVAR(X);
		_cam_dir = _cam_dir_init + _mouse_input;

		camUseNVG (ace_sys_nvg_on);

		_lm_cam setDir _cam_dir;
		[_lm_cam, GVAR(Y), 0] call GVAR(SPB);
		_lm_cam camCommit 0;
		sleep 0.05;
		// Blur effect when no goggles on and looking in ~same direction as helicopter and helicopter flying fast

		// ABORT on high speeds
		if (speed _v > 90) then {	GVAR(ABORT) = true; };
	};
	// Entferne Mausbewegung
	call GVAR(REMOVEMOUSEMOVEMENT);
	if (speed _v > 90) then { (localize "STR_ACE_LADEMEISTER_AIRFLOW") spawn ace_fnc_visual; };

	_lm_cam cameraEffect ["TERMINATE","BACK"];
	_lm_cam camCommit 0;
	camDestroy _lm_cam;
	13560 cutText ["","BLACK IN",2];
	sleep 1;
	GVAR(RUNNING) = false;
};

false;
