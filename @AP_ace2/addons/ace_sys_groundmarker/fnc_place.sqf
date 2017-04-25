/* ace_sys_groundmarker | (c) 2010,2011,2012 by rocko */

#include "script_component.hpp"

PARAMS_2(_unit,_panelMagazine);

private ["_panelType","_position","_z"];
_panelType = [_panelMagazine,"_M"] call CBA_fnc_replace;
if !(_panelMagazine in (magazines _unit)) exitWith { false };
if (_panelMagazine in (magazines _unit)) then { _unit removeMagazine _panelMagazine; };
if ((_unit call CBA_fnc_getUnitAnim) select 0 == "stand") then {
	_unit playMove "AmovPercMstpSrasWrflDnon_diary";
};
sleep 1;
_position = _unit modelToWorld [0,0,0];
_position set [0, (_position select 0) + (sin direction _unit) * 0.8];
_position set [1, (_position select 1) + (cos direction _unit) * 0.8];
_z = [_unit] call CBA_fnc_realHeight;
_position set [2,_z];
_panel = _panelType createVehicle _position;
_panel setDir direction _unit;
_panel setPos _position;
_unit reveal _panel;
