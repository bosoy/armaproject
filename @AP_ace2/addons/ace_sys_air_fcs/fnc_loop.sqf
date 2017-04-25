#include "script_component.hpp"

if (isDedicated) exitWith {};
PARAMS_3(_vehicle,_pos,_unit);
if (_unit == player) then {
	if (alive _vehicle) then {
		if (isNil "ACE_AH_GUNNERMFD_SYSTEM_INITIALIZED") then {
			if (_vehicle isKindOf "AH1_Base") then {
				if (player in [gunner _vehicle, driver _vehicle]) then {
					ACE_AH_GUNNERMFD_SYSTEM_INITIALIZED = true;
					// Player variable initialization
					_vehicle setVariable ["AH1Z_SYSTEMS_LOADED", nil];
					[player,_vehicle] spawn FUNC(AH1Z_MFDInit);
				};
			};

			if (_vehicle isKindOf "AH64_base_EP1") then {
				if (player in [gunner _vehicle, driver _vehicle]) then {
					ACE_AH_GUNNERMFD_SYSTEM_INITIALIZED = true;
					// Player variable initialization
					_vehicle setVariable ["AH64_SYSTEMS_LOADED", nil];
					[player,_vehicle] spawn FUNC(AH64_MFDInit);
				};
			};

			if (_vehicle isKindOf "ACE_AH6J_DAGR_FLIR") then {
				if (player in [gunner _vehicle, driver _vehicle]) then {
					ACE_AH_GUNNERMFD_SYSTEM_INITIALIZED = true;
					// Player variable initialization
					_vehicle setVariable ["AH1Z_SYSTEMS_LOADED", nil];
					[player,_vehicle] spawn FUNC(AH6_MFDInit);
				};
			};

			if (_vehicle isKindOf "AW159_Lynx_BAF") then {
				if (player in [gunner _vehicle, driver _vehicle]) then {
					ACE_AH_GUNNERMFD_SYSTEM_INITIALIZED = true;
					// Player variable initialization
					_vehicle setVariable ["AH1Z_SYSTEMS_LOADED", nil];
					[player,_vehicle] spawn FUNC(Lynx_MFDInit);
				};
			};
		};
		if (isNil "ACE_RU_GUNNERFCS_INITIALIZED") then {
			if (((_vehicle isKindOf "Mi24_Base") || {(_vehicle isKindOf "Kamov_Base")}) && {!(_vehicle isKindOf "Mi24_P")}) then {
				if (player in [gunner _vehicle, driver _vehicle]) then {
					ACE_RU_GUNNERFCS_INITIALIZED = true;
					// Player variable initialization
					_vehicle setVariable ["RU_SYSTEMS_LOADED", nil];
					[_vehicle] spawn FUNC(RFInit);
				};
			};
		};
	};
};

