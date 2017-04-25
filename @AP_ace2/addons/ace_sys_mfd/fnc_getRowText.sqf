#include "script_component.hpp"

private["_string", "_rowCount", "_idd", "_baseId", "_i", "_text"];

PARAMS_1(_row);
_string = "";

// get row count from config
// static to just the default config for now

_rowCount = getNumber (configFile >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textColumnCount");
if (_rowCount == 0) then {
	_rowCount = getNumber (missionConfigFile >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textColumnCount");
};

_baseId = (_row * 1000) + 1;
TRACE_1("",_rowCount);

for "_i" from 0 to (_rowCount - 1) do {
	_id = _baseId + _i;
	_text = ctrlText (GET_DIALOG displayCtrl _id);
	if (!isNil "_text") then {
		_string = _string + _text;
	} else {
		_string = _string + " ";
	};
};

_string