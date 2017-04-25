//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfg configFile >> "CfgAmmo" >> _ammoType >> "ace_guidance_type"
#define SERVICE_INTERVAL	0.3
// firedEH for all vehicles, missiles only 
// Parameters
private ["_target", "_tarVeh", "_tarType", "_tarPos", "_tarVel", "_mode", "_laserCode","_fakeprojectile", "_mando"];
PARAMS_7(_vehicle,_weapon,_c,_d,_ammoType,_magazine,_projectile);
if !(isText(__cfg)) exitWith {};

_mando = if (isNil "mando_missile_setup_full") then { false } else { mando_missile_setup_full };
if (_mando) exitWith {};

_vehicle setVariable ["ACE_jammed", false];
_gunnerInfo = [_vehicle, _weapon] call CBA_fnc_getFirer;
_isPlayer = (_vehicle isKindOf "CAManBase" && {isPlayer _vehicle}) || {(isPlayer (_gunnerInfo select 0))} || {(isNull (_gunnerInfo select 0))};
_isManualFire = isManualFire _vehicle && {player == effectiveCommander _vehicle};
_isLocal = local (_gunnerInfo select 0);
_type = getText(__cfg);

_laserCode = _vehicle getVariable "ACE_CURRENT_LASERTARGET_CODE";
if (isNil "_laserCode") then {
	_laserCode = 1001;
	_vehicle setVariable ["ACE_CURRENT_LASERTARGET_CODE", 1001, false];
};
_projectile setVariable ["ACE_LASERTARGET_CODE", _laserCode, false];	// does it work at all?

_fakeprojectile = _projectile;

TRACE_4("",_vehicle,_gunnerInfo,_type, _laserCode);

switch _type do {
	case "saclos": { //Standard SACLOS
		_target = objNull;
		if (_isPlayer || {(_isManualFire && {_isLocal})}) then {
			[_vehicle, _weapon, false] spawn FUNC(opt_laserloop);
		} else {
			_target = _vehicle getVariable QGVAR(longbowTarget);
			if (isNil "_target") then {
				_target = objNull;
				TRACE_2("Warning. No target!",_vehicle,_projectile);
			} else {
				_vehicle setVariable [QGVAR(longbowTarget), nil];
			};
		};
		_turret = [_vehicle, _gunnerInfo select 1] call CBA_fnc_getTurret;
		if (isDedicated) then {
			// PerFrame doesn't work on Dedicated Servers
			[_vehicle, _projectile, _ammotype, "saclos", _weapon, _target, _turret, _isPlayer] call FUNC(missile_saclos);
		} else {
			[_vehicle, _projectile, _ammotype, "saclos", _weapon, _target, _turret, (_isPlayer || _isManualFire || isNull _target) && _isLocal] call FUNC(missile_saclos);
		};
	};

	case "shturm": { //Shturm-V - radio guided rangefinded SACLOS
		_target = objNull;
		if (_isPlayer || {(_isManualFire && {_isLocal})}) then {
			[_vehicle, _weapon, false] spawn FUNC(opt_laserloop);
		} else {
			_target = _vehicle getVariable QGVAR(longbowTarget);
			if (isNil "_target") then {
				_target = objNull;
				TRACE_2("Warning. No target!",_vehicle,_projectile);
			} else {
				_vehicle setVariable [QGVAR(longbowTarget), nil];
			};
		};
		_turret = [_vehicle, _gunnerInfo select 1] call CBA_fnc_getTurret;
		if (isDedicated) then {
			// PerFrame doesn't work on Dedicated Servers
			[_vehicle, _projectile, _ammotype, "shturm", _weapon, _target, _turret, _isPlayer] call FUNC(missile_saclos);
		} else {
			[_vehicle, _projectile, _ammotype, "shturm", _weapon, _target, _turret, (_isPlayer || _isManualFire || isNull _target) && _isLocal] call FUNC(missile_saclos);
		};
	};

	case "hellfire": {	//Hellfire II - passive laser guided missile
		_mode = _vehicle getVariable QGVAR(hellfire_mode);
		if (isNil "_mode") then { _mode = 0 };
		// PerFrame doesn't work on Dedicated Servers... not required either
		if !(isDedicated) then {
			if (_isPlayer) then {
				_target = _vehicle getVariable QGVAR(laserObject);
				if (isNil "_target") then { _target = laserTarget _vehicle };
				if (_mode == 0) then {
					if (isNull _target) then {
						hint (Localize "STR_ACE_NOLOCKSWITCHTOLOAL");
						_mode = 1;	// In case there's no own laser target up, switch to LOAL-DIR for AGM-114K. Script will fire up incoming EH later
					} else {
						_range = _vehicle getVariable ["AH_DISTANCE_TO_TARGET", -1];
						_tof = 3e-07*(_range^2) + 0.0017*_range + 1.5491;
						_eta = _vehicle getVariable ["ACE_Missile_ETA",0];
						if(_eta == 0) then {
							[time+_tof, _vehicle] spawn {
								waitUntil {
									_eta = (_this select 0)-time;
									// player sideChat format["_eta: %1", _eta];
									(_this select 1) setVariable ["ACE_Missile_ETA",_eta max 0];
									_eta <= 0
								};
								_vehicle setVariable ["ACE_Missile_ETA",nil];
							};
						};
						[_target, _projectile, true] call FUNC(seekerRegisterTargetState);
					};
				};
				//[_vehicle, _projectile, _mode, false, _isPlayer, [_target, "LandVehicle", [0,0,0], [0,0,0]], _laserCode, _projectile] call FUNC(missile_hellfire);
				[FUNC(missile_hellfire2), 0.01, [_projectile, time, false, _mode, 0, 0, _target, 0, [], [0,0,0],time,[0,0,0],_laserCode,(getPosASL _projectile)]] call CBA_fnc_addPerFrameHandler;
			} else {
				_mode = 0;
				_target = _vehicle getVariable QGVAR(longbowTarget);
				if (isNil "_target") then { _target = objNull; TRACE_2("Warning. no longbow target!",_vehicle,_projectile) } else { _vehicle setVariable [QGVAR(longbowTarget), nil] };
			};
		// ToDo: hack up client's AI (gunner tracks the missile directly at the target, unless he dies or his instruments are destroyed)
		//	[_vehicle, _projectile, _mode, false, _isPlayer, [_target, "LandVehicle", [0,0,0], [0,0,0]], _laserCode] call FUNC(missile_hellfire);
		};
	};

	case "longbow": { //Longbow Hellfire - active fire & forget GPS/radar guided missile
		_mode = _vehicle getVariable QGVAR(hellfire_mode);
		if (isNil "_mode") then { _mode = 0 };
		_tarVel = [0,0,0];
		_tarPos = [0,0,0];
		_tarType = "LandVehicle";
		_target = _vehicle getVariable QGVAR(longbowTarget);
		TRACE_3("Target information1",_target,typeOf _target,[_target] call FUNC(getPosASL));
		_vehicle setVariable [QGVAR(longbowTarget), nil]; // Always reset
		// PerFrame doesn't work on Dedicated Servers... not required either
		if !(isDedicated) then {
			if (isNil "_target") then {
				/*
				// DISABLED: Superseeded by actual mapclick interface
				// Longbow hack, use laser pointer as "Mapclick" feature.
				_target = _vehicle getVariable QGVAR(laserObject);
				if (isNil "_target") then { _target = objNull };

				if !(isNull _target) then {
					_tarVeh = objNull;
					{ if !(_x isKindOf "StaticWeapon") exitWith { _tarVeh = _x } } forEach ((position _target) nearEntities [["LandVehicle", "Air", "Ship"],12]);
					if (isNull _tarVeh) then {
						_tarVeh = "ACE_Target_FakeLongbow" createVehicleLocal [0,0,0];
						_tarPos = getPosASL _target;
						_tarVeh setPosASL _tarPos;
						// hint "Using Laser map-click-placeholder";
						// IncomingMissile event will be handled in HellFire thread, if a target is found
					} else {
						TRACE_3("Triggering incoming missile for",_tarVeh,_vehicle,_projectile);
						[QGVAR(global_ieh), [_tarVeh, typeOf _projectile, _vehicle, _projectile]] spawn CBA_fnc_globalEvent;
						_tarVel = velocity _tarVeh;
						_tarPos = getPosASL _tarVeh;
						{if (_target isKindOf _x) then {_tarType = _x};} forEach ["LandVehicle","Air","Ship"];
					};
					_target = _tarVeh;
				};
				*/
			} else {
				// Grab target off longbow radar
				// Store target data to find it out later.
				if !(isNull _target) then {
					_tarVel = velocity _target;
					_tarPos = getPosASL _target;
					{if (_target isKindOf _x) then {_tarType = _x};} forEach ["LandVehicle","Air","Ship"];
					_tarVeh = "ACE_Target_FakeLongbow" createVehicleLocal [0,0,0];	// Reference point
					_tarVeh setPosASL _tarPos;
					if (_target isKindOf "Logic") then {deleteVehicle _target; _tarType = "LandVehicle"};	// mapclick
					_target = _tarVeh;
					
					_ppos = getPosASL _projectile;
					_mvUp = vectorUp _projectile;
					_mvDir = vectorDir _projectile;
					_mVel = velocity _projectile;
					_type = "ACE_M_HellfireL_Fake"; //typeOf _projectile;
					
					_projectile setPosATL [_ppos select 0,_ppos select 1,5000];
					_fakeprojectile = _type createVehicle [0,0,101];
					_fakeprojectile setPosASL [(_ppos select 0) + (_mvDir select 0)*5,(_ppos select 1) + (_mvDir select 1)*5,(_ppos select 2) + (_mvDir select 2)*5];
					_fakeprojectile setVectorDirAndUp [_mvDir,_mvUp];
					_fakeprojectile setVelocity _mVel;
				};
			};
			if (isNil "_target") then { _target = objNull; TRACE_2("Warning. no longbow target!",_vehicle,_projectile) };
			TRACE_3("Target information2",_target,typeOf _target,[_target] call FUNC(getPosASL));
			[_vehicle, _fakeprojectile, _mode, true, _isPlayer, [_target, _tarType, _tarVel, _tarPos], _laserCode, _projectile] call FUNC(missile_hellfire);
		};
	};

	case "lgb": {	// Passive laser guided bomb
		if !(isDedicated) then {
			_mode = nil;
			// PerFrame doesn't work on Dedicated Servers... not required either
			[_vehicle, _projectile, _isPlayer, _laserCode] call FUNC(missile_lgb);
		};
	};
	case "javelin": { //Javelin - active fire & forget IR guided missile
		_target = if (_isPlayer) then {player getVariable QGVAR(javelinTarget)} else {_vehicle getVariable QGVAR(longbowTarget)};
		// Reset target acquisition variables
		_vehicle setVariable [QGVAR(longbowTarget),nil];
		_mode = if (_isPlayer) then {
			uiNamespace getVariable QGVAR(javelinMode);
		} else {
			if (_vehicle distance _target > 200) then {1} else {0};
		};
		// PerFrame doesn't work on Dedicated Servers... not required either
		if (!isDedicated && {isNil "MMA_javelinEnabled"} && {_isPlayer}) then {
			if (isNil "_target") then { _target = objNull };
			
			_ppos = getPosASL _projectile;
			_mvUp = vectorUp _projectile;
			_mvDir = vectorDir _projectile;
			_mVel = velocity _projectile;
			_type = "ACE_M_Javelin_Fake"; //typeOf _projectile;
			_wdir = _vehicle weaponDirection _weapon;
			
			_projectile setPosATL [_ppos select 0,_ppos select 1,5000];
			_fakeprojectile = _type createVehicle [0,0,101];
			_fakeprojectile setPosASL [(_ppos select 0) + (_wdir select 0),(_ppos select 1) + (_wdir select 1),(_ppos select 2) + (_wdir select 2)];
			_fakeprojectile setVectorDirAndUp [_mvDir,_mvUp];
			_fakeprojectile setVelocity _mVel;
			
			if !(isNull _target) then { // todo: disallow firing w/o valid lock
				_targetlogic = "Logic" createVehicleLocal getPos _target;
				_targetlogic attachTo [_target,[0,0,0],"zamerny"];
				[_vehicle, _fakeprojectile, _mode, _target,_isPlayer,_projectile,_targetlogic] call FUNC(missile_javelin);
			};
		};
	};
	
	case "dragon": {
		if (_isPlayer) then {
			_this call FUNC(dragon_fired);
		} else {
			_target = _vehicle getVariable QGVAR(longbowTarget);
			if (isNil "_target") then { _target = objNull; TRACE_2("Warning. No target!",_vehicle,_projectile) } else { _vehicle setVariable [QGVAR(longbowTarget), nil] };
			_turret = [_vehicle, _gunnerInfo select 1] call CBA_fnc_getTurret;
			[_vehicle, _projectile, _ammotype, "saclos", _weapon, _target, _turret, _isPlayer] call FUNC(missile_saclos);
			if (_isLocal && {typeOf (_this select 6) == "M_47_AT_EP1"}) then {
				_this spawn {
					_shell = _this select 6;
					waitUntil {
						sleep (SERVICE_INTERVAL + (0.05 - random 0.1));
						_shellCharge = "ace_m47_dragon_serviceCharge" createVehicle (getPos _shell);
						_shellCharge setPosASL getPosASL _shell;
						!alive _shell
					};
				};
			};
		};
	};
};
