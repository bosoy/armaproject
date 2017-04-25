//#define DEBUG_MODE_FULL
#include "script_component.hpp"

//////////////////////////////////////////////////////////////////
//Function file for Armed Assault
//Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// Completed on April the 8th, 2011
//
//CREDITS:
//Coding and Graphics: Reezo
//UI help: Xeno
//RWR information: Nou, Ozzy, Hornet, Shumann
//Radio Visibility Check Tips: Mandoble, SickBoy, Jaynus, Nou
//Sounds provided by Trips, courtesy of OpenFalcon
//Beta Testing: SR5 Tactical
//////////////////////////////////////////////////////////////////


#define __TYPE (getText(configFile >> "CfgVehicles" >> typeOf _vehicle >> QGVAR(type)))
PARAMS_1(_vehicle);

private ["_crew"];
_crew = player;

sleep 1;

disableSerialization;

//INIT
private ["_type","_threats","_threatsAge","_lastScan","_RWRopen","_MaxTargets","_scanInterval","_RWRrange","_oldThreats"];
_type = 0;
_threats = [];
_threatsAge = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
_lastScan = [];
_oldThreats = [];
_RWRopen = false;

// CUSTOMIZABLE PARAMETERS (BASICALLY THE ONLY THING YOU CAN CHANGE HERE)
_maxTargets = 16; // RWR maximum number of targets on-screen
_scanInterval = 0.25; //RWR scan interval in seconds
_RWRrange = getNumber(configFile >> "CfgVehicles" >> typeOf _vehicle >> QGVAR(range)); //RWR range in meters

_skin = getText(CFGSETTINGS >> __TYPE >> QGVAR(skin));
_detectMissile = getNumber(CFGSETTINGS >> __TYPE >> QGVAR(detectMissile));

if (_RWRrange == 0) then {_RWRrange = 3600};

//INCOMING MISSILE EVENT HANDLER
GVAR(fireSource) = objNull;
private ["_incomingeh"];
_incomingeh = _vehicle addEventHandler ["IncomingMissile", {GVAR(fireSource) = _this select 2}];

//DEFINE
#define CTRL(A) ((uiNamespace getVariable "ACE_RWR_US") displayCtrl A)
#define SKIN 21999
#define THREATS_BASE 22000
#define THREATS_NEW 22020
#define THREATS_GROUND 22040
#define THREATS_AIR 22060
#define THREATS_LAUNCH 22080
#define SR5RWR_display_width 0.22
#define SR5RWR_display_height 0.2934

//UI POSITION SETTINGS
private ["_midx","_midy"];

// USE THESE WHEN THE RWR IS PLACED BOTTOM-RIGHT
//_midX = SafeZoneX + SafeZoneW - (SR5RWR_display_width / 2) - 0.01 - 0.0075;
//_midY = SafeZoneY + SafeZoneH - (SR5RWR_display_height / 2) - 0.01 - 0.01;

// USE THESE WHEN THE RWR IS PLACED TOP-LEFT
//_midX = SafeZoneX + 0.001 + (SR5RWR_display_width / 2);
//_midY = SafeZoneY + (SR5RWR_display_height / 2);

// ((uiNamespace getVariable "ACE_RWR_US") displayCtrl 21999)

_oldrwrposset = -1;

//BEGIN MAIN LOOP
private ["_nearStuff","_maxTargets","_threat","_invisibleThreats"];
private ["_LOSorigin","_LOSend","_LOSh","_LOSdist","_LOSvector","_LOS","_posH","_posT","_viewAngleH","_viewAngleT"];
private ["_AX","_AY","_AZ","_BX","_BY","_BZ","_HX","_HY","_HZ","_TX","_TY","_TZ"];
private ["_diffX","_diffY","_absoluteAngle","_relativeAngle","_quadrant","_quadrantFactor","_scaleX","_scaleY","_RWRposX","_RWRposY"];
private ["_age","_threatsAge","_launcher"];
private ["_new_rwr_xpos", "_new_rwr_ypos", "_old_rwr_xpos", "_old_rwr_ypos"];
_old_rwr_xpos = -2;
_old_rwr_ypos = -2;
while { (_crew == driver _vehicle || {_crew == gunner _vehicle} || {_crew == commander _vehicle}) && {alive _crew} && {alive _vehicle} } do {
	_rwr_set_pos = ["ACE", "sys_air_rwr", "resource_pos"] call ace_settings_fnc_getNumber;
	TRACE_1("",_rwr_set_pos);
	if (_oldrwrposset != _rwr_set_pos) then {
		switch (_rwr_set_pos) do {
			case 0: {
				_midX = SafeZoneX + SafeZoneW - (SR5RWR_display_width / 2) - 0.01 - 0.0075;
				_midY = SafeZoneY + SafeZoneH - (SR5RWR_display_height / 2) - 0.01 - 0.01;
				_new_rwr_xpos = SafeZoneX + SafeZoneW - 0.01 - SR5RWR_display_width;
				_new_rwr_ypos = SafeZoneY + SafeZoneH - 0.01 - SR5RWR_display_height;
			};
			case 1: {
				_midX = SafeZoneX + SafeZoneW - (SR5RWR_display_width / 2) - 0.01 - 0.0075;
				_midY = SafeZoneY + (SR5RWR_display_height / 2);
				_new_rwr_xpos = SafeZoneX + SafeZoneW - 0.01 - SR5RWR_display_width;
				_new_rwr_ypos = SafeZoneY + 0.01;
			};
			case 2: {
				_midX = SafeZoneX + 0.0025 + (SR5RWR_display_width / 2);
				_midY = SafeZoneY + (SR5RWR_display_height / 2);
				_new_rwr_xpos = SafeZoneX + 0.01;
				_new_rwr_ypos = SafeZoneY + 0.01;
			};
			case 3: {
				_midX = SafeZoneX + 0.0025 + (SR5RWR_display_width / 2);
				_midY = SafeZoneY + SafeZoneH - (SR5RWR_display_height / 2) - 0.01 - 0.01;
				_new_rwr_xpos = SafeZoneX + 0.01;
				_new_rwr_ypos = SafeZoneY + SafeZoneH - 0.01 - SR5RWR_display_height;
			};
		};
		_oldrwrposset = _rwr_set_pos;
	};
	TRACE_4("",_midX,_midY,_new_rwr_xpos,_new_rwr_ypos);
	
	//GATHER ALL NEARBY CARS AND TANKS
	_nearStuff = getPos _vehicle nearEntities [["air","tank"], _RWRrange * 0.8];
  
	//SET NUMBER OF TARGETS
	_maxTargets = if (count _nearStuff < 16) then {count _nearStuff} else {16};
  
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
			if (_vehicle isKindOf "AH64D_EP1" || {_vehicle isKindOf "BAF_Apache_AH1_D"}) then {
				_LOSorigin set [2, (_LOSorigin select 2) + 4 ];
			} else {
				_LOSorigin set [2, (_LOSorigin select 2) + 0 ];
			};
			_LOSend = getPosASL _threat;
			//_LOSend set [2,getTerrainHeightASL _LOSend];
			_LOSdist = _vehicle distance _threat;
			_posH = _vehicle worldToModel [_LOSend select 0, _LOSend select 1, (_LOSend select 2) + 0];
			_LOSvector = [(_posH select 0) / _LOSdist, (_posH select 1) / _LOSdist, (_posH select 2) / _LOSdist];
			_LOS = true;
			for [{_j = 20}, {_LOS && {(_j < (_LOSdist - 10))}}, {_j = _j + 20}] do {
				_posH = [(_LOSorigin select 0) + (_LOSvector select 0) * _j, (_LOSorigin select 1) + (_LOSvector select 1) * _j, (_LOSorigin select 2) + (_LOSvector select 2) * _j];
				_posT = [_posH select 0, _posH select 1, getTerrainHeightASL [_posH select 0, _posH select 1]];
				
				_AX = _LOSorigin select 0;	_AY = _LOSorigin select 1;	_AZ = _LOSorigin select 2;
				_HX = _posH select 0;	_HY = _posH select 1;	_HZ = _posH select 2;
				_TX = _posT select 0;	_TY = _posT select 1;	_TZ = _posT select 2;
				
				_LOSdistH = (getPos _vehicle) distance _posH;
				_LOSdistT = (getPos _vehicle) distance _posT;
				
				TRACE_4("",_posH,_posT,_AZ,_TZ);
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
				135737 cutRsc ["ACE_RWR_US","PLAIN"];
				_RWRopen = true;
				_ctrlepos = ctrlPosition CTRL(SKIN);
				_ctrlepos set [0, _new_rwr_xpos];
				_ctrlepos set [1, _new_rwr_ypos];
				_old_rwr_xpos = _new_rwr_xpos;
				_old_rwr_ypos = _new_rwr_ypos;
				CTRL(SKIN) ctrlSetPosition _ctrlepos;
				CTRL(SKIN) CtrlSetText _skin;
				CTRL(SKIN) ctrlCommit 0;
			};
			
			if (_RWRopen) then {
				if (_old_rwr_xpos != _new_rwr_xpos || {_old_rwr_ypos != _new_rwr_ypos}) then {
					_ctrlepos = ctrlPosition CTRL(SKIN);
					_ctrlepos set [0, _new_rwr_xpos];
					_ctrlepos set [1, _new_rwr_ypos];
					_old_rwr_xpos = _new_rwr_xpos;
					_old_rwr_ypos = _new_rwr_ypos;
					CTRL(SKIN) ctrlSetPosition _ctrlepos;
					CTRL(SKIN) ctrlCommit 0;
				};
			};
		
			for "_y" from 0 to (count _threats - 1) do {
				_threat = _threats select _y;
				
				_type = if (_threat isKindOf "Air") then {1} else {0};
				
				if (_threat in _threats && {!(_threat in _invisibleThreats)}) then {
					//GET VECTOR POSITIONS
					_AX = (getPos _vehicle) select 0;
					_BX = (getPos _threat) select 0;
					_AY = (getPos _vehicle) select 1;
					_BY = (getPos _threat) select 1;
					
					//GET VECTOR ANGLE INFORMATION COMPARED TO X-Y AXIS
					_diffX = _AX < _BX;
					_diffY = _AY < _BY;
					
					switch (true) do {
						case (_diffX && {!_diffY}): {_quadrantFactor = +000; _quadrant = 1;	}; //QUADRANT 1
						case (!_diffX && {!_diffY}): {_quadrantFactor = +090; _quadrant = 2;	}; //QUADRANT 2
						case (_diffX && {_diffY}): {_quadrantFactor = -090; _quadrant = 3; 	}; //QUADRANT 3
						case (!_diffX && {_diffY}): {_quadrantFactor = +180; _quadrant = 4;	}; //QUADRANT 4
					};
					
					_absoluteAngle = if (_quadrant in [1,4]) then {
						abs(atan((_AY-_BY)/(_AX-_BX)));
					} else {
						abs(atan((_AX-_BX)/(_AY-_BY)));
					};
					_relativeAngle = - ((getDir _vehicle) - _absoluteAngle) + _quadrantFactor;

					//TRANSLATE THE ABOVE TO UI VALUES
					_scaleX = (SR5RWR_display_width / 2) * (_vehicle distance _threat) / (_RWRrange + 0);
					_scaleY = (SR5RWR_display_height / 2) * (_vehicle distance _threat) / _RWRrange;
					_RWRposX = _midX + (cos _relativeAngle * _scaleX);
					_RWRposY = _midY + (sin _relativeAngle * _scaleY);
				
					//DISPLAY THREAT ON RWR UI
					
					//NEW THREAT
					if !(_threat in _lastScan) then {
						_lastScan set [count _lastScan, _threat];
						//SOUND
						switch (_type) do {
							case 0: {
								_generic = true;
								if (_threat isKindOf "2S6M_Tunguska") then { playSound "ACE_SR5RWR_tunguska"; _generic = false;	};
								if (_threat isKindOf "ZSU_TK_EP1" || {_threat isKindOf "ZSU_INS"} || {_threat isKindOf "ACE_ZSU_RU"}) then { playSound "ACE_SR5RWR_shilka"; _generic = false; };  // TODO: Add sound string to config ?
								if (_generic) then { playSound "ACE_SR5RWR_generic" };
							};
							case 1: {
								playSound "ACE_SR5RWR_air";
							};
						};
						//IMAGE
						if !(_threat in _oldThreats) then {
							CTRL(THREATS_NEW + _y) ctrlSetPosition [_RWRposX - 0.007, _RWRposY - 0.012, 0.029, 0.032];
							CTRL(THREATS_NEW + _y) CtrlSetText QPATHTO_T(data\rsc\threat_new.paa);
							CTRL(THREATS_NEW + _y) ctrlCommit 0;
						} else {
							CTRL(THREATS_NEW + _y) ctrlSetPosition [_RWRposX - 0.007, _RWRposY - 0.012, 0.029,0.032];
							CTRL(THREATS_NEW + _y) CtrlSetText "";
							CTRL(THREATS_NEW + _y) ctrlCommit 0;
						};
						switch (_type) do {
							case 0: {
								//BASIC GROUND THREAT ICON (SQUARE)
								CTRL(THREATS_GROUND + _y) ctrlSetPosition [_RWRposX - 0.005, _RWRposY + 0.00125, 0.025,0.032];
								CTRL(THREATS_GROUND + _y) CtrlSetText QPATHTO_T(data\rsc\threat_square.paa);
								//SET ICON POSITION
								CTRL(THREATS_BASE + _y) ctrlSetPosition [_RWRposX, _RWRposY + 0.005, 0.015, 0.022];
								_image = getText(configFile >> "CfgVehicles" >> typeOf _threat >> "ace_sys_air_rwr_threat_img");
								CTRL(THREATS_BASE + _y) CtrlSetText _image;
								//ADD NEW GROUND SYMBOLS HERE IF ANY
								CTRL(THREATS_BASE + _y) ctrlCommit 0;
								CTRL(THREATS_GROUND + _y) ctrlCommit 0;
							};
							case 1: {
								//BASIC AIR THREAT ICON (TRIANGLE)
								CTRL(THREATS_AIR + _y) ctrlSetPosition [_RWRposX-0.005, _RWRposY - 0.006, 0.025, 0.032];
								CTRL(THREATS_AIR + _y) CtrlSetText QPATHTO_T(data\rsc\threat_air.paa);
								//SET ICON POSITION
								CTRL(THREATS_BASE + _y) ctrlSetPosition [_RWRposX,_RWRposY+0.005,0.015,0.022];
								
								_image = getText(configFile >> "CfgVehicles" >> typeOf _threat >> "ace_sys_air_rwr_threat_img");
								CTRL(THREATS_BASE + _y) CtrlSetText _image;
								//ADD NEW AIR SYMBOLS HERE IF ANY
								CTRL(THREATS_BASE + _y) ctrlCommit 0;
								CTRL(THREATS_AIR + _y) ctrlCommit 0;
							};
						};
						sleep _scanInterval;
					} else {
						//OLD THREATS
						_Age = (_threatsAge select _y) + 1;
						_threatsAge set [_y,_Age];
						//REMOVE NEW THREAT NOTIFICATION
						if ((_threatsAge select _y) > 10 && !(_threat in _oldThreats)) then {
							CTRL(THREATS_NEW + _y) CtrlSetText "";
							CTRL(THREATS_NEW + _y) ctrlCommit 0;
							_oldThreats set [count _oldThreats, _threat];
						};
						//LAUNCH
						_launcher = GVAR(fireSource);
						if (_threat == _launcher && {_detectMissile == 1}) then {
							playSound "ACE_SR5RWR_launchIR";
							CTRL(THREATS_NEW + _y) ctrlSetPosition [(_RWRposX-0.007),(_RWRposY-0.012),0.029,0.032];
							CTRL(THREATS_NEW + _y) ctrlCommit 0;
							CTRL(THREATS_BASE + _y) ctrlSetPosition [_RWRposX,_RWRposY+0.005,0.015,0.022];
							CTRL(THREATS_BASE + _y) ctrlCommit 0;
							CTRL(THREATS_GROUND + _y) ctrlSetPosition [_RWRposX-0.005,_RWRposY+0.00125,0.025,0.032];
							CTRL(THREATS_GROUND + _y) ctrlCommit 0;
							CTRL(THREATS_AIR + _y) ctrlSetPosition [_RWRposX-0.005,_RWRposY-0.006,0.025,0.032];
							CTRL(THREATS_AIR + _y) ctrlCommit 0;
							CTRL(THREATS_LAUNCH + _y) ctrlSetPosition [_RWRposX-0.005,_RWRposY-0.006,0.025,0.032];
							CTRL(THREATS_LAUNCH + _y) CtrlSetText QPATHTO_T(data\rsc\threat_circle.paa);
							CTRL(THREATS_LAUNCH + _y) ctrlCommit 0;
							sleep 0.1;
							CTRL(THREATS_LAUNCH + _y) CtrlSetText "";
							CTRL(THREATS_LAUNCH + _y) ctrlCommit 0;
						} else {
							GVAR(fireSource) = objNull;
							CTRL(THREATS_NEW + _y) ctrlSetPosition [(_RWRposX-0.007),(_RWRposY-0.012),0.029,0.032];
							CTRL(THREATS_NEW + _y) ctrlCommit 0;
							CTRL(THREATS_BASE + _y) ctrlSetPosition [_RWRposX,_RWRposY+0.005,0.015,0.022];
							CTRL(THREATS_BASE + _y) ctrlCommit 0;
							CTRL(THREATS_GROUND + _y) ctrlSetPosition [_RWRposX-0.005,_RWRposY+0.00125,0.025,0.032];
							CTRL(THREATS_GROUND + _y) ctrlCommit 0;
							CTRL(THREATS_AIR + _y) ctrlSetPosition [_RWRposX-0.005,_RWRposY-0.006,0.025,0.032];
							CTRL(THREATS_AIR + _y) ctrlCommit 0;
						};
						sleep _scanInterval;
					};
				} else {
					//THREAT IS ACTIVE BUT OUT OF RANGE
					//if (_threat in _threats) then { _threats = _threats - [_threat] };
					if (_threat in _lastScan) then {_lastScan = _lastScan - [_threat] };
					if (_threat == GVAR(fireSource)) then { GVAR(fireSource) = objNull };
					_threatsAge set [_y,0];
					if (_RWRopen && {count (_threats - _invisibleThreats) <= 0}) then { 135737 cutRsc ["Default","PLAIN"]; _RWRopen = false; };
					CTRL(THREATS_BASE + _y) CtrlSetText "";
					CTRL(THREATS_BASE + _y) ctrlCommit 0;
					CTRL(THREATS_GROUND + _y) CtrlSetText "";
					CTRL(THREATS_GROUND + _y) ctrlCommit 0;
					CTRL(THREATS_AIR + _y) CtrlSetText "";
					CTRL(THREATS_AIR + _y) ctrlCommit 0;
					CTRL(THREATS_NEW + _y) CtrlSetText "";
					CTRL(THREATS_NEW + _y) ctrlCommit 0;
					CTRL(THREATS_LAUNCH + _y) CtrlSetText "";
					CTRL(THREATS_LAUNCH + _y) ctrlCommit 0;
				}; //END IF (_vehicle distance _threat > _RWRrange)
				//DEBUG
				#ifdef DEBUG_MODE_FULL
				if (_RWRopen) then { hintSilent Format["DISTANCE:\n%1\n\nABSOLUTE ANGLE:\n%2\n\nRELATIVE ANGLE:\n%3\n\nScreen Pos:\n%4,%5\n\nRWR Pos:\n%6,%7\n\nThreat Pos:\n%8,%9\n\nQUADRANT:\n%10\n\nFIRE SOURCE:\n%11\n\nAGE:\n%12\n\nTYPE:\n%13",_vehicle distance _threat,_absoluteAngle,_relativeAngle,_RWRposX,_RWRposY+0.005,_AX,_AY,_BX,_BY,_quadrant,GVAR(fireSource),_threatsAge select _y] };
				#endif
			}; //END for (threats)
		} else {
			//NO THREATS
			//_threats = [];
			_lastScan = [];
			135737 cutRsc ["Default","PLAIN"]; _RWRopen = false;
			GVAR(fireSource) = objNull;
		}; //END if (count _threats > 0)
	} else {
		//NO THREATS
		//_threats = [];
		_lastScan = [];
		135737 cutRsc ["Default","PLAIN"]; _RWRopen = false;
		GVAR(fireSource) = objNull;
	}; //END if (count _nearStuff > 0)
	sleep _scanInterval;
	//CLEANING
	_rmthreats = [];
	for "_y" from 0 to (count _threats - 1) do {
		_threat = _threats select _y;
		if (damage _threat > 0.9  && {_threat in _threats})	then { //THREAT DESTROYED
			_rmthreats set [count _rmthreats, _threat];
			_threatsAge set [_y,0];
			#ifdef DEBUG_MODE_FULL
			_crew globalChat "THREAT DESTROYED, REMOVED";
			#endif
		};
		if (_threat distance _vehicle > (_RWRrange * 0.8)) then { //THREAT OUT OF RANGE
			_rmthreats set [count _rmthreats, _threat];
			_threatsAge set [_y, 0];
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

_vehicle removeEventHandler ["IncomingMissile", _incomingeh];