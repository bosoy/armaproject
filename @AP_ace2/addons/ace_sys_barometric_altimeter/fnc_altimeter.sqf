#include "script_component.hpp"

disableSerialization;

private ["_dsp","_ctrl_avalue","_ctrl_vvalue"];

_dsp = uiNamespace getVariable "ACE_RscUnitInfoAir";
_ctrl_avalue = _dsp displayCtrl 1591614;
_ctrl_vvalue = _dsp displayCtrl 1591624;

while {!isNull _dsp} do {
	_ctrl_avalue ctrlSetText format["%1", GVAR(baseAlt) + (GVAR(aprecision)*round ((getPosASL cameraOn select 2) / GVAR(aprecision)))];
	_ctrl_vvalue ctrlSetText format["%1", GVAR(vprecision) * round ((velocity cameraOn select 2) / GVAR(vprecision))];
	sleep 0.1;
};
