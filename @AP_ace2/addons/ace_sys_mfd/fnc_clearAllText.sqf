#include "script_component.hpp"
private["_rowCount", "_columnCount", "_col", "_row", "_config"];

_rowCount = getNumber (configFile >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textRowCount");
if (_rowCount == 0) then {
	_config = missionConfigFile;
	_rowCount = getNumber (_config >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textRowCount");
};
_columnCount = getNumber (_config >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textColumnCount");

_row = 0;
while {_row < _rowCount} do {
	[_row, ""] call FUNC(setRowText);
	INC(_row);
};
