#include "script_component.hpp"

ADDON = false;

[] spawn {
	sleep 10;

	if (!isNil "ace_sys_aitalk_enabled") then {
		call COMPILE_FILE(talkinit);

		if (isServer) then {
			[] spawn FUNC(talker);
		};
	};
	
	if (isDedicated) exitWith {};

	if (!isNil "ace_sys_aitalk_radio_enabled") then {
		call COMPILE_FILE(vehicleradioinit);

		FUNC(GetRadioVehicles) = {
			private ["_no","_ret"];
			_ret = [];
			_no = (positionCameraToWorld [0,0,0]) nearEntities [["Car","Tank","Air"], 80];
			if (count _no > 0) then {
				{
					if (_x isKindOf "Tank" || {_x isKindOf "Wheeled_APC"}) then {
						if (_x call ace_v_alive) then {_ret set [count _ret, _x]};
					} else {
						if (!(_x isKindOf "ParachuteBase") && {!(_x isKindOf "StaticWeapon")} && {!(_x isKindOf "Ship")} && {!(_x isKindOf "BIS_Steerable_Parachute")} && {alive _x}) then {
							_ret set [count _ret, _x]
						}
					}
				} forEach _no
			};
			_ret
		};
		waitUntil {!isNull player};
		sleep 5;
		[] spawn FUNC(vehicleradio);
	};
};

ADDON = true;
