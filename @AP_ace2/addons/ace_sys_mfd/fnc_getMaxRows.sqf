#include "script_component.hpp"
private "_maxRows";

_maxRows = getNumber (configFile >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textRowCount");
if (_maxRows == 0) then {
	_maxRows = getNumber (missionConfigFile >> "RscTitles" >> GVAR(currentDialogClass) >> "ACE_textRowCount");
};

_maxRows