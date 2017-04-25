////////////////////////////////////////////
//  ACE Javelin Missile Guidance Thread   //
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

// Flight Modes
              // Direct Climb
#define cMODE_DIRECT_CLIMB 0
              // Top Climb
#define cMODE_TOP_CLIMB 1
              // Top Level
#define cMODE_TOP_LEVEL 2
              // Dive
#define cMODE_TERMINAL 3
              // Ballistic
#define cMODE_BALLISTIC 999


PARAMS_5(_vehicle,_projectile,_flightMode,_target,_isPlayer,_realprojectile);

_handle = [
	{ /* run code */
		_deltaTime = time - _prevTime;
		_prevTime = time;

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

		_tpos = if (isNull _target) then {_tpos} else {[_targetlogic] call FUNC(getPosASL)};
		if !(isNull _target) then {
			// Calculate ground distance and normal distance.
			_distance = _projectile distance _tpos;

			// Javelin has target position memory, if target disappears while flying on it it shouldn't break up
			_gndDistance = [_ppos select 0, _ppos select 1, 0] distance [_tpos select 0, _tpos select 1, 0];

			// Calculate actual vector to target.
			_vecToTarget = [(_tpos select 0) - (_ppos select 0), (_tpos select 1) - (_ppos select 1), (_tpos select 2) - (_ppos select 2)];
			_vecToTarget = _vecToTarget call FUNC(mat_normalize3d);
		};

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
		switch _mode do {
			case cMODE_DIRECT_CLIMB: {
				_targetPitchOffset = 60 - _pitch; // Pitch to climb
				if (((_curAlt - _initialAlt) > _climbDirect) || {(_gndDistance < (2 * _initDistance / 5))}) then {
					_profileStep = _profileStep + 1;
					_mode = _flightProfile select _profileStep;
					TRACE_1("Javelin coming out of Direct climb",_projectile);
				};
			};
			// Fly in a ballistic climb so that the missile can get altitude for a high angle hit.
			case cMODE_TOP_CLIMB: {
				_targetPitchOffset = 75 - _pitch; // Pitch to climb
				if (((_curAlt - _initialAlt) > _climbTop) || {(_gndDistance < (2 * _initDistance / 5))}) then {
					_profileStep = _profileStep + 1;
					_mode = _flightProfile select _profileStep;
					TRACE_1("Javelin coming out of Top climb",_projectile);
				};
			};
			// Keep altitude for a while
			case cMODE_TOP_LEVEL: {
				_targetPitchOffset = -_pitch;
				TRACE_2("Top level reached, ground distance",_projectile,_gndDistance);
				if (_gndDistance < (_initDistance / 3)) then {       // Switch modes when in proximity
					_profileStep = _profileStep + 1;
					_mode = _flightProfile select _profileStep;
					TRACE_2("Javelin entering Terminal mode",_projectile,_gndDistance);
				};
			};
			// Turn towards target
			case cMODE_TERMINAL: {
				// Calculate eta
				_eta = _distance / _projSpeed;
				if (_eta > _pitchDownETA) then {
					_targetPitchOffset = _finalPitch;
				} else {
					_targetPitchOffset = (_finalPitch * ((_eta + 1)*(_eta + 1)) / (_pitchDownETA*_pitchDownETA));
				};
				/*	BIS guidance sucks
				if (_eta <= 2) then {       // Switch modes when in proximity
					_targetPitchOffset = 0;
					_profileStep = _profileStep + 1;
					_mode = _flightProfile select _profileStep;
					TRACE_2("Javelin follows BIS rules now",_projectile,_gndDistance);
				};
				*/
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
		if ((_deltaR < 0 && _targetDeltaR >= 0) || {(_deltaR > 0 && _targetDeltaR <= 0)}) then {
			_turnAccel = 3 * _turnAccel;
		};
		if ((_deltaP < 0 && _targetDeltaP >= 0) || {(_deltaP > 0 && _targetDeltaP <= 0)}) then {
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
		_dir = _dir + _deltaR;
		_pitch = _pitch + _deltaP;

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

		if !(_mode in [cMODE_BALLISTIC]) then {
			_projectile setVectorDirAndUp [_vec, _vecUp];
			_projectile setVelocity [_vDirX * _projSpeed, _vDirY * _projSpeed, _vDirZ * _projSpeed];
		};
		TRACE_4("Javelin on the way",_projectile,_projSpeed,_curAlt,_distance);
		
		if !(isNull _realprojectile) then {
		//	_realprojectile setVelocity [0, 0, 0];
			_realprojectile setPosATL [_ppos select 0, _ppos select 1, 5000];
		};
	},
	_this, /* parameters */
	0, // delay
	{ /* init code */
		_vehicle = _this select 0;
		_projectile = _this select 1;
		_flightMode = _this select 2;
		_target = _this select 3;
		_isPlayer = _this select 4;
		_realprojectile = _this select 5;
		_targetlogic = _this select 6;
		TRACE_7("PARAMS_7",_vehicle,_projectile,_flightMode,_target,_isPlayer,_realprojectile,_targetlogic);

		if (isNil "_flightMode") then { _flightMode = 0 };

		// Javelin flight profiles.
		_PROFILE_DIRECT = [cMODE_DIRECT_CLIMB, cMODE_TERMINAL, cMODE_BALLISTIC];
		_PROFILE_TOP = [cMODE_TOP_CLIMB, cMODE_TOP_LEVEL, cMODE_TERMINAL, cMODE_BALLISTIC];

		// Has to match guidance profile modes in other parts of this framework

		// Top by default
		_flightProfile = _PROFILE_TOP;
		switch (_flightMode) do {
			case 1: {_flightProfile = _PROFILE_DIRECT};
			default	{};
		};

		#ifdef DEBUG_MODE_FULL
			[_projectile] spawn ace_fnc_track;
		#endif

		_profileStep = 0;

		_ppos = getPosASL _projectile;
		_mvUp = vectorUp _projectile;
		_mvDir = vectorDir _projectile;
		_mVel = velocity _projectile;
		
		_projSpeed = _mvel call ACE_fnc_magnitude;
		_tpos = if (isNull _target) then {[0,0,0]} else {[_target] call FUNC(getPosASL)};

		// Missile flight parameters. Tweak for epic fail.
		_cTurnRate = 140 * __TRACKINTERVAL;		// (deg/sec) (Max Turn Rate)
		_cMaxTurnAccel = 18.0 * __TRACKINTERVAL;	// (deg/sec/sec) (Max Turn Acceleration)

		// Flight variable init
		_prevAlt = 0;						// Previously measured altitude
		_curAlt = 0;						// Currently measured altitude
		_climb = 0;							// Climb rate
		_pitch = 0;							// Pitch amount
		_dir = 0;							// Direction
		_turnAccel = 0;						// How fast we are accelerating rotation around the model's Z axis.
		_pitchAccel = 0;					// How fast we are accelerating rotation around the model's X axis.
		_deltaP = 0;						// Rotational speed around X axis.
		_deltaR = 0;						// Rotational speed around Z axis.
		_targetDeltaP = 0;					// Our desired rotational velocity for delta pitch.
		_targetDeltaR = 0;					// Our desired rotational velocity for delta rotation.
		_targetHeadingOffset = 0;			// Target offset for heading.
		_targetPitchOffset = 85;			// Target offset for pitch.
		_finalPitch = 5;					// Final pitch
		_pitchDownETA = 2.5;				// ETA in seconds to begin final pitch to zero
		_eta = 0;
		_initialDir = getDir _projectile;	// Initial direction
		_initialAlt = _ppos select 2;
		_distance = 9999;
		_gndDistance = 9999;
		// Determine altitude to climb
		_initDistance = [_ppos select 0, _ppos select 1, 0] distance [_tpos select 0, _tpos select 1, 0];
		_climbDirect = (_initDistance / 30) + 3 - ((_ppos select 2) - (_tpos select 2));	// hills
		_climbTop = (_initDistance / 12.5) + 20 - ((_ppos select 2) - (_tpos select 2));
		_vecToTarget = [0,0,0];

		if !(_isPlayer || {(_initDistance > 200)}) then {_flightProfile = _PROFILE_DIRECT};	// Automatically pick correct mode.

		// Initial Mode
		_mode = _flightProfile select _profileStep;
		_prevTime = time - __TRACKINTERVAL;
	},
	{ /* exit code */ 
		if !(isNull _realprojectile) then {
			_realprojectile setVectorDirAndUp [_vec, _vecUp];
			if !(isNull _target) then {
				_projSpeed = (getNumber(configFile >> "CfgAmmo" >> typeOf _realprojectile >> "typicalSpeed")) max _projSpeed;
			};
			_realprojectile setVelocity [_vDirX * _projSpeed, _vDirY * _projSpeed, _vDirZ * _projSpeed];
			_realprojectile setPosASL _ppos;
			deleteVehicle _targetlogic;
		};
	},
	{ /* Run condition - default true */
		time - _prevTime > __TRACKINTERVAL
	},
	{isNull _projectile || {isNull _target}}, /* exit condition */
	[ /* Private variables, available throughout all states and conditions */
			"_vehicle","_projectile","_flightMode","_target","_isPlayer","_realprojectile","_targetlogic",
			"_mode",
			"_flightProfile","_PROFILE_DIRECT","_PROFILE_TOP","_profileStep",
			"_ppos","_mvUp","_mvDir","_mVel",
			"_cTurnRate","_cMaxTurnAccel","_climbDirect","_climbTop",
			"_prevAlt","_curAlt","_climb","_pitch","_dir",
			"_turnAccel","_pitchAccel","_deltaP","_deltaR","_targetDeltaP","_targetDeltaR","_targetHeadingOffset","_targetPitchOffset",
			"_initialDir","_initialAlt",
			"_distance","_gndDistance","_initDistance","_vecToTarget","_tpos",
			"_prevTime","_deltaTime",
			"_projSpeed","_vec","_vecUp","_vecToTarget_hmag","_vec_hmag","_headingOffset","_pitchOffset","_headingOffsetAbs","_pitchOffsetAbs","_pitchComponent",
			"_eta","_pitchDownETA","_finalPitch",
			"_vDirX","_vDirY","_vDirZ"
	]
] call cba_common_fnc_addPerFrameHandlerLogic;

_handle;
