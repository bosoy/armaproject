#include "script_component.hpp"


private ["_return","_javelinMode"];
// Mando's first
if (mando_missile_setup_full) exitWith {false};

// Javelin mode switcher
if !(alive player || {vehicle player == player}) exitWith {false};

_javelinMode = uiNamespace getVariable QGVAR(javelinMode);	// Should be set by targeting thread anyway

if (isNil "_javelinMode") then {
	uiNamespace setVariable [QGVAR(javelinMode),0];
	_javelinMode = 0;
};

_return = if (currentWeapon player in ["Javelin","ACE_Javelin_Direct"]) then {
	if (_javelinMode == 0) then {
		__JavelinIGUITop ctrlSetTextColor __ColorGray;
		__JavelinIGUIDir ctrlSetTextColor __ColorGreen;
		
		uiNamespace setVariable [QGVAR(javelinMode),1];
	} else {
		__JavelinIGUITop ctrlSetTextColor __ColorGreen;
		__JavelinIGUIDir ctrlSetTextColor __ColorGray;
		
		uiNamespace setVariable [QGVAR(javelinMode),0];
	};
	true;
} else {
	false
};

_return
