//guidance.sqf
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define TIME_FUNC	time
#define SET_STAGE(stage)	_params set[4, stage]

private ["_params", "_missile", "_startTime", "_replaced", "_mode", "_stage", "_vel", "_vec", "_vecUp",
		"_pos", "_laserCode", "_lastLDsearch", "_found", "_potentialTargets", "_vectorTo", "_polarTo",
		"_dir", "_vertOk", "_horzOk", "_closestDistance", "_disCheck", "_currentTarget", "_targetCode",
		"_curVelocity", "_currentTarget"];
		

_params = _this select 0;

_missile = _params select 0;
_startTime = _params select 1;
_replaced = _params select 2;
_mode = _params select 3;
_stage = _params select 4;
_laserDelay = _params select 5;
_currentTarget = _params select 6;
_lastLDsearch = _params select 7;
_modeParams = _params select 8;
_currentTargetPos = _params select 9;
_lastTime = _params select 10;
_lastTargetPos = _params select 11;
_laserCode = _params select 12;
_launchPos = _params select 13;
_launchAlt = _launchPos select 2;

_delta = TIME_FUNC-_lastTime;
_params set[10, TIME_FUNC];

if (!alive _missile) exitWith {
	[(_this select 1)] call cba_fnc_removePerFrameHandler; 
};
if (TIME_FUNC-_startTime > 45) exitWith {
	_vel = velocity _missile;
	_vec = vectorDir _missile;
	_vecUp = vectorUp _missile;
	_pos = getPosASL _missile;
	_isCurrentTarget = false;
	if (_currentTarget == _missile) then {
		_isCurrentTarget = true;
	};
	[_missile] call ace_sys_frag_fnc_removeTrack;
	deleteVehicle _missile;
	
	_missile = "ACE_M_Hellfire_AT_Coast" createVehicle [0,0,2000];
	_missile setPosASL _pos;
	_missile setVectorDirAndUp [_vec, _vecUp];
	_missile setVelocity _vel;
	[_missile] call ace_sys_frag_fnc_addManualTrack;
	_params set[0, _missile];
	_params set[2, true];
	if (_isCurrentTarget) then {
		_currentTarget = _missile;
	};
	#ifdef DEBUG_MODE_FULL
		THETYPE = "mil_triangle";
	#endif
	[_this select 1] call cba_fnc_removePerFrameHandler; 
};

_curVelocity = velocity _missile;
_totalVelocity = sqrt((_curVelocity select 0)^2 + (_curVelocity select 1)^2 + (_curVelocity select 2)^2);
if (_totalVelocity == 0) exitWith {};
_headingPitch = _curVelocity call CBA_fnc_vect2polar;

#ifdef DEBUG_MODE_FULL
	if (isNil "MARKERCOUNT") then {
		MARKERCOUNT = 0;
	};
	_marker = createMarkerLocal [format["m%1", MARKERCOUNT], (getPos _missile)];
	_marker setMarkerType "Dot";
	MARKERCOUNT = MARKERCOUNT + 1;
	// drop ["\Ca\Data\Cl_basic","","Billboard",1,60,(getPos _missile),[0,0,0],1,1.275,1.0,0.0,[2],[[1,0,0,0.25]],[0],0.0,2.0,"","",""];
	_distance = ([_launchPos, _missile] call BIS_fnc_distance2D);
	_marker = createMarkerLocal [format["m%1", MARKERCOUNT], [_distance, (getPosASL _missile) select 2]];
	_marker setMarkerTypeLocal THETYPE;
	_marker setMarkerColorLocal THECOLOR;
	MARKERCOUNT = MARKERCOUNT + 1;
	_marker = createMarkerLocal [format["m%1", MARKERCOUNT], [_distance, (getTerrainHeightASL [(getPosASL _missile) select 0, (getPosASL _missile) select 1])]];
	_marker setMarkerTypeLocal "Dot";
	_marker setMarkerColorLocal "ColorBrown";
	MARKERCOUNT = MARKERCOUNT + 1;
#endif


if (isNil "_laserCode") then {
	_laserCode = 1001;
};
if (TIME_FUNC-_lastLDsearch > 0.2 && {(_startTime+_laserDelay) < TIME_FUNC}) then {
	_lastLDsearch = TIME_FUNC;
	_params set[7, _lastLDsearch];
	_found = false;
	_results = [_missile, _laserCode, 75, _curVelocity] call FUNC(findLaserDesignator);
	_found = _results select 0;
	if (_found) then {
		_currentTarget = _results select 1;
		if (!isNull _currentTarget) then {
			_currentTargetPos = ([_currentTarget] call FUNC(getPosASL));
			_params set[9, _currentTargetPos];
		};
	} else {
		_currentTarget = _missile;
	};
};
_params set[6, _currentTarget];

_doHandoff = false; 
if(_currentTarget != _missile) then {
	_doHandoff = [_missile, _currentTarget, QUOTE(FUNC(missile_hellfire2)), _params, 0, 0.01] call FUNC(handOffGuidance);
};
if(_doHandoff) exitWith {
	[(_this select 1)] call cba_fnc_removePerFrameHandler;
	[_missile] call ace_sys_frag_fnc_removeTrack;
	deleteVehicle _missile;
};

_offset = 0;
_elevationOffset = 0;
if (_mode == HELLFIRE_MODE_LOBL) then {
	_targetPos = ([_currentTarget] call FUNC(getPosASL));
	if (_currentTarget == _missile || {isNull _currentTarget}) then {
		_targetPos = +_currentTargetPos;
	};
	#ifdef DEBUG_MODE_FULL
		THETYPE = "Dot";
		_tda = getTerrainHeightASL _targetPos;
		_dp = [_targetPos select 0, _targetPos select 1, (_targetPos select 2)-_tda];
		drop ["\Ca\Data\Cl_basic","","Billboard",1,0.25,_dp,[0,0,0],1,1.275,1.0,0.0,[1],[[1,0,0,1]],[0],0.0,2.0,"","",""];
	#endif
	_params set[11, +_targetPos];
	_distance = (getPosASL _missile) distance _targetPos;
	_2dDistance = [(getPosASL _missile), _targetPos] call BIS_fnc_distance2D;
	if ((_curVelocity select 2) <= 0 && {_stage > HELLFIRE_MODE_LOBL_STAGE_COAST}) then {
			_height = log((_2dDistance/(_totalVelocity/2))^2);
			_targetPos set[2, (_targetPos select 2)+(_height)+1];
	};
	
	
	
	_amount = 20*accTime;
	
	_vectorTo = ([(getPosASL _missile), _targetPos] call ACE_fnc_vectorFromXToY);
	_polarTo = _vectorTo call CBA_fnc_vect2polar;
	_dir = _polarTo select 1;
	
	_dir = _dir - (_headingPitch select 1);
	if (_dir < 0) then {_dir = _dir + 360};
	if (_dir > 360) then {_dir = _dir - 360};
	
	_positive = (_amount*_delta);
	_negative = -(_positive);
	if (_dir < 270 && {_dir > 90}) exitWith { _offSet = 0; _elevationOffset = 0; };
	if (_dir > 180) then {
		_dc = 360-_dir;
		_offset = _negative*((_dc/3) min 3);
	} else {
		_dc = _dir;
		_offset = _positive*((_dc/3) min 3);
	};
	
	switch (_stage) do {
		case HELLFIRE_MODE_ALL_STAGE_LAUNCH: {
			#ifdef DEBUG_MODE_FULL
				hintSilent format["stage: launch"];
			#endif
			_dir = 0;
			if (TIME_FUNC-_startTime > 0.15) then {
				SET_STAGE(HELLFIRE_MODE_LOBL_STAGE_CLIMB_PREPARE);
			};
		};
		case HELLFIRE_MODE_LOBL_STAGE_CLIMB_PREPARE: {
			#ifdef DEBUG_MODE_FULL
				hintSilent format["stage: prepare"];
				THECOLOR = "ColorRed";
			#endif
			_distance = _launchPos distance _targetPos;
			_2dDistance = [_launchPos, _targetPos] call BIS_fnc_distance2D;
			_addHeight = 3e-12*(_2dDistance^4) - 4e-08*(_2dDistance^3) + 0.0002*(_2dDistance^2) - 0.1834*_2dDistance + 45.717;
			// _addHeight = 2.5*((_2dDistance/1000)^3) - 25*((_2dDistance/1000)^2) + 377.5*(_2dDistance/1000) - 575;
			_max = 0.0076*(_2dDistance^1.3564);
			// _max = 205.88*(ln(_2dDistance)) - 1255;
			_addHeight = ((_addHeight min 800) max _max)/3.2808399;
			_cutOffAlt = _launchAlt + (_addHeight*0.6);
			_height = _launchAlt + _addHeight;
			
			_elev = 6;
			// if(_2dDistance < 1500) then {
				// _p = 1;//((_2dDistance)/1500) max 0;
				// _height = _height*_p;
				// _cutOffAlt = _cutOffAlt*_p;
				// _elev = 15*_p;
			// };
			_modeParams set[0, _height];
			_modeParams set[1, _cutOffAlt];
			
			_modeParams set[2, _elev];
			_modeParams set[3, _2dDistance];
			_modeParams set[4, _launchAlt];
			SET_STAGE(HELLFIRE_MODE_LOBL_STAGE_CLIMB);
		};
		case HELLFIRE_MODE_LOBL_STAGE_CLIMB: {
			_cutOffAlt = _modeParams select 1;
			_elev = _modeParams select 2;
			_initHeight = _modeParams select 4;
			_initDistance = _modeParams select 3;
			#ifdef DEBUG_MODE_FULL
				hintSilent format["stage: climb to %1", _cutOffAlt];
				THECOLOR = "ColorBlack";
			#endif
			_pE = _elev;
			_hP = ((_headingPitch select 2) max -89);
			if (_pE > _hP) then {
				_d = _pE-_hP;
				_elevationOffset = _positive*((_d/3) min 3);
			} else {
				if (_pE < _hP) then {
					_d = _hP-_pE;
					_elevationOffset = _negative*((_d/3) min 3);
				};
			};
			_orientation = (velocity _missile) call ACE_fnc_unitVector;
			_orientation = _orientation call CBA_fnc_vect2polar;
			if (((_orientation select 2) + _elevationOffset) < -89) then {
				_elevationOffset = 0;
				_offset = 0;
			};
			
			if (((getPosASL _missile) select 2) > _cutOffAlt) then {
				SET_STAGE(HELLFIRE_MODE_LOBL_STAGE_COAST);
			};
		};
		case HELLFIRE_MODE_LOBL_STAGE_COAST: {
			_diveAlt = _modeParams select 0;
			_initDistance = _modeParams select 3;
			#ifdef DEBUG_MODE_FULL
				hintSilent format["stage: coasting to: %1", _diveAlt];
				THECOLOR = "ColorGreen";
			#endif
			if (((getPosASL _missile) select 2) > _diveAlt || {(_curVelocity select 2) <= 0}) then {
				SET_STAGE(HELLFIRE_MODE_LOBL_STAGE_DIVE);
			};
		};
		case HELLFIRE_MODE_LOBL_STAGE_DIVE: {
			#ifdef DEBUG_MODE_FULL
				hintSilent format["diving: %1 %2 %3", ((getPosASL _missile) distance _targetPos), _targetPos select 2, _totalVelocity];
				deleteMarker TEST_TARGET;
				TEST_TARGET = createMarkerLocal [format["f%1", 236236], _targetPos];
				TEST_TARGET setMarkerType "Destroy";
				THECOLOR = "ColorWhite";
			#endif
			_max = 1;
			_pE = (_polarTo select 2);
			_hP = (_headingPitch select 2);
			_initDistance = _modeParams select 3;
			_m = (1*((1-(_2dDistance/(_initDistance*0.9))) max 0)) max 0;
			if (_2dDistance > (200+(_totalVelocity*2))) then {
				_pE = -0.5;
			};
			if (_initDistance > 2500) then {
				_m = 1;
			};
			if (_pE > _hP) then {
				_d = _pE-_hP;
				_elevationOffset = (_positive*((_d/2) min 2)*_m);
			} else {
				if (_pE < _hP) then {
					_d = _hP-_pE;
					if((_curVelocity select 2) >= 0) then {
						_m = 1;
					};
					_elevationOffset = (_negative*((_d/2) min 2)*_m);
				};
			};
			if ((_curVelocity select 2) <= 0) then {
				SET_STAGE(HELLFIRE_MODE_LOBL_STAGE_TERMINAL);
			};
		};
		case HELLFIRE_MODE_LOBL_STAGE_TERMINAL: {
			
			_max = 1;
			_pE = (_polarTo select 2);
			_hP = (_headingPitch select 2);			
			_initDistance = _modeParams select 3;
			_m = (2*((1-(_2dDistance/(_initDistance*0.9))) max 0)) max 0;
			if (_2dDistance > (500+(_totalVelocity))) then {
				if(_pE < _hP) then {
					#ifdef DEBUG_MODE_FULL
						THECOLOR = "ColorYellow";
					#endif
					_pE = -1;
					_m = 1;
				};
			};
			if (_pE > _hP) then {
				_d = _pE-_hP;
				_elevationOffset = (_positive*((_d/1) min 4)*_m);
			} else {
				if (_pE < _hP) then {
					_d = _hP-_pE;
					_elevationOffset = (_negative*((_d/1) min 4)*_m);
				};
			};
			_elevationOffset = _elevationOffset * accTime;
			_orientation = (velocity _missile) call ACE_fnc_unitVector;
			_orientation = _orientation call CBA_fnc_vect2polar;
			
			if (((_orientation select 2) + _elevationOffset) < -89.999999999) then {
				_elevationOffset = 0;
				_offset = 0;
			};
			#ifdef DEBUG_MODE_FULL
				hintSilent format["terminal: %1 %2 %3\ndive: %4\nD: %5\nE: %6", 
					((getPosASL _missile) distance _targetPos), 
					_targetPos select 2, 
					_totalVelocity, 
					(_headingPitch select 2),
					_offset,
					_elevationOffset
					];
				deleteMarker TEST_TARGET;
				TEST_TARGET = createMarkerLocal [format["f%1", 236236], _targetPos];
				TEST_TARGET setMarkerType "Destroy";
				THECOLOR = "ColorPink";
			#endif
		};
	};
} else {
	if (_mode == HELLFIRE_MODE_LOALDIR || {_mode == HELLFIRE_MODE_LOALHI} || {_mode == HELLFIRE_MODE_LOALLOW}) then {
		if (_currentTarget != _missile) exitWith {
			_params set[3, HELLFIRE_MODE_LOBL];
			_params set[13, (getPosASL _missile)];
			SET_STAGE(HELLFIRE_MODE_LOBL_STAGE_CLIMB_PREPARE);
		};
		_amount = 2*accTime;		
		_positive = (_amount)+(_amount*_delta);
		_negative = -(_positive);
		#ifdef DEBUG_MODE_FULL
			THETYPE = "mil_box";
		#endif
		switch (_stage) do {
			case HELLFIRE_MODE_ALL_STAGE_LAUNCH: {
				#ifdef DEBUG_MODE_FULL
					hintSilent format["LOAL stage: launch"];
				#endif
				_dir = 0;
				if (TIME_FUNC-_startTime > 0.15) then {
					_params set[13, (getPosASL _missile)];
					SET_STAGE(HELLFIRE_MODE_LOAL_STAGE_CLIMB_PREPARE);
				};
			};
			case HELLFIRE_MODE_LOAL_STAGE_CLIMB_PREPARE: {
				#ifdef DEBUG_MODE_FULL
					hintSilent format["LOAL stage: prepare"];
					THECOLOR = "ColorRed";
				#endif
				_height = 0;
				_elev = 7;
				switch(_mode) do {
					case HELLFIRE_MODE_LOALDIR: { _height = 800; };
					case HELLFIRE_MODE_LOALHI: { _height = 1500; _elev = 15;};
					case HELLFIRE_MODE_LOALLOW: { _height = 1100; _elev = 15;};
				};
				_cutOffAlt = _launchAlt + ((_height/3.2808399)*0.6);
				_height = _launchAlt + (_height/3.2808399);
				
				_modeParams set[0, _height];
				_modeParams set[1, _cutOffAlt];
				
				_modeParams set[2, _elev];
				_modeParams set[3, _launchAlt];
				switch(_mode) do {
					case HELLFIRE_MODE_LOALDIR: { SET_STAGE(HELLFIRE_MODE_LOAL_STAGE_CLIMB2); };
					case HELLFIRE_MODE_LOALHI: { SET_STAGE(HELLFIRE_MODE_LOAL_STAGE_CLIMB); };
					case HELLFIRE_MODE_LOALLOW: { SET_STAGE(HELLFIRE_MODE_LOAL_STAGE_CLIMB); };
				};
				
			};
			case HELLFIRE_MODE_LOAL_STAGE_CLIMB: {
				_initHeight = _modeParams select 3;
				_cutOffAlt = _initHeight+25;
				_elev = 45;
				#ifdef DEBUG_MODE_FULL
					hintSilent format["LOAL stage: climb to clear %1 %2", _cutOffAlt, ((getPosASL _missile) select 2)];
					THECOLOR = "ColorBlack";
				#endif
				_pE = _elev;
				_hP = ((_headingPitch select 2) max -89);
				if (_pE > _hP) then {
					_d = _pE-_hP;
					_elevationOffset = _positive*((_d/1) min 1) max 0;
				} else {
					if (_pE < _hP) then {
						_d = _hP-_pE;
						_elevationOffset = _negative*((_d/1) min 1) max 0;
					};
				};
				_orientation = (velocity _missile) call ACE_fnc_unitVector;
				_orientation = _orientation call CBA_fnc_vect2polar;
				if (((_orientation select 2) + _elevationOffset) < -89) then {
					_elevationOffset = 0;
					_offset = 0;
				};
				
				if (((getPosASL _missile) select 2) > _cutOffAlt) then {
					SET_STAGE(HELLFIRE_MODE_LOAL_STAGE_CLIMB2);
				};
			};
			
			case HELLFIRE_MODE_LOAL_STAGE_CLIMB2: {
				_cutOffAlt = _modeParams select 1;
				_elev = _modeParams select 2;
				#ifdef DEBUG_MODE_FULL
					hintSilent format["LOAL stage: climb to %1 %2", _cutOffAlt, ((getPosASL _missile) select 2)];
					THECOLOR = "ColorOrange";
				#endif
				_pE = _elev;
				_hP = ((_headingPitch select 2) max -89);
				if (_pE > _hP) then {
					_d = _pE-_hP;
					_elevationOffset = _positive*((_d/0.5) min 2);
				} else {
					if (_pE < _hP) then {
						_d = _hP-_pE;
						_elevationOffset = _negative*((_d/0.5) min 2);
					};
				};
				_orientation = (velocity _missile) call ACE_fnc_unitVector;
				_orientation = _orientation call CBA_fnc_vect2polar;
				if (((_orientation select 2) + _elevationOffset) < -89) then {
					_elevationOffset = 0;
					_offset = 0;
				};
				
				if (((getPosASL _missile) select 2) > _cutOffAlt) then {
					SET_STAGE(HELLFIRE_MODE_LOAL_STAGE_COAST);
				};
			};
			
			case HELLFIRE_MODE_LOAL_STAGE_COAST: {
				_diveAlt = _modeParams select 0;
				#ifdef DEBUG_MODE_FULL
					THECOLOR = "ColorGreen";
					hintSilent format["LOAL stage: coasting to: %1 %2", _diveAlt, ((getPosASL _missile) select 2)];
				#endif
				if (((getPosASL _missile) select 2) > _diveAlt || {(_curVelocity select 2) <= 0}) then {
					SET_STAGE(HELLFIRE_MODE_LOAL_STAGE_GLIDE);
				};
			};
			
			case HELLFIRE_MODE_LOAL_STAGE_GLIDE: {
				#ifdef DEBUG_MODE_FULL
					hintSilent format["LOAL stage: glide"];
					THECOLOR = "ColorBrown";
				#endif
				_pE = -1;
				_hP = ((_headingPitch select 2) max -89);
				if (_pE > _hP) then {
					_d = _pE-_hP;
					
					_elevationOffset = _positive*((_d/1) min 1);
				} else {
					if (_pE < _hP) then {
						_d = _hP-_pE;
						
						_elevationOffset = _negative*((_d/1) min 1);
					};
				};
				_orientation = (velocity _missile) call ACE_fnc_unitVector;
				_orientation = _orientation call CBA_fnc_vect2polar;
				if (((_orientation select 2) + _elevationOffset) < -89) then {
					_elevationOffset = 0;
					_offset = 0;
				};
				
				if (((getPosASL _missile) select 2) > _cutOffAlt) then {
					SET_STAGE(HELLFIRE_MODE_LOAL_STAGE_COAST);
				};
			};
		};
	};
};
if (_offset != 0 || {_elevationOffset != 0}) then {
	private ["_curPitch", "_newDir", "_curVelocity", "_totalVelocity", "_vec"];
	_curPitch = (_missile call BIS_fnc_getPitchBank);
	_newDir = (getDir _missile) + _offset;
	if (_newDir < 0) then {
		_newDir = 360 + _newDir;
	};
	if (_newDir >= 360) then {
		_newDir = _newDir mod 360;
	};
	_curVelocity = velocity _missile;
	_totalVelocity = sqrt((_curVelocity select 0)^2 + (_curVelocity select 1)^2 + (_curVelocity select 2)^2);
	_vec = [_totalVelocity, _newDir, (_curPitch select 0)] call CBA_fnc_polar2vect;
	_missile setVectorDir _vec;
	[_missile, ((_curPitch select 0) + _elevationOffset), 0] call BIS_fnc_setPitchBank;
};
	