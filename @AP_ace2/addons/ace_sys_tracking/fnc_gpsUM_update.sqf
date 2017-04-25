//#define DEBUG_MODE_FULL
#include "script_component.hpp"
PARAMS_1(_unit);
private ["_mkrName","_mkr","_mkrText"];
_mkrName = format ["ace_gpsunitmarker_%1", _unit];

// delete
if (_mkrName in GVAR(gpsUM)) then {
  deleteMarkerLocal _mkrName;
  GVAR(gpsUM) = GVAR(gpsUM) - [_mkrName];
};

// re-create
_mkr = createMarkerLocal [_mkrName, position vehicle _unit];
_mkr setMarkerShapeLocal "ICON";
_mkr setMarkerSizeLocal [0.9,0.9];
_mkr setMarkerColorLocal "ColorBlue";

// set icon type
_mkr setMarkerTypeLocal QGVAR(gpsUM_mkr_inf);
if (_unit == leader group _unit) then {_mkr setMarkerTypeLocal QGVAR(gpsUM_mkr_tl)};
if ([_unit] call ace_sys_wounds_fnc_isMedic) then {_mkr setMarkerTypeLocal QGVAR(gpsUM_mkr_med)};

// check if unit is in a vehicle or if it's AI
if !(isPlayer _unit && {driver vehicle _unit == _unit}) then {
	_mkrText = "";
} else {
	_mkrText = format["%1", name _unit]; // if on foot or driver/pilot then show name
	if (vehicle _unit != _unit) then {_mkr setMarkerTypeLocal QGVAR(gpsUM_mkr_drv)};
};

_mkr setMarkerTextLocal _mkrText;
// update marker direction
_mkr setMarkerDirLocal (direction vehicle _unit);
if (_unit call ace_sys_wounds_fnc_isUncon) then {_mkr setMarkerColorLocal "ColorRed"};

// add this marker to the global (local to player) "markers to delete array";
if !(_mkrName in GVAR(gpsUMnew)) then {GVAR(gpsUMnew) set [count GVAR(gpsUMnew), _mkrName]};
