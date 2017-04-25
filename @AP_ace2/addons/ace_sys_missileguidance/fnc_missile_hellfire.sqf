////////////////////////////////////////////
//  ACE Hellfire Missile Guidance Thread  //
////////////////////////////////////////////
// By Q1184, zGuba, Sickboy 

// NOTE: Make sure to keep the private array up2date, especially due to required serialization and deserialization of the local variables.

// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __TRACKINTERVAL 0.005
#define __cfg configFile >> "CfgAmmo" >> typeOf _projectile

#define cMaxPitch 85
						// Degrees.
#define cMinPitch -85
					// Damping radius in degrees.
#define cDampingRadius 2
						// Sensor cone in degrees.
#define cSensorCone 70

// Flight Modes
              // LOBL Climb
#define cMODE_STEADY_CLIMB 0
              // LOAL-HI Climb
#define cMODE_HI_CLIMB 1
              // LOAL-LO Climb
#define cMODE_LO_CLIMB 2
              // Find a target
#define cMODE_LASERSEARCH 3
              // Direct dive
#define cMODE_ATTACKDIRECT 4
              // Pitch down
#define cMODE_PITCHDOWN 5
              // Ballistic
#define cMODE_BALLISTIC 999


PARAMS_8(_vehicle,_projectile,_flightMode,_longbow,_isPlayer,_tarData,_laserCode,_realprojectile);

// if !(_isPlayer || _longbow) exitWith {}; // perFrame

_handle = [
	{ /* run code */
		_deltaTime = time - _prevTime;
		_prevTime = time;
		_elapsedTime = _prevTime - _startTime;

		// Avoid unnatural turns  when scripting performance is really low.
		_cTurnRate = 140 * (_deltaTime min 0.25);	// (deg/sec) (Max Turn Rate)
		_cMaxTurnAccel = 18.0 * (_deltaTime min 0.25);	// (deg/sec/sec) (Max Turn Acceleration)

		// Rate of climb.
		_prevAlt = _curAlt;
		_curAlt = (getPosASL _projectile) select 2;
		_climb = (_curAlt - _prevAlt) * _deltaTime;

		// Projectile and target positions.
		_ppos = getPosASL _projectile;

		// Projectile speed (m/s)
			_projSpeed = (velocity _projectile) call ACE_fnc_magnitude;

		// Set new vector
		_dir = getDir _projectile;
		_vec = [sin(_dir) * cos(_pitch), cos(_dir) * cos (_pitch), sin (_pitch)];

		_vecToTarget = [sin(_initialDir), cos(_initialDir), 0];
		_distance = 9999;
		_gndDistance = 9999;

		if !(isNull _target) then {
			_tPos = [_target] call FUNC(getPosASL);	// Update only if _target exists
			if (!_tarIsVehicle && {_isPlayer} && {isNull _tarVeh}) then {
				// Fire incomingMissile for laser guided Hellfire
				// // TODO: Only 30 when not local! issue is network simulation, within 1km is fine, but beyond 2km seems to be problematic
				{ if !(_x isKindOf "StaticWeapon") exitWith { _tarVeh = _x } } forEach ((position _target) nearEntities [["LandVehicle", "Air", "Ship"],12]);
				if !(isNull _tarVeh || {_longbow}) then {
					// TODO: If it's really needed - perhaps redo it, until the projectile is within ~30m of target, so it at least updates...
					// if (_flightMode > 0 && !(local _target)) then { _target = _tarVeh }; // HACK for LOAL LaserTargets on vehicles on the move in Multiplayer..
					TRACE_4("Triggering incoming missile for",_tarVeh,_vehicle,_projectile,_flightMode);
					[QGVAR(global_ieh), [_tarVeh, typeOf _projectile, _vehicle, _projectile]] spawn CBA_fnc_globalEvent;
				};
			};

			// Calculate ground distance and normal distance.
			_distance = _projectile distance _tPos;

		//	if (_distance >= 9999) then	{
		//		_mode = cMODE_BALLISTIC;
		//	};	not so fast, the missile won't ever reach that range in ArmA

			_trackingTarget = true;
		};

		if (_trackingTarget) then {
			// Hellfire has target position memory, if laser gets burn out while flying on it it shouldn't break up
			_gndDistance = [_ppos select 0, _ppos select 1, 0] distance [_tPos select 0, _tPos select 1, 0];

			// Calculate actual vector to target.
			_vecToTarget = [(_tPos select 0) - (_ppos select 0), (_tPos select 1) - (_ppos select 1), (_tPos select 2) - (_ppos select 2)];
			_vecToTarget = _vecToTarget call FUNC(mat_normalize3d);
		};

		// Calculate eta
		_eta = _distance / _projSpeed;

		_vecToTarget_hmag = _vecToTarget call FUNC(mat_horizmag);
		_vec_hmag = _vec call FUNC(mat_horizmag);

		// Calc heading offset
		_headingOffset = (( _vecToTarget select 0) atan2 (_vecToTarget select 1)) - (( _vec select 0) atan2 (_vec select 1));
		if (_headingOffset > 180) then { _headingOffset = _headingOffset - 360; };
		if (_headingOffset < -180) then { _headingOffset = _headingOffset + 360; };

		// Calc pitch offset
		_pitchOffset = abs(_vecToTarget_hmag atan2 (_vecToTarget select 2)) - abs(_vec_hmag atan2 (_vec select 2));
		if (_pitchOffset > 180) then { _pitchOffset = _pitchOffset - 360; };
		if (_pitchOffset < -180) then { _pitchOffset = _pitchOffset + 360; };

		// *** FLIGHT MODES ***
		if (_mode != cMODE_BALLISTIC && {!isNull _target}) then {
			if ((abs(_pitchOffset) > cSensorCone) || {(abs(_headingOffset) > cSensorCone)}) then {
				if (_distance > 200) then {
					TRACE_1("Hellfire gone ballistic",_projectile);
					_mode = cMODE_BALLISTIC; // Go hard ballistic
				};
			};
		};

		// Show hit ETA for LOBL or Longbow Hellfire
		if ((_flightMode == 0 || {_longbow}) && {(_elapsedTime > 2.5)}) then {
			if (isNil {_vehicle getVariable "ACE_Missile_ETA"}) then {
				_vehicle setVariable ["ACE_Missile_ETA",_eta];
			} else {
				_vehicle setVariable ["ACE_Missile_ETA",_eta min (_vehicle getVariable "ACE_Missile_ETA")];
			};
		};

		switch _mode do {
			// Direct attack: Fly almost at the target with a slight deviation based on expected impact ETA.
			case cMODE_ATTACKDIRECT: {
				if (_eta > _pitchDownETA) then {
					_targetPitchOffset = _finalPitch;
				} else {
					_targetPitchOffset = _finalPitch * (_eta*_eta) / (_pitchDownETA*_pitchDownETA);
				};
				if (!(isNull _target) && {_longbow}) then {
					if (typeOf _target == "ACE_Target_FakeLongbow") then {
						_newPos = [(_tarPos select 0) + (_tarVel select 0)*_elapsedTime, (_tarPos select 1) + (_tarVel select 1)*_elapsedTime, (_tarPos select 2) + (_tarVel select 2)*_elapsedTime];
						TRACE_2("Moving fake longbow target", getPosASL _target, _newPos);
						_target setPosASL _newPos;
						_tarVeh = _target;
						{ if !(_x isKindOf "StaticWeapon") exitWith { _tarVeh = _x} } forEach nearestObjects [_target, [_tarType], 12];
						_target = _tarVeh;	// Will change only if target type did not changed
						_tPos = [_target] call FUNC(getPosASL);
						TRACE_2("Switched target?", typeOf _target, _tPos);
					};
				};
			};
			// Fly in a ballistic climb so that the missile can get altitude for a high angle hit.
			case cMODE_STEADY_CLIMB: {
				_targetPitchOffset = (10 + ((_gndDistance / 8000) * 20)) min 70;
				TRACE_2("Steady climb, ground distance",_projectile,_gndDistance);
				if (_gndDistance < 800) then {       // Switch modes when in proximity
					_profileStep = _profileStep + 1;
					_mode = _flightProfile select _profileStep;
					TRACE_2("Hellfire within 800 meters",_projectile,_gndDistance);
				};
			};
			case cMODE_LASERSEARCH: {
				_targetPitchOffset = 7 - _pitch; // Pitch to climb & search.
	
				_ownTarget = _vehicle getVariable [QGVAR(laserObject), objNull];

				// Search for targets. If Longbow Hellfire was fired without lock, then it's lost.
				_tlist = if !(isNull _target) then {
					if (typeOf _target == "ACE_Target_FakeLongbow") then {
						_newPos = [(_tarPos select 0) + (_tarVel select 0)*_elapsedTime, (_tarPos select 1) + (_tarVel select 1)*_elapsedTime, (_tarPos select 2) + (_tarVel select 2)*_elapsedTime];
						TRACE_2("Moving fake longbow target", getPosASL _target, _newPos);
						_target setPosASL _newPos;
						_tarVeh = _target;
						{ if !(_x isKindOf "StaticWeapon") exitWith { _tarVeh = _x} } forEach nearestObjects [_target, [_tarType], 12];
						_target = _tarVeh;	// Will change only if target type did not changed
						_tPos = [_target] call FUNC(getPosASL);
						TRACE_2("Switched target?", typeOf _target, _tPos);
					};
					[_target]
				} else {
					if (_longbow) then {
						[]
					} else {
						if !(isNil "ACE_LASERTARGET_ARRAY_INITIALIZED") then {
							ACE_LASERTARGET_ARRAY
						} else {
							[_ownTarget]
						};
					};
				};
				_targetFound = false;

				// Always prefer own target inside sensor cone
				if (count _tlist > 0) then {
					{
						// Determine if target is within our sensor cone.
						_xpos = [_x] call FUNC(getPosASL);
						_v = [(_xpos select 0) - (_ppos select 0), (_xpos select 1) - (_ppos select 1), (_xpos select 2) - (_ppos select 2)];
						_n = _v call FUNC(mat_normalize3d);
						_t = ((((_n select 0) atan2 (_n select 1)) - (( _vec select 0) atan2 (_vec select 1)) + 180) % 360) - 180;

						if (abs(_t) < cSensorCone) then {
							// jaynus change:
							// check to make sure it matches the current laserCode 
							// this basically forces lock-on to current set laser code, 
							// otherwise target is immidiately rejected
							// NOTE: This code doesnt get hit if its an ownTarget, that is still working permenant.
							_targetCode = _x getVariable "ACE_LASERTARGET_CODE";
							if(isNil "_targetCode") then {
								_targetCode = 1001;
								_x setVariable["ACE_LASERTARGET_CODE", _targetCode, false];
							};
							TRACE_4("Comparing codes", _projectile, _x, _laserCode, _targetCode);
							// Longbow always pass.
							if(_longbow || {_targetCode == _laserCode}) then {
								if (!_targetFound) then	{
									_target = _x; _targetFound = true;
									if !(isNull _target) then {_tPos = [_target] call FUNC(getPosASL)};
									_tarIsVehicle = _target isKindOf "AllVehicles";
									TRACE_1("Found Target",_target);
								} else {
									if ((_projectile distance _tPos) > (_projectile distance _x) || {(_x == _target)} || {(_x == _ownTarget)}) then	{
										TRACE_1("Changing Target?",_target);
										_target = _x;
										_tPos = [_target] call FUNC(getPosASL);
										_tarIsVehicle = _target isKindOf "AllVehicles";
									};
								};
							};
						} else {
							TRACE_5("Hellfire rejected target",_x,_v,_n,_t,cSensorCone)
						};
					} forEach _tlist;

					if (_targetFound) then {
						_profileStep = _profileStep + 1;
						_mode = _flightProfile select _profileStep;
						TRACE_2("Hellfire acquired target, tracking",_projectile,_target);
					};
				}; // If there were any targets, we'll have the closest here at the end.
			};

			case cMODE_LO_CLIMB: {
				_targetPitchOffset = 45 - _pitch; // Pitch to climb
				if ((_curAlt - _initialAlt) > 100) then {
					_profileStep = _profileStep + 1;
					_mode = _flightProfile select _profileStep;
					TRACE_1("Hellfire coming out of LO climb",_projectile);
				};
			};
			case cMODE_HI_CLIMB: {
				_targetPitchOffset = 45 - _pitch; // Pitch to climb
				if ((_curAlt - _initialAlt) > 300) then {
					_profileStep = _profileStep + 1;
					_mode = _flightProfile select _profileStep;
					TRACE_1("Hellfire coming out of HI climb",_projectile);
				};
			};
		};

		// Compute desired rotation for this frame.
		_headingOffsetAbs = abs(_headingOffset);
		_targetDeltaR = _cTurnRate;
		if (_headingOffsetAbs < cDampingRadius) then { _targetDeltaR = _cTurnRate * ((_headingOffsetAbs*_headingOffsetAbs) / (cDampingRadius*cDampingRadius)); };
		if (_headingOffset < 0) then { _targetDeltaR = -_targetDeltaR; };

		_pitchOffsetAbs = abs(_targetPitchOffset-_pitchOffset);
		_targetDeltaP = _cTurnRate;
		if (_pitchOffsetAbs < cDampingRadius) then { _targetDeltaP = _cTurnRate * ((_pitchOffsetAbs*_pitchOffsetAbs) / (cDampingRadius*cDampingRadius)); };
		if ((_targetPitchOffset-_pitchOffset) < 0) then { _targetDeltaP = -_targetDeltaP; };

		_turnAccel = _cMaxTurnAccel;
		_pitchAccel = _cMaxTurnAccel;

		// Recentering triple as fast to decrease zigzaging (very much like BIS 1.05 driving wheel control fix)
		if ((_deltaR < 0 && {_targetDeltaR >= 0}) || {(_deltaR > 0 && {_targetDeltaR <= 0})}) then {
			_turnAccel = 3 * _turnAccel;
		};
		if ((_deltaP < 0 && {_targetDeltaP >= 0}) || {(_deltaP > 0 && {_targetDeltaP <= 0})}) then {
			_pitchAccel = 3 * _pitchAccel;
		};

		// TRACKING
		if (_deltaR < _targetDeltaR) then {
			_deltaR = (_deltaR + _turnAccel) min _targetDeltaR;
		} else {
			if (_deltaR > _targetDeltaR) then {
				_deltaR = (_deltaR - _turnAccel) max _targetDeltaR;
			};
		};

		if (_deltaP < _targetDeltaP) then {
			_deltaP = (_deltaP + _pitchAccel) min _targetDeltaP;
		} else {
			if (_deltaP > _targetDeltaP) then {
				_deltaP = (_deltaP - _pitchAccel) max _targetDeltaP;
			};
		};

		// Enforce min/max deltas.
		_deltaR = (-_cTurnRate max _deltaR) min _cTurnRate;
		_deltaP = (-_cTurnRate max _deltaP) min _cTurnRate;

		// Rotate
		if (_mode != cMODE_BALLISTIC and _distance > 5) then {
			_dir = _dir + _deltaR;
			_pitch = _pitch + _deltaP;
		};

		// Enforce min/max pitch & direction.
		_pitch = (cMinPitch max _pitch) min cMaxPitch;
		if (_dir > 360) then { _dir = _dir - 360; };
		if (_dir < 0) then { _dir = _dir + 360; };

		// Recalc Vector - Yes, we can do a proper 3d vector rotation here and avoid gimbal
		// lock altogether, but our current ghetto-esque method is faster, and works as long as
		// our missile isn't ballistic.

		_vec = [sin(_dir) * cos(_pitch), cos(_dir) * cos (_pitch), sin (_pitch)] call FUNC(mat_normalize3d);

		_vDirX = _vec select 0;
		_vDirY = _vec select 1;
		_vDirZ = _vec select 2;

		_pitchComponent = cos(_pitch + 90);

		_vUpX = sin(_dir) * _pitchComponent;
		_vUpY = cos(_dir) * _pitchComponent;
		_vUpZ = sin(_pitch + 90);

		_vecUp = [_vUpX, _vUpY, _vUpZ] call FUNC(mat_normalize3d);

		_projectile setVectorDirAndUp [_vec, _vecUp];

		// This is here in case we need to manually set velocity
		_spd =  _projSpeed;
		TRACE_7("Hellfire on the way",_projectile,_spd,_curAlt,_distance,_target,typeOf _target,[_target] call FUNC(getPosASL));

		if (_mode != cMODE_BALLISTIC) then {
			_projectile setVelocity [_vDirX * _spd, _vDirY * _spd, _vDirZ * _spd];
		};
		
		if !((isNull _realprojectile) || {(_realprojectile == _projectile)}) then {
			_realprojectile setVelocity [0, 0, 0];
			_realprojectile setPosATL [_ppos select 0, _ppos select 1, 5000];
		};
	},
	_this, /* parameters */
	0, // delay
	{ /* init code */
		_vehicle = _this select 0;
		_projectile = _this select 1;
		_flightMode = _this select 2;
		_longbow = _this select 3;
		_isPlayer = _this select 4;
		_tarData = _this select 5;
		_laserCode = _this select 6; // hard-set laser code into the missile so guidance/lock is NOT updated after launch
		_realprojectile = _this select 7;
		
		
		TRACE_6("PARAMS_6",_vehicle,_projectile,_flightMode,_longbow,_isPlayer,_tarData);
		// Disabled for private issue - PARAMS_6(_vehicle,_projectile,_flightMode,_longbow,_isPlayer,_tarData);

	// PerFrame, please do the fancy job
	//	if !(_isPlayer || _longbow) exitWith {};

		_target = _tarData select 0;
		_tarType = _tarData select 1;
		_tarVel = _tarData select 2;
		_tarPos = _tarData select 3;

		_tarIsVehicle = _target isKindOf "AllVehicles";
		_deleteMe = objNull;
		if (_isPlayer && {!(isNull _target)}) then
		{
			// Fixme: Lame
			if (_target isKindOf "ACE_Target_FakeLongbow") then { _deleteMe = _target };
		};

		if (isNil "_flightMode") then { _flightMode = 0 };

		//_lbDone = false;	// wtf?


		// Hellfire flight profiles.
		_PROFILE_LOBL = [cMODE_LASERSEARCH, cMODE_STEADY_CLIMB, cMODE_ATTACKDIRECT, cMODE_BALLISTIC];	// it seems that both LOBL and LOAL-DIR are behaving the same way
		_PROFILE_LOAL_DIR = [cMODE_LASERSEARCH, cMODE_STEADY_CLIMB, cMODE_ATTACKDIRECT, cMODE_BALLISTIC];
		_PROFILE_LOAL_LO = [cMODE_LO_CLIMB, cMODE_LASERSEARCH, cMODE_STEADY_CLIMB, cMODE_ATTACKDIRECT, cMODE_BALLISTIC];
		_PROFILE_LOAL_HI = [cMODE_HI_CLIMB, cMODE_LASERSEARCH, cMODE_STEADY_CLIMB, cMODE_ATTACKDIRECT, cMODE_BALLISTIC];

		// Has to match guidance profile modes in other parts of this framework

		// LOBL by default
		_flightProfile = _PROFILE_LOBL;
		switch (_flightMode) do {
			case 1: {_flightProfile = _PROFILE_LOAL_DIR};
			case 2: {_flightProfile = _PROFILE_LOAL_LO};
			case 3: {_flightProfile = _PROFILE_LOAL_HI};
			default	{};
		};

		#ifdef DEBUG_MODE_FULL
			[_projectile] spawn ace_fnc_track;
		#endif

		_profileStep = 0;

		_ppos = getPosASL _projectile;
		_mvUp = vectorUp _projectile;
		_mvDir = vectorDir _projectile;
		_mvel = velocity _projectile;
		_projspeed = _mvel call ACE_fnc_magnitude;
		_tPos = [_target] call FUNC(getPosASL);

		// Missile flight parameters. Tweak for epic fail.
		_cTurnRate = 140 * __TRACKINTERVAL;		// (deg/sec) (Max Turn Rate)
		_cMaxTurnAccel = 18.0 * __TRACKINTERVAL;	// (deg/sec/sec) (Max Turn Acceleration)

		// Flight variable init
		_prevAlt = 0;						// Previously measured altitude
		_curAlt = 0;						// Currently measured altitude
		_climb = 0;							// Climb rate
		_pitch = 0;							// Pitch amount
		_dir = 0;							// Direction
		_spd = 0;							// Speed - redundant?
		_targetAlt = 0;						// TargetAltitude
		_turnAccel = 0;						// How fast we are accelerating rotation around the model's Z axis.
		_pitchAccel = 0;					// How fast we are accelerating rotation around the model's X axis.
		_deltaP = 0;						// Rotational speed around X axis.
		_deltaR = 0;						// Rotational speed around Z axis.
		_targetDeltaP = 0;					// Our desired rotational velocity for delta pitch.
		_targetDeltaR = 0;					// Our desired rotational velocity for delta rotation.
		_targetHeadingOffset = 0;			// Target offset for heading.
		_targetPitchOffset = 85;			// Target offset for pitch.
		_timer = 0;							// Timer - used in some modes.
		_setTime = 0;						// Time offset - used in some modes.
		_finalPitch = 5;			// LOAL is working sometimes :P
		_pitchDownETA = 2.5;				// ETA in seconds to begin final pitch to zero
		_eta = 0;							// eta
		_initialDir = getDir _projectile;	// Initial direction
		_initialAlt = _ppos select 2;
		_distance = 9999;
		_gndDistance = 9999;
		_vecToTarget = [0,0,0];
	//	_tPos = [0,0,0];
		_tarVeh = objNull;
		_trackingTarget = false;

		_initTime = getNumber (__cfg >> "initTime");
		_saf = getNumber (__cfg >> "sideairFriction");
		_th = getNumber (__cfg >> "thrust");
		_tht = getNumber (__cfg >> "thrusttime");

		// Initial Mode
		_mode = _flightProfile select _profileStep;

		// AI stuff
		if (isNil {_vehicle getVariable QGVAR(missile_array)}) then {
			_vehicle setVariable [QGVAR(missile_array), [_projectile]];
		} else {
			_missile_array = (_vehicle getVariable QGVAR(missile_array)) - [objNull];
			PUSH(_missile_array,_projectile);
			_vehicle setVariable [QGVAR(missile_array), _missile_array];
		};
		_startTime = time;
		_prevTime = _startTime - __TRACKINTERVAL;
	},
	{ /* exit code */
		// Reset ETA counter
		_vehicle setVariable ["ACE_Missile_ETA",nil];
		if !(isNull _deleteMe) then { deleteVehicle _deleteMe };
		if !(isNull _realprojectile) then {
			_realprojectile setVectorDirAndUp [_vec, _vecUp];
			if !(isNull _target) then {
				_projSpeed = (getNumber(configFile >> "CfgAmmo" >> typeOf _realprojectile >> "typicalSpeed")) max _projSpeed;
			};
			_realprojectile setVelocity [_vDirX * _projSpeed, _vDirY * _projSpeed, _vDirZ * _projSpeed];
			_realprojectile setPosASL _ppos;
		};
	},
	{ /* Run condition - default true */
		time - _prevTime > __TRACKINTERVAL
	},
	{isNull _projectile}, /* exit condition */
	[ /* Private variables, available throughout all states and conditions */
			"_vehicle","_projectile","_flightMode","_longbow","_isPlayer","_tarData","_realprojectile",
			"_target","_tarType","_tarVel","_tarPos","_tarIsVehicle","_deleteMe",
			"_mode",
			"_flightProfile","_PROFILE_LOBL","_PROFILE_LOAL_DIR","_PROFILE_LOAL_LO","_PROFILE_LOAL_HI",	"_profileStep",
			"_ppos","_mvUp","_mvDir","_mvel",
			"_cTurnRate","_cMaxTurnAccel",
			"_prevAlt","_curAlt","_climb","_pitch","_dir","_spd","_targetAlt",
			"_turnAccel","_pitchAccel","_deltaP","_deltaR","_targetDeltaP","_targetDeltaR","_targetHeadingOffset","_targetPitchOffset",
			"_timer","_setTime","_finalPitch","_pitchDownETA","_eta","_initialDir","_initialAlt",
			"_distance","_gndDistance","_vecToTarget","_tPos","_tarVeh","_trackingTarget",
			"_startTime","_prevTime","_elapsedTime","_deltaTime",
			"_projSpeed","_vec","_vecUp","_vecToTarget_hmag","_vec_hmag","_headingOffset","_pitchOffset","_headingOffsetAbs","_pitchOffsetAbs","_pitchComponent",
			"_missile_array","_tlist","_targetFound","_ownTarget","_xpos","_v","_n","_t",
			"_vDirX","_vDirY","_vDirZ","_saf","_th","_tht","_inittime","_tPos", "_laserCode", "_targetCode"
	]
] call cba_common_fnc_addPerFrameHandlerLogic;

_handle;
