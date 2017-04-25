/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL

#include "script_component.hpp"
#include "script_dialog_defines.hpp"

PARAMS_2(_unit,_display);

private["_ctrl","_ruckmags","_ruckweps","_mag_items","_mag_count","_wep_items","_wep_count","_row","_i","_xx","_qty"];

if (!isNil QGVAR(RUCKUPDATING)) exitWith {};
GVAR(RUCKUPDATING) = true;

_mag_items = [];
_mag_count = [];
_wep_items = [];
_wep_count = [];

_ctrl = _display displayCtrl ACE_RUCK_CONTENTS_IDC;
// _ctrl ctrlSetFontHeight 0.0185;


if (_unit call FUNC(HasRuck)) then {
	_ruckweps = _unit call FUNC(RuckWeapons);
	{
		_xx = _x;

		if (_xx in _wep_items) then {
			_i = _wep_items find _xx;
			_wep_count set [_i, (_wep_count select _i) + 1];
		} else {
			PUSH(_wep_items,_xx);
			PUSH(_wep_count,1);
		};
	} forEach _ruckweps;

	_ruckmags = _unit call FUNC(RuckMagazines);
	{
		_xx = _x;

		if (_xx in _mag_items) then {
			_i = _mag_items find _xx;
			_mag_count set [_i, (_mag_count select _i) + 1];
		} else {
			PUSH(_mag_items,_xx);
			PUSH(_mag_count,1);
		};
	} forEach _ruckmags;
};

lnbClear _ctrl;
_row = 0;
{
	_qty = _wep_count Select _forEachIndex;
	_confItem = __CONF_WEAPONS >> _x;

	_ctrl lnbAddRow [str(_qty), getText(_confItem >> "displayName")];
	_ctrl lnbSetPicture[[_row, 1], getText(_confItem >> "picture")];
	_ctrl lnbSetData [[_row, 0], "weapon"];
	_ctrl lnbSetData [[_row, 1], _x];

// Test for rows
	INC(_row);
} forEach _wep_items;

{
	_qty = _mag_count Select _forEachIndex;
	_confItem = __CONF_MAGAZINES >> _x;

	_ctrl lnbAddRow [str(_qty), getText(_confItem >> "displayName")];
	_ctrl lnbSetPicture[[_row, 1], getText(_confItem >> "picture")];
	_ctrl lnbSetData [[_row, 0], "magazine"];
	_ctrl lnbSetData [[_row, 1], _x];

// Test for rows
	INC(_row);
} forEach _mag_items;

GVAR(RUCKUPDATING) = Nil;