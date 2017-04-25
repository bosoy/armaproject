// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_5(_vehicle,_weapon,_realLaser,_laserObject,_newLaser);

if (_newLaser) then {
	_handle = [
		{
			if !(isNull _laserObject) then {
				_newPos = getPosASL _laserObject;
				// Only broadcast if position is different
				if (str(_newPos) != _oldPos) then {
					TRACE_2("Laser newPos",_newPos,_oldPos);
					_oldPos = str(_newPos);
					_vehicle setVariable [QGVAR(opticalTarget), _newPos];
				};
				// Laser code
				_laserCode = _vehicle getVariable ["ACE_CURRENT_LASERTARGET_CODE", 1001];
				if ((_laserObject getVariable ["ACE_LASERTARGET_CODE", 1001]) != _laserCode) then {
					_laserObject setVariable ["ACE_LASERTARGET_CODE", _laserCode, true];
				};
				if (isNull _tarVeh) then {
					{ 
						if !(_x isKindOf "StaticWeapon") exitWith { 
							_tarVeh = _x 
						} 
					} forEach ((position _laserObject) nearEntities [["LandVehicle", "Air", "Ship"],12]);
				} else {
				// Reset lasertarget if too far from laser object
					if (_tarVeh distance _laserObject > 12) then {
						_tarVeh = objNull;
					} else {
						if (_tarVeh getVariable ["ace_targeted_time",0] < (time - 30)) then {
							TRACE_3("Triggering incoming lasertarget for",_tarVeh,_vehicle,_laserObject);
							["ace_lasertarget", [_vehicle, _tarVeh, _laserObject]] spawn CBA_fnc_globalEvent;
						};
					};
				};
			} else {
				_laserObject = laserTarget _vehicle;
				if !(isNull _laserObject) then {
					_vehicle setVariable [QGVAR(laserObject), _laserObject];
					if (_realLaser) then {
						_laserObject setVariable ["SPON_RF_owner", name (effectiveCommander _vehicle), true]; // compatible with sys_rangefinder
						_laserObject setVariable ["ace_RF_owner",player,true];
					} else {
					// Invisible laser; still visible on laserscanner, but ignored by AI otherwise
						_laserObject hideObject true;
						_laserObject setDamage 1;
					};
				};
			};
		},
		[_vehicle,_realLaser], /* parameters */
		0.01, // delay
		{ /* init code */
			_vehicle = _this select 0;
			_realLaser = _this select 1;
			TRACE_2("PARAMS_2",_vehicle,_realLaser);
			
			// Initialize vars.
			_laserObject = objNull;
			_newPos = [0,0,0];
			_oldPos = "";
			_vehicle setVariable [QGVAR(opticalTarget), [0,0,0]];
			_tarVeh = objNull;
			_timePrev = time;
			
			// Create lasertarget
			if (isNull laserTarget _vehicle) then {
				_vehicle fireAtTarget [objNull,"ACE_Laserdesignator_Hidden"];
			};
		},
		{ /* exit code */
			_weapon = currentWeapon _vehicle;
			if !(isNull laserTarget _vehicle) then {
				_vehicle fireAtTarget [objNull,"ACE_Laserdesignator_Hidden"];
			};
			if ("Laserbatteries" in magazines _vehicle) then {
				_vehicle removeMagazine "Laserbatteries";
			};
			if ("ACE_Laserdesignator_Hidden" in weapons _vehicle) then {
				_vehicle removeWeapon "ACE_Laserdesignator_Hidden";
			};
			_vehicle selectWeapon _weapon;
			// Reset on exit.
			_vehicle setVariable [QGVAR(laser_designation), nil];
			_vehicle setVariable [QGVAR(laser_working), nil];
			_vehicle setVariable [QGVAR(laser_off), nil];
			TRACE_1("Laserloop exit",nil);
		},
		{ /* Run condition - default true */
			!isNull laserTarget _vehicle
		},
		{!((player == gunner _vehicle) && {(alive _vehicle)} && {(isNil {_vehicle getVariable QGVAR(laser_off)})})}, /* exit condition */
		[ /* Private variables, available throughout all states and conditions */
			"_vehicle", "_realLaser",
			"_laserObject", "_tarVeh", "_newPos","_oldPos"
		]
	] call cba_common_fnc_addPerFrameHandlerLogic;
} else { // Keep old functionality if one still runs 1.60 stable. Remove productVersion check after next stable patch
	_handle = [
		{
			// Start out in front of the vehicle.
			_aidPos = getPosASL _aidPoV;

			// This script runs every frame
			// The lasermarker is updated every 2 frames. 1 frame to fire, 1 frame to receive range
			// Except that if the position hasn't changed since last time, then it will not broadcast needlessly
			if !(isNull _pulse) then {
				_unset = true;
				_pulsePos = getPosASL _pulse;
				_range = _pulsePos distance _aidPos;

				if ((_range > 25) && {(_range < 9999)}) then {
					_magn = (velocity _pulse) call ACE_fnc_magnitude;
					TRACE_3("In range",_range,_pulsepos,_magn);
					_newPos = _pulsePos;
					_invalidPos = false;
					_validRange = _range;

					// Helper due to pulse not dieying immediately even though it's stopped
					if (_magn < 0.002) then {
						deleteVehicle _pulse;
						_pulse = objNull;
					};
				} else {
					if (_range > 9999) then {
						_validRange = 9999;
						deleteVehicle _pulse;	// Quit, allow new instance ASAP!
						_pulse = objNull;
					};
					_invalidPos = true;
				};
			};
			
			if (isNull _pulse) then {
				if (_unset) then {
					_unset = false;

					if (_invalidPos) then {
						// Get direction of the weapon. The pulse will be fired along the bore axis.
						if (_tracker in _weapons) then {
							_laserVec = _vehicle weaponDirection _tracker
						} else {
							if(!_sensorOnly) then {
								if (_aidEnd distance _aidBeg > 0) then {
									_laserVec = ([getPosASL _aidEnd, getPosASL _aidBeg] call BIS_fnc_vectorDiff) call FUNC(mat_normalize3d)
								} else {
									_laserVec = [0,0,1] // fubar
								};
							} else {
								_pos1 = [_vehicle, _sensorSelection] call cba_fnc_modelToWorldASL;
								_pos2 = [_vehicle, _sensorPoint] call cba_fnc_modelToWorldASL;
								_laserVec = [_pos1, _pos2] call ACE_fnc_vectorFromXToY;
							};
						};
						_newPos = [(_aidPos select 0) + (_laserVec select 0)*_validRange, (_aidPos select 1) + (_laserVec select 1)*_validRange, (_aidPos select 2) + (_laserVec select 2)*_validRange];
						TRACE_3("Check",_laserVec,_newPos,_validRange);
						TRACE_2("Outside range",_range,_pulsepos);
					};

					// Only broadcast if position is different
					if (str(_newPos) != _oldPos) then {
						TRACE_2("SetPos",_newPos,_oldPos);
						_oldPos = str(_newPos);
						_vehicle setVariable [QGVAR(opticalTarget), +_newPos];
						(_vehicle getVariable QGVAR(laserObject)) setPosASL _newPos;
					};
					_laserObj = (_vehicle getVariable QGVAR(laserObject));
					_laserCode = _vehicle getVariable ["ACE_CURRENT_LASERTARGET_CODE", 1001];
					if((_laserObj getVariable ["ACE_LASERTARGET_CODE", 1001]) != _laserCode) then {
						_laserObj setVariable ["ACE_LASERTARGET_CODE", _laserCode, true];
					};
					if (_realLaser && {!_invalidPos}) then {
						if (isNull _tarVeh) then {
							{ 
								if !(_x isKindOf "StaticWeapon") exitWith { 
									_tarVeh = _x 
								} 
							} forEach (position (_vehicle getVariable QGVAR(laserObject))) nearEntities [["LandVehicle", "Air", "Ship"], 12];
							if !(isNull _tarVeh) then {
								TRACE_3("Triggering incoming lasertarget for",_tarVeh,_vehicle,(_vehicle getVariable QGVAR(laserObject)));
								["ace_lasertarget", [_vehicle, _tarVeh, (_vehicle getVariable QGVAR(laserObject))]] spawn CBA_fnc_globalEvent;
							};
						};
					};
				} else {
					if (time > _prevTime) then {
						_prevTime = time; // Used for HeatUp time, only when initiating the laser

						// Get direction of the weapon. The pulse will be fired along the bore axis.
						if (_tracker in _weapons) then {
							_laserVec = _vehicle weaponDirection _tracker
						} else {
							if(!_sensorOnly) then {
								_laserVec = if (_aidEnd distance _aidBeg > 0) then {
									([getPosASL _aidEnd, getPosASL _aidBeg] call BIS_fnc_vectorDiff) call FUNC(mat_normalize3d)
								} else {
									[0,0,1] // fubar
								};
							} else {
								_pos1 = [_vehicle, _sensorSelection] call cba_fnc_modelToWorldASL;
								_pos2 = [_vehicle, _sensorPoint] call cba_fnc_modelToWorldASL;
								_laserVec = [_pos1, _pos2] call ACE_fnc_vectorFromXToY;
							};
						};
						// Offset to avoid collision with shooter
						_pulsePos = [(_aidPos select 0) + (_laserVec select 0)*15, (_aidPos select 1) + (_laserVec select 1)*15, (_aidPos select 2) + (_laserVec select 2)*15];

						_invalidPos = true;
						_pulse = "ACE_MissileGuidance_LaserPulse" createVehicleLocal [0,0,1000];
						_pulse setPosASL _pulsePos; // TODO: Do not keep setPossing the same position over and over. Perhaps even within a certain error range..
						_range = 0;
						_pulse setVelocity [(_laserVec select 0) * _spd, (_laserVec select 1) * _spd, (_laserVec select 2) * _spd];
					};
				};
			};
		},
		[_vehicle,_weapon,_realLaser,_laserObject], /* parameters */
		0, // delay
		{ /* init code */
			_vehicle = _this select 0;
			_weapon = _this select 1;
			_realLaser = _this select 2;
			_laserObject = _this select 3;
			TRACE_4("PARAMS_4",_vehicle,_weapon,_realLaser,_laserObject);
			// Disabled for private issue - PARAMS_4(_vehicle,_weapon,_realLaser,_laserObject);

			_oldPos = "";

			// Initialize vars.
			_newPos = [0,0,0];
			_vehicle setVariable [QGVAR(opticalTarget), [0,0,0]];
			_spd = 600000;	// we don't have personal supercomputers yet. 50 times lower speed of "laser projectile" is still enormous for nowadays computers - A2 is no space simulation :)
			_tarVeh = objNull;
			_validRange = 9998;

			_gunnerInfo = [_vehicle, _weapon] call CBA_fnc_getFirer;
			_turret = [_vehicle, _gunnerInfo select 1] call CBA_fnc_getTurret;
			/*
			ace_sys_missile_guidance_sensorOnly = 1;
					ace_sys_missile_guidance_sensorSelection[] = {-0.0255, 1.3716, 1.306};
					ace_sys_missile_guidance_sensorPoint = "gunnerview";
			*/
			_sensorOnly = getNumber (_turret >> QGVAR(sensorOnly));
			_sensorSelection = "";
			_sensorPoint = "";
			if(_sensorOnly == 1) then {
				_sensorOnly = true;
				if(isArray (_turret >> QGVAR(sensorSelection))) then {
					_sensorSelection = getArray (_turret >> QGVAR(sensorSelection));
				} else {
					_sensorSelection = getText (_turret >> QGVAR(sensorSelection));
				};
				_sensorPoint = getText (_turret >> QGVAR(sensorPoint));
			} else {
				_sensorOnly = false;
			};
			
			_pov = getText (_turret >> "memoryPointGunnerOptics");
			_gunBeg = getText (_turret >> "gunBeg");
			_gunEnd = getText (_turret >> "gunEnd");
			_tracker = getText (_turret >> QGVAR(tracker));
			_weapons = weapons _vehicle;

			_aidPoV = objNull;
			_aidBeg = objNull;
			_aidEnd = objNull;

			_aidPoV = "ACE_LogicDummy" createVehicleLocal [0,0,0];
			_aidBeg = "ACE_LogicDummy" createVehicleLocal [0,0,0];
			_aidEnd = "ACE_LogicDummy" createVehicleLocal [0,0,1];

			// Attachment problems
			_aidPoV attachTo [_vehicle,[0,0,0],_pov];
			_aidBeg attachTo [_vehicle,[0,0,0],_gunBeg];
			_aidEnd attachTo [_vehicle,[0,0,0],_gunEnd];

			TRACE_3("Names",_pov,_gunBeg,_gunEnd);

			#ifdef DEBUG_MODE_FULL
				[_vehicle getVariable QGVAR(laserObject), getPosASL (_vehicle getVariable QGVAR(laserObject))] spawn ace_fnc_track;
			#endif

			_unset = false;
			_invalidPos = false;
			_pulse = objNull;

			_prevTime = time + 0.1;	//heat up
		},
		{ /* exit code */
			{deleteVehicle _x} forEach [_aidPoV,_aidBeg,_aidEnd,_vehicle getVariable QGVAR(laserObject)];

			// Reset on exit.
			_vehicle setVariable [QGVAR(laser_designation), nil];
			_vehicle setVariable [QGVAR(laser_working), nil];
			_vehicle setVariable [QGVAR(laser_off), nil];
			TRACE_1("Laserloop exit",nil);
		},
		{ /* Run condition - default true */
			_r = false;
			if (_aidEnd distance _vehicle < 10) then {
				if (_aidBeg distance _vehicle < 10) then {_r = _aidPoV distance _vehicle < 10}
			};
			_r;
		},
		{!((player == gunner _vehicle) && {(alive _vehicle)} && {(isNil {_vehicle getVariable QGVAR(laser_off)})})}, /* exit condition */
		[ /* Private variables, available throughout all states and conditions */
			"_prevTime", "_spd", "_laserVec",
			"_vType", "_vehicle",
			"_pov", "_gunBeg", "_gunEnd",
			"_turret", "_gunnerInfo",
			"_weapons", "_tracker",
			"_aidPoV", "_aidPos",
			"_aidBeg", "_aidEnd",
			"_designation", "_realLaser",
			"_pulse", "_pulsePos",
			"_laserObject", "_tarVeh", "_unset",
			"_newPos", "_invalidPos", "_validRange", "_range",
			"_sensorOnly", "_sensorSelection", "_sensorPoint",
			"_oldPos"
		]
	] call cba_common_fnc_addPerFrameHandlerLogic;
};
