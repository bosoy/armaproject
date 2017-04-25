//XEH_postClientInit.sqf
#include "script_component.hpp"

if (isDedicated) exitWith {};
[] spawn {
	waitUntil {sleep 5; !isNull player};
	if (vehicle player != player) then {
		[vehicle player, "", player] call FUNC(loop);
	};
};
