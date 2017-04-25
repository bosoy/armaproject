//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_data", "_rowCount", "_baseId", "_id", "_i"];
PARAMS_2(_row,_string);

TRACE_1("", GVAR(currentDialogClass));
TRACE_1("", GVAR(currentDialog));

// get row count from config
// static to just the default config for now
_rowCount = getNumber (configFile >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textColumnCount");
if (_rowCount == 0) then {
	_rowCount = getNumber (missionConfigFile >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textColumnCount");
};

TRACE_1("", _rowCount);
_baseId = (_row * 1000) + 1;

for "_i" from 0 to (_rowCount - 1) do {
	_id = _baseId + _i;
	(GET_DIALOG displayCtrl _id) ctrlSetText "";
};

_data = toArray _string;
_i = 0;
while {_i < _rowCount && {_i < (count _data)}} do {
	_id = _baseId + _i;
	(GET_DIALOG displayCtrl _id) ctrlSetText (toString [_data select _i]);
	INC(_i);
};
