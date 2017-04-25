#include "script_component.hpp"

if (GVAR(enabled)) then {
	[FUNC(monitorGrenadeWeapon), 0, []] call cba_fnc_addPerFrameHandler;

	GVAR(keyDownId) = ["KeyDown", QUOTE(_this call FUNC(handleKeyDown))] call CBA_fnc_addDisplayHandler;
	GVAR(keyUpId) = ["KeyUp", QUOTE(_this call FUNC(handleKeyUp))] call CBA_fnc_addDisplayHandler;
	GVAR(mouseUp) = ["MouseButtonUp", QUOTE(_this call FUNC(handleMouseUp))] call CBA_fnc_addDisplayHandler;
	GVAR(mouseDown) = ["MouseButtonDown", QUOTE(_this call FUNC(handleMouseDown))] call CBA_fnc_addDisplayHandler;
};