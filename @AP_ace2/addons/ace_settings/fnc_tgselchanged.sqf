#include "script_component.hpp"
private "_selidx";
disableSerialization;

if !(uiNamespace getVariable QGVAR(first_tg_sel_change_done)) exitWith {
	uiNamespace setVariable [QGVAR(first_tg_sel_change_done), true];
};

_selidx = _this select 1;
if (_selidx == -1) exitWith {};

setTerrainGrid (switch (_selidx) do {
	case 0: {12.5};
	case 1: {25};
	case 2: {50};
});
