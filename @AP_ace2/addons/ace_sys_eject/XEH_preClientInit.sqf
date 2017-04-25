#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

FUNC(clientGetOut) = {
	PARAMS_1(_vec);
	{
		_id = _vec getVariable _x;
		if (!isNil "_id") then {
			_vec removeAction _id;
			_vec setVariable [_x, nil];
		};
	} forEach [QGVAR(eject), QGVAR(jumpOutL), QGVAR(jumpOutR), QGVAR(jumpOut), QGVAR(jumpOutLR), QGVAR(diseng_eject), QGVAR(eng_eject)];
};

[QGVAR(ejfl), { _this call FUNC(seat_flame) }] call CBA_fnc_addEventHandler;

//["player", [ace_sys_interaction_key_self], -9567, [QPATHTO_F(fnc_menuDef_Self), "main"]] call CBA_ui_fnc_add;
["ACE_UsedPara_Base", [ace_sys_interaction_key], -9665, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;

ADDON = true;
