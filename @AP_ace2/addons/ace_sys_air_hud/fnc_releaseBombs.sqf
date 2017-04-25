//fnc_releaseBombs.sqf
#include "script_component.hpp"
// player sideChat format["RELEASE!"];
if(GVAR(CCIP_RELEASE_COUNT) <= 0) then {
	[(_this select 1)] call cba_fnc_removePerFramehandler;
} else {
	if(GVAR(CCIP_RELEASE_RIPPLEPAIRS)) then {
		// player sideChat format["rip"];
		[FUNC(shackEm), 0, [0]] call cba_fnc_addPerFramehandler;
	} else {
		GVAR(ccip_plane) fireAtTarget [GVAR(ccip_plane),(GVAR(currentPlaneWeapons) select GVAR(currentPlaneWeaponsIndex))];
	};
	GVAR(CCIP_RELEASE_COUNT) = GVAR(CCIP_RELEASE_COUNT) - 1;
};