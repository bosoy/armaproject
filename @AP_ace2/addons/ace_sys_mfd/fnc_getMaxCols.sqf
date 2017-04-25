#include "script_component.hpp"
private "_maxCols";

_maxCols = getNumber (configFile >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textColumnCount");
if (_maxCols == 0) then {
	_maxCols = getNumber (missionConfigFile >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textColumnCount");
};

_maxCols