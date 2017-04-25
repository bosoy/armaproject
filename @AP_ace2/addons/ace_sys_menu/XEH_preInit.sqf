#include "script_component.hpp"

if (isNil QUOTE(GVAR(custom))) then { GVAR(custom) = [] };
if (isNil "ace_referee") then {
	ace_referee = false;
};
if (isNil "ace_rf") then {
	ace_rf = [];
};


GVAR(db) =
[
	false // 0 - Laser Tracking
];

_pid = [] spawn {};
GVAR(pids) =
[
	_pid // 0 - Laser Tracking
];

if (isNil "ACE_DEBUG_MISS") then {
	ACE_DEBUG_MISS = false;
};

// Prepare Functions & Scripts
PREP(viewDistance);
PREP(time);
PREP(date);
PREP(year);
PREP(overcast);
PREP(fog);
PREP(rain);
PREP(snow);
PREP(showMap);
PREP(admins);
PREP(buildDBMenu);
PREP(buildMenu);
PREP(menuProcess);
PREP(scripts);

GVAR(proc) = {
	switch (_this select 0) do {
		case 1: {
			switch (_this select 1) do {
				case 0: {
					private ["_hint"];
					if (SIX_NOSPECT) then {
						SIX_NOSPECT = false;
						_hint = "Spectator Enabled";
					} else {
						SIX_NOSPECT = true;
						_hint = "Spectator Disabled";
					};
					publicVariable "SIX_NOSPECT";
					hint _hint;
				};
				case 1: {
					private ["_hint"];
					if (SIX_NODISABLERESPAWN) then {
						SIX_NODISABLERESPAWN = false;
						_hint = "Respawn into Civilian Group Enabled";
					} else {
						SIX_NODISABLERESPAWN = true;
						_hint = "Respawn into Civilian Group Disabled";
					};
					publicVariable "SIX_NODISABLERESPAWN";
					hint _hint;
				};
			};
		};
		case 15: {
			if (ace_sys_menu getVariable "config_group") then {
				ace_sys_menu setVariable ["config_group", false, true];
				hint "Disabled group management";
			} else {
				ace_sys_menu setVariable ["config_group", true, true];
				hint "Enabled group management";
			};
		};
	};
};
