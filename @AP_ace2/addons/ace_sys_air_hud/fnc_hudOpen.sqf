//fnc_hudOpen.sqf
#include "script_component.hpp"
uiNamespace setVariable ["ACE_HUD_RSC", _this select 0];
[] spawn {
	_displayEh = uiNamespace getVariable "ACE_HUD_DISPLAYEH";
	waitUntil {!isNull (findDisplay 46)};
	if(!isNil "_displayEh") then {
		{
			(findDisplay 46) displayRemoveEventHandler _x;
		} forEach _displayEh;
	};
	uiNamespace setVariable ["ACE_HUD_DISPLAYEH", []];
	_displayEh = uiNamespace getVariable "ACE_HUD_DISPLAYEH";
	_id = (findDisplay 46) displayAddEventHandler ["mouseButtonDown", QUOTE(_this call FUNC(triggerPressCheckDown))];
	_displayEh set[(count _displayEh), ["mouseButtonDown", _id]];
	_id = (findDisplay 46) displayAddEventHandler ["mouseButtonUp", QUOTE(_this call FUNC(triggerPressCheckUp))];
	_displayEh set[(count _displayEh), ["mouseButtonUp", _id]];
	_id = (findDisplay 46) displayAddEventHandler ["JoystickButton", QUOTE(_this call FUNC(triggerPressCheckDown))];
	_displayEh set[(count _displayEh), ["JoystickButton", _id]];
	_id = (findDisplay 46) displayAddEventHandler ["KeyDown", QUOTE(_this call FUNC(checkChangeWeapon))];
	_displayEh set[(count _displayEh), ["KeyDown", _id]];
	
};