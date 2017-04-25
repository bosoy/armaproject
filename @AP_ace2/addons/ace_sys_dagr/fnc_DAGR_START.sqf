#include "script_component.hpp"

disableSerialization;
private ["_run", "_output", "_display"];

if !(local player) exitwith { false; };

_run = false;
_veh = (vehicle player);

if (cameraView == "GUNNER") exitWith { false; };
if (player hasweapon "ACE_DAGR") then {
	if (DAGR_RUN) then {
		DAGR_STP = true;
	} else {
		_run = true;
	};
	if (_run) then {
		DAGR_RUN = true;
		switch (toUpper DAGR_DISPLAY_SELECTION) do {
			case "WP" : {
				[] spawn FUNC(DAGR_OUTPUT_WP);
			};
			case "VECTOR" : {
				[] spawn FUNC(DAGR_OUTPUT_VECTOR);
			};
			case "DATA" : {
				[] spawn FUNC(DAGR_OUTPUT_DATA);
			};
		};
		[_veh] spawn {
			PARAMS_1(_veh);
			while {!DAGR_STP && {alive player} && {cameraView != "GUNNER"} && {(Vehicle player) == _veh}} do {
				sleep 0.5;
			};
			//KILL DISPLAY
			135471 cutRsc ["Default", "plain down"];

			DAGR_RUN = false;
			DAGR_STP = false;
		};
	};
	true;
} else {
	false;
};
