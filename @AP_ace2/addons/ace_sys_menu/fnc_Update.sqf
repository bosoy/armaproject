#include "script_component.hpp"
sleep 6; // Delay, so that we can buffer
_callSigns = [] + ace_sys_menu_cs_CS;
_groups = [] + ace_sys_menu_cs_GROUPS;
_c = count _callSigns;
if (_c > 0) then {
	for "_i" from 0 to (_c-1) do {
		_g = _groups select _i;
		if !(isNull _g) then {
			_g setGroupID [(_callSigns select _i) call ace_sys_menu_fnc_getCs];
		};
	};
};
