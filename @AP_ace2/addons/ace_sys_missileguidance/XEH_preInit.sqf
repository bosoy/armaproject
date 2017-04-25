#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(fired);
PREP(incomingMissile);
PREP(towsmoke);
PREP(laser_init);

PREP(missile_hellfire);
PREP(missile_hellfire2);
PREP(missile_javelin);
PREP(missile_saclos_bits);
PREP(missile_saclos);
PREP(missile_lgb);
PREP(missile_lgb_track);
PREP(missile_Kh29);
PREP(missile_Kh29_track);

PREP(mat_applyRotation);
PREP(mat_buildRotationMatrix);
PREP(mat_horizmag);
PREP(mat_normalize3d);
PREP(mat_cos2Dvec);
PREP(mat_cos3Dvec);
PREP(mat_sub3Dvec);
PREP(mat_getvecdir);
PREP(mat_2vecanglediff);
PREP(mat_roundnumber);
PREP(mat_turn3Dvec);
PREP(mat_turnvecdirup);

PREP(opt_predictvect);
PREP(opt_avg_wdir);
PREP(opt_losoffset);
PREP(opt_laserloop);
PREP(opt_laserloop_pfh);
PREP(opt_limitloop);
PREP(opt_limits);

PREP(worldtoscreen_bounds);

PREP(Gunship_keyPressed);
PREP(Javelin_keyPressed);
PREP(LongbowMapTarget_keyPressed);

PREP(Kh29_Lase);
PREP(Kh29_Limits);
PREP(Kh29_keyPressed_lase);
PREP(Kh29_lasepfh);

PREP(dragon_fired);

PREP(target_javelin);

FUNC(getPosASL) = {visiblePositionASL (_this select 0)};

FUNC(global_ieh) = { _this spawn SLX_XEH_EH_IncomingMissile };

FUNC(global_towsmoke) = {
	PARAMS_2(_mis,_ammotype);
	[_mis,_ammotype] spawn FUNC(towsmoke);
};

FUNC(longbowTarget_clear) = {
	PARAMS_1(_vehicle);
	_vehicle setVariable [QGVAR(longbowTarget), nil];
	{deletevehicle _x} forEach ace_sys_missileguidance_maptargets;
	ace_sys_missileguidance_maptargets = [];
};

if (!isDedicated) then {
	FUNC(block_keys) = {
		((_this select 1) in actionKeys ("ForceCommandingMode") && {(currentWeapon player == secondaryWeapon player)} && {(currentWeapon player != "")})
	};
};

[QGVAR(global_ieh), {_this call FUNC(global_ieh)}] call CBA_fnc_addEventHandler;
if (!isDedicated) then {
	[QGVAR(global_towsmoke), {_this call FUNC(global_towsmoke)}] call CBA_fnc_addEventHandler;
};

GVAR(presstime_Kh29) = 0;
GVAR(Kh29_lasinginprogress) = false;

if (!isDedicated) then {
	[QUOTE(ADDON), "Lase_Kh29", { [] call FUNC(Kh29_keyPressed_lase)}] call CBA_fnc_addKeyHandlerFromConfig;
	[QUOTE(ADDON), "Lase_Gunship", { _this call FUNC(Gunship_keyPressed)}] call CBA_fnc_addKeyHandlerFromConfig;
	[QUOTE(ADDON), "Javelin_Mode", { _this call FUNC(Javelin_keyPressed)}] call CBA_fnc_addKeyHandlerFromConfig;
	[QUOTE(ADDON), "Longbow_Map", { _this call FUNC(LongbowMapTarget_keyPressed)}] call CBA_fnc_addKeyHandlerFromConfig;

	["KeyDown", QUOTE(_this call FUNC(block_keys))] call CBA_fnc_addDisplayHandler;
};

ace_laser_object = objNull;
ace_sys_missileguidance_maptargets = [];

[] call FUNC(missile_saclos_bits);

GVAR(checkedDesignators) = [] call CBA_fnc_hashCreate;

FUNC(seekerRegisterTargetState) = {
	_designator = _this select 0;
	_seeker = _this select 1;
	_state = _this select 2;
	// player sideChat format["ff"];
	_interval = 1;
	if(!([GVAR(checkedDesignators), _seeker] call CBA_fnc_hashHasKey)) then {
		[GVAR(checkedDesignators), _seeker, ([] call CBA_fnc_hashCreate)] call CBA_fnc_hashSet;
	};
	_designatorHash = [GVAR(checkedDesignators), _seeker] call cba_fnc_hashGet;
	if(!([_designatorHash, _designator] call CBA_fnc_hashHasKey)) then {
		[_designatorHash, _designator, [time-_interval, false, LASER_LOS_STAGE_PULSE, _pos1, _pos2, -1, nil, _designator]] call CBA_fnc_hashSet;
	};
	_desInfo = [_designatorHash, _designator] call cba_fnc_hashGet;
	_desInfo set[1, _state];
};

FUNC(pulseLosCheck) = {
	private ["_designator", "_seeker", "_pos1", "_pos2", "_interval", "_desInfo", "_time", "_found", "_stage", "_return", "_loopId"];
	
	_pos1 = _this select 0;
	_pos2 = _this select 1;
	_designator = _this select 2;
	_seeker = _this select 3;
	// player sideChat format["ff"];
	_interval = 1;
	if(!([GVAR(checkedDesignators), _seeker] call CBA_fnc_hashHasKey)) then {
		[GVAR(checkedDesignators), _seeker, ([] call CBA_fnc_hashCreate)] call CBA_fnc_hashSet;
	};
	_designatorHash = [GVAR(checkedDesignators), _seeker] call cba_fnc_hashGet;
	if(!([_designatorHash, _designator] call CBA_fnc_hashHasKey)) then {
		[_designatorHash, _designator, [time-_interval, false, LASER_LOS_STAGE_PULSE, _pos1, _pos2, -1, nil, _designator]] call CBA_fnc_hashSet;
	};
	_desInfo = [_designatorHash, _designator] call cba_fnc_hashGet;
	_time = _desInfo select 0;
	_found = _desInfo select 1;
	_stage = _desInfo select 2;
	_loopId = _desInfo select 5;
	// player sideChat format["des info: %1", _desInfo];
	_return = _found;
	switch (_stage) do {
		case LASER_LOS_STAGE_PULSE: {
			if(time > _time+_interval) then {
				// player sideChat format["start"];
				_desInfo set[3, _pos1];
				_desInfo set[4, _pos2];
				_loopId = [FUNC(losPulseLoop), 0, _desInfo] call CBA_fnc_addPerFrameHandler;
				_desInfo set[5, _loopId];
			};
		};
		case LASER_LOS_STAGE_FINDING: {
			if(time > _time+_interval) then {
				// player sideChat format["find"];
				_desInfo set[2, LASER_LOS_STAGE_PULSE];
				[_loopId] call CBA_fnc_removePerFrameHandler;
			};
		};
		case LASER_LOS_STAGE_END: {
			// player sideChat format["end"];
			if(time > _time+_interval) then {
				_desInfo set[2, LASER_LOS_STAGE_PULSE];	
			};
		};
	};
	_return
};

FUNC(losPulseLoop) = {
	private ["_params", "_time", "_found", "_stage", "_pos1", "_pos2", "_loopId", "_pulse", "_designator",
			"_vectorTo", "_speed", "_range", "_pulsePos"];
	_params = _this select 0;
	// player sideChat format["p: %1", _params];
	_time = _params select 0;
	_found = _params select 1;
	_stage = _params select 2;
	_pos1 = _params select 3;
	_pos2 = _params select 4;
	_loopId = _params select 5;
	_pulse = _params select 6;
	_designator = _params select 7;
	
	switch (_stage) do {
		case LASER_LOS_STAGE_PULSE: {
			_vectorTo = [_pos1, _pos2] call ACE_fnc_vectorFromXToY;
			_speed = 600000;
			_spawnPos = [(_pos1 select 0) + (_vectorTo select 0)*15, (_pos1 select 1) + (_vectorTo select 1)*15, (_pos1 select 2) + (_vectorTo select 2)*15];
			_pulse = "ACE_MissileGuidance_LaserPulse" createVehicleLocal [0,0,1000];
			_pulse setPosASL _spawnPos;
			_range = 0;
			_pulse setVelocity [(_vectorTo select 0) * _speed, (_vectorTo select 1) * _speed, (_vectorTo select 2) * _speed];
			_params set[6, _pulse];
			_params set[0, time];
			_params set[2, LASER_LOS_STAGE_FINDING];
		};
		case LASER_LOS_STAGE_FINDING: {
			if(!(isNull _pulse)) then {
				_pulsePos = getPosASL _pulse;
				_range = _pulsePos distance _pos1;
				// player sideChat format["range: %1", _range];
				if ((_range > 25) && {(_range < 9999)}) then {
					_desRange = _pulsePos distance _pos2;
					// player sideChat format["desDis: %1", _desRange];
					if(_desRange <= (1+(_range*0.002))) then {
						_params set[1, true];
					} else {
						_params set[1, false];
					};
				} else {
					_params set[1, false];
					deleteVehicle _pulse;
				};
				_params set[2, LASER_LOS_STAGE_END];
			} else {
				_params set[6, nil];
				_params set[2, LASER_LOS_STAGE_PULSE];				
			};
			deleteVehicle _pulse;
			[(_this select 1)] call cba_fnc_removePerFrameHandler;
		};
	};
};

// LoS to Javelin target
FUNC(JavelinLosOccluded) = {
	private ["_pos1","_pos2"];
	_pos1 = aimPos (_this select 0);
	_pos2 = eyePos (_this select 1);
	if (terrainIntersectASL [_pos1,_pos2]) then {
		true
	} else {
		lineIntersects [_pos1,_pos2,_this select 0,_this select 1]
	};
};
	
FUNC(checkLos) = {
	private ["_pos1", "_pos2", "_spacing", "_vectorTo", "_x", "_y", "_z", "_distance", "_count", "_return", "_alt", "_pos", "_designator", "_seeker"];
	_pos1 = _this select 0;
	_pos2 = _this select 1;
	_designator = _this select 2;
	_seeker = _this select 3;
	_spacing = 100;
	if((count _this) > 4) then {
		_spacing = _this select 4;
	};
	
	_return = true;
	_vectorTo = [_pos2, _pos1] call ACE_fnc_vectorFromXToY;
	
	_x = (_vectorTo select 0)*0.25;
	_y = (_vectorTo select 1)*0.25;
	_z = (_vectorTo select 2)*0.25;
	
	_pos2 = [(_pos2 select 0) + _x, (_pos2 select 1) + _y, (_pos2 select 2) + _z];
	
	// player sideChat format["new los check"];
	if(terrainIntersect [_pos2, _pos1]) then {
		_return = false;
	} else {
		if(lineIntersects [_pos2, _pos1]) then {	// should take as arguments and add to this command objects to exclude - target and observer
			// player sideChat format["with: %1", lineIntersectsWith [_pos1, _pos2]];
			_return = false;
		};
	};
	_return;
};

FUNC(findLaserDesignator) = {
	private ["_missile", "_headingPitch", "_found", "_vectorTo", "_polarTo", "_dir", "_vertOk", "_horzOk", "_fov",
			 "_closestDistance", "_pos1", "_pos2", "_disCheck", "_currentTarget", "_potentialTargets", "_offset", "_vector"];
	_missile = _this select 0;
	_laserCode = _this select 1;
	_fov = if (count _this > 2) then {_this select 2} else {75};
	_vector = if (count _this > 3) then {_this select 3} else {vectorDir _missile};
	_offset = if (count _this > 4) then {_this select 4} else {[0,0,0]};
	
	_headingPitch = _vector call CBA_fnc_vect2polar;	
	_currentTarget = nil;
	_found = false;
	if(!(isNil "ACE_LASERTARGET_ARRAY")) then {
		_potentialTargets = [];
		{
			if(!(isNull _x)) then {
				_sensorPos = ATLtoASL(_missile modelToWorld _offset);
				_vectorTo = ([_sensorPos, ([_x] call FUNC(getPosASL))] call ACE_fnc_vectorFromXToY);
				_polarTo = _vectorTo call CBA_fnc_vect2polar;
				_dir = _polarTo select 1;
				_dir = _dir - (_headingPitch select 1);
				if (_dir < 0) then {_dir = _dir + 360};
				if (_dir > 360) then {_dir = _dir - 360};
				_vertOk = false;
				_horzOk = false;
				if(_dir < _fov || {_dir > (360-_fov)}) then {
					_horzOk = true;
				};
				if(abs((abs(_polarTo select 2))-(abs(_headingPitch select 2))) < _fov) then {
					_vertOk = true;
				};
				if(_vertOk && {_horzOk}) then {
					// Does the laser currently have our current code, if we have one?
					_targetCode = _x getVariable ["ACE_LASERTARGET_CODE", 1001];
					if(_targetCode == _laserCode) then {
						_potentialTargets set[(count _potentialTargets), _x];
					};
				};
			};
		} forEach ACE_LASERTARGET_ARRAY;
		_closestDistance = 100000;
		{
			_pos1 = (getPosASL _missile);
			_pos2 = ([_x] call FUNC(getPosASL));
			_disCheck = _pos1 distance _pos2;
			// shouldn't this bail out when a valid target is found instead of iterating over all potential targets ?
			if(_disCheck < _closestDistance && {[_pos1, _pos2, _x, _missile] call FUNC(checkLos)}) then {
				_found = true;
				_currentTarget = _x;
				_closestDistance = _disCheck;
			};
		} forEach _potentialTargets;
	};
	[_found, _currentTarget]
};

cba_fnc_modelToWorldASL = {	// why here and not in CBA instead?
	private ["_model", "_selection", "_pos", "_alt"];
	_model = _this select 0;
	_selection = _this select 1;
	_pos = [];
	if(IS_ARRAY(_selection)) then {
		_pos = _model modelToWorld _selection;
	} else {
		_pos = _model modelToWorld (_model selectionPosition _selection);
	};
	_alt = getTerrainHeightASL [_pos select 0, _pos select 1];
	_pos set[2, (_pos select 2)+_alt];
	_pos
};

FUNC(handOffGuidance) = {
	private ["_missile", "_laserObject", "_function", "_params", "_missileIndex", "_timing", "_return",
			"_owner", "_pos", "_velocity", "_vectorDir", "_vectorUp", "_laserCode", "_typeOf", "_handOffParams"];
	_missile 		= _this select 0;
	_laserObject 	= _this select 1;
	_function 		= _this select 2;
	_params 		= _this select 3;
	_missileIndex	= _this select 4;
	_timing			= _this select 5;
	_return = false;
	_owner = _laserObject getVariable "ace_RF_owner";
	if(!isNil "_owner" && {_owner != player}) then {
		_pos = getPosASL _missile;
		_velocity = velocity _missile;
		_vectorDir = vectorDir _missile;
		_vectorUp = vectorUp _missile;
		_laserCode = _missile getVariable ["ACE_LASERTARGET_CODE", 1001];
		_typeOf = typeOf _missile;
		_handOffParams = [
							_owner,
							_pos,
							_velocity,
							_vectorDir,
							_vectorUp,
							_laserCode,
							_typeOf,
							_function,
							_params,
							_missileIndex,
							_timing
						];
		_return = true;
		["ace_guidancehandoff", _handOffParams] call ACE_fnc_receiverOnlyEvent;
	};
	_return
};

FUNC(handleGuidanceHandOff) = {
	private ["_owner", "_pos", "_velocity", "_vectorDir", "_vectorUp", "_laserCode", "_typeOf",
		"_function", "_params", "_mIndex", "_timing", "_missile"];
	_owner 		= _this select 0;
	_pos 		= _this select 1;
	_velocity 	= _this select 2;
	_vectorDir	= _this select 3;
	_vectorUp	= _this select 4;
	_laserCode	= _this select 5;
	_typeOf		= _this select 6;
	_function	= _this select 7;
	_params		= _this select 8;
	_mIndex		= _this select 9;
	_timing 	= _this select 10;
	
	_missile = _typeOf createVehicle [0,0,10000];
	_missile setPosASL _pos;
	_missile setVectorDirAndUp [_vectorDir, _vectorUp];
	_missile setVelocity _velocity;
	
	_missile setVariable ["ACE_LASERTARGET_CODE", _laserCode];
	[_missile] call ace_sys_frag_fnc_addManualTrack;
	_params set[_mIndex, _missile];
	
	[] call (compile format["ACE_HANDOFF_FNC = %1", _function]);

	[ACE_HANDOFF_FNC, _timing, _params] call CBA_fnc_addPerFramehandler;
	
	
};

["ace_guidancehandoff", {_this call FUNC(handleGuidanceHandOff)}] call ACE_fnc_addReceiverOnlyEventhandler;

ADDON = true;
