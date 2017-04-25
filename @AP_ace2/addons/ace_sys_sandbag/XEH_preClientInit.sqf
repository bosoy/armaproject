/* ace_sys_sandbag (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"
LOG(MSG_INIT);

ADDON = false;

GVAR(key_add) = {
	GVAR(handlerid_press) = (findDisplay 46) displayAddEventHandler ["KeyDown", QUOTE(_this call GVAR(keypressed))];
	GVAR(handlerid_release) = (findDisplay 46) displayAddEventHandler ["KeyUp", QUOTE(_this call GVAR(keyreleased))];
	GVAR(handlerid_mousez) = (findDisplay 46) displayAddEventHandler ["MouseZChanged", QUOTE(_this call GVAR(z))];
};
GVAR(key_rem) = {
	(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(handlerid_press)];
	(findDisplay 46) displayRemoveEventHandler ["KeyUp", GVAR(handlerid_release)];
	(findDisplay 46) displayRemoveEventHandler ["MouseZChanged", GVAR(handlerid_mousez)];
};
GVAR(keypressed) = {
	if (_this select 2) then {
		GVAR(height) = true; // SHIFT for setting height
	};
	if (_this select 3) then {
		GVAR(rotate) = true; // ALT for rotating
	};
};
GVAR(keyreleased) = {
	GVAR(height) = false;
	GVAR(rotate) = false;
};
GVAR(z) = {
	_zChange = _this select 1;
	if (isNil QGVAR(height)) then {
		GVAR(height) = false;
	};
	if (isNil QGVAR(rotate)) then {
		GVAR(rotate) = false;
	};
	if (GVAR(height)) then {
		GVAR(OffsetZ) = GVAR(OffsetZ) + (_zChange/25);
	};
	if (GVAR(rotate)) then {
		GVAR(dir) = GVAR(dir) + (_zChange * 5);
	};
};

// Ladder stuff
FUNC(ladderKey_add) = {
	GVAR(ladder_handlerid_press) = (findDisplay 46) displayAddEventHandler ["KeyDown", QUOTE(_this call FUNC(ladder_interaction))];
};
FUNC(ladderKey_remove) = {
	(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(ladder_handlerid_press)];
};

FUNC(ladder_interaction) = {
	private "_fnc_collide";
	#define __ANIMS ["extract_4","extract_5","extract_6","extract_7","extract_8","extract_9","extract_10","extract_11"]
	// Ladder animations start from "extract_4" onwards, because from initial setting, the first three elements extract automatically
	_ladder = GVAR(ladder);
	_key = _this select 1;
	_shift = _this select 2;
	_fnc_collide = {
		_pos1 = ATLtoASL(GVAR(ladder) modelToWorld (GVAR(ladder) selectionPosition "check2"));
		_pos2 = [_pos1 select 0,_pos1 select 1,(_pos1 select 2)+0.4];
		lineIntersects [_pos1, _pos2, GVAR(ladder)]
	};
	
	if (_key == 18 && {!_shift}) then { // UP
		if (call _fnc_collide) exitWith {};
		_currentStep = GVAR(currentStep);
		_currentStep = _currentStep + 1;
		if (_currentStep == 12) exitWith { GVAR(currentStep) = 11; };
		if (_ladder animationPhase (format["extract_%1",_currentStep]) == 0) then {
			_ladder animate [(format["extract_%1",_currentStep]),1];
			GVAR(currentStep) = _currentStep;
		};
	};
	if (_key == 18 && {_shift}) then { 
		_currentAngle = GVAR(currentAngle);
		_currentAngle = _currentAngle + 2.5;
		if (_currentAngle > 90) exitWith { GVAR(currentAngle = 90); };
		_ladder animate ["rotate",_currentAngle];
		GVAR(currentAngle) = _currentAngle;
	};
	if (_key == 16 && {!_shift}) then { // DOWN // TODO: actionKeyName "leanleft"
		_currentStep = GVAR(currentStep);
		if (_currentStep == 3) exitWith { GVAR(currentStep) = 3; };
		if (_ladder animationPhase (format["extract_%1",_currentStep]) == 1) then {
			_ladder animate [(format["extract_%1",_currentStep]),0];
			GVAR(currentStep) = _currentStep - 1;
		};		
	};
	if (_key == 16 && {_shift}) then {
		_currentAngle = GVAR(currentAngle);
		_currentAngle = _currentAngle - 2.5;
		if (_currentAngle <= 0) then { _currentAngle = 0; };
		_ladder animate ["rotate",_currentAngle];
		GVAR(currentAngle) = _currentAngle;	
	};
	false
};

[["Land_HBarrier_large","ACE_ConcertinaWire","ACE_ConcertinaWireCoil","ACE_Tactical_Ladder"], [ace_sys_interaction_key], 4, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;

["player", [ace_sys_interaction_key_self], -9, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;

ADDON = true;
