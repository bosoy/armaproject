////////////////////////////////////////////
//  ACE Javelin Missile Targeting Thread  //
////////////////////////////////////////////
// By zGuba

// NOTE: Make sure to keep the private array up2date, especially due to required serialization and deserialization of the local variables.

// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __TRACKINTERVAL 0.1	// how frequent the check should be.
#define __LOCKONTIME 1.85	// Lock on won't occur sooner
#define __LOCKONTIMERANDOM 0.3	// Deviation in lock on time
#define __SENSORSQUARE 1	// Locking on sensor square side in angles

#define __ConstraintTop (((ctrlPosition __JavelinIGUITargetingConstrainTop) select 1) + ((ctrlPosition (__JavelinIGUITargetingConstrainTop)) select 3))
#define __ConstraintBottom ((ctrlPosition __JavelinIGUITargetingConstrainBottom) select 1)
#define __ConstraintLeft (((ctrlPosition __JavelinIGUITargetingConstrainLeft) select 0) + ((ctrlPosition (__JavelinIGUITargetingConstrainLeft)) select 2))
#define __ConstraintRight ((ctrlPosition __JavelinIGUITargetingConstrainRight) select 0)

#define __OffsetX ((ctrlPosition __JavelinIGUITargetingLineV) select 0) - 0.5
#define __OffsetY ((ctrlPosition __JavelinIGUITargetingLineH) select 1) - 0.5

// Reset variables
uiNamespace setVariable [QGVAR(javelinMode),0];
player setVariable [QGVAR(javelinTarget),nil];

if !(isNil "MMA_javelinEnabled") exitWith {
	__JavelinIGUITargetingConstrains ctrlShow false;
	__JavelinIGUITargetingGate ctrlShow false;
	__JavelinIGUITargetingLines ctrlShow false;
};

_handle = [
	{ /* run code */
		_prevTime = time;

		// Use engine to return target we're aiming at.
		_newTarget = objNull;
		
		_range = parseNumber (ctrlText __JavelinIGUIRangefinder);
		if (_range > 50 && {_range < 2500}) then {
			_pos = positionCameraToWorld [0,0,_range];
			_targetArray = _pos nearEntities ["AllVehicles", _range/25];
			if (count (_targetArray) > 0) then {
				_newTarget = _targetArray select 0;
			};
		};
		
		if (isNull _newTarget) then {
			_newTarget = cursorTarget;
		};
		
		if ((velocity player) distance [0,0,0] > 0.5 && {cameraView == "GUNNER"} && {cameraOn == player}) then {	// keep it steady.
			player switchCamera "INTERNAL";
		};
		
		if (isNull _newTarget) then {
			_target = objNull;
		
			__JavelinIGUISeek ctrlSetTextColor __ColorGray;
			__JavelinIGUINFOV ctrlSetTextColor __ColorGreen;
			__JavelinIGUITargetingConstrains ctrlShow false;
			__JavelinIGUITargetingGate ctrlShow false;
			__JavelinIGUITargetingLines ctrlShow false;
			
			player setVariable [QGVAR(javelinTarget),nil];
			
			// Disallow fire
			if (player ammo "Javelin" > 0 || {player ammo "ACE_Javelin_Direct" > 0}) then {player setWeaponReloadingTime [player, "Javelin", 0.2];};
		} else {
			// Locking on target will occur only on NFOV & TI mode & missile loaded
			if (_newTarget distance player < 2500 && {(call CBA_fnc_getFoV) select 1 > 7} && {currentVisionMode player == 2} && {(player ammo "Javelin" > 0 || {player ammo "ACE_Javelin_Direct" > 0})}) then {
				private ["_apos","_aposX","_aposY"];
				
				_apos = worldToScreen (_newTarget modelToWorld _randomPosWithinBounds);
				
				if (count _apos < 2) then {
					_aposX = 1;
					_aposY = 0;
				} else {
					_aposX = (_apos select 0) + _offsetX;
					_aposY = (_apos select 1) + _offsetY;
				};
				
				__JavelinIGUISeek ctrlSetTextColor __ColorGreen;
				__JavelinIGUINFOV ctrlSetTextColor __ColorNull;
				__JavelinIGUITargetingConstrains ctrlShow true;
				
				if (_newTarget == _target && {((_aposX > _constraintLeft && {_aposX < _constraintRight}) || {_constraintLeft == _constraintRight})} && {((_aposY > _constraintTop && {_aposY < _constraintBottom}) || {_constraintTop == _constraintBottom})}) then {
					if (time - _initTime > (__LOCKONTIME + _randomDelay) && {!([_target,player] call FUNC(JavelinLOSOccluded))}) then {
						__JavelinIGUITargetingGate ctrlShow true;
						__JavelinIGUITargetingLines ctrlShow true;
						
						// Move target marker to coords.
						__JavelinIGUITargetingLineV ctrlSetPosition [_aposX,ctrlPosition __JavelinIGUITargetingLineV select 1];
						__JavelinIGUITargetingLineH ctrlSetPosition [ctrlPosition __JavelinIGUITargetingLineH select 0,_aposY];
						{_x ctrlCommit __TRACKINTERVAL} forEach [__JavelinIGUITargetingLineH,__JavelinIGUITargetingLineV];
						
						_boundsInput = if (_target isKindOf "CAManBase") then {
							[_target,[-1,-1,-2],_target selectionPosition "body"];
						} else {
							[_target,[-1,-1,-2],_target selectionPosition "zamerny"];
						};
						
						_bpos = _boundsInput call FUNC(worldtoscreen_bounds);
						
						_minX = ((_bpos select 0) + _offsetX) max _constraintLeft;
						_minY = ((_bpos select 1) + _offsetY) max _constraintTop;
						_maxX = ((_bpos select 2) + _offsetX) min (_constraintRight - 0.025*(3/4)*SafezoneH);
						_maxY = ((_bpos select 3) + _offsetY) min (_constraintBottom - 0.025*SafezoneH);
						
						__JavelinIGUITargetingGateTL ctrlSetPosition [_minX,_minY];
						__JavelinIGUITargetingGateTR ctrlSetPosition [_maxX,_minY];
						__JavelinIGUITargetingGateBL ctrlSetPosition [_minX,_maxY];
						__JavelinIGUITargetingGateBR ctrlSetPosition [_maxX,_maxY];
						
						{_x ctrlCommit __TRACKINTERVAL} forEach [__JavelinIGUITargetingGateTL,__JavelinIGUITargetingGateTR,__JavelinIGUITargetingGateBL,__JavelinIGUITargetingGateBR];
						
						player setVariable [QGVAR(javelinTarget),_target];
						
						playSound "ACE_Javelin_Locked";
					} else {
						__JavelinIGUITargetingGate ctrlShow true;
						__JavelinIGUITargetingLines ctrlShow false;
						
						player setVariable [QGVAR(javelinTarget),nil];
						
						_boundsInput = if (_target isKindOf "CAManBase") then {
							[_target,[-1,-1,-2],_target selectionPosition "body"];
						} else {
							[_target,[-1,-1,-1],_target selectionPosition "zamerny"];
						};
						
						_bpos = _boundsInput call FUNC(worldtoscreen_bounds);
						
						_minX = ((_bpos select 0) + _offsetX) max _constraintLeft;
						_minY = ((_bpos select 1) + _offsetY) max _constraintTop;
						_maxX = ((_bpos select 2) + _offsetX) min (_constraintRight - 0.025*(3/4)*SafezoneH);
						_maxY = ((_bpos select 3) + _offsetY) min (_constraintBottom - 0.025*SafezoneH);
						
						__JavelinIGUITargetingGateTL ctrlSetPosition [_minX,_minY];
						__JavelinIGUITargetingGateTR ctrlSetPosition [_maxX,_minY];
						__JavelinIGUITargetingGateBL ctrlSetPosition [_minX,_maxY];
						__JavelinIGUITargetingGateBR ctrlSetPosition [_maxX,_maxY];
						
						{_x ctrlCommit __TRACKINTERVAL} forEach [__JavelinIGUITargetingGateTL,__JavelinIGUITargetingGateTR,__JavelinIGUITargetingGateBL,__JavelinIGUITargetingGateBR];
						
						playSound "ACE_Javelin_Locking";
						
						// Disallow fire
						if (player ammo "Javelin" > 0 || {player ammo "ACE_Javelin_Direct" > 0}) then {player setWeaponReloadingTime [player, "Javelin", 0.2];};
					};
				} else {
					_initTime = _prevTime;
					_randomDelay = random __LOCKONTIMERANDOM;
					_target = _newTarget;
					
					__JavelinIGUITargetingGate ctrlShow false;
					__JavelinIGUITargetingLines ctrlShow false;
					
					_zamerny = if (_target isKindOf "CAManBase") then {_target selectionPosition "body"} else {_target selectionPosition "zamerny"};
					_randomPosWithinBounds = [(_zamerny select 0) + 1 - (random 2.0),(_zamerny select 1) + 1 - (random 2.0),(_zamerny select 2) + 0.5 - (random 1.0)];
					
					player setVariable [QGVAR(javelinTarget),nil];
					
					// Disallow fire
					if (player ammo "Javelin" > 0 || {player ammo "ACE_Javelin_Direct" > 0}) then {player setWeaponReloadingTime [player, "Javelin", 0.2];};
				};
			} else {
				__JavelinIGUISeek ctrlSetTextColor __ColorGray;
				__JavelinIGUINFOV ctrlSetTextColor __ColorGreen;
				__JavelinIGUITargetingConstrains ctrlShow false;
				__JavelinIGUITargetingGate ctrlShow false;
				__JavelinIGUITargetingLines ctrlShow false;
				
				player setVariable [QGVAR(javelinTarget),nil];
				
				// Disallow fire
				if (player ammo "Javelin" > 0 || {player ammo "ACE_Javelin_Direct" > 0}) then {player setWeaponReloadingTime [player, "Javelin", 0.2];};
			};
		};
	},
	[], /* parameters */
	0, // delay
	{ /* init code */
		_target = objNull;
		_initTime = time;
		_prevTime = _initTime - __TRACKINTERVAL;
		_randomDelay = random __LOCKONTIMERANDOM;
		_randomPosWithinBounds = [0,0,0];
		
		_constraintTop = __ConstraintTop;
		_constraintLeft = __ConstraintLeft;
		_constraintBottom = __ConstraintBottom;
		_constraintRight = __ConstraintRight;
		
		_offsetX = __OffsetX;
		_offsetY = __OffsetY;
		
		player setVariable [QGVAR(javelinTarget),nil];
	},
	{ /* exit code */ 
		player setVariable [QGVAR(javelinTarget),nil];
	},
	{ /* Run condition - default true */
		time - _prevTime > __TRACKINTERVAL
	},
	{!(currentWeapon (vehicle player) in ["Javelin","ACE_Javelin_Direct"]) || {vehicle player != player}}, /* exit condition */
	[ /* Private variables, available throughout all states and conditions */
		"_target","_newTarget",
		"_randomDelay","_initTime","_prevTime",
		"_constraintTop","_constraintBottom","_constraintLeft","_constraintRight",
		"_offsetX","_offsetY",
		"_randomPosWithinBounds"
	]
] call cba_common_fnc_addPerFrameHandlerLogic;

_handle;
