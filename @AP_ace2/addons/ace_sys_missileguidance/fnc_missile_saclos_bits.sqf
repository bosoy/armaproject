///////////////////////////////////////////
//  ACE Optical Missile Guidance Thread  //
///////////////////////////////////////////
// SACLOS method - missile tries to stay in gunner's LOS to target
// by q1184
// zGuba
// Sickboy
// Rocko

// NOTE: Make sure to keep the private array up2date, especially due to required serialization and deserialization of the local variables.

// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfg configFile >> "CfgAmmo" >> _ammoType
#define __TRACKINTERVAL 0.025

#define __EXCEED_SPEED 70
#define __EXCEED_DIST 1000

FUNC(saclos_run_code) = {
	_deltaTime = time - _prevTime;
	_prevTime = time;
	_flighttime = time - _starttime;
//	_wind = wind;
	_vehicle setVariable [QGVAR(missile_flying), true];

	//certain error in line of sight position, creates a 'corridor' for the missile to wobble in
//	_curoffset = [(_offset select 0) + random _raderror - random _raderror, (_offset select 1) + random _raderror - random _raderror,_offset select 2];
	_curoffset = _offset;

	if !(_vehicle isKindOf "CAManBase") then {
		_vec = if (_aidEnd distance _aidBeg > 0) then {
			([visiblePositionASL _aidEnd, visiblePositionASL _aidBeg] call BIS_fnc_vectorDiff) call FUNC(mat_normalize3d)
		} else {
			if (_tracker in _weapons) then {_vehicle weaponDirection _tracker} else {_startData select 0}
		};
		if (_launchTest) then {
			_guidanceDir = [_vehicle, _vType, _vec, false, _turret] call FUNC(opt_limits);
			_realwdir = _guidanceDir select 0;
			_exceeded = if (_isPlayer) then {_guidanceDir select 1} else {false};
			_exceededAlready = _exceeded;
			_launchTest = false;
		} else {
			_guidanceDir = [_vehicle, _vType, _vec, true, _turret, _startdata] call FUNC(opt_limits);
			_realwdir = _guidanceDir select 0;
			_exceeded = if (_isPlayer) then {_guidanceDir select 1} else {false};
		};
	} else {
		_realwdir = _vehicle weaponDirection (secondaryWeapon _vehicle);
	};

	// a reference point on aiming line, in front of the sight
	_zero = visiblePositionASL _aidPoV;

	TRACE_8("",_aidPoV,_aidEnd,_aidBeg,_vec,_zero, _realwdir,_deltaTime,_dist);

	_pvel = velocity _projectile;

	_spd = _pvel call ACE_fnc_magnitude;

	// Limits exceeded, a bit easier way.
	if (!_exceeded && {!_exceededAlready} && {(alive _vehicle)}) then {
		if (_isPlayer) then {
			//missile pos, vel
			_ppos = visiblePositionASL _projectile;
			_vvel = velocity _vehicle;

			_target = _vehicle getVariable QGVAR(laserObject);
			_tPos = if (isNil "_target") then { _target = objNull; _vehicle getVariable QGVAR(opticalTarget) } else { visiblePositionASL _target };
			// Predicted zero position for next frame. Max 0.1 sec ahead!
			_nextzero = [(_zero select 0) + (_vvel select 0) * _deltaTime,(_zero select 1) + (_vvel select 1) * _deltaTime,(_zero select 2) + (_vvel select 2) * _deltaTime];
			#ifdef DEBUG_MODE_FULL
				_aimTest setPosASL _nextZero;
			#endif
			//distance from reference point to projectile
			_dist = _ppos distance _nextzero;

			TRACE_6("",_target,_tPos,_pPos,_vvel,_nextZero,_dist);

			//3D vector from reference point to missile
			_vectortomissile = [_ppos, _nextzero] call FUNC(mat_sub3Dvec);

			//predicting next los vector
			_t = [_wdirprev,_realwdir,_deltaTime,_vectortomissile,_dist,_vehicle] call FUNC(opt_predictvect);
			_wdir = _t select 0;

			_cos3d = [_wdir, _vectortomissile] call FUNC(mat_cos3Dvec);
			_rcdist = _cos3d*_dist;

			// point on aiming line where the normal from missile crosses it
			_rc = [(_wdir select 0)*_rcdist + (_nextzero select 0), (_wdir select 1)*_rcdist + (_nextzero select 1), (_wdir select 2)*_rcdist + (_nextzero select 2)];

			// Depending on framerate. SACLOS requires relatively quick reaction - too much error lag is unacceptable.
			_tdistcur = 1 max (_spd*(_deltaTime min 0.125)*2.5);

			// Shturm-V has 2 modes - rangefinded and direct. All in all it is still stupid SACLOS.
			// ToDo: lase only on demand.
			if (_shturm && {_isPlayer} && {!isNil {_vehicle getVariable QGVAR(laser_designation)}} && {(_dist > 100)}) then {
				if ((_rc distance _tPos) > 2*_spd) then {
					_ppos set [2, (_ppos select 2) - 5];	// - I think you're below LoS... - Tak tochno!
				} else {
					_shturm = false;	// Don't come back.
					_shturmDescending = true;
				};
			};
			if (_shturmDescending && {!_shturmDescended}) then {
				if (((_rc distance _tPos) > _spd)) then {
					_tdistcur = _rc distance _tPos;
					_ppos set [2, (_ppos select 2) - ((10*(_tdistcur/(2*_spd max 1)) - 5) max 0)];	// go down smooth
				} else {
					_shturmDescended = true;
				};
			};

			// a point on aiming line x m farther than remotecenter, temporary target for the missile
			_tpoint = [(_nextzero select 0) + (_wdir select 0)*(_tdistcur + _dist), (_nextzero select 1) +  (_wdir select 1)*(_tdistcur + _dist), (_nextzero select 2) + (_wdir select 2)*(_tdistcur + _dist)];

			// vector from missile to temp point, equals desired direction of the missile
			_desvec = [_tpoint,_ppos] call FUNC(mat_sub3Dvec);

			// Missile direction
			_dir = vectorDir _projectile;

			//Horiz missile direction
			_dirH = [_dir] call FUNC(mat_getvecdir);

			//difference between mis direction and desired missile orientation
			_anglediffH = [_desvec,_dir] call FUNC(mat_2vecanglediff);

			//applying turn speed limitation
			if (abs (_anglediffH) > _maxturnrateH*_deltaTime) then {
				_anglediffH = abs (_angleDiffH)*_maxturnrateH*_deltaTime/_angleDiffH;
			};

			//vertical missile direction
			_dir_Hmag = _dir call FUNC(mat_horizmag);
			_cosH_mtp = [[_desvec select 0,_desvec select 1],[(_dir select 0),(_dir select 1)]] call FUNC(mat_cos2Dvec);
			_desvec_hmag = (_desvec call FUNC(mat_horizmag))*_cosH_mtp;

			_dirV = [[_dir_hmag,(_dir select 2)]] call FUNC(mat_getvecdir);
			_anglediffV = [[_desvec_hmag,(_desvec select 2)],[_dir_hmag,(_dir select 2)]] call FUNC(mat_2vecanglediff);

			//applying turn speed limitation
			if (abs (_anglediffV) > _maxturnrateV*_deltaTime) then {
				_anglediffV = abs (_angleDiffV)*_maxturnrateV*_deltaTime/_angleDiffV;
			};

			// Angular error
			_anglediffH = [_anglediffH, _toler] call FUNC(mat_roundnumber);
			_anglediffV = [_anglediffV, _toler] call FUNC(mat_roundnumber);

			/*
			//if lag behind los has increased, apply max turn
			if (abs(_offH) > 1) then {
				if ((abs(_offH) - abs(_offHprev)) > 0) then {
					_anglediffH = abs (_angleDiffH)*_maxturnrateH*_deltaTime/_angleDiffH;
				};
			};
			if (abs(_offV) > 1) then {
				if ((abs(_offV) - abs(_offVprev)) > 0) then {
					_anglediffV = abs (_angleDiffV)*_maxturnrateV*_deltaTime/_angleDiffV;
				};
			};
			*/
			// *** setting stuff

			_newdirH = _dirH + _angleDiffH;
			_newdirV = _dirV + _angleDiffV;

			_vec = [sin(_newdirH) * sin(_newdirV), cos(_newdirH) * sin (_newdirV), cos (_newdirV)]; // call FUNC(mat_normalize3d);

			_vDirX = _vec select 0;
			_vDirY = _vec select 1;
			_vDirZ = _vec select 2;

			_pitchComponent = sin(_newdirV - 90);

			_vUpX = sin(_newdirH) * _pitchComponent;
			_vUpY = cos(_newdirH) * _pitchComponent;
			_vUpZ = cos(_newdirV - 90);

			_vecUp = [_vUpX, _vUpY, _vUpZ];// call FUNC(mat_normalize3d);

			_projectile setVectorDirAndUp [_vec,_vecUp];
/*	// TODO: Russian single-surface spinning missiles
			if (_bankSpeed != 0) then {
				private "_pitchBank";
				_pitchBank = _projectile call BIS_fnc_getPitchBank;
				[_projectile, (_pitchBank select 0), (_bankSpeed * _deltaTime * (_spd/_maxSpeed)) + (_pitchBank select 1)] call BIS_fnc_setPitchBank;
			};
*/
			_vVelX = _vDirX * _spd;
			_vVelY = _vDirY * _spd;
			_vVelZ = _vDirZ * _spd;

			_vel = [_vVelX, _vVelY, _vVelZ];

			//[format ["spd %1 rspd %6 dir %2 vup %3 dist %4 max %5",_spd,[_vdirx,_vdiry,_vdirz],[_vupx,_vupy,_vupz],_projectile distance player,_maxrange,_pvel call ACE_fnc_magnitude]] call cba_fnc_debug;

			_projectile setVelocity _vel;
			TRACE_3("NOT Exceeded",_vel,_spd,_vecUp);
		} else {
			_dir = if (isDedicated) then {[0,0,-1]} else {vectorDir _projectile};
			_up = if (isDedicated) then {[0,1,0]} else {vectorUp _projectile};

			// Carrier killed
			if !((alive _vehicle) && {((_vehicle getVariable "ace_canshoot") || {(isNil {_vehicle getVariable "ace_canshoot"})})}) then {
				_exceededAlready = true;
				TRACE_1("Aborting. Killed",_projectile);
			};
			// TODO: Verify, is good? Maybe should make object (vehicle who is jamming), or array of vehicles jamming?
			if (_vehicle getVariable "ACE_jammed") then {
				_exceededAlready = true;
				TRACE_1("Aborting. Jammed",_projectile);
			};
		};
	} else {
		// Computing fail when exceeded or jammed
		_exceededAlready = true;

		// Allow speeding up
		_vel = velocity _projectile;

		if !(_isPlayer) then {
			_projectile setVectorDirAndUp [_dir,_up];
		};

		// Velocity

		_vVelX = _vel select 0;
		_vVelY = _vel select 1;
		_vVelZ = _vel select 2;
		
		_vel = [_vVelX, _vVelY, _vVelZ - (_grav * _deltaTime)];

		_projectile setVelocity _vel;

		TRACE_1("Exceeded",_projectile);
	};

	//[format ["dir %1 pitch %2 turnH %3 turnV %4 angldifH %5 angldifV %6 vdir %7 vUp %8",_newdir,_newpitch, _turnH,_turnV, _diffH,_diffV,_vec,[_vupx,_vupy,_vupz]]] call ACE_fDebug;
	_wdirprev = _realwdir;

	// TODO: Account for incomingMissile on weapons that still have "Right click lock on" enabled.
	if (_isPlayer && {(isNull _tarVeh)} && {!isNil "_tPos"} && {!isNull _target}) then {
		// Using laserObject again because opticalTarget is ASL!
		{ if !(_x isKindOf "StaticWeapon") exitWith { _tarVeh = _x } } forEach ((position _target) nearEntities [["LandVehicle", "Air", "Ship"],12]);

		// Fire incomingMissile for wire
		if !(isNull _tarVeh) then {
			TRACE_3("Triggering incoming missile for",_tarVeh,_vehicle,_projectile);
			[QGVAR(global_ieh), [_tarVeh, typeOf _projectile, _vehicle, _projectile]] spawn CBA_fnc_globalEvent;
		};
	};

	if (_dist > _maxRange) then {
		TRACE_2("Aborting. Max range",_dist,_maxRange);
		_exceededAlready = true;
	} else {
		if (_dist > __EXCEED_DIST && {_spd < __EXCEED_SPEED}) then {
			TRACE_4("Aborting. Too slow",_dist,__EXCEED_DIST,_spd,__EXCEED_SPEED);
			_exceededAlready = true;
		};
	};
};
FUNC(saclos_init_code) = {
	_vehicle = _this select 0;
	_projectile = _this select 1;
	_ammoType = _this select 2;
	_guidance = _this select 3;
	_weapon = _this select 4;
	_target = _this select 5;
	_turret = _this select 6;
	_isPlayer = _this select 7;
	TRACE_8("PARAMS_8",_vehicle,_projectile,_ammotype,_guidance,_weapon,_target,_turret,_isPlayer);
	// Disabled for private issue - PARAMS_8(_vehicle,_projectile,_ammotype,_guidance,_weapon,_target,_turret,_isPlayer);

	_shturm = false;
	_tarVeh = objNull;

	_vType = typeOf _vehicle;
	_pov = if (_vehicle isKindOf "CAManBase") then {"launcher"} else {getText (_turret >> "memoryPointGunnerOptics")};
	_gunBeg = getText (_turret >> "gunBeg");
	_gunEnd = getText (_turret >> "gunEnd");
	_tracker = getText (_turret >> QGVAR(tracker));	// if _vec call ACE_fnc_magnitude == 0

	_weapons = weapons _vehicle;

	_startdata = [vectorDir _vehicle, vectorUp _vehicle];
	_pos = visiblePositionASL _projectile;
	_dir = vectorDir _projectile;
	_up = vectorUp _projectile;
	_vel = velocity _projectile;

	if (_guidance == "shturm") then {_shturm = true};

	#ifdef DEBUG_MODE_FULL
		[_projectile] spawn ace_fnc_track;
		_aimTest = "ACE_LogicDummy" createVehicleLocal [0,0,0];
		[_aimTest] spawn ace_fnc_track;

	#endif

	// Tracer FX / TOW FX /Smoke FX - disable for Dragon when up!
	[QGVAR(global_towsmoke), [_projectile, _ammotype]] spawn CBA_fnc_globalEvent;

	_aidPoV = objNull;
	_aidBeg = objNull;
	_aidEnd = objNull;
	
	_aidsInPlace = false;

	_aidPoV = "ACE_LogicDummy" createVehicleLocal [0,0,0];
	_aidBeg = "ACE_LogicDummy" createVehicleLocal [0,0,0];
	_aidEnd = "ACE_LogicDummy" createVehicleLocal [0,0,0];

	// Attachment problems
	_aidPoV attachTo [_vehicle,[0,0,0],_pov];
	_aidBeg attachTo [_vehicle,[0,0,0],_gunBeg];
	_aidEnd attachTo [_vehicle,[0,0,0],_gunEnd];

	_maxturnrateH = getNumber (__cfg >> "ace_maxturnrateH");
	_maxturnrateV = getNumber (__cfg >> "ace_maxturnrateV");
	_bankSpeed = getNumber (__cfg >> "ace_bankSpeed");	// Bank speed in angles per second @ maximum speed
	_maxSpeed = (getNumber (__cfg >> "maxSpeed")) max 1;
	//_tdist = getNumber (__cfg >> "ace_correctiondist"); 		// distance on LOS from missile to the temp 'target', m
	_airFriction = getNumber (__cfg >> "airFriction");
	_initTime1 = getNumber (__cfg >> "initTime");
	_initTime2 = getNumber (__cfg >> "ace_guidance_initTime");
	_initTime = if (_initTime2 > 0) then {_initTime2} else {_initTime1};
	_saf = getNumber (__cfg >> "sideairFriction");
	_th = getNumber (__cfg >> "thrust");
	_tht = getNumber (__cfg >> "thrusttime");
	_flighttime = 0;
	_starttime = time;
	_toler = 0;
	if (_isPlayer) then {_toler = getNumber (__cfg >> "ace_angletoler")}; 		// angular tolerance/accuracy, deg (if calculated correction in course/pitch is lower, it's not applied)
	//_raderror = getNumber (__cfg >> "ace_raderror"); 		// radius of the 'corridor' around LOS
	_maxRange = getNumber (__cfg >> "maxControlRange");
	_exceeded = false;
	_exceededAlready = false;
	_shturmDescended = false;
	_shturmDescending = false;
	//_supercontrol = getNumber (__cfg >> "ace_supercontrol");
	_supercontrol = 0;
	_offset = [0,0,0];
	_initoffset = [0,0,1];
	_dist = 0;
	_grav = 9.81; // m/s^2
	_wdirprev = vectorDir _projectile;
	_spd = _vel call ACE_fnc_magnitude;
	_offHprev = 0;
	_offVprev = 0;

	_vehicle setVariable [QGVAR(saclos_cur), [_wdirprev,0,0,0,0]];
	[_vehicle,_projectile] spawn FUNC(opt_avg_wdir);

	if (isNil {_vehicle getVariable QGVAR(missile_array)}) then {
		_vehicle setVariable [QGVAR(missile_array), [_projectile]];
	} else {
		_missile_array = (_vehicle getVariable QGVAR(missile_array)) - [objNull];
		_missile_array set [count _missile_array,_projectile];
		_vehicle setVariable [QGVAR(missile_array), _missile_array];
	};

	_launchTest = true;
	TRACE_2("Initial",_vel,_spd);

	_prevTime = time + _initTime - __TRACKINTERVAL;
};
FUNC(saclos_exit_code) = {
	{deletevehicle _x} forEach [_aidPoV,_aidBeg,_aidEnd];

	// Cleanup
	_missile_array = (_vehicle getVariable QGVAR(missile_array)) - [objNull];
	_vehicle setVariable [QGVAR(missile_array), _missile_array];
	_vehicle setVariable [QGVAR(missile_flying), nil];

	// Last missile closes the door
	if ((count _missile_array) == 0) then {
		if (isNil {_vehicle getVariable QGVAR(laser_designation)}) then {
			_vehicle setVariable [QGVAR(laser_off), true];
		};
	};
};
FUNC(saclos_run_condition) = {
	_r = false;
	if (time - _prevTime > __TRACKINTERVAL) then {
		if !(_aidsInPlace) then {
			if (_aidEnd distance _vehicle < 10) then {
				if (_aidBeg distance _vehicle < 10) then {_aidsInPlace = _aidPoV distance _vehicle < 10};
			};
		};
		_r = _aidsInPlace;
	};
	_r;
};
FUNC(saclos_exit_condition) = {isNull _projectile};
GVAR(saclos_private_variables) = [ /* Private variables, available throughout all states and conditions */
		"_vehicle", "_projectile", "_ammotype", "_guidance", "_weapon", "_target", "_turret", "_isPlayer", "_startdata",
		"_exceeded","_exceededAlready","_launchTest",
		"_shturm","_shturmDescending","_shturmDescended",
		"_missile_array", "_weapons", "_tracker",
		"_deltaTime","_prevTime",
		"_pos","_dir","_up","_vel",
		"_pov","_gunBeg","_gunEnd","_initoffset","_offset","_curoffset",
		"_aidPoV","_aidBeg","_aidEnd","_zero","_nextzero","_wdir","_wdirprev","_realwdir","_t",
		"_airFriction","_grav","_bankSpeed","_maxSpeed","_maxRange",
		"_maxturnrateH","_maxturnrateV","_supercontrol","_toler","_raderror","_initTime",
		"_ppos","_pvel","_vvel","_spd",
		"_vectortomissile","_desvec","_desvec_hmag","_cosH_mtp",
		"_cos3d","_rc","_rcdist","_tpoint",
		"_dist","_tdist","_tdistcur",
		"_dir","_dirH","_dirV","_dir_hmag",
		"_anglediffH","_anglediffV",
		"_newdirH","_newdirV",
		"_vec","_vDirX","_vDirY","_vDirZ","_vUpx","_vUpY","_vUpZ","_vecUp",
		"_offH","_offV","_offHprev","_offVprev",
		"_vType", "_tarVeh", "_tPos","_saf","_th","_tht","_flighttime","_starttime",
		"_aimTest","_aidsInPlace"
];
