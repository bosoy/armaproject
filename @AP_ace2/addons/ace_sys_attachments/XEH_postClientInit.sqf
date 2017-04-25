#include "script_component.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"
/* ace_sys_attachments - by Sickboy (sb_at_dev-heaven.net)
 * Status: Alpha
*/

// TODO: Make Eventbased
0 spawn {
	private "_lastWeap";
	_lastWeap = "";
	while { true } do {
		waitUntil {sleep 0.1; ([player] call ACE_fnc_getPistol) != _lastWeap };
		_lastWeap = [player] call ACE_fnc_getPistol;
		if (_lastWeap != "") then {
			GVAR(available_Pistol) = _lastWeap call FUNC(weapon);
		};
		sleep 2;
	};
};

0 spawn {
	private "_lastWeap";
	_lastWeap = "";
	while { true } do {
		waitUntil {sleep 0.1; primaryWeapon player != _lastWeap };
		_lastWeap = primaryWeapon player;
		if (_lastWeap != "") then {
			GVAR(available) = _lastWeap call FUNC(weapon);
			GVAR(cqb) = _lastWeap call FUNC(weaponCQB);
		};
		sleep 2;
	};
};

["player", [ace_sys_interaction_key_self], 2, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;
