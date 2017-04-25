/* ace_sys_minesweeper (.pbo) | (c) 2011 by rocko */

#include "script_component.hpp"

ADDON = false;

[QGVAR(rocketAPOBS_FX), { _this call FUNC(rocketAPOBS_FX) }] call CBA_fnc_addEventHandler;

PREP(sweep); // Useraction via Interaction menu to use the detector, beeps occasionally and constant if near a mine
//PREP(jammer); // Used later for special equipped jammer vehicles, to block IED detonation that are remotely detonated

FUNC(place_marker) = {
	PARAMS_1(_unit);
	_hasMarkersLeft = _unit getVariable [QGVAR(markersleft),10];
	_hasMarkersLeft = _hasMarkersLeft - 1;
	_unit setVariable [QGVAR(markersleft),_hasMarkersLeft];
	if (_hasMarkersLeft <= 0 && {"ACE_MineMarkers" in (weapons player)}) then {
		_unit removeWeapon "ACE_MineMarkers";
	};
	_marker = "ACE_MineMarker" createVehicle [0,0,0];
	_pos = _unit modelToWorld [0,0,0];
	_offset = if ((_unit call CBA_fnc_getUnitAnim select 0) == "prone") then { 1.2 } else { 1.1 };
	_pos set [0, (_pos select 0) + (sin (direction _unit) * _offset)];
	_pos set [1, (_pos select 1) + (cos (direction _unit) * _offset)];
	_marker setPos _pos; // TODO: Place 1m in front of player
	_marker setDir (getDir _unit);
	_unit reveal _marker;
};

FUNC(place_flag) = {
	PARAMS_1(_unit);
	_hasFlagsLeft = _unit getVariable [QGVAR(flagsleft),8];
	_hasFlagsLeft = _hasFlagsLeft - 1;
	_unit setVariable [QGVAR(flagsleft),_hasFlagsLeft];
	if (_hasFlagsLeft <= 0 && {"ACE_MineMarkers_MineFlag" in (weapons player)}) then {
		_unit removeWeapon "ACE_MineMarkers_MineFlag";
	};
	_marker = "ACE_Minemarker_flag" createVehicle [0,0,0];
	_pos = _unit modelToWorld [0,0,0];
	_offset = if ((_unit call CBA_fnc_getUnitAnim select 0) == "prone") then { 1.2 } else { 1.1 };
	_pos set [0, (_pos select 0) + (sin (direction _unit) * _offset)];
	_pos set [1, (_pos select 1) + (cos (direction _unit) * _offset)];
	_marker setPos _pos; // TODO: Place 1m in front of player
	_marker setDir (getDir _unit);
	_unit reveal _marker;
};

FUNC(pickup_marker) = {
	PARAMS_1(_marker);
	// Increment to eternity
	if !("ACE_MineMarkers" in (weapons player)) then {
		player addWeapon "ACE_MineMarkers";
		player setVariable [QGVAR(markersleft),1];
	} else {
		_hasMarkersLeft = player getVariable [QGVAR(markersleft),1];
		_hasMarkersLeft = _hasMarkersLeft + 1;
		player setVariable [QGVAR(markersleft),_hasMarkersLeft];
	};
	// Check for light
	_light = _marker getVariable [QGVAR(light),objNull];
	if (!isNull _light) then { 
		deleteVehicle _light;
	};
	deleteVehicle _marker;
};

FUNC(pickup_flag) = {
	PARAMS_1(_marker);
	// Increment to eternity
	if !("ACE_MineMarkers_MineFlag" in (weapons player)) then {
		player addWeapon "ACE_MineMarkers_MineFlag";
		player setVariable [QGVAR(flagsleft),1];
	} else {
		_hasFlagsLeft = player getVariable [QGVAR(flagsleft),1];
		_hasFlagsLeft = _hasFlagsLeft + 1;
		player setVariable [QGVAR(flagsleft),_hasFlagsLeft];
	};
	deleteVehicle _marker;
};

FUNC(changeMineMarker) = {
	PARAMS_3(_marker,_attachment,_enable);
	switch (_attachment) do {
		case "light": {
			_marker animate ["remove_light",_enable]; // In Arma you cannot animate markerlight memorypoints!
			if (_enable == 0) then {
				_light = "ACE_MineMarker_Light" createVehicle getPos _marker;
				_light attachto [_marker,[0,0,0],"light"];
				_marker setVariable [QGVAR(light),_light,true];
			} else {
				_light = _marker getVariable [QGVAR(light),objNull];
				if (!isNull _light) then {
					deleteVehicle _light;
				};
			};
		};
		case "sign": {
			_marker animate ["remove_sign",_enable];
		};
		case "path": {
			_marker animate ["remove_path",_enable];
		};
		case "flip": {
			if (_marker animationPhase "flip_path" == 1) then {
				_enable = 0;
			} else {
				_enable = 1;
			};
			_marker animate ["flip_path",_enable];
		};		
	};
};

FUNC(assembleAPOBS) = { // TODO: Move attach stuff to Init XEH
	private ["_pos","_apobs","_apobs_rocket"];
	PARAMS_2(_front,_rear);	
	_pos = getPosATL _front; // Needed to align APOBS on the Front assembly // TODO: Check geometry (kills player)
	{ _x setPos [_pos select 0, _pos select 1, (_pos select 2) - 20] } foreach [_front,_rear];
	_apobs = "ACE_APOBS_MK7MOD2" createVehicle [0,0,0];
	_apobs setVelocity [0,0,0];
	_apobs_rocket = "ACE_APOBS_MK7MOD2_Rocket" createVehicle [0,0,0];
	_apobs_rocket attachTo [_apobs,[0,0,0],"rocket"];
	_apobs setVariable [QGVAR(rocket),_apobs_rocket,true];
	_apobs setPosATL _pos;
	_apobs setDir getDir player;
	_apobs setVariable [QGVAR(empty),false,true];
	_apobs setVariable [QGVAR(armed),false,true];
	_apobs setVariable [QGVAR(frontass),_front,true];
	_apobs setVariable [QGVAR(rearass),_rear,true];
	// TODO: progress bar
};

FUNC(disassembleAPOBS) = {
	private ["_front","_rear","_asPos","_bsPos"];
	PARAMS_1(_apobs);
	_pos = getPosATL _apobs;
	_dir = getDir _apobs;
	_front = _apobs getVariable QGVAR(frontass);
	_rear = _apobs getVariable QGVAR(rearass);
	_rocket = _apobs getVariable QGVAR(rocket);
	_asPos = _apobs selectionPosition "a";
	_bsPos = _apobs selectionPosition "b";
	_front setpos (_apobs modelToWorld _asPos);
	_front setDir _dir;
	_rear setpos (_apobs modelToWorld _bsPos);
	_rear setDir _dir;
	_front setVectorDirAndUp [[-0.0204803,-0.585819,0.810183],[0.00794978,-0.810423,-0.585792]];
	_rear setVectorDirAndUp [[-0.0204803,-0.585819,0.810183],[0.00794978,-0.810423,-0.585792]];
	deleteVehicle _rocket;
	deleteVehicle _apobs;
	// TODO: progress bar
};

FUNC(sight_addkey) = {
	GVAR(key_dn) = (findDisplay 46) displayAddEventHandler["KeyDown", '["KeyDown", _this] call FUNC(sight_event)'];
	GVAR(key_up) = (findDisplay 46) displayAddEventHandler["KeyUp", '["KeyUp", _this] call FUNC(sight_event)'];
};

FUNC(sight_remkey) = {
	(findDisplay 46) displayRemoveEventhandler ["KeyDown", GVAR(key_dn)];
	(findDisplay 46) displayRemoveEventhandler ["KeyUp", GVAR(key_up)];
};

FUNC(sight_rotate) = {
	PARAMS_3(_apobs,_direction,_pos);
	_z = [player] call CBA_fnc_realHeight; //account for placement above ground
	_pos set [2, _z];
	_rotation = 0;
	private ["_rotation"];
	if (_direction == "R") then { _rotation = 1 };
	if (_direction == "L") then { _rotation = -1 };
	_old_dir = direction _apobs;
	_new_dir = _old_dir + _rotation;
	_apobs setDir _new_dir;
	_apobs setPos _pos;	
};

FUNC(sight_event) = {
	PARAMS_2(_event,_parameters);
	if (GVAR(presstime) == time) exitwith {false};
	GVAR(presstime) = time;
	switch(_event) do {
		case "KeyDown": {
			_key = _parameters select 1;
			switch(_key) do {
				case 32: { GVAR(sight_right) = true; };
				case 30: { GVAR(sight_left) = true; };
				case 1:  { GVAR(peep_sight) = false; };
			};
		};
		case "KeyUp": {
			_key = _parameters select 1;
			switch(_key) do {
				case 32: { GVAR(sight_right) = false; };
				case 30: { GVAR(sight_left) = false; };
				case 1:  { GVAR(peep_sight) = false; };
			};
		};
	};
	!(GVAR(peep_sight))
};

FUNC(setupAPOBS) = {
	private ["_apobs","_pos","_z","_camera","_cameraPos"];
	_apobs = _this;
	if ((player call CBA_fnc_getUnitAnim) select 0 == "stand") then {
		player playMove "AmovPercMstpSrasWrflDnon_diary";
	};
	_pos = getPosATL _apobs;
	_z = [_apobs] call CBA_fnc_realHeight;
	_pos set [2,_z];	
	_camera = "camera" camCreate _pos;
	_camera cameraEffect ["internal", "back"];
	GVAR(sight_right) = false;
	GVAR(sight_left) = false;
	call FUNC(sight_addkey);
	GVAR(peep_sight) = true;
	GVAR(presstime) = 0;	

	while { GVAR(peep_sight) } do {
		if (GVAR(sight_right)) then { [_apobs, "R",_pos] call FUNC(sight_rotate); };
		if (GVAR(sight_left)) then { [_apobs, "L",_pos] call FUNC(sight_rotate); };
		_dir = getdir _apobs;
		_camera setDir _dir;
		_cameraPos = _apobs modelToWorld (_apobs selectionPosition "camera");
		_camera setPos _cameraPos;
		camUseNVG ace_sys_nvg_on;
		_camera camCommit 0.1;
		sleep 0.05;
	};	
	call FUNC(sight_remkey);
	_camera cameraEffect ["terminate", "back"];
	cutrsc ["default", "PLAIN DOWN"];
	camDestroy _camera;	
};

FUNC(rocketAPOBS_FX) = {
	private ["_smoketrail","_light"];
	#define __vol 1.0
	#define __wei 1.27
	#define __life 0.15

	_this spawn {
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
	[_this, "ACE_EjectionSeat"] spawn {
		private ["_vehicle", "_sound", "_positionCamera", "_positionVehicle"];
		_vehicle = _this select 0;
		_sound = _this select 1;
		_positionCamera = positionCameraToWorld [0, 0, 0];
		_positionVehicle = _vehicle modelToWorld [0, 0, 0];
		if ((_positionCamera distance _positionVehicle) < 150) then {
			_vehicle say _sound;
		};
	};
};

FUNC(clearanceAPOBS) = {
	PARAMS_2(_apobs,_posAPOBSR);
	private ["_posAPOBS","_dir","_distance","_count","_ratio","_c"];
	_posAPOBS = position _apobs;
	_dir = getDir _apobs;
	_posAPOBS set [0,(_posAPOBS select 0)+((sin _dir)*5)];
	_posAPOBS set [1,(_posAPOBS select 1)+((cos _dir)*5)];
	_distance = (_posAPOBS distance _posAPOBSR); //45;
	_count = 54; // Original has 108 grenades
	_ratio = _distance/_count;
	_apobs animate ["hide",1];
	for "_i" from 1 to _count do {
		_posAPOBSC = [(_posAPOBS select 0)+((sin _dir)*(_ratio*_i)),(_posAPOBS select 1)+((cos _dir)*(_ratio*_i)),0];
		_c = createVehicle ["ACE_DetCordLineGrenade", _posAPOBSC, [], 0, "CAN_COLLIDE"]; // TODO: Switch to trigger = can even kill wire // TODO: Make one big explosion (oval shaped?)
		sleep 0.001;
	};
};

FUNC(fireAPOBS) = {
	private ["_rocket","_dir","_vel","_t1","_pos"];
	PARAMS_1(_apobs);
	
	_apobs setVariable [QGVAR(APOBSarmed),true,true];
	_apobs spawn {
		_apobs = _this;
		sleep 15;
		_apobs setVariable [QGVAR(APOBSempty),true,true];
		_rocket = _apobs getVariable QGVAR(rocket);
		sleep 0.01;
		detach _rocket;
		_dir = getDir _apobs;
		_vel = [sin _dir * 15, cos _dir * 15,sin 45 * 15];
		[QGVAR(rocketAPOBS_FX), _rocket] call CBA_fnc_globalEvent;
		_t1 = time;
		while {(time - _t1) < 0.25} do {
			_rocket setVelocity _vel;
			sleep 0.01;
		};
		waitUntil { _rocket distance _apobs > 50 };
		_rocket setVelocity [0,0,0];
		waitUntil { (getpos _rocket select 2) < 1 };
		sleep 1;
		_pos = getPos _rocket;
		deleteVehicle _rocket;
		[_apobs,_pos] spawn FUNC(clearanceAPOBS);		
	};
};

ADDON = true;
