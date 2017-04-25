#include "script_component.hpp"

// ghetto-method to see if sys is enabled in config :)
if (getNumber(configfile>>"cfgweapons">>"SVD">>"ace_sys_reticles_enable")==1) then {
	GVAR(reticles_loop1_freq) = 0.01;
	GVAR(reticles_loop1) = [
		{
			if (getNumber(configfile >> "cfgweapons" >> currentweapon player >> "ace_sys_reticles_enable")==1) then {
				GVAR(reticles_loop1_freq) = 0.01;
				
				_mz = currentmuzzle player;
				_a = (currentweapon player) call ace_sys_weaponselect_fnc_hasGL;
				if !((_a select 0) && {_mz == (_a select 1)}) then {
					if (cameraOn == player) then {
						GVAR(sightup) = true;
						player spawn FUNC(reticle);
					};
				};
			} else {
				GVAR(reticles_loop1_freq) = 2;
			};
		}, /* Run code */
		_timeBack, /* parameters */
		GVAR(reticles_loop1_freq), // delay
		{}, /* Init code */
		{}, /* Exit code */
		{ /* Run condition - default true */
			player == (vehicle player) && {cameraview == "GUNNER"} && {!GVAR(sightup)} && {!visibleMap}
		},
		{false}, /* Exit condition */
		[] /* Private variables, available throughout all states and conditions */
	] call cba_common_fnc_addPerFrameHandlerLogic;
};
