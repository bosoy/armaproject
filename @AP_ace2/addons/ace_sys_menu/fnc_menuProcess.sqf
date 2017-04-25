#include "script_component.hpp"
#define __defaultPos [1, 1, 1]
private ["_id", "_item", "_enable", "_disable", "_action"];

PARAMS_1(_id);
switch _id do {
	case 0: {
		#define __marker "ace_lasertracker"
		_item = "Laser Tracking";
		_enable = {
			if (format["%1", getMarkerPos __marker] == format["%1", [0, 0, 0]]) then {
				createMarker [__marker, __defaultPos];
				__marker setMarkerTextLocal "LaserTarget";
				__marker setMarkerShapeLocal "ICON";
				__marker setMarkerTypeLocal "Dot";
			};
			if (scriptDone (ace_sys_menu_pids select _id)) then { [] spawn (ace_sys_menu_scripts select _id) };
		};
		_disable = {
			if !(scriptDone (ace_sys_menu_pids select _id)) then { terminate (ace_sys_menu_pids select _id) };
			deleteMarkerLocal __marker;
		};
	};
};

if (ace_sys_menu_db select _id) then {
	ace_sys_menu_db set [_id, false];
	_action = "Disabled";
	call _disable;
} else {
	ace_sys_menu_db set [_id, true];
	_action = "Enabled";
	call _enable;
};
hint format["BC: %1 %2", _item, _action];
