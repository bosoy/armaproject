// by Xeno
#define THIS_FILE "x_checkhelipilotout.sqf"
#include "x_setup.sqf"
private ["_vehicle","_position","_enterer"];

_enterer = _this select 2;
__notlocalexit(_enterer);

PARAMS_2(_vehicle,_position);

if (_position == "driver") then {
	if (_enterer == player) then {
		if (__pGetVar(GVAR(hud_id)) != -1000) then {
			_vehicle removeAction __pGetVar(GVAR(hud_id));
			__pSetVar [QGVAR(hud_id), -1000];
		};
	};
};