// laser code utility function
// by jaynus

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

// laser code is reseting, so we need to change (if we are currently lasing) code
private["_currentLaser", "_laserCode"];
_laserCode = _this select 0;

if (_laserCode < 1001 || {_laserTarget > 1999}) exitWith { false };

GVAR(currentLaserCode) = _laserCode;
/*
if((currentWeapon player) != "Laserdesignator") exitWith { true };

//_currentLaser = [] call FUNC(findLT);
// FIND the current laser based off of the lasertargets array instead

if(!isNil "ACE_LASERTARGET_ARRAY_INITIALIZED") then {
	if(ACE_LASERTARGET_ARRAY_INITIALIZED) then {
		_currentLaser = nil;
		{
			private["_laser", "_owner"];
			_laser = _x;
			if(!isNull "_laser") then {
				_owner = _laser getVariable "ace_RF_owner";
				if(!isNil "_owner") then {
					if(_owner == player) exitWith {
						_currentLaser = _laser;
					};
				};
			};
		} forEach ACE_LASERTARGET_ARRAY;

		if(isNil "_currentLaser") exitWith { true };
		if(isNull "_currentLaser") exitWith { true };
		_curSetCode = _currentLaser getVariable "ACE_LASERTARGET_CODE";
		if(_curSetCode != GVAR(currentLaserCode)) then {
			TRACE_2("reset laser code of laser", _laser, GVAR(currentLaserCode));
			_currentLaser setVariable ["ACE_LASERTARGET_CODE", GVAR(currentLaserCode), true];
		};
	};
};
*/
true
