// _this (c) by Xeno
private ["_items", "_disp", "_ctrl", "_item", "_index"];
#include "script_component.hpp"

#define CTRL(A) (_disp displayCtrl A)
#define DISPNAME(B) getText(configFile>>"CfgMagazines">>B>>"displayName")
#define PIC(P) getText(configFile>>"CfgMagazines">>P>>"picture")

// currently only CfgMagazines

// one item:
//player setVariable ["ace_sys_dogtag_items", [["ACE_DogTag",["Name:", "Hans"], ["Whatever:","jaja"], ["Hello:","blub"]]]]

_items = player getVariable [QGVAR(items), []];
if (count _items == 0) exitWith {};

disableSerialization;
_disp = uiNamespace getVariable "ACE_ItemsDialog";

_ctrl = CTRL(100);
lbClear _ctrl;

{
	_item = _x select 0;
	_index = _ctrl lbAdd DISPNAME(_item);
	_ctrl lbSetPicture [_index, PIC(_item)];
} forEach _items;

_ctrl lbSetCurSel 0;

