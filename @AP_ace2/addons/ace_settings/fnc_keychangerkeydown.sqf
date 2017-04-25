#include "script_component.hpp"
private "_disp";

disableSerialization;

if !(uiNamespace getVariable QGVAR(KeyChangeDo)) exitWith {false};

_disp = uiNamespace getVariable "ACE_SETTINGS_DIALOG";

(_disp displayCtrl 6002) ctrlSetText (call compile format ["%1", keyName (_this select 1)]);

_cokc = uiNamespace getVariable QGVAR(cur_one_key_ctrl);
_cokc set [4, _this select 1];

true