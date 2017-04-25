Private ["_unit"];
_unit = _this;

_unit setVariable ['hasAction',true];
_unit addAction ["<t color='#FE7F69'>First Aid</t>","Client\Module\ISIS\ISIS_Action.sqf", "", 2, false, true, "", "(_target getVariable 'stunned') && alive _target && _this != _target"];