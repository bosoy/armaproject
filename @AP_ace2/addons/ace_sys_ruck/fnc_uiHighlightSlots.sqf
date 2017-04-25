//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"

disableSerialization;
PARAMS_3(_unit,_display,_control);
DEFAULT_PARAM(3,_itm,Nil);
DEFAULT_PARAM(4,_isWep,Nil);
DEFAULT_PARAM(5,_remember,false);
private ["_IDCsArray", "_i", "_slotArray", "_j", "_slot", "_itmSlot", "_bitArray", "_n", "_valResult", "_outputArray", "_IDCRow", "_CtrlRow", "_IDCCtrl", "_IDC", "_coords", "_faded"];

_IDCsArray = [
	[CA_GEAR_SLOT_PRIMARY_IDC],
	[CA_GEAR_SLOT_HANDGUN_IDC],
	[CA_GEAR_SLOT_SECONDARY_IDC],
	[255],
	[CA_GEAR_SLOT_HANDGUN_ITEM1_IDC, CA_GEAR_SLOT_HANDGUN_ITEM2_IDC, CA_GEAR_SLOT_HANDGUN_ITEM3_IDC, CA_GEAR_SLOT_HANDGUN_ITEM4_IDC, CA_GEAR_SLOT_HANDGUN_ITEM5_IDC, CA_GEAR_SLOT_HANDGUN_ITEM6_IDC, CA_GEAR_SLOT_HANDGUN_ITEM7_IDC, CA_GEAR_SLOT_HANDGUN_ITEM8_IDC],
	[255],
	[255],
	[255],
	[CA_GEAR_SLOT_ITEM1_IDC, CA_GEAR_SLOT_ITEM2_IDC, CA_GEAR_SLOT_ITEM3_IDC, CA_GEAR_SLOT_ITEM4_IDC, CA_GEAR_SLOT_ITEM5_IDC, CA_GEAR_SLOT_ITEM6_IDC, CA_GEAR_SLOT_ITEM7_IDC, CA_GEAR_SLOT_ITEM8_IDC, CA_GEAR_SLOT_ITEM9_IDC, CA_GEAR_SLOT_ITEM10_IDC, CA_GEAR_SLOT_ITEM11_IDC, CA_GEAR_SLOT_ITEM12_IDC],
	[255],
	[255],
	[255],
	[CA_GEAR_SLOT_SPECIAL1_IDC, CA_GEAR_SLOT_SPECIAL2_IDC],
	[255],
	[255],
	[255],
	[255],
	[CA_GEAR_SLOT_INVENTORY1_IDC, CA_GEAR_SLOT_INVENTORY2_IDC, CA_GEAR_SLOT_INVENTORY3_IDC, CA_GEAR_SLOT_INVENTORY4_IDC, CA_GEAR_SLOT_INVENTORY5_IDC, CA_GEAR_SLOT_INVENTORY6_IDC, CA_GEAR_SLOT_INVENTORY7_IDC, CA_GEAR_SLOT_INVENTORY8_IDC, CA_GEAR_SLOT_INVENTORY9_IDC, CA_GEAR_SLOT_INVENTORY10_IDC, CA_GEAR_SLOT_INVENTORY11_IDC, CA_GEAR_SLOT_INVENTORY12_IDC],
	[ACE_GEAR_SLOT_WOB_IDC],
	[255],
	[255],
	[255]
];

_faded = false;

if (!isNil "_itm" && {!isNil "_isWep"}) then {
	for "_i" from 0 to (count _IDCsArray) - 1 do {
		_slotArray = _IDCsArray select _i;

		for "_j" from 0 to (count _slotArray) - 1 do {
			_slot = _display displayctrl (_slotArray select _j);
			_slot ctrlSetFade 0.5;
			_slot ctrlCommit 0.3;
		};
	};

	if (_isWep) then {
		_itmSlot = getNumber(__CONF_WEAPONS >> _itm >> "type");
		TRACE_1("Wep",_itmSlot);
	} else {
		_itmSlot = getNumber(__CONF_MAGAZINES >> _itm >> "type");
		TRACE_1("Mag",_itmSlot);
	};

	_itmSlot = (_itmSlot call FUNC(ParseTypeSlots)) select 0;
	TRACE_2("Slot",_itm,_itmSlot);

	_bitArray = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
	_n = 524288;

	for "_i" from 19 to 0 step -1 do {
		_valResult = _itmSlot mod _n;

		if (_valResult != _itmSlot) then {
			_bitArray set [_i, 1];
		};

		_n = _n / 2;
		_itmSlot = _valResult;
	};

	_outputArray = [];
	for "_i" from 0 to (count _IDCsArray) - 1 do {
		if ((_bitArray select _i) == 1) then {
			_outputArray = [_outputArray, _IDCsArray select _i] call BIS_fnc_arrayPushStack;
			//_outputArray = _outputArray + (_IDCsArray select _i);
		};
	};
	TRACE_2("11",_bitArray,_outputArray);

	_fade = if (count _outputArray > 0) then {_faded = true;0.25} else {0};
	for "_i" from 0 to (count _outputArray) - 1 do {
		_slot = _display displayctrl (_outputArray select _i);
		_slot ctrlSetFade _fade;
		_slot ctrlCommit 0;
	};
};

if (_remember) then {
	for "_i" from 0 to (count _IDCsArray) - 1 do {
		scopeName "Scan";
		_IDCRow = _IDCsArray select _i;
		_CtrlRow = [];

		for "_j" from 0 to (count _IDCRow) - 1 do {
			_IDCCtrl = _display displayctrl (_IDCRow select _j);

			if ( _control == _IDCCtrl ) then {
				_unit setVariable [QGVAR(LastGearSlot), [_i, _j], false];
				breakOut "Scan";
			};
		};
	};
	TRACE_2("Remember",_control,_unit getVariable QGVAR(LastGearSlot));
};

_IDC = -1;
_coords = _unit getVariable [QGVAR(LastGearSlot),[]];
if ( count _coords == 2 ) then {
	_i = _coords select 0;
	_j = _coords select 1; 

	if ( _i >= 0 && {_i < (count _IDCsArray)} ) then {	
		_IDCRow = _IDCsArray select _i;

		if ( _j >= 0 && {_j < (count _IDCRow)} ) then {
			_IDC = _IDCRow select _j;
		};
	};
};
if (_faded) then {
	_cslot = _display displayctrl _IDC;
	_cslot ctrlSetFade 0;
	_cslot ctrlCommit 0;
	TRACE_1("faded",_IDC);
};

TRACE_2("IDC",_coords,_IDC);
_IDC;