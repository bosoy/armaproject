//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private "_anim";
PARAMS_2(_unit,_animstatechange);

#define __ANIMS [ \
	"ACE_launcherprone",\
	"ACE_launcherkneel_launcherprone", \
	"ACE_launcherstand_launcherprone", \
	"ACE_launcherprone_launcherkneel", \
	"amovpknlmstpsraswlnrdnon"]

if (_animstatechange in __ANIMS) then {
	_anim = animationstate _unit;
	waitUntil { (animationstate _unit != _anim) || {(animationstate _unit == "ACE_launcherprone_launcherkneel")} };
	if (animationstate _unit in __ANIMS) then {
		TRACE_1("Detected Animation - Switching to Launcher","");
		_unit selectweapon (secondaryweapon _unit)
	};
	if (_animstatechange in ["ACE_launcherprone"]) then {
		waitUntil { animationstate _unit=="ACE_launcherprone" };
		_unit selectweapon (secondaryweapon _unit);
		TRACE_1("Detected Animation - Switching to Launcher","");
	};
};
