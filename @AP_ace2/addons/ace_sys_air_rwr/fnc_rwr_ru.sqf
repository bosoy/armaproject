/* ace_sys_air_rwr | SPO15 RWR | (c) 2011 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_vehicle);

private ["_crew"];
_crew = player;

sleep 1;

disableSerialization;

//INIT
private ["_type","_threats","_lastScan","_RWRopen","_MaxTargets","_scanInterval","_RWRrange","_oldThreats"];
_type = 0;
_threats = [];
_lastScan = [];
_oldThreats = [];
_RWRopen = false;

// CUSTOMIZABLE PARAMETERS
_maxTargets = 6; /* RWR maximum number of targets on-screen - 6 Primary 6 Secondary at a time, depending on its priority */
_scanInterval0 = 0.5; //RWR scan interval in seconds
_scanInterval = 0.25;
_RWRrange = getNumber(configFile >> "CfgVehicles" >> typeOf _vehicle >> QGVAR(range)); //RWR range in meters

if (_RWRrange == 0) then {_RWRrange = 3600};

//INCOMING MISSILE EVENT HANDLER
GVAR(fireSource) = objNull;
private ["_incomingeh"];
_incomingeh = _vehicle addEventHandler ["IncomingMissile", {GVAR(fireSource) = _this select 2}];

//DEFINE
#define CTRL(A) ((uiNamespace getVariable "ACE_RWR_RU") displayCtrl A)

#define IDCRWRBASE 22000
#define __IDC [22000,22001,22002,22003,22004,22005,22006,22007,22008,22009,22010,22011,22012,22013,22014,22015,22016,22017,22018,22019,22020,22021,22022,22023,22024,22025,22026,22027,22028,22029,22030,22031,22032,22033]
#define __IDC_DIR [22000,22001,22002,22003,22004,22005,22006,22007,22008,22009,22010,22011,22012,22013,22014,22015,22028,22029,22030,22031]

#define SR5RWR_display_width 0.22
#define SR5RWR_display_height 0.2934

// Primary threat direction array
#define __PRIDIR [[IDCRWRBASE + 0,IDCRWRBASE + 1],[IDCRWRBASE + 2,IDCRWRBASE + 3],[IDCRWRBASE + 4,IDCRWRBASE + 5],[IDCRWRBASE + 6,IDCRWRBASE + 7],[IDCRWRBASE + 28,IDCRWRBASE + 29]]
// Secondary threat direction array
#define __SECDIR [[IDCRWRBASE + 8,IDCRWRBASE + 9],[IDCRWRBASE + 10,IDCRWRBASE + 11],[IDCRWRBASE + 12,IDCRWRBASE + 13],[IDCRWRBASE + 14,IDCRWRBASE + 15],[IDCRWRBASE + 30,IDCRWRBASE + 31]]
// Primary threat types array
#define __PRITYP [IDCRWRBASE + 16,IDCRWRBASE + 17,IDCRWRBASE + 18,IDCRWRBASE + 19,IDCRWRBASE + 20,IDCRWRBASE + 21]
// Secondary threat type array
#define __SECTYP [IDCRWRBASE + 22,IDCRWRBASE + 23,IDCRWRBASE + 24,IDCRWRBASE + 25,IDCRWRBASE + 26,IDCRWRBASE + 27]
// Signal strength
#define __SIGNAL IDCRWRBASE + 32
// Launch
#define __LAUNCH IDCRWRBASE + 33

// TODO: Better: Find all the controls that are supposed to be lit up - remove them from all controls that are NOT supposed to be lit up and use ctrlShow on each.

FUNC(clearControls) = {
	PARAMS_1(_controls);
	{
		if (ctrlShown CTRL(_x)) then {
			CTRL(_x) ctrlShow false;
			CTRL(_x) ctrlCommit 0;
		};
	} foreach _controls;
};
FUNC(clearAllControls) = {
	[__IDC] call FUNC(clearControls);
};
FUNC(displayThreatTypes) = {
	PARAMS_2(_ctrl,_show);
	CTRL(_ctrl) ctrlShow _show;
	CTRL(_ctrl) ctrlCommit 0;
};
FUNC(showThreatTypes) = {
	PARAMS_3(_type,_type_index,_show);
	switch (_type) do {
		case "SECONDARY": {
			/* Light up secondary threat type  */
			[(__SECTYP select _type_index),_show] call FUNC(displayThreatTypes);
			/* Check if primary threat lamp is still lit up  */
			_c = __PRITYP select _type_index;
			if (ctrlShown CTRL(_c)) then {
				[[_c]] call FUNC(clearControls);
			};
		};
		case "PRIMARY": {
			/* Light up primary threat type */
			[(__PRITYP select _type_index),_show] call FUNC(displayThreatTypes);
			[(__SECTYP select _type_index),_show] call FUNC(displayThreatTypes);
		};
	};
};
FUNC(displayThreatDirection) = FUNC(displayThreatTypes);
FUNC(showThreatDirection) = {
	PARAMS_3(_type,_dir_index,_show);
	// CLEAR
	[__IDC_DIR] call FUNC(clearControls);
	{
		_element = _x select 0; // Direction lights index
		_light = _x select 1; // Direction lights side
		switch (_type) do {
			case "SECONDARY": {
				// Light up secondary threat type
				[(__SECDIR select _element) select _light,_show] call FUNC(displayThreatDirection);
			};
			case "PRIMARY": {
				// Light up primary threat type
				[(__PRIDIR select _element) select _light,_show] call FUNC(displayThreatDirection);
				[(__SECDIR select _element) select _light,_show] call FUNC(displayThreatDirection);
			};
		};
	} foreach _dir_index;
};
FUNC(displaySignalStrength) = {
	PARAMS_3(_type,_threat,_vehicle);
	private ["_rwrrange","_threatrange","_strength","_int"];
	//_verified	= _vehicle getVariable QGVAR(primary_threat);
	if (_type == "PRIMARY" /*&& _threat == _verified*/) then {
		_rwrrange = getNumber(configFile >> "CfgVehicles" >> typeOf _vehicle >> QGVAR(range)); //RWR range in meters
		_threatrange = _vehicle distance _threat;
		_strength = round((_threatrange/_rwrrange) * 100);
		switch (true) do {
			case (_strength < 10): { _int = 100; };
			case (_strength > 95): { _int = 0; };
			case (_strength > 85): { _int = 10; };
			case (_strength > 75): { _int = 20; };
			case (_strength > 65): { _int = 30; };
			case (_strength > 55): { _int = 40; };
			case (_strength > 45): { _int = 50; };
			case (_strength > 35): { _int = 60; };
			case (_strength > 25): { _int = 70; };
			case (_strength > 15): { _int = 80; };
			case (_strength > 10): { _int = 90; };
		};
		if (isnil "_int") then { _int = 0; };
		CTRL(__SIGNAL) ctrlSetText format["x\ace\addons\sys_air_rwr\data\rsc\threat_signal_strength%1.paa",_int];
		CTRL(__SIGNAL) ctrlShow true;
		CTRL(__SIGNAL) ctrlCommit 0;
		_launched = _vehicle getVariable [QGVAR(LaunchWarning),false];
		if (_int >= 60 && {!_launched}) then {
			CTRL(__LAUNCH) ctrlSetText QPATHTO_T(data\rsc\threat_launch.paa);
			CTRL(__LAUNCH) ctrlShow true;
		} else {
			CTRL(__LAUNCH) ctrlSetText "";
			CTRL(__LAUNCH) ctrlShow false;
		};
		CTRL(__LAUNCH) ctrlCommit 0;
	};
};
FUNC(displayLaunchWarning) = {
	PARAMS_1(_vehicle);
	_vehicle setVariable [QGVAR(LaunchWarning),true];
	0 spawn {
		for "_i" from 2 to 10 do {
			// 4 FLASHES AND AUDIO TONE
			if (_i mod 2 == 0) then {
				CTRL(__LAUNCH) ctrlSetText QPATHTO_T(data\rsc\threat_launch.paa);
				CTRL(__LAUNCH) ctrlShow true;
				playSound ["ACE_SPO15_IR",true];
			} else {
				CTRL(__LAUNCH) ctrlSetText "";
				CTRL(__LAUNCH) ctrlShow false;
			};
			CTRL(__LAUNCH) ctrlCommit 0;
			sleep 0.2;
		};
		_vehicle setVariable [QGVAR(LaunchWarning),false];
	};
};

//BEGIN MAIN LOOP
private ["_nearStuff","_maxTargets","_threat","_invisibleThreats"];
private ["_LOSorigin","_LOSend","_LOSh","_LOSdist","_LOSvector","_LOS","_posH","_posT","_viewAngleH","_viewAngleT"];
private ["_AX","_AY","_AZ","_BX","_BY","_BZ","_HX","_HY","_HZ","_TX","_TY","_TZ"];
private ["_dir_index","_type_index"];
private "_launcher";
while { (_crew == driver _vehicle || {_crew == gunner _vehicle} || {_crew == commander _vehicle}) && {alive _crew} && {alive _vehicle} } do {
	//GATHER ALL NEARBY CARS AND TANKS
	_nearStuff = getPos _vehicle nearEntities [["air","tank"], _RWRrange * 0.8];
  
	//SET NUMBER OF TARGETS
	_maxTargets = if (count _nearStuff < 6) then {count _nearStuff} else {6};
  
	if (count _nearStuff > 0) then {
		//ACQUIRE THREATS AND BUILD ARRAY
		for "_y" from 0 to (_maxTargets - 1) do {
			_threat = _nearStuff select _y;
			if (getNumber(configFile >> "CfgVehicles" >> typeOf _threat >> "ace_sys_air_rwr_detectable") == 1 && {_threat != _vehicle} && {({alive _x} count crew _threat > 0)} && {!(_threat in _threats)}) then {
				_threats set [count _threats, _threat];
			};
		};
		
		//CHECK FOR RADIO VISIBILITY
		_invisibleThreats = [];
		for "_y" from 0 to (count _threats - 1) do {
			_threat = _threats select _y;
			_LOSorigin = getPosASL _vehicle;
			_LOSorigin set [2, (_LOSorigin select 2) + 0 ];
			_LOSend = getPosASL _threat;
			_LOSdist = _vehicle distance _threat;
			_posH = _vehicle worldToModel [_LOSend select 0, _LOSend select 1, (_LOSend select 2) + 0];
			_LOSvector = [(_posH select 0) / _LOSdist, (_posH select 1) / _LOSdist, (_posH select 2) / _LOSdist];
			_LOS = true;
			for [{_j = 20}, {(_j < (_LOSdist - 10)) && _LOS}, {_j = _j + 20}] do {
				_posH = [(_LOSorigin select 0) + (_LOSvector select 0) * _j, (_LOSorigin select 1) + (_LOSvector select 1) * _j, (_LOSorigin select 2) + (_LOSvector select 2) * _j];
				_posT = [_posH select 0, _posH select 1, getTerrainHeightASL [_posH select 0, _posH select 1]];
				
				_AX = _LOSorigin select 0;	_AY = _LOSorigin select 1;	_AZ = _LOSorigin select 2;
				_HX = _posH select 0;	_HY = _posH select 1;	_HZ = _posH select 2;
				_TX = _posT select 0;	_TY = _posT select 1;	_TZ = _posT select 2;
				
				_LOSdistH = (getPos _vehicle) distance _posH;
				_LOSdistT = (getPos _vehicle) distance _posT;
				
				//TRACE_4("",_posH,_posT,_AZ,_TZ);
				_tt = if (_AZ - _HZ == 0) then {0.0001} else {_AZ - _HZ};
				_viewAngleH = atan(_LOSdistH / _tt);
				if (_viewAngleH < 0) then { _viewAngleH = 360 + _viewAngleH };
				_tt = if (_AZ - _TZ == 0) then {0.0001} else {_AZ - _TZ};
				_viewAngleT = atan(_LOSdistT / _tt);
				if (_viewAngleT < 0) then { _viewAngleT = 360 + _viewAngleT };
				
				if (_viewAngleH < _viewAngleT) then { _LOS = false };
			};
			if (!_LOS && {!(_threat in _invisibleThreats)}) then { _invisibleThreats set [count _invisibleThreats, _threat] };
		};
		
		if (count (_threats - _invisibleThreats) > 0) then {
			if !(_RWRopen) then {
				135737 cutRsc ["ACE_RWR_RU","PLAIN"];
				_RWRopen = true;
				// INITIATE SPO15
				call FUNC(clearAllControls);
			};
		
			for "_y" from 0 to (count _threats - 1) do {
				_threat = _threats select _y;
				
				// PRIORITIY TYPES
				/* On Primary threat:
				 - Big direction indicator lamps light up
				 - Small direction indicator lamps light up
				 - Big type indicator lamp lights up
				 - Small type indicator lamp lights up
				
				 On Secondary threat:
				 - Small direction indicator lamps light up
				 - Small type indicator lamp lights up
				
				 Maximum 6 primary threats can be displayed
				 N, 3, X, H, F, C = All Big type indicator lamps light up && All Small type indicator lamps light up
				
				 Maximum 6 secondary threats can be displayed
				 All small type indicator lamps light up */
				
				/* Aircraft is always a primary threat!  */
				_type = if (_threat isKindOf "Plane") then { "PRIMARY" } else { "SECONDARY" };
				
				/* If there is only one threat available, it becomes the primary threat - even if it is a secondary class threat  */
				if (count _threats == 1) then { _type = "PRIMARY" };
				/* Once there is a primary class threat detected, priority switches back again */
				//if (_type == "PRIMARY") then { _vehicle setVariable [QGVAR(primary_threat),_threat]; };
				
				// GET DIRECTION TOWARDS OWN AIRCRAFT
				if (_threat in _threats && {!(_threat in _invisibleThreats)}) then {
					//GET VECTOR POSITIONS
					_p1 = getPos _vehicle;
					_p2 = getPos _threat;
					_AX = _p1 select 0;
					_BX = _p2 select 0;
					_AY = _p1 select 1;
					_BY = _p2 select 1;
					
					_dir = (_BX - _AX) atan2 (_BY - _AY); // 180 to -180 degree
					// RELATIVE TO VEHICLE
					_dir = _dir - getDir _vehicle;
					if (_dir < 0) then { _dir = 360 + _dir; };
					if (_dir > 180) then { _dir = _dir - 360; };
					_dir = round _dir;
					
					// GET DIRECTION
					switch (true) do {
						// LEFT
						// 10
						case (_dir < 0 && {_dir >= -10}) : { _dir_index = [[0,0]]; };
						// 10 + 30
						case (_dir < -10 && {_dir > -30}) : { _dir_index = [[0,0],[1,0]]; };
						// 30
						case (_dir == -30) : { _dir_index = [[1,0]]; };
						// 30 + 50
						case (_dir < -30 && {_dir > -50}) : { _dir_index = [[1,0],[2,0]]; };
						// 50
						case (_dir == -50) : { _dir_index = [[2,0]]; };
						// 50 + 90
						case (_dir < -50 && {_dir > -90}) : { _dir_index = [[2,0],[3,0]]; };
						// 90
						case (_dir == -90) : { _dir_index = [[3,0]]; };
						// > 90
						case (_dir < -90) : { _dir_index = [[4,0]]; };
						
						// RIGHT
						// 10
						case (_dir > 0 && {_dir <= 10}) : { _dir_index = [[0,1]]; };
						// 10 + 30
						case (_dir > 10 && {_dir < 30}) : { _dir_index = [[0,1],[1,1]]; };
						// 30
						case (_dir == 30) : { _dir_index = [[1,1]]; };
						// 30 + 50
						case (_dir > 30 && {_dir < 50}) : { _dir_index = [[1,1],[2,1]]; };
						// 50
						case (_dir == 50) : { _dir_index = [[2,1]]; };
						// 50 + 90
						case (_dir > 50 && {_dir < 90}) : { _dir_index = [[2,1],[3,1]]; };
						// 90
						case (_dir == 90) : { _dir_index = [[3,1]]; };
						// > 90
						case (_dir > 90) : {  _dir_index = [[4,1]];};
					};
				
					//DISPLAY THREAT ON RWR UI
					_type_index = getNumber(configFile >> "CfgVehicles" >> typeOf _threat >> QGVAR(threat_img_spo));
					
					//NEW THREAT
					if !(_threat in _lastScan) then {
						_lastScan set [count _lastScan, _threat];
					};
					// AUDIO
					playSound ["ACE_SPO15_TRACK",true];
					// THREAT TYPE DISPLAY
					[_type,_type_index,true] call FUNC(showThreatTypes);
					
					// THREAT DIRECTION DISPLAY
					[_type,_dir_index,true] call FUNC(showThreatDirection);
					
					// SIGNAL STRENGTH PRIMARY
					[_type,_threat,_vehicle] call FUNC(displaySignalStrength);

					//LAUNCH
					if (_threat == GVAR(fireSource)) then {
						_launched = _vehicle getVariable [QGVAR(LaunchWarning),false];
						if (!_launched) then {
							[_vehicle] call FUNC(displayLaunchWarning);
						};
					} else {
						GVAR(fireSource) = objNull;
					};
					sleep _scanInterval0;
				} else {
					//THREAT IS ACTIVE BUT OUT OF RANGE
					if (_threat in _lastScan) then {_lastScan = _lastScan - [_threat] };
					if (_threat == GVAR(fireSource)) then { GVAR(fireSource) = objNull };
					if (_RWRopen && {count (_threats - _invisibleThreats) <= 0}) then {
						135737 cutRsc ["Default","PLAIN"];
						_vehicle setVariable [QGVAR(LaunchWarning),false];
						_RWRopen = false;
					};
					// RESET 
					[_type,_type_index,false] call FUNC(showThreatTypes);
				}; //END IF (_vehicle distance _threat > _RWRrange)
				//DEBUG
				#ifdef DEBUG_MODE_FULL
				if (_RWRopen) then { hintSilent Format["DISTANCE:\n%1\n\nABSOLUTE ANGLE:\n%2\n\nRELATIVE ANGLE:\n%3\n\nScreen Pos:\n%4,%5\n\nRWR Pos:\n%6,%7\n\nThreat Pos:\n%8,%9\n\nQUADRANT:\n%10\n\nFIRE SOURCE:\n%11\n\nAGE:\n%12\n\nTYPE:\n%13",_vehicle distance _threat,_absoluteAngle,_relativeAngle,_RWRposX,_RWRposY+0.005,_AX,_AY,_BX,_BY,_quadrant,GVAR(fireSource),0,typeOf _threat] };
				#endif
			}; //END for (threats)
		} else {
			//NO THREATS
			_lastScan = [];
			135737 cutRsc ["Default","PLAIN"];
			_RWRopen = false;
			_vehicle setVariable [QGVAR(LaunchWarning),false];
			GVAR(fireSource) = objNull;
		}; //END if (count _threats > 0)
	} else {
		//NO THREATS
		_lastScan = [];
		135737 cutRsc ["Default","PLAIN"];
		_RWRopen = false;
		_vehicle setVariable [QGVAR(LaunchWarning),false];
		GVAR(fireSource) = objNull;
	}; //END if (count _nearStuff > 0)
	sleep _scanInterval;
	//CLEANING
	_rmthreats = [];
	for "_y" from 0 to (count _threats - 1) do {
		_threat = _threats select _y;
		if (damage _threat > 0.9  && {_threat in _threats})	then { //THREAT DESTROYED
			_rmthreats set [count _rmthreats, _threat];
			#ifdef DEBUG_MODE_FULL
				_crew globalChat "THREAT DESTROYED, REMOVED";
			#endif
		};
		if (_threat distance _vehicle > (_RWRrange * 0.8)) then { //THREAT OUT OF RANGE
			_rmthreats set [count _rmthreats, _threat];
			#ifdef DEBUG_MODE_FULL
				_crew globalChat "THREAT OUT OF RANGE, REMOVED";
			#endif
		};
	};
	if (count _rmthreats > 0) then {
		_threats = _threats - _rmthreats;
		_oldThreats = _oldThreats - _rmthreats;
		_lastScan = _lastScan - _rmthreats;
		_threats = _threats - [objNull];
		_oldThreats = _oldThreats - [objNull];
		_lastScan = _lastScan - [objNull];
	};
}; //END While Main Loop

135737 cutRsc ["Default","PLAIN"];
_vehicle setVariable [QGVAR(LaunchWarning),false];
_vehicle removeEventHandler ["IncomingMissile", _incomingeh];