// _this (c) by Xeno
private ["_disp", "_ctrl", "_selidx", "_itemsp", "_item", "_class", "_idcs", "_i", "_one"];
#include "script_component.hpp"

#define CTRL(A) (_disp displayCtrl A)
#define DISPNAME(B) getText(configFile>>"CfgMagazines">>B>>"displayName")
#define PIC(P) getText(configFile>>"CfgMagazines">>P>>"picture")

PARAMS_2(_ctrl,_selidx);

if (_selidx == -1) exitWith {};

disableSerialization;
_disp = uiNamespace getVariable "ACE_ItemsDialog";

_itemsp = player getVariable [QGVAR(items), []];
if (count _itemsp == 0) exitWith {};

_item = _itemsp select _selidx;
_class = _item select 0;

_ctrl = CTRL(101);
_ctrl ctrlSetText DISPNAME(_class);

_ctrl = CTRL(102);
_ctrl ctrlSetText PIC(_class);

_idcs = 110;
for "_i" from 1 to (count _item - 1) do {
	_one = _item select _i;
	_ctrl = CTRL(_idcs);
	_ctrl ctrlSetText (_one select 0);
	INC(_idcs);
	_ctrl = CTRL(_idcs);
	_ctrl ctrlSetText (_one select 1);
	INC(_idcs);
};