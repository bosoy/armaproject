// by Xeno
#define THIS_FILE "x_sethud.sqf"
#include "x_setup.sqf"
private ["_vec", "_state"];
PARAMS_1(_vec);
_state = _this select 3;

switch (_state) do {
	case 0: {
		GVAR(chophud_on) = false;
		_vec removeAction __pGetVar(GVAR(hud_id));
		__pSetVar [QGVAR(hud_id), _vec addAction [(localize "STR_DOM_MISSIONSTRING_177") call FUNC(GreyText), "x_client\x_sethud.sqf",1,-1,false]];
	};
	case 1: {
		GVAR(chophud_on) = true;
		_vec removeAction __pGetVar(GVAR(hud_id));
		__pSetVar [QGVAR(hud_id), _vec addAction [(localize "STR_DOM_MISSIONSTRING_176") call FUNC(GreyText), "x_client\x_sethud.sqf",0,-1,false]];
	};
};