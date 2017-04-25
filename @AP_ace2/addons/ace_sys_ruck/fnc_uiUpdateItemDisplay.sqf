//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"

disableSerialization;
PARAMS_3(_itm,_isWep,_display);
private ["_pic", "_nam", "_dsc", "_vol", "_wgt", "_picCtrl", "_namCtrl", "_dscCtrl", "_volCtrl", "_wgtCtrl"];

if (_isWep) then {
	_pic = getText(__CONF_WEAPONS >> _itm >> "picture");
	_nam = getText(__CONF_WEAPONS >> _itm >> "displayName");
	_dsc = getText(__CONF_WEAPONS >> _itm >> "descriptionShort");
	_vol = getNumber(__CONF_WEAPONS >> _itm >> "ACE_Size");
	_wgt = getNumber(__CONF_WEAPONS >> _itm >> "ACE_Weight");
} else {
	_pic = getText(__CONF_MAGAZINES >> _itm >> "picture");
	_nam = getText(__CONF_MAGAZINES >> _itm >> "displayName");
	_dsc = getText(__CONF_MAGAZINES >> _itm >> "descriptionShort");
	_vol = getNumber(__CONF_MAGAZINES >> _itm >> "ACE_Size");
	_wgt = getNumber(__CONF_MAGAZINES >> _itm >> "ACE_Weight");
};

_picCtrl = _display displayctrl CA_ITEM_PICTURE_IDC;
_picCtrl ctrlSetText  _pic;
_namCtrl = _display displayctrl CA_ITEMNAME_IDC;
_namCtrl ctrlSetText _nam;
_dscCtrl = _display displayctrl CA_CUSTOMDESCRIPTION_IDC;
_dscCtrl ctrlSetStructuredText  parseText(_dsc);

_volCtrl = _display displayctrl ACE_ITEM_VOLUME_IDC;
_volCtrl ctrlSetText format["%1 %2", [_vol, 1, 0, true] call CBA_fnc_formatNumber, localize "STR_ACE_SYS_RUCK_CUBICCENTIMETERS"];
_wgtCtrl = _display displayctrl ACE_ITEM_WEIGHT_IDC;
_wgtCtrl ctrlSetText format["%1 %2", [_wgt, 1, 3, true] call CBA_fnc_formatNumber, localize "STR_ACE_SYS_RUCK_KILOGRAM"];
