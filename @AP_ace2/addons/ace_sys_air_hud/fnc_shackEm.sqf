//fnc_shackEm.sqf
#include "script_component.hpp"
_params = _this select 0;
_count = _params select 0;
// player sideChat format["plane: %1", GVAR(ccip_plane)];
GVAR(ccip_plane) fireAtTarget [GVAR(ccip_plane),(GVAR(currentPlaneWeapons) select GVAR(currentPlaneWeaponsIndex))];
_count = _count + 1;
_params set[0, _count];
// player sideChat format["shack: %1", _count];
if(_count == 2) then {
	[(_this select 1)] call cba_fnc_removePerFramehandler;
};