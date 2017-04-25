//fnc_missile_lgb_track.sqf
// laser guidance and tracking for LGB
// by Nou
// integrated /w laser tracking by jaynus
// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define MIN_OPT_SPEED 100
private ["_curVelocity", "_tdif", "_totalVelocity", "_headingPitch", "_marker", "_vectorTo", "_polarTo", "_dir",
		 "_amount", "_negative", "_positive", "_offset", "_elevationOffset", "_orientation", "_laserCode", "_targetCode"];

_params = _this select 0;
		 
_bomb 			= _params select 0;
_laserCode 		= _params select 1;
_lastTime 		= _params select 2;
_lastLDSearch 	= _params select 3;
_currentTarget	= _params select 4;

if(!alive _bomb) exitWith {
	[(_this select 1)] call CBA_fnc_removePerFrameHandler;
};

// _tdif & _lastTime is a compensation mechanism for lower frame 
// rates. It is used to multiply the navigational corrections to 
// the weapon. I am not sure if this is needed if this only
// runs on one machine.
_tdif = (time-_lastTime);
_lastTime = time;

// _curVelocity is the velocity vector for this frame
// and is used as the source for other functions of
// guidance later on.
_curVelocity = velocity _bomb;
_totalVelocity = sqrt((_curVelocity select 0)^2 + (_curVelocity select 1)^2 + (_curVelocity select 2)^2);
// ... such as this
_headingPitch = _curVelocity call CBA_fnc_vect2polar;

_laserCode = _bomb getVariable "ACE_LASERTARGET_CODE";
if(isNil "_laserCode") then {
	_laserCode = 1001;
	_bomb setVariable ["ACE_LASERTARGET_CODE", _laserCode];
};

// If the time between the last search for a laser designator
// is longer than 1.5 game seconds then look again.
if(time-_lastLDsearch > 1.5) then {
	// reset timer
	_lastLDsearch = time;
	_found = false;
	_results = [_bomb, _laserCode, 30, _curVelocity] call FUNC(findLaserDesignator);
	_found = _results select 0;
	if(_found) then {
		_currentTarget = _results select 1;
	} else {
		_currentTarget = _bomb;
	};
};

_doHandoff = false; 
if(_currentTarget != _bomb) then {
	_doHandoff = [_bomb, _currentTarget, QUOTE(FUNC(missile_lgb_track)), _params, 0, 0.01] call FUNC(handOffGuidance);
};
if(_doHandoff) exitWith {
	[(_this select 1)] call cba_fnc_removePerFrameHandler;
	[_bomb] call ace_sys_frag_fnc_removeTrack;
	deleteVehicle _bomb;
};

#ifdef DEBUG_MODE_FULL
//TRACKINGSHIT <-- YOU CAN DELETE THIS STUFF WHEN DONE DEBUGIN OR COMMENT OUT
	drop ["\Ca\Data\Cl_basic","","Billboard",1,20,(getPos _bomb),[0,0,0],1,1.275,1.0,0.0,[5],[[1,0,0,1]],[0],0.0,2.0,"","",""];
	_marker = createMarkerLocal [format["m%1", MARKERCOUNT], (getPos _bomb)];
	_marker setMarkerTypeLocal "Dot";
	_marker setMarkerColorLocal "ColorGreen";
	MARKERCOUNT = MARKERCOUNT + 1;
//ENDTRACKINGSHIT
#endif

// if the _currentTarget is not the _bomb then its a LD
// so lets begin tracking it.
if(_currentTarget != _bomb) then {
	// Lets get the vector to the target
	_vectorTo = ([(getPosASL _bomb), ([_currentTarget] call FUNC(getPosASL))] call ACE_fnc_vectorFromXToY);
	
	// it is easier to work in polar coordinates than vectors
	// at least from a visualizing point of view.
	_polarTo = _vectorTo call CBA_fnc_vect2polar;
	
	// get the dir to the target
	_dir = _polarTo select 1;
	
	// ... and then make it relative to our current heading
	_dir = _dir - (_headingPitch select 1);
	if (_dir < 0) then {_dir = _dir + 360};
	if (_dir > 360) then {_dir = _dir - 360};
	
	// This is the one so called "magic number" but it comes
	// from experience testing and how shotMissile works.
	// This is the amount of vector direction change in pitch
	// and yaw. This will not truely change the course THAT much
	// the simulation overrides it and sends it back closer to 
	// the original, so it is a fairly BLUNT adjustment.
	//
	// accTime is used for singlePlayer where the time might be
	// sped up or slowed down. We want to make sure that the
	// movements compensate because the speed of execution is still
	// real time.
	_amount = 0.5*accTime;
	
	// Apply the _tdif we calculated at the start to compensate
	// for lag.
	_positive = (_amount+(_amount*_tdif));
	_negative = -(_positive);
	
	// This is the offset in heading from current course.
	// Paveway II uses "bang-bang" adjusments. Its control
	// surfaces are either extended fully in one direction
	// or not extended at all. Compare to JDAM, LJDAM/Paveway
	// IV where it uses smooth control surface adjustments where
	// this would be multiplied by the percentage of offset
	// needed to conserve energy.
	_offset = 0;
	if(_dir > 180) then {
		_offset = _negative*1;
	} else {
		_offset = _positive*1;
	};
	
	// This is the elevation offset code. The code is set
	// so that the bomb will only begin to do elevation changes
	// after it has reached apogee, to prevent early ballistic
	// exit which might impede the desired loft effect.
	_elevationOffset = 0;
	if((_curVelocity select 2) <= 0) then {
		// The max 89 stuff is to make sure we do not have a gimble
		// lock at 90 degrees elevation, which can seriously cause
		// some odd shit to happen in ArmA2 (like bombs deciding to
		// execute crazy spirals or horizontal hover movements...!
		if((_polarTo select 2) > ((_headingPitch select 2) max -89)) then {
			_elevationOffset = _positive*1;
		} else {
			if((_polarTo select 2) < ((_headingPitch select 2) max -89)) then {
				_elevationOffset = _negative*1;
			};
		};
	};
	
	// This is the same about the gimble lock. Again make sure that
	// any adjustments will not bring it into a straight vertical
	// dive. If that is the case, then do not adjust guidance this
	// frame and let the bomb get to a point where it is out of 
	// potential gimbal locking. This is not THAT dangerous because
	// the assumption is made that if the bomb is in vertical it is
	// so over the target already and will terminate naturally and
	// accurately.
	_orientation = (velocity _bomb) call ACE_fnc_unitVector;
	_orientation = _orientation call CBA_fnc_vect2polar;
	if(((_orientation select 2) + _elevationOffset) < -89) then {
		_elevationOffset = 0;
		_offset = 0;
	};
	
	// More debug stuff, good to see, but obviously can comment out/delete.
	_offset = _offset*((((_totalVelocity)/MIN_OPT_SPEED) min 1) max 0);
	_elevationOffset = _elevationOffset*((((_totalVelocity)/MIN_OPT_SPEED) min 1) max 0);
	#ifdef DEBUG_MODE_FULL
		hintSilent format["dir: %1\nrdir: %2\noff: %3\nElOff: %4\nVectorTo: %5\nPolarTo: %6, ERROR: %7\nAlt:%8\nspeed: %9", 
						(_headingPitch select 1), 
						_dir, 
						_offset,
						_elevationOffset,
						_vectorTo,
						_polarTo,
						(_bomb distance _currentTarget),
						(getPosATL _bomb select 2),
						_totalVelocity
					];
	#endif
	
	
	// The Magic! If we can make an offset vertically or horizontally
	// then lets do it!
	//
	// adjustTrajectory
	if(_offset != 0 && {_elevationOffset != 0}) then {
		// Get the bombs current pitch and bank.
		private ["_curPitch", "_newDir", "_curVelocity", "_totalVelocity", "_vec"];
		_curPitch = (_bomb call BIS_fnc_getPitchBank);
		
		
		// Get the new direction of the bomb and make sure it
		// is within 360 degrees.
		_newDir = (getDir _bomb) + _offset;
		if(_newDir < 0) then {
			_newDir = 360 + _newDir;
		};
		if(_newDir >= 360) then {
			_newDir = _newDir mod 360;
		};
		
		// Get the velocity vector, then calculate the total
		// velocity in m/s.
		_curVelocity = velocity _bomb;
		_totalVelocity = sqrt((_curVelocity select 0)^2 + (_curVelocity select 1)^2 + (_curVelocity select 2)^2);
		
		// Create a new vector for the adjustment that the control
		// surfaces would effect the bomb.
		_vec = [_totalVelocity, _newDir, (_curPitch select 0)] call CBA_fnc_polar2vect;
		
		// Set the vectorDir for heading adjustment
		_bomb setVectorDir _vec;
		
		// Use this bis function to set the correct vectorUp for
		// elevation adjustment
		[_bomb, ((_curPitch select 0) + _elevationOffset), 0] call BIS_fnc_setPitchBank;
	};
};

_params set[2, _lastTime];
_params set[3, _lastLDSearch];
_params set[4, _currentTarget];