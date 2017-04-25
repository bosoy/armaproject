//fnc_frago.sqf
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define FRAG_VEC_VAR 0.0085

#define MAX_FRAG_COUNT 80

if(!isServer) exitWith {};

private ["_startTime", "_round", "_lastPos", "_lastVel", "_shellType", "_fragTypes", "_indirectHitRange",
	"_fragRange", "_fragPower", "_fragPowerRandom", "_objects", "_target", "_boundingBox", "_add",
	"_bbX", "_bbY", "_bbZ", "_cubic", "_targetPos", "_targetVel", "_distance", "_baseVec", "_count",
	"_vecVar", "_vec", "_fp", "_vel", "_fragType", "_fragObj", "_endTime","_fuzeDist", "_gun"
];
	
// _startTime = diag_tickTime;
_round = _this select 0;
_lastPos = _this select 1;
_lastVel = _this select 2;
_shellType = _this select 3;
_gun = nil;

if((count _this) > 5) then {
	_gun = _this select 5;
};

_fragTypes = [
	"ACE_frag_tiny", "ACE_frag_tiny", "ACE_frag_tiny",
	"ACE_frag_small","ACE_frag_small","ACE_frag_small","ACE_frag_small",
	"ACE_frag_medium", "ACE_frag_medium", "ACE_frag_medium", "ACE_frag_medium", "ACE_frag_medium",
	"ACE_frag_medium", "ACE_frag_medium", "ACE_frag_large", "ACE_frag_large", "ACE_frag_large",
	"ACE_frag_huge", "ACE_frag_huge", "ACE_frag_huge"
];

if(isArray (configFile >> "CfgAmmo" >> _shellType >> "ACE_FRAG_CLASSES")) then {
	_fragTypes = getArray (configFile >> "CfgAmmo" >> _shellType >> "ACE_FRAG_CLASSES");
};

_fm = 1;
if(isNumber (configFile >> "CfgAmmo" >> _shellType >> "ACE_FRAG_MULTIPLIER")) then {
	_fm = getNumber (configFile >> "CfgAmmo" >> _shellType >> "ACE_FRAG_MULTIPLIER");
};

_atlPosZ = 0 max ((_lastPos select 2) - (getTerrainHeightASL [(_lastPos select 0), (_lastPos select 1)]));
_atlPos = [(_lastPos select 0), (_lastPos select 1), _atlPosZ];

_isArmed = true;
if(!isNil "_gun") then {
	_fuseDist = getNumber(configFile >> "CfgAmmo" >> _shellType >> "fuseDistance");
	_isArmed = ((getPosASL _gun) distance _lastPos > _fuseDist);
};

_indirectHitRange = getNumber(configFile >> "CfgAmmo" >> _shellType >> "indirecthitrange");
_fragRange = 5*_indirectHitRange*4*_fm;
_fragPower = getNumber(configFile >> "CfgAmmo" >> _shellType >> "indirecthit")*(sqrt(_indirectHitRange))*_fm;
_fragPowerRandom = _fragPower*0.5;
if((_atlPos select 2) < 0.5) then {
	_lastPos set[2, (_lastPos select 2)+0.5];
};

_manObjects = _atlPos nearEntities ["CaManBase", _fragRange];
TRACE_1("",_atlPos);

//_objects = nearestObjects [_atlPos, ["AllVehicles"], _fragRange]; // Not sure if tracking "ReammoBox" is required, if so revert this change for _objects
_objects = _atlPos nearEntities ["AllVehicles", _fragRange];
_objects = _objects - _manObjects;
_objects = _manObjects + _objects;

// Target also people inside vehicles or manning weapons
_crew = [];
{
    {
        _crew set [count _crew,_x]
    } forEach (crew _x);
} forEach _objects;

_objects = _objects - _crew;
_objects = _objects + _crew;

_fragCount = 0;

_fragArcs = [];
_fragArcs set[360, 0];

#ifdef DEBUG_MODE_FULL
	player sideChat format["_fragRange: %1", _fragRange];
	player sideChat format["_objects: %1", _objects];
#endif
_doRandom = false;
if(_isArmed && {(count _objects) > 0}) then {
	{
		if(random(1) > 0.5) then {
			_target = _x;
			if(alive _target) then {
				_boundingBox = boundingBox _target;
				_add = ((_boundingBox select 1) select 2);
				_bbX = (abs((_boundingBox select 0) select 0))+((_boundingBox select 1) select 0);
				_bbY = (abs((_boundingBox select 0) select 1))+((_boundingBox select 1) select 1);
				_bbZ = (abs((_boundingBox select 0) select 2))+((_boundingBox select 1) select 2);
				_cubic = _bbX*_bbY*_bbZ;
				if(_cubic > 1) then {
					_doRandom = true;
					_targetPos = (getPosASL _target);
					_targetVel = (velocity _target);
					_distance = _target distance _lastPos;
					_targetPos set[2, (_targetPos select 2)+_add];
					_targetPos set[0, (_targetPos select 0)+((_targetVel select 0)*(_distance/_fragPower))];
					_targetPos set[1, (_targetPos select 1)+((_targetVel select 1)*(_distance/_fragPower))];
					
					_baseVec = [_lastPos, _targetPos] call ACE_fnc_vectorFromXToY;
					
					_dir = floor(_baseVec call CBA_fnc_vectDir);
					_currentCount = _fragArcs select _dir;
					if(isNil "_currentCount") then {
						_currentCount = 0;
					};
					if(_currentCount < 20*_fm) then {
						_count = (0 max round(random((ceil sqrt(_cubic))*_fm))) min 10;
						_vecVar = FRAG_VEC_VAR;
						if !(_target isKindOf "Man") then {
							_vecVar = ((sqrt _cubic)/2000)+FRAG_VEC_VAR;
							if (count (crew _target) == 0 && {_count > 0}) then {
								_count = 0 max (_count/2);
							};
						};
						for "_i" from 1 to _count do {
							_vec = +_baseVec;
							
							_vec set[0, (_vec select 0)-(_vecVar/2)+(random _vecVar)];
							_vec set[1, (_vec select 1)-(_vecVar/2)+(random _vecVar)];
							_vec set[2, (_vec select 2)-(_vecVar/2)+(random _vecVar)];
							
							_fp = (_fragPower-(_fragPowerRandom*0.5)+(random (_fragPowerRandom))) min 1000;
							_vel = [
									(_vec select 0)*_fp,
									(_vec select 1)*_fp,
									(_vec select 2)*_fp
								];
							
							_fragType = round (random ((count _fragTypes)-1));
							_fragObj = (_fragTypes select _fragType) createVehicleLocal [0,0,10000];
							_fragObj setPosASL _lastPos;
							_fragObj setVectorDir _vec;
							_fragObj setVelocity _vel;
							#ifdef DEBUG_MODE_FULL
								GVAR(TOTALFRAGS) = GVAR(TOTALFRAGS) + 1;
								GVAR(traceFrags) = true;
							#endif
							if(GVAR(traceFrags)) then {
								[FUNC(frag_trace), 0.05, [_fragObj]] call cba_fnc_addPerFrameHandler;
							};
							_fragCount = _fragCount + 1;
							_currentCount = _currentCount + 1;
						};
						_fragArcs set[_dir, _currentCount];
					};
				};
			};
		};
		if(_fragCount > MAX_FRAG_COUNT) exitWith {};
	} forEach _objects;
	if(_fragCount > MAX_FRAG_COUNT) exitWith {};
	_randomCount = (ceil((MAX_FRAG_COUNT-_fragCount)*0.1)) max 0;
	_sectorSize = 360 / (_randomCount max 1);
	if(_doRandom) then {
		for "_i" from 1 to _randomCount do {
			// Distribute evenly
			_sectorOffset = 360 * (_i - 1) / (_randomCount max 1);
			_randomDir = random(_sectorSize);
			_vec = [cos(_sectorOffset + _randomDir), sin(_sectorOffset + _randomDir), sin(30 - (random 45))];
			
			_fp = (_fragPower-(_fragPowerRandom*0.5)+(random (_fragPowerRandom))) min 1000;
			_vel = [
					(_vec select 0)*_fp,
					(_vec select 1)*_fp,
					(_vec select 2)*_fp
				];
			
			_fragType = round (random ((count _fragTypes)-1));
			_fragObj = (_fragTypes select _fragType) createVehicleLocal [0,0,10000];
			_fragObj setPosASL _lastPos;
			_fragObj setVectorDir _vec;
			_fragObj setVelocity _vel;
			#ifdef DEBUG_MODE_FULL
				// GVAR(TOTALFRAGS) = GVAR(TOTALFRAGS) + 1;
				//[FUNC(frag_trace), 0, [_fragObj]] call cba_fnc_addPerFrameHandler;
				GVAR(traceFrags) = true;
			#endif
			if(GVAR(traceFrags)) then {
				[FUNC(frag_trace), 0.05, [_fragObj]] call cba_fnc_addPerFrameHandler;
			};
			_fragCount = _fragCount + 1;
		};
	};
};
#ifdef DEBUG_MODE_FULL
	player sideChat format["total frags: %1", GVAR(TOTALFRAGS)];
	player sideChat format["tracks: %1", (count GVAR(trackedObjects))];
#endif
// _endTime = diag_tickTime;
